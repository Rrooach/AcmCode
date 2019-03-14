#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int main ()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	a--,b--,c--,d--;
	char t[N][N];
	
	for (int i = 0; i < 25; ++i)
		for (int j = 0; j < 25; ++j)
			t[i][j] = 'A';
	for (int i = 25; i < 50; ++i)
		for (int j = 0; j < 25; ++j)
			t[i][j] = 'C';
	for (int i = 0; i < 25; ++i)
		for (int j = 25; j < 50; ++j)
			t[i][j] = 'B';
	for (int i = 25; i < 50; ++i)
		for (int j = 25; j < 50; ++j)
			t[i][j] = 'D';
		
	for (int i = 0;i<25; i+=2)
	{
		for (int j = 0;j<25;j+=2)
		{
			if (d--)
			{
				t[i][j] = 'D';
			}
			else break;
		}
		if (d==-1) break;
	}	
	
	for (int i = 0;i<25; i+=2)
	{
		for (int j = 25;j<50;j+=2)
		{
			if (c--)
			{
				t[i][j] = 'C';
			}
			else break;
		}
		if (c==-1) break;
	}	
	
	for (int i = 25;i<50; i+=2)
	{
		for (int j = 0;j<25;j+=2)
		{
			if (b--)
			{
				t[i][j] = 'B';
			}
			else break;
		}
		if (b==-1) break;
	}	
	
	for (int i = 25;i<50; i+=2)
	{
		for (int j = 25;j<50;j+=2)
		{
			if (a--)
			{
				t[i][j] = 'A';
			}
			else break;
		}
		if (a==-1) break;
	}	
	cout <<"50 "<<"50\n";
	for (int i = 0;i<50 ; ++i)
	{
		for (int j = 0;j<50; ++j)
			cout << t[i][j];
		cout << endl;
	}
	
	return 0;
 } 
