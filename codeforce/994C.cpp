#include <bits/stdc++.h>

using namespace std;


struct node {
	int x,y;
}a[5],b[5];

int d1;
int d2;
int midx,midy;
int c[220][220];

int isIN(int x,int y,int d1,int d2)
{
	return abs ((x-midx)*d1/2) +abs((y-midy)*d2/2) - (d1*d2)/4;
}

bool dry(int x,int y)
{
	if (isIN(x,y,d1,d2) <= 0)
		return true;
	else
		return false;
}

int main ()
{
	
	int minxB = 101010, minyB = 101010;
	int maxxB = -101010, maxyB = -101010;
	
	int minxA = 101010, minyA = 101010;
	int maxxA = -101010, maxyA = -101010;
	
	for (int i = 0;i < 4; ++i)
	{
		cin >> a[i].x >> a[i].y;
		if (a[i].x < minxA) minxA = a[i].x;
		if (a[i].x > maxxA) maxxA = a[i].x;
		if (a[i].y < minyA) minyA = a[i].y;
		if (a[i].y > maxyA) maxyA = a[i].y;
	}	
	for (int i = 0;i < 4; ++i)
	{
		cin >> b[i].x >> b[i].y;
		if (b[i].x < minxB) minxB = b[i].x;
		if (b[i].x > maxxB) maxxB = b[i].x;
		if (b[i].y < minyB) minyB = b[i].y;
		if (b[i].y > maxyB) maxyB = b[i].y;
	}
	d1 = maxxB-minxB;
	d2 = maxyB-minyB;
	midx = (maxxB+minxB)/2;
	midy = (maxyB+minyB)/2;
//	cout <<d1 << ends << d2 <<endl;
	for (int i = minxB; i <= maxxB; ++i)
	{
		for (int j = maxyB; j >= minyB; --j)
		{
			if (dry(i,j)) 
			{
				c[i][j] = 1;
			}
			
		//	cout <<i <<ends<<j<<endl;
		}
	}
	
/*	for (int i = 0 ; i < 50 ;++i)
	{
		for (int j =0;j < 50; ++j)
		{
			cout << c[i][j];
		}
		cout << "\n";
	}
*/	
	int f1 = maxxA - minxA;
	int f2 = maxyA - minyA;
	int flag = 0;
	for(int i = minxA; i <= maxxA; ++i)
	{
		for (int j = maxyA; j >= minyB; --j)
		{
			if (c[i][j]) flag = 1;
		}
	}
	if (flag) cout <<"YES\n";
	else cout <<"NO\n";
	return 0;
 } 
