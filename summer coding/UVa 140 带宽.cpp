#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

const int N =10, inf=0x7fffffff;
//***********���������Ǹ�ʲô�� 
char letter [N],s[N];	//��ĸ����������
int id[256];	//��ĸ�ı�� 
int p[N];	 //ȫ���еı������飬�洢��ÿ����ĸ�ı�� 
int pos[N];		// ��¼ÿ����ĸ��λ�ã�����Ƶ��ʹ��strchr

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
