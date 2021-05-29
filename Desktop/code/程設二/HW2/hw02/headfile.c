#include <stdio.h>
#include <stdlib.h>

typedef struct TNode * Position;   //���s�R�W��Ӹ`�I�a�}���w
typedef Position BinTree;    //���s�R�W�ڵ��I�a�}���w
struct TNode{
	int  Data;
	BinTree Left;
	BinTree Right;
};

typedef struct lnode{
	int data;
	struct lnode *next;
}Node;

Position bst_search(BinTree BST, int X){
	if(!BST) return NULL;  //�d�䥢��

	if(X>BST->Data)
		return bst_search(BST->Right,X);   //�b�k�l��d��
	else if(X<BST->Data)
		return bst_search(BST->Left,X);    //�b���l��d��
	else
		return BST;          //X==BST->Data
}

BinTree bst_insert(BinTree BST,int  X){
	if(!BST){   //�p�GPosition�S���`�I�A�إߤ@�ӷs���`�I
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else{
		if(X<BST->Data)   //�p�GX<�ڡA���k�M�䥪�`�I�A����䤣��F
			BST->Left = bst_insert(BST->Left,X);
		else
			BST->Right = bst_insert(BST->Right,X);
		//�p�G X == BST->Data ������
	}
		return BST;
}

void arr_insert(int *arr, int *data,int size){
	for (int i = 0; i < size;i++)
		arr[i] = data[i];
}

int arr_search(int *arr,int num,int size){
	for(int i = 0; i < size ;i++){
		if(arr[i]==num){
			return num;
		}
	}
	return EOF;
}

int bs_search(int data[], int search, int n){
	int low = 0, high = n - 1;
	while (low <= high){
		int mid = (low + high) / 2;
		if (data[mid] == search)
			return mid;
		else if (data[mid] > search)
			high = mid - 1;
		else if (data[mid] < search)
			low = mid + 1;  
	}
	return -1;
}

Node *ll_insert(Node *l,int key){
	Node *p;
	p=(Node *)malloc(sizeof(Node));
	p->data=key;
	p->next=l;
	return p;
}

void ll_search(Node *list, int query){
	while (list){
		if (list->data == query)
			break;
		else
			list = list->next;
	}
}
