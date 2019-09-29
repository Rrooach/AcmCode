#include <bits/stdc++.h>

using namespace std;

char sz[3][3] =
{
        "()",
        "[]",
        "{}",
}; 
int main()
{ 
    int n;
    cin >> n;
    getchar();
    while (n--)
    {
        getchar();
        stack<char> s;
        char ch;
        bool flag = true;
        while (true)
        { 
            scanf("%c", &ch);
            if (ch == ')')
                if (s.top() == '(')
                    s.pop();
                else
                {
                    flag = false;
                    break;
                }
            else if (ch == ']')
                if (s.top() == '[')
                    s.pop();
                else
                {
                    flag = false;
                    break;
                }
            else if (ch == '}')
                if (s.top() == '{')
                    s.pop();
                else
                {
                    flag = false;
                    break;
                }
            if (ch == '\n')
                break;
            if (ch != ')' && ch != ']' && ch != '}')
                s.push(ch);
        }
        if(s.empty())
            cout << "Match!\n";
        else
        {
            cout << "Not match!\n";
        }  
    }
    return 0;
}