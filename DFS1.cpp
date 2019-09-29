#include <bits/stdc++.h>
#define maxn 30
using namespace std;
int w[maxn]; 
int max1 = 0;
int r1, r2;
int n, v;
void DFS(int index, int cnt, int sum)
{
    if (index +cnt > n)
        return;
    if (w[index] + w[index+cnt] == sum)
    {
        if (w[index] * w[index] + w[index + cnt] *w[index + cnt] > max1)
        {
            max1 = w[index] * w[index] + w[index + cnt] * w[index + cnt];
            r1 = index;
            r2 = index + cnt;
        }
    }
    DFS(index+1, cnt, sum);
    DFS(index, cnt + 1, sum);
}
int main()
{
    cin >> n >> v;
    for (int i = 0; i < n; ++i)
        cin >> w[i]; 
    DFS(0, 0, v);
    cout << r1 << ends << r2 << endl;
    cout << max1;
    system("pause");
    return 0;
}