#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 300000+10;
map<LL,int> ma;//�洢����
LL sum[MAXN];
int n,m,a,b;
LL cal_xor(LL a,LL b)
{
	return a^b;
}
int main()
{
	int Case=0;
	LL s;
	char c;
	LL goal;
	while(~scanf("%d%d%d%d",&n,&m,&a,&b))
	{
		ma.clear();
		LL ans=0;
		sum[0]=0;
		memset(sum,0,sizeof(sum));
		goal = (LL)pow(2.0,(double)n)-1;
		getchar();
		for(int i = 1;i <= m;++ i)
		{
			c=getchar();
			s=c-'0';
			cout <<"#"<< s << endl;
			for(int j = 1;j < n&&(c=getchar());++ j)
			{
				s<<=1;
				s+=c-'0';
				cout <<"##"<< s << endl;
			}
			getchar();
/*			sum[i]=cal_xor(sum[i-1],s);
			if(i>=a)//�ڹ涨�����ڣ�ȫ�����
				ma[sum[i-a]]++;
			if(i>b)//һ�������涨���Ⱦ�ɾ��ǰ��ı��
				ma[sum[i-b-1]]--;
			if(i>=a)//��ÿ����goal��sum[i]��򣩵õ���״ֵ̬��ǰ���Ƿ񱻱��
				ans+=ma[cal_xor(goal,sum[i])];*/
		}
		printf("Case %d: %lld\n",++Case,ans);
	}
}

