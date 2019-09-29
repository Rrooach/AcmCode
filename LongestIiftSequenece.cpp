#include <bits/stdc++.h> 
using namespace std;

const int maxn = 103, INF = 0x7f7f7f7f;
int a[maxn], f[maxn];
int n, ans = -INF;
int main()
{
    int n;
    while (cin >> n)
    { 
        vector<int> r;
        for (int i = 0; i < n; ++i)
        {
            int t;
            cin >> t;
            r.push_back(t);
        }
        int dp[n + 4] = {1};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (r[j] < r[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i]);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}