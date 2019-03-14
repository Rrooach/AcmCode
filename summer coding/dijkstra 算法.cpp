#include <iostream>
#include <cstdio>
#include <cstring> 
#include <cstdlib>
#include <vector>
#include <queue>
#define N 10  
#define INF 0x3f3f3f

using namespace std;
 
const int maxint = 32767;
 
int dis[N];
int prev[N];
int a[N][N];
int fa[N]={0};

int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin>>a[i][j]; 
	memset(prev,0,sizeof (prev));
	dis [0]=0;
	for (int i=1;i<n;i++)
		dis[i]=INF;
	for (int i=0;i<n;i++)
	{
		int x,m=INF;
		for (int y=0;y<n;y++)
			if (!prev[y]&&dis[y]<m) m=dis[x=y];
		for (int y=0;y<n;y++)
			if (dis[y]>dis[y]+a[i][y])
			{
				dis[y]=dis[y]+a[i][y];
				fa[y]=x;
			}
	}
	for (int i=0;i<sizeof (dis);i++)
		cout<<dis[i]<<" ";
	return 0;
}
