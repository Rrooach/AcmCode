#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

void print_subset(int n,int *A,int cur)
{
	for (int i=0;i<cur ;i++) cout<<A[i];
	cout<<"\n";
	int s=cur?A[cur-1]+1:0;
	for (int i=s;i<n;i++)
	{
		A[cur]=i;
		print_subset(n,A,cur+1);
	}
}
int main()
{
	int n,cur;
	cur=0;
	cin>>n;
	int A[n];
	print_subset(n,A,0); 
	return 0;
 } 
