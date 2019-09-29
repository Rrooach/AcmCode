#include <bits/stdc++.h>
#define maxn 100005
#define A(i) nums[(1 + 2 * (i)) % (n | 1)]
using namespace std;

void wiggleSort(vector<int> &nums)
{
    int n = nums.size(); 
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr; 
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
    {
        cout << A(j);
        if (A(j) > mid)
            swap(A(i++), A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;
    }
}
int main()
{
    vector<int> nums = {18, 17, 19, 16, 15, 11, 14, 10, 13, 12};
    wiggleSort(nums);
    for(auto it : nums)
        cout << it << ends;
    system("pause");
    return 0;
}