
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, cap, flow, cost;       //���,�յ�,����,����,����
    Edge(int u, int v, int c, int f, int w):from(u), to(v), cap(c), flow(f), cost(w) {}
};
struct MCMF
{
    int n, m;                //�����,����(��������),Դ��s,���t
    vector<Edge> edges;            //�߱�edges[e]��edges[e^1]��Ϊ����
    vector<int> G[MAXN];           //�ڽӱ�G[i][j]��ʾ���i�ĵ�j������edges�����е����
    bool inq[MAXN];                //�Ƿ��ڶ�����
    int d[MAXN];                   //Bellman-Ford
    int p[MAXN];                   //��һ����
    int a[MAXN];                   //�ɸĽ���
 
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
 
    bool BellmanFord(int s, int t, int &flow, long long& cost)//����ֲ�����
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

