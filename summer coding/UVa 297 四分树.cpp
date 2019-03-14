#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <MEMORY>
#define N 1024+10 
using namespace std;

const int len =32;
 
char s[N];
int buf[len][len],cnt;

void  draw (char *s,int& p,int r,int c,int w)
{
	char ch =s[p++];
	if(ch=='p') 
	{
		draw (s,p,r,c+w/2,w/2);
		draw (s,p,r,c ,w/2);
		draw (s,p,r+w/2,c,w/2);
		draw (s,p,r+w/2,c+w/2,w/2);		
	}
	else if(ch=='f') 
	for(int i=r;i<r+w;i++)
		for(int j=c;j<c+w;j++)
			if(buf[i][j]==0 ) 
			{
				buf [i][j]=1;
				cnt++;
			} 
}

int main()
{
	int kase;
	scanf("%d",&kase);
	while (kase--)
	{
		memset (buf,0,sizeof(buf));
		cnt = 0; 
		for(int i=0;i<2;i++)
		{
			cin>>s;
		 	int p=0;
		 	draw (s,p,0,0,len);
		}
		printf("there are %d black pixels.\n",cnt);		
	}
	
	
	return 0;
}

/*
sample input :
3
ppeeefpffeefe
pefepeefe
peeef
peefe
peeef
peepefefe

sample output:
there are 640 black pixels.
there are 512 black pixels.
there are 384 black pixels.

*/
