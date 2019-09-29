#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

struct node
{
    int add;
    int data;
    int next;
    bool flag;
} node[maxn];

int main()
{ 
    int start, n, k;
    cin >> start >> n; 
    for (int i = 0; i < maxn; ++i)
        node[i].flag = false; 
    for (int i = 0; i < n; ++i)
    {
        int address, data, next;
        cin >> address >> data >> next;
        node[address].add = address;
        node[address].data = data;
        node[address].next = next;
    }
    int pos = start;
    vector<struct node> a, b;
    set<int> res;
    int cnt = 0;
    while (pos != -1)
    {
        cnt++;
        node[pos].flag = true;
        pos = node[pos].next;
    } 
    pos = start;
    while (pos != -1 && node[pos].flag == true)
    {
        if (res.find(abs(node[pos].data)) == res.end())
        {
            res.insert(abs(node[pos].data));
            a.push_back(node[pos]);
        } 
        else
            b.push_back(node[pos]);
        pos = node[pos].next;
    }
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (i + 1 == a.size())
        {
            printf("%05d %d -1\n", a[i].add, a[i].data);
        }
        else
        {
            printf("%05d %d %05d\n", a[i].add, a[i].data, a[i + 1].add);
        }
    }

    for (size_t i = 0; i < b.size(); ++i)
    {
        if (i + 1 == b.size())
        {
            printf("%05d %d -1\n", b[i].add, b[i].data);
        }
        else
        {
            printf("%05d %d %05d\n", b[i].add, b[i].data, b[i + 1].add);
        }
    }  
     system("pause");
    return 0;
}