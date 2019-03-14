 #include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct{
    int a[12];
    int p;
    int v;
}job[10000];

int time2;

void dothings(int t){
    if (job[t].v==1)
        return;
    for (int i=1;i<=job[t].p;i++)
        dothings(job[t].a[i]);
    time2+=job[t].a[0];
    job[t].v=1;
}

int main()
{
    int m,n,i,j,x;
    string line;
    while (scanf("%d",&n)==1 && n!=0){
        scanf("%d\n",&m);
        time2=0;
        for (i=1;i<=n;i++){
            j=0;
            job[i].v=0;
            job[i].p=0;
            getline(cin,line);
            stringstream ss(line);
            while (ss>>x){
                job[i].a[j]=x;
                j++;
            }
            job[i].p=j-1;
        }
        dothings(m);
        cout<<time2<<endl;
    }
    return 0;
}

