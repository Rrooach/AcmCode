#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#define N 100000
using namespace std;

stack<int> s;
int G[N][N],vis[N][N];
int n; 
void euler (int u)
{
	for (int v=0;v<n;v++)
	{
		if (G[u][v]&&!vis[u][v])
		{
			vis[u][v]=vis[v][u]=1;
			euler(v);
			s.push(u,v);
		}
	}
}
int main()
{
	memset (G,0,sizeof (G));
	while (cin>>n)
	{
		if (n==0) break;
		euler (n);
	}
	return 0;
 } 
