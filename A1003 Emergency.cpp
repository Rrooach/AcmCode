#include <bits/stdc++.h>
#define maxn 550
#define INF 0x3f3f3f3f
using namespace std;

int n, m, s, e;
int wei[maxn];
int c[maxn];
int g[maxn][maxn];
int dis[maxn];
bool vis[maxn];
int num[maxn];
void dij(int start)
{
    fill(dis, dis + maxn, INF);
    dis[start] = 0;
    c[start] = wei[start];
    num[start] = 1;
    for (int i = 0;i < n; ++i)
    {
        int u = -1, Min = INF;
        for (int j = 0; j < n; ++j)
        {
            if (vis[j] == false && dis[j] < Min)
            {
                u = j;
                Min = dis[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 0; v < n; ++v)
        {
            if (g[u][v] != INF && !vis[v])
            {
                if (dis[u] + g[u][v] < dis[v])
                {
                    dis[v] = dis[u] + g[u][v];
                    c[v] = c[u] + wei[v];
                    num[v] = num[u];
                }
                else if (dis[v] == dis[u] + g[u][v])
                {
                    if (c[v] < c[u] + wei[v])
                        c[v] = c[u] + wei[v];
                    num[v] += num[u];    
                } 
            }
        }
    }
}

int main()
{
    fill(g[0], g[0] + maxn*maxn, INF);
    cin >> n >> m >> s >> e;
    for (int i = 0; i < n; ++i)
        cin >> wei[i];
    for (int i = 0; i < m; ++i)
    {
        int sta, end, len;
        cin >> sta >> end >> len;
        g[sta][end] = g[end][sta] = len;
    }
    dij(s);
    cout << num[e] << " "
         << c[e] << endl;
    system("pause");
    return 0;
}