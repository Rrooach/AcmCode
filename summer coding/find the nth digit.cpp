#include<iostream>  

using namespace std;  

int main()  
{  
    int k,n,i,s,m,a[9]={9,1,2,3,4,5,6,7,8};  
    while(scanf("%d",&k)!=EOF)  
    {  
        while(k--)  
        {  
            scanf("%d",&n);  
            s=0;  
            for(i=1;s<n;i++)  
                s+=i;  
            s=s-i;  
            m=n-s-1;  
            printf("%d\n",a[m%9]);  
        }  
    }  
    return 0;  
}  
