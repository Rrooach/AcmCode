#include <stdio.h>
#include <string.h>
#define MAXN 1000 + 10
#define N 20
int f[N],SG[MAXN],S[MAXN];
//f[N]:�ɸı䵱ǰ״̬�ķ�ʽ��NΪ��ʽ�����࣬f[N]Ҫ��getSG֮ǰ��Ԥ����
//SG[]:0~n��SG����ֵ
//S[]:Ϊx���״̬�ļ���
void  getSG(int n){
    int i,j;
    memset(SG,0,sizeof(SG));
    //��ΪSG[0]ʼ�յ���0������i��1��ʼ
    for(i = 1; i <= n; i++){
        //ÿһ�ζ�Ҫ����һ״̬ �� ��̼��� ����
        memset(S,0,sizeof(S));
        for(j = 0; f[j] <= i && j <= N; j++)
            S[SG[i-f[j]]] = 1;  //�����״̬��SG����ֵ���б��
        for(j = 0;; j++) if(!S[j]){   //��ѯ��ǰ���״̬SGֵ����С�ķ���ֵ
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
