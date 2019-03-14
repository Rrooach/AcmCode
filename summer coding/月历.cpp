#include<stdio.h>
int year,month;
int sbsyh(int a,int b)//定义一个傻逼沈煜恒函数 
{
	int i=1,n=0,m=1;
	while(i<a)
	{
		if(i%100!=0)
		{
			if(i%4==0)
			{
				n=n+366;
			}
			else
			{
				n=n+365;
			}
		}
		else
		{
			if(i%400==0)
			{
				n=n+366;
			}
			else
			{
				n=n+365;
			}
		}
		i++;
	}
	while(m<b)
	{
		if(m==2)
		{
			if(i%100!=0)
			{
				if(i%4==0)
				{
					n=n+29;
				}
				else
				{
					n=n+28;
				}
			}
			else
			{
				if(i%400==0)
				{
					n=n+29;
				}
				else
				{
					n=n+28;
				}
			}
		}
		if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
		{
			n=n+31;
		}
		else if(m!=2)
		{
			n=n+30;
		}
		m++;
	}
	return(n);
	
}
void yue(int n)
{
	if((n=n+1)==7)n=0;
	int i=n,d,j=1;
	printf("year:%d month:%d\n",year,month);
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	while(i--)printf("    ");
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)d=31;
	else if(month==2){
	if(i%100!=0)
		{
			if(i%4==0)d=29;
			else d=28;
		}
		else
		{
			if(i%400==0) d=29;
			else d=28;
		}
	}
	else d=30;
	while(j<=d)
	{
		
		printf("%-4d",j);
		n++;
		if(n==7){
		printf("\n");
		n=0;
		}
		j++;
	}
	if(n!=0)printf("\n");
}
int main()
{
	int u,time1=0;
	long int s;
	scanf("%d",&u);
	while(u--)
	{
		scanf("%d %d",&year,&month);
		s=sbsyh(year,month);	
		s=(s)%7;
		yue(s);
	}
}
