#include <bits/stdc++.h>

using namespace std;
 
bool cmp(int a, int b)
{
    return a > b;
}

bool flag[100010] = {false};

void solve(int n)
{
    while(n != 1)
    {
        if(n&1)  n = (3*n+1)/2;
        else  n = n/2;
        if (flag[n] ==  true)
            break;
        else
            flag[n] = true;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n+10];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i]; 
        solve(a[i]);
    }
    vector<int> res;
    for (int i = 0; i < n; ++i)
    {
        if (flag[a[i]] == false)
            res.push_back(a[i]);
    }
    sort (res.begin(), res.end(), cmp);
    for (vector<int> :: iterator it = res.begin(); it != res.end(); ++it)
    {
        if (it != res.end() - 1)
            cout << *it << " ";
        else
            cout << *it << endl;
    }
    system("pause");
    return 0;
}