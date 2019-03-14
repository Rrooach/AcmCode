#include <bits/stdc++.h>

using namespace std;

int main()
{
	int m,n,k;
	cin >> n >> m >> k;
	int a[n][m];
	int v[n][m];
	memset (v,0,sizeof(v));
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	int x = 0;
	int cnt = 0;
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j < m ;++j)
		{
			if (v[i][j] != 1)
			{
				v[i][j] = 1;
				x ^= a[i][j];
			}
		}
		if (x == k)
			cnt ++;
	}
	cout << cnt;
	
	return 0;
 } 
