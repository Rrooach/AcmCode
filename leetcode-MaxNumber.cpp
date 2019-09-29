#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    vector<string> tmp;
    for (auto &it : nums)
    {
        string s = to_string(it);
        tmp.push_back(s);
    }
    sort(tmp.begin(), tmp.end());
    for (auto it : tmp)
        cout << it << ends;
    cout << endl;
    system("pause");
    return 0;
}