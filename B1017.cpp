#include <bits/stdc++.h>

using namespace std;

#define N 100050

struct node{
    int d[N];
    int len;
};

node muti(string a)
{
    node c;
    int len = a.length();
    reverse(a.begin(), a.end()); 
    int carry = 0; 
    for (int i = 0; i < len; ++i)
    {
        int temp = 0;
        temp += carry + (a[i] - '0') +( a[i] - '0');
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0)
    {
        c.d[c.len++] = carry %10;
        carry /= 10;
    }
    return c;
}

int main()
{
    string a;
    cin >> a;
    node big = muti(a);
    node res = big;
    reverse(res.d, res.d + res.len);
    sort(a.begin(), a.end());
    int b[N];
    int len = a.length();
    for (int i = 0; i < len; ++i)
        b[i] = a[i] - '0';
    int flag = 1;  
    sort(big.d, big.d + big.len);
    if (big.len != len)
    {
        cout << "No\n";
        for (int i = 0; i < res.len; ++i)
            cout << res.d[i]; 
    }
    else
    {
        for (int i = 0; i < len; ++i)
            if (big.d[i] != b[i])
                flag = 0;
        if (flag == 0)
        {
            cout << "No\n";
            for (int i = 0; i < res.len; ++i)
                cout << res.d[i];
        }
        else
        {
            cout << "Yes\n";
            for (int i = 0; i < res.len; ++i)
                cout << res.d[i];
        }
    }
    
    cout << endl;
    system("pause");
    return 0;
}