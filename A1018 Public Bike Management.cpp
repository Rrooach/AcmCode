#include <bits/stdc++.h>
#define maxn 550
#define INF 0x3f3f3f3f
using namespace std;
int c, n, sp, m;
int cnt[maxn];
int g[maxn][maxn];
int d[maxn];
bool vis[maxn];
vector<vector<int>> pre;
int num[maxn];
vector<int> path, temPath;
int Mintake = INF, Minremain = INF;
bool spfa(int s)
{
    pre.resize(n + 10);
    for (int i = 0; i < n + 10; ++i)
        pre[i].resize(0);
    fill(d, d + maxn, INF);
    d[s] = 0;
    num[s]++;
    vis[s] = true;
    priority_queue<int> q;
    // piorio_queue<int> q;
    q.push(s);
    
    while (!q.empty())
    {
        int top = q.top();
        q.pop();
        vis[top] = false;
        for (int i = 0; i <= n; ++i)
        {
            if (g[top][i] != INF)
            {
                if (d[i] > d[top] + g[top][i])
                {
                    d[i] = d[top] + g[top][i];
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
                else if (d[i] == d[top] + g[top][i])
                {
                    pre[i].push_back(top);  
                } 
            }
        }
    }
    return true;
}

void dij(int s)
{
    pre.resize(n + 10);
    for (int i = 0; i < n + 10; ++i)
        pre[i].resize(0);
    fill(d, d + maxn, INF);
    d[s] = 0; 
    for (int i = 0; i <= n; ++i)
    {
        int u = -1, Min = INF;
        for (int j = 0; j < n; ++j)
        {
            if (!vis[j] && d[j] < Min)
            {
                u = j;
                Min = d[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int j = 0; j <= n; ++j)
        {
            if (!vis[j] && g[u][j] != INF)
            {
                if (d[j] > d[u] + g[u][j])
                {
                    d[j] = d[u] + g[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }
                else if (d[j] == d[u] + g[u][j])
                {
                    pre[j].push_back(u);
                } 
            }
        }
    }
}

void dfs(int ed)
{ 
    if (ed == 0)
    {
        int remain = 0, take = 0;
        temPath.push_back(ed); 
        for (int i = temPath.size() - 1; i >= 0; --i)
        { 
            int id = temPath[i];
            if (cnt[id] > 0)
                remain += cnt[id];
            else
            {
                if (remain <= abs(cnt[id]))
                {
                    take += abs(cnt[id]) - remain;
                    remain = 0;
                }
                else
                {
                    remain += cnt[id];
                }
            }
        }
        if (take < Mintake)
        {
            Mintake = take;
            Minremain = remain;
            path = temPath;
        }else if (take == Mintake && Minremain > remain)
        {
            Mintake = take;
            Minremain = remain;
            path = temPath;
        } 
        temPath.pop_back();
        return;
    }
    temPath.push_back(ed);
    for (int i = 0; i < pre[ed].size(); ++i)
        dfs(pre[ed][i]);
    temPath.pop_back();
}


int main()
{
    cin >> c >> n >> sp >> m;
    fill(g[0], g[0] + maxn * maxn, INF);
    for (int i = 1; i <= n; ++i)
    {
        int temp;
        cin >> temp;
        cnt[i] = temp - c/2;
    }
        
    for (int i = 0; i < m; ++i)
    {
        int a, b, t;
        cin >> a >> b >> t;
        g[a][b] = g[b][a] = t;
    }
    // dij(0);
    spfa(0);
    dfs(sp);
    cout << Mintake << " ";
    for (int i = path.size() - 1; i > 0 ; --i)
        cout << path[i] << "->";
    cout << path[0] << " ";
    cout << Minremain << endl;
    system("pause");
    return 0;
}