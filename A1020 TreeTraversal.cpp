#include <bits/stdc++.h>
#define maxn 10
using namespace std;

struct node{
    int data;
    int layer;
    struct node *left;
    struct node *right;
};
vector<int> res;
int in[maxn];
int su[maxn];

node* create(int inL, int inR, int suL, int suR)
{
    if (suL > suR)
        return NULL; 
    node* root = new node;
    root->data = su[suR];
    int k;
    for (k = inL; k <= inR; ++k)
        if (in[k] == su[suR])
            break;
    int len = k - inL; 
    root->left = create(inL, k - 1, suL, suL + len - 1);
    root->right = create(k + 1, inR, suL + len, suR - 1);
    return root;
}

void Slayer(node* root)
{
    if (root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        res.push_back(temp->data);
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right!= NULL)
            q.push(temp->right);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> su[i];
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    node* root = create(0, n - 1, 0, n - 1);
    Slayer(root);
    for (auto it : res)
        cout << it << ends;
        system("pause");
    return 0;
}

/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/