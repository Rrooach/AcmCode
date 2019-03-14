#include <cstdio>
#include <cstdlib>
#include <iostream>
#define N 100

typedef int elem;
using namespace std;
int x,y; 	//原稀疏矩阵行列数 
typedef struct {
	int i;
	int j;
	elem e;
}triple; 

typedef struct {
	triple data [N];
	int mu,nu,tu;	//total line total col total num
}tsMartix; 

void init (tsMartix *m)
{
	int  p=1;
	int c;
	cout<<"plz enter the array:\n";
	for (int i=1;i<=x;i++)
		for (int j=1;j<=y;j++)
		{
			cin>>c;
			if (c!=0)
			{
				m->data[p].e=c;
				m->data[p].i=i;
				m->data[p].j=j;
				p++;
			}
		}
		m->tu=p-1;
		m->mu=x;
		m->nu=y;
		cout<<"原矩阵有："<<m->mu<<"行 "<<m->nu<<"列 "<<"非零元素有：" <<m->tu<<"个\n";
}

void  FastTransposeSMatrix(tsMartix M,tsMartix &T)
{
	int cpot[N],num[N];
	T.mu=M.nu; T.nu=M.mu; T.tu=M.tu;
	if(T.tu)
  	{
 		for(int col=1;col<=M.mu;++col) num[col]=0;
  		for(int t=1;t<=M.tu;++t) ++num[M.data[t].j]; //记述M.data[t].j列
  		cpot[1]=1;	//非0元的个数
  			//求第col列中第一个非零元在b.data(T)中的序号
  		for(int col=2;col<=M.mu;++col)
         cpot[col]=cpot[col-1]+num[col-1];
  		for(int p=1;p<=M.tu;++p)
         {
         	int col=M.data[p].j;
      		int q=cpot[col];
         	T.data[q].i=M.data[p].j;
         	T.data[q].j=M.data[p].i;
         	T.data[q].e=M.data[p].e;
         	++cpot[col];
      	}
  }
}

void fasttrans (tsMartix &t,tsMartix m)
{
	int num [N],cpot[N];
	t.mu=m.mu;	t.nu=m.nu;	t.tu=m.tu;
	if (t.tu)
	{

		//初始化num数组 
		for (int col =1;col<=m.mu;col++)	num[col]=0;
		//更新num数组->每列有多少元素 
		for (int i=1;i<=m.tu;++i)	++num[m.data[i].j];
		cpot[1]=1;
		//求起始位置 
		for (int col =2;col<=m.mu;++col)
			cpot [col]=cpot[col-1]+num[col-1];
		for (int p=1;p<=m.tu;++p)
		{
			int col=m.data[p].j;
			int q=cpot[col];
			t.data[q].i=m.data[p].j;
			t.data[q].j=m.data[p].i;
			t.data[q].e=m.data[p].e;
			++cpot[col];
		}
	}
}

void show (tsMartix *m)
{
	for (int i=1;i<=m->tu;i++)
		cout<<m->data[i].i<<" "<<m->data[i].j<<" "<<m->data[i].e<<"\n";
}



int main ()
{
	tsMartix *m;
	m=(tsMartix *)malloc (sizeof (tsMartix ));
	//初始化三元组 
	cout<<"plz enter a number of the martix:\n";
	cin>>x>>y;
	init (m);
	cout<<"三元组表示的稀疏矩阵为：\n";  
	show(m);
	//快速转置 
	tsMartix *t;
	t=(tsMartix *)malloc (sizeof (tsMartix));
//	FastTransposeSMatrix(*m,*t);
	fasttrans(*t,*m); 
	cout<<"转置后的矩阵为：\n";
	show(t);
	return 0;
}

/*
4 4
1 0 0 1
0 0 0 2
0 0 2 0
3 0 4 0
*/
