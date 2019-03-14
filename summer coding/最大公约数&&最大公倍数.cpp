#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	int a,b;
	cin>>a>>b;
	int c;
	c=gcd(a,b);
	int d=a/c*b;
	cout<<"最大公倍数为："<<d<<"\n"; 
	cout<<"最大公约数为："<<c<<endl; 
 } 
