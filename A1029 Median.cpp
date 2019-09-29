#include <bits/stdc++.h>

using namespace std;

int main()
{
    int  n, m;
    scanf("%d", &n);
    int a[n+5];
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    int b[m+5];
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    a[n] = b[m] = 0x3f3f3f;
    int mid = (n + m - 1) / 2;
    int cnt = 0, i = 0, j = 0; 
    int temp = 0;
    while (cnt <= mid)
    {
        if (a[i] < b[j])
            i++;
        else
            j++;
        cnt++;
    }
    if (a[i] < b[j])
        temp = a[i];
    else
        temp = b[j];
    cout << temp << endl;
    system("pause");
    return 0;
}