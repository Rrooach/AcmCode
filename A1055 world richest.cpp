#include <bits/stdc++.h>

using namespace std;

struct node {
    string name;
    int age;
    int money;
};

bool cmp(struct node a, struct node b)
{
    if (a.money != b.money)
        return a.money > b.money;
    else if (a.age != b.age)
        return a.age < b.age;
    else 
        return a.name < b.name;
}
int main()
{
    int n, quere;
    cin >> n >> quere;
    struct node info[n+10];
    for (int i = 0; i < n; ++i)
        cin >> info[i].name >> info[i].age >> info[i].money;
    sort (info, info + n, cmp);
    for (int i = 0; i < quere; ++i)
    {
        int left, right, num;
        cin >> left >> right >> num;
        vector<struct node> res;
        int cnt = 0;
        for(auto it : info)
        {
            if (cnt == num)
                break;
            if (info[i].age >= left && info[i].age <= right)
            {
                res.push_back(info[i]);
                cnt++;
            }
        }
        sort(res.begin(), res.end(), cmp);
        for (auto it : res)
            cout << it.name << ends << it.age << ends << it.money << endl;
    }
    system("pause");
    return 0;
}