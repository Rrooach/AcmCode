#include <bits/stdc++.h>
#define maxn 150
using namespace std; 
int m, s, w;
int sum = 0;
int path[maxn]; 
struct node
{
    int data;
    vector<int> child;
}Node[maxn];

void dfs(int index, int numNode, int sum)
{
    if (sum > w)
        return;
    if (sum == w)
    {
        if (!Node[index].child.empty())
            return; 
        for (int i = 0; i < numNode - 1; ++i) 
            printf("%d ", Node[path[i]].data);
        printf("%d\n", Node[path[numNode - 1]].data);
        return;
    } 
    int len = Node[index].child.size();
    for (int i = 0; i < len; ++i)
    {
        int child = Node[index].child[i];
        path[numNode] = child;
        dfs(child, numNode + 1, sum + Node[child].data);
    } 
    return;
}
bool cmp(int a, int b)
{
    return Node[a].data > Node[b].data;
}

int main()
{
    scanf("%d%d%d", &m, &s, &w); 
    int temp;
    for (int i = 0; i < m; ++i) 
        scanf("%d", &Node[i].data);  
    for (int i = 0; i < s; ++i)
    {
        int fa, t;
        scanf("%d%d", &fa, &t);
        for (int i = 0; i < t; ++i)
        {
            int child;
            scanf("%d", &child);
            Node[fa].child.push_back(child);
        }
        sort(Node[fa].child.begin(), Node[fa].child.end(), cmp);
    }
    dfs(0, 1, Node[0].data); 
    system("pause");
    return 0;
}