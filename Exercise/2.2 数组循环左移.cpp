#include<iostream>
using namespace std;

void Reverse(int * arr, int p, int q)
{
	for (; p < q; p++, q--)
	{
		int temp = arr[q];
		arr[q] = arr[p];
		arr[p] = temp;
	}
}

void sum(int *arr, int n, int m)
{
	Reverse(arr, 0, m - 1);
	Reverse(arr, m, n - 1);
	Reverse(arr, 0, n - 1);
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	int arr[100];
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}

	if (m%n == 0)
	{
		for (int i = 0; i <n - 1; i++)
		{
			cout << arr[i] << " ";
		}
		cout << arr[n - 1];

		return 0;
	}
	else
	{	
		if (m > n)
		{
			m = m%n;
		}
		
		sum(arr, n, m);
		for (int i = 0; i <n - 1; i++)
		{
			cout << arr[i] << " ";
		}
		cout << arr[n - 1];

		return 0;
	}

}
