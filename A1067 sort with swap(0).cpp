#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int n;
    cin >> n;
    int a[n+10];
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        a[i] = temp;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != i)
        {
            swap(a[i], a[0]);
            cout << i << endl;
            for (int j = 0; j < n; ++j)
                    cout << a[j] << ends;
                cout << endl;
            if (i != 0)
                cnt++;
            while (a[0] != 0)
            {
                swap(a[0], a[a[0]]);
                cnt ++;
                cout <<i <<  endl;
                for (int j = 0; j < n; ++j)
                    cout << a[j] << ends;
                cout << endl;
            } 
            
        }
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}