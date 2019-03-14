#include <stdio.h>
#include <malloc.h>
#include <math.h>
 
typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
 
void CreateBiTree(BiTree &bt)
{
	ElemType data;
	scanf("%c", &data);
	if (data == '#')
	{
		bt = NULL;
	}
	else
	{
		bt = (BiTree)malloc(sizeof(BiTNode)); 
		bt->data = data; 
		CreateBiTree(bt->lchild);
		CreateBiTree(bt->rchild);
	}
}

void visit(BiTree bt)
{
	if (bt->data != '#')
		printf("%3c", bt->data);
}

void PreOrder(BiTree bt)
{
	if (bt != NULL)
	{
		visit(bt);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void PostOrder(BiTree bt)
{
	if (bt != NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		visit(bt);
	}
}
 
void InOrder(BiTree bt)
{
	if (bt != NULL)
	{
		//����������
		InOrder(bt->lchild);
		//���ʸ����
		visit(bt);
		//����������
		InOrder(bt->rchild);
	}
}

//����������
int DepthBtree(BiTree bt)
{
	int lh, rh, th;
	if (bt == NULL)
		return 0;
	else
	{
		lh = DepthBtree(bt->lchild);
		rh = DepthBtree(bt->rchild);
		th = (lh >= rh) ? lh : rh;
		return th + 1;
	}
}

//��֤n0=n2+1,����Ҷ�ӽ��ĸ���
int leaf(BiTree bt)
{

	if (bt == NULL)
		return 0;
	if ((bt->lchild == NULL) && (bt->rchild == NULL))
		return 1;
	re turn leaf(bt->lchild) + leaf(bt->rchild);
}

void main()
{
	BiTree bt;
	printf("������һ�ö�����:\n");
	CreateBiTree(bt);

	printf("\n�������:\n");
	PreOrder(bt);

	printf("\n�������:\n");
	InOrder(bt);

	printf("\n�������:\n");
	PostOrder(bt);
	printf("\n");

	printf("�ö���������ȣ�\n");
	printf("%d\n", DepthBtree(bt));

	printf("�ö�������Ҷ�ӽ��ĸ����ǣ�%d\n", leaf(bt));
}
