#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void gcd(int a,int b,int& d,int& x,int& y)
{
	if (!b) 	//b=0 为其最终状态 
		d=a,x=1,y=0;
	else 
		gcd(b,a%b,d,y,x),y-=x*(a/b);
}

int main()
{
	
	
	
	return 0;
 } 

/*
扩展欧几里得算法详解与例题 
http://blog.csdn.net/zhjchengfeng5/article/details/7786595  

*/ 
