#include <bits/stdc++.h>

using namespace std;
const int N=1e5;

int main()
{
    int x,y;
    cin >> y >> x;
    if(x==1 && y>0 || x==0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    int c = x-1;
    y -= c;
    if(y>=0 && y%2==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
