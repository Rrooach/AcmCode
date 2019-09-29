#include <bits/stdc++.h>

using namespace std;

string gewei[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string shiwei[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> mmp;

void init()
{
    for (int i = 0; i < 13; ++i)
    {
        mmp[gewei[i]] = i;
        mmp[shiwei[i]] = i * 13;
    }
    for (int i = 1; i < 13; ++i)
    {
        for (int j = 1; j < 13; ++j)
        {
            string str = shiwei[i] + " " + gewei[j];
            mmp[str] = i * 13 + j;
        }
    }
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i)
    {
        string temp;
        getline(cin, temp);
        if (isdigit(temp[0]))
        {
            int n = stoi(temp); 
            for (auto it : mmp)
            {
                if (n == it.second)
                {
                    cout << it.first << endl;
                    break;
                } 
            }
        }
        else
        {
            cout << mmp[temp] << endl;
        }
    }
    system("pause");
    return 0;
}