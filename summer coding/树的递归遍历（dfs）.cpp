#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <sstream>
#define N 100010

using namespace std;

int in_order[N],post_order[N],lch[N],rch[N];
int n;		//*********??干什么用的 

//先序遍历用L1,L2...Ln表示
//后序遍历用R1,R2...Rn表示 

//*******************为什么要将可以用数组保存的信息用字符串数组保存并转化为字符流 
bool read_list (int *a)
{
	string line ;
	if(!getline (cin,line)) return false;
	stringstream ss(line);
	n=0; int x;
	while(ss>>x) a[n++]=x;
	return n>0; 
}
//read_list中将in_order&&post_order 进行了初始化与赋值 
//build中 将中序遍历与后序遍历建立成一棵二叉树并返回树根 

int build(int L1,int R1,int L2,int R2)
{
	if(L1>R1) return 0;		//左子树不能大于右子树 
	int root=post_order[R2];	//根就是后序遍历的最后一个 
	//找到中序遍历的根是排在第几位 
	int p=L1;
	while (in_order [p]!=root) p++;
	
	int cnt=p-L1;	//中序遍历中左边的剩余数字的个数 
 	//值为root的左孩子 
	lch[root] = build(L1,p-1,L2,L2+cnt-1);
	//值为root的右孩子 
	rch[root] = build(p+1,R1,L2+cnt,R2-1);
	return root;	 		
} 

int best,best_sum;

void dfs(int u,int sum)
{
	sum+=u;
	
	if(!lch[u]&&!rch[u])	//判断是不是叶子 （为0的时候即为空树，此时树到达最低层，即为叶子） 
	{
		if(sum<best_sum||sum==best_sum&&u<best)		//更新best 
		{
			best=u;
			best_sum=best;
		}
	}
	//若不为叶子则继续深入 
	//**********************哪里用到dfs的思想？不应该用stack进行求解？  
	if(lch[u]) dfs(lch[u],sum);
	if(rch[u]) dfs(rch[u],sum);
}

int main()
{
	while (read_list(in_order))
	{
		read_list(post_order);
		//*********从0到n-1进行建树 
		build(0,n-1,0,n-1);		//L1 L2为先序遍历所需   R1 R2为后序遍历所需 
		best_sum=10000000;
		dfs(post_order[n-1],0);
		cout<<best<<"\n";
	}
	
	return 0;
}
