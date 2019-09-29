#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;

struct node
{
    int add;
    int data;
    int next;
    bool flag;
} node[5];

int main()
{ 
    int start, n, k;
    cin >> start >> n >> k;
    cout << n << endl;
    for (int i = 0; i < n; ++i)
    {
        int address, data, next;
        cin >> address >> data >> next;
        node[address].add = address;
        node[address].data = data;
        node[address].next = next;
    }
    int pos = start;
    struct node head = node[pos];
    struct node pre;
    struct node next;
    while (head.next != -1)
    {  
        next = node[head.next];
        node[head.next] = pre;
        pre = head;
        head = next;
    } 
    while (pos != -1)
    {
        cout << node[pos].data << ends;
        pos = node[pos].next;
    }
    // for (int i = 0; i < maxn; ++i)
    //     node[i].flag = false;
    // int start, n, k;
    // cin >> start >> n >> k;
    // cout << n << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     int address, data, next;
    //     cin >> address >> data >> next;
    //     node[address].add = address;
    //     node[address].data = data;
    //     node[address].next = next;
    // }
    // int pos = start;
    // int cnt = 0;
    // while (pos != -1)
    // {
    //     cnt++;
    //     node[pos].flag = true;
    //     pos = node[pos].next;
    // }
    // pos = start;
    // for (int i = 0; i < cnt; i += k)
    // {
    //     if (i + k >= cnt)
    //         break;
    //     int tt = 0;
    //     // int pre = -1;
    //     struct node pre;
    //     struct node next;
    //     // int next = -1;
    //     while (pos!= -1)
    //     {
    //         tt++;
    //         if(tt == k)
    //         {
    //             node[start].next = node[pos].next;
    //             break;
    //         }   
    //         next = node[node[pos].next];
    //         node[node[pos].next] = pre;
    //         pre = node[pos];
    //         node[pos] = next;
    //     }
    // }
    // while (pos != -1)
    // {
    //     cout << node[pos].data << ends;
    //     pos = node[pos].next;
    // }
    system("pause");
    return 0;
}