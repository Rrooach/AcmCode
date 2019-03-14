#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;
    int a[n+10];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    vector<pair<int, int> >res;
    int l = 0, r = n-1;
    while (l < r)
    {
        cout << l << ends << a[l] << " " << a[r] << endl;
        if (a[l] + a[r] < b)
            l++;
        if (a[l] + a[r] > b)
            r--;
        if (a[l] + a[r] == b)
        {
            break;
        }
    } 
    if (l < r)
        cout << a[l] << " " << a[r] << endl;
    else 
        cout << "No Solution\n";
    system("pause");
    return 0;
}