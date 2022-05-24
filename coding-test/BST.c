#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
	struct node* left;
	struct node* right;
} Node;

int initialize(Node** h)
{
	(*h) = (Node*)malloc(sizeof(Node));
	(*h)->key = -9999;
	(*h)->right = (*h);
	(*h)->left = NULL;
}
int preorder(Node* ptr)
{
	if(ptr) {
		printf("%d ", ptr->key);	//
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
int inorder(Node* ptr)
{
	if(ptr) {
		
		inorder(ptr->left);
		printf("%d ", ptr->key);
		inorder(ptr->right);
	}
}
int postorder(Node* ptr)
{
	if(ptr) {
		
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ", ptr->key);
	}
}
int freenode(Node* ptr)
{
	if(ptr) {
		freenode(ptr->left);
		freenode(ptr->right);	//**
		free(ptr);	//
	}
}
int freeBST(Node * h)
{
	Node* temp = h->left;
	freenode(temp);
	free(h);
}
int insertnode(Node* h, int num)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->key = num;
	newnode->right = NULL;
	newnode->left = NULL;
	
	if(h->left==NULL) {
		h->left = newnode;
		return 1; 	//**
	}
	
	Node* ptr = h->left;
	Node* parent = NULL;	//**
	while(ptr) {
		parent = ptr;	//**
		if(ptr->key > num) ptr = ptr->left;	//
		else if (ptr->key < num) ptr = ptr->right;
	}
	if(parent->key > num) parent->left = newnode;	//
	else if(parent->key < num) parent->right = newnode;	//
}
Node* searchrecursive(Node* ptr, int num)	//
{
	if(ptr->key > num) ptr = searchrecursive(ptr->left, num);
	else if(ptr->key < num) ptr = searchrecursive(ptr->right, num);
	return ptr;
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
		insertnode(head, arr[i]);
	}
	
	preorder(head->left);
	printf("\n");
	inorder(head->left);
	printf("\n");
	postorder(head->left);
	
	freeBST(head);
}
