#include <bits/stdc++.h>
#define maxn 10053
using namespace std;
int n;
int father[maxn];
struct node{
    int data;
    vector<int> child;
} N[maxn];
bool vis[maxn];
int maxdp = -1;
vector<int> ans;

int findFa(int a)
{
    if (a == father[a])
        return a;
    else
    {
        int v = findFa(father[a]);
        father[a] = v;
        return v;
    } 
} 
int bfs(int i)
{
    queue<node> q;
    q.push(N[i]);
    int curcnt = 1;
    int nextcnt = 0;
    int ly = 0;
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        if (vis[top.data])
            continue;
        vis[top.data] = true;
        curcnt--;
        for (int i = 0; i < top.child.size(); ++i)
        {
            if (!vis[top.child[i]])
            {
                q.push(N[top.child[i]]);
                nextcnt++;
            } 
        }
        if (curcnt == 0)
        {
            ly++;
            curcnt = nextcnt;
            nextcnt = 0;
        }
    }
    return ly;
}

void unionFind(int a, int b)
{
    int t1 = findFa(a);
    int t2 = findFa(b);
    if (t1 != t2)
        father[t1] = t2;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        father[i] = i;
    for (int i = 0; i < n-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        unionFind(a, b);
        N[a].data = a;
        N[b].data = b;
        N[a].child.push_back(b);
        N[b].child.push_back(a);
    }
    set<int> res;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        res.insert(findFa(i));
    if (res.size() > 1) 
        printf("Error: %d components\n", res.size()); 
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            memset(vis, false, sizeof(vis));
            int dp = bfs(i);
            if (dp > maxdp)
            {
                maxdp = dp;
                ans.clear();
                ans.push_back(i);
            }
            else if (dp == maxdp)
                ans.push_back(i);
        }
        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << endl; 
    } 
    system("pause");
    return 0;
}