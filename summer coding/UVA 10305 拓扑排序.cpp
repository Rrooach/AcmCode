#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream> 
#define N 10000
 
using namespace std;

int m,n,a,b,t;
int G[N][N],c[N],res[N];	//G->存储，c->访问，res->result 

bool dfs(int i){ 
	c[i]=-1;	//作为访问标志，进行dfs时有用 
	for (int j=0;j<n;j++)
		if (G[i][j])
			if (c[j]<0) return false;
			else if (!c[j]&&!dfs[j]) return false;
	c[i]=1;
	res[t--]=i;
	
}
 
bool toposort()
{
	t=n;
	memset (c,0,sizeof (c));
	for (int i=0;i<n;i++)
		if (!c[i])		//判断是否访问	
			if (!dfs(i)) return false;
	return true;
}

int main()
{
	//输入 
	while (cin>>m,n)
	{
		if (m==0||n==0) break;
		for (int i=0;i<n;i++)
		{
			cin>>a,b;
			G[a-1][b-1]=1;
		}
	//拓扑排序 
	toposort();
	//输出 
	for (int i=0;i<n;i++)
		printf("%d",res[i]);
	}
	
	return 0;
}
