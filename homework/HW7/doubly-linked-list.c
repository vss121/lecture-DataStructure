#include<stdio.h>
#include<stdlib.h>

typedef struct Node {	//이중 연결리스트의 노드 구조
	int key;	//데이터 필드
	struct Node* llink;	//왼쪽 노드와 연결하는 llink
	struct Node* rlink;	//오른쪽 노드를 연결하는 rlink
} listNode;

typedef struct Head {	//리스트 시작을 나타내는 head노드
	struct Node* first;
}headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음
         lab3의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h);	//이중 연결 리스트 초기화(생성)

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해 할것
         - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h);	//이중 연결 리스트 메모리 해제

int insertNode(headNode* h, int key);	//입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입
int insertLast(headNode* h, int key);	//리스트의 마지막에 노드 삽입
int insertFirst(headNode* h, int key);	//list 처음에 key에 대한 노드하나를 추가
int deleteNode(headNode* h, int key);	//list에서 key에 대한 노드 삭제
int deleteLast(headNode* h);	//list의 마지막 노드 삭제
int deleteFirst(headNode* h);	//list의 첫번째 노드 삭제
int invertList(headNode* h);	//리스트의 링크를 역순으로 재배치

void printList(headNode* h);	//이중 연결 리스트 출력

int main()
{
	char command;	//command 입력받을 변수 선언
	int key;	//key를 입력받을 변수 선언
	headNode* headnode=NULL;	//headnode를 NULL로 초기화
	printf("[----- [김예경] [2021039010] -----]");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
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
			initialize(&headnode);	//이중 연결 리스트 초기화(생성)
			break;
		case 'p': case 'P':	//p 입력시
			printList(headnode);	//이중 연결 리스트 출력
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
			invertList(headnode);	//리스트의 링크를 역순으로 재 배치
			break;
		case 'q': case 'Q':	//q 입력시
			freeList(headnode);	//이중 연결 리스트 메모리 해제
			break;
		default:	//그 외 입력시
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');	//q를 입력하면 반복분을 빠져나감

	return 1;
}

int initialize(headNode** h) {	//이중 연결 리스트 초기화(생성)

	if(*h != NULL)	//headNode가 NULL이 아니면
		freeList(*h);	//freeNode를 호출하여 할당된 메모리 모두 해제

	*h = (headNode*)malloc(sizeof(headNode));	//*h에 headNode에 대한 메모리를 할당하여 리턴
	(*h)->first = NULL;	//널로 초기화
	return 1;
}

int freeList(headNode* h){	//이중 연결 리스트 메모리 해제

	listNode* p = h->first;	//p를 headnode로 초기화

	listNode* prev = NULL;
	while(p != NULL) {	// h와 연결된 listNode 메모리 해제
		prev = p;	//prev을 p로 초기화
		p = p->rlink;	//오른쪽 노드로 이동
		free(prev);	//prev의 메모리 해제
	}
	free(h);	//headNode도 해제되어야 함.
	return 0;
}

