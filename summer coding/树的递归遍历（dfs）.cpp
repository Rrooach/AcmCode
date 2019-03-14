#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <sstream>
#define N 100010

using namespace std;

int in_order[N],post_order[N],lch[N],rch[N];
int n;		//*********??��ʲô�õ� 

//���������L1,L2...Ln��ʾ
//���������R1,R2...Rn��ʾ 

//*******************ΪʲôҪ�����������鱣�����Ϣ���ַ������鱣�沢ת��Ϊ�ַ��� 
bool read_list (int *a)
{
	string line ;
	if(!getline (cin,line)) return false;
	stringstream ss(line);
	n=0; int x;
	while(ss>>x) a[n++]=x;
	return n>0; 
}
//read_list�н�in_order&&post_order �����˳�ʼ���븳ֵ 
//build�� �����������������������һ�ö��������������� 

int build(int L1,int R1,int L2,int R2)
{
	if(L1>R1) return 0;		//���������ܴ��������� 
	int root=post_order[R2];	//�����Ǻ�����������һ�� 
	//�ҵ���������ĸ������ڵڼ�λ 
	int p=L1;
	while (in_order [p]!=root) p++;
	
	int cnt=p-L1;	//�����������ߵ�ʣ�����ֵĸ��� 
 	//ֵΪroot������ 
	lch[root] = build(L1,p-1,L2,L2+cnt-1);
	//ֵΪroot���Һ��� 
	rch[root] = build(p+1,R1,L2+cnt,R2-1);
	return root;	 		
} 

int best,best_sum;

void dfs(int u,int sum)
{
	sum+=u;
	
	if(!lch[u]&&!rch[u])	//�ж��ǲ���Ҷ�� ��Ϊ0��ʱ��Ϊ��������ʱ��������Ͳ㣬��ΪҶ�ӣ� 
	{
		if(sum<best_sum||sum==best_sum&&u<best)		//����best 
		{
			best=u;
			best_sum=best;
		}
	}
	//����ΪҶ����������� 
	//**********************�����õ�dfs��˼�룿��Ӧ����stack������⣿  
	if(lch[u]) dfs(lch[u],sum);
	if(rch[u]) dfs(rch[u],sum);
}

int main()
{
	while (read_list(in_order))
	{
		read_list(post_order);
		//*********��0��n-1���н��� 
		build(0,n-1,0,n-1);		//L1 L2Ϊ�����������   R1 R2Ϊ����������� 
		best_sum=10000000;
		dfs(post_order[n-1],0);
		cout<<best<<"\n";
	}
	
	return 0;
}
