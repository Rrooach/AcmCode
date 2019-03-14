#include <cstdio>
#include <cstdlib>
#include <malloc.h>
#include <math.h>
#include <iostream>

typedef char elem; 
using namespace std;
typedef struct node {
	elem data;
	struct node *lc,*rc;
}BiNode,*BiTree;


//���� 
void creat(BiTree &bt)
{
	elem data;
	cin>>data;
	if (data =='#')
		bt =NULL;
	else 
	{
		bt=(BiTree)malloc(sizeof(BiTree));
		bt ->data=data; 
		creat(bt->lc);
		creat(bt->rc);
	}
}

//���
void print (BiTree bt)
{
	if (bt->data!='#')
		cout<<bt->data<<" ";
 } 
//�������
void preOrder (BiTree bt)
{
	if (bt !=NULL)
	{
		print (bt);
		print (bt->lc);
		print (bt->rc);
	}
}
//�������
void midOrder (BiTree bt)
{
	if (bt !=NULL)
	{
		print (bt->lc);
		print (bt);
		print (bt->rc);
	}
}
//�������
void postOrder (BiTree bt)
{
	if (bt !=NULL)
	{
		print (bt->lc);
		print (bt->rc);
		print (bt);
	}
}
//�����
int depth (BiTree bt)
{
	int lh,rh,fh;
	if (bt==NULL)
		return 0;
	else 
	{
		lh = depth (bt->lc);
		rh = depth (bt->rc);
		fh =(lh>rh)?lh:rh; 
	} 
	return fh;
} 
//��Ҷ�ӽ����� 
int total(BiTree bt)
{
	
	if (bt =NULL) 
		return 0;
	if((bt->lc==NULL) && (bt->rc ==NULL)) return 1;
	return total(bt->lc )+total(bt->rc );	
}
int main ()
{
	//����
	BiTree bt;
	cout<<"������һ�Ŷ�����\n";
	creat (bt); 
	//�������
	cout<<"������ǰ������ǣ�\n";
	preOrder (bt);
	//�������
	cout<<"��������������ǣ�\n";
	midOrder (bt);
	//�������
	cout<<"�����ĺ�������ǣ�\n";
	postOrder (bt);
	//�����
	cout<<"���������Ϊ��\n";
	depth (bt);
	//��Ҷ�ӽ����� 
	cout<<"����Ҷ�ӽ�����Ϊ��\n";
	total(bt);
	
	return 0;
}
