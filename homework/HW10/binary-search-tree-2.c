/*
 * Binary Search Tree #2
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {	//이진트리의 노드
	int key;	//데이터 필드
	struct node *left;	//왼쪽 자식 노드와 연결
	struct node *right;	//오른쪽 자식 노드와 연결
} Node;

/* for stack */
#define MAX_STACK_SIZE		20
Node* stack[MAX_STACK_SIZE];	//스택 생성
int top = -1;	//top

Node* pop();	//스택의 삭제
void push(Node* aNode);	//스택의 삽입

/* for queue */
#define MAX_QUEUE_SIZE		20
Node* queue[MAX_QUEUE_SIZE];	//큐 생성
int front = -1;	//front
int rear = -1;	//rear

Node* deQueue();	//큐의 삭제
void enQueue(Node* aNode);	//큐의 삽입

int initializeBST(Node** h);	//BST 초기화

/* functions that you have to implement */
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

void printStack();	//스택 출력

int main()
{
	printf("[----- [김예경] [2021039010] -----]\n");
	char command;	//command 입력받을 변수 선언
	int key;	//key를 입력받을 변수 선언
	Node* head = NULL;	//head 선언 및 NULL로 초기화

	do{	
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//명령어 입력받음

		switch(command) {	//switch-case로 command 판단할 조건문 이용
		case 'z': case 'Z':	
			initializeBST(&head);	//이진 탐색 트리 초기화(생성)
			break;
		case 'q': case 'Q':
			freeBST(head);	//메모리 할당 해제
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);	//key 입력받고
			insert(head, key);	//노드 삽입
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);	//key 입력받고
			deleteNode(head, key);	//노드 삭제
			break;

		case 'r': case 'R':
			recursiveInorder(head->left);	
			break;
		case 't': case 'T':
			iterativeInorder(head->left);	//반복적 중위 순회
			break;

		case 'l': case 'L':
			levelOrder(head->left);	//레벨 순서 순회
			break;

		case 'p': case 'P':
			printStack();	//스택 출력
			break;

		default:	//그 외 입력시
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');	//q를 입력하면 반복분을 빠져나감

	return 1;
}

int initializeBST(Node** h) {	//이진 탐색 트리 초기화(생성)

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));	
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;

	top = -1;

	front = rear = -1;

	return 1;
}

void recursiveInorder(Node* ptr)	//recursive 중위순회(#BST-1)
{
	if(ptr) {	//ptr이 널이 아니면
		recursiveInorder(ptr->left);	//왼쪽 서브 트리 이동
		printf(" [%d] ", ptr->key);		//현재 노드 처리
		recursiveInorder(ptr->right);	//오른쪽 서브 트리 이동
	}
}

/**
 * textbook: p 224
 */
void iterativeInorder(Node* node)	//반복적 중위 순회
{
	for(;;)
	{
		for(; node; node = node->left)	//왼쪽 노드는 널 노드에 도달될 때까지
			push(node);	//스택에 삽입
		node = pop();	//스택에서 삭제

		if(!node) break;	//공백 스택이면 반복문 탈출
		printf(" [%d] ", node->key);	//삭제된 노드의 데이터 필드 출력
		node = node->right;	//오른쪽 자식노드로 이동
	}
}

/**
 * textbook: p 225
 */
void levelOrder(Node* ptr)	//레벨 순서 순회
{
	if(!ptr) return; // 공백트리이면

	enQueue(ptr);	//큐에 삽입

	for(;;)
	{
		ptr = deQueue();	//큐에서 삭제
		if(ptr) {
			printf(" [%d] ", ptr->key);	//삭제한 노드의 데이터 필드 출력

			if(ptr->left)	//왼쪽 자식 큐에 삽입
				enQueue(ptr->left);
			if(ptr->right)	//오른쪽 자식 큐에 삽입
				enQueue(ptr->right);
		}
		else	//ptr이 널이면
			break;

	}
}

int insert(Node* head, int key)	//이진 탐색 트리의 노드 삽입(#BST-1)
{
	Node* newNode = (Node*)malloc(sizeof(Node));	//새로운 노드 생성
	//새로운 노드 초기화
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	if (head->left == NULL) {	//head의 왼쪽 자식 노드가 널이면
		head->left = newNode;	//왼쪽에 새로운 노드 삽입
		return 1;
	}

	/* head->left is the root */
	Node* ptr = head->left;	//왼쪽 자식 노드를 가리키는 ptr 노드 생성

	Node* parentNode = NULL;	//parentNode 생성
	while(ptr != NULL) {	//ptr이 널이 아닐 동안

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;	//입력한 key 값을 갖는 노드가 존재하면 1 리턴

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;	//parentNode를 ptr로 초기화

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)	//입력한 key 값보다 ptr의 키 값이 더 작으면
			ptr = ptr->right;	//ptr을 오른쪽으로 이동
		else	//크거나 같으면
			ptr = ptr->left;	//ptr을 왼쪽으로 이동
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)	//parent노드의 키값이 입력한 key값보다 크면
		parentNode->left = newNode;	//왼쪽 자식노드에 새로운 노드 삽입
	else	//작거나 같으면
		parentNode->right = newNode;	//오른쪽 자식노드에 새로운 노드 삽입
	return 1;
}

