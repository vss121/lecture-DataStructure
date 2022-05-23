#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}Node;

void inorder(Node* ptr)
{
    if(ptr) {
    inorder(ptr->left);
	printf("%d ", ptr->key);
	inorder(ptr->right);
    }
}
void preorder(Node* ptr)
{
    if(ptr) {
	printf("%d ", ptr->key);
	preorder(ptr->left);
	preorder(ptr->right);
    }
}
void postorder(Node* ptr)
{
    if(ptr) {
	postorder(ptr->left);
	postorder(ptr->right);
	printf("%d ", ptr->key);
    }
}

int main()
{
	int num; scanf("%d", &num);
	
	Node* newnode = (Node*)malloc(sizeof(Node)*(num+1));
	
	for(int i=1; i<=num; i++) {
		newnode[i].key = i;
		newnode[i].left = NULL;
		newnode[i].right = NULL;
	}
	
	for(int i=1; i<=num; i++) {
		if(i%2==0) newnode[i/2].left = &newnode[i];
		else newnode[i/2].right = &newnode[i];
	}

	preorder(&newnode[1]);
}
