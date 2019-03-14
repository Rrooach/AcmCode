#include <iostream>
#include <cstdio>
#include <cstring> 
#include <cstdlib>
#include <vector>
#define N 10000 
#define INF 0x3f3f3f
using namespace std;

int d[N];
int v[N];
int w[N][N];
int fa[N];

int main()
{
	int n;
	cin>>n;
	memset (v,0,sizeof (v));
	d[0]=0;
	for (int i=1;i<n;i++) d[i]=INF;
	for (int i=0;i<n;i++)
	{
		int x,m=INF;
		for (int y=0;y<n;y++)
			if (!v[y]&&d[y]<=m) m=d[x=y];
		v[x]=1;
		for (int y=0;y<n;y++)
			if (d[y]>d[x]+w[x][y])
			{
				d[y]=d[x]+w[x][y];
				fa[y]=x;
			}
	}
	return 0;
}
