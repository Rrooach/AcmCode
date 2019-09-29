#include <bits/stdc++.h>

using namespace std;

int integerReplacement(int n)
{ 
    if (n == 0 || n == 1)
        return 0;
    vector<int> dp(n + 8, 0);
    dp[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (i % 2)
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = dp[i / 2] + 1;
    }
    return dp[n];
}
int main()
{
    cout << integerReplacement(8);
    system("pause");
    return 0;
}  