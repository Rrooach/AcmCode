//���ֻ���ʮ���й��ɵģ���ʵ����ͳ��2����1�ĸ����������Լ�̫���ˣ���Ȼû��������
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
