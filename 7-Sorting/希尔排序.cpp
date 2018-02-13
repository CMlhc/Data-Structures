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
	for(int D=N/2;D>0;D/=2)
	{
		for(int p=D;p<N;p++)
	{
		int temp=arr[p];
		int i;
		for(i=p;i>=D&&temp<arr[i-D];i=i-D)
		{
			arr[i]=arr[i-D];
		}
		arr[i]=temp;
	}
			
	}
	
	
}
