#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int ee=50;
const int e=99999999;
int n;
int a[ee]={0},f[ee][ee],root[ee][ee]={0};	//f(i,j)中序遍历为i,i+1,…,j的二叉树的最大加分

void front (int x,int y)
{
	if (root[x][y]!=0)				cout <<root[x][y]<<" ";
	if(root[x][root[x][y]-1]!=0)    front(x,root[x][y]-1);
    if(root[root[x][y]+1][y]!=0)    front(root[x][y]+1,y);
}

int main()
{
	cin>>n;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			f[i][j]=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][i]=a[i];
		root[i][i]=i; 
	}
	for (int len=1;len<=n;len++)
		for (int i=1;i<=n;i++)
		{
			int j=i+len;
			if (j<=n) 
			{
				int temp=e;
				for (int k=i;k<=j;k++)
				{
					if (temp<f[i][k-1]*f[k+1][j]+a[k])
					{
						temp=f[i][k-1]*f[k+1][j]+a[k];
						root[i][j]=k;
					}
				}
				f[i][j]=temp;
			}
		}
	cout<<f[1][n];
	cout<<endl;
	front (1,n);
	return 0;
 } 
 
 /*
 试求一棵符合中序遍历为（1,2,3,…,n）且加分最高的二叉树tree。要求输出；
（1）tree的最高加分
（2）tree的前序遍历
input:
第1行：一个整数n（n＜30），为节点个数。
第2行：n个用空格隔开的整数，为每个节点的分数（分数＜100）。
output:
第1行：一个整数，为最高加分（结果不会超过4,000,000,000）。
第2行：n个用空格隔开的整数，为该树的前序遍历。
*/ 
