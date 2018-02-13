void InorderTraversal(BinTree BT)
{
	if (BT)
	{
		InorderTraversal(BT->Left);
		printf(" %c", BT->Data);
		InorderTraversal(BT->Right);
	}
}

void PreorderTraversal(BinTree BT)
{
	if (BT)
	{
		printf(" %c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
	
}

void PostorderTraversal(BinTree BT)
{
	if (BT)
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c", BT->Data);
	}
}

void LevelorderTraversal(BinTree BT)
{
	if (!BT)
	{
		return;
	}
	int MaxSize = 100;
	BinTree* arr;
	arr = (BinTree*)malloc(sizeof(BinTree)*MaxSize);
	arr[0] = BT;
	int Front = -1;
	int Rear = 0;
	while (Front!=Rear)
	{
		BinTree a;
		a = arr[++Front%MaxSize];
		printf(" %c", a->Data);
		if (a->Left)
		{
			arr[++Rear%MaxSize] = a->Left;
		}
		if (a->Right)
		{
			arr[++Rear%MaxSize] = a->Right;
		}
	}
}
