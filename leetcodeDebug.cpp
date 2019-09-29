#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;

bool ishui(string s)
{
    int r = s.length() - 1;
    int l = 0;
    while (l <= r)
    {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}
int lenLongestFibSubseq(vector<int> &A)
{
    int N = A.size();
    unordered_set<int> S(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
        {
            /* With the starting pair (A[i], A[j]),
                 * y represents the future expected value in
                 * the fibonacci subsequence, and x represents
                 * the most current value found. */
            int x = A[j], y = A[i] + A[j];
            int length = 2;
            while (S.find(y) != S.end())
            {
                int z = x + y;
                x = y;
                y = z;
                ans = max(ans, ++length);
            }
        }

    return ans >= 3 ? ans : 0;
}
int main()
{
    vector<int> a = {1, 3, 7, 11, 12, 14, 18};
    cout << lenLongestFibSubseq(a) << endl;
    // string a = "leet";
    // cout << a.substr(1, 1);
    system("pause");
}