#include<iostream>
#define MaxDigit 4
#define Radix 10
using namespace std;
typedef int ElementType;
void LSDRadixSort(ElementType A[],int N);
int main()
{
	int arr[10]={0,1,512,343,64,125,216,27,8,729};
	LSDRadixSort(arr,10);
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	
	
	
	return 0;
}

//ͰԪ�ؽڵ�
typedef struct Node* PtrToNode;
struct Node{
	int key;
	PtrToNode next;
};

//ͰԪ�ؽڵ�ͷ
struct HeadNode{
	PtrToNode head,tail;
	
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(int X,int D)
{
	int d,i;
	
	for(i=1;i<=D;i++)
	{
		d=X%Radix;
		X/=Radix;
	}
	
	return d;
}

void LSDRadixSort(ElementType A[],int N)
{
	int D,Di,i;
	Bucket B;
	PtrToNode tmp,p,List=NULL;
	
	for(i=0;i<Radix;i++)
	{
		B[i].head=B[i].tail=NULL;
	}
	
	//��ʼ��ÿ��ͰΪ������
	for(i=0;i<N;i++)
	{
		tmp=(PtrToNode)malloc(sizeof(struct Node));
		tmp->key=A[i];
		tmp->next=List;
		List=tmp;
	} 
	
	//��ʼ����
	for(D=1;D<=MaxDigit;D++)
	{
		p=List;
		while(p)
		{
			//��ȡ��ǰԪ�ص�ǰλ������ 
			Di=GetDigit(p->key,D);
			
			tmp=p;
			p=p->next;
			
			tmp->next=NULL;
			if(B[Di].head==NULL)
			{
				B[Di].head=B[Di].tail=tmp;
			} 
			else
			{
				B[Di].tail->next=tmp;
				B[Di].tail=tmp;
			}
		}
	
		//�ռ�����
		List=NULL;
		for(Di=Radix-1;Di>=0;Di--)
		{
			if(B[Di].head)
			{
				B[Di].tail->next=List;
				List=B[Di].head;
				B[Di].head=B[Di].tail=NULL;
			}
		} 	
	
	} 
	
	//��List���� A[] ���ͷſռ�
	for(i=0;i<N;i++)
	{
		tmp=List;
		List=List->next;
		A[i]=tmp->key;
		free(tmp);
	} 
	
}





