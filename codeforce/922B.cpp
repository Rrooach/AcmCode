#include <bits/stdc++.h>

using namespace std;
const int N=1e5;

int main()
{
    int n;
    int sum = 0;
    cin >> n;
    for (int i = 1;i <= n; ++i)
    {
    	for (int j = i; j <=n; ++j)
    	{
    		int a = i ^ j;
    		if (a>=j && a<=n && i+j>a && a-j<i)
    			sum ++;
		}
	}
	cout<< sum << endl;
    return 0;
}
