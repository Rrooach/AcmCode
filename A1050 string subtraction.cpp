#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b; 
    getline(cin, a);
    getline(cin, b);
    map<char, bool> mmp;
    int l1 = a.length(), l2 = b.length();
    for (int i = 0; i < l2; ++i)
    {
        mmp[b[i]] = true;
    }
    for(int i = 0; i < l1; ++i)
    {
        if (mmp[a[i]] == true)
            continue;
        else 
            cout << a[i];   
    }
    system("pause");
    return 0;
}