#include <iostream>

using namespace std;

int BBsort(int *a, int lo, int hi)
{
	int last = lo;
	while (++lo < hi)
	{
		if (a[lo-1] > a[lo])
		{
			last = lo;
			swap(a[lo-1], a[lo]);
		}
	}
	return last;
}


void Bsort(int *a, int lo, int hi)
{
	while (lo < (hi = BBsort(a, lo, hi)));
}



int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	Bsort(a, 0, n);
	for (int i = 0; i < n; ++i)
		cout << a[i] << ends;
	system("pause");
	return 0;
 } 
