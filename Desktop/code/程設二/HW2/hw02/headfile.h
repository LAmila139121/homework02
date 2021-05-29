typedef struct TNode * Position;  
typedef Position BinTree;   
struct TNode{
       	int Data;
	BinTree Left;
	BinTree Right;
};
typedef struct lnode{
	int data;
	struct lnode *next;
}Node;

Position bst_search();
BinTree bst_insert();
void arr_insert();
int arr_search();
int bs_search();
Node *ll_insert();
Node *ll_search();

