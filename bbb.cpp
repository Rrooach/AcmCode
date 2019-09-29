#include <bits/stdc++.h>

using namespace std;
map<char, int> mmp;
struct node
{
    int data;
    node *next;
    node(){}
    node(int _data) {data= _data;}
};
// 创建单链表
node *creat()
{
    string a;
    cin >> a;
    node *head, *p;
    head = new node;
    p = head;
    int x, cycle = 0;
    int len = a.length();
    while (cycle < len)
    { 
        char x = a[cycle];
        if (isdigit(x))
        {
        	node *s = new node;
        	s->data = x; 
        	p->next = s;
        	p = s;	
        } 
        cycle++;
    }
    head = head->next;
    p->next = NULL;
    return head;
} 

bool hasCycle(node *head)
{
    if (head == NULL)
        return false;
    node *p = head;
    while (p!= NULL)
    {
        if (mmp[p->data] >= 1)
            return true;
        mmp[p->data]++;
        p = p->next;
    }
    return false;
}

node *reverseKGroup(node *head, int k)
{
    if (!head || k == 1)
        return head;
    node *dummy = new node(-1), *pre = dummy, *cur = head;
    dummy->next = head;
    for (int i = 1; cur; ++i)
    {
        if (i % k == 0)
        {
            pre = reverseOneGroup(pre, cur->next);
            cur = pre->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return dummy->next;
}
node *reverseOneGroup(node *pre, node *next)
{
    node *last = pre->next, *cur = last->next;
    while (cur != next)
    {
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = last->next;
    }
    return last;
}
int main()
{
    node *head = creat(); 
    int k;
    cin >> k; 
    node *p = reverseKGroup(head, k);
    system("pause");
    return 0;
}