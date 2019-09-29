#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<set<int>> res(n+2, set<int>()); //初始层数，赋值
    for (int i = 1; i <= n; ++i)
    {
        int temp;
        scanf("%d", &temp);
        for (int j = 0; j < temp; ++j)
        {
            int t;
            scanf("%d", &t);
            res[i].insert(t);
        }
    }
    
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        set<int> rr;
        int a, b, cnt = 0;
        scanf("%d%d", &a, &b);
        int l1 = res[a].size(), l2 = res[b].size();                                                                                        
        for (int j = 0; j < l2; ++j)
        {
            if (rr.find(res[b]) == rr.end())
                rr.insert(res[b]);
            else
                cnt++; 
        }
        cout << cnt << endl;
        cout << (double)cnt / (double)(rr.size()-1) << endl;
    }
        system("pause");
    return 0;
}