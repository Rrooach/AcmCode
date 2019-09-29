#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
struct node
{
    int hp;
    int gj;
} a[MAX];
bool cmp(const struct node a, const struct node b)
{
    return a.gj > b.gj;
}
int main()
{
    int n, k, c;
    scanf("%d%d%d", &n, &k, &c);
    for (int i = 0; i < n; i++) 
        scanf("%d %d", &a[i].hp, &a[i].gj); 
    sort(a, a + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (k >= a[i].hp) 
            continue; 
        else
        {
            if (c >= 0)
            {
                if ((a[i].hp - k) % k == 0)
                    c -= ((a[i].hp - k) / k);
                else
                    c -= ((a[i].hp - k) / k + 1);
                a[i].hp -= k * (((a[i].hp - k) / k) + 1);
                if (a[i].hp <= 0) 
                    continue; 
                else 
                    if (c <= 0) 
                        ans += ((a[i].hp) / k + 1) * a[i].gj;   
            }
            else 
                ans += ((a[i].hp) / k + 1) * a[i].gj; 
        }
    }
    printf("%d\n", ans);
    return 0;
}