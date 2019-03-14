#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	double n;
	while (cin>>n)
	{
		if (n==0) break;
		for (int i=n+1;i<=2*n;i++)
		{
			double t;
			t=(n*i)/(i-n);
			if ((int)t==t) cout<<t<<"    "<<i<<"\n";
		}
		
		
	}
	
	return 0;
 } 
