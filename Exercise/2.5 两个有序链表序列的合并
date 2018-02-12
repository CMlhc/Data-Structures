List Merge(List L1, List L2)
{
	List L,pa,pb,pc;
	L = (List)malloc(sizeof(struct Node));
	pa = L1->Next;
	pb = L2->Next;
	pc = L;
	while (pa&&pb)
	{
		if (pa->Data < pb->Data)
		{
			pc->Next = pa;
			pc = pa;
			pa = pa->Next;
		}
		else
		{
			pc->Next = pb;
			pc = pb;
			pb = pb->Next;
		}
	}

	pc->Next = pa ? pa : pb;

	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}
