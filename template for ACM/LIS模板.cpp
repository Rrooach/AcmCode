#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;
 
const int N = 131072;
 
int n = 7, a[N] = {0,0,1,1,0,0,2};
 
template<class Cmp>
int LIS (Cmp cmp)
{
    static int m, end[N];
    m = 0;
    for (int i=0;i<n;i++)
    {
        int pos = lower_bound(end, end+m, a[i], cmp)-end;
        end[pos] = a[i], m += pos==m;
    }
    return m;
}
bool greater1(int value)
{
    return value >=1;
}
 
int main ()
{
    cout << LIS(less<int>()) << endl;         //严格上升
    cout << LIS(less_equal<int>()) << endl;   //非严格上升
    cout << LIS(greater<int>()) << endl;      //严格下降
    cout << LIS(greater_equal<int>()) << endl;//非严格下降
    cout << count_if(a,a+7,greater1) << endl; //计数
    //第二个参数为末尾元素的下一个位置
    return 0;
}
 
//OUT：
//3 5 2 4 3

