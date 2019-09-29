/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        // cout << "21312";
        if (M.empty())
            return 0;
        int n = M.size();
        int ans = 0; 
        for (int i = 0; i < n; ++i)
        {
            if (!M[i][i])
                continue;
            cout << ans << endl;
            ++ans;
            dfs(i, M);
        }
        return ans;
    }
    void dfs(int j, vector<vector<int>> &M)
    {
        for (int k = 0; k < M.size(); ++k)
        {
            if (!M[j][k])
                continue;
            M[j][k] = M[k][j] = 0;
            dfs(k, M);
        }
    } 
};

