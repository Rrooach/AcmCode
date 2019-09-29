#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, p, r;
vector<int> res;

struct node{
    int data;
    vector<int> child;
};
int maxd = -1, num = 0;
node N[1000];
void dfs(int root, int dep)
{
    if (N[root].child.empty())
    {
        if (dep > maxd)
        {
            maxd = dep;
            num = 1;
        }
        else if (dep == maxd)
            num++;
        return;
    }
    for (int i = 0; i < N[root].child.size(); ++i)
        dfs(N[root].child[i], dep + 1);
    return;
}
int main()
{
    int root;
    cin >> n >> p >> r;
    for (int i = 0; i < n; ++i)
    {
        N[i].data = i;
        int temp;
        cin >> temp;
        if (temp != -1)
            N[temp].child.push_back(i);
        else 
            root = i; 
    }
    dfs(root, 0);
    cout << maxd<< endl << num;
    system("pause");
    return 0;
}