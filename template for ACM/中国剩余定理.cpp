#include<cstdio>
#define ll long long
//��չŷ������㷨 
void gcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(b==0){
        d=a;
        x=1,y=0;
    }
    else{//else����ʡ�� 
        gcd(b,a%b,d,y,x);
        y-=(a/b)*x;
    }
}
//�й�ʣ�ඨ�� 
ll China(int n,ll *m,ll *a)
{
    ll M=1,d,y,x=0;
    for(int i=0;i<n;i++) M*=m[i];
    for(int i=0;i<n;i++){
        ll w=M/m[i];
        gcd(m[i],w,d,d,y);
        x=(x+y*w*a[i])%M;
    }
    return (x+M)%M;
}
ll m[15],a[15];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&m[i],&a[i]);
    printf("%lld",China(n,m,a));
} 
