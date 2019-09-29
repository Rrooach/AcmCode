#include <bits/stdc++.h>

using namespace std;

string muti (string a, string b)
{
    int n = a.length(), m = b.length();
    if (n == 1 && a[0] == '0' || m == 1 && b[0] == '0')
        return "0";
    string res(n + m, '0');
    for (int i = n, l = n + m - 1, carry = 0; i-- || carry; --l)
    {
        for (int j = m, k = l; j || carry; )
        {
            if (j)
                carry += (a[i] - '0') * (b[--j] - '0') + res[k] - '0';
            res[k--] = carry % 10 + '0';
            carry /= 10;
        }
    }
    if (res[0] == '0')
        res.erase(0, 1);
    return res;
}

int main(){ 
    system("pause");
    return 0;
 }        