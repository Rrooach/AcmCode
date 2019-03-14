#include<iostream>  
#include<cstdio>  
#include<string>  
#include<algorithm>  
#define MAXN 50  
using namespace std;  
  
int n, A[MAXN] = {1}, ispe[MAXN], vis[MAXN];  
  
void dfs(int cur) {  
    if(cur == n&& ispe[A[0] + A[n - 1]]) {  
        for(int i = 0; i < n; i++) {  
            i ? printf(" %d", A[i]) : printf("%d", A[i]);  
        }  
        printf("\n");  
    } else for(int i = 2; i <= n; i++) {  
        if(!vis[i]&& ispe[i + A[cur - 1]]) {  
            A[cur] = i;  
            vis[i] = 1;  
            dfs(cur + 1);  
            vis[i] = 0;  
        }  
    }  
}  
int main() 
{  
    for(int i = 2; i <= 50; i++)  
        ispe[i] = 1;  
    for(int i = 1; i <= 50; i++)  cout<<ispe[i];
	cout<<"\n";
    for(int i = 2; i <= 50; i++)  
        for(int j = i + i; j + i <= 50; j += i)  
            ispe[j] = 0;  
	for(int i = 1; i <= 50; i++)  cout<<ispe[i];
/* 
    int kase = 0;  
    while(cin >> n) {  
        if(kase++)  
            printf("\n");  
        printf("Case %d:\n", kase);  
        dfs(1);  
         
    }  */
    return 0;  
}  
