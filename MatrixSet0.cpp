#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
string s = "pwwkew";
int main()
{
    int maxL = 0;
    int len = s.length();
    unordered_set<char> mmp;
    int left = 0, index = 0;
    while (index < len)
    {
        if (mmp.find(s[index]) == mmp.end())
        {
            mmp.insert(s[index++]);
            int size = mmp.size();
            maxL = max(maxL, size);
        }
        else
        {
            mmp.erase(s[left++]);
        }
    }
    cout << maxL;
    string s;
    s.subs
    system("pause");
    return 0;
}