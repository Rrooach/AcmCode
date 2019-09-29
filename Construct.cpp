
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
ll ind[108];
ll cnt[108];

ll getcnt(ll p, ll x)
{
    ll res = 0;
    while (x)
    {
        res += x / p;
        x /= p;
    }
    return res;
}

int main()
{
    ll n, m;
    while(cin >> n >> m){
        int mm = m;
        for (int i = 1; i <= 25; i++)
        {
            while (mm % prime[i] == 0)
            {
                ind[prime[i]]++;
                mm /= prime[i];
            }
        }
        for (int i = 1; i <= 25; i++)
        {
            if (ind[prime[i]])
            {
                cnt[prime[i]] = getcnt(prime[i], n);
            }
        }
        ll ans = 1e18 + 1;
        for (int i = 1; i <= 25; i++)
        {
            if (ind[prime[i]])
            {
                ans = min(ans, cnt[prime[i]] / ind[prime[i]]);
            }
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}