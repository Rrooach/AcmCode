#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
vector<int> pre, mid, post; 

struct node{
    int data;
    node *lc;
    node *rc;
};

node* build(int ps, int pe, int ms, int me)
{
    if (ps > pe)
        return NULL;
    node *root = new node;
    root->data = pre[ps];
    int j;
    for (j = ms; j < me; ++j)
        if (mid[j] == pre[ps])
            break;
    int len = j - ms;
    root->lc = build(ps + 1, ps + len, ms, j - 1);
    root->rc = build(ps + len + 1, pe, j + 1, me);
    return root;
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->lc);
    postorder(root->rc);
    post.push_back(root->data);
}


int main()
{
    int n, cnt = 0;
    stack<int> temp;
    cin >> n;
    n = n << 1;
    getchar();
    while (cnt < n)
    {
        string s;
        getline(cin, s);
        cnt++;
        if (s.find("Push") != string::npos)
        {
            int tt = s[s.length() - 1] - '0';
            temp.push(tt);
            pre.push_back(tt);
        }
        if (s.find("Pop") != string::npos)
        {
            mid.push_back(temp.top());
            temp.pop();
        }
    }
    n = n >> 1;
    node * root = build(0, n-1, 0, n-1);
    postorder(root);
    for (auto it : post)
        cout << it << ends;
    cout << endl;
    system("pause");
    return 0;
}