#include <bits/stdc++.h> 
using namespace std;
int n;
vector<int> a, r1, r2, r12, r22; 
struct node{
    int data;
    node *left;
    node *right;
};

void insert(node* &root, int n)
{
    if (root == NULL)
    {
        root = new node;
        root->data = n;
        root->left = NULL, root->right = NULL; 
        return;
    }
    if (n >= root->data)
        insert(root->right, n);
    else
        insert(root->left, n);
} 
void preorder(node* root)
{
    if(root == NULL)
        return; 
    r1.push_back(root->data);
    preorder(root->left);
    preorder(root->right); 
}

void mirr_perorder(node *root)
{
    if (root == NULL)
        return; 
    r2.push_back(root->data);
    mirr_perorder(root->right);
    mirr_perorder(root->left);
}

void postordor(node* root)
{
    if (root == NULL)
        return; 
    postordor(root->left);
    postordor(root->right);
    r12.push_back(root->data); 
}
void mirr_postordor(node *root)
{
    if (root == NULL)
        return; 
    mirr_postordor(root->right);
    mirr_postordor(root->left); 
    r22.push_back(root->data); 
}
void check()
{ 
    if (r1 == a)
    {
        cout << "YES\n";
        for (int i = 0; i < n-1; ++i)
            cout << r12[i] << " ";
        cout << r12[n - 1] << endl;
    }
    else if(r2 == a)
    {
        cout << "YES\n";
        for (int i = 0; i < n - 1; ++i)
            cout << r22[i] << " ";
        cout << r22[n - 1] << endl;
    }
    else
        cout << "NO\n";   
}

int main()
{
    node *root = NULL;
    cin >> n; 
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
        insert(root, temp);
    }
    preorder(root);
    mirr_perorder(root);
    postordor(root);
    mirr_postordor(root);
    check(); 
    system("pause");
    return 0;
}