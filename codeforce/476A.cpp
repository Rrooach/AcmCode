#include<bits/stdc++.h>

using namespace std;

int a[100010];
long long sum[100010];

int main(){
	int w,l;
	cin>>w>>l;
	for(int i=1;i<=w-1;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=sum[w-1];
	for(int i=l;i<=w-1;i++){
		ans=min(ans,sum[i]-sum[i-l]);
	}
	cout<<ans;
	return 0; 
		
}
