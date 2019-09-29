#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
struct node{
    int data;
    int lc;
    int rc;
};
bool father[1000] = {false};
node N[1000];
vector<int> ly, in;
void lyorder(int root)
{
    queue<node> res;
    res.push(N[root]);
    while (!res.empty())
    {
        node t = res.front();
        res.pop();
        ly.push_back(t.data);
        if (t.rc != -1)
            res.push(N[t.rc]);
        if (t.lc != -1)
            res.push(N[t.lc]);
    }
}

void inorder(int root)
{
    if (root == -1)
        return;
    if (N[root].rc != -1)
        inorder(N[root].rc);
    in.push_back(N[root].data);
    if (N[root].lc != -1)
        inorder(N[root].lc);
}

int findroot()
{
    for (int i = 0; i < n; ++i)
        if (!father[i])
            return i;
}

int main()
{
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i)
    { 
        N[i].data = i;
        char a, b;
        scanf("%c %c", &a, &b);
        getchar();
        if (a == '-')
            N[i].lc = -1;
        else
        {
            int a1 = a - '0';
            father[a1] = true;
            N[i].lc = a1;
        }
        if (b == '-')
            N[i].rc = -1;
        else
        {
            int b1 = b - '0';
            father[b1] = true;
            N[i].rc = b1;
        }
    }
    int root = findroot();
    lyorder(root);
    for (auto it : ly)
        cout << it << ends;
    cout << endl;
    inorder(root);
    for (auto it : in)
        cout << it << ends;
    cout << endl;
    system("pause");
    return 0;
}