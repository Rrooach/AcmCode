#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	int x = 0, y = 0, cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'U') y++;
		else x++;
		if (x==y && s[i]==s[i+1]) cnt++;
	}
	cout << cnt << endl;
	
	return 0;
}
