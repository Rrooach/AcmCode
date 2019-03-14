#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
int a[1005],b[1005],dp[1005],n,m;
 
int LICS()
{
    int i,j,MAX;
    memset(dp,0,sizeof(dp));
    for(i = 1; i<=n; i++)
    {
        MAX = 0;
        for(j = 1; j<=m; j++)
        {
            if(a[i]>b[j] && MAX<dp[j])
                MAX = dp[j];
            if(a[i]==b[j])
                dp[j] = MAX+1;
        }
    }
    MAX = 0;
    for(i = 1; i<=m; i++)
        if(MAX<dp[i])
            MAX = dp[i];
    return MAX;
}
 
int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i = 1;i<=n;i++)
        scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i = 1;i<=m;i++)
        scanf("%d",&b[i]);
        printf("%d\n",LICS());
    }
 
    return 0;
}

