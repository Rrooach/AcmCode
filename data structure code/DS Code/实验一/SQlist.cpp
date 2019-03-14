#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

#define MaxSize 100
typedef int ElemType; 
//����SqList��
 typedef struct 
{
	ElemType data[MaxSize];
	int length;
}SqList;
 
//��ʼ�����Ա�
void InitList(SqList &L)
{
	L.length = 0;	
} 

//��������
int InsertList(SqList &L, int i, ElemType e)
{
	//�жϺϷ��� 
	if( i < 1 || i > L.length + 1)
	{
		return 0;
	}
	//��λ 
	for(int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j-1];
	}
	//�������� 
	L.data[i-1] = e;
	//��+1 
	L.length++;
	return 1;
} 
//ɾ��   �ж��Ƿ�Ϊ��
int DeleteData(SqList &L, int i )
{
	//�жϺϷ��� 
	if( i < 1 || i > L.length + 1)
	{
		return 0;
	} 
	//��λ��ɾ��λ������ֱ���ɺ�һ�����ǣ� �����һ�����NULL�� 
	for(int j = i-1; j < L.length - 1 ; j++)
	{
			L.data[j] = L.data[j+1];
	} 
	//�����һλ��ΪNULL
	L.data[L.length-1] = NULL;
	//����1
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
	//�������Ա� 
	SqList L;
	//��ʼ�����Ա� 
	InitList(L);
	//����Ԫ��
	srand((unsigned)time(NULL));
	InsertList(L, 1, rand()%100);
	InsertList(L, 2, rand()%100);
	InsertList(L, 3, rand()%100);
	InsertList(L, 4, rand()%100);
	InsertList(L, 5, rand()%100);
	InsertList(L, 6, rand()%100);
	Display(L);
	cout << "-------------ɾ���ָ���--------------" << endl;
	//ɾ��Ԫ��
	DeleteData(L,3); 
	Display(L);
	return 0;
}
