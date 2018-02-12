Position BinarySearch(List Tbl, ElementType K)
{
	Position Left, Mid, Right;
	Left = 1;
	Right = Tbl->Last;

	while (Left<=Right)
	{
		Mid = (Left + Right) / 2;
		if (K < Tbl->Data[Mid])
		{
			Right = Mid - 1;
		}
		else if(K>Tbl->Data[Mid])
		{
			Left = Mid + 1;
		}
		else
		{
			return Mid;
		}

	}
	return NotFound;

}
