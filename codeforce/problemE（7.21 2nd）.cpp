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
        vis[maxn + cnt] ++; // ��ǰָ�� maxn + cnt ָ���ǣ���m���ֵ�ͱ�mС��ֵ�Ĳͨ�׵Ľ����������ڻ��� -cnt �����Դյ�0 
  		cout <<"cnt = "<< cnt <<" maxn + cnt = " <<maxn + cnt<<" vis [maxn + cnt] = "<< vis[maxn + cnt]<<endl;
    }
    cnt = 0;
    long long ans = 0;
    for(int i = pos ; i >= 0 ; i--)
    {
        if(a[i] < m) cnt ++;
        if(a[i] > m) cnt --;
        ans += vis[maxn + cnt]; // ������� �������Ѿ��յ� cnt���ˣ���ô����ֵ����0�����Ǿ���vis[cnt]�������� 
        ans += vis[maxn + cnt + 1]; // ��ϸ������ǵ����䳤����ż����ʱ�� ����ȡ���������λ 

    }
    cout<<ans<<endl;
}
