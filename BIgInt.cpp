#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int makeSameLen(string &a, string &b)
{ 
    int len1 = a.length();
    int len2 = b.length();
    if (len1 < len2)
    {
        int diff = len2 - len1;
        for (int i = 0; i < diff; ++i)
            a = "0" + a;
        return len2;
    }
    else
    {
        int diff = len1 - len2;
        for (int i = 0; i < diff; ++i)
            b = "0" + b;
        return len1;
    } 
}

string swift(string &a, int len)
{
    if (len == 0)
        return a;
    string res = a;
    for (int i = 0; i < len; ++i)
        res.insert(res.end(), '0');
    return res;
}

string add(string a, string b)
{
    string res = "";
    int len1 = a.length();
    int len2 = b.length();
    if (len1 == 0)
        return b;
    if (len2 == 0)
        return a;
    int i = len1 - 1, j = len2 - 1, carry = 0;
    int sum, num1, num2;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        num1 = (i >= 0) ? a[i]-'0' : 0;
        num2 = (j >= 0) ? b[j]-'0' : 0;
        sum = num1 + num2 + carry;
        carry = sum / 10;
        res.insert(res.begin(), (sum % 10)+'0');
        i--, j--;
    }
    if (carry > 0)
    {
        res.insert(res.begin(), carry % 10+'0');
    }
    return res;
}
 
string sub(string a, string b)
{
    bool sign = true;
    int len1 = a.length(), len2 = b.length();
    if (len1 < len2)
    {
        swap(len1, len2);
        swap(a, b);
        sign = false;
    }
    string res;
    int i = len1 - 1, j = len2 - 1;
    int num1, num2, sum, carry = 0;
    while (i >= 0 || j >= 0)
    {
        num1 = (i >= 0) ? a[i] - '0' : 0;
        num2 = (j >= 0) ? b[j] - '0' : 0;
        sum = num1 - num2 + carry;
        carry = 0;
        if (sum < 0)
        {
            sum += 10;
            carry = -1;
        }
        res.insert(res.begin(), (sum % 10) + '0');
        i--, j--;
    }
    auto it = res.begin();
    while (it != res.end() && *(it) == 0)
        it++;
    res.erase(res.begin(), it);
    return sign == true ? res : '-' + res;
}

string muti(string x, string y)
{

    int len = makeSameLen(x, y);
    int mid = len / 2;
    if (len == 0)
        return "0";
    if (len == 1)
    {
        return to_string((x[0] - '0') * (y[0] - '0'));
    }
    string a = x.substr(0, mid);
    string b = x.substr(mid, len - mid);
    string c = y.substr(0, mid);
    string d = y.substr(mid, len - mid);

    string fir = muti(a, c);
    string thr = muti(b, d);
    string sec = sub(sub(muti(add(a, b), add(c, d)), fir), thr);

    string r1 = swift(fir, 2*(len-mid));
    string r2 = swift(sec, len - mid);
    string res = add(add(r1, r2), thr);
    return res; 
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