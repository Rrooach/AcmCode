#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream> 
#define N 10000
 
using namespace std;

int m,n,a,b,t;
int G[N][N],c[N],res[N];	//G->�洢��c->���ʣ�res->result 

bool dfs(int i){ 
	c[i]=-1;	//��Ϊ���ʱ�־������dfsʱ���� 
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
		if (!c[i])		//�ж��Ƿ����	
			if (!dfs(i)) return false;
	return true;
}

int main()
{
	//���� 
	while (cin>>m,n)
	{
		if (m==0||n==0) break;
		for (int i=0;i<n;i++)
		{
			cin>>a,b;
			G[a-1][b-1]=1;
		}
	//�������� 
	toposort();
	//��� 
	for (int i=0;i<n;i++)
		printf("%d",res[i]);
	}
	
	return 0;
}
