#include <bits/stdc++.h>

using namespace std;

int main()
{ 
    int n;
    cin >> n;
    getchar();
    vector<string> j;
    for (int i = 0; i < n; ++i)
    {
        string temp;
        getline(cin, temp);
        // cout << temp << endl;
        j.push_back(temp);
    }
    int len = j.size();
    string res = j[0];
    for (int i = 1; i < len; ++i)
    {
        int len1 = res.length();
        int len2 = j[i].length();
        bool equal = true;
        string op = j[i];
        for (int i = len1, m = len2; i>=0 || m>=0; --i, --m)
        { 
            
            if (res[i] == op[m])
                continue;
            if (res[i] != op[m])
            {
                res = res.substr(i + 1, len1);
                break;
            }
        }
    }
    if (res == "")
        cout << "nai";
    else
        cout << res;
    system("pause");
    return 0;
}