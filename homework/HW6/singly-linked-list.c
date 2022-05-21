#include<stdio.h>
#include<stdlib.h>

typedef struct Node {	//노드 구조체 선언
	int key;	//노드의 데이터를 저장할 key값 선언 
	struct Node* link;	//다음 노드의 주소를 저장할 link값 선언
} listNode;

typedef struct Head {	//헤드 구조체 선언
	struct Node* first;	//헤드 노드 생성
}headNode;

//함수 원형
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	printf("[----- [김예경] [2021039010] -----]\n");
	char command;	//command 입력받을 변수 선언
	int key;		//key를 입력받을 변수 선언
	headNode* headnode=NULL;	//headnode를 NULL로 초기화

	do{	//do-while로 빠져나올 때까지 반복
		
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//명령어 입력받음

		switch(command) {	//switch-case로 command 판단할 조건문 이용
		case 'z': case 'Z':	//z 입력시
			headnode = initialize(headnode);	//리스트 초기화	
			break;
		case 'p': case 'P':	//p 입력시
			printList(headnode);	//리스트 출력
			break;
		case 'i': case 'I':	//i 입력시
			printf("Your Key = ");
			scanf("%d", &key);	//key를 입력받고
			insertNode(headnode, key);	//리스트에 노드 삽입
			break;
		case 'd': case 'D':	//d 입력시
			printf("Your Key = ");
			scanf("%d", &key);	//key를 입력받고
			deleteNode(headnode, key);	//리스트에 노드 삭제
			break;
		case 'n': case 'N':	//n 입력시
			printf("Your Key = ");
			scanf("%d", &key);	//key를 입력받고
			insertLast(headnode, key);	//리스트에 마지막노드로 삽입
			break;
		case 'e': case 'E':	//e 입력시
			deleteLast(headnode);	//리스트에 마지막노드 삭제
			break;
		case 'f': case 'F':	//f 입력시
			printf("Your Key = ");
			scanf("%d", &key);	//key를 입력받고
			insertFirst(headnode, key);	//리스트에 첫번째 노드로 삽입
			break;
		case 't': case 'T':	//t 입력시
			deleteFirst(headnode);	//리스트 첫번째 노드 삭제
			break;
		case 'r': case 'R':	//r 입력시
			invertList(headnode);	//리스트 노드 역순으로 
			break;
		case 'q': case 'Q':	//q 입력시
			freeList(headnode);	//메모리 할당 해제
			break;
		default:	//그 외 입력시
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");	
			break;
		}

	}while(command != 'q' && command != 'Q');	//q를 입력하면 반복분을 빠져나감

	return 1;
}

headNode* initialize(headNode* h) {	//연결리스트 초기화

	if(h != NULL)	//headNode가 NULL이 아니면,
		freeList(h);	// 할당된 메모리 모두 해제 

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode));	//headnode 크기만큼 메모리 할당
	temp->first = NULL;	//첫번째 node 초기화
	return temp;	//temp 리턴
}

int freeList(headNode* h){	//연결리스트 메모리 할당 해제
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first;	//p를 headnode로 초기화

	listNode* prev = NULL;
	while(p != NULL) {	//마지막 노드까지 반복하며
		prev = p;	//
		p = p->link;	//다음 노드로 옮김
		free(prev);
	}
	free(h);	//h 메모리 할당 해제
	return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {	

	listNode* node = (listNode*)malloc(sizeof(listNode));	//노드 생성하고 메모리 할당 받음
	node->key = key;	//key값으로 데이터 초기화
	node->link = NULL;	//link는 널로 초기화

	if (h->first == NULL)	//list가 비었을 경우
	{
		h->first = node;	//headnode가 노드를 가리키게 함 
		return 0;
	}

	listNode* n = h->first;		//노드 n 생성
	listNode* trail = h->first;	//노드 trail 생성

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) {
		if(n->key >= key) {	//입력받은 key보다 노드 값이 큰 경우
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) {	//n이 첫노드일경우
				h->first = node;	//headnode가 노드를 가리키게 함 
				node->link = n;	//생성한 노드와 n을 연결
			} else { /* 중간이거나 마지막인 경우 */
				node->link = n;	//n을 노드 다음이 되게 연결
				trail->link = node;	//노드가 trail 다음이 되게 연결
			}
			return 0;
		}

		trail = n;	//trail에 n 대입
		n = n->link;	//n이 다음노드를 가리키게 함
	}

	/* 마지막 노드까지 찾지 못한 경우 , 마지막에 삽입 */
	trail->link = node;	//trail 다음 노드 연결
	return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {	//리스트의 마지막에 노드 삽입

	listNode* node = (listNode*)malloc(sizeof(listNode));	//메모리 할당하여 node 생성
	node->key = key;	//node의 key에 입력받은 key값으로 초기화
	node->link = NULL;	//node의 link에 NULL로 초기화

	if (h->first == NULL)	//list가 비었을 경우
	{
		h->first = node;	//headnode가 노드를 가리키게 함 
		return 0;
	}

	listNode* n = h->first;	//마지막 노드를 찾을 n 생성
	while(n->link != NULL) {	//마지막 노드가 될 때까지 반복
		n = n->link;	//n에 다음 노드 저장
	}
	n->link = node;	//마지막 노드와 생성한 노드 연결
	return 0;
}

