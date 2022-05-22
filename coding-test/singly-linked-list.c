#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node* link;	
} listNode;

typedef struct Head {
	struct Node* first;
} headNode;

int freeList(headNode* h)
{
	listNode* p = h->first;
	listNode* prev = NULL;
	while(p!=NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}

int initialize(headNode** h)
{
	if(*h != NULL) freeList(*h);
	
	*h = (headNode*)malloc(sizeof(headNode));
    (*h)->first = NULL;
}
int insertNode(headNode* h, int num)
{
    listNode* newNode;
    int idx = 2;
	listNode* node = (listNode*)malloc(sizeof(listNode));	
	node->key = 1;	
	node->link = NULL;

    //첫번째 노드 생성
	if (h->first == NULL)	//list가 비었을 경우
	{
		h->first = node;
	}

    //나머지 노드 생성
	listNode* temp = h->first;
    for(int i=2; i<=num; i++) {
        newNode = (listNode*)malloc(sizeof(listNode));
        newNode->key = idx;
        newNode->link = NULL;

        temp->link = newNode;
        temp = temp->link;
        idx++;
    }
    
}
void printList(headNode* h)
{
	listNode* p = h->first;
	
	if(h==NULL) {
		printf("nothing");
		return;
	}
	while(p!=NULL) {
		printf("%d ", p->key);
		p = p->link;
	}
}
int invertList(headNode* h) {	//리스트의 링크를 역순으로 재 배치

	if(h->first == NULL) {	//list가 비었을 경우
		printf("nothing to invert...\n");
		return 0;	//종료
	}
	listNode *n = h->first;	//n을 headnode로 초기화
	listNode *trail = NULL;	//trail을 널로 초기화
	listNode *middle = NULL;	//middle을 널로 초기화

	while(n != NULL){	//마지막 노드까지
		trail = middle;	//trail에 middle 대입
		middle = n;	//middle에는 n 대입
		n = n->link;	//n 다음 노드로
		middle->link = trail;	//middle의 link는 trail과 연결
	}

	h->first = middle;	//헤드노드는 middle과 연결

	return 0;
}
int main()
{
	headNode* headnode = NULL;
	
	initialize(&headnode);
	
	int num;
	scanf("%d", &num);
	
	insertNode(headnode, num);
	printList(headnode);
	freeList(headnode);
}
