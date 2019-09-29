#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size, arr_len, q;
    scanf("%d%d%d", &size, &arr_len, &q);
    for (int i = 0; i < q; ++i)
    {       
        bool flag = true;
        int arr[arr_len + 5];
        for (int j = 1; j <= arr_len; ++j)
            cin >> arr[j];
        stack<int> a;
        int m = 0;
        int cur = 1;
        for (int j = 1; j <= arr_len; ++j)
        {
            a.push(j);
            if (a.size() > size)
            {
                flag = false;
                break;
            }
            while (!a.empty() && a.top() == arr[cur])
            {
                a.pop();
                cur++;
            }
        }
        if (flag == true && a.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
        system("pause");
    return 0;
}