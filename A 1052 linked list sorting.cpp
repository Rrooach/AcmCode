#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

struct node{
    int cur;
    int data;
    int next;
    bool flag;
} node[maxn];

bool cmp(struct node &a, struct node &b)
{
    if (a.flag == false || b.flag == false)
        return a.flag > b.flag;
    else
        return a.data < b.data;
}

int main()
{
    for (int i = 0; i < maxn; ++i)
        node[i].flag = false;
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        int cur, n, next;
        cin >> cur >> n >> next;
        node[cur].data = n;
        node[cur].next = next;
        node[cur].cur = cur;
    }  
    int pos = s;
    int cnt = 0;
    while (pos != -1)
    {
        node[pos].flag = true;
        pos = node[pos].next;
        cnt++;
    }
    if (cnt == 0)
        cout << "0 -1\n";
    else
    {
        sort(node, node + maxn, cmp);
        pos = s;
        printf("%d %05d\n", cnt, node[0].cur);
        for (int i = 0; i < cnt - 1; ++i)
        {
            printf("%05d %d %05d\n", node[i].cur, node[i].data, node[i + 1].cur);
        }
        printf("%05d %d -1\n", node[cnt - 1].cur, node[cnt - 1].data);
    }
     
    
    system("pause");
    return 0;
}