#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define N 32000

using namespace std;

int fac[100][2];	//һ�ű�fac[i][0]�����������fac[i][1]����ָ�� 
int fac_c[100];
int a[N];

void factor (int m)		//�ֽ�m 
{
	 int & num=fac[0][0];	//�ñ�ͷ����ܸ��� 
	 num=0;
	 for (int i=2;i*i<=m;i++)
	 if (m%i==0)
	 {
	 	fac[++num][1]=i;
	 	fac[num][1]=0;
	 	do 
	 	{
	 		fac[num][1]++;
	 		m/=i;
		 }while (m%i==0);	//��i����ɾ� 
	 }
	 if (m>1)//����ֽ⵽���m��Ȼ����1,˵������һ��������ע�⣺���ֻ���ж�����������Щ������û�д˴��жϣ���������д˲�  
	 {
	 	fac[++num][0]=m;
	 	fac[num][1]=1;
	 }
}
//*********�� 
bool check (int n,int j)
{
	int num=fac[0][0];
	int a=n-j;
	int b=j;
	for (int i=1;i<=num;i++)
	{
		int p=fac[i][0];
		int &q=fac_c[i];
		for (; a%p == 0; a /= p, q++);//Ϊ�����Ч�ʣ�ֻ�ü���m�ķֽ�ʽ�е�����������  
        for (; b%p == 0; b /= p, q--);  
    }  
    for (int i = 1; i <= num;i++)  
    if (fac[i][1] > fac_c[i])  
        return false;  
    return true;  
}
 
int main()
{
	int m,n;
	while (cin>>n>>m)
	{
		int cnt=0;
		factor (m);
		memset(fac_c,0,sizeof (fac_c));
		for (int i=1;i<n;i++)
			if (check(n,i))
				a[cnt++]=i+1;
		cout<<cnt;
		for (int i=0;i<cnt;i++) 
			printf ("%s%d",i==0?"":"  ",a[i]);
		cout<<"\n";	 
	}
	return 0;
} 
