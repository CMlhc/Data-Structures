#include<iostream>
using namespace std;

#define MaxTree 10
typedef int Tree;
struct TreeNode
{
	char Data;
	Tree Left;
	Tree Right;
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[]);
bool compare(Tree R1, Tree R2);


int main()
{
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if (compare(R1, R2))
	{
		cout<<"Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	system("pause");
	return 0;
}

Tree BuildTree(struct TreeNode T[])
{
	Tree Root;
	int N;
	cin >> N;
	
	if (N)
	{
		int *check = new int[N];
		for (int i = 0; i < N; i++)
			check[i] = 0;
		for (int i = 0; i < N; i++)
		{
			char c_Left, c_Right;
			cin >> T[i].Data >> c_Left >> c_Right;
			if (c_Left != '-')
			{	
				T[i].Left = c_Left - '0';
				check[T[i].Left] = 1;
			}
			else
			{
				T[i].Left = -1;
			}

			if (c_Right != '-')
			{
				T[i].Right = c_Right - '0';
				check[T[i].Right] = 1;
			}
			else
			{
				T[i].Right = -1;
			}
			int k;
			for (k = 0; k < N; k++)
			{
				if (!check[k])
				{
					break;
				}
					
			}
			Root = k;
		}
	}
	else
	{
		Root = -1;
	}

	return Root;
}

bool compare(Tree R1, Tree R2)
{
	if ((R1 == -1) && (R2 == -1))
		return true;
	if (((R1 == -1) && (R2 != -1)) || ((R2 == -1) && (R1 != -1)))
		return false;
	if (T1[R1].Data != T2[R2].Data)
		return false;

	if ((T1[R1].Left == -1) && (T2[R2].Left == -1))
		return compare(T1[R1].Right, T2[R2].Right);

	if ((T1[R1].Left != -1) && (T2[R2].Left != -1) && ((T1[T1[R1].Left].Data) == (T2[T2[R2].Left].Data)))
	{
		return (compare(T1[R1].Left, T2[R2].Left) && compare(T1[R1].Right, T2[R2].Right));
	}
	else
	{
		return (compare(T1[R1].Left, T2[R2].Right) && compare(T1[R1].Right, T2[R2].Left));
	}
}
