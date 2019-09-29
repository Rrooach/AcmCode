#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        while(!pq.empty())
            pq.pop();
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i)
        {
            int temp;
            scanf("%d", &temp);
            pq.push(temp);
        }
        for (int i = 0; i < k-1; ++i) 
            pq.pop(); 
        cout << pq.top() << endl;
    }
    // int mmp[100][100];
    // for (int k = 1; k <= 10; ++k)
    // {
    //     for (int c = 1; c <= 10; ++c)
    //     {
    //         int temp = k;
    //         int cnt = 0; 
    //         while (temp != 1)
    //         {
    //             temp = temp * c / (c + 1);
    //             cnt++;
    //         }
    //         mmp[k][c] = cnt; 
    //     } 
    // }
    // for (int i = 1; i <= 100; ++i)
    // {
    //     for (int j = 1; j <= 100; ++j)
    //     {
    //         cout << mmp[i][j] << ends;
    //     }
    //     cout << endl;
    // } 
    system("pause");
    return 0;
}