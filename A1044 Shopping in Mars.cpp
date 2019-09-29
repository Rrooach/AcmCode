#include <bits/stdc++.h>

using namespace std;  

int main()
{
    int n, m, nearS = 100000010;
    scanf("%d%d", &n, &m);
    int s[n+5] = {0};
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        int j = upper_bound(s + i, s + n + 1, s[i - 1] + m) - s;
        if (s[j - 1] - s[i - 1] == m)
        {
            nearS = m;
            break;
        }
        else if (s[j] - s[i - 1] < nearS && j <= n)
            nearS = s[j] - s[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        int j = upper_bound(s + i, s + n + 1, s[i - 1] + nearS) - s;
        if (s[j - 1] - s[i - 1] == nearS)
            cout << i  << "-" << j - 1 << "\n";
    }
    system("pause");
    return 0;
}