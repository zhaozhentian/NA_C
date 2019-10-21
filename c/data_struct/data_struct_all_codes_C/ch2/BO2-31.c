 /* bo2-31.c һ������ֻ����һ����̬����(���ݽṹ��c2-3.h����)�Ļ�������(11��) */
 void InitList(SLinkList L)
 { /* ����һ���յ���������ͷΪL�����һ����ԪL[MAXSIZE-1]�����൥Ԫ���� */
   /* һ��������������ͷΪL�ĵ�һ����ԪL[0]����0����ʾ��ָ�� */
   int i;
   L[MAXSIZE-1].cur=0; /* L�����һ����ԪΪ�������ı�ͷ */
   for(i=0;i<MAXSIZE-2;i++) /* �����൥Ԫ���ӳ���L[0]Ϊ��ͷ�ı������� */
     L[i].cur=i+1;
   L[MAXSIZE-2].cur=0;
 }

 Status ClearList(SLinkList L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
   int i,j,k;
   i=L[MAXSIZE-1].cur; /* ������һ������λ�� */
   L[MAXSIZE-1].cur=0; /* ������ */
   k=L[0].cur; /* ����������һ������λ�� */
   L[0].cur=i; /* �������Ľ���������������ı�ͷ */
   while(i) /* û������β */
   {
     j=i;
     i=L[i].cur; /* ָ����һ��Ԫ�� */
   }
   L[j].cur=k; /* ���������ĵ�һ�����ӵ�������β�� */
   return OK;
 }

 Status ListEmpty(SLinkList L)
 { /* ��L�ǿձ�������TRUE�����򷵻�FALSE */
   if(L[MAXSIZE-1].cur==0) /* �ձ� */
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(SLinkList L)
 { /* ����L������Ԫ�ظ��� */
   int j=0,i=L[MAXSIZE-1].cur; /* iָ���һ��Ԫ�� */
   while(i) /* û����̬����β */
   {
     i=L[i].cur; /* ָ����һ��Ԫ�� */
     j++;
   }
   return j;
 }

 Status GetElem(SLinkList L,int i,ElemType *e)
 { /* ��e����L�е�i��Ԫ�ص�ֵ */
   int l,k=MAXSIZE-1; /* kָ���ͷ��� */
   if(i<1||i>ListLength(L))
     return ERROR;
   for(l=1;l<=i;l++) /* �ƶ�����i��Ԫ�ش� */
     k=L[k].cur;
   *e=L[k].data;
   return OK;
 }

 int LocateElem(SLinkList L,ElemType e) /* �㷨2.13���иĶ��� */
 { /* �ھ�̬�������Ա�L�в��ҵ�1��ֵΪe��Ԫ�ء����ҵ����򷵻�����L�е� */
   /* λ�򣬷��򷵻�0����������LocateElem()�Ķ��岻ͬ) */
   int i=L[MAXSIZE-1].cur; /* iָʾ���е�һ����� */
   while(i&&L[i].data!=e) /* �ڱ���˳������(e�������ַ���) */
     i=L[i].cur;
   return i;
 }

 Status PriorElem(SLinkList L,ElemType cur_e,ElemType *pre_e)
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ���� */
   /*           �������ʧ�ܣ�pre_e�޶��� */
   int j,i=L[MAXSIZE-1].cur; /* iָʾ������һ������λ�� */
   do
   { /* ����ƶ���� */
     j=i;
     i=L[i].cur;
   }while(i&&cur_e!=L[i].data);
   if(i) /* �ҵ���Ԫ�� */
   {
     *pre_e=L[j].data;
     return OK;
   }
   return ERROR;
 }

 Status NextElem(SLinkList L,ElemType cur_e,ElemType *next_e)
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣� */
   /*           �������ʧ�ܣ�next_e�޶��� */
   int j,i=LocateElem(L,cur_e); /* ��L�в��ҵ�һ��ֵΪcur_e��Ԫ�ص�λ�� */
   if(i) /* L�д���Ԫ��cur_e */
   {
     j=L[i].cur; /* cur_e�ĺ�̵�λ�� */
     if(j) /* cur_e�к�� */
     {
       *next_e=L[j].data;
       return OK; /* cur_eԪ���к�� */
     }
   }
   return ERROR; /* L������cur_eԪ��,cur_eԪ���޺�� */
 }

 Status ListInsert(SLinkList L,int i,ElemType e)
 { /* ��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e */
   int l,j,k=MAXSIZE-1; /* kָ���ͷ */
   if(i<1||i>ListLength(L)+1)
     return ERROR;
   j=Malloc(L); /* �����µ�Ԫ */
   if(j) /* ����ɹ� */
   {
     L[j].data=e; /* ��ֵ���µ�Ԫ */
     for(l=1;l<i;l++) /* �ƶ�i-1��Ԫ�� */
       k=L[k].cur;
     L[j].cur=L[k].cur;
     L[k].cur=j;
     return OK;
   }
   return ERROR;
 }

 Status ListDelete(SLinkList L,int i,ElemType *e)
 { /* ɾ����L�е�i������Ԫ��e����������ֵ */
   int j,k=MAXSIZE-1; /* kָ���ͷ */
   if(i<1||i>ListLength(L))
     return ERROR;
   for(j=1;j<i;j++) /* �ƶ�i-1��Ԫ�� */
     k=L[k].cur;
   j=L[k].cur;
   L[k].cur=L[j].cur;
   *e=L[j].data;
   Free(L,j);
   return OK;
 }

 Status ListTraverse(SLinkList L,void(*vi)(ElemType))
 { /* ��ʼ����:���Ա�L�Ѵ��� */
   /* �������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ�� */
   int i=L[MAXSIZE-1].cur; /* ָ���һ��Ԫ�� */
   while(i) /* û����̬����β */
   {
     vi(L[i].data); /* ����vi() */
     i=L[i].cur; /* ָ����һ��Ԫ�� */
   }
   printf("\n");
   return OK;
 }