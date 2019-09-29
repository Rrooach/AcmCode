#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

struct node{
    int id, total, al, ds;
}temp[maxn];

int main()
{
    vector<int> res = {12, 232, 324};
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> temp[i].al >> temp[i].ds;
        temp[i].id = i+1;
        temp[i].total = temp[i].al + temp[i].ds;
    }
    int cnt = 0;
    for (int i = 0; i < k; ++i)
    {
        for (int j = k - 1; j > 0; --j)
        {
            if (temp[j].total > temp[j - 1].total || ((temp[j].total == temp[j - 1].total) && temp[j].al > temp[j-1].al))
            {
                swap(temp[j], temp[j - 1]);
                cnt++;
            }
                
        }
    }
    for (int i = 0; i < k; ++i)
    {
        cout << temp[i].id << ends << temp[i].total << ends << temp[i].al << ends << temp[i].ds << endl;
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}