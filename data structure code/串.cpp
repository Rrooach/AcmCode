#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//串的堆分配存储描述
typedef struct{
	char *ch; //若是非空串，则按串长分配存储区，否则，ch为NULL
	int length; //串长度
}HString;


//初始化一个空的顺序串
void Str_Init(HString *S){
	S->ch = NULL;
	S->length = 0;
}



//清空顺序串
void Str_Clear(HString *S){
	if(S->ch){
		free(S->ch);
		Str_Init(S);
	}
}


//判断顺序串是否为空
int Str_IsEmpty(HString *S){
	return S->length == 0;
}


//求取串的长度
int Str_GetLength(HString *S){
	return S->length;
}

//顺序串的赋值
void Str_Assign(HString *S,char *chars){
	int i = 0,j;
	char *c = chars;
	//先清空顺序串S
    Str_Clear(S);
	//求得赋值串的长度
	while(*c){
		i++;
		c++;
	}
	//如果赋值串的长度大于0，则进行赋值
	if(i > 0){
		S->ch = (char*)malloc(3*sizeof(char));
		for(j = 0;j < i;j++){
			S->ch[j] = chars[j];
		}
		S->length = i;
	}
}
//顺序串的复制,将Ｔ复制到Ｓ
void Str_Copy(HString *S,HString *T){
	int i;
	//先清空顺序串S
    Str_Clear(S);
    S->length = T->length;
   
    if(S->length){
		S->ch = (char *)malloc(sizeof(char)*S->length);
		for(i = 0;i < S->length;i++)
			S->ch[i] = T->ch[i];
	}
}




//顺序串的连接,将T连接到S后 
void Str_Concat(HString *S,HString *T){
	//临时存放S串 
	HString temp;
	int i,j;
	Str_Init(&temp);
	Str_Assign(&temp,S->ch);
	
	//清空S
	Str_Clear(S);
	//重新为S分配空间
	S->length = temp.length + T->length;
	S->ch = (char*)malloc(sizeof(char) * S->length);
	//分别将temp和T依次赋值给S
	for(i = 0;i < temp.length;i++)
		S->ch[i] = temp.ch[i];
	for(j = 0; j < T->length;j++)
		S->ch[i++] = T->ch[j];

	//将temp释放掉
	free(temp.ch);
}

//顺序串的比较,如果Ｓ>T,返回大于０的值，小于，则返回小于０的值
int Str_Compare(HString *S,HString *T){
	int i;
	for(i = 0; i < S->length && i < T->length;i++)
		if(S->ch[i] != T->ch[i])
			return S->ch[i] - T->ch[i];
	return S->length - T->length;
}


//求子串并用Ｓub返回
void Str_GetSub(HString *S,int pos,int len,HString *Sub){
	int i;
	//判断位置和长度的合法性
	if(pos < 1 || pos > S->length || len < 0 || len > S->length - pos + 1){
		printf("子串的位置或长度不合法！\n");
		exit(-1);
	}
	else{
		Str_Clear(Sub);
		if(len){
			Sub->ch = (char *)malloc(len * sizeof(char));
			for(i = 0;i < len;i++)
				Sub->ch[i] = S->ch[pos + i -1];
			Sub->length = len;
		}
	}
}

//在顺序串中找出给定子串给定位置后出现的第一个的位置
int Str_GetSubIndex(HString *S,HString *Sub,int pos){
	int i,j;
	//先判断位置的合法性
	if(pos < 1 || pos > S->length){
		printf("位置不合法!\n");
		exit(-1);
	}
	if(Str_IsEmpty(S)){
		printf("顺序串为空！\n");
		return -1;
	}
	if(Str_IsEmpty(Sub)){
		printf("给定子串为空，空串为任何串的子串！\n");
		return 0;
	}
	
	for(i = pos - 1; i < S->length - Sub->length + 1;i++){
		for(j = 0; j < Sub->length;j++)
			if(S->ch[i+j] != Sub->ch[j])
				break;
		// 如果找到子串，则j= sub->length
		if(j == Sub->length)
			return i + 1;			
	}
	//如果找不对，则返回-1;
	return -1;	
}




//顺序串中插入子串
void Str_Insert(HString *S,int pos,HString *T){
	int i;
	HString temp;
	if(pos < 1 || pos > S->length){
		printf("位置不合法!\n");
		exit(-1);
	}
	if(Str_IsEmpty(T)){
		printf("子串为空!\n");
		exit(0);
	}
	Str_Init(&temp);
	temp.length = S->length + T->length;
	printf("%d\n",temp.length);
	temp.ch = (char *)malloc(sizeof(char)*temp.length);
	for(i  = 0 ;i < pos ;i++)
		temp.ch[i] = S->ch[i];
	for(; i < pos + T->length;i++)
		temp.ch[i] = T->ch[i - pos];
	for(;i < temp.length;i++)
		temp.ch[i] = S->ch[i - T->length];
	//将串Ｓ　清空，并将串temp赋值给S
	Str_Clear(S);
	S->ch = temp.ch;
	S->length = temp.length;
	
}


//在顺序串删除子串
void Str_DeleteSub(HString *S,int pos,int len){
	int i;
	HString temp;
	//判断位置和长度的合法性
	if(pos < 1 || pos > S->length || len < 0 || len > S->length - pos + 1){
		printf("子串的位置或长度不合法！\n");
		exit(-1);
	}
	if(Str_IsEmpty(S)){
		printf("顺序串为空!\n");
		exit(0);
	}
	Str_Init(&temp);
	temp.length = S->length - len;
	temp.ch = (char *)malloc(sizeof(char)*temp.length);
	for(i = 0 ;i < pos - 1; i++)
		temp.ch[i] = S->ch[i];
	for(;i < temp.length;i++)
		temp.ch[i] = S->ch[i+len];
	//将串Ｓ清空，并将串temp赋值给S
	Str_Clear(S);
	S->ch = temp.ch;
	S->length = temp.length;
	
}
//打印顺序串
void Str_Print(HString *S){
	int i = 0;
	if(Str_IsEmpty(S)){
		printf("顺序串为空!\n");
		exit(0);
	}
	else
		printf("%s\n",S->ch);		
}

int main ()
{
	HString s,t;
	Str_Init(&s); 
	Str_Print(&s);
	Str_GetLength(&s);
	Str_Compare(&s,&t);
	Str_DeleteSub(&s,0,0);
	return 0;
	
}

