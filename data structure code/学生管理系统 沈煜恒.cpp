#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <windows.h>
#include <algorithm>
#define N 128
using namespace std;
int i=0; 
int cnt=0;
struct node {
	char name[10];
	char num[20];
	char sex;	//f m
	int math,english;
	int sum;
	double ave;
	int fail;
}per[N];

//菜单函数 
int menu();
//添加用户函数 
void add();
//删除用户函数 
void delet();
//显示所有用户排名函数 
void show();
//编辑信息函数 
void edit ();
//查询函数 
void inquiry();
// 显示所有用户信息函数 
void display();

int main ()
{	
	while (1)
	{
		//windows库清屏函数 
		system("cls");
		switch(menu())
		{
			case 1:
				system("cls");
				printf ("\n\n\t\tloading...\t\t\n");
				//windows库暂停函数 
				Sleep(500);
				add();
				break;
			case 2:
				system("cls");
				printf ("\n\n\t\tloading...\t\t\n");
				Sleep(500);
				delet();
				break;
			case 3:
				system("cls");
				printf ("\n\n\t\tloading...\t\t\n");
				Sleep(500);
				edit();
				break;
			case 4:
				system("cls");
				printf ("\n\n\t\tloading...\t\t\n");
				Sleep(500);
				inquiry();
				break;
			case 5:
				system("cls");
				printf ("\n\n\t\tloading...\t\t\n");
				Sleep(500);
				display();
				break;
			case 6:
				system ("cls");
				printf("\n\t\tbey bey!\n");  
                Sleep(500);
                //windows库终止函数 
                exit(0); 
                break;
		}
		
	}
	return 0;
 } 
 
 int menu()
 {
 	//打印目录 
 	printf ("\t\t--------------------------------------\t\t\n\n");
 	printf ("\t\tWelcome To Student's MIS Manage System\t\t\n\n");
 	printf ("\t\t--------------------------------------\t\t\n\n");
 	printf ("\t\t1.Add \t\t 2.Delet \t\n\n");
 	printf ("\t\t3.Edit\t\t 4.Inquiry\t\n\n");
 	printf ("\t\t5.Display\t 6.Exit\t\n\n");
 	printf ("\t\tPlz Input 1-6:");
 	//定义参数 
 	int cases;
 	cin>>cases;
 	return cases;
 }
void add()
{
    int n=0;  
	//首先定义sing='y'  
    char sign='y'; 
	//清屏函数  系统中调用                                
    system("cls");
	//其实只有当输入N或n时才跳出循环                               
    while(sign!='n'&&sign!='N')                      
      {  
        printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
        printf("\t\tAdd Student's Imformation\n");  
        printf("\t\t\tNumber: ");  
        getchar();
        cin>>per[i].num;  
        printf("\t\t\tName :");  
        getchar();
        cin>>per[i].name;  
        printf("\t\t\tGender:");  
        getchar();
        cin>>per[i].sex;  
        printf("\t\t\tEnglish:");  
        getchar();
        cin>>per[i].english;  
        printf("\t\t\tMath:");  
        getchar();
        cin>>per[i].math;  
        //计算sum 
        per[i].sum=per[i].english+per[i].math;
        //计算平均数 
    	per[i].ave=(double)per[i].sum/2;
    	//计算挂科 
    	if (per[i].math<60&&per[i].english<60)
    		per[i].fail=2;
    	if(per[i].math<60&&per[i].english>=60)
			per[i].fail=1;
		if (per[i].math>=60&&per[i].english<60)
			per[i].fail=1;
    	if(per[i].math>=60&&per[i].english>=60)
    		per[i].fail=0;
        printf("\t\tis countine?(y/n):");  
        getchar();
        scanf("%c",&sign);  
        i++;  
        n=n+1;
        //同步静态变量cnt 
		cnt=i;  
        system( "cls ");  
   }system("pause");                                     //等待命令  
}

void delet ()
{
	char name1[20];
	int i;
	char sign='y';                              //首先定义sing='y'  
    system("cls");                                //清屏函数  系统中调用  
    while(sign!='n'&&sign!='N')   
    {
	   	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
		printf ("Plz Enter The Name You Want To Delet :");
		//输入姓名 
		cin>>name1;
		//for循环进行姓名匹配 
		for (i=0;i<cnt;i++)
		{
			//如果匹配到进入if 
			if (!strcmp(name1,per[i].name))
			{
				for (int j=i;j<cnt;j++)
				{
					per[j]=per[j+1];
				}
				
			}
			system ("cls");
				cout<<"\n\n\n\n\t\t\tDelet Complete\n";
				Sleep(100);
				//windows库暂停函数 
			break;
		}
		//如果未匹配到 
		if (i==cnt) 
			cout<<"\n\n\n\n\t\t\tName NOT Found!\n"; 
		cnt--;	
		printf("is countine?(y/n):");  
        getchar();
        scanf("%c",&sign);
		getchar ();  
        system("cls");	
	}system("pause");    
}

