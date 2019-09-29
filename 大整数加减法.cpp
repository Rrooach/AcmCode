#include <bits/stdc++.h>

using namespace std;

struct node
{
    int d[1000];
    int len;
    node (){
        memset(d, 0, sizeof(d));
        len = 0;
    } 
};

struct node change(string str)
{
    node a;
    a.len = str.length();
    for (int i = 0; i < a.len; ++i)
    {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}
/*
input:123
output :321
*/
node add(node a, node b)
{
    int carry = 0;
    node c;
    c.len = 0;
    for (int i = 0; i < a.len || i < b.len; ++i)
    { 
        int temp = a.d[i] + b.d[i] + carry;
        if (temp >= 10)
            c.d[i] = temp % 10;
        else
            c.d[i] = temp;
        carry /= 10;
        c.len++;
    }
    if (carry != 0)
        c.d[c.len++] = carry;
    return c;
}

/*
    2 3 4
    1 2 5
   -------
    1 0 9
*/
node deduct(node a, node b)
{
    node c; 
    for (int i = 0; i < a.len || i < b.len; ++i)
    {
        if (a.d[i] < b.d[i])
        {
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.d[c.len-1] == 0 && c.len >= 1)
        c.len--;
    return c;
}

int main()
{
    string a, b;
    cin >> a >> b;
    struct node n1 = change(a);
    struct node n2 = change(b);
    node res = add(n1, n2);
    res = deduct(n1, n2);
    for (int i = res.len-1; i >= 0; --i)
        cout << res.d[i] << ends;
    system("pause");
    return 0;
}