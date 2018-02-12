List Reverse(List L)
{
	List front,rear,tag;
	
	front=L;
	if(!front) return NULL;
	rear=front->Next;
	front->Next=NULL;
	while(rear)
	{
		tag=rear->Next;
		rear->Next=front;
		front=rear;
		rear=tag;
	}
	L=front;
	return L;
	
}
