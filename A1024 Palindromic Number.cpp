#include <bits/stdc++.h>
#define N 1000500
using namespace std;

int cnt = 0;
bool flag = true;
bool ishui(vector<int> a)
{
    int n = a.size();
    for (int i = 0, j = n - 1; i <= j; ++i, --j)
        if (a[i] != a[j])
            return false;
    return true;
}

vector<int> add(vector<int> a, vector<int> b)
{
    int l1 = a.size();
    int l2 = b.size();
    vector<int> ans;
    int len = 0;
    int carry = 0;
    for (int i = 0; i < l1 || i < l2; ++i)
    {
        int temp = a[i] + b[i] + carry;
        ans.push_back(temp%10);
        carry = temp / 10;
    }
    if (carry != 0)
        ans.push_back(carry);
    return ans;
}

int main()
{
    string num;
    int times;
    vector<int> res;
    cin >> num >> times;  
    int tt = times;
    vector<int> n;
    for (int i = 0; i < num.length(); ++i)
        n.push_back(num[i] - '0');
    reverse(n.begin(), n.end());
    while (cnt < times && !ishui(n))
    {
        vector<int> nen = n;
        reverse(nen.begin(), nen.end());
        n = add(n, nen);  
        cnt++;
    }

    reverse(n.begin(), n.end());
    if (flag == true)
    {
        for (int i = 0; i < n.size(); ++i)
            cout << n[i];
        cout << endl;
        cout << cnt << endl;
    }
    else  
    {
        for (int i = 0; i < n.size(); ++i)
            cout << n[i];
        cout << endl;
        cout << tt << endl;
    } 
    system("pause");
    return 0;
}