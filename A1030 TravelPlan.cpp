#include <bits/stdc++.h>
#define maxn 550
#define INF 0x3f3f3f
using namespace std;
int n, m, s, d;
int g[maxn][maxn];
bool vis[maxn];
int ds[maxn];
int total = INF;
vector<vector<int>> pre;
vector<int> path, temPath;
int wei[maxn][maxn];

void dij(int s)
{
    fill(ds, ds + maxn, INF);
    ds[s] = 0;
    for (int i = 0; i < n; ++i)
    {
        int u = -1, Min = INF;
        for (int j = 0; j < n; ++j)
        {
            if (vis[j] == false && ds[j] < Min)
            {
                Min = ds[j];
                u = j;
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 0; v < n; ++v)
        {
            if (g[u][v] != INF && vis[v] == false ) 
            {
                if(ds[v] > ds[u] + g[u][v])
                {
                    ds[v] = ds[u] + g[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (ds[v] == ds[u] + g[u][v])
                {
                    pre[v].push_back(u);
                } 
            } 
        }
    }
}

void dfs(int v)
{
    if (s == v)
    {
        temPath.push_back(v);
        int tempcost = 0;
        for (int i = temPath.size() - 1; i > 0; --i)
        {
            int t1 = temPath[i], t2 = temPath[i - 1];
            tempcost += wei[t1][t2];
        }
        if (tempcost < total)
        {
            total = tempcost;
            path = temPath;
        }
        temPath.pop_back();
        return;
    }
    temPath.push_back(v);
    for (int i = 0; i < pre[v].size(); ++i)
        dfs(pre[v][i]);
    temPath.pop_back();
}

int main()
{
    fill(g[0], g[0] + maxn * maxn, INF);
    fill(wei[0], wei[0] + maxn * maxn, INF);
    cin >> n >> m >> s >> d;
    pre.resize(n+5);
    for (int i = 0; i < n+5; ++i)
        pre[i].resize(0);
    for (int i = 0; i < m; ++i)
    {
        int c1, c2, dis, cost;
        cin >> c1 >> c2 >> dis >> cost;
        g[c1][c2] = g[c2][c1] = dis;
        wei[c1][c2] = wei[c2][c1] = cost;
    } 
    dij(s);
    path.clear();
    path.resize(n + 5);
    dfs(d);
    for (int i = path.size() - 1; i > 0; --i)
        cout << path[i] << " ";
    cout << path[0] << " ";
    cout << ds[d] << " " << total << endl;
    system("pause");
    return 0;
}