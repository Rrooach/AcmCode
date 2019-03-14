
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
	int cap, flow; //ע�������˳���ǲ������ı�ģ���ֹ���������ߵ�ʱ��˳��ͬ���ͳ�����ˡ� 
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
	
	void addEdge(int a, int b, int c) //������ 
	{
		edges.push_back((Edge){a, b, c, 0});
		edges.push_back((Edge){b, a, 0, 0});
		int nc = edges.size();
		G[a].push_back(nc - 2); //�����Ľ�����ϵ�Ļ����ʹ����������Ĺ�ϵ:����������ߴ���edges[e],edges[e ^ 1]��Ϊ����� 
		G[b].push_back(nc - 1); 
	}
	
	bool BFS() //BFS�����еĵ�ָ�ɲ��ģ�� 
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
		return vis[t]; //������������ܲ��ܷ��ʵ���㣬������ʲ������Ͳ����ټ������ˡ� 
	}
	
	int DFS(int u, int a)
	{
		if (u == t || a == 0) //�����ʵ����Ļ���ʱ�򣬻���ǰ��������������Ϊ0����ô�Ͳ������ˣ�ֱ�ӷ���ǰ������������ˡ� 
		{
			return a;
		}
		int nc = G[u].size();
		int flow = 0;
		int f;
		for (int& i = cur[u]; i < nc; i++) //�����cur[x]��ȷʵ��֪����ʲô�������ô������Ƿ�ֹ���ʵ�ʱ���ٷ��������ʸ��ڵ㡣 
		{
			Edge& e = edges[G[u][i]];
			int v = e.to;
			if (d[v] == d[u] + 1 && (f = DFS(v, min(a, e.cap - e.flow))) > 0) //�������ж��ǲ��Ƿ�����һ��εģ�����ǵģ������ж�������Ƿ���� 
			{
				e.flow += f;
				edges[G[u][i] ^ 1].flow -= f; //���ߵ�ʱ���Ҳſ�����ΪʲôҪ-f����Ϊ�����õķ���������capΪ0���������������÷��ϲ������磡 
				a -= f;						//����Ҳ�ͳ�����ߵ�Ŀ�ģ�Ϊ�˸��õķ��ڣ����ѽ������ô��⡣ 
				flow += f;
				if (a == 0) //����ж��Ƿǳ��ĺõģ�a == 0��ʱ�����˵���ˣ�ǰ�洫��������С�������ҷ��ʵ��⼸���ߵ�ʱ�� 
				{			//���Ѿ������ˣ�����ıߣ��Ҳ��÷����ˣ���Ϊ������Ҳ�ò�����ѽ������ֱ���˳�ѭ���� 
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
		while (BFS())//ÿ�ζ���BFS���жϲ��������еĲ��ģ���Ƿ��ܹ������� 
		{
			memset(cur, 0, sizeof(cur)); //������ʵ����ڵ㡣 
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

