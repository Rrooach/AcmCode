#include <iostream>
using namespace std;
int id[10000];
int sz[10000];
int find (int p)
{
	while(p != id[p]) p = id[p];
	return p;
}
bool isConnect(int x,int y)
{
	return find(x) == find(y);
}
void unioned (int x,int y)
{
	int i = find (x);
	int j = find (y);
	if (i == j) return;
	if (sz[i] < sz[j])
	{
		id[i] = j;
		sz[j] +=sz[i];
	} 
	else
	{
		id[j] = i;
		sz[i] += sz[j];
	}
} 
int main ()
{	
	//n个人，m个亲戚关系，询问p对亲戚关系。
	int n,m,p;
	cin>>n>>m>>p;
	for (int i = 0;i<n;i++)
	{
		sz[i] = 1;
	}
	for (int i = 0;i<n;i++)
	{
		id[i] = i;
	}
	//合并a,b
	int a,b; 
	for (int i=0;i<m;i++)
	{
		cin>>a>>b;
		unioned(a,b);
	}
	//查询x,y
	int x,y;
	for (int i = 0;i < p;i++) 
	{
		cin>>x>>y;
		if (isConnect(x,y))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}	
	return 0;
 } 

