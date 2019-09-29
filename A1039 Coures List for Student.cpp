#include <bits/stdc++.h>

using namespace std;

int process(string a)
{
    int res;
    for (int i = 0; i < 3; ++i)
    {
        res = res * 26 + (a[i] - '0');
    }
    res = res * 10 + (a[3] - '0');
    return res;
}

int main()
{
    int stu, cor;
    cin >> stu >> cor;
    vector<vector<int> > res;
    for (int i = 0; i < cor; ++i )
    {
        int id, stu_num;
        cin >> id >> stu_num;
        for (int i = 0; i < stu_num; ++i)
        {
            string a;
            cin >> a;
            int has = process(a);
            res[has].push_back(id);
        }
    }
    for (int i = 1; i <= stu; ++i)
    {
        string name;
        cin >> name;
        int has = process(name);
        sort(res[i].begin(), res[i].end());
    }
    system("pause");
    return 0;
}