#include <bits/stdc++.h>
#define maxn 10005
using namespace std;

struct node{
    int add;
    int data;
    int next;
    bool flag;
} node[maxn];

int main()
{
    // for (int i = 0; i < maxn; ++i)
    //     node[i].flag = false;
    int start, n, k; 
    cin >> start >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int address, data, next;
        node[address].add = address;
        node[address].data = data;
        node[address].next = next;
    }
    int pos = start;
    int cnt = 0;
    while (pos != -1)
    {
        cnt++;
        node[pos].flag = true;
        pos = node[pos].next;
    }
    pos = start;
    for (int i = 0; i < cnt; i += k)
    {
        if (i +k>=cnt)
            break;
        for (int j = i; j < k; ++j)
        {
            int p = node[pos].next;
            int t = node[p].next;
            node[pos].next = node[p].next;
            node[p].next = node[t].next;
            node[t].next = p;
        }
    }
    pos = start;
    while (pos != -1)
    {
        cout << node[pos].data << ends;
        pos = node[pos].next;
    }
        system("pause");
    return 0;
}