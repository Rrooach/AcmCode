#include <bits/stdc++.h>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;
string a, b;
int dp[maxn][maxn];

int main()
{
    cin >> a >> b;
    int lenA = a.length(), lenB = b.length();
    for (int i = 0; i <= lenA; ++i)
        dp[i][0] = 0;
    for (int i = 0; i <= lenB; ++i)
        dp[0][i] = 0;
    for (int i = 1; i <= lenA; ++i)
    {
        for (int j = 0; j <= lenB; ++j)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[lenA][lenB] << endl;
    system("pause");
    return 0;
}

/*
absort
abort

*/