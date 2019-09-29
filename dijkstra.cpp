#include <bits/stdc++.h>
#define maxn 100005
#define INF 0x3f3f
using namespace std;

vector<vector<int>> g;
vector<int> d;
bool vis[maxn] = {false};
int n;
vector<int> path[maxn];
void dij(int s)
{
    d.resize(n);
    fill(d.begin(), d.end(), INF);
    d[s] = 0;
    for (int i = 0; i < n; ++i)
    {
        int min = INT_MAX, u = -1;
        for (int j = 0; j < n; ++j)
        {
            if (!vis[j] && d[j] < min)
            {
                min = d[j];
                u = -1;
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        vector<int> temp_path;
        for (int j = 0; j < n; ++j)
        {
            if(!vis[j] && g[u][j] != INF)
            {
                if (d[j] > d[u] + g[u][j])
                {
                    d[j] = d[u] + g[u][j];
                    path[j].clear();
                    path[j].push_back(u);
                }
                if (d[j] == d[u] + g[u][j])
                { 
                    path[j].push_back(u);
                }
            }
        }
    }
}

int main()
{ 
    while (cin >> n)
    {
        g.resize(n);
        for (int i = 0; i < n; ++i)
            g[i].resize(n);
        for (int i = 0; i < n; ++i)
        {
            int a, b, w;
            cin >> a >> b >> w;
            g[a][b] = g[b][a] = w;
        }
        int start;
        cin >> start;
        dij(start);
        cout << d[start];
    }
    system("pause");
    return 0;
}