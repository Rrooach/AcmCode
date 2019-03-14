#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
#define N 1000

using namespace std;
//用一个c数组表示每一列c[j]=i表示皇后在第j列第i行的位置上 
int n,cnt=0,c[N];
//n为皇后的数量 
void search(int cur)
{
	if (cur==n) cnt++;		//最后递归边界，到此处所有皇后都不冲突了 
	//用一个二重循环遍历每一个元素，用ok进行标记，如果在在killing zone ，ok=0，继续遍历else 进行递归 
	else for (int i=0;i<n;i++)
		{
			int ok=1;
		 	c[cur]=i;		 	
		 	for (int j=0;j<cur;j++)
		 		if (c[cur]==c[j]||cur-c[cur]==j-c[j]||cur+c[cur]==j+c[j])
		 		{	//同一列       同一斜线（45°）    同一斜线（-45°） 
		 			ok=0;
		 			break;
				 }
			if (ok) search(cur+1);
		}
				
}

int main()
{
	int cur=0;
	cin>>n;
	memset(c,0,sizeof(c));
	search (cur);
	return 0;
 } 
