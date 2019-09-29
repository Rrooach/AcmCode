#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int cnt;
vector<int> num;
bool cmp(int a, int b)
{
    return a > b;
} 
int main()
{
    cin >> cnt;
    for (int i = 0; i < cnt; ++i)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    int m, n;
    sort(num.begin(), num.end(), cmp);
    for (n = sqrt((double)cnt); n >= 1; n--)
    {
        if (cnt % n == 0)
        {
            m = cnt / n;
            break;
        }
    }
    if (m < n)
        swap(m, n);
    if (n == 1)
    { 
        for (int i = 0; i < cnt; i++)
            cout << num[i] << endl;
        return 0;
    }
    int mmp[m+1][n+1];
    int total = 0;
    int left = 0, right = n-1;
    int top = 0, botton = m-1;
    int r = 0, c = 0;
    while (1)
    {
        c = left;
        while (c <= right && total <= cnt)
            mmp[r][c++] = num[total++];
        top++, c--;
        r = top;
        while (r <= botton &&total <= cnt)
            mmp[r++][c] = num[total++];
        right--, r--;
        c = right;
        while (c >= left && total <= cnt)
            mmp[r][c--] = num[total++];
        botton--, c++;
        r = botton;
        while (r >= top && total <= cnt)
            mmp[r--][c] = num[total++];
        left++, r++;
        if (total >= cnt)
            break;
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n-1; ++j)
            cout << mmp[i][j] << " ";
        cout << mmp[i][n - 1] << endl;
    }
    system("pause");
    return 0;
}