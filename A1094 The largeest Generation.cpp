#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
map<int, int> mmp; 
int n, m, root;
struct node{
    int data;
    vector<int> child;
} N[110];
bool isroot[110] = {false};

void bfs(int root)
{
    queue<node> q;
    q.push(N[root]);
    int level = 1;
    int crucnt = 1, nextcnt = 0;
    while (!q.empty())
    {
        mmp[level]++;
        node t = q.front();
        q.pop();
        cout << t.data << ends;
        crucnt--; 
        for (int i = 0; i < t.child.size(); ++i)
        { 
            q.push(N[t.child[i]]);
            nextcnt++;
        } 
        if (crucnt == 0)
        {
            cout << endl;
            level++;
            crucnt = nextcnt;
            nextcnt = 0; 
        }
    }
    return;
}

void dfs(int root, int dep)
{
    mmp[dep]++;
    for (int i = 0; i < N[root].child.size(); ++i)
        dfs(N[root].child[i], dep + 1);
    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int fa, numchild;
        cin >> fa >> numchild;
        N[fa].data = fa; 
        for (int j = 0; j < numchild; ++j)
        {
            int leaf;
            cin >> leaf;
            N[fa].child.push_back(leaf);
            isroot[leaf] = true;
            // cout << leaf << endl;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (isroot[i] == false)
        {
            root = i;
            break;
        }
    bfs(root);
    // dfs(root, 1);
    int maxL, maxnum = -1;
    for (auto it:mmp)
    { 
        if (it.second > maxnum)
        {
            maxL = it.first;
            maxnum = it.second;
        }
    }
    cout << maxnum << " " << maxL << endl;
    system("pause");
    return 0;
}