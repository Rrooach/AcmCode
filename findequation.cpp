#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, tar;
bool flag = false;
int minn = INT_MAX;
string ops[2] = {"+", "*"};

bool cal (vector<string> a)
{
    int sum = 0;
    int len = a.size();
    for (int i = 0; i < len; ++i)
    {
        if (!(a[i] == "+" || a[i] == "*"))
        {
            sum += stoi(a[i]);
        }
        else
        {
            if (a[i] == "+")
                continue;
            if (a[i] == "*")
            {
                sum = sum * stoi(a[i + 1]);
                i++;
            }
        }
    }
    if (sum == tar)
        return true;
    else
    {
        if (sum < minn && sum > tar)
        {
            minn = sum;
        }
        return false;
    }
    
}

bool solve(vector<string> a, int start, int end)
{
    if (start > end)
    {
        if (cal(a))
        {
            for (auto it : a)
                cout << it;
            flag = 1;
            return true;
        }
        return false;
    }
    for (int i = 0; i < 2; ++i)
    {
        a.insert(a.begin() + start + 1, ops[i]);
        solve(a, start + 2, n);
        if (flag)
            return true;
        for (int j = a.size()-1; j >= 0; --j)
        {
            if (a[j] == "*" || a[j] == "+")
            {
                a.erase(a.begin() + j);
                break;
            }
        } 
    }
}
/*
4 235
34 12 5 5
*/
int main()
{
    while (cin >> n >> tar)
    {
        vector<string> a;
        for (int i = 0; i < n; ++i)
        {
            string t;
            cin >> t;
            a.push_back(t);
        }
        int len = a.size();
        solve(a, 0, len);
    }
    system("pause");
    return 0;
}