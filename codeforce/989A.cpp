#include <bits/stdc++.h>

using namespace std;

int main ()
{
	string a;
	cin >> a;
	int n = a.length();
	for (int i = 1; i < n-1; ++i)
	{
		if (a[i-1] != a[i] && a[i]!= a[i+1] && a[i-1]!=a[i+1] && a[i-1]!='.'&&a[i]!='.'&&a[i+1]!='.')
		{
				cout << "Yes\n";
				return 0;
		}
				
	}
	cout << "No\n";
	return 0;
 } 
