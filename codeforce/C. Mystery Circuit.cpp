#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, blood;
        cin >> n >> blood;
        int c[n + 5], b[n + 5], a[n + 5], tt[n+5];
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
            tt[i] = blood;
        } 
        int dp[n + 5];
        dp[0] = blood;
        for (int i = 1; i <= n; ++i)
        {

        }
    }
    return 0;
}