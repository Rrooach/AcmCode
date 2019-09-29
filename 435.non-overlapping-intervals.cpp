/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &in)
    {
        if (in.empty())
            return 0;
        int len = in.size();
        sort(in.begin(), in.end(), cmp);
        int cnt = 0;
        for (int i = 1; i < len; ++i)
        {
            if (in[i - 1][1] > in[i][0])
            {
                in.erase(in.begin() + i);
                cnt++;
            }
        }
        return cnt;
    }
};

