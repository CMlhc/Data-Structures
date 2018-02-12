#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define NotFound 0

typedef int Position;
typedef int ElementType;
typedef int* List;

Position BinarySearch(List Tbl, ElementType K,int Length)
{
	Position Left, Mid, Right;
	Left = 1;
	Right = Length;

	while (Left<=Right)
	{
		Mid = (Left + Right) / 2;
		if (K < Tbl[Mid])
		{
			Right = Mid - 1;
		}
		else if(K>Tbl[Mid])
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

int main()
{

    int arr[14]={13,5,16,39,45,51,98,100,202,226,321,368,444,501};
    printf("please input the number you want to find:\n");
    int num=0;
    scanf("%d",&num);

    if(BinarySearch(arr,num,arr[0])==0)
    {
        printf("Not Found!\n");
    }
    else
    {
        printf("The posision is %d\n",BinarySearch(arr,num,arr[0]));
    }


    return 0;
}