int deleteNode(Node* head, int key)
{

	if (head == NULL) {	//헤드가 널이면
		printf("\n Nothing to delete!!\n");
		return -1;	//-1 리턴
	}

	if (head->left == NULL) {	//헤드의 왼쪽 자식노드가 널이면
		printf("\n Nothing to delete!!\n");
		return -1;	//-1 리턴
	}

	/* head->left is the root */
	Node* root = head->left;	//root노드
	Node* parent = NULL;	//parent노드
	Node* ptr = root;	//ptr노드

	//key 탐색
	while((ptr != NULL)&&(ptr->key != key)) {	
		if(ptr->key != key) {

			parent = ptr;	//parent 저장

			if(ptr->key > key)	//ptr의 키값이 입력한 key값 보다 크다면
				ptr = ptr->left;	//ptr을 왼쪽 자식노드로 이동
			else	//작거나 같다면
				ptr = ptr->right;	//ptr을 오른쪽 자식노드로 이동
		}
	}

	//key가 없다면
	if(ptr == NULL)
	{
		printf("No node for key [%d]\n ", key);
		return -1;
	}

	//case 1: 단말노드일 때
	if(ptr->left == NULL && ptr->right == NULL)	//ptr의 왼쪽, 오른쪽 자식노드가 비어있다면(단말노드면)
	{
		if(parent != NULL) { //root가 아닐 경우
			if(parent->left == ptr)	// 왼쪽 자식 노드가 ptr과 같다면
				parent->left = NULL;	//왼쪽 자식 노드를 널로 초기화(삭제)
			else	// 오른쪽 자식 노드가 ptr과 같다면
				parent->right = NULL;	//오른쪽 자식 노드를 널로 초기화(삭제)
		} else {	//root 일경우
			head->left = NULL;	
		}
		free(ptr);	//ptr 할당 해제
		return 1;
	}

	//case 2: 자식노드가 하나 있을 때
	if(ptr->left == NULL || ptr->right == NULL)	//자식노드가 하나 있을 때
	{
		Node* child;	//child 노드 생성
		if (ptr->left != NULL)	//왼쪽 자식 노드일 경우
			child = ptr->left;	//child 저장
		else	//오른쪽 자식 노드일 경우
			child = ptr->right;	//child 저장

		if(parent != NULL)	//root가 아닐 경우
		{
			if(parent->left == ptr)	//왼쪽 자식 노드일 경우
				parent->left = child;	//왼쪽에 child로 연결
			else	//오른쪽 자식 노드일 경우
				parent->right = child;	//오른쪽에 child로 연결
		} else {	//삭제되는 게 root 일경우
			root = child;	//root에 child로 연결
		}

		free(ptr);	//ptr 할당 해제
		return 1;
	}

	//case 3: ptr의 자식노드가 둘 있을 때, ptr의 오른쪽 서브트리의 작은 후손을 연결
	Node* candidate;	//후보자 노드 생성
	parent = ptr;

	candidate = ptr->right;	//ptr의 오른쪽 자식 노드

	while(candidate->left != NULL)	//ptr의 오른쪽 자식 노드의 왼쪽 자식이 널이 아닐 때까지
	{	//ptr의 오른쪽 서브트리의 가장 깊은 왼쪽 노드에 도달할 때까지
		parent = candidate;	//candidate의 parent 노드
		candidate = candidate->left;	//왼쪽 자식으로 이동
	}

	if (parent->right == candidate)	//candidate가 바로 위 노드의 오른쪽 자식일 경우
		parent->right = candidate->right;	//위 노드의 오른쪽 자식에 candidate의 오른쪽 자식 연결
	else	//candidate가 바로 위 노드의 왼쪽 자식일 경우
		parent->left = candidate->right;	//위 노드의 왼쪽 자식에 candidate의 오른쪽 자식 연결(왼쪽 끝이라 왼쪽은 없음)

	ptr->key = candidate->key;	//ptr의 key를 candidate의 key값으로 변경

	free(candidate);	//candidate 할당 해제
	return 1;
}

void freeNode(Node* ptr)	//노드의 할당 해제(#BST-1)
{
	if(ptr) {	//ptr이 널이 아니면
		freeNode(ptr->left);	//ptr의	 왼쪽 자식노드 할당 해제
		freeNode(ptr->right);	//ptr의 오른쪽 자식노드 할당 해제
		free(ptr);	//ptr 할당 해제
	}
}

int freeBST(Node* head)	//트리 할당 해제(#BST-1)
{

	if(head->left == head)	//트리가 비었으면
	{
		free(head);	//head 할당 해제
		return 1;
	}

	Node* p = head->left;	//왼쪽 자식노드 가리키는 p 선언

	freeNode(p);	//p노드 할당 해제

	free(head);	//head 할당 해제
	return 1;
}

Node* pop()
{
	if (top<0) return NULL;	//비었을 경우
	return stack[top--];	//스택에서 삭제 후 그 노드 리턴
}

void push(Node* aNode)
{
	stack[++top] = aNode;	//스택에 삽입
}

Node* deQueue()
{
	if (front == rear) {	//비어있을 경우
		return NULL;
	}

	front = (front + 1) % MAX_QUEUE_SIZE;	//큐에서 삭제
	return queue[front];	//삭제된 노드 리턴
}

void enQueue(Node* aNode)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;	//rear값 증가
	if (front == rear) {	//가득 찼을 경우
		printf("\n....Now Queue is full!!\n");
		return;
	}

	queue[rear] = aNode;	//삽입
}

void printStack()
{
	int i = 0;
	printf("--- stack ---\n");
	while(i <= top)	//스택 끝까지
	{
		printf("stack[%d] = %d\n", i, stack[i]->key);	//idx와 key값 출력
	}
}
