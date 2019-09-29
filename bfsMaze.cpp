#include <bits/stdc++.h>
#define maxn 1000
using namespace std;
int n, m;
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, -1, 0, 1};
char mmp[maxn][maxn];
bool vis[maxn][maxn];
struct node{
    int x;
    int y;
    int step;
};
struct node S, T, res;

bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] == true || mmp[x][y] == '*')
        return false; 
    return true; 
}
void bfs()
{
    struct node N;
    N = S; 
    queue<struct node> q;
    q.push(N);
    while (!q.empty())
    {
        struct node NN = q.front();
        q.pop();
        if (NN.x == T.x && NN.y == T.y)
        {
            cout << NN.x << ends << NN.y << endl;
            cout << NN.step << endl;
            return;
        }
        for (int i = 0; i < 4; ++i)
        {
            int t1 = NN.x + dir_x[i];
            int t2 = NN.y + dir_y[i];
            if (check(t1, t2))
            {
                N.step = NN.step + 1;
                N.x = t1, N.y = t2;
                q.push(N);
                vis[t1][t2] = true;
            }
        }
    }
}

int main()
{
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> mmp[i][j];
            if (mmp[i][j] == 'S')
                S.x = i, S.y = j;
            if (mmp[i][j] == 'T')
                T.x = i, T.y = j;
        }
        getchar();
    }
    S.step = 0;
    bfs();
    system("pause");
    return 0;
}

/*
5 5
.....
.*.*.
.*S*.
.***.
...T*

*/