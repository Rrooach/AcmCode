#include<stdio.h> 
#include<string.h> 
 
int n;     		   //������ 
int map[50][50];   //�ڽӾ��� 
int tl[50];        //ʱ������ 

//********** 
int best;          //��ѷ���ʱ�� 
int visit[50];     //����ʱ�� 
 
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
 
void find_shortest()   //����Floyd�㷨����������֮��ľ��� 
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
 
void ready()  //���ݳ�ʼ�� 
{ 
    find_shortest(); 
    best=-1; 
    memset(visit,0,sizeof(visit)); 
} 
 
bool no_solution()  //Ԥ�����ж��Ƿ��н� 
{ 
    int i,j; 
    int x=map[1][1]; 
    for(i=1;i<=n;i++) 
        for(j=1;j<=n;j++) 
            if(i!=j&&map[i][j]<x) //Ѱ���·�� 
                x=map[i][j]; 
    for(i=2;i<=n;i++) 
        if(tl[i]>=x*(n-1)) return false;  //�·����ʱ��Ҫ�̣��н� 
 
    return true;   //�������·����ʱ��̣��޽� 
} 
 
bool ontime(int x,int t)  //�Ż���������ǰֱ�ӵ���ĳ�������Ƿ�ʱ 
{ 
    int i; 
    for(i=2;i<=n;i++) 
        if(visit[i]==0&&t+map[x][i]>tl[i])  //��ǰδ���ʲ��ܼ�ʱ������� 
            return false; 
    return true; 
} 
 
void search(int p, int x, int t) //�����������������pΪ��������������tΪ��ʱ�䣬xΪ��ǰ���� 
{ 
    if(p>n)   //�Ѿ��ҵ�һ�ַ��� 
    { 
        if(t<best||best==-1) best=t;  //�޸����ŷ��� 
        return; 
    } 
    if(!ontime(x,visit[x])) return;  //�����Ż��жϵ�ǰ�Ƿ��ܵ� 
    if(t+visit[x]*(n-p+1)>=best&&best>-1) return;  //��ǰ���������ܱ�֮ǰ�ĸ��� 
 
    int i; 
    for(i=2;i<=n;i++)  //����������� 
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
