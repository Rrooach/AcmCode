#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#define N 10000

using namespace std;

int k;
char G[2][7][6];	//用一个三维的数组存储两个矩阵 
int vis[2][30],cnt[10],he[10];	//vis[][]表示是否访问，cnt是每一列的总数，he使后缀积 
char select[10][10],ans[10];	//select[i][j]表示第i行第j个字母被标识 

int main()
{
	int cases;
	cin>>cases;
	while (cases--)
	{
		cin>>k;
		//输入 
		for (int i=0;i<2;i++)
			for (int j=0;j<6;j++)
				scanf("%s",G[i][j]);
		memset (cnt,0,sizeof (cnt)); 
		for (int i=0;i<5;i++)
		{
			memset(vis,0,sizeof (vis));
			for (int j=0;j<5;j++) 
				for (int m=0;m<6;m++)
					vis[j][G[j][m][i]-'A']=1;
			for (int j=0;j<26;j++)
				if (vis[0][j]&&vis[1][j])
					select[i][++cnt[i]]='A'+j;
		}		
		he[5]=1;
		for (int i=4;i>=0;i--)
			he[i]=cnt[i]*he[i+1];
		for (int i=0;i<5;i++)
			cout<<cnt[i]<<" "<<he[i]<<"\n"; 
		if (k>he[0])
		{
			cout<<"NO\n";
			continue;
		}
		k--;
		for (int i=0;i<5;i++)
		{
			int t=k/he[i+1];
			ans[i]=select[i][t+1];
			k=k%he[i+1];
		}
		ans[5]='\0';
		cout<<ans<<"\n"; 
	 } 
	
	
	return 0;
}

/**
1
AYGSU
DOMRA
CPFAS
XBODG
WDYPK
PRXWO
CBOPT
DOSBG
GTRAR
APMMS
WSXNU
EFGHI

**/
