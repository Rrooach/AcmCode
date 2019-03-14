
#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
#define M 107  
#define inf 0x3f3f3f  
using namespace std;  
int g[M][M],path[M][M];//path�����i��j���ı�Ȩ  
int dist[M],pre[M],vis[M];  
bool used[M][M];//�Ƿ�����С��������  
int n,m,mst;  
  
void init()  
{  
    for(int i=0;i<=n;i++)  
        for(int j=i+1;j<=n;j++)  
            g[i][j]=g[j][i]=inf;  
  
}  
  
int prime()  
{  
    int mst=0;  
    memset(path,0,sizeof(path));  
    memset(vis,0,sizeof(vis));  
    memset(used,0,sizeof(used));  
    vis[1]=1;  
    for(int i=1;i<=n;i++)  
    {  
        dist[i]=g[1][i];  
        pre[i]=1;  
    }  
    for(int i=1;i<n;i++)  
    {  
        int u=-1;  
        for(int j=1;j<=n;j++)  
        {  
            if(!vis[j])  
                if(u==-1||dist[j]<dist[u])  
                    u=j;  
        }  
        used[u][pre[u]]=used[pre[u]][u]=true;//����mst  
        mst+=g[pre[u]][u];  
        vis[u]=1;  
        for(int j=1;j<=n;j++)  
        {  
            if(vis[j]&&j!=u)//��u��j����·�������ߵ�Ȩֵ  
                path[j][u]=path[u][j]=max(path[j][pre[u]],dist[u]);  
            if(!vis[j])  
                if(dist[j]>g[u][j])//�������ڽڵ�ľ���  
                {  
                    dist[j]=g[u][j];  
                    pre[j]=u;//��¼����ǰ��  
                }  
        }  
    }  
    return mst;  
}  
  
int second_tree()//���С������  
{  
    int res=inf;  
    for(int i=1;i<=n;i++)  
        for(int j=1;j<=n;j++)  
            if(i!=j&&!used[i][j])  
                res=min(res,mst-path[i][j]+g[i][j]);//ɾ������Ȩֵ����·�����Ҽ�������·��������  
    return res;  
}  
  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d%d",&n,&m);  
        init();  
          
        mst=prime();//��С������  
        int second_mst=second_tree();//��С������  
    }  
}
