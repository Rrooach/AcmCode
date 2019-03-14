#include <iostream>
#include <cstring>
#include <cmath>
#define N 35

using namespace std;

int n;
double v[N],t; 

double solve ()
{
	if (fabs(1-t)<1e-9)
		return v[n];
	double ans=v[n];
	for (int i=n-1;i>=0;i--)
	{
		double f=v[i]/ans;
		if (f <= t)  
            ans  = (1 + t) / 2 * ans;  
        else  
            ans = (f - t) / (1 - t) * v[i] + (1 - f) / (1 - t) * (1 + f) / 2 * ans;  
	}
	return ans;
}

int main()
{
	v[0]=1;
	for (int i=0;i<=30;i++)
		v[i]=v[i-1]*2;
	while (cin>>n>>t)
	{
		cout<<solve();
	}
	cout<<endl;
	return 0;
}
