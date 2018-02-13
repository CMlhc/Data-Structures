int GetHeight(BinTree BT)
{
	int MaxHeight;
	int HL, HR;
	if (BT)
	{	
		HL = GetHeight(BT->Left);
		HR = GetHeight(BT->Right);
		MaxHeight = HL > HR ? HL : HR;
		return MaxHeight + 1;
	}
	else
	{
		return 0;
	}
		
}
