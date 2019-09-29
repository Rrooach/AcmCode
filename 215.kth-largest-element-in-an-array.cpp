/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (47.13%)
 * Total Accepted:    355.4K
 * Total Submissions: 754.2K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        if (nums.empty())
            return 0;
        int l = 0;
        int ans = 0;
        int r = nums.size();
        while (l < r)
        {
            int pos = partition(l, r, nums, k);
            if (k == pos - 1)
            {
                ans = nums[pos];
                break;
            }
            if (k > pos - 1)
                r = pos - 1;
            if (k < pos - 1)
                l = pos;
        }
        return ans;
    }
    int partition(int left, int right, vector<int> &nums, int k)
    {
        int l = left, r = right;
        int temp = nums[l];
        while (l < r)
        {
            while (l < r && temp > nums[l])
                l++;
            swap(nums[l], nums[r]);
            while (l < r && temp < nums[r])
                r--;
            swap(nums[l], nums[r]);
        }
        nums[l] = temp;
        return nums[l];
    }
};