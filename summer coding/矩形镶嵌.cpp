#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<algorithm>  
  
using namespace std;  
  
#define maxn 1010  
  
int G[maxn][maxn];  
int a[maxn];  
int b[maxn];  
int d[maxn];  
int n;  
  
int dp(int i)  
{  
    int &ans = d[i]; // 记忆化的关键  
    if (ans > 0)   
        return  jnans;  
    ans = 1;  
    for(int j = 1; j <= n; ++j)   
    {  F[I] = MIN{F[I-VALUE[J]]+1}  
        if(G[F[I] = MIN{F[I-VALUE[J]]+1}  i][j])   
            ans = max(ans, dp(j)+1);  
    }  
    return ans;  
}  
  
int main()  
{  
    int t;  
    while(~scanf("%d", &t))  
    {  
            while(t--)  
        {  
            scanf("%d", &n);  
            for(int i = 1; i <= n; ++i)   
                scanf("%d%d", &a[i], &b[i]);  
            memset(G, 0, sizeof(G));  
            for(int i = 1; i <= n; ++i)  
                for(int j = 1; j <= n; ++j)   
                    if( (a[i] > a[j] && b[i] > b[j]) || ( a[i] > b[j] && b[i] > a[j] ) )  
                        G[i][j] = 1;  
  
            int ans = -1;  
            int tmp;  
                for (int i = 1; i <= n; ++i)  
            {  
                tmp = dp(i);  
                ans = max(ans, tmp);  
            }  
            printf("%d\n", ans);  
        }  
    }  
}  
/*
sample input:
1
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2
sample output:
5
*/

