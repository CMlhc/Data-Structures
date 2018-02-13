#include<iostream>
using namespace std;

void getpre(int *post, int *in, int n)
{
	if (n <= 0)
		return;
	int root = post[n - 1];
	int i;
	for (i=0; i < n; i++)
	{
		if (in[i] == root)
		{
			break;
		}
			
	}
	cout << " " << root;
	getpre(post, in, i);
	getpre(post + i, in + i + 1, n - i - 1);
}

int main()
{
	int n;
	int post[30];
	int in[30];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> post[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
	}
	cout << "Preorder:";
	getpre(post, in, n);
	system("pause");
	return 0;
}
