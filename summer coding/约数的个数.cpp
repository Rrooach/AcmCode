#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define N 10000

using namespace std;

int n;

int main()
{
	int times;
	cin>>times;
	while (times--)
	{
		cin>>n;
		int r=(int)sqrt (1.0*n);
		int sum=0;
		if (r*r==n) sum++,r--;
		for (int i=1;i<=r;i++)
			if (n%i==0)
				sum+=2;
		cout<<sum<<"\n";
	}
	return 0;
}

