#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
struct node {
    int x, y, z; 
};
int mmp[1290][130][61];
bool vis[1290][130][61] = {false};
int m, n, l, t;
int ans = 0;
int dir_x[6] = {-1, 1, 0, 0, 0, 0};
int dir_y[6] = {0, 0, -1, 1, 0, 0};
int dir_z[6] = {0, 0, 0, 0, -1, 1};

bool check1(int x, int y, int z)
{
    if (x >= n || y >= m || z >= l || x < 0 || y < 0|| z < 0 )
        return false;
    if ( mmp[x][y][z] == 0 || vis[x][y][z] == true)
        return false;
    return true;
}
bool check(int x, int y, int z)
{
    if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l)
        return false;
    if (mmp[x][y][z] == 0 || vis[x][y][z] == true)
        return false;
    return true;
}

int bfs(int x, int y, int z)
{     
    int total = 0;
    queue<struct node> q;
    struct node N;
    N.x = x, N.y = y, N.z = z;
    q.push(N);
    vis[x][y][z] = true; 
    while (!q.empty())
    {
        struct node top = q.front();
        q.pop();
        total++;
        
        for (int i = 0; i < 6; ++i)
        {
            int x1, y1, z1;
            struct node temp;
            int tx = top.x + dir_x[i];
            int ty = top.y + dir_y[i];
            int tz = top.z + dir_z[i];
            if (check(tx, ty, tz))
            {
                vis[tx][ty][tz] = true;
                temp.x = tx, temp.y = ty, temp.z = tz;
                q.push(temp);
            }
        }
    }
    if (total >= t)
        return total;
    else
        return 0;
}

int main()
{ 
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < n; ++k)
                cin >> mmp[j][k][i];
    ans = 0;
    for (int i = 0; i < l; ++i) 
        for (int j = 0; j < m; ++j) 
            for (int k = 0; k < n; ++k)  
                if (mmp[j][k][i] == 1 && vis[j][k][i] == false) 
                    ans += bfs(j, k, i);  
    cout << ans << endl; 
    system("pause");
    return 0;
}