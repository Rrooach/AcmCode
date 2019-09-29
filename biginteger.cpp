#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int makesameLen(string &a, string &b)
{
    int len1 = a.length();
    int len2 = b.length();
    if (len1 < len2)
    {
        for (int i = 0; i < len2-len1; ++i)
        {
            a = '0' + a;
        } 
        return len2;
    }
    if (len2 < len1)
    {
        for (int i = 0; i < len1 - len2; ++i)
        {
            b = '0' + b;
            // b.insert(b.begin(), '0');
        }
        return len1;
    }
}

string add(string a, string b)
{
    int len1 = a.length(), len2 = b.length();
    int i = len1 - 1, j = len2 - 1;
    int num, carry = 0;
    string res = "";
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int num1 = i < 0 ? 0 : a[i] - '0';
        int num2 = j < 0 ? 0 : b[j] - '0';
        num = num1 + num2 + carry;
        res.insert(res.begin(), (num % 10) + '0');
        carry = num / 10;
        i--, j--;
    }
    return res;
}

string sub(string a, string b)
{
    bool sign = true;
    int len1 = a.length();
    int len2 = b.length();
    if (a == b)
        return "0";
    if (len1 < len2 && (len1 == len2 || a < b))
    {
        swap(a, b);
        swap(len1, len2);
        sign = false;
    }
    int num, carry = 0, num1, num2;
    int i = len1 - 1, j = len2 - 1;
    string res = "";
    while (i >= 0 || j >= 0)
    {
        num1 = i >= 0 ? a[i] - '0' : 0;
        num2 = j >= 0 ? b[j] - '0' : 0;
        num = num1 - num2 + carry;
        carry = 0;
        if (num < 0)
        {
            num += 10;
            carry = -1;
        }
        res.insert(res.begin(), (num%10) + '0');
        --i, --j;
    }
    string :: iterator it = res.begin();
    while (*it == 0 && it != res.end())
        it++;
    res.erase(res.begin(), it);
    return sign ? res : '-' + res;
}

string swift(string a, int len)
{
    if (a == "0")
        return a;
    for (int i = 0; i < len; ++i)
        a += '0';
    return a;
}

string muti(string x, string y)
{
    int len = makesameLen(x, y);
    if (len == 0)
        return "0";
    if (len == 1)
    {
        return to_string((x[0] - '0') * (y[0] - '0'));
    }
    int mid = len / 2;
    // string x1 = x.substr(0, mid);
    // string x0 = x.substr(mid, len - mid);
    // string y1 = y.substr(0, mid);
    // string y0 = y.substr(mid, len - mid);

    // string z0 = muti(x0, y0);
    // string z1 = muti(add(x1, x0), add(y1, y0));
    // string z2 = muti(x1, y1);

    // string r1 = swift(z2, 2 * (len - mid));

    // string r2 = swift(sub(sub(z1, z2), z0), len - mid);
    // return add(add(r1, r2), z0);
    string a = x.substr(0, mid);
    string b = x.substr(mid, len - mid);
    string c = y.substr(0, mid);
    string d = y.substr(mid, len - mid);

    string z0 = muti(b, d);
    string z2 = muti(a, c);
    string z1 = sub(sub(muti(add(a, b), add(c, d)), z0), z2);

    string res = add(add(swift(z2, (len - mid) * 2), swift(z1, (len - mid))), z0);
    return res;
}

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        // string c = add(a, b);
        string c = muti(a, b);
        string ::iterator it = c.begin();
        while (*it == '0' && it != c.end())
            it++;
        c.erase(c.begin(), it);
        cout << c << endl;
    
        // cout << add(a, b) << endl << sub(a, b) << endl;
    }
    
    system("pause");
    return 0;
}