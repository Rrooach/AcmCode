#include <bits/stdc++.h>

using namespace std;

const int N = 10000;



int main ()
{
	string s;
	cin >> s;
	int ans = 0;
	int m = s.length();
	int a[m];
	for (int i = 0; i < m; ++i)
		a[i] = s[i] - '0';
		
	for (int i = 0; i < m; ++i)
	{
		
		if (!(a[i] % 3))
		{
//			cout << "1:a[i]= "<< a[i]<<endl;
			ans ++;
			continue;
		}
			
		if (i < (m - 1)&&!((a[i] + a[i+1]) % 3)&&(a[i + 1] != 0)&&(a[i + 1] != 3)&&(a[i + 1] != 6)&&(a[i + 1] != 9))
		{
//			cout << "2:a[i]= "<<(a[i]*10 + a[i+1])<<endl;
			ans ++;
			i ++; 
			continue;
		}
//		cout << "3:a[i]= "<<(a[i]*100 + a[i+1]*10 + a[i+2])<<endl;
		if (i < (m - 2)&&!((a[i] + a[i+1] + a[i+2]) % 3)&&(a[i + 1] != 0)&&(a[i + 1] != 3)&&(a[i + 1] != 6)&&(a[i + 1] != 9)
		&&(a[i + 2] != 0)&&(a[i + 2] != 3)&&(a[i + 2] != 6)&&(a[i + 2] != 9))
		{
			ans ++;
			i += 2;
			continue;
		}
	}	
	
	cout << ans <<endl;
	return 0;
} 

/*

44084

*/

