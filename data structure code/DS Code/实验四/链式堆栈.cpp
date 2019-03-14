#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#define size 10

using namespace std;

typedef  int Elem;

 struct node{
	Elem data;
	struct node* next;
};
//初始化 
void initial(struct node *&head)
{
	head=(struct node*)malloc (sizeof (struct  node*));
	head->next=NULL;
}
//建立链表 
void build (int n,struct node *&head)
{
		struct node *p;
		p=head;
		for (int i=0;i<n;i++)
		{
			struct node *new1=(struct node *)malloc(sizeof (struct node*));
			new1->data=i;
			new1->next=p->next;
			p->next=new1;
		}
 } 
//显示 
void show (struct node *&head)
{
	struct node *p;
	p=head;
	while ((p=p->next)!=NULL)
	{
		cout<<p->data<<" ";
	}
	cout<<"\n";
}
//插入
bool insert(struct node *&head,int num,int loc) 
{
	if (loc<0) return false;
	int length=0;
	struct node *p;
	p=head;
	while (p!=NULL&&length<loc-1)
	{
		length++;
		p=p->next;
	}
	if (p==NULL) return false;
	else 
	{
		struct node * new1=(struct node *)malloc (sizeof (struct node *));
		new1->data=num;
		new1->next=p->next;
		p->next=new1;
		return true; 
	}
}
//删除 
bool delet(struct node *&head,int loc)
{
	int length=0;
	struct node *p,*q;
	p=head;
	if (loc<0) return false;
	while (p->next!=NULL&&length<loc-1)
	{
		length++;
		p=p->next;
	}
	if (p->next==NULL) return false;
	else
	{
		q=p->next;
		if (q==NULL) return false;
		else
		{
			cout<<"删除的元素为"<<q->data<<"\n";
			p->next=q->next;
			free(q);
			return true;
		}
	}
}
//获取长度
int  getLength(struct node *&head)
{
	int length=0;
	struct node* p;
	p=head;
	while (p->next!=NULL)
	{
		length++;
		p=p->next;
	}
	return length;
}

//获取特定元素位置 
void  Getnum(struct node * head,int num)
{
	int length=0; 
	struct node *p;
	p=head;
	while ((p=p->next)!=NULL)
	{
		length++;
		if (p->data==num)
		{
			cout<<"length is :"<< length;
			break;
		}
	} 
	if (p->next==NULL)
		cout<<"location fail;\n";
}
//销毁链表
void destory (struct node *&head)
{
	struct node *p,*q;
	p=head->next;
	while (p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	head->next=NULL;	
 } 
int main()
{
	Elem a;
	struct node * head;
	//初始化
	initial(head); 
	//
	insert(head,1,1);
	 insert(head,2,2);
	 insert(head,3,3);
	 insert(head,4,4);
	 show(head);
	 //销毁链表
	 destory(head);
	 cout<<"destory complete\n";
	return 0;
 } 
