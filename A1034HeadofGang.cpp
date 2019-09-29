#include <bits/stdc++.h>
#define maxn 10
#define INF 0x3f3f3f3f
using namespace std;
/****************SPFA Version *****************************/
int n, m, st, ed;
int g[maxn][maxn];
vector<int> wei;
int maxlen = 0, maxcnt = 0;
bool vis[maxn];
int ds[maxn] ;
int cnt[maxn];
vector<vector<int>> pre;
int num[maxn];
vector<int> path, temPath;
bool spfa(int s)
{
    fill(ds, ds + maxn, INF);
    num[s]++;
    vis[s] = true;
    cnt[s] = wei[s];
    ds[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        vis[top] = false;
        for (int i = 0; i < n; ++i)
        {
            if (g[top][i] != INF)
            {
                if (ds[i] > ds[top] + g[top][i])
                {
                    ds[i] = ds[top] + g[top][i];
                    pre[i].clear();
                    pre[i].push_back(top);
                    if (!vis[i])
                    {
                        q.push(i);
                        vis[i] = true;
                        num[i]++;
                        if (num[i] >= n)
                            return false;
                    }
                }
                if (ds[i] == ds[top] + g[top][i] )
                    pre[i].push_back(top);
            } 
        }
    }
    return true;
}

int dfs(int s)
{
    if (s == st)
    {
        temPath.push_back(s);
        int tempC = 0;
        for (int i = temPath.size() - 1; i > 0; --i)
        {
            int a = temPath[i], b = temPath[i - 1];
            tempC += wei[pre[s][i]];
        }
    }
}

int main()
{
    cin >> n >> m >> st >> ed;
    pre.resize(n + 10);
    for (int i = 0; i < n + 10; ++i)
        pre[i].resize(0);
    fill(g[0], g[0] + maxn * maxn, INF);
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        wei.push_back(a);
    }
    for (int i = 1; i <= m; ++i)
    {
        int a, b, v;
        cin >> a >> b >> v;
        g[a][b] = g[b][a] = v;
    }
    if (spfa(st))
    {
        dfs(ed);
    }
    system("pause");
    return 0;
}