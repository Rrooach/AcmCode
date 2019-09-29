#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a;
        cin >> a;
        int len = a.length();
        int loc_p = -1, loc_t = -1, num_p = 0, num_t = 0, other = 0;
        for (int i = 0; i < len; ++i)
        {
            if (a[i] == 'P')
            {
                loc_p = i;
                num_p++;
            }
            else if (a[i] == 'T')
            {
                loc_t = i;
                num_t++;
            }
            else if (a[i] != 'A')
                other++;
        }
        cout << other << ends << loc_t - loc_p << ends << num_p << ends << num_t << endl;
        if (other != 0 || loc_t - loc_p <= 1 || (num_p != 1 || num_t != 1))
        {
            cout << "NO\n";
            continue;
         }
        if (loc_t-loc_p-1 <= 2)
           cout << "YES\n";
        else
           cout << "NO\n";
         
    }
    system("pause");
    return 0;
}