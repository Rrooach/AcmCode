#include<cstdio >  
#include<cstring>  
#include <iostream>
#define N 50010  
using namespace std;

int phi[N],n,sum[N];  
void phi_table()  
{  
    int i,j;  
    memset(phi,0,sizeof(phi));  
    phi[1]=1;  
    for(i=2;i<=30;i++)  
    if(!phi[i])  
    for(j=i;j<=30;j+=i)  /*ɸ����ŷ������ֵ*/  
    {  
        if(!phi[j])  
            phi[j]=j;  
//        cout<<i<<" "<<j<<"\n";
        phi[j]=phi[j]/i*(i-1); /*phi[j]���治����j����j���ʵ��������ĸ���*/  
    }  
	sum[0]=0;  
    for(i=1;i<=50000;i++)  
        sum[i]=sum[i-1]+phi[i];  
}  
int main()  
{  
    int i; 
	cin>>i;
	phi_table();  
	for (int j=1;j<=i;j++)
		cout<<phi[j]<<" "; 
    int i;  
    while(~scanf("%d",&n)&&n)  
    {  
        printf("%d\n",2*sum[n]-1);  
    } 
    return 0;  
}  
 /*ת��Ϊ�ж��ٶ�ʱ��2��1���ʣ����ǣ�2,1���ͣ�1,2����2�ԣ�����Ӧ�ó���2�����ǣ�1,1�����������Σ����Լ�ȥһ��*/  
