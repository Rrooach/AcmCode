#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define INF 0x3f3f3f
#define N 1000
using namespace std;

double G[N][N],low[N];
int vis[N];

struct node {
	double x;
	double y;
} p[N];

void prim(int n)
{
	memset(vis,0,sizeof (vis));
	int pos=1;
	vis[pos]=1;
	double ans=0;
	for (int i=1;i<=n;i++)
		if (i!=pos)
			low[i]=G[pos][i];
	for(int i = 1; i < n; i++)  
    {  
        double Min = 0x7ffffff;  
        for(int j = 1; j <= n; j++)  
        {  
            if(!vis[j] && Min > low[j])  
            {  
                Min = low[j];  
                pos = j;  
            }  
        }  
        vis[pos] = 1;  
        ans += Min;  
        for(int j = 1; j <= n; j++)  
        {  
            if(!vis[j] && low[j] > G[pos][j])  
                low[j] = G[pos][j];  
        }  
    }  
    printf("%.2lf\n",ans);  
}

int main()
{
	double dis,x,y;
	int kase;
	while (scanf("%d",&kase)!=EOF)
	{
		for (int i=1;i<=kase;i++)
			for (int j=1;j<=kase;j++)
				G[i][j]=INF;
		memset(p,0,sizeof (p));
		for (int i=1;i<=kase;i++)
			cin>>p[i].x>>p[i].y;
		for (int i=1;i<=kase;i++)
			for (int j=1;j<=kase;j++)
			{
				x=p[i].x-p[j].x;
				y=p[i].y-p[j].y;
				dis=sqrt(x*x+y*y);
				G[i][j]=dis;
			}
		prim(kase);
	}
	return 0;
}  
