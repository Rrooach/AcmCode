#include <cstdio>
#include <cstdlib>
#include <iostream>
#define N 1000

char opTab[7]="+-*/()";

int prTab[6][6]=
{
	{1,1,-1,-1,-1,1},
    {1,1,-1,-1,-1,1},
    {1,1,1,1,-1,1},
    {1,1,1,1,-1,1},
    {-1,-1,-1,-1,-1,-1},
    {1,1,1,1,1,1}
}; 

char opStack[N];	//操作符栈
int opTop;	//操作符栈指针
int numStack[N];	//运算数栈 
int numTop;		//运算数指针 


using namespace std;

int getIndex(char op) {
    int i;
    for(i=0; i<6; i++) {
        if(opTab[i]==op)
            return i;
    }
    return -1;
}

int cmpPriority(char opLeft,char opRight) {
    int leftIndex=getIndex(opLeft);
    int rightIndex=getIndex(opRight);
    return prTab[leftIndex][rightIndex];
}

int compute(int a,char op,int b) {
    int result;
    switch(op)
	{
	    case '+': result= a+b; break;
	    case '-': result= a-b; break;
	    case '*': result= a*b; break;
	    case '/': result= a/b;
    }
    return result;  
}

void resolve (char *s)
{
	opTop =numTop =-1;
	int rightOp,leftOp,nowOp,opResult,cmpResult;
	int i=0;
	char nowChar,op;
	
	while (1)
	{
		nowChar = s[i++];
		if  (nowChar =='\0')
			break;
		if (nowChar>='0'&&nowChar<='9')
		{
			nowOp=0;
			do 
			{
				nowOp=nowOp*10+(nowChar-'0');
				nowChar =s[i++];
			}while (nowChar !='\0'&&nowChar >='0'&&nowChar<='9');
			
			numStack[++numTop]=nowOp;
			if (nowChar ==='\0')
				break;
		}
		if (opTop==-1)
			opStack[++opTop]=nowChar;
		else
		{
			while (opTop>-1&& cmpPriority(opStack[opTop],nowChar)>0) 
			{
				op=opStack[opTop--];
				rightOp=numStack[numTop--];
				leftOp=numStack[numTop--];
				opResult=compute(leftOp,op,rightOp);
				numStack[++numTop]=opResult;
			}
			if(nowChar==')') 
				opTop--;    
			else
				opStack[++opTop]=nowChar;
		}
	}
		while( opTop>-1) 
		{
	        op=opStack[opTop--];
	        rightOp =numStack[numTop--];
	        leftOp =numStack[numTop--];
	
	        opResult=compute(leftOp ,op,rightOp );
	        numStack[++numTop]=opResult;
    	}
	cout<<opResult<<"\n";	
} 

void evaluation()
{
	char exp[N];
	int cases;
	cin>>cases;
	while (cases--)
	{
		cin>>exp;
		resolve (exp);
	}
}

int main ()
{
	evaluation();
	return 0;
}
/*测试用例：
6
(1+2*(4-3)+5)
1+(2-3)*5+6/((7-8+9)/(0-1))-2
1+23*4-567+8901
(1+23)*4-(567+8901)
(1+2*3-(4+10*8)/(5+6*7))
((((1+2)*3+4)/5)-6*(7+8)+9)*10

//表达式结果
8
-6
8427
-9372
6
-790
*/
