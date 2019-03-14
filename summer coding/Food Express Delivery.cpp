#include<stdio.h> 
#include<string.h> 
 
int n;     		   //顶点数 
int map[50][50];   //邻接矩阵 
int tl[50];        //时间限制 

//********** 
int best;          //最佳访问时间 
int visit[50];     //访问时间 
 
bool read_data() 
{ 
    scanf("%ld",&n); 
    if(n==0) return false; 
 
    int i,j; 
    for(i=1;i<=n;i++) 
        for(j=1;j<=n;j++) 
            scanf("%ld",&map[i][j]); 
    for(i=2;i<=n;i++) scanf("%ld",&tl[i]); 
    return true; 
} 
 
void find_shortest()   //利用Floyd算法求任意两点之间的距离 
{ 
    int i,j,k; 
    for(k=1;k<=n;k++) 
        for(i=1;i<=n;i++) 
 //           if(i!=k) 
                for(j=1;j<=n;j++) 
 //                   if(i!=j&&j!=k) 
                        if(map[i][k]+map[k][j]<map[i][j])  
                            map[i][j]=map[i][k]+map[k][j]; 
} 
 
void ready()  //数据初始化 
{ 
    find_shortest(); 
    best=-1; 
    memset(visit,0,sizeof(visit)); 
} 
 
bool no_solution()  //预处理判断是否有解 
{ 
    int i,j; 
    int x=map[1][1]; 
    for(i=1;i<=n;i++) 
        for(j=1;j<=n;j++) 
            if(i!=j&&map[i][j]<x) //寻找最长路径 
                x=map[i][j]; 
    for(i=2;i<=n;i++) 
        if(tl[i]>=x*(n-1)) return false;  //最长路径比时间要短，有解 
 
    return true;   //不符合最长路径比时间短，无解 
} 
 
bool ontime(int x,int t)  //优化函数，当前直接到达某个顶点是否及时 
{ 
    int i; 
    for(i=2;i<=n;i++) 
        if(visit[i]==0&&t+map[x][i]>tl[i])  //当前未访问不能及时到达，剪掉 
            return false; 
    return true; 
} 
 
void search(int p, int x, int t) //深度优先搜索，其中p为已搜索顶点数，t为总时间，x为当前顶点 
{ 
    if(p>n)   //已经找到一种方案 
    { 
        if(t<best||best==-1) best=t;  //修改最优方案 
        return; 
    } 
    if(!ontime(x,visit[x])) return;  //利用优化判断当前是否能到 
    if(t+visit[x]*(n-p+1)>=best&&best>-1) return;  //当前搜索不可能比之前的更优 
 
    int i; 
    for(i=2;i<=n;i++)  //深度优先搜索 
        if(visit[i]==0) 
        { 
            visit[i]=visit[x]+map[x][i]; 
            search(p+1,i,t+visit[i]); 
            visit[i]=0; 
        } 
} 
 
 
int main() 
{ 
    while(read_data()) 
    { 
        ready(); 
        if(!no_solution()) 
            search(2,1,0); 
        printf("%ld\n",best); 
    } 
    return 0; 
}
