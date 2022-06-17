// C++ program to find maximum number of edge disjoint paths
// #include <bits/stdc++.h>

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

// Number of vertices in given graph
#define V 101 // max node size n<=100

// these variable is set to global for global access
int init_graph[V][V];     // init graph to input data from test case
vector<int> path_lengths; // length for every posible path in graph

// calculate min value
int min_length = INT_MAX;
int book[101];
int real_path[101];
int nodes;

void find_min_path(int current_node, int total_length)
{
    int j = 0;

    if (total_length > min_length) // if total length>min, no need to continue search
    {
        return;
    }

    // reach target node
    if (current_node == nodes - 1)
    {
        if (total_length < min_length)
        {
            min_length = total_length;
            // cout << "path: ";
            for (int i = 0; i <= nodes - 1; i++)
            {
               real_path[i]=book[i]; 
            }
            // cout << endl;
            // cout<<"total length: "<<total_length<<endl;
        }
        return;
    }

    // try from first node to last node
    for (j = 0; j <= nodes - 1; j++)
    {
        if (init_graph[current_node][j] != 0 && book[j] == 0)
        {
            book[j] = current_node; // mark this node have been visited
            find_min_path(j, total_length + init_graph[current_node][j]);
            book[j] = 0;
        }
    }

    return;
}

// calculate min value

/* Returns true if there is a path from source 's' to sink 't' in
residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V][V], int s, int t, int parent[], int nodes)
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < nodes; v++)
        {
            if (visited[v] == false && (rGraph[u][v] > 0 | rGraph[v][u] > 0)) // change into undirected graph
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}

// Returns the maximum number of edge-disjoint paths from s to t.
// This function is copy of forFulkerson() discussed at http://goo.gl/wtQ4Ks
int findDisjointPaths(int graph[V][V], int s, int t, int nodes)
{
    int u, v;

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int rGraph[V][V]; // Residual graph where rGraph[i][j] indicates
                      // residual capacity of edge from i to j (if there
                      // is an edge. If rGraph[i][j] is 0, then there is not)
    for (u = 0; u < nodes; u++)
        for (v = 0; v < nodes; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];    // This array is filled by BFS and to store path
    int max_flow = 0; // There is no flow initially

    // Augment the flow while there is path from source to sink
    while (bfs(rGraph, s, t, parent, nodes))
    {
        // cout << "gGraph: " << endl;
        // for (u = 0; u < nodes; u++)
        // {
        //     for (v = 0; v < nodes; v++)
        //         cout << rGraph[u][v] << " ";
        //     cout << endl;
        // }
        // cout << "into while" << endl;
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        int path_length = 0; // length from source -> destination

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] -= path_flow;
        }

        // calculate path length
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_length += init_graph[u][v];
        }
        path_lengths.push_back(path_length);

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // cout << "gGraph: " << endl;
    // for (u = 0; u < nodes; u++)
    // {
    //     for (v = 0; v < nodes; v++)
    //         cout << rGraph[u][v] << " ";
    //     cout << endl;
    // }
    // Return the overall flow (max_flow is equal to maximum
    // number of edge-disjoint paths)
    return max_flow;
}

int main()
{
    int edges = 0;                      // nodes and edges in a graph
    int start = 0, end = 0, weight = 0; // for each edge [start,end, weight]
    int graph01[V][V];                  // create graph whose edge is only 0 or 1 to do max-flow algorithm in order to find the "number of non overlap paths"
    int nonoverlap_paths = 0;           // non overlap paths
    // main program
    while (cin >> nodes)
    {

        if (nodes == 0)
            break;
        memset(init_graph, 0, sizeof(init_graph)); // set all edge length in init graph to be 0

        // input edge info of graph
        cin >> edges;
        while (edges--)
        {
            cin >> start >> end >> weight;
            init_graph[start - 1][end - 1] = weight;
            init_graph[end - 1][start - 1] = weight;
        }

        //   if(nodes>=15)
        //    {
        //    	cout << "Back to jail" << endl;
        //      continue;
        //    }

        // for (int i = 0; i < nodes; i++)
        // {
        //     for (int j = 0; j < nodes; j++)
        //     {
        //         cout.width(3);
        //         cout << init_graph[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // change init graph to graph whose edge weight is only 1 or 0
        for (int i = 0; i < nodes; i++)
            for (int j = 0; j < nodes; j++)
                graph01[i][j] = init_graph[i][j] > 0 ? 1 : 0;

        // output for test

        // for (int i = 0; i < nodes; i++)
        // {
        //     for (int j = 0; j < nodes; j++)
        //     {
        //         cout.width(3);
        //         cout << init_graph[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 0; i < nodes; i++)
        // {
        //     for (int j = 0; j < nodes; j++)
        //     {
        //         cout.width(3);
        //         cout << graph01[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // cout << "current nonoverlap: " << nonoverlap_paths << endl;
        // cout << "current nodes: " << nodes << endl;
        // for (int i = 0; i < nodes; i++)
        // {
        //     cout.widen(3);
        //     for (int j = 0; j < nodes; j++)
        //         cout << graph01[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;

        // output for test

        nonoverlap_paths = findDisjointPaths(graph01, 0, nodes - 1, nodes);
        // cout << "non overlap paths: " << nonoverlap_paths << endl;
        // show path_lengths
        sort(path_lengths.begin(), path_lengths.end());
        if (nonoverlap_paths < 2)
            cout << "Back to jail" << endl;
        else
        {
            int ans=0;
            // cout<<"origin length: ";
            // cout << path_lengths[0] + path_lengths[1] << endl;
            // for (int i = 0; i <= nodes-1; i++)
            // {
            //     for (int j = 0; j <= nodes-1; j++)
            //         cout << init_graph[i][j] << " ";
            //     cout << endl;
            // }
            find_min_path(0, 0);
            ans+=min_length;
            // cout << "min length: " << min_length << endl;

            // cout<<"begin second loop:"<<endl;
            // cout<<"book: ";
            // for(int i=0;i<nodes;i++)
            // cout<<real_path[i]<< " ";
            // cout<<endl;
            // second round
            for (int i = nodes-1; i > 0;)
            {
                init_graph[i][real_path[i]] = 0;
                init_graph[real_path[i]][i] = 0;
                i = real_path[i];
            }
            // for (int i = 0; i <= nodes-1; i++)
            // {
            //     for (int j = 0; j <= nodes-1; j++)
            //         cout << init_graph[i][j] << " ";
            //     cout << endl;
            // }

            min_length = INT_MAX;
            for (int i = 0; i <= nodes-1; i++)
                book[i] = 0;
            find_min_path(0, 0);
            ans+=min_length;
            cout<<ans<<endl;
            // cout << "min length: " << min_length << endl;
        }

        // output data to test
        // cout << "nonoverlap paths: " << nonoverlap_paths << endl;
        // for (int i = 0; i < path_lengths.size(); i++)
        //     cout << path_lengths[i] << " ";
        // cout << endl
        //      << endl;

        // output data to test

        path_lengths.clear();
    }

    return 0;
}