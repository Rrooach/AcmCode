#include <bits/stdc++.h>

using namespace std;
int n;
string process(string a)
{
    string res = "";
    while (a[0] == '0')
        a.erase(a.begin());
    int pos = 0, e = 0;
    if (a[0] == '.')
    {
        a.erase(a.begin());
        while (a[0] == '0')
        {
            a.erase(a.begin());
            e--;
        }
    }
    else
    {
        while (pos < a.length() && a[pos] != '.')
        {
            pos++;
            e++;
        }
        if (pos < a.length())
            a.erase(a.begin() + pos);
    }

    if (a.length() == 0)
        e = 0;
    int num = 0;
    pos = 0;
    res += "0.";
    while (num < n)
    {
        if (pos < a.length())
            res += a[pos++];
        else
            res += "0";
        num++;
    }
    res += "*10^";
    res += to_string(e);
    return res;
}


int main()
{
    scanf("%d", &n);
    string a, b;
    cin >> a >> b;
    string c, d;
    c = process(a);
    d = process(b);
    cout << c << endl
         << d;
