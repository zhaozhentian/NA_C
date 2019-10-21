 /* main3-5.c ����bo3-5.cpp�������� */
 #include"c1.h"
 typedef int SElemType; /* ����ջԪ�ص����� */
 #include"bo3-5.c"

 void print(SElemType c)
 {
   printf("%d ",c);
 }

 void main()
 {
   int j;
   LinkStack s;
   SElemType e;
   if(InitStack(&s))
     for(j=1;j<=5;j++)
       Push(s,2*j);
   printf("ջ�е�Ԫ�ش�ջ�׵�ջ������Ϊ: ");
   StackTraverse(s,print);
   Pop(s,&e);
   printf("������ջ��Ԫ��Ϊ%d\n",e);
   printf("ջ�շ�: %d(1:�� 0:��)\n",StackEmpty(s));
   GetTop(s,&e);
   printf("��ǰջ��Ԫ��Ϊ%d��ջ�ĳ���Ϊ%d\n",e,StackLength(s));
   ClearStack(s);
   printf("���ջ��ջ�շ�: %d(1:�� 0:��)��ջ�ĳ���Ϊ%d\n",StackEmpty(s),StackLength(s));
   printf("�Ƿ�����ջ��: %d(1:�� 0:��)\n",DestroyStack(&s));
 }