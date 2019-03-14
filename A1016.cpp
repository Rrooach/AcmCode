#include <bits/stdc++.h>

using namespace std;

struct node{
    string name;
    string date;
    string statue;
    node() {};
    node(string _name, string _date, string _statue)
    {
        name = _name;
        date = _date;
        statue = _statue;
    };
};

bool cmp(struct node a, struct node b)
{
    if (a.name != b.name)
        return a.name < b.name;
    if (a.date != b.date)
        return a.date < b.date;
    if (a.statue != b.statue)
        return a.statue > b.statue;
}

int main()
{
    int n;
    cin >> n;
    struct node info[n+10];
    for (int i = 0; i < n; ++i)
    {
        cin >> info[i].name >> info[i].date >> info[i].statue;
    }
    sort(info, info+n, cmp);
    vector<struct node> res;
    res.push_back(info[0]);
    for (int i = 1; i < n; ++i)
    {
/*
CYJJ 01:01:05:59 on-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:06:01 on-line
CYLL 01:01:08:03 off-line
CYLL 01:28:15:41 on-line
CYLL 01:28:16:05 off-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
aaa 01:04:23:59 off-line
aaa 01:05:02:24 on-line
        */ 
        if (info[i].name == res.back().name)
        {
            if (info[i].date > res.back().date)
            {
                if (info[i].statue == "on-line" && info[i].statue == res.back().statue)
                    res.back() = info[i];
                else if (info[i].statue == "off-line" && info[i].statue == res.back().statue)
                    continue;
                else
                    res.push_back(info[i]);
            }
            else
                res.push_back(info[i]);
        } 
        else
                res.push_back(info[i]);
        //cout << info[i].name << ends << info[i].date << ends << info[i].statue << endl;
    }
    if (res.back().statue == "on-line")
        res.resize(res.size() - 1);
    for (auto i : res)
        cout << i.name << ends << i.date << ends << i.statue << endl;

    system("pause");
    return 0;
}