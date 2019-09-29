#include <bits/stdc++.h>

using namespace std;

void merge(int *a, int l, int r, int * temp)
{
    
}

void mergesort(int l, int r, int *a, int * temp)
{
    int left = l, right = r;
    if (l < r)
    {
        int mid = (l + r) >> 1;
        mergesort(l, mid, a, temp);
        mergesort(mid + 1, r, a, temp);
        merge(a, l, r, temp);
    }

}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    mergesort(0, n, a);

    system("pause");
    return 0;
}