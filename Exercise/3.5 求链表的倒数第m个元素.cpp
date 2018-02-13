ElementType Find(List L, int m)
{
	List pre;
	int i = 1;
	pre = L;
	while (pre->Next!=NULL)
	{
		i++;
		pre = pre->Next;
	}

	pre = L;
	if (i < m)
	{
		return ERROR;
	}
	for (int a = 0; a < i - m; a++)
	{
		pre = pre->Next;
	}
	return pre->Data;
	
}
