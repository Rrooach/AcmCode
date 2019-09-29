#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int in = 0;
int out = 0;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
void dfs(int step, int k, int n, int x, int y)
{
    if (x >= n || y >= n || x < 0 || y < 0)
    {
        if (step == k)
        {
            out++;
            return;
        }
        else
        {
            return;
        }
    }
    if (step == k && 0 <= x && x < n && 0 <= y &&& y < n)
    {
        in ++;
        return;
    }
    for (int i = 0; i < 8; ++i)
    {
        dfs(step + 1, k, n, x + dy[i], y + dx[i]);
    }
}

double knightProbability(int N, int K, int r, int c)
{
    dfs(0, K, N, r, c);
    return double(out / (in + out));
}
int main()
{ 
    knightProbability(3, 2, 0, 0);
    return 0;
}
 