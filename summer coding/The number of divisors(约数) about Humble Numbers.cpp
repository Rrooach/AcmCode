#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#define Int __int64

using namespace std;



int main()
{
    Int n;
    while (scanf("%I64d", &n), n)
    {
        Int num[4] = {2, 3, 5, 7};
        int ans[4] = {1, 1, 1, 1};//�������ʱ��û�а�0��2��0��3��0��5����0��7����������ȥ������һ��ʼ�ͼ���
        for (int i = 0; i < n; i++)
        {
            while (n != 1 && n % num[i] == 0)//���2��3��5��7�ĸ���
            {
                ans[i]++;
                n /= num[i];
            }
        }
        printf("%d\n", ans[0] * ans[1] * ans[2] * ans[3]);
    }
    return 0;
}

/*
 4
12
0 
*/
