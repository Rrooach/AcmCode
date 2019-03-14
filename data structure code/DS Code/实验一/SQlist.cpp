#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

#define MaxSize 100
typedef int ElemType; 
//声明SqList类
 typedef struct 
{
	ElemType data[MaxSize];
	int length;
}SqList;
 
//初始化线性表
void InitList(SqList &L)
{
	L.length = 0;	
} 

//插入数据
int InsertList(SqList &L, int i, ElemType e)
{
	//判断合法性 
	if( i < 1 || i > L.length + 1)
	{
		return 0;
	}
	//移位 
	for(int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j-1];
	}
	//插入数据 
	L.data[i-1] = e;
	//表长+1 
	L.length++;
	return 1;
} 
//删除   判断是否为空
int DeleteData(SqList &L, int i )
{
	//判断合法性 
	if( i < 1 || i > L.length + 1)
	{
		return 0;
	} 
	//移位（删除位置数据直接由后一个覆盖， 最后面一个变成NULL） 
	for(int j = i-1; j < L.length - 1 ; j++)
	{
			L.data[j] = L.data[j+1];
	} 
	//将最后一位变为NULL
	L.data[L.length-1] = NULL;
	//表长减1
	L.length--;
	return 1; 
} 
//ListLength 
void Display(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		cout << i << ":\t" << L.data[i] << endl;
	} 
}
int main(int argc, char** argv) 
{
	//定义线性表 
	SqList L;
	//初始化线性表 
	InitList(L);
	//插入元素
	srand((unsigned)time(NULL));
	InsertList(L, 1, rand()%100);
	InsertList(L, 2, rand()%100);
	InsertList(L, 3, rand()%100);
	InsertList(L, 4, rand()%100);
	InsertList(L, 5, rand()%100);
	InsertList(L, 6, rand()%100);
	Display(L);
	cout << "-------------删除分割线--------------" << endl;
	//删除元素
	DeleteData(L,3); 
	Display(L);
	return 0;
}
