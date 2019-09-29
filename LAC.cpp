#include <bits/stdc++.h>
#define maxn 100001
using namespace std;
int n;
int num[maxn]; 
int dp[maxn];
int s[maxn];
int main()
{
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i]; 
    }
    dp[0] = num[0];
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i-1] + num[i] > num[i])
        {
            dp[i] = dp[i - 1] + num[i];
            s[i] = s[i - 1];
        }
        else
        {
            dp[i] = num[i];
            s[i] = i;
        }
        
    }
        // dp[i] = max(num[i], dp[i-1] + num[i]);
    int maxx = -1;
    int pos = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (maxx < dp[i])
        {
            maxx = dp[i];
            pos = i;
        }
    } 
    cout << maxx << " ";
    cout << num[s[pos]] << " " << num[pos] << endl;
    system("pause");
    return 0;
}
/*
6
-2 11 -4 13 -5 -2
*/