#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;
void Sort (int a[],int n)
{
	for (int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	int temp;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<a[i-1])
		{
			temp=a[i];
			for (int j=1;a[0]<a[j];j--)
			{
				a[j+1]=a[j];
				a[j+1]=temp;
			}
		}
	}
	for (int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}
void directinsert_sort(int a[], int len)  
{  
	for (int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
    int i,j;  
    int temp;  
    for (i=1; i<len; i++) //  
    {  
        temp  = a[i];  
        for (j=i-1; j>=0; j--)  
        {  
            if (temp < a[j])  //如果插入的值小于某个值，则退出循环  
            break;  
  
            a[j+1] = a[j];  
          
        }  
        a[j+1] = temp;  
    }  
}  

int main ()
{
	int a[10];
	for (int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	cout<<"Sort:"<<"\n";
	Sort (a,10);
	cout<<"directinsert_sort:"<<"\n";
	directinsert_sort (a,10);	
	for (int i=0;i<10;i++)
		cout<<a[i]<<" ";
	return 0;
 } 
 //9 8 6 7 4 5 1 3 2 0
