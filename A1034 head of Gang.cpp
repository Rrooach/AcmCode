#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int cntPeople = 0, numGang = 0;
int n, k;
struct node{
    string name;
    int total;
} N[maxn];
map<int, int> cntWei;
int call[10][10];
bool vis[1005];
map<string, int> mmp;
map<int, int> res;
int tohash(string a)
{ 
    if (mmp.find(a) != mmp.end())
        return mmp[a];
    else
    {
        mmp[a] = cntPeople;
        return cntPeople++;
    }
}

void dfs(int &len,  int &memnum, int cur, int &node)
{ 
        memnum++;
        if (cntWei[cur] > cntWei[node])
            node = cur;
        for (int i = 0; i < cntPeople; ++i)
        {
            if (call[cur][i] > 0)
            {
                len += call[cur][i];
                call[cur][i] = call[i][cur] = 0;
                if (!vis[i])
                {
                    vis[i] = true; 
                    dfs(len, memnum, i, node);
                }
            } 
        } 
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        string n1, n2;
        int wei;
        cin >> n1 >> n2 >> wei;
        int t1 = tohash(n1);
        cntWei[t1] += wei;
        int t2 = tohash(n2); 
        cntWei[t2] += wei;
        call[t1][t2] += wei;
        call[t2][t1] += wei;
    } 
    for (int i = 0; i < cntPeople; ++i)
    { 
        if (!vis[i])
        {
            int memnum = 0, len = 0, node = i;
            vis[i] = true;
            dfs(len, memnum, i, node);
            if (len > k && memnum > 2)
            {
                numGang++;
                res[node] = memnum;
            }
        }  
    }
    cout << numGang << endl;
    for (auto it : res)
    {
        string a;
        for (auto itt :mmp)
            if (it.second == it.first)
            {
                a = itt.first;
                break;
            }
        cout << a << " " << it.second << endl;
    }
        
    system("pause");
    return 0;

}