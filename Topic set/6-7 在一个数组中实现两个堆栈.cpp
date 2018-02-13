Stack CreateStack(int MaxSize)
{
	Stack S=(Stack)malloc(sizeof(struct SNode));
	S->MaxSize=MaxSize;
	S->Data=(ElementType *)malloc(sizeof(ElementType)*MaxSize);
	S->Top2=MaxSize;
	S->Top1=-1;
	return S;
}

bool Push(Stack S,ElementType X,int Tag)
{
	if(S->Top2-S->Top1==1)
	{
		printf("Stack Full\n");
		return false;
	}
	else
	{
		if(Tag==1)
		{
			S->Data[++(S->Top1)]=X;
		}
		else
		{
			S->Data[--(S->Top2)]=X;
		}
	
	}
		return true;
}

ElementType Pop(Stack S,int Tag)
{
	int X;
	if(Tag==1)
	{
		if(S->Top1==-1)
		{
			printf("Stack 1 Empty\n");
			return ERROR;
		}
		else
		{
			X=S->Data[S->Top1];
			S->Top1--;
			return X;
		}
	}
	else{
		if(S->Top2==S->MaxSize)
		{
			printf("Stack 2 Empty\n");
			return ERROR;
		}
		else
		{
			X=S->Data[S->Top2];
			S->Top2++;
			return X;
		}
	}
	
}
