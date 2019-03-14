#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 1000

using namespace std;

int m,n,cnt=0;
char s[N];

dfs(int cur)
{
	if (cnt++==n)
	{
		for (int i=0;i<cur;i++)	cout<<'A'+s[i];
		cout<<"\n";
		return 0;
	}
	for (int i=0;i<m;i++)
	{
	 	s[cur]=i;
	 	
	 	int ok=1;
	 	for(int j=1;j*2<=cur +1;j++)
	 	{
	 		int equal=1;
	 		for (int k=0;k<j;k++)
	 			if ((s[cur-k])!=s[cur-k-j])
	 				if (equal) 
					 {
					 	ok=0;
					 	break;
					 }
			if (ok) if(!dfs(cur+1)) return 0;
		 }
	}
}

int main()
{
	while (cin>>m,n)
	{
		if (m==0||n==0) break;
		memset(s,0,sizeof (s));
		dfs(0);		
	}
	return 0;
}

/*
sample input:
7 3
30 3
sample output:
ABACABA
ABACABCACBABCABACABCACBACABA
*/
