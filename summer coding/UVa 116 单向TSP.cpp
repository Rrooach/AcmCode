#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
#define INF 0x3f3f3f3f  
#define LL long long  
using namespace std;  
  
int mat[30][110], dp[30][110], path[30][110];  
int n, m;  
int main()  
{  
    while (~scanf("%d %d", &n, &m))
	{  
        for (int i = 1; i <= n; i++)  
            for (int j = 1; j <= m; j++) scanf("%d", mat[i]+j);  
        memset(dp, INF, sizeof(dp));  
        for (int i = 1; i <= n; i++) dp[i][m] = mat[i][m];  
        for (int j = m; j > 1; j--)
		{  
            for (int i = 1; i <= n; i++)
			{  
                int row[3] = {i-1, i, i+1};  
                if (i == 1) row[0] = n;  
                if (i == n) row[2] = 1;  
                sort(row, row+3);  
                for (int x = 0; x < 3; x++)
				{  
                    int tmp = dp[i][j]+mat[row[x]][j-1];  
                    if (tmp < dp[row[x]][j-1])
					{  
                        dp[row[x]][j-1] = tmp;  
                        path[row[x]][j-1] = i;  
                    }  
                }  
            }  
        }  
        int cost = INF, r;  
        for (int i = 1; i <= n; i++)  
            if (cost > dp[i][1]) r = i, cost = dp[i][1];  
        printf("%d", r);  
        for(int i = path[r][1], j = 1; j < m; j++, i = path[i][j]) printf(" %d", i);  
        printf("\n%d\n", cost);  
    }  
    return 0;  
}  

/*
 Sample Input:
5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 8 6 4
5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 1 2 3
2 2
9 10 9 10

Sample Output:
1 2 3 4 4 5
16
1 2 1 5 4 5
11
1 1
19
*/
