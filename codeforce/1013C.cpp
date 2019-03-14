#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define maxn 200001
#pragma warning(disable:4996)
int store[maxn];

int main()
{
	int n, temp;
	scanf("%d", &n);
	temp = n;
	n <<= 1;
	for (int i = 0; i < n; i++)
		scanf("%d", &store[i]);
	sort(store, store + n);
	long long a, b, ans = 0x7fffffff;
	a = store[n / 2 - 1] - store[0];
	b = store[n - 1] - store[n / 2];
	ans = a * b;
	for (int i = 1; i < temp; i++)
	{
		a = store[i + temp - 1] - store[i];
		b = store[n - 1] - store[0];
		ans = min(a*b, ans);
	}
	
	cout << ans << endl;
	system("pause");
	return 0;
}

/*
5 
1 1 50 51 51 51 51 52 100 100
*/