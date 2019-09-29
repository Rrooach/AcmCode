/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (52.13%)
 * Total Accepted:    352K
 * Total Submissions: 675.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  vector<vector<int>> subsets(vector<int> &nums)
  {
      int n = nums.size();
      if (nums.empty())
          return res;
      int i = 1;
      int size = pow(2, n);
      while (size--)
      {
          res.push_back(check(size, nums));
      }
      vector<int> t;
      t.clear();
      res.push_back(t);
      return res;
    }
    vector<int> check(int n, vector<int> &nums)
    {
        vector<int> ans;
        int temp = n;
        int pos = 0;
        while (temp&1)
        {
            ans.push_back(nums[pos]);
            pos++;
        }
        string a = "";
        char s = 'c';
        a += s; 
        temp -= 1;
        return ans;
    }

};

