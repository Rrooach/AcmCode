#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define N 10000

using namespace std;

int n;
//int c[N];
int c[N][N];

int main()
{
	cin>>n;
	memset (c,0,sizeof (c));
	for (int i=0;i<n;i++)
		for (int j=0;j<=n;j++)
			j==n?cout<<"\n":cout <<c[i][j]<<" ";
	for (int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for (int j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	cout<<"\n";
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			j==n?cout<<"\n":cout <<c[i][j]<<" ";
			
	/*
	for (int i=1;i<=n;i++)
		c[i]=c[i-1]*(n-i+1)/i;
	for (int i=1;i<=n;i++)
		cout<<c[i]<<" ";
		*/
	return 0;
 } 
