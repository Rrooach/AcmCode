#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S = "()))((";
    stack<char> ss;
    if (S.empty())
        return 0;
    for (auto it : S)
    {
        char top = '1';
        if (!ss.empty())
            top = ss.top();
        if (top == '(' && it == ')')
            ss.pop();
        else
            ss.push(it);
    }
    cout << ss.size();
    system("pause");
    return 0;

    return 0;
}