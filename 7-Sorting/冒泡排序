#include<stdio.h>

void sort(int arr[],int N);
void swap(int *a,int *b);

int main()
{
	int N=15;
	int arr[15]={1,8,6,5,4,12,18,33,46,88,3,68,13,54,66};
	
	sort(arr,N);
	for(int i=0;i<N;i++)
	{
		printf("%d ",arr[i]);
		
	}	
	return 0;
} 

void sort(int arr[],int N)
{
	for(int p=N-1;p>=0;p--)
	{
		int flag=0;
		for(int i=0;i<p;i++)
		{
			if(arr[i]>arr[i+1])
			{
				swap(&arr[i],&arr[i+1]);
				flag=1;
			}
		}
		if(flag=0) break;
	}
	
}



void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
