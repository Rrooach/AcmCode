#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=50000+100;
 
int dmax[MAXN][20];
int dmin[MAXN][20];
 
void initmax(int n,int d[])//��ʼ�����ֵ��ѯ
{
    for(int i=1; i<=n; i++)
        dmax[i][0]=d[i];
    for(int j=1 ; (1<<j)<=n ; j++)
        for(int i=1; i+(1<<j)-1 <=n; i++)
            dmax[i][j]=max(dmax[i][j-1],dmax[i+(1<<(j-1))][j-1]);
}
int getmax(int L,int R)//��ѯ���ֵ
{
    int k=0;
    while((1<<(k+1))<=R-L+1)k++;
    return max(dmax[L][k] , dmax[R-(1<<k)+1][k]);
}
 
void initmin(int n,int d[])//��ʼ����Сֵ��ѯ
{
{
    for(int i=1; i<=n; i++)
        dmin[i][0]=d[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            dmin[i][j]= min( dmin[i][j-1],dmin[i+(1<<(j-1))][j-1] );
}
int getmin(int L,int R)//��ѯ��Сֵ
{
    int k=0;
    while( (1<<(k+1)) <=R-L+1)k++;
    return min(dmin[L][k],dmin[R-(1<<k)+1][k]);
}
