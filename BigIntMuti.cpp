#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
 
int makeSameLen(string &a, string &b)
{
    int l1 = a.length(), l2 = b.length();
    if (l1 < l2)
    {
        for (int i = 0; i < l2 - l1; ++i)
        {
            a = "0" + a;
        }
        return l2;
    }
    else
    {
        for (int i = 0; i < l1 - l2; ++i)
        {
            b = "0" + b;
        }
        return l1;
    }
}

string add(string a, string b)
{
    int l1 = a.length();
    int l2 = b.length();
    if (l1 <= 0)
        return b;
    if (l2 <= 0)
        return a;
    string res;
    int i = l1 - 1, j = l2 - 1;
    int num1, num2, sum, carry = 0;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        num1 = i >= 0 ? a[i] - '0' : 0;
        num2 = j >= 0 ? b[j] - '0' : 0;
        sum = num1 + num2 + carry;
        carry = sum / 10;
        res.insert(res.begin(), (sum % 10)+ '0');
        --i, --j;
    }
    return res;
}
 
string sub(string a, string b)
{
    bool sign = true;
    int l1 = a.length(), l2 = b.length();
    if (a == b)
        return "0";
    if (l1 < l2 || (l1 == l2 && a < b))
    {
        swap(a, b);
        swap(l1, l2);
        sign = false;
    }
    string res;
    int i = l1 - 1, j = l2 - 1;
    int num1, num2, sum, carry = 0;
    while (i >= 0  || j >= 0)
    {
        num1 = i >= 0 ? a[i] - '0' : 0;
        num2 = j >= 0 ? b[j] - '0' : 0;
        sum = num1 - num2 + carry;
        carry = 0;
        if (sum < 0)
        {
            sum += 10;
            carry = -1;
        }
        res.insert(res.begin(), (sum) + '0');
        --i, --j;
    }
    string :: iterator it = res.begin();
    while (it != res.end() && *it == '0')
        ++it;
    res.erase(res.begin(), it);
    return sign ? res : '-' + res;
}

string ShiftString(string num, int len)
{
    if (num == "0")
        return num;
    for (int i = 0; i < len; ++i)
        num += "0";
    return num;
} 

string muti(string a, string b)
{
    int len = makeSameLen(a, b);
    if(len == 0)
        return "0";
    if (len == 1)
    {
        return to_string((a[0] - '0') * (b[0] - '0'));
    }
    int mid = len / 2;
    string x1 = a.substr(0, mid);
    string x0 = a.substr(mid, len - mid);
    string y1 = b.substr(0, mid);
    string y0 = b.substr(mid, len - mid);

    string z0 = muti(x0, y0);
    string z1 = muti(add(x1, x0), add(y1, y0));
    string z2 = muti(x1, y1);

    string r1 = ShiftString(z2, 2 * (len - mid));

    string r2 = ShiftString(sub(sub(z1, z2), z0), len - mid);
    return add(add(r1, r2), z0);
}

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        string res = muti(a, b);
        cout << res << endl;
    }
    system("pause");
    return 0;
}
