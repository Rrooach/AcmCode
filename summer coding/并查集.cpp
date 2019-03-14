#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctdlib>
#define N 1111

using namespace std;

int fa[N],rank[N];
void init (int n)
{
	for (int i=1;i<=n;i++)
		fa[i]=i,rank[i]=1;
}

int find (int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void unite (int x,int y)
{
	x=find(x),y=find(y);
	if (x==y) return ;
	if (rank[x]>rank[y]) ra[y]=x;
	else 
	{
		fa[x]=y;
		if (rank[x]==rank[y]) rank[x]++;
	}
}

int main()
{
	
	
	return 0;
 } 
