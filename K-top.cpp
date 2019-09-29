#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
priority_queue<int, vector<int>, less<int> > res;
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < nums.size(); i++)
    {
        if (pq.size() == k)
        {
            int x = pq.top();
            if (nums[i] > x)
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        else
        {
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
} int
                                          main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        int temp;
        cin >> temp;
        res.push(temp);
    }
    while (!res.empty())
    {
        cout << res.top() << ends;
        res.pop();
    }
    cout << endl;
    int cnt = 0;
    while(cnt < n)
    {
        cout << res.top() << endl;
        res.pop(res.top());
        cnt++;
    }
    cout << res.top() << endl; 
    system("pause");
    return 0;
}