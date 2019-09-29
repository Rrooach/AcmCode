#include <iostream>
using namespace std;
struct
{
    char key;
    int next;
    bool flag;
} node[100010];
int main()
{
    int d1, d2, n;
    cin >> d1 >> d2 >> n;
    for (int i = 0; i < n; i++)
    {
        int t1, t2;
        char ch;
        cin >> t1 >> ch >> t2;
        node[t1] = {ch, t2, false};
    }
    for (int i = d1; i != -1; i = node[i].next)
        node[i].flag = true;
    for (int i = d2; i != -1; i = node[i].next)
    {
        if (node[i].flag)
        {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
