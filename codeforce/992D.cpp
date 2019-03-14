#include <bits/stdc++.h>

using namespace std;

//const int N = 100005;

int main()
{
	int n,k;
	int cnt = 0;
	scanf("%d%d",&n,&k);
	int a[n],s[n],p[n];
	memset(s,0,sizeof(s));
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&a[i]);
		i == 1 ? s[i] = a[i] : s[i] = s[i-1] + a[i]; 
	}

	int j = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		int mul = 1;
		for (int j = i;j <= n; j++)
		{
			int presum = s[j] - s[i-1];
			mul *= a[j];
			
			if (mul/presum == k && !(mul%presum)) cnt ++;
//			cout << i <<ends<< j <<ends<<mul<<ends<< presum <<ends <<cnt<<endl;
		}
		
	}
	cout << cnt << endl;
	
	
	return 0;
 } 
