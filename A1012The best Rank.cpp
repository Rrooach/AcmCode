#include <bits/stdc++.h>

using namespace std;

struct node {
    string sid;
    int c, m, e, a;
    node() {};
    node(string _sid, int _c, int _m, int _e, int _a)
    {
        sid = _sid;
        c = _c, m = _m, e = _e, a = _a;
    };
};

int main()
{
    int d, t;
    cin >> d >> t;
    struct node info[d+10];
    for (int i = 0; i < d; ++i)
    {
        cin >> info[i].sid >> info[i].c >> info[i].m >> info[i].e;
        info[i].a = info[i].c + info[i].e + info[i].m;
    }
    for (int i = 0; i < 4; ++i)
    {
        
    }

    system("pause");
    return 0;
}