#include<iostream>
using namespace std;

typedef struct AVLTreeNode *AVLTree;
typedef struct AVLTreeNode {
	int Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int GetHeight(AVLTree T)
{
	int HL, HR, MaxH;
	if (T)
	{
		HL = GetHeight(T->Left);
		HR = GetHeight(T->Right);
		MaxH = HL > HR ? HL : HR;
		return (MaxH + 1);
	}
	else
	{
		return 0;
	}
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(B->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;

	return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(B->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;

	return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
	A->Left = SingleLeftRotation(A->Left);
	return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->Right = SingleLeftRotation(A->Right);
	return SingleLeftRotation(A);
}

AVLTree Insert(int X,AVLTree T)
{
	if (!T)
	{
		T = (AVLTree)malloc(sizeof(struct AVLTreeNode));
		T->Data = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Data)
	{
		T->Left = Insert(X, T->Left);
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2)
		{
		if (X < T->Left->Data)
		{
			T = SingleLeftRotation(T);
		}
			
		else
		{
			T = DoubleLeftRightRotation(T);
		}

		}
		
		
		
	}
	else if (X > T->Data)
	{
		T->Right = Insert(X, T->Right);
		if (GetHeight(T->Left) - GetHeight(T->Right) == -2)
		{
		if (X > T->Right->Data)
		{
				T = SingleRightRotation(T);
		}			
		else
		{
			T = DoubleRightLeftRotation(T);
		}

		}
		
	}
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;
}


int main()
{
	int n, m;
	cin >> n;
	struct AVLTreeNode *head = NULL;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		head = Insert(m, head);
	}

	cout << head->Data;
	system("pause");
	return 0;
}
