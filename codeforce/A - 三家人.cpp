#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		double temp = (x+y)/3.0;
		double x1 = x - temp,y1 = y - temp;
		double p;
		p = x1/(x1+y1)*z;
		printf("%.0lf\n",p);	
	}
	
	
	return 0;
 } 
