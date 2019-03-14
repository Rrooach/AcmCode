#include <stdio.h>
#include <string.h>
#define MAXN 1000 + 10
#define N 20
int f[N],SG[MAXN],S[MAXN];
//f[N]:可改变当前状态的方式，N为方式的种类，f[N]要在getSG之前先预处理
//SG[]:0~n的SG函数值
//S[]:为x后继状态的集合
void  getSG(int n){
    int i,j;
    memset(SG,0,sizeof(SG));
    //因为SG[0]始终等于0，所以i从1开始
    for(i = 1; i <= n; i++){
        //每一次都要将上一状态 的 后继集合 重置
        memset(S,0,sizeof(S));
        for(j = 0; f[j] <= i && j <= N; j++)
            S[SG[i-f[j]]] = 1;  //将后继状态的SG函数值进行标记
        for(j = 0;; j++) if(!S[j]){   //查询当前后继状态SG值中最小的非零值
            SG[i] = j;
            break;
        }
    }
}
int main(){
    int n,m,k;
    f[0] = f[1] = 1;
    for(int i = 2; i <= 16; i++)
        f[i] = f[i-1] + f[i-2];
    getSG(1000);
    while(scanf("%d%d%d",&m,&n,&k),m||n||k){
        if(SG[n]^SG[m]^SG[k]) printf("Fibo\n");
        else printf("Nacci\n");
    }
    return 0;
}
