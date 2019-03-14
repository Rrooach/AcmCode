#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int a[maxn*2],vis[maxn*2];
int main()
{
    int n,m;
    int pos = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n ;i ++)
    {
        scanf("%d",&a[i]);
        if(a[i] == m)
        {
            pos = i;
        }
    }
    int cnt = 0;
    for(int i = pos ; i < n ; i++)
    {
        if(a[i] > m) cnt++;
        if(a[i] < m) cnt--;
        vis[maxn + cnt] ++; // 当前指的 maxn + cnt 指的是，比m大的值和比m小的值的差，通俗的讲就是我现在还差 -cnt 个可以凑到0 
  		cout <<"cnt = "<< cnt <<" maxn + cnt = " <<maxn + cnt<<" vis [maxn + cnt] = "<< vis[maxn + cnt]<<endl;
    }
    cnt = 0;
    long long ans = 0;
    for(int i = pos ; i >= 0 ; i--)
    {
        if(a[i] < m) cnt ++;
        if(a[i] > m) cnt --;
        ans += vis[maxn + cnt]; // 这个就是 我现在已经凑到 cnt个了，那么他的值就是0，于是就有vis[cnt]个区间了 
        ans += vis[maxn + cnt + 1]; // 仔细想想就是当区间长度是偶数的时候 我们取他的左边那位 

    }
    cout<<ans<<endl;
}
