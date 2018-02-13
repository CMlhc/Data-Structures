#include<iostream>
#define N 100005
using namespace std;


int main()
{
	int arr[N] = { 0 };
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int q1=0, q2=0, p1=0, p2=0;
	for (int i = 0; i < n-1; i++)
	{
		
		if (arr[i] < arr[i + 1])
		{
			p2++;
		}
		else
		{
			p1 = i + 1;
			p2 = 0;
		}

		if (p2 > q2)
		{
			q2 = p2;
			q1 = p1;
		}


	}

	for (int i = q1; i <q1+q2; i++)
	{
		cout << arr[i] << " ";
	}
	cout << arr[q1 + q2];
	
	return 0;
}
