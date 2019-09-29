#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int num, lyer;
vector<vector<int>> mmp;
bool vis[maxn];

int bfs(int data)
{
    int curcnt = 1, nextcnt = 0;
    queue<int> q;
    q.push(data);
    int ly = 0, cnt = 0;
    while (!q.empty())
    {
        if (ly == lyer)
            return cnt;
        int top = q.front();
        q.pop();
        curcnt--;
        for (int i = 0; i < mmp[top].size(); ++i)
        {
            int d = mmp[top][i];
            if (!vis[d])
            {
                cnt++;
                vis[d] = true;
                nextcnt++;
                q.push(d);
            }
        }
        if (curcnt == 0)
        {
            curcnt = nextcnt;
            nextcnt = 0;
            ly++;
        } 
    }
}

int main()
{
    cin >> num >> lyer;
    mmp.resize(num+5);
    for (int i = 0; i < num+5; ++i)
        mmp[i].resize(0);
    for (int i = 1; i <= num; ++i)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; ++j)
        {
            int a;
            cin >> a;
            mmp[a].push_back(i);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        memset(vis, false, sizeof(vis));
        int q;
        cin >> q;
        vis[q] = true;
          int ans = bfs(q);
         cout << ans << endl;
    }
    system("pause");
    return 0;
}
