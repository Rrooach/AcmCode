#include <vector>
#include <iostream> 
#include <algorithm>
#define N 1000

using namespace std;
int main()
{
	int m,n ;
	cin.tie(0);
	while (cin>>m>>n)
	{
		if(0==m) break;
		vector<int>list(m);
		for (int i=0;i<m;i++)
			cin>>list[i]; 
		sort(list.begin(),list.end());
		cout<<list[0];
		for (int i=n;i<m;i+=n)
		cout<<" "<<list[i]; 
		cout<<"\n";
	}
	return 0;
 } 
