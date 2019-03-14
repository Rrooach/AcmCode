#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring>
#define N 1000 


//����ת��
//���ʽ��ֵ
//����ƥ�� 
using namespace std;

typedef char elem;

typedef struct  stack{
	elem data[N];
	int front;
}Stack;

//��ʼ��
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
	//��ʼ��
	init(s);
	//������ת��
	int n;
	cout<<"plz enter a number you want to convert:\n";
	cin>>n;
	Dtb(s,n);                                               
	cout<<"plz enter a string to match :";
	//����ƥ�� 
	char a[N];
	cin>>a;
	match (s,a);
	return 0;
}
