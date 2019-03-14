#include <stdio.h>

int main()
{
	long long n;
	while (scanf("%lld",&n)==1)
	{
		long long p=1;
		while (p)
		{
			p*=9;
			if (p>=n)
			{
				printf("Nic wins.\n");
	
				break;
			}
			p*=2;
			if (p>=n)
			{
				printf ("Susan wins.\n");
				break;
			}
		}
		
	}
	
	
	return 0;
}
