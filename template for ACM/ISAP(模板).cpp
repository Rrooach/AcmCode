
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, cap, flow, cost;       //起点,终点,容量,流量,花费
    Edge(int u, int v, int c, int f, int w):from(u), to(v), cap(c), flow(f), cost(w) {}
};
struct MCMF
{
    int n, m;                //结点数,边数(包括反向弧),源点s,汇点t
    vector<Edge> edges;            //边表。edges[e]和edges[e^1]互为反向弧
    vector<int> G[MAXN];           //邻接表，G[i][j]表示结点i的第j条边在edges数组中的序号
    bool inq[MAXN];                //是否在队列中
    int d[MAXN];                   //Bellman-Ford
    int p[MAXN];                   //上一条弧
    int a[MAXN];                   //可改进量
 
    void init(int n)
    {
        this->n = n;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }
    void add_edge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
 
    bool BellmanFord(int s, int t, int &flow, long long& cost)//构造分层网络
    {
        for (int i = 0; i <= n; i++) d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0; inq[s] = true; p[s] = 0; a[s] = INF;
 
        queue<int> Q;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) { Q.push(e.to); inq[e.to] = true; }
                }
            }
        }
        if (d[t] == INF) return false;
        flow += a[t];
        cost += (long long)d[t] * (long long)a[t];
        for (int u = t; u != s; u = edges[p[u]].from)
        {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
        }
        return true;
    }
 
    int Mincost_Maxflow(int s, int t, long long& cost)
    {
        int flow = 0; cost = 0;
        while (BellmanFord(s, t, flow, cost));
        return flow;
    }
};
MCMF solve;
int main()
{
    int n, m, s, t;
    while(~scanf("%d%d%d%d", &n, &m, &s, &t))
    {
        solve.init(n);
        while(m--)
        {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            solve.add_edge(a, b, c, d);
        }
        long long cost = 0;
        int Max_Flow = solve.Mincost_Maxflow(s, t, cost);
        printf("%d %lld\n", Max_Flow, cost);
    }
    return 0;
}

