#include<stdio.h>
#include<stdlib.h>
#define ElementType int
void sort(int arr[], int N);
void Quicksort(ElementType s[], int l, int r);

int main()
{
	int N = 15;
	int arr[15] = { 9,8,65,5,4,12,18,33,46,88,3,68,13,54,66 };

	sort(arr, N);
	for (int i = 0; i<N; i++)
	{
		printf("%d ", arr[i]);

	}
	
	return 0;
}

void sort(int arr[], int N)
{
	Quicksort(arr, 0, N - 1);
}


void Quicksort(ElementType s[], int l, int r)
{
	if (l < r)  
    {  
        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j] >= x) 
                j--;    
            if(i < j)   
                s[i++] = s[j];  
              
            while(i < j && s[i] < x) 
                i++;    
            if(i < j)   
                s[j--] = s[i];  
        }  
        s[i] = x;  
        Quicksort(s, l, i - 1);   
        Quicksort(s, i + 1, r);  
    }  

}
