#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#define  ll long long
using namespace std;
int cnt = 0;
const int maxn=30000+5; 
struct Edge{
	int from,to;
	ll weight,a,b;
	Edge(int from,int to,ll weight,ll a,ll b):from(from),to(to),weight(weight),a(a),b(b){}
};
struct HeapNode{  //prority_queue 中的优先级 
	int u,dist;   //dist: u点到起点的最短路 ,u: 有向边的终点 
	HeapNode(int u,int d):u(u),dist(d){}
	bool operator < (const HeapNode& h) const {
		return dist>h.dist;
	}
};
struct Dijkstra{ //打包在Dijkstra中 
	int n,m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int dist[maxn];
	int p[maxn];
	Dijkstra(int n):n(n){
		for(int i=0;i<n;i++) G[i].clear();
		edges.clear();
	}
	void AddEdge(int from,int to,ll weight,ll a, ll b){
		edges.push_back(Edge(from,to,weight,a,b));
		m=edges.size();
		G[from].push_back(m-1);  //保存from出发的边 
	}
	void dijkstra(int s)
	{
		priority_queue<HeapNode> Q;
		memset(dist,0x7f,sizeof(dist));
		memset(done,false,sizeof(done));
		dist[s]=0;
		Q.push(HeapNode(s,0));
		while(!Q.empty())
		{
			int u=Q.top().u; Q.pop();
			if(done[u]) continue;
			done[u]=true;
			for(int i=0;i<G[u].size();i++)
			{
				Edge& e=edges[G[u][i]];
				int v=e.to;
				ll w=e.weight;
				ll a = e.a,b = e.b;
				if (w > a) continue;
				ll t = (dist[u])%(a+b);
				ll temp=0;
				if(t<=a)
	            {
	            	ll tt = t + w;
	                if(tt <= a)
	                    temp=0;
	                else
	                    temp=a+b-t;
	            }
	            else
	                temp=a+b-t;
	            w += temp;
				if(dist[v]>dist[u]+w)
				{
					dist[v]=dist[u]+w;
					if (!done[v])
					{
						p[v]=G[u][i];          //记录到各点的最短路径 
						Q.push(HeapNode(v,dist[v]));
					}	
				}
			}
		}
	}
};
int main()
{
	int n,m,s,u,v; 
	ll t,w,a,b;
	while(~scanf("%d%d%d%lld",&n,&m,&s,&t))
	{
		cnt ++;
		Dijkstra d(n);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%lld%lld%lld",&u,&v,&a,&b,&w);
			//cout  << u << ends << v << ends << w << ends << a << ends << b << endl;
			d.AddEdge(u,v, w,a,b);
		}		
		d.dijkstra(s);          //s点出发 
		printf("Case %d: %d\n",cnt,d.dist[t]);
	}
	
	return 0;
}
 
