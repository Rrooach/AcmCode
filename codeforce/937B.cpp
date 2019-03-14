#include<bits/stdc++.h>

using namespace std;

int main ()
{
	int p,y;
	cin >> p >> y;
	int ans = 0;
	while (y > p)
	{
		int flag = 0;
		for (int i = 2; i <= sqrt(y); ++i)
		{
			if (y % i == 0 && i <= p)
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			ans = y;
			break;
		}
		y --;
	}
	if (ans) cout << ans <<endl;
	else cout << "-1\n";
	
	
	return 0;
 } 
