 /* algo3-1.c �����㷨3.1�ĳ��� */
 #define N 16 /* �����ת���Ľ���N(2��9) */
 typedef int SElemType; /* ����ջԪ������Ϊ����*/
 #include<c1.h> 
 #include"c3-1.h" /* ����˳��ջ*/
 #include"bo3-1.h" /* ����˳��ջ�Ļ������� */

 void conversion() /* �㷨3.1 */
 { /* �������������һ���Ǹ�10������������ӡ��������ֵ��N������ */
   SqStack s;
   unsigned n; /* �Ǹ����� */
   SElemType e;
   InitStack(&s); /* ��ʼ��ջ */
   printf("��10��������nת��Ϊ%d�������������룺n(>=0)=",N);
   scanf("%u",&n); /* ����Ǹ�ʮ��������n */
   while(n) /* ��n������0 */
   {
     Push(&s,n%N); /* ��ջn����N������(N���Ƶĵ�λ) */
     n=n/N;
   }
   while(!StackEmpty(s)) /* ��ջ���� */
   {
     Pop(&s,&e); /* ����ջ��Ԫ���Ҹ�ֵ��e */
	 if(e<=9){
		 printf("%d",e); /* ���e */
	 }else
	 {
		  printf("%c",e+55); /* ���e */
	 }
   }
   printf("\n");
 }

int main()
 {
   conversion();
   return 0;
 }
