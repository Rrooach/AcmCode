
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
 
using namespace std;
 
const int MAXN = 100 + 11;
 
const int INF = 0x3fffffff;
 
struct Edge
{
	int from, to;
	int cap, flow; //注意这里的顺序是不能随便改变的，防止你下面插入边的时候顺序不同，就出大错了。 
}edges;
 
struct Dinic
{
	int N, M;
	int s, t;
	vector <Edge> edges;
	vector <int> G[MAXN];
	bool vis[MAXN];
	int d[MAXN];
	int cur[MAXN];
	
	void init(int n, int m)
	{
		this->N = n;
		this->M = m;
	}
	
	void clearAll()
	{
		edges.clear();
		for (int i = 0; i < N; i++)
		{
			G[i].clear();
		}
	}
	
	void addEdge(int a, int b, int c) //建立边 
	{
		edges.push_back((Edge){a, b, c, 0});
		edges.push_back((Edge){b, a, 0, 0});
		int nc = edges.size();
		G[a].push_back(nc - 2); //这样的建立关系的话，就存在着这样的关系:反向的两条边存在edges[e],edges[e ^ 1]互为反向边 
		G[b].push_back(nc - 1); 
	}
	
	bool BFS() //BFS将所有的点分割成层次模型 
	{
		memset(vis, 0, sizeof(vis));
		queue <int> Q;
		Q.push(s);
		vis[s] = 1;
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			int nc = G[u].size();
			for (int i = 0; i < nc; i++)
			{
				Edge& e = edges[G[u][i]];
				int v = e.to;
				if (!vis[v] && e.cap > e.flow)
				{
					vis[v] = 1;
					d[v] = d[u] + 1;
					Q.push(v);
				}
				
			}
		}
		return vis[t]; //看看层次网络能不能访问到汇点，如果访问不到，就不用再继续做了。 
	}
	
	int DFS(int u, int a)
	{
		if (u == t || a == 0) //当访问到最后的汇点的时候，或者前面流过来的流量为0，那么就不用做了，直接返回前面的流量就是了。 
		{
			return a;
		}
		int nc = G[u].size();
		int flow = 0;
		int f;
		for (int& i = cur[u]; i < nc; i++) //这里的cur[x]我确实不知道有什么高明的用处，就是防止访问的时候再返回来访问父节点。 
		{
			Edge& e = edges[G[u][i]];
			int v = e.to;
			if (d[v] == d[u] + 1 && (f = DFS(v, min(a, e.cap - e.flow))) > 0) //这里先判断是不是访问下一层次的，如果是的，继续判断最大流是否存在 
			{
				e.flow += f;
				edges[G[u][i] ^ 1].flow -= f; //建边的时候，我才看懂。为什么要-f，因为你设置的反向流量的cap为0，所以这样做正好符合残留网络！ 
				a -= f;						//而且也和出反向边的目的：为了更好的反悔，相悖呀。不怎么理解。 
				flow += f;
				if (a == 0) //这个判断是非常的好的，a == 0的时候就是说明了，前面传过来的最小容量，我访问到这几个边的时候 
				{			//就已经用完了，后面的边，我不用访问了，因为访问我也用不到了呀。所以直接退出循环。 
					break;
				}
			}
		}
		return flow;
	}
	
	int maxFlow(int s, int t)
	{
		this->s = s;
		this->t = t;
		int flow = 0;
		while (BFS())//每次都做BFS来判断残留网络中的层次模型是否能够到达汇点 
		{
			memset(cur, 0, sizeof(cur)); //避免访问到父节点。 
			flow += DFS(s, INF);
		}
		return flow;
	} 
};
 
Dinic dn;
 
int main()
{
	int N, M;
	while (scanf("%d%d", &N, &M) != EOF)
	{
		dn.init(N, M);
		dn.clearAll();
		int a, b, c;
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			dn.addEdge(a, b, c);
		}
		int s, t;
		scanf("%d%d", &s, &t);
		int ans = dn.maxFlow(s, t);
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}

