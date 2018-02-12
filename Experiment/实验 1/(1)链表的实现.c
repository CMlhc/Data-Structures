
 #include<stdio.h>
 #include<stdbool.h>
 #include<stdlib.h>

 #define MAXSIZE 100
 #define ERROR -1

 typedef int ElementType;
 typedef struct LNode* PtrToLNode;
 struct LNode{
 	ElementType Data;
 	PtrToLNode Next;

 };
 typedef PtrToLNode List;
 typedef PtrToLNode Position;

 List MakeEmpty();
 ElementType FindKth(List L,int K);
 int Find(List L,ElementType X);
 bool Insert(List L,ElementType X,int i);
 bool Delete(List L,int i);
 int Length(List L);

 void all(List L);
 void show();


 int main()
 {

 	int i,a;
 	int X;
	List L;
 	while(1)
 	{	show();
	 	scanf("%d",&a);
	 	switch(a)
	 	{
	 		case 1:
			 	printf("List MakeEmpty()\n");
	 			L=MakeEmpty();
	 			system("pause");
	 			system("cls");
	 			break;
 			case 2:
 				printf("ElementType FindKth(List L,int K)\n");
 				scanf("%d",&i);
 				int position=FindKth(L,i+1);
 				if(position!=-1)
                {
                   printf("the num is %d \n",FindKth(L,i+1));
                }

 				system("pause");
 				system("cls");
 				break;
			case 3:
				printf("Position Find(List L,ElementType X)\n");
				scanf("%d",&X);
				int q=Find(L,X);
				if(q!=0)
                {
                  printf("the number you want to find is in %d th position\n",q );
                }
				system("pause");
				system("cls");
				break;
			case 4:
				printf("List Insert(List L,ElementType X,Position i)\n");
				scanf("%d %d",&X,&i);
				if(Insert(L,X,i))
				{
					printf("sucess!!\n");
				}
				else
				{
					printf("faill\n");
				}
				system("pause");
				system("cls");
				break;
			case 5:
				printf("Delete(List L,Position i)\n");
				scanf("%d",&i);
				if(Delete(L,i))
				{
					printf("sucess!!\n");
				}
				else
				{
					printf("faill\n");
				}
				system("pause");
				system("cls");
				break;
			case 6:
				printf("int Length(List L)\n");
				printf("The length of the List is %d\n",Length(L));
				system("pause");
				system("cls");
				break;
			case 7:
				printf("void all(List L)\n");
				all(L);
				system("pause");
				system("cls");
				break;


	 	}

 	}



 	return 0;
 }

 void show()
 {
    printf("-------请先创建一个空表-----\n");
    printf("该链表从第1个位置开始计数\n");
 	printf("1:创建一个空的链表\n");
 	printf("2:查找链表的第n个元素\n");
 	printf("3:查找链表的元素所在的位置\n");
 	printf("4:插入元素\n");
 	printf("5:删除元素\n");
 	printf("6:线性表的长度\n");
 	printf("7:显示所有元素\n");

 }
 List MakeEmpty()
 {
 	List L;
 	L=(List)malloc(sizeof(struct LNode));
 	L->Next=NULL;
 	L->Data=-1;
 	return L;

 }
 ElementType FindKth(List L,int K)
 {
 	Position p;
 	p=L;
 	int cnt=1;
 	while(p && (cnt<K))
 	{
	 	p=p->Next;
	 	cnt++;
	 }
	 if((K==cnt)&&p)
	 {
 		return p->Data;
 	}
 	else
 	{
 	    printf("ERROR!\n");
	 	return ERROR;
	 }
 }
int Find(List L,ElementType X)
 {
 	Position p;
 	p=L;
    int num=0;
 	while(p && p->Data!= X)
 	{
 	    num++;
	 	p=p->Next;
	 }
	 if(p==NULL)
	 {
        printf("not find!\n");
 		return 0;
 	 }
 	 else
 	 {
	 	return num;
	 }
 }
 bool Insert(List L,ElementType X,int i)
{
 	Position tmp,pre;
 	int cnt=0;

 	pre=L;
 	while(pre && cnt <i-1)
 	{
	 	pre=pre->Next;
	 	cnt++;
	 }

	 if((pre==NULL&&cnt!=i-1)||i==0)
	 {
 		printf("ERROR");
 		return false;
 	}
 	else{
	 	tmp=(Position)malloc(sizeof(struct LNode));
	 	tmp->Data=X;
	 	tmp->Next=pre->Next;
	 	pre->Next=tmp;
	 	return true;
		 }

 }
 bool Delete(List L,int i)
 {
 	Position pre,tmp;
 	pre=L;
 	int cnt=0;

 	while(pre && cnt<i-1)
 	{
	 	pre=pre->Next;
	 	cnt++;
	}

	if(pre==NULL||pre->Next==NULL||cnt!=i-1)
	{
		printf("ERROR\n");
		return false;
	}
	else
	{
		tmp=pre->Next;
		pre->Next=tmp->Next;
		free(tmp);
		printf("sucess\n");
		return true;
	}
 }
 int Length(List L)
 {
 	Position p;
 	int cnt=0;
 	p=L;
 	while(p)
 	{
	 	p=p->Next;
	 	cnt++;
	}
	return cnt-1;
 }

 void all(List L)
 {
 	Position p;
 	p=L;
 	int cnt=0;
 	while(p)
 	{
 		if(cnt==0)
 		{

		 	cnt++;
		}else
		{
			printf("%d   ",p->Data);
		}

	 	p=p->Next;

	 }
	 if(p!=NULL)
	 {
 		printf("%d   ",p->Data);

 	}

	 printf("\n");

 }
