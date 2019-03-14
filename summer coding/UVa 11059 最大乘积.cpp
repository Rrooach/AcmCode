#include <iostream>;
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
	int n;
	while (cin>>n)
	{
		if (n==0) break;
		int data[n]={0};
		for (int i=0;i<n;i++) cin>>data[i];
		long long max,t=0,neg=0,pos=0;		//neg->负数 pos->正数 
		for (int i=0,m=i+1;m<n;m++,i++)
		{
			 if (data[i]==0) neg=pos=0;
			 else if (data[i]>0)
			 {
			 	pos*=data[i];
			 	neg*=data[i];
			 	if (pos==0) pos=data [i];
			 }
			 else if (data[i]<0)
			 {
			 	neg=pos*data[i];
			 	pos=neg*data[i];
			 	if (neg==0) pos=data [i];
			 }
			 if (max<pos&&data[i]) max=pos;
		}
		cout<<max<<"\n";
	}
	
	return 0;
}
