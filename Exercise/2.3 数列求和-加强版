#include<iostream>
using namespace std;

int main()
{
	int A, N;
	cin >> A >> N;
	if (N == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	int n[N];
	int j = 0, last = 0;
	for (int i = N; i > 0; i--)
	{
		n[j++] = (i*A + last) % 10;
		last = (i*A + last) / 10;
	}
	if (last > 0)
	{
		cout << last;
	}
	for (int i = N-1; i >= 0; i--)
	{
		cout << n[i];
	}
	cout << endl;
	system("pause");
	return 0;
}
