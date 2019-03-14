#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int tu[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int amap[5][6];
int dx,dy,cnt;
void dfs(int x,int y){
    int posx,posy;
    for(int i=0;i<8;++i){
        posx=x+tu[i][0];
        posy=y+tu[i][1];
        if(posx>0&&posx<=4&&posy>0&&posy<=5&&amap[posx][posy]==0){
            amap[posx][posy]=1;
            dfs(posx,posy);
            amap[posx][posy]=0;
        }
        else if(posx==dx&&posy==dy)
            cnt++;
    }
}
int main(){
    while(scanf("%d%d",&dx,&dy)!=EOF){
        if(dx<=0||dx>4||dy<=0||dy>5){
            printf("ERROR\n");
            continue;
        }
        memset(amap,0,sizeof(amap));
        amap[dx][dy]=1;
        cnt=0;
        dfs(dx,dy);
        printf("%d\n",cnt);
    }
    return 0;
}

