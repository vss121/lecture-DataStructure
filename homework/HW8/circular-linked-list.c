#include<stdio.h>
#include<stdlib.h>

typedef struct Node {	//이중 연결리스트의 노드 구조
	int key;	//데이터 필드
	struct Node* llink;	//왼쪽 노드와 연결하는 llink
	struct Node* rlink;	//오른쪽 노드를 연결하는 rlink
} listNode;

/* 함수 리스트 */
int initialize(listNode** h);	//연결 리스트 초기화(생성)
int freeList(listNode* h);	//연결 리스트 메모리 해제
int insertLast(listNode* h, int key);	//리스트의 마지막에 노드 삽입
int deleteLast(listNode* h);	//list의 마지막 노드 삭제
int insertFirst(listNode* h, int key);	//list 처음에 key에 대한 노드하나를 추가
int deleteFirst(listNode* h);	//list의 첫번째 노드 삭제
int invertList(listNode* h);	//리스트의 링크를 역순으로 재배치

int insertNode(listNode* h, int key);	//입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입
int deleteNode(listNode* h, int key);	//list에서 key에 대한 노드 삭제

void printList(listNode* h);	//연결 리스트 출력

int main()
{
	char command;	//command 입력받을 변수 선언
	int key;	//key를 입력받을 변수 선언
	listNode* headnode=NULL;	//headnode를 NULL로 초기화
	printf("[----- [김예경] [2021039010] -----]\n");
	do{	//계속 반복
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
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
			initialize(&headnode);	//연결 리스트 초기화(생성)
			break;
		case 'p': case 'P':	//p 입력시
			printList(headnode);	//연결 리스트 출력
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
			freeList(headnode);	//연결 리스트 메모리 해제
			break;
		default:	//그 외 입력시
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');	//q를 입력하면 반복분을 빠져나감

	return 1;
}

int initialize(listNode** h) {	//연결 리스트 초기화(생성)

	if(*h != NULL)	//headNode가 NULL이 아니면
		freeList(*h);	//freeNode를 호출하여 할당된 메모리 모두 해제

	*h = (listNode*)malloc(sizeof(listNode));	//*h에 headNode에 대한 메모리를 할당하여 리턴
	(*h)->rlink = *h;	//오른쪽 이동해도 자기 자신을 가리킴
	(*h)->llink = *h;	//왼쪽 이동해도 자기 자신을 가리킴
	(*h)->key = -9999;	//key값 -9999로 초기화
	return 1;
}

/* 메모리 해제 */
int freeList(listNode* h){
	if(h->rlink==h) {	//오른쪽 이동해도 자기 자신이면(노드하나)
		free(h);	//할당 해제
		return 1;
	}

	listNode* p = h->rlink;	//h 오른쪽에 p 연결

	listNode* prev = NULL;	//prev
	while(p != NULL && p != h) {	//p가 널이 아니고 h가 아닐 때
		prev = p;	//prev에 p대입
		p = p->rlink;	//p를 오른쪽으로 이동
		free(prev);	//prev의 메모리 해제
	}
	free(h);	//headnode 할당 해제
	return 0;
}

void printList(listNode* h) {	//연결 리스트 출력
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {	//리스트 없을 때
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink;	//h의 오른쪽에 p 연결

	while(p != NULL && p != h) {	//p가 널이 아니고 headnode가 아닐 때
		printf("[ [%d]=%d ] ", i, p->key);	//인덱스의 값과 그 key값 출력
		p = p->rlink;	//오른쪽 노드로 이동
		i++;
	}
	printf("  items = %d\n", i);

	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);	
	//headnode의 왼쪽과 연결된 노드, 헤드노드, 오른쪽과 연결된 노드 주소 출력

	i = 0;
	p = h->rlink;	//첫번째 노드
	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		//인덱스값, key값, llink값, node값, rlink값 출력
		p = p->rlink;	//오른쪽으로 이동
		i++;
	}

}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(listNode* h, int key) {	//리스트의 마지막에 노드 삽입

	if (h == NULL) return -1;	//리스트 없을 때

	listNode* node = (listNode*)malloc(sizeof(listNode));	//새로운 노드 메모리 할당
	node->key = key;	//새로운 노드에 key값 저장
	node->rlink = NULL;	//새로운 노드의 rlink 널로 초기화
	node->llink = NULL;	//새로운 노드의 llink 널로 초기화

	if (h->rlink == h) /*  */
	{	//리스트가 비었을 경우 첫 노드로 삽입
		h->rlink = node;	//h의 rlink에 node 연결
		h->llink = node;	//h의 lllink에 node 연결
		node->rlink = h;	//node의 rlink에 h 연결
		node->llink = h;	//node의 llink에 h 연결
	} else {	//리스트가 비어있지 않을 경우
		h->llink->rlink = node;	//마지막노드의 rlink에 node 연결
		node->llink = h->llink;	//node의 llink에 마지막노드 연결
		h->llink = node;	//마지막노드를 node로
		node->rlink = h;	//node의 rlink에 h 연결
	}

	return 1;
}

