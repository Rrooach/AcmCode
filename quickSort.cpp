#include <bits/stdc++.h>

using namespace std;

int select(int a[], int l, int r)
{
    int temp = a[l];
    while (l < r)
    {
        while (l < r && temp < a[r]) 
            r--;
        a[l] = a[r];
        while (l < r && temp > a[l])
            l++;
        a[r] = a[l];
    }
    a[l] = temp;
    return l;
}

void quickSort(int a[], int left, int right)
{
    int l = left, r = right;
    if (l < r)
    {
        int pose = select(a, l, r);
        quickSort(a, left, pose);
        quickSort(a, pose + 1, right);
    }
    

}

int main()
{
    int a[5] = {2, 3, 1, 6, 4};
    quickSort(a, 0, 4);
    for (int i = 0; i < 5; ++i)
        cout << a[i] << ends;
        system("pause");
    return 0;
}