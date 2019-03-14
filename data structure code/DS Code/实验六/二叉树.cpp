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


//建树 
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

//输出
void print (BiTree bt)
{
	if (bt->data!='#')
		cout<<bt->data<<" ";
 } 
//先序遍历
void preOrder (BiTree bt)
{
	if (bt !=NULL)
	{
		print (bt);
		print (bt->lc);
		print (bt->rc);
	}
}
//中序遍历
void midOrder (BiTree bt)
{
	if (bt !=NULL)
	{
		print (bt->lc);
		print (bt);
		print (bt->rc);
	}
}
//后序遍历
void postOrder (BiTree bt)
{
	if (bt !=NULL)
	{
		print (bt->lc);
		print (bt->rc);
		print (bt);
	}
}
//求深度
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
//求叶子结点个数 
int total(BiTree bt)
{
	
	if (bt =NULL) 
		return 0;
	if((bt->lc==NULL) && (bt->rc ==NULL)) return 1;
	return total(bt->lc )+total(bt->rc );	
}
int main ()
{
	//建树
	BiTree bt;
	cout<<"先序建立一颗二叉树\n";
	creat (bt); 
	//先序遍历
	cout<<"此树的前序遍历是：\n";
	preOrder (bt);
	//中序遍历
	cout<<"此树的中序遍历是：\n";
	midOrder (bt);
	//后序遍历
	cout<<"此树的后序遍历是：\n";
	postOrder (bt);
	//求深度
	cout<<"此树的深度为：\n";
	depth (bt);
	//求叶子结点个数 
	cout<<"树的叶子结点个数为：\n";
	total(bt);
	
	return 0;
}
