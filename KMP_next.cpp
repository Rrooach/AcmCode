#include <bits/stdc++.h>
#define maxn 10
using namespace std;

int j = -1;
string a, b;
int nn[maxn];
int len;
int la, lb;

void getNext(string b)
{
    int j = -1;
    nn[0] = -1;
    for (int i = 1; i < lb; ++i)
    {
        while (j != -1 && b[i] != b[j+1])
            j = nn[j];
        if (b[i] == b[j+1])
            j++;
        //way 1:
        // nn[i] = j;
        //way 2:
        if (j == -1 || b[i+1] == b[j+1])
            nn[i] = j;
        else
            nn[i] == nn[j];   
    }
}

int KMP()
{
    la = a.length(), lb = b.length();
    getNext(b);
    int ans = 0, j = -1;
    for (int i = 0; i < la; ++i)
    {
        while (j != -1 && a[i] != b[j + 1])
            j = nn[j];
        if (a[i] == b[j + 1])
            j++;
        if (j == lb-1)
        {
            ans++;
            j = nn[j];
        }
    }
    return ans;
}


int main()
{
    cin >> a >> b;  
    int res = KMP();
    cout << res << endl;
    system("pause");
    return 0;
}
// #include <algorithm>
// #include <iostream>
// #include <string>

// using namespace std;

// void ComputePrefix(string s, int next[])
// {
//     int n = s.length();
//     int q, k;
//     next[0] = 0;
//     for (k = 0, q = 1; q < n; q++)
//     {
//         while (k > 0 && s[k] != s[q])
//             k = next[k];
//         if (s[k] == s[q])
//             k++;
//         next[q] = k;
//     }
// }
// int KMPMatcher(string text, string pattern)
// {
//     int n = text.length();
//     int m = pattern.length();
//     int next[pattern.length()];
//     ComputePrefix(pattern, next);
//     int ans = 0;
//     for (int i = 0, q = 0; i < n; i++)
//     {
//         while (q > 0 && pattern[q] != text[i])
//             q = next[q];
//         if (pattern[q] == text[i])
//             q++;
//         if (q == m)
//         {
//             ans++;
//             cout << "Pattern occurs with shift " << i - m + 1 << endl;
//             q = 0;
//         }
//     }
// }

// int main()
// {
//     string s = "asasasas";
//     string p = "asas";
//     int res = KMPMatcher(s, p);
//     cout << res << endl;
//     system("pause");
//     return 0;
// }
