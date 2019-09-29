#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll res[67][67] = {0};
// n^2时间复杂度，数据范围在n=67，m=33时溢出
ll func1(ll n, ll m)
{
    if (m == 0 || m ==n)
        return 1;
    if (res[n][m] != 0)
        return res[n][m];
    return res[n][m] = func1(n - 1, m) + func1(n - 1, m - 1);
}
//on时间复杂度，数据范围在n=62，m=31时溢出
ll func2(ll n, ll m)
{
    ll ans = 1;
    for (ll i = 1; i <= m; ++i)
        ans = ans * (n - m + i) / i;
    return ans;
}
//如果实在溢出，用大Lucas定理做                                                                                                                    453 
int main()
{
    ll n, m;
    cin >> n >> m;
    ll res1 = func1(n, m);
    cout << res1 << endl;
    ll res2 = func2(n, m);
    cout << res2 << endl;
    system("pause");
    return 0;
}