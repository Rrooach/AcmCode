#include<cstdio>
using namespace std;
struct node
{int x;
 int value;
 int next;
};
node e[60000];
int visited[1505],dis[1505],st[1505],queue[1000];
int main()
{
	  int n,m,u,v,w,start,h,r,cur;
	 
	  while(scanf("%d%d",&n,&m)!=EOF)
	  {
	    for(int i=1;i<=1500;i++)
	      {
			  visited[i]=0;
		       dis[i]=-1;
		       st[i]=-1;  //�����ʼ�����±��Ǹ�whileѭ������Ӱ��
	      }
	 
	   for(int i=1;i<=m;i++)
	      {
		       scanf("%d%d%d\n",&u,&v,&w);     
		       e[i].x=v;            //��¼��̽ڵ�    �൱�������еĴ���һ���ڵ㣬��ʹ���������ȼ�¼
		       e[i].value=w;
		       e[i].next=st[u];     //��¼����ڵ��ĳһ���߱�ڵ���±꣬�൱���������аɸñ߱�ڵ��nextָ����ָ�����ĺ�̱߱�ڵ�
		       st[u]=i;                //�Ѹö����ָ��ָ��߱�ڵ㣬�൱�������еĲ����У�ͷ����ָ��ı�
	      }
	    start=1;
	    visited[start]=1;
	    dis[start]=0;
	    h=0;
	    r=1;
	    queue[r]=start;
	    while(h!=r)
	     {
	
	      h=(h+1)%1000;
	      cur=queue[h];
	      int tmp=st[cur];
	      visited[cur]=0;	
	     while(tmp!=-1)
	        {
	            if (dis[e[tmp].x]<dis[cur]+e[tmp].value)            //�ĳɴ��ںŲŶ�
	            {
	                   dis[e[tmp].x]=dis[cur]+e[tmp].value;
	                    if(visited[e[tmp].x]==0)
	                      {
	
	                           visited[e[tmp].x]=1;
	                           r=(r+1)%1000;
	                            queue[r]=e[tmp].x;
	                       }
	            }
	         tmp=e[tmp].next;      
	        }
	     } 
	    printf("%d\n",dis[n]);
	  }
  return 0;   
}