int deleteLast(listNode* h) {	//list의 마지막 노드 삭제

	if (h == NULL || h->llink ==h) {	//리스트 없거나 비어있을 때 
		printf("nothing to delete.\n");
		return 1;
	}
	listNode* nodetoremove = h->llink;	//list의 마지막 노드 
	nodetoremove->llink->rlink = h;	//뒤에서 두번째 노드의 rlink를 h와 연결
	h->llink = nodetoremove->llink;	//h의 llink를 뒤에서 두 번째 노드와 연결
	free(nodetoremove);	//할당해제
	return 1;
}

int insertFirst(listNode* h, int key) {	//list 처음에 key에 대한 노드하나를 추가

	listNode* node = (listNode*)malloc(sizeof(listNode));	//새로운 노드 메모리 할당
	node->key = key;	//새로운 노드에 key값 저장
	node->rlink = NULL;	//새로운 노드의 rlink 널로 초기화
	node->llink = NULL;	//새로운 노드의 llink 널로 초기화

	node->rlink = h->rlink;	// node의 rlink를 첫번째노드와 연결
	h->rlink->llink = node;	//첫번째노드의 llink를 node와 연결
	node->llink = h;	//node의 llink를 h와 연결
	h->rlink = node;	//h의 rlink를 노드와 연결
	return 1;
}

int deleteFirst(listNode* h) {	//list의 첫번째 노드 삭제

	if(h == NULL || h->rlink == h) {	//리스트 없거나 비어있을 때
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* nodetoremove = h->rlink;	//list의 첫번째 노드

	nodetoremove->rlink->llink = h;	//두번째 노드의 llink를 h와 연결
	h->rlink = nodetoremove->rlink;	//h의 rlink를 두 번째 노드와 연결
	free(nodetoremove);	//할당해제

	return 1;
}

int invertList(listNode* h) {	//리스트의 링크를 역순으로 재 배치

	if(h->rlink == h || h == NULL) {	//리스트 없거나 비어있을 때
		printf("nothing to invert...\n");
		return 0;
	}

	listNode *n = h->rlink;	//n을 첫번째 노드로 초기화
	listNode *trail = h;	//trail을 헤드노드로 초기화
	listNode *middle = h;	//trail을 헤드노드로 초기화

	/* 최종 바뀔 링크 유지 */
	h->llink = h->rlink;	

	while(n != NULL && n != h){	//n이 널이 아니고 headnode가 아닐 동안
		trail = middle;
		middle = n;
		n = n->rlink;	//trail 다음 middle 다음 n
		middle->rlink = trail;	//middle의 rlink를 middle의 왼쪽 노드와 연결
		middle->llink = n;	//middle의 llink를 middle의 오른쪽 노드와 연결
	}

	h->rlink = middle;	//첫번째 노드를 middle로 초기화
	return 0;
}

/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(listNode* h, int key) {
	if(h == NULL) return -1;	//리스트 없을 경우

	listNode* node = (listNode*)malloc(sizeof(listNode));	//새로운 노드 메모리 할당
	node->key = key;	//새로운 노드에 key값 저장
	node->rlink = NULL;	//새로운 노드의 rlink 널로 초기화
	node->llink = NULL;	//새로운 노드의 llink 널로 초기화

	if (h->rlink == h)	//비어있을 때
	{
		insertFirst(h, key);
		return 1;
	}

	listNode* n = h->rlink;	//첫번째 노드

	while(n != NULL && n != h) {	//n이 널이 아니고 headnode가 아닐 동안
		if(n->key >= key) {	//n의 key값이 입력받은 값 이상이면
			if(n == h->rlink) {	//첫 노드 앞쪽에 삽입해야할 경우
				insertFirst(h, key);
			} else { /* 중간이거나 마지막인 경우 */
				node->rlink = n;	// node의 rlink를 n노드와 연결
				node->llink = n->llink;	// node의 llink를 n 왼쪽 노드와 연결
				n->llink->rlink = node;	//n 왼쪽 노드의 rlink를 node와 연결
				n->llink = node;	//n의 llink를 node와 연결
			}
			return 0;
		}
		n = n->rlink; //오른쪽으로 이동
	}
	/* 마지막 노드까지 찾지 못한 경우, 마지막에 삽입 */
	insertLast(h, key);
	return 0;
}

int deleteNode(listNode* h, int key) {	//list에서 key에 대한 노드 삭제

	if(h->rlink==h || h == NULL) {	//리스트 없거나 비어있을 때
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->rlink;	//첫번째 노드

	while(n != NULL && n != h) {
		if(n->key == key) {	//key값이 같을 때
			if(n == h->rlink) /* 첫 노드째 노드인 경우 */
				deleteFirst(h);
			else if (n->rlink == h) {	/* 마지막 노드인 경우 */
				deleteLast(h);
			}
			else {	/* 중간인 경우 */
				n->llink->rlink = n->rlink;	//n의 왼쪽노드의 rlink를 n의 오른쪽노드와 연결
				n->rlink->llink = n->llink;	//n의 오른쪽노드의 llink를 n의 왼쪽노드와 연결
				free(n);	//할당해제
			}
			return 0;
		}
		n = n->rlink; //오른쪽으로 이동
	}
	/* 찾지 못 한경우 */
	printf("cannot find the node for key = %d\n", key);
	return 0;
}
