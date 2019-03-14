#include <cstdio>
#include <cstdlib>
#include <iostream>
#define N 100

typedef int elem;
using namespace std;

typedef struct node {
	elem data;
	struct node * next;
}queue;

typedef struct Q{
	queue *front,*rear;
}cqueue;

//init
void init (cqueue *&q)
{
	q=(cqueue *)malloc (sizeof (cqueue));
	q->front=q->rear=NULL;
}

//isinit
bool isinit(cqueue *q)
{
	if (q->front==NULL)
		return true;
	else 
		return false;
}
//isempty
bool isempty (cqueue *q)
{
	if (q->front==q->rear)
		return true;
	else 
		return false;
 } 

//push 
void push(cqueue *&q,int n)
{
	queue *p=(queue *)malloc (sizeof (queue));
	p->next=NULL;
	p->data=n;
	//若队列没有被初始化 
	if (isinit(q))
	{
		q->front=q->rear=p;
	}
	//若队列已被初始化 
	else 
	{
		q->rear->next=p;
		q->rear=p;
	}
}

//pop
void pop (cqueue *&q)
{
	int a;
	queue *p;
	if (!isinit(q))
	{
		p=q->front;
		a=p->data;
		if(isempty(q)) 
			q->front=q->rear=NULL;
		else 
			q->front=q->front->next;
		free(p);	
	} 
	else 
		cout<<"your queue isn't init yet!\n";
	
}
	
//get_top
void gettop(cqueue *q)
{
	int a;
	//************有bug！！！！ 
	if(q->front!=NULL)
	{
		a=q->front->data;
		cout<<a<<" "; 
	}
	else  
		cout<<"acquri fail!\n";	
	cout<<"\n";
}
//destroy
void destroy(cqueue *&q){
	queue *pre=q->front,*p;
	if(pre!=NULL){
		if(pre==q->rear){
			free(pre);
		}
		else{
			p=pre->next;
			while(p!=NULL){
				free(pre);
				pre=p;
				p=p->next;
			}
			free(pre);
		}
		free(q);
	}
	cout<<"deftroy compelet\n";
}


//show
void show (cqueue *q)
{
	queue *p;
	p=q->front;
	while (1)
	{
		cout<<p->data<<" ";
		if (p==q->rear)
			break;
		p=p->next;
	}
	cout<<"\n";
} 

int main ()
{
	cqueue *q;
	//init
	init (q);
	//push
	push(q,1);
	push(q,5);
	show(q);
	//pop
	pop(q);
	show(q);
	//get_top
	gettop(q);
	//destroy
	destroy(q);
	
	
	return 0;
}
