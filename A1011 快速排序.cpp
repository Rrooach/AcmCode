#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100000 + 5;
int main()
{
    int n;
    scanf("%d", &n);
    int num[maxn]; 
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
    }
    int maxnum[maxn];
    int minnum[maxn];
    num[0] = 0;
    maxnum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        maxnum[i] = max(maxnum[i - 1], num[i - 1]);
    }
    num[n + 1] = INF;
    minnum[n + 1] = INF;
    for (int i = n; i >= 1; i--)
    {
        minnum[i] = min(minnum[i + 1], num[i + 1]);
    }
    int res[maxn]; 
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (maxnum[i] < num[i] && num[i] < minnum[i])
        {
            res[cnt] = num[i];
            cnt++;
        }
    }
    printf("%d\n", cnt);
    if (cnt >= 1)
        printf("%d", res[0]);
    for (int i = 1; i < cnt; i++)
    {
        printf(" %d", res[i]);
    }
    printf("\n"); //不加这个第三个测试竟然过不去
    return 0;
}