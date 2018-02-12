#include<iostream>
using namespace std;

int sum(int arr[], int N)
{
	int ThisSum, MaxSum;
	ThisSum = MaxSum = 0;
	for (int i = 0; i < N; i++)
	{
		ThisSum += arr[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
		}
		if (ThisSum < 0)
		{
			ThisSum = 0;
		}
	}
	return MaxSum;
}

int main()
{
	int n;
	int arr[100001];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << sum(arr, n);



	return 0;
}
