#include <bits/stdc++.h>

using namespace std;
map<char, int> mmp;
struct node
{
    char data;
    node *next;
};
// 创建单链表
// bool *creat()
// {
//     string a;
//     cin >> a;
//     node *head, *p;
//     head = new node;
//     p = head;
//     int x, cycle = 0;
//     int len = a.length();
//     while (cycle < len)
//     { 
//         char x = a[cycle];
//         if (isalpha(x))
//         {
//         	node *s = new node;
//         	s->data = x; 
//         	p->next = s;
//             if (mmp[x] >= 1)
//                 return true;
//             mmp[x]++;

//             p = s;	
//         } 
//         cycle++;
//     }
//     head = head->next;
//     p->next = NULL;
//     return head;
// } 

// bool hasCycle(node *head)
// {
//     if (head == NULL)
//         return false;
//     node *p = head;
//     while (p!= NULL)
//     {
//         if (mmp[p->data] >= 1)
//             return true;
//         mmp[p->data]++;
//         p = p->next;
//     }
//     return false;
// }

// node *reverseList(node *head)
// {
//     if (head == NULL || head->next == NULL)
//         return head;
//     else
//     {
//         node *h = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return h;
//     }
// }

int main()
{
    string a;
    cin >> a;
    int len = a.length();
    int flag = 0;
    for (int i = 0; i <len; ++i)
    {
        char x = a[i];
        if (isalpha(x))
        {
            if (mmp[x]>=1)
            {
                flag = 1;
                break;
            }
            else
                mmp[x]++; 
        }
    }
    if (flag == 1)
        cout << true;
    else
        cout << "false";
    system("pause");
    return 0;
}