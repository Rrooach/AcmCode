#include <bits/stdc++.h>

using namespace std;

int main()
{
   string a, b;
   cin >> a >> b;
   int l1 = a.length(), l2 = b.length();
   if (l1 == 0 && l2 == 0)
      cout << "Yes " << "0" << endl;
   if (l1 == 0)
      cout << "No " << l2 << endl;
   if (l2 == 0)
      cout << "Yes " << l1 << endl;
   map<char, int> mmp;
   for (int i = 0; i < l1; ++i)
      mmp[a[i]] ++;
   int flag = 0;
   int cnt = 0;
   for (int i = 0; i < l2; ++i)
   {
      if (mmp[b[i]] != 0)
         mmp[b[i]] --;
      else
      {
         flag = 1; 
         cnt ++;
      }
   }
   if (flag == 1)
      cout << "No " << cnt << endl;
   else
   {
      cout <<"Yes " << l1-l2 << endl;
   }
   
   
   // system("pause");
   return 0;
}