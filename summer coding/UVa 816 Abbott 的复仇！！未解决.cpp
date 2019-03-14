#include<iostream>  
#include<cstring>  
#include<cstdio>  
#include<queue>  
#include<vector>  
using namespace std;  

 
struct node  
{  
    int r,c,dir;  
    node(int rr=0,int cc=0,int dirr=0):r(rr),c(cc),dir(dirr){} ;
};  


const char* dirs="NESW";  
const char* turns="FLR";  

int dir_id(char c) {return strchr(dirs,c)-dirs;}  
int turn_id(char c) {return strchr(turns,c)-turns;}  


int dr[]={-1,0,1,0};  
int dc[]={0,1,0,-1};  
`int d[10][10][4];  
node p[10][10][4];  
bool has_edge[10][10][4][3];  
int r0,c0,r1,c1,dir,r2,c2;  
char name[100],c[100],s[100];  

 
node walk(node &u,int turn)  
{  
    int dir=u.dir;  
    if(turn==1) dir=(dir+3)%4;  
    if(turn==2) dir=(dir+1)%4;  
    return node(u.r+dr[dir],u.c+dc[dir],dir);  
}  


bool inside(int r,int c)  
{  
    if(r>=1&&r<=9&&c>=1&&c<=9) return true;  
    return false;  
}  


bool Input()  
{  
    if(scanf("%s %d%d %s %d%d", name, &r0, &c0, c, &r2, &c2)!=6)    return false;  
    printf("%s\n", name);  
    scanf("%d%d%s%d%d",&r0,&c0,&c,&r2,&c2);  
    dir=dir_id(c[0]);  
    r1=r0+dr[dir];  
    c1=c0+dc[dir];  
    memset(has_edge,false,sizeof(has_edge));  
    int a,b;  
    while(scanf("%d",&a)){  
        if(a==0) break;  
        scanf("%d",&b);  
        while(scanf("%s",s)){  
            if(s[0]=='*') break;  
            int temp=dir_id(s[0]);  
            int l=strlen(s);  
            for(int i=1;i<l;++i){  
                has_edge[a][b][temp][turn_id(s[i])]=true;  
            }  
        }  
    }  
    return true;  
}  


void print_ans(node u)  
{  
    printf("%s\n",name);  
    vector<node> nodes;  
    for(;;){  
        nodes.push_back(u);  
        if(d[u.r][u.c][u.dir]==0) break;  
        u=p[u.r][u.c][u.dir];  
    }  
    nodes.push_back(node(r0,c0,dir));  
    int cnt=0;  
    for(int i=nodes.size()-1;i>=0;--i){  
        if(cnt%10==0) printf(" ");  
        printf(" (%d,%d)",nodes[i].r,nodes[i].c);  
        if(++cnt%10==0) printf("\n");  
    }  
    if(nodes.size()%10!=0) printf("\n");  
}  


void BFS()  
{  
    queue<node> q;  
    memset(d,-1,sizeof(d));  
    node u(r1,c1,dir);  
    d[u.r][u.c][dir]=0;  
    q.push(u);  
    while(!q.empty()){  
        node u=q.front();q.pop();  
        if(u.r==r2&&u.c==c2){print_ans(u);return ;}  
        for(int i=0;i<3;++i){  
            node v=walk(u,i);  
            if(has_edge[u.r][u.c][u.dir][i]&&inside(v.r,v.c)&&d[v.r][v.c][v.dir]<0){  
                d[v.r][v.c][v.dir]=d[u.r][u.c][u.dir]+1;  
                p[v.r][v.c][v.dir]=u;  
                q.push(v);  
            }  
        }  
    }  
    printf("No Solution Possible\n");  
}  


int main()  
{  
    while(Input()){  
        BFS();  
    }  
    return 0;  
}   


/*
Sample Input
SAMPLE
3 1 N 3 3
1 1 WL NR *
1 2 WLF NR ER *
1 3 NL ER *
2 1 SL WR NF *
2 2 SL WF ELF *
2 3 SFR EL *
0
NOSOLUTION
3 1 N 3 2
1 1 WL NR *
1 2 NL ER *
2 1 SL WR NFR *
2 2 SR EL *
0
END


Sample Output
SAMPLE
(3,1) (2,1) (1,1) (1,2) (2,2) (2,3) (1,3) (1,2) (1,1) (2,1)
(2,2) (1,2) (1,3) (2,3) (3,3)
NOSOLUTION
No Solution Possible
*/ 
