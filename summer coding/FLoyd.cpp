#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define INF 1000000
#define N 111111
#include <queue>
#include <vector>

using namespace std;

int w[N][N];
int d[N][N];
int n;

int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin>>w[i][j];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			d[i][j]=i==j?0:INF;
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			if (d[i][j]<INF&&d[k][j]<INF)
				d[i][j]=d[i][j]<d[i][k]+d[k][j]?d[i][j]:d[i][k]+d[k][j];	
	for (int i==0;i<n;i++) 
	{
		for (int j=0;j<n;j++)
	 	{
	 		cout<<w[i][j]<<" ";
	 		
		}
		cout<<"\n";
	}
	/*
	所得矩阵的每个值就是从i到j所需的最短路径
	*/ 
	return 0;
}
