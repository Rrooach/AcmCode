#include <bits/stdc++.h>
#define maxn 10
#define INF 0x3f3f3f
using namespace std;
int n;
int num[maxn];
int dp[maxn];

void LIS1()
{
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        for (int j = 1; j < i; ++j)
        {
            if (num[i] >= num[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    LIS1();
    int maxx = -1;