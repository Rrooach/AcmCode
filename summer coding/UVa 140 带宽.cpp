#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

const int N =10, inf=0x7fffffff;
//***********输入序列是干什么的 
char letter [N],s[N];	//字母和输入序列
int id[256];	//字母的编号 
int p[N];	 //全排列的编序数组，存储是每个字母的编号 
int pos[N];		// 记录每个字母的位置，避免频繁使用strchr

int main()
{
	while (cin>>s&&s[0]!='#')
	{
		int len=strlen(s),n=0;
		for (char ch='A';ch<='z';ch++)
		{
			if (strchr(s,ch)!=NULL)
			{
				letter[n]=ch;
				id [ch]=n++;
			}
		}
		vector<int >u,v;
	//	for (int i=0;i<len;i++)
	 } 
	
	
	return 0;
}
