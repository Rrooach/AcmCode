#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
string s[N];
ll a[N],b[N];
map<string,ll> M;
int main()
{
    int n,k,m,x;
    ll ans=0;
    cin>>n>>k>>m;
    for(int i=1; i<=n; i++)
        cin>>s[i];
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1,x; i<=k; i++)
    {
        cin>>x;
        ll mi=INF;
        for(int j=1; j<=x; j++)
        {
            cin>>b[j];
            mi=min(mi,a[b[j]]);
        }
        for(int j=1; j<=x; j++)
            M[s[b[j]]]=mi;
    }
    string c;
    for(int i=1; i<=m; i++)
        cin>>c,ans+=M[c];
    cout<<ans;
    return 0;
}
