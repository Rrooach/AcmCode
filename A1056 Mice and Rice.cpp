#include <bits/stdc++.h>
#define maxn 10005
using namespace std;

struct node{
    int data;
    int rank;
}node[maxn];

int main()
{
    int np, ng;
    queue<int> a;
    cin >> np >> ng;
    for (int i = 0; i < np; ++i)
        cin >> node[i].data;
    for (int i = 0; i < np; ++i)
    {
        int n;
        cin >> n;
        a.push(n);
    }
    int cnt = 0;
    while (a.size() > 1)
    {
        int temp;
        int Max = -1, Maxt = 0; 
        for (int i = 0; i < ng; ++i)
        {
            if (cnt >= np)
            {
                np = a.size()+1;
                cnt = 0;
                break;
            } 
            int t = a.front();
            a.pop();
            temp = node[t].data;
            if (Max < temp)
            {
                Max = temp;
                Maxt = t;
            }
            cnt++;
        }
        a.push(Maxt); 
    }
    while(!a.empty())
    {
        cout << a.front();
        a.pop();
    }
    system("pause");
    return 0;
}