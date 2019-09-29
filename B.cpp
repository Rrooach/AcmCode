#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000000 - 1;
int t;
int main()
{
    cin >> t;
    while (t--)
    {
        long long ans = 0;
        long long m, n;
        scanf("%d%d", &n, &m);
        m += 1, n += 1;
        if (n <= m)
            ans = n * (n * n - 1) * (2 * m - n) % (1000000000 - 1) / 12;
        else
            ans = m * (m * m - 1) * (2 * n - m) % (1000000000 - 1) / 12;
        ans %= (1000000000 - 1);
        cout << ans << endl;
    }
    // system("pause");
    return 0;
}