/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {	//리스트의 처음에 노드 삽입

	listNode* node = (listNode*)malloc(sizeof(listNode));	//메모리 할당하여 node 생성
	node->key = key;	//node의 key에 입력받은 key값으로 초기화

	node->link = h->first;	//생성한 노드의 링크에 headnode 받음
	h->first = node;	//headnode에 생성한 노드 연결

	return 0;
}

/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {	//노드 삭제

	if (h->first == NULL)	//list가 비었을 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first;	//노드 n 생성, 헤드노드가 되게 초기화
	listNode* trail = NULL;	//노드 trail 생성, 널로 초기화

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) {	//노드 마지막까지
		if(n->key == key) {	//입력한 값과 데이터 값이 같을 경우
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) {	//첫 노드이면
				h->first = n->link;	//헤드노드를 n의 다음 노드와 연결
			} else { /* 중간인 경우거나 마지막인 경우 */
				trail->link = n->link;	//trail링크에 n의 link 대입
			}
			free(n);	//n 메모리 할당 해제
			return 0;
		}
		//입력한 값과 데이터 값이 같지 않을 경우
		trail = n;	//trail에 n 대입
		n = n->link;	//n이 다음노드를 가리키게 함
	}

	/* 찾지 못 한경우 */
	printf("cannot find the node for key = %d\n", key);
	return 0;

}

int deleteLast(headNode* h) {	//연결리스트의 마지막 노드 삭제

	if (h->first == NULL)	//list가 비었을 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first;	//노드 n 생성
	listNode* trail = NULL;	//노드 trail 생성

	/* 노드가 하나만 있는 경우, 즉 first node == last node인  경우 처리 */
	if(n->link == NULL) {	//list가 비었을 경우
		h->first = NULL;	//헤드노드를 널로 초기화
		free(n);	//n 메모리 할당 해제
		return 0;
	}

	/* 마지막 노드까지 이동 */
	while(n->link != NULL) {	//마지막 노드가 될 때까지 반복
		trail = n;	//trail에 n 대입
		n = n->link;	//다음 노드로 이동
	}

	/* n이 삭제되므로, 이전 노드의 링크 NULL 처리 */
	trail->link = NULL;	//마지막 바로 이전 노드의 link를 널로 초기화
	free(n);	//n 메모리 할당 해제

	return 0;
}
/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {

	if (h->first == NULL)	//list가 비었을 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->first;	//노드 n 생성

	h->first = n->link;	//헤드노드를 n의 다음 노드와 연결
	free(n);	//n 메모리 할당 해제

	return 0;
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

void printList(headNode* h) {	//list 출력
	int i = 0;	//node의 수
	listNode* p;	//노드 포인터 p 생성

	printf("\n---PRINT\n");

	if(h == NULL) {	//list가 비었을 경우
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;	//p를 headnode로 초기화

	while(p != NULL) {	//마지막까지 반복하며
		printf("[ [%d]=%d ] ", i, p->key);	//인덱스의 값과 그 key값 출력
		p = p->link;	//다음 노드로 옮김
		i++;	//인덱스 증가
	}

	printf("  items = %d\n", i);	//node 수 출력
}
