#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int N=100+5;
char pic[N][N];
int m,n;
int idx[N][N];

void dfs (int r,int c,int id)
{
	if (r<0||r>=m||c<0||c>=n) return;	 //����Ƿ���� 
	if (idx[r][c]>0||pic [r][c]!='@') return;	//����Ƿ��Ѿ����� 
	idx[r][c]=id;	//��ͬ�������б��**
	//*********ע���������е��߼���ϵ 
	//���������ĸ������������  ��һ����ͨͼ��ֱ�ӱ����� 
	for (int dr=-1;dr<=1;dr++)
		for (int dc=-1;dc<=1;dc++)
			if (dr!=0||dc!=0) dfs(r+dr,c+dc,id);
}
int main()
{
	while (scanf("%d%d",&m,&n)==2&&m&&n)
	{
		
		for (int i=0;i<m;i++) scanf("%s",pic[i]);
			memset (idx ,0,sizeof (idx));
		int cnt=0;
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
				if (idx[i][j]==0&&pic[i][j]=='@') dfs(i,j,++cnt);
		printf("%d\n",cnt); 
	}

	
	
	return 0;
}

/*
sample input :
****@
*@@*@
*@**@
@@@*@
@@**@

sample output :
2
*/ 
