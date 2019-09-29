#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

string ops[4] = {"+", "-", "*", "/"};
int tar;
int flag = 0;
int cal(vector<string> a)
{
    int len = a.size();
    stack<double> t;
    for (int i = 0; i < len; ++i)
    {
        if (!(a[i] == "+" || a[i] == "-" || a[i] == "*" || a[i] == "/"))
        {
            t.push(stod(a[i]));
        }
        else if (a[i] == "+")
        {
            continue;
        }
        else if (a[i] == "-")
        {
            double b = stod(a[i+1]);
            t.push(-b);
            i++;
        }
        else if (a[i] == "*" || a[i] == "/")
        {
            double b = stod(a[i+1]);
            
            double c = t.top();
            t.pop();
            if (a[i] == "*")
                t.push(b * c);
            if (a[i] == "/")
                t.push(c / b);
            i++;
        }  
    }
    double sum;
    while (!t.empty())
    {
        sum += t.top();
        t.pop();
    }
    return sum;
}

bool solve(vector<string> s, int start, int n)
{
    if (start >= n+1)
    {
        if(cal(s) == tar)
        {
            flag = 1;
            return true;
        } 
        return false;
    }
    for (int i = 0; i < 4; ++i)
    {
        s.insert(s.begin() + start + 1, ops[i]);
        solve(s, start+2, n);
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/")
            {
                s.erase(s.begin() + i);
                break;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("thuSE16_03.txt", "r", stdin);
#endif
    int n;
    while (cin >> n)
    {
        vector<string> s; 
        for (int i = 0; i < n; ++i)
        {
            string t;
            cin >> t;
            s.push_back(t);
        }
        cin >> tar;
        solve(s, 0, n);
        if (flag)
            cout << "1\n";
        else
            cout << "0\n"; 
    }
    system("pause");
    return 0;
}