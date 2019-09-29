#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

int main()
{ 
    node *head = (struct node *)malloc(sizeof(struct node));  
    head->next = NULL;
    node* pre = head;
    for (int i = 0; i < 6; ++i)
    {
        node *op = (struct node *)malloc(sizeof(struct node)); 
        op->data = i;
        op->next = NULL;
        pre->next = op;
        pre = op; 
    }
    pre = head;
    while (pre != NULL)
    {
        cout << pre->data;
        pre = pre->next;
    }
    system("pause");
    return 0;
}