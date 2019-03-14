#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int ans = 0; 
	string s,t;
	cin >>s;
	getchar();
	cin>>t;
	int m,n;
	m = s.length();
	n = t.length();
	
	while (s[m - 1] == t[n - 1])
	{
		m--;
		n--;
	}
	ans = m + n;
	cout << ans << endl;
	
	return 0;
} 
