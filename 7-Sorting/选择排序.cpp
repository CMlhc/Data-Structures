#include<stdio.h>

void sort(int arr[],int N);
void swap(int *a,int *b);
int FindMin(int arr[],int i,int j); 

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
	for(int i=0;i<N;i++)
	{
		int minmin;
		minmin=FindMin(arr,i,N-1);
		swap(&arr[i],&arr[minmin]);
	}
	
	
}

int FindMin(int arr[],int i,int j)
{
	int temp=i;
	int min=arr[i];
	for(int k=i+1;k<=j;k++)
	{
		if(arr[k]<min)
		{
			min=arr[k];
			temp=k;
		}
		
	}
	
	return temp;
}


void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
