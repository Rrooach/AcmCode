#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main ()
{
	int l,r,x,y;
	cin >> l >> r >> x>>y;
	int num = y/x;
	int ans = 0;
	if (y%x != 0) 
	{
		cout << "0\n" << endl;ret
	}
	for (int i = 1; i*i <=num ;++i)
	{
		int j = num /i;
		if (gcd(i,j) == 1 && num % i==0&&l<=i*x&&i*x<=r&&l<=j*x&&j*x<=r) ans += i==j?1:2 ;
	}	
	cout << ans << endl;
 	return 0;
 } 
