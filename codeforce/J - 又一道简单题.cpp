#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,cnt = 1;
	cin >> t;
	while (t--)
	{
		int ans = 0;
		cin >> n;
		int op[] = {0,n/1000,n/100%10,n/10%10,n%10};
		int num;
		for (int i = 1; i <= 4; ++i)
		{
			int temp = op[i];
			for (int j = 0; j <= 9; ++j)
			{
				if (i == 1 && j == 0) continue;
				if (j != temp) 
				{
					op[i] = j;
					int a = 1;
					num = 0;
					for (int k = 4; k >=1; --k)
					{
						num += op[k]*a;
						a*=10;
					}
					if ((int)sqrt(num)*sqrt(num) == num)
						ans ++;
				}
			}
			op[i] = temp;
		} 
		 printf("Case %d: %d\n",cnt++,ans);
		
	}
	
	return 0;
 } 
