#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int array[15][15];

int init(int n)                                
{
    int i;
    int j;
	memset(array,0,sizeof(array[n+1][n+1]));
  //  for(i=0; i<=n+1; i++)
    //for(j=0; j<=n+1; j++)
      //  array[i][j] = 0;
    return 0;
}
 //           3      1      1      1 
int solve(int n, int x, int y, int num)      
{
    int i;	int j;	int k;
    i = y;
    j = n/2 + x;
    for(k=num; k<=num+n*n-1; k++){
        array[i][j] = k;
        if((k-num+1)%n == 0){           
            i = (i-y+1)%n+y;
        }
        else{                                
            i = (i-y-1+n)%n+y;
            j = (j-x+1)%n+x;
        }
    }
    return 0;
}

int main()
{
    int n;
    
    while (scanf("%d",&n)&&n)
    {
		init(n);
       	solve(n,1,1,1);
		printf("%d\n",array[n][n]);
	}
    

    return 0;
}
