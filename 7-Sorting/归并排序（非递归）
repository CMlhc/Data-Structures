#include<stdio.h>
#include<stdlib.h>
#define ElementType int
void sort(int arr[],int N);
void Merge( ElementType A[], ElementType TmpA[],int L, int R, int RightEnd );
void MSort( ElementType A[], ElementType TmpA[],int N, int  length );

int main()
{
	int N=15;
	int arr[15]={9,8,65,5,4,12,18,33,46,88,3,68,13,54,66};
	
	sort(arr,N);
	for(int i=0;i<N;i++)
	{
		printf("%d ",arr[i]);
		
	}	
	return 0;
} 



void Merge( ElementType A[], ElementType TmpA[],int L, int R, int RightEnd )
{
	int LeftEnd=R-1;
	int num=RightEnd-L+1;
	int i=L;
	
	while((L<=LeftEnd)&&(R<=RightEnd))
	{
		if(A[L]<=A[R])
		{
			TmpA[i++]=A[L++];
		}
		else
		{
			TmpA[i++]=A[R++];
		}
	}
	while(L<=LeftEnd)
	{
		TmpA[i++]=A[L++];	
	}
	while(R<=RightEnd)
	{
		TmpA[i++]=A[R++];	
	}
	
	for(i=0;i<num;i++,RightEnd--)
	{
		A[RightEnd]=TmpA[RightEnd];
	}
}

void MSort( ElementType A[], ElementType TmpA[],int N, int  length )
{
	int i,j;
	for ( i=0; i <= N-2*length; i += 2*length )
		Merge( A, TmpA, i, i+length, i+2*length-1);
	if ( i+length < N ) 
		Merge( A, TmpA, i, i+length, N-1);
	else 
		for ( j = i; j < N; j++ ) TmpA[j] = A[j];
}

void sort(int arr[],int N)
{
	int *TmpA;
	TmpA=(int*)malloc(N*sizeof(int));
	int length=1;
	if(TmpA!=NULL)
	{
		while(length<N)
		{
			MSort(arr,TmpA,N,length);
			length*=2;
			MSort(TmpA,arr,N,length);
			length*=2;
			
		}
	
		free(TmpA);
	}
	else
	{
		printf("Error\n");
	}
	
}
