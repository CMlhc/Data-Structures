List Insert(List L, ElementType X)
{
	List pre, tmp,head;
	pre = head=L;
	pre = pre->Next;
	tmp = (List)malloc(sizeof(struct Node));
	tmp->Data = X;
	if (L->Next == NULL)
	{
		head->Next = tmp;
		tmp->Next = NULL;
		return L;
	}
	if (pre->Next == NULL)
	{
		if (pre->Data > X)
		{
			tmp->Next = head->Next;
			head->Next = tmp;
			return L;
		}
		else
		{
			pre->Next = tmp;
			tmp->Next = NULL;
			return L;
		}

	}

	while (pre->Next!=NULL&&pre->Next->Data<X)
	{
		pre = pre->Next;
	}


	if (pre->Next == NULL)
	{
		pre->Next = tmp;
		tmp->Next = NULL;
		return L;
	}
	else
	{
		tmp->Next = pre->Next;
		pre->Next = tmp;
		return L;
	}
}
