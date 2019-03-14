#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int ee=50;
const int e=99999999;
int n;
int a[ee]={0},f[ee][ee],root[ee][ee]={0};	//f(i,j)�������Ϊi,i+1,��,j�Ķ����������ӷ�

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
 ����һ�÷����������Ϊ��1,2,3,��,n���Ҽӷ���ߵĶ�����tree��Ҫ�������
��1��tree����߼ӷ�
��2��tree��ǰ�����
input:
��1�У�һ������n��n��30����Ϊ�ڵ������
��2�У�n���ÿո������������Ϊÿ���ڵ�ķ�����������100����
output:
��1�У�һ��������Ϊ��߼ӷ֣�������ᳬ��4,000,000,000����
��2�У�n���ÿո������������Ϊ������ǰ�������
*/ 
