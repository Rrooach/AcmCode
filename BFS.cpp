#include <bits/stdc++.h>
#define maxn 100
using namespace std; 
int n, m;
int mmp[maxn][maxn];
bool vis[maxn][maxn];
int a[4] = {-1, 0, 1, 0};
int b[4] = {0, -1, 0, 1};
struct node {
    int x;
    int y;
};

bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] == true || mmp[x][y] == 0)
        return false;
    return true;
}

void bfs(int x, int y)
{
    struct node Node;
    Node.x = x, Node.y = y;
    queue<struct node> q; 
    q.push(Node);
    while (!q.empty())
    {
        struct node N = q.front();
        q.pop();
        int t1, t2;
        for (int i = 0; i < 4; ++i)
        {
            t1 = Node.x + a[i], t2 = Node.y + b[i];
            if (check(t1, t2))
            {
                Node.x = t1, Node.y = t2;
                q.push(Node);
                vis[t1][t2] = true;
            }
        }
    }
}

int main()
{
    memset(vis, false, sizeof(vis));
    int ans = 0;
    cin >> n >> m; 
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> mmp[i][j];  
         
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mmp[i][j] == 1 && vis[i][j] == false)
            {
                vis[i][j] = true;
                ans++;
                bfs(i, j);
            } 
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}

/*
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
*/