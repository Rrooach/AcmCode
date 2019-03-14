#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int N = 100005;
int p[N];
vector<int> g[N];

void build(int u, int fa)
{
    int n = g[u].size();
    for(int i=0; i<n; i++){
        int v = g[u][i];
        if(v == fa) continue;
        p[v] = u;
        build(v, u);
    }
}
int main()
{
    int n, t, start;
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<N; i++)
            g[i].clear();
        scanf("%d%d", &n, &start);
        int a, b;
        for(int i=0; i<n-1; i++){
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        p[start] = -1;
        build(start, -1);
        if(n >= 1)
            printf("%d", p[1]);
        for(int i=2; i<=n; i++)
            printf(" %d", p[i]);
        printf("\n");
    }
    return 0;
}
