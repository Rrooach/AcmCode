#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
#define N 1000

using namespace std;
//��һ��c�����ʾÿһ��c[j]=i��ʾ�ʺ��ڵ�j�е�i�е�λ���� 
int n,cnt=0,c[N];
//nΪ�ʺ������ 
void search(int cur)
{
	if (cur==n) cnt++;		//���ݹ�߽磬���˴����лʺ󶼲���ͻ�� 
	//��һ������ѭ������ÿһ��Ԫ�أ���ok���б�ǣ��������killing zone ��ok=0����������else ���еݹ� 
	else for (int i=0;i<n;i++)
		{
			int ok=1;
		 	c[cur]=i;		 	
		 	for (int j=0;j<cur;j++)
		 		if (c[cur]==c[j]||cur-c[cur]==j-c[j]||cur+c[cur]==j+c[j])
		 		{	//ͬһ��       ͬһб�ߣ�45�㣩    ͬһб�ߣ�-45�㣩 
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
