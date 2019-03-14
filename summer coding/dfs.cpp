#include <iostream>
#include <cstdlib>
#include  <string>
#include <algorithm>
#define N 1000
#define INF  0x3f3f3f3f

using namespace std;
int num;
int in_order[N];
int post_order[N];
bool read()
{
	int num=0;
	char e;
	
	if(scanf("%d%c",&in_order[num],&e)==EOF) return false;
	num++;
	while (e!='\n')
	{
		scanf("%d%c",&in_order[num],&e);
		num++;
	}
	for (int i=0;i< num;i++)
		scanf("%d",&post_order[i]);	
	return true;
}

int build(L1,L2,R1,R2)
{
	if(L1<R1) return 0;
	int root=post_order[R2];
	
	int p=L1;
	while (in_order[p]!=root) p++;
	
	int cnt=p-L1;
	lch[root]=build(L1,p-1,L2+cnt-1);
	rch[root]=build(p+1,R1,L2+cnt,R2-1);
}

int best,sum_best;

void dfs(int u,int sum)
{
	sum+=u;
	if(!lch[u]&&!rch[u]) 
		if(sum<best_sum||sum==best_sum&&u<best)
		{
			best=u;
			best_sum=best;
		 } 
	if(lch[u]) dfs();
	if(rch[u]) dfs();
}

int main()
{
	if(read())
	{
		build(0,num-1,0,num-1);
		int best=0;
		dfs();
		cout<<best<<"\n";
	}
	
	
	
	
	return 0;
}
