#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void gcd(int a,int b,int& d,int& x,int& y)
{
	if (!b) 	//b=0 Ϊ������״̬ 
		d=a,x=1,y=0;
	else 
		gcd(b,a%b,d,y,x),y-=x*(a/b);
}

int main()
{
	
	
	
	return 0;
 } 

/*
��չŷ������㷨��������� 
http://blog.csdn.net/zhjchengfeng5/article/details/7786595  

*/ 
