 #include<stdio.h>
 #include<stdbool.h>
 #include<stdlib.h>
 #define MAXSIZE 100
 typedef int Position;
 typedef int ElementType;
 typedef struct LNode* PtrToLNode;
 struct LNode{
 	ElementType Data[MAXSIZE];
 	Position Last;
 };
 typedef PtrToLNode List;

 List MakeEmpty();
 ElementType FindKth(List L,Position i);
 Position Find(List L,ElementType X);
 bool Insert(List L,ElementType X,Position i);
 bool Delete(List L,Position i);
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
 				printf("ElementType FindKth(List L,Position i)\n");
 				printf("请输入你要找元素的位置\n");
 				scanf("%d",&i);
 				int position1=FindKth(L,i);
 				if(position1!=-1)
                {
                  printf("the num is %d \n",FindKth(L,i));
                }
 				system("pause");
 				system("cls");
 				break;
			case 3:
				printf("Position Find(List L,ElementType X)\n");
				printf("请输入你所要找的元素\n");
				scanf("%d",&X);
				int position=Find(L,X);
				if(position!=-1)
                {
                   printf("the number you want to find is in %d th position\n",position);

                }

				system("pause");
				system("cls");
				break;
			case 4:
				printf("bool Insert(List L,ElementType X,Position i)\n");
				printf("请依次输入你想插入的元素以及元素的位置\n");
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
				printf("请输入你想删除元素的位置\n");
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
    printf("该线性表从第0个位置开始计数\n");
 	printf("1:创建一个空的线性表\n");
 	printf("2:查找线性表的第n个元素\n");
 	printf("3:查找线性表的元素所在的位置\n");
 	printf("4:插入元素\n");
 	printf("5:删除元素\n");
 	printf("6:线性表的长度\n");
 	printf("7:显示所有元素\n");
 }
 List MakeEmpty()
 {
 	List L;
 	L=(List)malloc(sizeof(struct LNode));
 	L->Last=-1;
 	return L;
 }
 ElementType FindKth(List L,Position i)
 {
 	int num=0;
 	if(i>L->Last)
 	{
	 	printf("Error!!!\n");
	 	return -1;
	}
 	else
 	{
	 	return L->Data[i];
	}

 }
 Position Find(List L,ElementType X)
 {
 	int i=0;
 	while(i<=L->Last && L->Data[i]!=X)
 	{
	 	i++;
	}

	if(i>L->Last)
	{
		printf("Not Find!!!\n");
		return -1;
	}
	else
	{
		return i;
	}

 }
 bool Insert(List L,ElementType X,Position i)
{
 	if(L->Last==MAXSIZE-1)
 	{
	 	return false;
	 }
	 if(i<0||i>L->Last+1)
	 {
 		return false;
 	}
	 int num;
	 for(num=L->Last;num>=i-1;num--)
	 {
 		L->Data[num+1]=L->Data[num];

 	}
 	L->Last++;
	L->Data[i]=X;
	return true;
 }
 bool Delete(List L,Position i)
 {
 	if(i<0||i>L->Last)
	 {
 		return false;
 	}
 	int num;
 	for(num=i;num<=L->Last;num++)
 	{
	 	L->Data[num]=L->Data[num+1];

	 }
	 L->Last--;
	 return true;
 }
 int Length(List L)
 {
 	return L->Last+1;
 }

 void all(List L)
 {
 	int i;
 	for(i=0;i<=L->Last;i++)
 	{
	 	printf("%d   ",L->Data[i]);

	}
	printf("\n");

 }
