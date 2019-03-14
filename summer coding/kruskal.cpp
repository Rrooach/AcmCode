#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#define N 1000
using namespace std;

int w[N];
int p[N];
int r[N],u[N],v[N];
int n,m;

int cmp(const int i,const int j)
{
	return w[i]<w[j];
}

int find (int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}

int Kruskal()
{
	int ans=0;
	for (int i=0;i<n;i++) p[i]=i;
	for (int i=0;i<m;i++) r[i]=i;
	sort (r,r+m,cmp);
	for (int i=0;i<m;i++)
	{
		int e=r[i];
		int x=find (u[e]);
		int y=find (v[e]);
		if (x!=y) 
		{
			ans+=w[e];
			p[x]=y;
		}
	}
	return ans;
}

int main()
{
	
	
	return 0;
 } 