void printList(headNode* h) {	//이중 연결 리스트 출력
	int i = 0;	//index 값
	listNode* p;	//노드포인터 p

	printf("\n---PRINT\n");

	if(h == NULL) {	//h가 널이면
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;	//p를 headnode로 초기화

	while(p != NULL) {	//p가 널이 아닌 동안 반복하며
		printf("[ [%d]=%d ] ", i, p->key);	//인덱스의 값과 그 key값 출력
		p = p->rlink;	//오른쪽 노드로 이동
		i++;	//인덱스 증가
	}

	printf("  items = %d\n", i);	//원소의 개수
}

int insertLast(headNode* h, int key) {	//리스트의 마지막에 노드 삽입

	listNode* node = (listNode*)malloc(sizeof(listNode));	//새로운 노드 메모리 할당
	node->key = key;	//새로운 노드에 key값 저장
	node->rlink = NULL;	//새로운 노드의 rlink 널로 초기화
	node->llink = NULL;	//새로운 노드의 llink 널로 초기화

	if (h->first == NULL)	//list가 비었을 경우
	{
		h->first = node;	//새로운 노드를 맨 앞에 추가
		return 0;
	}

	listNode* n = h->first;	//마지막 노드를 찾을 노드 n 선언
	while(n->rlink != NULL) {	//마지막 노드에 도달할 때까지 반복
		n = n->rlink;	//오른쪽 노드로 이동
	}
	n->rlink = node;	//마지막 노드의 rlink를 새로운 노드와 연결
	node->llink = n;	//새로운 노드의 llink에는 마지막 노드와 연결
	return 0;
}

int deleteLast(headNode* h) {	//리스트의 마지막 노드 삭제

	if (h->first == NULL)	//list가 비었을 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first;	//마지막 노드를 찾을 노드 n 선언
	listNode* trail = NULL;	//마지막 노드의 왼쪽 노드를 찾을 trail 선언

	/* 노드가 하나만 있는 경우, 즉 first node == last node인  경우 처리 */
	if(n->rlink == NULL) {	//노드가 하나만 있는 경우
		h->first = NULL;	//헤드노드를 널로 초기화
		free(n);	//n 할당 해제
		return 0;
	}

	/* 마지막 노드까지 이동 */
	while(n->rlink != NULL) {	//마지막 노드에 도달할 때까지 반복
		trail = n;	
		n = n->rlink;	//오른쪽 노드로 이동
	}

	/* n이 삭제되므로, 이전 노드의 링크 NULL 처리 */
	trail->rlink = NULL;	//마지막 노드의 왼쪽 노드의 rlink를 널로 초기화
	free(n);	//n 할당 해제

	return 0;
}

int insertFirst(headNode* h, int key) {	//list 처음에 key에 대한 노드하나를 추가

	listNode* node = (listNode*)malloc(sizeof(listNode));	//새로운 노드 메모리 할당
	node->key = key;	//새로운 노드에 key값 저장
	node->rlink = node->llink = NULL;	//새로운 노드의 링크 널로 초기화

	if(h->first == NULL)	//list가 비었을 경우
	{
		h->first = node;	//새로운 노드를 맨 앞에 추가
		return 1;
	}

	node->rlink = h->first;	//새로운 노드의 rlink을 원래 첫번째 노드와 연결
	node->llink = NULL;		//새로운 노드의 llink 널로 초기화

	listNode *p = h->first;	//p를 첫번째 노드로 초기화
	p->llink = node;	//원래의 첫번째 노드의 llink에 새로운 노드 연결
	h->first = node;	//첫번째에 새로운 노드로 초기화

	return 0;
}

int deleteFirst(headNode* h) {	//list의 첫번째 노드 삭제

	if (h->first == NULL)	//list가 비었을 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->first;	//n을 첫번째 노드로 초기화
	h->first = n->rlink;	//n의 오른쪽 노드를 첫번째 노드로 설정

	free(n);	//n 메모리 해제

	return 0;
}

int invertList(headNode* h) {	//리스트의 링크를 역순으로 재 배치

	if(h->first == NULL) {	//list가 비었을 경우
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->first;	//n을 첫번째 노드로 초기화
	listNode *trail = NULL;	//trail을 널로 초기화
	listNode *middle = NULL;	//middle을 널로 초기화

	while(n != NULL){
		trail = middle;	
		middle = n;
		n = n->rlink;	//trail 다음 middle 다음 n
		middle->rlink = trail;	//middle의 rlink를 middle의 왼쪽 노드와 연결
		middle->llink = n;	//middle의 llink를 middle의 오른쪽 노드와 연결
	}

	h->first = middle;	//첫번째 노드를 middle로 초기화

	return 0;
}

/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));	//새로운 노드 메모리 할당
	node->key = key;	//새로운 노드에 key값 저장
	node->llink = node->rlink = NULL;	//새로운 노드의 링크 널로 초기화

	if (h->first == NULL)	//list가 비었을 경우
	{
		h->first = node;	//새로운 노드를 맨 앞에 추가
		return 0;
	}

	listNode* n = h->first;	//n을 첫번째 노드로 초기화

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) {
		if(n->key >= key) {	//입력받은 key보다 노드 값이 크거나 같은 경우
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) {	//그 노드가 첫번째 노드이면
				insertFirst(h, key);	//함수를 호출하여 첫 번째에 삽입
			} else { /* 중간이거나 마지막인 경우 */
				//n의 왼쪽 노드 -> 새로운 노드 -> n 노드
				node->rlink = n;	//새로운 노드의 rlink를 n과 연결
				node->llink = n->llink;	//새로운 노드의 llink를 n의 왼쪽 노드와 연결
				n->llink->rlink = node;	//n의 왼쪽 노드의 rlink를 새로운 노드와 연결
			}
			return 0;
		}

		n = n->rlink;	//오른쪽 노드로 이동
	}

	/* 마지막 노드까지 찾지 못한 경우, 마지막에 삽입 */
	insertLast(h, key);	//함수를 호출하여 마지막에 삽입
	return 0;
}

int deleteNode(headNode* h, int key) {	//list에서 key에 대한 노드 삭제

	if (h->first == NULL)	//list가 비었을 경우
	{
		printf("nothing to delete.\n");
		return 1;
	}

	listNode* n = h->first;	//삭제할 노드 n 선언 첫번째 노드로 초기화

	while(n != NULL) {
		if(n->key == key) {	//입력한 값과 데이터 값이 같을 경우 
			if(n == h->first) { /* 첫 노드째 노드 인경우 */
				deleteFirst(h);	//함수를 호출하여 첫 번째 노드 삭제
			} else if (n->rlink == NULL){ /* 마지막 노드인 경우 */
				deleteLast(h);	//함수를 호출하여 마지막 노드 삭제
			} else { /* 중간인 경우 */
				n->llink->rlink = n->rlink;	//삭제할 노드의 오른쪽 노드를 왼쪽노드의 rlink와 연결
				n->rlink->llink = n->llink;	//삭제할 노드의 왼쪽 노드를 오른쪽노드의 llink와 연결
				free(n);	//n 할당 해제
			}
			return 1;	//리턴 1
		}

		n = n->rlink;	//오른쪽 노드로 이동
	}

	/* 찾지 못 한경우 */
	printf("cannot find the node for key = %d\n", key);
	return 1;
}
