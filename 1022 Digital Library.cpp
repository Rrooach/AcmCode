#include <bits/stdc++.h>

using namespace std;

struct node
{
    int n;
    struct node *next;
    node(){};
    node(int _n, struct node *_next)
    {
        n = _n;
        next = _next;
    };
};

int main()
{
    struct node *p, *head;
    head = new node;
    p = new node                                                                                                                                                                                                                                                                                                                                                                                                                                      ;
    head->next = p;
    p->next = NULL;
    for (int i = 0; i < 6; ++i)
    {
        struct node *t = new node();
        t->n = i;
        t->next = head->next;
        head->next = t;
    }
    struct node *t = head->next;
    while (t->next != NULL)
        {
            cout << t->n;
            t = t->next;
        }

        system("pause");
        return 0;
}