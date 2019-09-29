#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int main()
{
    string a;
    while (cin >> a)
    {
        int len = a.length();
        int mark, minn = '0';
        for (int i = len-1; i >= 0; --i)
        {
            if (a[i] < a[len-1] && a[i] > minn)
            {
                minn = a[i];
                mark = i;
            }
        }
        swap(a[len - 1], a[mark]);
        
        cout << mark << endl;
        sort(a.begin() + mark+1, a.end());
        cout << a << endl;
        /*
        4321 4321


        1432 2134
        1234 1243
        1112 1121 
        123 132
        */
    }
    system("pause");
    return 0;
}