#include <bits/stdc++.h>
#define ll long long  
using namespace std;
ll mod=1e9+7;
int a[100100],b[100100];


void gcd(ll a,ll b,ll& d,ll& x,ll& y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}else {
		gcd(b,a %b,d,y,x);
		y-=x*(a/b);
	}
}
ll inv(ll a,ll n){
	ll d,x,y;
	gcd(a,n,d,x,y);
	return d==1 ? (x+n) % n : -1;
} 
int main () {
	ll n,m;
	cin>>n>>m;
	ll num=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=0 && b[i]!=0){
			if(a[i]>b[i])
			{
				ans+=num%mod;
				break;
			}
			if(a[i]==b[i])
				continue;
			if(a[i]<b[i])
				break;
		}else if(a[i]==0 && b[i]!=0){
			ans+=(m-b[i])*num%mod*inv(m,mod)%mod;
			ans%=mod;
			num=num*inv(m,mod)%mod;
		}else if(a[i]!=0 && b[i]==0){
			ans+=(a[i]-1)*num%mod*inv(m,mod)%mod;
			ans%=mod;
			num=num*inv(m,mod)%mod;
		}else{
			ans+=(m-1)*num%mod*inv(m*2ll,mod)%mod;
			ans%=mod;
			num=num*inv(m,mod)%mod;
		}
	}
	cout<<ans%mod;
	return 0;
}
