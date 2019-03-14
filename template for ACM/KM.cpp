#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=110;
const int inf=0x7fffffff;
int n,m,w[maxn][maxn];//n��ʾx�ߵ�ĸ�����y��ʾy�ߵ�ĸ�����w��ʾ��Ȩֵ 
int lx[maxn],ly[maxn];//lx��ʾx�ߵı�ˣ�ly��ʾy�ߵı�� 
int from[maxn],to[maxn];//from[i]=j��ʾy�ߵ�i��x�ߵ�j���ӡ�to[i]=j��ʾx�ߵ�i���Ե���y�ߵ�j 
bool s[maxn],t[maxn];//s��ʾx�ߵĵ㼯��t��ʾy�ߵĵ㼯 
bool find(int x)//�������㷨 
{
    s[x]=1;
    for(int i=1;i<=m;i++)
    if(lx[x]+ly[i]==w[x][i]&&!t[i])
    {
        t[i]=1;
        if(!from[i]||find(from[i]))
        {
            from[i]=x;
            to[x]=i;
            return 1;
        }
    }
    return 0;
}
void update()//���±�� 
{
    int d=inf;
    for(int i=1;i<=n;i++)
    if(s[i])
    for(int j=1;j<=m;j++)
    if(!t[j])
    d=min(d,lx[i]+ly[j]-w[i][j]);//�������������ԭ�����d 
    for(int i=1;i<=n;i++)//�㼯s�еĵ�ı��lx[i]-d 
    if(s[i]) lx[i]-=d;
    for(int j=1;j<=m;j++)//�㼯t�еĵ�ı��ly[j]+d 
    if(t[j]) ly[j]+=d;
}
void km()//km�㷨 
{
    for(int i=1;i<=n;i++)//��ʼ����� 
      for(int j=1;j<=m;j++)
      lx[i]=max(lx[i],w[i][j]);
    for(int i=1;i<=n;i++)//x��ÿ�����ƥ�� 
    for(;;)
    {
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        if(find(i)) break;
        else update();
    }
}
int main()
{
    scanf("%d%d",&n,&m);//���� 
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
      scanf("%d",&w[i][j]);
    km();
    int ans=0;
    for(int i=1;i<=n;i++)//����� 
    ans+=w[i][to[i]];
    printf("%d",ans);//��� 
    return 0;
}
