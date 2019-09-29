#include <bits/stdc++.h>
#define maxn 100
using namespace std;
int n, v;
int c[maxn];
int dp[maxn];
int res[maxn][maxn];
int vis[maxn];
int main()
{
    cin >> n >> v;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = v; j >= c[i]; --j)
        {
            if (dp[j] < dp[j-c[i]] + c[i])
            {
                dp[j] = dp[j - c[i]] + c[i];
                res[i][j] = 1;
            }
            else
            {
                res[i][j] = 0;
            }
        }
    }
    
    if (dp[v] != v)
        cout << "No Solution\n";
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (res[i][j])
                {
                    vis[i] = 1;
                    break;
                }
            }
        }
        for (int i = n; i > 1; --i)
            if (!vis[i])
                cout << c[i] << " ";
        cout << endl;
    }

    
    system("pause");
    return 0;
}