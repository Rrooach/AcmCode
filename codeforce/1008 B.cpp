#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

vector <pair<int, int> > mmp;

int main()
{
	int c;
	cin >> c;
	int m,n;
	for (int i = 0; i < c; ++i) 
	{
		cin >> m >> n;
		mmp.push_back(make_pair(m,n));
	}
	int flag = 0;
	int de;
	int h = max(mmp[0].first,mmp[0].second);
	for (int i = 1; i < c; ++i)
	{
		if (h >= mmp[i].first && h >= mmp[i].second)
			h = max(mmp[i].first,mmp[i].second);
		if (h >= mmp[i].first && h < mmp[i].second)
			h = mmp[i].first;
		if (h < mmp[i].first && h >= mmp[i].second)
			h = mmp[i].second;
		if (h < mmp[i].first && h < mmp[i].second)
			flag = 1;
	}
	if (flag == 1) cout <<"NO\n";
	else cout << "YES\n";
	
	return 0;
 } 
