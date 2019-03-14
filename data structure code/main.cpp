#include <iostream>
#include<stdio.h>
#include<malloc.h>

//定义二叉树
typedef char ElemType;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BTree; 


//创建一棵二叉树
void CreateBT(BTree *&bt){
	char ch;
	
    scanf("%c",&ch);
    if(ch=='#') bt=NULL;
    else{
    	bt=(BTree *)malloc(sizeof(BTree));
    	bt->data=ch;
    	CreateBT(bt->lchild);
    	CreateBT(bt->rchild);
	}
	
} 

//先序遍历二叉树
void PreOrder(BTree *bt){
	if(bt!=NULL){
		printf("%c",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
} 

//中序遍历二叉树
void InOrder(BTree *bt){
	if(bt!=NULL){
		InOrder(bt->lchild);
		printf("%c",bt->data);
		InOrder(bt->rchild);
	}
} 

//后序遍历二叉树
void PostOrder(BTree *bt){
	if(bt!=NULL){
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%c",bt->data);
	}
} 

int Depth(BTree *bt){
	int lh,rh;
	if(bt==NULL) return 0;
	else{
		lh=Depth(bt->lchild);
		rh=Depth(bt->rchild);
		if(lh>=rh) return lh+1;
		else return rh+1;
	}
}

int Leaf(BTree *bt){
	if(bt==NULL) return 0;
	if((bt->lchild==NULL) && (bt->rchild==NULL)) {
		return 1;
	}else{
		return Leaf(bt->lchild)+Leaf(bt->rchild);
	}
}

int TwoDegree(BTree *bt){
	int s;
	if(bt==NULL) return 0;
	s=(bt->rchild!=NULL) && (bt->lchild!=NULL) ;
	return s+TwoDegree(bt->lchild)+TwoDegree(bt->rchild);	
}

int countDegreeTwo(BTree *bt){
  if (bt == NULL)return 0;
  if (bt->lchild != NULL && bt->rchild != NULL){
  	return 1 + countDegreeTwo(bt->lchild) + countDegreeTwo(bt->rchild);
  }else{
  	return countDegreeTwo(bt->lchild) + countDegreeTwo(bt->rchild);
  }    
	 
}

int OneDegree(BTree *bt){
	int s;
	if(bt==NULL) return 0;
	s=((bt->rchild!=NULL) && (bt->lchild==NULL)) ||((bt->rchild==NULL) && (bt->lchild!=NULL));
	return s+TwoDegree(bt->lchild)+TwoDegree(bt->rchild);
}

int main(int argc, char** argv) {
	BTree *bt;	
	//建立一棵二叉树
	printf("按前序序列输入一棵二叉树;\n");
	CreateBT(bt);
	
	//先序遍历二叉树
	printf("前序遍历二叉树:\n");
	PreOrder(bt);
	printf("\n");
	//中序遍历二叉树
	printf("中序遍历二叉树:\n");
	InOrder(bt);
	printf("\n");
	//后序遍历二叉树
	printf("后序遍历二叉树:\n");
	PostOrder(bt); 
	printf("\n");
	
	//计算二叉树的深度
	printf("二叉树的深度为:%d\n",Depth(bt)) ;
	
	//计算二叉树的叶子个数
	printf("二叉树的叶子结点个数:%d\n",Leaf(bt)); 
	
	//计算度为2的结点个数
	printf("度为2的结点个数:%d\n",TwoDegree(bt)); 
	
	printf("度为2的结点个数:%d\n",countDegreeTwo(bt)); 
	
	//计算度为1的结点
	printf("度为1的结点个数:%d\n",OneDegree(bt)); 
	return 0;
}