void edit ()
{
	char sign='y';                              //首先定义sing='y'  
    system("cls");                                //清屏函数  系统中调用  
    while(sign!='n'&&sign!='N')    
    {
    	char name1[10];
    	//匹配姓名 
    	cout<<"\n\n\t\tPlz Enter The Name You Want To Edit:";
    	cin>>name1;
    	for (int i=0;i<cnt ;i++)
    	{
    		if (!strcmp(name1,per[i].name))
    		{
    			int n;
    			//打印菜单 
    			cout<<"\n\t\t1.Number\t2.Gender\n\n";
    			cout<<"\t\t3.Math\t\t4.English\n\n";
    			cout<<"\t\tPlz Enter The Item You Want To Edit:";
				//输入操作数进行匹配 
				cin>>n; 
    			switch(n)
    			{
    				case 1:
    					cout<<"\n\t\tPlz Enter New Number:";
    					char number[20];
						cin>>per[i].num;
						break;
					case 2:
						cout<<"\n\t\tPlz Enter New Gender:";
						char sexx;
						cin>>per[i].sex;
						break;
					case 3:
						cout<<"\n\t\tPlz Enter New Math Garde:";
						int math;
						cin>>per[i].math;
						break;
					case 4:
						cout<<"\n\t\tPlz Enter New English Garde:";
						int en;
						cin>>per[i].english;
						break;
					default:
						cout<<"\n\t\tInvaild Input!\n";
						break;
				}
    									
			}
		} 
		cout<<"\n\n\t\tEditon Complete!";
		Sleep(100);
		system("cls");
		printf("is countine?(y/n):"); 
    	getchar();
        scanf("%c",&sign);
		getchar ();  
        system("cls");	
	}system("pause");  
}

void inquiry()
{
	//首先定义sing='y'  
	char sign='y';                        
	//清屏函数  系统中调用  
    system("cls");                               
    while(sign!='n'&&sign!='N')    
    {
    	char name1[10];
    	cout<<"\n\n\t\tPlz Enter The Name You Want To Inquiry:";
    	cin>>name1;
    	for (int i=0;i<cnt ;i++)
    	{
    		if (!strcmp(name1,per[i].name))
    		{
    			int n;
    			cout<<"\n\t\t1.Number\t2.Gender\n\n";
    			cout<<"\t\t3.Math\t\t4.English\n\n";
    			cout<<"\t\t5.Sum\t\t6.Average\n\n";
    			cout<<"\t\t7.Rank\t\t8.Total Fail\n\n";
    			cout<<"\t\tPlz Enter The Item You Want To Edit:";
				cin>>n;
				system ("cls");
    			switch(n)
    			{
    				case 1:
    					cout<<"\n\n\t\tYour Number Is:";
						cout<<per[i].num<<"\n";
						system ("pause");
						break;
					case 2:
						cout<<"\n\n\t\tYour Gender Is:";
						cout<<per[i].sex<<"\n";
						system ("pause");
						break;
					case 3:
						cout<<"\n\n\t\tYour Math Garde Is:";
						cout<<per[i].math<<"\n";
						system ("pause");
						break;
					case 4:
						cout<<"\n\n\t\tYour English Garde Is:";
						cout<<per[i].english<<"\n";
						system ("pause");
						break;
					case 5:
						cout<<"\n\n\t\tYour Sum Garde Is:"<<per[i].sum<<"\n";
						system ("pause");
						break;
					case 6:
						cout<<"\n\n\t\tYour Average Is:"<<per[i].ave<<"\n";
						system ("pause");
						break;
					case 7:
						show();
						break;
					case 8:
						cout<<"\n\n\t\tYour Total Fail Is:"<<per[i].fail<<"\n";
						system ("pause");
						break;
					default:
						cout<<"\n\n\t\tInvaild Input!\n";
						system ("pause");
						break;
				}
    									
			}
		}
		system("cls");
		printf("\n\n\t\tis countine?(y/n):"); 
    	getchar();
        scanf("%c",&sign);
		getchar ();  
        system("cls");	
	}system("pause");  
}

void display ()
{
	
	system ("cls");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
    printf("\tSerial\tNumber\tName\tGender\tMath\tEnglish\t   Sum\t  Avege\n");  
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
    for (int n=0;n<cnt;n++)
    {
    	printf("\t%d\t%s \t%s \t%c \t%d \t%d    \t%d  \t%.2lf\n",n+1,per[n].num,per[n].name,per[n].sex,per[n].english,per[n].math,per[n].sum,per[n].ave);  
	}
	system ("pause");
	system ("cls");
 } 
 //定义sort函数比较方式 
 bool cmp(node x,node y){
	return x.sum<y.sum;
 } 
 
 void show ()
 {
 	system("cls");
 	//自定义sort函数，从小到大定义 
 	sort (per,per+cnt,cmp);	
	printf("\tSerial\tNumber\tName\tGender\tMath\tEnglish\t   Sum\t  Avege\n");
 	for (int n=0;n<cnt;n++)
 	{
 	 
 		printf("\t%d\t%s \t%s \t%c \t%d \t%d\t%d  \t%.2lf\n",n+1,per[n].num,per[n].name,per[n].sex,per[n].english,per[n].math,per[n].sum,per[n].ave);
	 }
	 system("pause"); 
	 system ("cls");
 }
