#include <bits/stdc++.h>
#define maxn 10
using namespace std;
int m, n;
int father[maxn];
priority_queue<int, vector<int>, greater<int> >res;

void init()
{
    for (int i = 1; i <= maxn; ++i)
        father[i] = i;
}

int findfather(int d)
{
    if (d == father[d])
        return d;
    else
    {
        int v = findfather(father[d]);
        father[d] = v;
        return v;
    }
}

void union1(int a, int b)
{
    int p1 = findfather(a);
    int p2 = findfather(b);
    if (p1 != p2)
    {
        father[p2] = p1;
    }
}

int main()
{
    init(); 
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        cout << father[i];
    cout << endl;
    for (int i = 1; i <= n; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        union1(t1, t2);
    }

    set<int> res;

    for (int i = 1; i <= m; ++i)
        if (res.find(father[i]) == res.end())
            res.insert(father[i]);
    for (int i = 1; i <= m; ++i)
        cout << father[i] << ends;
    cout << endl;
    cout << res.size();
    system("pause");
    return 0;
}

/*
4 2
1 4
2 3 

7 5
1 2
2 3
3 1
1 4
5 6
*/