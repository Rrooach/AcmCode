#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define N 10000

using namespace std;

int i=1;
void move (int n,char from,char to)
{
	cout<<"第"<<i++<<"步:将"<<n<<"号盘子"<<from<<"---->"<<to<<"\n"; 
}

void hanoi(int n,char from,char depend_on,char to)
{
	if (n==1) move (1,from,to);
	else 
	{
		hanoi(n-1,from,to,depend_on);
		move (n,from,to);
		hanoi(n-1,depend_on,from,to);
	}
}

int main()
{
	int n;
	cin>>n;
	char x='A',y='B',z='C';
	hanoi(n,x,y,z);
	return 0;
 } 
