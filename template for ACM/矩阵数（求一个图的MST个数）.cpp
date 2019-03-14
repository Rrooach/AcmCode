#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 20
#define eps 1e-9
using namespace std;
int A[MAXN][MAXN],D[MAXN][MAXN];//AÊÇÁÚ½Ó¾ØÕóDÊÇ¶ÈÊý¾ØÕó 
double C[MAXN][MAXN];//»ù¶û»ô·ò¾ØÕó 
int T,n,m;
void in(int &x)
{
    x = 0;
    char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0',ch = getchar();
}
void gauss()
{
    int now = 1;
    for (int i = 1;i <= n;i++)
    {
        int x = now;
        while (fabs(C[x][now]) < eps && x <= n) x++;
        if (x == n + 1) 
        {
            puts("0");
            return;
        }
        for (int j = 1;j <= n;j++)  swap(C[now][j],C[x][j]);
        for (int j = now + 1;j <= n;j++)
        {
            double temp = C[j][now] / C[now][now];
            for (int k = 1;k <= n;k++)
                C[j][k] -= temp * C[now][k];
        }
        now++;
    }
    double ans=1;
    for (int i = 1;i <= n;i++) ans*=C[i][i];
    ans=fabs(ans);
    printf("%.0lf\n",ans);
}
int main()
{
    in(T);
    while (T--)
    {
        memset(A,0,sizeof(A));
        memset(D,0,sizeof(D));
        in(n);in(m);
        n--;
        for (int i = 1;i <= m;i++)
        {
            int u,v;
            in(u);in(v);
            D[u][u]++;D[v][v]++;
            A[u][v]++;A[v][u]++;
        }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                C[i][j] = D[i][j] - A[i][j];
        gauss();
    }
}
