#include <bits/stdc++.h>

using namespace std;

const int N = 15;

struct node{
	int teamID;
	char proID;
	int time;
}pro[N];
int vis[20][105];
int main()
{
	memset(vis,0,sizeof(vis));
	int n,t,m;
	cin >> n >> t >> m;
	for (int i = 0; i < n; ++i)
		pro[i].proID = 'A' + i;
	int time,teamID;
	string proID;
	char res[3];
	for (int i = 0; i < m; ++i)
	{
		cin >> time >> teamID;
		cin >> proID;
		cin >> res;
		int temp = proID[0]-'A';
		if (!vis[temp][teamID]&&pro[temp].time <= time && !strcmp(res,"Yes")) 
		{		
			vis[temp][teamID] = 1;
			pro[temp].teamID = teamID;
			pro[temp].time = time;
		}
	}
	for (int i = 0; i < n ; ++i)
	{
		if (pro[i].time == 0) 
			cout << pro[i].proID <<" "<<"-"<<" "<<"-"<<endl;
		else
			cout << pro[i].proID<<" "<<pro[i].time<<" "<<pro[i].teamID<<endl;
	}
	return 0;
}
