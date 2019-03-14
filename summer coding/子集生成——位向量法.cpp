#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

void print_subset(int n,int *B,int cur )
{
	if (cur == n)
	{
		for (int i=0;i<cur ;i++)
			if (B[i]) cout <<i;
		cout <<"\n";
		return;
	}
	B[cur]=1;
	print_subset(n,B,cur+1);
	B[cur]=0;
	print_subset(n,B,cur+1);
}

int main()
{
	int n;
	cin>>n;
	int B[n];
	print_subset(n,B,1);
	return 0;
}
