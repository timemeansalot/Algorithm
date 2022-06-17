// C++ program to find maximum number of edge disjoint paths
#include <bits/stdc++.h>

// #include <iostream>
// #include <limits.h>
// #include <string.h>
// #include <queue>
using namespace std;

// Number of vertices in given graph
#define V 101 // max node size n<=100

// these variable is set to global for global access
int init_graph[V][V]; // init graph to input data from test case
int row_number, col_number;
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
            if (visited[v] == false && rGraph[u][v] > 0)
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
int findDisjointPaths(int s, int t, int nodes)
{
    int u, v;

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph

    int parent[V];    // This array is filled by BFS and to store path
    int max_flow = 0; // There is no flow initially

    // Augment the flow while there is path from source to sink
    while (bfs(init_graph, s, t, parent, nodes))
    {
        // cout << "into while" << endl;
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, init_graph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            init_graph[u][v] -= path_flow;
            init_graph[v][u] += path_flow;
            // rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow (max_flow is equal to maximum
    // number of edge-disjoint paths)
    return max_flow;
}

int main()
{
    int nodes = 0, edges = 0;           // nodes and edges in a graph
    int start = 0, end = 0, weight = 0; // for each edge [start,end, weight]
    int graph_bak[V][V];                // create graph whose edge is only 0 or 1 to do max-flow algorithm in order to find the "number of non overlap paths"
    int nonoverlap_paths = 0;           // non overlap paths
    int ans[V][V];                      // result
    int T;
    int test_case = 1;
    int rows[V], cols[V];
    cin >> T;
    // main program
    while (test_case <= T)
    {
        test_case++;
        cin >> row_number >> col_number;
        nodes = 2 + row_number + col_number;
        // cout << endl
        //      << "nodes: " << nodes << endl;
        memset(ans, 0, sizeof(ans));
        memset(init_graph, 0, sizeof(init_graph)); // set all edge length in init graph to be 0

        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));

        for (int i = 1; i <= row_number; i++)
            cin >> rows[i];
        for (int i = 1; i <= col_number; i++)
            cin >> cols[i];
        for (int i = row_number; i > 0; i--)
            rows[i] = rows[i] - rows[i - 1];
        for (int i = col_number; i > 0; i--)
            cols[i] = cols[i] - cols[i - 1];

        // cout << "rows: " << endl;
        // for (int i = 1; i <= row_number; i++)
        //     cout << rows[i] << " ";
        // cout << endl;
        // cout << "cols: " << endl;
        // for (int i = 1; i <= col_number; i++)
        //     cout << cols[i] << " ";
        // cout << endl;

        // connect s with row nodes
        for (int i = 0; i < row_number; i++)
        {
            init_graph[0][i + 1] = rows[i + 1] -col_number ;
        }
        // connect col nodes with t
        for (int i = 0; i < col_number; i++)
        {
            init_graph[i + 1 + row_number][nodes - 1] = cols[i + 1] - row_number;
        }
        for (int i = 0; i < row_number; i++)
        {
            for (int j = 0; j < col_number; j++)
            {
                init_graph[i + 1][1 + row_number + j] = 19;
            }
        }

        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
                graph_bak[i][j] = init_graph[i][j];
        }

        // for (int i = 0; i < 1 + row_number + col_number; i++)
        // {
        //     for (int j = 0; j < 1 + row_number + col_number; j++)
        //     {
        //         cout << init_graph[i][j] << " ";
        //     }

        //     cout << endl;
        // }

        // cout.width(3);
        // cout << "init: " << endl;
        // for (int i = 0; i < nodes; i++)
        // {
        //     for (int j = 0; j < nodes; j++)
        //         cout << graph_bak[i][j] << " ";
        //     cout << endl;
        // }
        nonoverlap_paths = findDisjointPaths(0, nodes - 1, nodes);
        // cout << "after: " << endl;
        // for (int i = 0; i < nodes; i++)
        // {
        //     for (int j = 0; j < nodes; j++)
        //         cout << init_graph[i][j] << " ";
        //     cout << endl;
        // }

        cout <<"Matrix "<<test_case-1 << endl;
        // get origin matrix
        for (int i = 0; i < row_number; i++)
        {
            for (int j = 0; j < col_number; j++)
            {
                ans[i][j] = graph_bak[i + 1][j + 1 + row_number] - init_graph[i + 1][j + 1 + row_number] + 1;
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
    }

    return 0;
}