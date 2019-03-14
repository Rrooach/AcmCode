#include<cstdio>
#include<cstring>
struct shit{int aim,next;}e[2200];
int father[2200],a,b,n,m,point,head[2200];
bool v[2200];
void  fuck(int x,int y)
{
    e[++point].aim=y;
    e[point].next=head[x];
    head[x]=point;
}
bool f(int x)
{
    for(int i=head[x];i!=0;i=e[i].next)
    {
        if(v[i])continue;
        v[i]=true;
        if(!father[e[i].aim]||f(father[e[i].aim]))
        {
            father[e[i].aim]=x;
            return true;
        }
    }
    return false ;
    
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        fuck(i,a),fuck(i,b);
    }
    int k;
    for(k=1;k<=m;k++)
    {
        memset(v,0,sizeof(v));
        if(!f(k))break;
    }
    printf("%d",k-1);
    return 0;
}
