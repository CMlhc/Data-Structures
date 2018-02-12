#include<stdio.h>

void sort(int arr[],int N);


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
	for(int p=1;p<N;p++)
	{
		int temp=arr[p];
		int i;
		for(i=p;i>0&&temp<arr[i-1];i--)
		{
			arr[i]=arr[i-1];
		}
		arr[i]=temp;
	}
	
}
