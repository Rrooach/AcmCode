#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define N 1000 

using namespace std;

int seq[N];
int seqlen[N];

int main()
{
	int n;
	int max,maxlen;
	cin>>n;
	for (int i=0;i<n;i++)	cin>>seq[i];
	for (int i=0;i<9;i++)	seqlen[i]=1;
	for (int i=0;i<n;i++)
	{
		max=0;
		for (int j=0;j<n;j++) 
			//在前i-1个序列中，寻找以终点小于seq[i]的最长的子序列，即最优子状态  
			if (seq[j]<seq[i]&&seqlen[j]>max)	max=seqlen[j]; 
		seqlen[i]=max+1; 
		//seqlen中保存的是第i个数为终点的最长上升序列，找出这个数组中最大的值即为最优序列长度  
		if (seqlen[i]>maxlen) maxlen=seqlen[i];
	}
	cout<<maxlen<<endl;
	return 0;
}
/*
sample input
5
1 3 2 4 5
sample output:
4
*/
