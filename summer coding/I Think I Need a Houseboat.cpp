#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#define pi 3.1415926

using namespace std;

int main()
{
    int n,k;
    double x,y;
    double s;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x>>y;
 	    s=(x*x+y*y)*pi/100;
        k=(int)(s+1);
        cout<<"Property " <<i<< ": This property will begin eroding in year "<<k<<".\n";
    }
    cout<<"END OF OUTPUT.\n";
    return 0;
 }
 
 /*
2 
1.0 1.0 
25.0 0.0 
*/
