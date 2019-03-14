#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstring>
#define maxn 1000

using namespace std;
int sum[maxn];

void build (int p)
{
	int v; cin>>v;
	if(v==-1) return ;
	sum[p]+=v;
	build(p-1); build (p+1);
}
bool init ()
{
	int v;
	cin>>v;
	if (v==-1 ) return false;
	memset (sum,0,sizeof(sum));
	int pos=maxn/2;
	sum[pos]=v;
	build(pos-1); build (pos+1);
	return true;
}

int main()
{
	int kase=0;
	while (init())
	{
		int p=0;
		while (sum[p]==0) p++;
		cout<<"Case"<<++kase<<":\n"<<sum[p++];
		while (sum[p]!=0) cout<<" "<<sum[p++];
		cout <<"\n\n";
	}
	
	return 0;
}
/*5 7 -1 6 -1 -1 3 -1 -1
  8 2 9 -1 -1 6 5 -1 -1 12 -1 -1 3 7 -1 -1 -1 
  */
