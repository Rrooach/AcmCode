#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, pos = 0;
vector<int> num, res; 
struct node
{
    int data;
    int lc;
    int rc;
} N[110];

void perorder(int root)
{ 
    if (root == -1)
        return;
    perorder(N[root].lc);
    N[root].data = num[pos++]; 
    perorder(N[root].rc);
}

void lyorder(int root)
{
    queue<node> q;
    q.push(N[root]);
    while (!q.empty())
    {
        node t = q.front();
        q.pop();
        res.push_back(t.data);
        if (t.lc != -1)
            q.push(N[t.lc]);
        if (t.rc != -1)
            q.push(N[t.rc]);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int left, right;
        cin >> left >> right;
        N[i].lc = left;
        N[i].rc = right;
    }
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end()); 
    perorder(0);
    lyorder(0);
    for (int i = 0; i < res.size() - 1; ++i)
        cout << res[i] << " ";
    cout << res[res.size() - 1] << endl;
    system("pause");
    return 0;
}