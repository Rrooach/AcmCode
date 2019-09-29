#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
vector<int> arr;

struct node{
    int data, hight;
    node *left;
    node *right;
};
node *root;

int getHight(node* root)
{
    if (root == NULL)
        return 0;
    return max(getHight(root->right), getHight(root->left)) + 1;
}

void updateHight(node* root)
{ 
    root->hight =  max(getHight(root->right), getHight(root->left)) + 1;
}

int getBalanceFactor(node* root)
{
    return getHight(root->left) - getHight(root->right);
}

void L(node* &root)
{
    node *temp = new node();
    temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHight(root);
    updateHight(temp);
    root = temp;
}

void R(node* &root)
{
    node *temp = new node();
    temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHight(root);
    updateHight(temp);
    root = temp;
}

void insert(node* &root, int data)
{
    if (root == NULL)
    {
        root = new node();
        root->data = data;
        root->left = NULL, root->right = NULL;
        return;
    }
    if (data < root->data)
    {
        insert(root->left, data);
        updateHight(root);  
        if (getBalanceFactor(root) == 2)
        {
            if (getBalanceFactor(root->left) == 1)
                R(root);
            else if (getBalanceFactor(root->left) == -1)
            {
                L(root->left);
                R(root);
            } 
        }
    } 
    else
    {
        insert(root->right, data);
        updateHight(root);
        if (getBalanceFactor(root) == -2)
        {
            if (getBalanceFactor(root->right) == -1)
                L(root);
            else if (getBalanceFactor(root->right) == 1)
            {
                R(root->right);
                L(root);
            }
        }
    }
        
} 
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        insert(root, temp);
    } 
    cout << root->data;
    system("pause");
    return 0;
}