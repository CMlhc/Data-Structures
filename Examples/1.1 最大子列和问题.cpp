#include<stdio.h>

int MaxSum1(int List[],int N);
int main()
{
	int N=0;
	scanf("%d",&N);
	int List[N];
	for(int i=0;i<N;i++)
	{
		scanf("%d",&List[i]);	
	}
	
	printf("%d",MaxSum1(List,N));
	return  0;
} 

int MaxSum1(int List[],int N)
{
	int i;
	int ThisSum,MaxSum;
	ThisSum=MaxSum=0;
	for(int i=0;i<N;i++)
	{
		ThisSum+=List[i];
		if(ThisSum>MaxSum)
		{
			MaxSum=ThisSum;
		}
		else if(ThisSum<0)
		{
			ThisSum=0;
		}
		
	}	
	return MaxSum;
	
}
