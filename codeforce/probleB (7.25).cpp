#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main()
{
	int n,b;
	cin >> n >>b;
	int cnt_even = 0,cnt_odd = 0,j = 0,sum = 0,ans = 0;
	int cost[N];
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] % 2) cnt_odd ++;
		else cnt_even ++; 
		if (cnt_even == cnt_odd && i + 1 < n)
			cost[j++] = abs(a[i]-a[i+1]);
	}
	sort(cost,cost+j);
	for (int i = 0; i < j; ++i)
	{
		sum += cost[i];
		if (sum <= b)
			ans ++;
		else break;
	}
	cout << ans << endl;
	
	
	return 0;
}
