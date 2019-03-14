#include <bits/stdc++.h>


using namespace std;

int main ()
{
	int n,maxA = -1,maxB = -1;
	scanf ("%d",&n);
	int a[n],b[101];
	memset (b, 0, sizeof (b));
	for (int i = 0; i < n; ++i)
	{
		scanf ("%d",&a[i]);
		b[a[i]] ++;
		if (maxA < a[i]) maxA = a[i];
		if (maxB < b[a[i]]) maxB = b[a[i]];
	}	
	cout << maxB <<endl;
	return 0;
} 
/*
6
1 1 1 3 3 4
*/
