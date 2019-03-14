#include <bits/stdc++.h>
#define  ll long long
using namespace std;

const int N = 100005;
ll t[N];
ll k[N]; 

int main()
{
	int m,n;
	while (scanf ("%d%d",&n,&m) && n)
	{
		for (int i = 0; i < n; ++i)
			scanf ("%lld",&k[i]);
		for (int i = 0; i < n; ++i)
			scanf ("%lld",&t[i]);
		for (int i = 0; i < m; ++i)
		{
			ll k1[N]={0},t1[N]={0};
			for (int i = 0; i < n; ++i)
			{
				k1[i]=k[i],t1[i]=t[i];
			}
			int q;
			scanf("%d",&q);
			int x = 0;
			int y = n-1;
			while (q>0)
			{
				swap(k1[x++],t1[y--]);
				q--;
			}
			sort (t1,t1+n);
			sort (k1,k1+n);
			int ans = 0;
			for (int i = 0; i < n; ++i)
			{
				if (t1[i] > k1[i]) ans++;
			}
			printf ("%d\n",ans);
		}
	}
	return 0;
}
