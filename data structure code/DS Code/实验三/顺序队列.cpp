#include <cstdio>
#include <cstdlib>
#include <iostream>
#define N 10
typedef int elem;

using namespace std;

typedef struct Squeue{
	elem data[N];
	int front,rear;
}queue;
queue q;
//初始化
void init(queue &q)
{
	q.front=0;
	q.rear=0;
 } 
//isempty
bool isempty (queue q)
{
	if (q.front ==q.rear)
		return true;
	else 
		return false;
}
//isfull
bool isfull(queue q)
{
	if (q.rear==N) 
		return true;
	else 
		return false;
 } 
 //push
 void push (queue &q,int n)
{
	if (!isfull(q))
	{
		q.data[q.rear]=n;
		q.rear++;
	}	
	else 
		cout<<"push fail queue is full\n";
 } 
 //pop
 int pop (queue &q)
 {
 	if (!isempty(q))
 	{
 		int a;
	 	a=q.data[q.front];
	 	q.front++;
	 	return a;	
	}
	else 
		cout<<"pop fail queue is empty\n";
 }


int main()
{
	queue q;
	//初始化
	init(q);
	//push
	for(int i=0;i<10;i++) 
		push (q,i);
	//pop
	while (!isempty(q))
	{
		cout<<pop(q)<<" ";
	}
	cout<<"\n";
	return 0;
}
