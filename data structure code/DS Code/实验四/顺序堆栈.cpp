#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring>
#define N 1000 


//进制转换
//表达式求值
//括号匹配 
using namespace std;

typedef char elem;

typedef struct  stack{
	elem data[N];
	int front;
}Stack;

//初始化
void init(Stack &s)
{
	s.front=-1;
 } 
 //isempty  empty->true  not empty->false
bool isempty(Stack s)
{
	if (s.front==-1) return true;
	else return false;
 } 
 //isfull full0->true not full->false
 bool isfull(Stack s)
 {
 	if (s.front==N) return true;
 	else return false;
 }
//push 
void push(Stack &s,elem num)
{
	if (!isfull(s))
	{
		s.front++;
		s.data[s.front]=num;
	}
	else 
		cout<<"push fail,stack is full\n";
	
}

 //pop
elem pop(Stack &s)
{
	if (!isempty(s))
	{
		elem a=s.data[s.front];
		s.front--;
		return a;
	}
	else
		cout<<"pop fail,stack is empty\n"; 	
 } 
elem getop(Stack &s)
{
	return s.data[s.front];
}
 //
 void Dtb(Stack &s,int n)
 {
 	while (n)
 	{
 		push(s,n%2);
 		n/=2;
	 }
	 while (!isempty(s))	 
	 {
	 	cout<<pop(s);
	 }
	 cout<<"\n";
 }
 
 void match (Stack &s,char a[])
 {
 	for (int i=0;i<strlen(a);i++)
 	{
 		switch (a[i])
 		{
	 		case '(':
			case '{':
			case '[':
				push (s,a[i]);
				break;
			case ')':
			{ 
				if ('('==getop(s)) pop(s);
				break; 
			}
			case '}':
			{
				if ('{'==getop(s)) cout<<pop(s)<<" ";
				break;
			}
			case ']':
			{
				if ('['==getop(s)) cout<<pop(s)<<" ";
				break;
			}
		}
	}
	if (isempty (s)) cout<<"yes\n";
	else cout<<"no\n"; 
 }
int main()
{
	Stack s;
	//初始化
	init(s);
	//二进制转化
	int n;
	cout<<"plz enter a number you want to convert:\n";
	cin>>n;
	Dtb(s,n);                                               
	cout<<"plz enter a string to match :";
	//括号匹配 
	char a[N];
	cin>>a;
	match (s,a);
	return 0;
}
