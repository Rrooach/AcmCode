#include <bits/stdc++.h>
#define maxn 100
using namespace std; 
string s;
int resC = -1, resL = -1;
int p[maxn];
string manacher(string s)
{
    memset(p, 1, sizeof(p));
    string t = "$#";
    int len = s.length();
    for (int i = 0; i < len; ++i)
    {
        t += s[i];
        t += '#';
    }
    int id = 0, mx = 0;
    //*****************一定从1开始**************
    for (int i = 1; i < t.size(); ++i)
    {
        p[i] = mx > i ? min(p[id * 2 - i], mx - i) : 1;
        while (t[i +p[i]] == t[i-p[i]])
            p[i]++;
        if (mx < i+p[i])
        {
            mx = i + p[i];
            id = i;
        }
        if (resL < p[i])
        {
            resL = p[i];
            resC = i;
        }
    }
    return s.substr((resC - resL) / 2, resL - 1);
}

int main()
{
    cin >> s;
    string ans = manacher(s);
    cout << ans << endl;
    system("pause");
    return 0;
}