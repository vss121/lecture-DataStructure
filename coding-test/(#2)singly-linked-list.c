#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int key;
	struct Node * link;
} listNode;

typedef struct Head{
	struct Node* first;
} headNode;

int initialize(headNode** h)
{
	(*h) = (headNode*)malloc(sizeof(headNode));
	(*h)->first = NULL;
}
int freenode(headNode* h)	//**
{
	listNode* p = h->first;	//
	listNode* prev = h->first;
	while(p){
		prev = p; 
		p = p->link;
		free(prev);
	}
	free(h);	//*
}
int insert(headNode* h, int num)
{
	if(h->first == NULL) {
		listNode* firstnode = (listNode*)malloc(sizeof(listNode));
		firstnode->key = 1;
		firstnode->link = NULL;
		
		h->first = firstnode;
	}
	int idx = 2;
	listNode* temp = h->first;
	for(int i=2; i<=num; i++) {
		listNode* newnode = (listNode*)malloc(sizeof(listNode));
		newnode->key = idx;
		newnode->link = NULL;
		idx++;
		
		temp->link = newnode;
		temp = temp->link;	//**
}
}
int printnode(headNode* h)
{
	listNode* temp = h->first;
	while(temp) {
		printf("%d ", temp->key);
		temp = temp->link;
	}
}
int main()
{
	headNode* head;
	initialize(&head);
	insert(head, 10);
	printnode(head);
	freenode(head);
	
	
}
