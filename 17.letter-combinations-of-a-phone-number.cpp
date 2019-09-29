/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (41.11%)
 * Total Accepted:    372.5K
 * Total Submissions: 906.1K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:  
    vector<string> letterCombinations(string digits)
    {
        vector<string> mp{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty())
            return vector<string>{};
        queue<string> q;
        q.push("");
        for (int i = 0; i < digits.size(); ++i)
        { 
            int len = q.size();
            for (int j = 0; j < len; ++j)
            {
                string top = q.front();
                q.pop();
                for (int k = 0; k < mp[digits[i] - '0'].size(); ++k)
                {
                    q.push(top + mp[digits[i] - '0'][k]);
                }
            }
        }
        vector<string> ans;
        while (!q.empty())
        {
            string top = q.front();
            q.pop();
            ans.push_back(top);
        }
        return ans;
    } 
};
