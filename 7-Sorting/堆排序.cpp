#include<stdio.h>

void sort(int arr[],int N);
void swap(int *a,int *b);
void PercDown(int arr[],int p,int N);

int main()
{
	int N=15;
	int arr[15]={9,8,6,5,4,12,18,33,46,88,3,68,13,54,66};
	
	sort(arr,N);
	for(int i=0;i<N;i++)
	{
		printf("%d ",arr[i]);
		
	}	
	return 0;
} 

void sort(int arr[],int N)
{
	int i;
	for(i=N/2-1;i>=0;i--)
	{
		PercDown(arr,i,N);
	}
	for(i=N-1;i>0;i--)
	{
		swap(&arr[0],&arr[i]);
		PercDown(arr,0,i);
	}
	
}

void PercDown(int arr[],int p,int N)
{
	int Parent,Child;
	int X;
	X=arr[p];
	for(Parent=p;(Parent*2+1)<N;Parent=Child)
	{
		Child=Parent*2+1;
		if(Child!=N-1&&(arr[Child]<arr[Child+1]))
		{
			Child++;		
		}
		if(X>=arr[Child])
		{
			break;
		}
		else
		{
				arr[Parent]=arr[Child];	
		}
		
	}
	arr[Parent]=X;
}



void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
