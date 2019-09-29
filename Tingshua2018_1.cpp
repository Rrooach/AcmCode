#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int main()
{
    long long a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        vector<string> ans;
        for (long long i = a; i <= b; ++i)
        {
            string s = to_string(i);
            string t = s;
            reverse(s.begin(), s.end());
            if (t == s)
            {
                cout << t << endl; 
            } 
        }
        for (auto it : ans)
            cout << it << endl;
    }

    system("pause");
    return 0;
}