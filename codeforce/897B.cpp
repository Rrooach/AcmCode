#include <bits/stdc++.h>
using namespace std;

long long  a[1000000];
void init()
{
    int cnt=0;
    for(int i=1;i<=100000;i++)
    {
        long long temp=i;
        int p=i;
        while(p){
            temp=temp*10+p%10;
            p/=10;
        }
        a[++cnt]=temp;
    }
}

int main ()
{
	init();
	int k,p;
	cin >>k >> p;
	long long sum = 0;
	long long temp;
	
	for (int i = 1; i <= k; ++i)
	{
//		cout << a[i] << endl;
		sum += a[i];
		sum %= p;
	} 
	cout << sum << endl;
	return 0;
 } 
 //42147 412393322
