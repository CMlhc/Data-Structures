#include<iostream>
using namespace std;
#define N 10000

void add(int *arr1, int *arr2,int *arr3)
{
	for (int i = 0; i < N; i++)
	{
		arr3[i] += arr1[i] + arr2[i];
	}
}

void mulit(int *arr1, int *arr2, int *arr4)
{
	for (int i= 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr1[i] != 0)
			{
				arr4[i+j] += arr1[i] * arr2[j];
			}
			
		}
	}
}

void Aprintf(int *arr)
{
	int cnt = 0;
	for (int i = N-1; i >=0; i--)
	{
		if (arr[i] != 0)
		{	
			if (cnt) cout << " ";
			cout << arr[i] << " "<<i;
			cnt++;
		}
	}
	if (!cnt) cout << "0 0";
}


int main()
{
	int arr1[N] = { 0 };
	int arr2[N] = { 0 };
	int arr3[N] = { 0 };
	int arr4[N] = { 0 };

	int a, a1,a2;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> a1 >> a2;
		arr1[a2] += a1;
	}

	int b, b1,b2;
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		cin >> b1>>b2;
		arr2[b2] += b1;

	}
	add(arr1, arr2, arr3);
	mulit(arr1, arr2, arr4);
	
	Aprintf(arr4);
	cout << endl;
	Aprintf(arr3);

	return 0;
}
