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
	for(;;)
	{
		int n;
		int max,maxlen=0;
		cin>>n;
		if (n==0) break;
		for (int i=0;i<n;i++)	cin>>seq[i];
		for (int i=0;i<n;i++)	seqlen[i]=0;
		for (int i=0;i<n;i++)
		{
			max=0;
			for (int j=0;j<n;j++) 
	 			if (seq[j]<seq[i]&&seqlen[j]>max)	max=seqlen[j]; 
			seqlen[i]=max+seq[i]; 
	 		if (seqlen[i]>maxlen) maxlen=seqlen[i];
		}
		cout<<maxlen<<endl;
	}
	
	return 0;
}
