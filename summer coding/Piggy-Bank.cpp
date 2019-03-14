#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm> 

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int e,f,n,p[50001],w[10001],temp[10001];
        cin>>e>>f;
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>p[i]>>w[i];
        for(int i=1;i<=f-e;++i)
            temp[i]=INT_MAX;
        temp[0]=0;
        for(int i=1;i<=n;++i)
            for(int j=w[i];j<=f-e;++j)
                if(temp[j-w[i]]!=INT_MAX)
                    if(temp[j-w[i]]+p[i]<temp[j])
                        temp[j]=temp[j-w[i]]+p[i];
        if(temp[f-e]<INT_MAX)
            cout<<"The minimum amount of money in the piggy-bank is "<<temp[f-e]<<"."<<endl;
        else
            cout<<"This is impossible."<<endl;
    }
    return 0;
}
