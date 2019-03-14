#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] % 2) a[i] ++;	
	}
	
	for (int i = 0; i < n-1; ++i)
	{
		if (! (a[i] % 2)) a[i]--;
		cout << a[i] << " ";
	}
	if (! (a[n - 1] % 2))
	{
		a[n - 1] --;
		cout << a[n - 1];
	}
	cout<<endl;
	return 0;
 } 
