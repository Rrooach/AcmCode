#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<char> full;
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int l1 = a.length(), l2 = b.length();
    transform(a.begin(), a.end(), a.begin(), :: tolower);
    transform(b.begin(), b.end(), b.begin(), :: tolower);
    for (int i = 0; i < l2; ++i)
        full.insert(b[i]);
    vector<char> res;
    for (int i = 0; i < l1; ++i)
    {
        if (full.find(a[i]) == full.end())
            res.push_back(a[i]);
    }
    transform(res.begin(), res.end(), res.begin(), :: toupper);
    for (auto it : res)
        cout << it;

    system("pause");
    return 0;
}