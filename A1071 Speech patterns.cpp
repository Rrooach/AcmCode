#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    string a;
    map<string, int> mmp;
    getline(cin, a);
    int len = a.length();
    string temp = "";
    for (int i = 0; i < len; ++i)
    { 
        if (isdigit(a[i]) || isalpha(a[i]))
        {
            a[i] = tolower(a[i]);
            temp += a[i];
        }
        else
        {
            if (temp == "")
                continue;
            if (mmp.find(temp) == mmp.end())
                mmp[temp] = 1;
            else
                mmp[temp]++;
            temp = "";
        }
    }
    int maxn = -1;
    string res;
    if (temp != "")
        mmp[temp] = 1;
    for (auto it : mmp)
    {
        if (it.second >= maxn)
        {
            maxn = it.second;
            res = it.first;
        }
    }
    cout << res << " " << maxn << endl;
    system("pause");
    return 0;
}