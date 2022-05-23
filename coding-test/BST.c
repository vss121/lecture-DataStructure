#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int key;
	struct node* left;
	struct node* right;
} Node;

void initialize(Node** h)
{
	(*h) = (Node*)malloc(sizeof(Node));
	(*h)->key = -9999;
	(*h)->left = NULL;	//사용
	(*h)->right = (*h);
}
void freenode(Node* ptr)
{
	if(ptr) {
		freenode(ptr->left);
		freenode(ptr->right);
		free(ptr);
	}
}
int freeBST(Node* h)
{
	Node* p = h->left;	//root node
	freenode(p);
	free(h);
}
int insert(Node* h, int num)
{
	
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->key = num;
	newnode->left = NULL;
	newnode->right = NULL;
	
	if(h->left == NULL) {
		h->left = newnode;
		return 1;
	}
	
	Node* ptr = h->left;	//root node
	Node* parent = NULL;
	while(ptr) {
		parent = ptr;
		if(ptr->key < num) ptr = ptr->right;
		else ptr = ptr->left;
	}
	if(parent->key > num) parent->left = newnode;
	else parent->right = newnode;
}
Node* searchrecursive(Node* ptr, int num)
{
	if(ptr->key > num) ptr = searchrecursive(ptr->left, num);
	else if(ptr->key < num) ptr = searchrecursive(ptr->right, num);
	return ptr;
}
void inorderTraversal(Node* ptr)	//중위 순회
{
	if(ptr) {	//ptr이 널이 아니면
		inorderTraversal(ptr->left);	//왼쪽 서브 트리 이동
		printf("%d ", ptr->key);	//현재 노드 처리
		inorderTraversal(ptr->right);	//오른쪽 서브 트리 이동
	}
}

void preorderTraversal(Node* ptr)	//전위 순회
{
	if(ptr) {	//ptr이 널이 아니면
		printf("%d ", ptr->key);	//현재 노드 처리
		preorderTraversal(ptr->left);	//왼쪽 서브 트리 이동
		preorderTraversal(ptr->right);	//오른쪽 서브 트리 이동
	}
}

void postorderTraversal(Node* ptr)	//후위 순회
{
	if(ptr) {	//ptr이 널이 아니면
		postorderTraversal(ptr->left);	//왼쪽 서브 트리 이동
		postorderTraversal(ptr->right);	//오른쪽 서브 트리 이동
		printf("%d ", ptr->key);	//현재 노드 처리
	}
}
int main()
{
	Node* head = NULL; 
	initialize(&head);
	
	int arr[5];
	for(int i=0; i<5; i++) {
		scanf("%d", &arr[i]);
	}
	for(int i=0; i<5; i++) {
		insert(head, arr[i]);
	}
	
	inorderTraversal(head->left);
	printf("\n");
	preorderTraversal(head->left);
	printf("\n");
	postorderTraversal(head->left);
	freeBST(head);
}
