#include <stdio.h>
#include <stdlib.h>

typedef struct TNode * Position;   //重新命名單個節點地址指針
typedef Position BinTree;    //重新命名根結點地址指針
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
	if(!BST) return NULL;  //查找失敗

	if(X>BST->Data)
		return bst_search(BST->Right,X);   //在右子樹查找
	else if(X<BST->Data)
		return bst_search(BST->Left,X);    //在左子樹查找
	else
		return BST;          //X==BST->Data
}

BinTree bst_insert(BinTree BST,int  X){
	if(!BST){   //如果Position沒有節點，建立一個新的節點
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else{
		if(X<BST->Data)   //如果X<根，遞歸尋找左節點，直到找不到了
			BST->Left = bst_insert(BST->Left,X);
		else
			BST->Right = bst_insert(BST->Right,X);
		//如果 X == BST->Data 不做事
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
