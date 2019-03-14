#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//���Ķѷ���洢����
typedef struct{
	char *ch; //���Ƿǿմ����򰴴�������洢��������chΪNULL
	int length; //������
}HString;


//��ʼ��һ���յ�˳��
void Str_Init(HString *S){
	S->ch = NULL;
	S->length = 0;
}



//���˳��
void Str_Clear(HString *S){
	if(S->ch){
		free(S->ch);
		Str_Init(S);
	}
}


//�ж�˳���Ƿ�Ϊ��
int Str_IsEmpty(HString *S){
	return S->length == 0;
}


//��ȡ���ĳ���
int Str_GetLength(HString *S){
	return S->length;
}

//˳�򴮵ĸ�ֵ
void Str_Assign(HString *S,char *chars){
	int i = 0,j;
	char *c = chars;
	//�����˳��S
    Str_Clear(S);
	//��ø�ֵ���ĳ���
	while(*c){
		i++;
		c++;
	}
	//�����ֵ���ĳ��ȴ���0������и�ֵ
	if(i > 0){
		S->ch = (char*)malloc(3*sizeof(char));
		for(j = 0;j < i;j++){
			S->ch[j] = chars[j];
		}
		S->length = i;
	}
}
//˳�򴮵ĸ���,���Ը��Ƶ���
void Str_Copy(HString *S,HString *T){
	int i;
	//�����˳��S
    Str_Clear(S);
    S->length = T->length;
   
    if(S->length){
		S->ch = (char *)malloc(sizeof(char)*S->length);
		for(i = 0;i < S->length;i++)
			S->ch[i] = T->ch[i];
	}
}




//˳�򴮵�����,��T���ӵ�S�� 
void Str_Concat(HString *S,HString *T){
	//��ʱ���S�� 
	HString temp;
	int i,j;
	Str_Init(&temp);
	Str_Assign(&temp,S->ch);
	
	//���S
	Str_Clear(S);
	//����ΪS����ռ�
	S->length = temp.length + T->length;
	S->ch = (char*)malloc(sizeof(char) * S->length);
	//�ֱ�temp��T���θ�ֵ��S
	for(i = 0;i < temp.length;i++)
		S->ch[i] = temp.ch[i];
	for(j = 0; j < T->length;j++)
		S->ch[i++] = T->ch[j];

	//��temp�ͷŵ�
	free(temp.ch);
}

//˳�򴮵ıȽ�,�����>T,���ش��ڣ���ֵ��С�ڣ��򷵻�С�ڣ���ֵ
int Str_Compare(HString *S,HString *T){
	int i;
	for(i = 0; i < S->length && i < T->length;i++)
		if(S->ch[i] != T->ch[i])
			return S->ch[i] - T->ch[i];
	return S->length - T->length;
}


//���Ӵ����ã�ub����
void Str_GetSub(HString *S,int pos,int len,HString *Sub){
	int i;
	//�ж�λ�úͳ��ȵĺϷ���
	if(pos < 1 || pos > S->length || len < 0 || len > S->length - pos + 1){
		printf("�Ӵ���λ�û򳤶Ȳ��Ϸ���\n");
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

//��˳�����ҳ������Ӵ�����λ�ú���ֵĵ�һ����λ��
int Str_GetSubIndex(HString *S,HString *Sub,int pos){
	int i,j;
	//���ж�λ�õĺϷ���
	if(pos < 1 || pos > S->length){
		printf("λ�ò��Ϸ�!\n");
		exit(-1);
	}
	if(Str_IsEmpty(S)){
		printf("˳��Ϊ�գ�\n");
		return -1;
	}
	if(Str_IsEmpty(Sub)){
		printf("�����Ӵ�Ϊ�գ��մ�Ϊ�κδ����Ӵ���\n");
		return 0;
	}
	
	for(i = pos - 1; i < S->length - Sub->length + 1;i++){
		for(j = 0; j < Sub->length;j++)
			if(S->ch[i+j] != Sub->ch[j])
				break;
		// ����ҵ��Ӵ�����j= sub->length
		if(j == Sub->length)
			return i + 1;			
	}
	//����Ҳ��ԣ��򷵻�-1;
	return -1;	
}




//˳���в����Ӵ�
void Str_Insert(HString *S,int pos,HString *T){
	int i;
	HString temp;
	if(pos < 1 || pos > S->length){
		printf("λ�ò��Ϸ�!\n");
		exit(-1);
	}
	if(Str_IsEmpty(T)){
		printf("�Ӵ�Ϊ��!\n");
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
	//�����ӡ���գ�������temp��ֵ��S
	Str_Clear(S);
	S->ch = temp.ch;
	S->length = temp.length;
	
}


//��˳��ɾ���Ӵ�
void Str_DeleteSub(HString *S,int pos,int len){
	int i;
	HString temp;
	//�ж�λ�úͳ��ȵĺϷ���
	if(pos < 1 || pos > S->length || len < 0 || len > S->length - pos + 1){
		printf("�Ӵ���λ�û򳤶Ȳ��Ϸ���\n");
		exit(-1);
	}
	if(Str_IsEmpty(S)){
		printf("˳��Ϊ��!\n");
		exit(0);
	}
	Str_Init(&temp);
	temp.length = S->length - len;
	temp.ch = (char *)malloc(sizeof(char)*temp.length);
	for(i = 0 ;i < pos - 1; i++)
		temp.ch[i] = S->ch[i];
	for(;i < temp.length;i++)
		temp.ch[i] = S->ch[i+len];
	//��������գ�������temp��ֵ��S
	Str_Clear(S);
	S->ch = temp.ch;
	S->length = temp.length;
	
}
//��ӡ˳��
void Str_Print(HString *S){
	int i = 0;
	if(Str_IsEmpty(S)){
		printf("˳��Ϊ��!\n");
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

