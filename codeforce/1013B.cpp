#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 100001

int store[maxn], num[maxn];

int main()
{
	int n, x, temp, flag = -1;
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		if (store[num[i]])return cout << 0, 0;
		store[num[i]]++;
	}
	
	for (int i = 0; i < n; i++)
	{
		temp = num[i];
		if (temp != (temp&x))
		{
			if (store[(temp&x)] >  0)return cout << 1, 0;
			if (store[(temp&x)] < 0)flag = 2;
			store[(temp&x)] = -1;
		}
	}
	cout << flag;
	return 0;
}
