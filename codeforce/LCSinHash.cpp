#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
const int p = 1000007;
const int mod = 100000009;
string a, b;
int po[maxn];
int h1[maxn], h2[maxn];
map<int, int> mmp;

void calH(int h[], string a)
{
    fill(h, h + maxn, 1);
    for (int i = 1; i <= a.length(); ++i)
        h[i] = (h[i - 1] * p) + a[i] - 'a';
    
}

void calHij(int h[], string a)
{
    for (int i = 1; i <= len; ++i)
    {
        for (intx                  j = i; j <= len; ++j)
        {
            int hashV = calString(h, i, j);
            mmp.
        }
    }
}

int main()
{
    cin >> a >> b;
    int len = max(a.length(), b.length());
    po[0] = 1;
    for (int i = 1; i <= len; ++i)
        po[i] = (po[i - 1] * p) % mod;
    calH(h1, a);
    calH(h2, b);
    calHij(h1, a);
    calHij(h2, b);
    system("pause");
    return 0;
}