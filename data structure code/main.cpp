#include <iostream>
#include<stdio.h>
#include<malloc.h>

//���������
typedef char ElemType;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BTree; 


//����һ�ö�����
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

//�������������
void PreOrder(BTree *bt){
	if(bt!=NULL){
		printf("%c",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
} 

//�������������
void InOrder(BTree *bt){
	if(bt!=NULL){
		InOrder(bt->lchild);
		printf("%c",bt->data);
		InOrder(bt->rchild);
	}
} 

//�������������
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
	//����һ�ö�����
	printf("��ǰ����������һ�ö�����;\n");
	CreateBT(bt);
	
	//�������������
	printf("ǰ�����������:\n");
	PreOrder(bt);
	printf("\n");
	//�������������
	printf("�������������:\n");
	InOrder(bt);
	printf("\n");
	//�������������
	printf("�������������:\n");
	PostOrder(bt); 
	printf("\n");
	
	//��������������
	printf("�����������Ϊ:%d\n",Depth(bt)) ;
	
	//�����������Ҷ�Ӹ���
	printf("��������Ҷ�ӽ�����:%d\n",Leaf(bt)); 
	
	//�����Ϊ2�Ľ�����
	printf("��Ϊ2�Ľ�����:%d\n",TwoDegree(bt)); 
	
	printf("��Ϊ2�Ľ�����:%d\n",countDegreeTwo(bt)); 
	
	//�����Ϊ1�Ľ��
	printf("��Ϊ1�Ľ�����:%d\n",OneDegree(bt)); 
	return 0;
}

