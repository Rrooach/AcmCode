#include <bits/stdc++.h>

using namespace std;

int head[510];
int indegree[510];
int q[510];
int num;
struct stu{
   int to,next;
}edge[2510];
void inin(){//初始化 
    memset(indegree,0,sizeof(indegree)); 
    memset(head,-1,sizeof(head));
    num=0;
}
void add(int a,int b){//添加边 
   stu E={b,head[a]};
   edge[num]=E;
   head[a]=num++;
   indegree[b]++;
}
void topo(int n){
    int i,j,id,t=0;
    for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
            if(indegree[i]==0){
              id=i;
              break;    
            }
        }
        q[t++]=id;indegree[id]=-1;
        for(i=head[id];i!=-1;i=edge[i].next){
            int k=edge[i].to;
            indegree[k]--;
        }
    }
    printf("%d",q[0]);//输出拓扑序列 
    for(i=1;i<n;++i){
        printf(" %d",q[i]);
    }
    printf("\n");
}
int main(){
    int n,m,i,j,a,b;
    while(scanf("%d%d",&n,&m)!=EOF){
        inin();
        for(i=1;i<=m;i++){
           scanf("%d%d",&a,&b);
           add(a,b);
        }
        topo(n);
    }
    return 0;
}
