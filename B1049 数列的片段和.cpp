#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    double temp;
    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf", &temp);
        sum += (temp * (n - i) * (i + 1));
    }
    printf("%.2f\n", sum);
    system("pause");
    return 0;
}