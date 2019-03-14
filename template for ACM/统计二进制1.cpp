//数字还是十分有规律的，其实就是统计2进制1的个数，但是自己太菜了，竟然没有做出来
#include <bits/stdc++.h>
using namespace std;
long long la(long long m)
{
    if(m==0)return 0;
    return 2LL*la(m/2)+(m+1)/2;
}
int main()
{
    long long n;
    cin>>n;
    cout<<la(n-1);
    return 0;
}
