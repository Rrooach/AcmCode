#include <bits/stdc++.h>
#define long long ll
using namespace std;
int Maxn = 100050;
bool cmp (char a, char b)
{
    return a > b;
}

int main()
{
    string a;
    cin >> a;
    int len = a.length();
    while(1)
    {
        int Min, Max;
        sort(a.begin(), a.end());  
        Min  = stoi(a);
        sort(a.begin(), a.end(), cmp);
        Max = stoi(a);
        int n = Max - Min;
        printf("%04d - %04d = %04d\n", Max, Min, n);
        if (n == 0 || n == 6174)
            break;
        else
            a = to_string(n);
        
    }

    system("pause");
    return 0  ;
}