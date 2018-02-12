#include<stdio.h>
#include<stdlib.h>
int GetNumInPos(int num,int pos);
void RadixSort(int arr[],int N);


int main()
{
	int N = 15;
	int arr[15] = { 9,8,65,5,4,12,18,34,33,88,3,68,13,54,66 };

	RadixSort(arr, N);
	for (int i = 0; i<N; i++)
	{
		printf("%d ", arr[i]);

	}
	
	return 0;
}

void RadixSort(int arr[],int N)
{
	int *arr1[10];
	for(int i=0;i<N;i++)
	{
		arr1[i]=(int *)malloc((N+1)*sizeof(int));
		arr1[i][0]=0;
	}
	
	for(int pos=1;pos<10;pos++)
	{
		for(int i=0;i<N;i++)
		{
			int num=GetNumInPos(arr[i],pos);
			int index=++arr1[num][0];
			arr1[num][index]=arr[i];
		}
		for(int i=0,j=0;i<N;i++)
		{
			for(int k=1;k<=arr1[i][0];k++)
			{
				arr[j++]=arr1[i][k];
			}
			arr1[i][0]=0;
		}
	}
	
	
}


int GetNumInPos(int num,int pos)
{
	int temp=1;
	for(int i=0;i<pos-1;i++)
	{
		temp*=10;
	}
	return (num/temp)%10;
	
}
