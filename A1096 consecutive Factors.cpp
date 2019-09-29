#include <bits/stdc++.h>
#define ll long long

using namespace std; 

int main()
{
    ll n;
    ll start = 0, len = 0;
    scanf("%lld", &n);
    ll s = sqrt(n);
    for (int i = 2; i <= s; ++i)
    {
        int temp = 1, j = i;
        while (true)
        {
            temp *= j;
            if (n % temp != 0) break;
            if (j - i+1 > len)
            {
                start = i;
                len = j - i + 1;
            }
            j++;
        }
    }
    // cout << len << ends << start << endl;
    
    if (len == 0)
        cout << n << endl;
    else
    {
        cout << len << endl;
        for (int i = start; i < start + len; ++i)
            cout << i << ends;
    }
    system("pause");
    return 0;
}
 