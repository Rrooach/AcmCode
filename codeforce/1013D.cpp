#include<bits/stdc++.h>
using namespace std;
int n,m,q,cnt,f[400005];
int fnd(int x){return f[x]==0?x:f[x]=fnd(f[x]);}
int main()
{
	scanf("%d%d%d",&n,&m,&q);cnt=n+m-1;
	int a[2*n][n+m];
	memset (a,0,sizeof (a)); 
	for(int i=1,x,y;i<=q;i++)
	{
		scanf("%d%d",&x,&y);y+=n;
		x=fnd(x);y=fnd(y);
		a[x][y]=1;
		if(x!=y){cnt--;f[x]=y;}
	}
	for (int i = 0; i < 2*n; ++i)
	{
		for (int j = 0; j < 2*m; ++j)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	printf("%d\n",cnt);
	return 0;
}
