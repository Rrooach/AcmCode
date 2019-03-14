#include<stdio.h>
#include<math.h>
int main()
{
int n,m,i;
double sum;
while(scanf("%d",&n)!=EOF){
while(n--){
scanf("%d",&m);
sum=0;
for(i=1;i<=m;i++)
sum=sum+log10((double)i);
printf("%d\n",(int)sum+1);
}
}
return 0;
}
