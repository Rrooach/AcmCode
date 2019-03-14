#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i < n; ++i)
	{
		int t = n - i;
		if (!(t%i)) ans++;
	}
	
	cout << ans << endl;
	
	
	return 0;
}
