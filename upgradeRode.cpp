#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
vector<int> pre;
vector<int> post;
struct node{
    int val;
    struct node *l, *r;
    node(int _val)
    {
        val = _val;
        r = l = NULL;
    }
};

node *build(node* root, int a)
{ 
    if (root == NULL)
    {
        root = new node(a);
        return root;
    }
    if (root->val > a)
        root->l = build(root->l, a);
    if (root->val < a)
        root->r = build(root->r, a);
    return root;
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    pre.push_back(root->val);
    preorder(root->l);
    preorder(root->r);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->l);
    postorder(root->r);
    post.push_back(root->val);
}

int main()
{ 
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    node *root = NULL;
    for (int i = 0; i < n; ++i)
    {
        root = build(root, a[i]);
    }
    preorder(root);
    for (auto it : pre)
        cout << it << ends;
    cout << endl;
    postorder(root);
    for (auto it : post)
        cout << it << ends;
    cout << endl;
    system("pause");
    return 0;
}