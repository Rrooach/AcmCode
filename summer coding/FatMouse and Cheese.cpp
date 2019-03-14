#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define N 111

using namespace std;

int n,k;
int map[N][N];
int sum[N][N];
int dd[4][2]={0,1,0,-1,1,0,-1,0};

int dfs(int X,int Y)
{
	int l=0,x,y,m;
	for (int i=0;i<4;i++)
		for (int j=1;j<=k;j++)
		{
			x=X+dd[i][0]*j;
			y=Y+dd[i][1]*j;
			if (x>=0&&y>=0&&x<n&&y<n)
			{
				if (map[x][y]>map[X][Y])
				{
					m=dfs(x,y);
					l=max(l,m);
				}
			}
		}
		sum[X][Y]=l+map[X][Y];
		return sum[X][Y];
}

int main()
{
	while (cin>>n>>k)
	{
		if (n==-1&&k==-1) break;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				cin>>map[i][j];
		memset(sum,0,sizeof(sum));
		int l=dfs(0,0);
		cout<<l<<endl;	 
		
	 } 
	
	
	return 0;
}
