#include <bits/stdc++.h>

using namespace std;

struct node{
    int start;
    int end;
    node() {};
    node(int _start, int _end)
    {
        start = _start;
        end = _end;
    };
}Node[10010];

bool cmp(struct node a, struct node b)
{
    return a.start < b.start;
}

int main()
{
    int n;
    cin >> n;
    int a, b; 
    struct node Node[n+10];
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        Node[i] = node(a, b);
    }
    sort(Node, Node+n, cmp);
    vector<struct node> res;
    res.push_back(Node[0]);
    for (int i = 1; i < n; ++i)
    {
        if (Node[i].start < res.back().end)
            res.back().end = Node[i].end;
        else
        {
                res.push_back(Node[i]);
        }
    }

    for (auto it : res)
        cout << it.start << ends << it.end << endl;
    system("pause");
    return 0;
}