#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int key;
	struct Node* link;
}listNode;

typedef struct Head {
	struct Node* first;
}headNode;

int freeList(headNode* h)
{
	listNode* p = h->first;
	listNode* prev = NULL;
	while(p) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
}

int initialize(headNode** h)
{
	*h = (headNode*)malloc(sizeof(headNode));
	(*h)->first = NULL;
}

int insert(headNode* h, int num)
{
	
	int idx = 2;
	if(h->first == NULL) {
		listNode* firstnode = (listNode*)malloc(sizeof(listNode));
		firstnode->key = 1;
		firstnode->link = NULL;
		
		h->first = firstnode;
	}
	listNode* temp = h->first;
	for(int i=2; i<=num; i++) {
		listNode* newNode = (listNode*)malloc(sizeof(listNode));
		newNode->key = idx;
		newNode->link = NULL;
		
		idx++;
		temp->link = newNode;
		temp = temp->link;
	}
	
}
void printList(headNode* h)
{
	
	listNode* temp = h->first;
	while(temp) {
		printf("%d ", temp->key);
		temp = temp->link;
	}
}
int main()
{
	int num; scanf("%d", &num);
	
	headNode* headnode;
	initialize(&headnode);
	
	insert(headnode, num);
	printList(headnode);
	
}
