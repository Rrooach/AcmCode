/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (54.23%)
 * Total Accepted:    323.5K
 * Total Submissions: 596.5K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string a;
        for (int i = 0; i < n; i++)
        {
            a += "(";
            a += ")";
        }
        sort(a.begin(), a.end());
        vector<string> ans;
        do{
            if (check(a))
            {
                cout << 1 << ends << a << endl;
                ans.push_back(a);
            }
        }while (next_permutation(a.begin(), a.end()));
        return ans;
    }
    bool check(string a)
    {
        stack<char> s;
        cout << a << endl;
        for (auto it : a)
        {
            if (it == '(')
                s.push(it);
            else
            {
                if (s.empty())
                    return false;
                if (it == ')')
                    s.pop();
            }
        }
        return true;
    }
};

