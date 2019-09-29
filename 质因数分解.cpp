 #include <bits/stdc++.h>
 
 using namespace std;
 int maxn = 1100000;
 int prime[1100000];
 bool isprime[1100000];
 int cnt = 0;
 struct node
 {
     int base;
     int cnt;
};

void check()
{
    
    prime[1] = 1;
    for (int i = 2; i <= maxn; ++i)
    {
        if (isprime[i])
        {
            prime[cnt++] = i; 
            for (int j = i + i; j < maxn; j += i)
            {
                isprime[j] = false; 
            }    
        }
    }
}


 int main()
 {
     int n;
     scanf("%d", &n);
     int temp = n;
     if (n == 1)
     {
         cout << "1=1\n";
         return 0;
     }
     printf("%d=", temp);
     memset(isprime, true, sizeof(isprime));
     check(); 
     int ans = 0;
     int r = sqrt(1.0 * n);
     struct node pp[r];
     for (int i = 0; i < r; ++i)
     {
         if (n % prime[i] == 0)
         {
             pp[++ans].base = prime[i];
             pp[ans].cnt = 0;
             while (n % prime[i] == 0)
             {
                 pp[ans].cnt++;
                 n /= prime[i];
             }
             //  ans++;
         }
          }
          if (n != 1)
          {  
              pp[++ans].base = n; 
              pp[ans].cnt = 1;
          } 
          for (int i = 1; i <= ans; ++i)
          { 
              if (pp[i].cnt > 1)
                  printf("%d^%d", pp[i].base, pp[i].cnt);
             if (pp[i].cnt == 1)
                 printf("%d", pp[i].base);
            if (i > 0 && i < ans )
                cout << "*";
          }
          cout << endl;
          system("pause");
          return 0;
 }


 /*
 97523468
 */