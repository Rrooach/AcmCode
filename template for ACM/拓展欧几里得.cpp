#include<bits/stdc++.h>
using namespace std;

int exgcd(int a,int b,int &x,int &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    int q=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return q;
}

int main()
{
	

	
	return 0;
 } 
