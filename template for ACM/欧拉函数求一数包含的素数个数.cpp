#include <bits/stdc++.h>

using namespace std;

const int N=100005;

void phi_table(int n,int* phi)
{
    for(int i=2;i<=n;i++)
    {
        phi[i]=0;
    }
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!phi[i])
        {
            for(int j=i;j<=n;j+=i)
            {
                if(!phi[j]) phi[j]=j;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}
int main()
{
	int phi[N];
    phi_table(10000,phi);
    int n;
    while(scanf("%d",&n))
        printf("%d\n",phi[n]);
}

