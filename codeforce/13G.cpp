#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int a[N];
int c[N];
int ans;
void solve(int c[],int j,int a[],int n)
{
	int x = 0;
	int flag = 1;
	if (j == 0) 
		return;
	if (j == 1) 
	{
		ans ++;
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == c[x])
		{
			for (int t = 0; t < j; ++t)
			{
				if (a[i++] != c[x++])
				{
					return;
				}
			}
		}
	}
	sort (c,c+j);

	int d = c[1]-c[0];
	for (int i = 1; i < j; ++i)
	{
		if ((c[i] - c[i-1]) != d)
		{
			flag = 0;
			break;
		}
	}
	if (flag) ans ++;
	return;
}

void get_allsubset(int a[],int n)
{
	ans = 0;
	int mask=0;
	int start=0;
	int end=(1<<n)-1;
	int i=0;
	bool isnull;
	for(mask=start;mask<=end;mask++)
	{
		int j = 0;
	    isnull=1;
	    for(i=0;i<n;i++)
			if((1<<i)&mask)
			{
			    isnull=0;
			    //cout<<a[i]<<" ";
				c[j++] = a[i];
			}
	    solve(c,j,a,n);
    }
    printf("%d\n",ans);
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for (int i = 0;i < n; ++i)
		scanf ("%d",&a[i]);
		get_allsubset(a,n);
	}
	
	
	return 0;
}
