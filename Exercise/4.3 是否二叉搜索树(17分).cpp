ElementType maxValue(BinTree T)
{
	int max;
	BinTree p;
	p = T->Right;
	max = T->Data;
	while (p)
	{
		if (max < p->Data)
		{
			max = p->Data;
		}
		
		p = p->Right;
	}
	return max;
}

ElementType minValue(BinTree T)
{
	int min;
	BinTree p;

	p = T->Left;
	min = T->Data;
	while (p)
	{
		if (min > p->Data)
		{
			min = p->Data;
		}
		
		p = p->Left;
	}
	return min;
}

bool IsBST(BinTree T)
{
	if (T==NULL) return true;
	if (T->Left != NULL&& maxValue(T->Left) > T->Data)
	{
		return false;
	}
	if (T->Right != NULL&& minValue(T->Left) < T->Data)
	{
		return false;
	}
	if (!IsBST(T->Left) || !IsBST(T->Right))
		return false;

	return true;
}
