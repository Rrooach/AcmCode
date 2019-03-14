#include <bits/stdc++.h>

using namespace std;
//利用二分思想
long long qmuti1(int a, int b, int m)
{
    if (b == 0) return 1;
    if (b & 1) 
        return a * qmuti1(a, b-1, m) % m;
    else
    {
        long long muti = qmuti1(a, b/2, m);
        return (muti * muti) % m;
    }
}
//利用二进制，判定b的最低位是否为1
long long qmuti2(int a, int b, int m)
{
    long long ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = ans * a % m;
        a  = a * a % m;
        b >>= 1;
    }
    return ans;
}


int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    long long res = qmuti1(a, b, m);
    cout << "qmuti1: " << res << endl;
    res = qmuti2(a, b, m);
    cout << "qmuti2: " <<  res;
    system("pause");
    return 0;
}