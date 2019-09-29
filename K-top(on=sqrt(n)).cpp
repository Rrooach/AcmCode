#include <bits/stdc++.h>
#define maxn 10
using namespace std;


int main()
{ 
    int t;
    cin >> t; 
    while (t--)
    {
        int block[maxn], table[maxn];
        memset(block, 0, sizeof(block));
        memset(table, 0, sizeof(table));
        int n, k, res, flag = 0;
        cin >> n >> k;
        int size = sqrt(n);
        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            block[num / size]++;
            table[num]++;
        }
        int sum = 0, idx = 0;
        while (sum + block[idx] < k)
            sum += block[idx++];
        int num = idx * size;
        while (sum + table[num] < k)
            sum += table[num++];
        cout << num << endl;
    }
    // system("pause");
    return 0;
}