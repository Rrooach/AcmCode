#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    if (nums.empty())
        return ans;
    multiset<int> window(nums.begin(), nums.begin() + k - 1);
    for (int i = k - 1; i < nums.size(); ++i)
    {
        window.insert(nums[i]);
        ans.push_back(*window.rbegin()); 
        if (i - k + 1 >= 0)
        {
            int t = window.count(nums[i - k + 1]);
            if (t != 1)
            {
                window.erase(nums[i - k + 1]);
                while ((t--) > 1)
                    window.insert(nums[i - k + 1]);
            }
            else
                window.erase(nums[i - k + 1]);
        }
    }
    return ans;
}

int main()
{
    int k = 4;
    vector<int> nums = { -7, -8, 7, 5, 7, 1, 6, 0};
    vector<int > ans = maxSlidingWindow(nums, k);
    for (auto it:ans)
        cout << it << ends;
    cout << endl;
    system("pause");
    return 0;
}