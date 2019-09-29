#include <bits/stdc++.h>

using namespace std;

int mode = 1000000007;

int main()
{
    string a;
    cin >> a;
    int len = a.length();
    int p[len] = {0}; 
    int j = 0;
    for (int i = 0; i < len; ++i)
    {
        if (i > 0)
            p[i] = p[i - 1];
        if (a[i] == 'P')
            p[i]++;
    }
    int t = 0, ans = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        if (a[i] == 'T')
            t++;
        if (a[i] == 'A')
            ans += (p[i] * t);
        ans %= mode;
    }
    cout << ans%mode << endl;
    system("pause");
    return 0;
}