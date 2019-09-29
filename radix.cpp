#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

vector<int> res = {6, 435, 223, 1235, 2345};
vector<int> res1 = {6, 435, 223, 1235, 2345};
vector<int> a(maxn);
void quick_sort(vector<int> &res, int L, int R)
{
    if (L >= R)
        return;
    int b = res[L];
    int l = L;
    int r = R;
    while (l <= r)
    {
        while(res[l] < b)
            ++l;
        while(b < res[r])
            --r;
        if (l <= r)
            swap(res[l++], res[r--]);
    }
    quick_sort(res, L, r);
    quick_sort(res, l, R);
}

void merge_sort(vector<int> &res, int L, int R)
{
    if (L == R)
        return;
    int mid = (L + R) >> 1;
    merge_sort(res1, L, mid);
    merge_sort(res1, mid+1, R);
    int lidx = L;
    int s = L;
    int ridx = mid+1;
    while (lidx <= mid && ridx <= R)
    {
        if(res1[lidx] < res1[ridx]) 
            a[s++] = res1[lidx++]; 
        else 
            a[s++] = res[ridx++];  
    }
    while (lidx <= mid)
        a[s++] = res1[lidx++];
    while (ridx <= R)
        a[s++] = res1[ridx++];
    for (int i = L; i <= R; ++i)
        res1[i] = a[i];
}

int main()
{
    quick_sort(res, 0, res.size()-1);
    // merge_sort(res1, 0, res.size()-1);
    for (auto it : res)
        cout << it << " ";
    cout << endl;
    system("pause");
    return 0;
}