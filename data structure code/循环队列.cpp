#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 10
typedef int elem;
using namespace std;

typedef struct node {
	elem data[N];
	int front,rear; 
}cqueue;

//≥ı ºªØ 
void init(cqueue &q)
{
	q.front=q.rear=0;
}

//isfull
bool isfull(cqueue q)
{
	if ((q.rear+1)%N==q.front)
		return true;
	else 
		return false;
 } 
 
 //isempty
 bool isempty (cqueue q)
 {
 	if (q.front==q.rear)
 		return true;
 	else 
 		return false;
 }

//push
void push (cqueue &q,int num)
{
	if (!isfull(q))
	{
		q.rear=(q.rear+1)%N;
		q.data[q.rear]=num;
	}
	else 
		cout<<"push fail! the queue is full!\n";
}

//pop
void pop(cqueue &q)
{
	if (!isempty(q))
	{
		q.front=(q.front+1)%N;
	}
	else 
		cout<<"pop fail! the queue is empty!\n";
}

//acquir top element
int gettop (cqueue q )
{
	if (!isempty(q))
	{
		int a;
		q.front=(q.front+1)%N;
		a=q.data[q.front];
		return a;
	}
	else
	{
		cout<<"acquir fail! the queue is empty!\n";	
		return 0;
	}
}

//show
void show (cqueue q)
{
	for (int i=q.front+1;i<=q.rear;i++)
		cout<<q.data[i]<<" ";
	cout<<"\n";
}

int main()
{
	cqueue q;
	//init
	init(q);
	//push
	cout<<"plz enter the number you want to push:\n";
	int n;
	cin>>n;
	push (q,1);
	push (q,2);
	push (q,3);
	cout<<"queue is:\n";
	show(q); 
	//pop
	pop(q);
	cout<<"queue is:\n";
	show (q);
	//acquir top element
	cout<<"the top element is :"<<gettop(q)<<"\n"; 
	
	return 0;
 } 
