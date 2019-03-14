#include <iostream>
   #include <cmath>
   #include <cstdio>
   #include <cstring>
   #include <cstdlib>
   #include <algorithm>
   #include <string>
   typedef long long LL;
   using namespace std;
   const int MAXV = 100;
   const int MAXE = 10000;
   const int INF = 0x3f3f3f3f; 
   
   //�����V����,��rootΪ���ڵ��ͼmap����С����ͼ
   int zhuliu(int root, int V, int map[MAXV + 7][MAXV + 7]){
       bool visited[MAXV + 7];
       bool flag[MAXV + 7];//������Ϊtrue,������Ȼ����
       int pre[MAXV + 7];//��i�ĸ��ڵ�Ϊpre[i]
       int sum = 0;//��С����ͼ��Ȩֵ
       int i, j, k;
       for(i = 0; i <= V; i++) flag[i] = false, map[i][i] = INF;
       pre[root] = root;
       while(true){
           for(i = 1; i <= V; i++){//����̻�����E0 
               if(flag[i] || i == root) continue;
               pre[i] = i;
               for(j = 1; j <= V; j++)
                   if(!flag[j] && map[j][i] < map[pre[i]][i])
                       pre[i] = j;
               if(pre[i] == i) return -1;
           }
           for(i = 1; i <= V; i++){//���E0
               if(flag[i] || i == root) continue; 
               for(j = 1; j <= V; j++) visited[j] = false;
               visited[root] = true;
               j = i;//�ӵ�ǰ�㿪ʼ�һ�
               do{
                   visited[j] = true;
                   j = pre[j];
               }while(!visited[j]);
               if(j == root)continue;//û�ҵ���
               i = j;//����G�е�����
               do{//����������ȡֵ����,�ۼƼ���ԭͼ����С����ͼ
                   sum += map[pre[j]][j];
                   j = pre[j];
               }while(j != i);
               j = i;
               do{//���ڻ��ϵĵ��йصı�,�޸���Ȩֵ
                   for(k = 1; k <= V; k++)
                       if(!flag[k] && map[k][j] < INF && k != pre[j])
                           map[k][j] -= map[pre[j]][j];
                   j = pre[j];
               }while(j != i);
               for(j = 1; j <= V; j++){//����,������������i�ŵ�,�����뻷�ϵĵ��йصı�ת�Ƶ���i
                   if(j == i) continue;
                   for(k = pre[i]; k != i; k = pre[k]){
                       if(map[k][j] < map[i][j]) map[i][j] = map[k][j];
                       if(map[j][k] < map[j][i]) map[j][i] = map[j][k];
                   }
               }
               for(j = pre[i]; j != i; j = pre[j]) flag[j] = true;//��ǻ���������Ϊ������
               break;//��ǰ���������,�γ��µ�ͼG',����������G'����С����ͼ
           }
           if(i > V){//������еĵ㶼�������û�л�����,���ڵ���̻�����E0������С����ͼ.�ۼƼ���sum,�㷨����
               for(i = 1; i <= V; i++)
                   if(!flag[i] && i != root) sum += map[pre[i]][i];
               break;
           }
       }
       return sum;
 }
