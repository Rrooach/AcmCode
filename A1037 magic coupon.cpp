#include <bits/stdc++.h>

using namespace std;

int main()
{ 
    int n, m;
    cin >> n;
    int a[n+10];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    int b[m+10];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m && a[i] < 0 && b[j] < 0)
        ans += a[i++] * b[j++];
    i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0 && a[i] > 0 && b[j] > 0)
        ans += a[i--] * b[j--];
    cout << ans << endl;
    system("pause");
    return 0;
}
/*
4
1 2 4 -1
4
7 6 -2 -3
*/
