#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

vector<string> wordBreak(string s, vector<string> &wd)
{
    int n = s.length();
    unordered_set<string> md(wd.begin(), wd.end());
    vector<bool> dp(n + 1, false);
    vector<string> res;
    dp[0] = true;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (dp[j] && md.find(s.substr(j, i - j)) != md.end())
                dp[j] = true;
        }
    }
    for (auto it : dp)
        cout << it << ends;
    cout << endl;
    if (!dp[s.length()])
        return res;
    string ans = "";
}

int main()
{
    vector<string> a = {"!23", "1231231"};
    wordBreak("123123", a);
    system("pause");
    return 0;
}