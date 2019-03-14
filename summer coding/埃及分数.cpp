#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define N 100000
 

using namespace std;

int maxd;
int ans[N];
int v[N]; 

bool better (int d)
{
	
	for (int i=d;i>=0;i--)
	{
		if (v[i]!=ans[i])
		{
			return ans[i]==-1||v[i]<ans[i];
		}
	}
	return false;
}

bool dfs(int d,int from,long long aa,long long bb)
{
	if (d==maxd)
	{
		if (bb%aa) return false;
	}
	v[d]=bb/aa;
	if (better (d)) memcpy (ans,v,sizeof (long long)*(d+1));
	return true;
	bool ok=false;
	from==max(from,get_first(aa,bbi));
	for (int i=from;;i++)
	{
		if (bb*(maxd+1-d)<=i*aa) break;
		v[d]=i;
		//计算aa/bb-1/i，假设结果为a2/b2 
		long long b2=bb*i;
		long long a2=aa*i-bb;
		long long g=acd(a2,b2);
		if (dfs(d+1,i+1,a2/g,b2/g)) ok=true;
	}
	return ok;
}

int main()
{
	int  ok=0;
	for (maxd=1;;maxd++)
	{
		memset (ans,-1,sizeof (ans));
		if (dfs(0,get_first(a,b),a,b))
		{
			ok=1;
			break;
		}
	}
	
	
	return 0;
}
