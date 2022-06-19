#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 110
using namespace std;
int N, M, ans;
int flow[MAXN][MAXN], cost[MAXN][MAXN], cap[MAXN][MAXN], d[MAXN], inq[MAXN], p[MAXN];
int min_cost()
{
    memset(flow, 0, sizeof(flow));
    int s = 0, t = N + 1, f = 0;
    ans = 0;
    while (1)
    {
        memset(d, INF, sizeof(d));
        memset(inq, 0, sizeof(inq));
        queue<int> q;
        d[s] = 0;
        q.push(s);
        inq[s] = 1; // inq: in queue or not
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int v = 0; v <= N + 1; v++)
                if (cap[u][v] > flow[u][v] && d[v] > d[u] + cost[u][v])
                {
                    d[v] = d[u] + cost[u][v]; // distance
                    p[v] = u;                 // parent
                    if (!inq[v])
                    {
                        q.push(v);
                        inq[v] = 1;
                    }
                }
        }
        if (d[t] == INF) // distance to t is infinit
            break;
        int a = INF;
        for (int u = t; u != s; u = p[u])
        {
            a = min(a, cap[p[u]][u] - flow[p[u]][u]); // a=cap-flow
            cost[p[u]][u] = cost[u][p[u]] = -cost[u][p[u]];
        }
        for (int u = t; u != s; u = p[u])
        {
            flow[p[u]][u] += a; // modify graph
            flow[u][p[u]] -= a;
        }
        f += a;
        ans += a * d[t];
    }
    if (f < 2)
        return 0;
    return 1;
}
int main()
{
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &N), N)
    {
        scanf("%d", &M);
        memset(cap, 0, sizeof(cap));
        memset(cost, INF, sizeof(cost));
        int u, v, t;
        while (M--)
        {
            scanf("%d%d%d", &u, &v, &t);
            cap[u][v] = cap[v][u] = 1;
            cost[u][v] = cost[v][u] = t;
        }
        cap[0][1] = 2;
        cap[N][N + 1] = 2;
        cost[0][1] = cost[1][0] = 0;
        cost[N][N + 1] = cost[N + 1][N] = 0;
        if (min_cost())
            printf("%d\n", ans);
        else
            printf("Back to jail\n");
    }
    return 0;
}
