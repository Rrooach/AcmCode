#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

vector<int> a[N];
int vis[N];
int used[N];
int main()
{
	memset (vis,0,sizeof(vis)); 
	memset (used,0,sizeof(used));
	int m,n;
	scanf ("%d%d",&n,&m);
	int x,y;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y); 
	}
	
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
        {
            vis[i]=i;
            for (int j=0;j < a[i].size();j++)
                if (!vis[a[i][j]]) vis[a[i][j]]=i;
            used[i]=1;
        }
	}
	for (int i = n; i >=0; --i)
	{
		if (used[i])
        {
            for (int j = 0; j < a[i].size(); j++) 
				used[a[i][j]] = 0;
        }
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) 
		if (used[i]) 
			ans++;
    printf("%d\n",ans);
    for (int i = 1; i <= n; ++i) 
		if (used[i]) 
			printf("%d ",i);

	return 0;
} 
