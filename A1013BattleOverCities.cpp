#include <bits/stdc++.h>
#define maxn 1010 
using namespace std;
int n, m, k;
vector<vector<int>> g;
int vis[maxn];
int father[maxn];
int del; 
void dfs(int q)
{
    if (q == del)
        return;
    vis[q] = true;
    for (int i = 0; i < g[q].size(); ++i)
        if (!vis[g[q][i]])
            dfs(g[q][i]); 
}

void dfsTour()
{
    cin >> n >> m >> k;
    g.resize(n + 10);
    for (int i = 0; i < n + 10; ++i)
        g[i].resize(0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int j = 0; j < k; ++j)
    {
        int cnt = 0;
        cin >> del;
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; ++i)
        {
            if (i != del && !vis[i])
            {
                dfs(i);
                cnt++;
            }
        }
        cout << (cnt - 1) << endl;
    }
}

int find1(int a)
{
    if (father[a] == a)
        return a;
    else
    {
        int v = find1(father[a]);
        father[a] = v;
        return v;
    } 
}

void unionFind(int a, int b)
{
    int t1 = find1(a);
    int t2 = find1(b); 
    if (t1 != t2)
    {
        father[t2] = t1;
    }
}

int main()
{  
    // dfsTour();
    cin >> n >> m >> k;
    g.resize(n + 10);
    for (int i = 0; i < n + 10; ++i)
        g[i].resize(0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < k; ++i)
    {
        for (int i = 0; i <= n; ++i)
            father[i] = i;
            memset(vis, false, sizeof(vis));
        int t;
        cin >> t;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < g[i].size(); ++j)
            {
                int u = i, v = g[i][j]; 
                if (u == t || v == t )
                    continue; 
                unionFind(u, v);
            }
        } 
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i == t)
                continue;
            int fa_i = find1(i);
            if (!vis[fa_i])
            {
                cnt++;
                vis[fa_i] = true;
            }
        }
        cout << cnt - 1 << endl;
    }
    system("pause");
    return 0;}