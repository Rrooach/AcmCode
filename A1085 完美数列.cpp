#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n + 5];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int j = upper_bound(a + i, a + n, a[i] * m) - a;
        // int l = i, r = n;
        // while (l < r)
        // {
        //     int mid = (l+r) >> 1;
        //     if (a[mid] <= a[i] * m)
        //         l = mid+ 1;
        //     else
        //         r = mid;
        // }
        ans = max(ans, j - i);
    }
        cout << ans;
    system("pause");
    return 0;
}