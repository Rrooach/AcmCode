#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
bool flag = false; 
int s, c, p;
vector<int> res;
vector<int> d;
vector<int> t;
int maxx = -1;
void dfs(int index, int op, int summ, int sum)
{
    if (summ > s || op > c)
        return;
    if (summ == s && op == c)
    {
        if (sum > maxx)
        {
            res = t;
            maxx = sum;
        }
        return;
    }
    if (index > 0)
    {
        t.push_back(index);
        dfs(index, op+1, summ + d[index], sum + index);
        t.pop_back();
        dfs(index - 1, op, summ, sum);
    } 
}

int main()
{
    scanf("%d%d%d", &s, &c, &p);
    int index = 1;
    int temp = 1;
    while (temp < s)
    {
        d.push_back(temp);
        temp = pow(index, p);
        index++;
    }
    dfs(d.size()-1, 0, 0, 0);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ends;
    system("pause");
    return 0;
}