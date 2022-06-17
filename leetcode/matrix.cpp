#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define Siz(x) (int)x.size()
using namespace std;
const int maxn = 1000 + 7;
const int inf = 1000000;

struct Edge
{
    int from, to, cap, flow;
};

struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges; // total edges in graph
    vector<int> G[maxn];
    bool vis[maxn]; // mark if one node has been visited
    int d[maxn];    // match dfs relation between nodes
    int cur[maxn];

    void init(int nn)
    {
        edges.clear();
        for (int i = 0; i < nn; ++i)
            G[i].clear();
    }

    void AddEdge(int from, int to, int cap)
    {
        edges.push_back((Edge){from, to, cap, 0}); // edge: start->end
        edges.push_back((Edge){to, from, 0, 0});   // edge: end->start, capacity is set to 0
        m = edges.size();                          // total edges that we create
        G[from].push_back(m - 2);                  // corresponding edge index with node from
        G[to].push_back(m - 1);                    // corresponding edge index with node to
    }

    bool BFS()
    {
        memset(vis, 0, sizeof vis);
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); ++i)
            {
                Edge &e = edges[G[x][i]];         // edge start from x, into i
                if (!vis[e.to] && e.cap > e.flow) // havevn't visited e, and current edge has capacity remain
                {
                    vis[e.to] = 1; // mark this node been visisted
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    // current node, remaining_flow
    int DFS(int x, int a)
    {
        if (x == t || a == 0)
            return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); ++i)
        {
            Edge &e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f; // backward edge
                flow += f;
                a -= f;
                if (!a)
                    break;
            }
        }
        return flow;
    }

    int Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof cur);
            flow += DFS(s, inf);
        }
        return flow;
    }

} dic;
int a[30], b[30];
int ans[30][30];
// int main()
// {
//     vector<int> G[maxn];
//     G[0].push_back(1);
//     G[0].push_back(11);
//     G[1].push_back(2);
// }
int main(){
    int T, test_case = 0; // ks for test case
    scanf("%d",&T);
    while(T--){
        // input data
        int n,m;
        scanf("%d %d",&n, &m);
        dic.init(n+m+7);
        for (int i = 1; i <= n; ++i) {
            scanf("%d",a+i);
        }
        for (int i = n; i > 1; --i) a[i] -= a[i-1];
        for (int i = 1; i <= m; ++i) {
            scanf("%d",b+i);
        }
        for (int i = m; i > 1; --i) b[i] -= b[i-1];

        // construct graph
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                dic.AddEdge(i,j+n,19); // edges between row_nodes and col_nodes
            }
        }
        for (int i = 1; i <= n; ++i){
            dic.AddEdge(0,i,a[i]-m); // edges from source to row_nodes
        }
        for (int i = 1; i <= m; ++i){
            dic.AddEdge(i+n,n+m+1,b[i]-n); // edges from col_nodes to destination
        }

        // calculate Maxflow
        dic.Maxflow(0,n+1+m);
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < Siz(dic.G[i]); ++j){
                int id=dic.G[i][j];
                Edge& e = dic.edges[id]; // edge between each row_node and col_node
                if (e.to-n >= 1 && e.to-n <= m)ans[i][e.to-n] = e.flow + 1; //要特么范围，否则负数会造成循环赋值。
            }
        }

        // output results
        if (test_case++)puts("");
        printf("Matrix %d\n",test_case);
        for (int i = 1; i <= n;++i){
            for (int j = 1; j <= m; ++j){
                if (j > 1)printf(" ");
                printf("%d",ans[i][j]);
            }
            putchar('\n');
        }

    }

    return 0;
}
/**
 **/
