#include <bits/stdc++.h>

using namespace std;

string fir[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string carr[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}; 
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        string temp;
        getline(cin, temp);
        if (isdigit(temp[0]))
        {
            string res;
            int t = stoi(temp);
            vector<int> ans;
            while (t)
            {
                ans.push_back(t / 13);
                t %= 13;
            }
            for (int i = 0; i < ans.size(); ++i)
                cout << ans[i];
                for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
                    res += carr[*it] + " ";
            res += fir[*ans.end()];
            cout << res << endl;
        }
        else
        {
            int len = temp.length();
            string a;
            for (int i = 0; i < len; ++i)
            {
                vector<int> ans;
                a = "";
                if (a[i] != ' ')
                    a += temp[i];
                for (int i = 0; i < 13; ++i) 
                    if (a == carr[i])
                        ans.push_back(i);
                for (int i = 0; i < 13; ++i)
                    if (a == fir[i])
                        ans.push_back(i);
                int res = 0;
                for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
                {
                    res += 13 * (*it);
                }
                res += (*ans.end());
                cout << res << endl;
            }
        }
        
    }
        system("pause");
    return 0;
}