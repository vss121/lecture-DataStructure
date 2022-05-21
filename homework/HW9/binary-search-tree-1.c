/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {	//연결 자료구조를 이용한 이진 트리
	int key;	//데이터 필드
	struct node *left;	//왼쪽 자식 노드와 연결
	struct node *right;	//오른쪽 자식 노드와 연결
} Node;

int initializeBST(Node** h);	//이진트리 초기화

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */
void freeNode(Node* ptr);	//노드 할당 해제 함수

int main()
{
	printf("[----- [김예경] [2021039010] -----]\n");
	char command;	//command 입력받을 변수 선언
	int key;	//key를 입력받을 변수 선언
	Node* head = NULL;	//head 선언 및 NULL로 초기화
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//명령어 입력받음

		switch(command) {	//switch-case로 command 판단할 조건문 이용
		case 'z': case 'Z':	//z 입력시
			initializeBST(&head);	//이진 탐색 트리 초기화(생성)
			break;
		case 'q': case 'Q':	//q 입력시
			freeBST(head);	//메모리 할당 해제
			break;
		case 'n': case 'N':	//n 입력시
			printf("Your Key = ");
			scanf("%d", &key);	//key 입력받고
			insert(head, key);	//노드 삽입
			break;
		case 'd': case 'D':	//d 입력시
			printf("Your Key = ");
			scanf("%d", &key);	//key 입력받고
			deleteLeafNode(head, key);	//노드 삭제
			break;
		case 'f': case 'F':	//f 입력시
			printf("Your Key = ");
			scanf("%d", &key);	//key 입력받고
			ptr = searchIterative(head, key);	//노드 탐색(Iterative)
			if(ptr != NULL)	//있다면
				printf("\n node [%d] found at %p\n", ptr->key, ptr);	//key값과 그 주소 출력
			else	//없다면
				printf("\n Cannot find the node [%d]\n", key);	//발견하지 못했다 출력
			break;
		case 's': case 'S':	//s 입력시
			printf("Your Key = ");
			scanf("%d", &key);		//key 입력받고
			ptr = searchRecursive(head->left, key);	//노드 탐색(Recursive)
			if(ptr != NULL)	//있다면
				printf("\n node [%d] found at %p\n", ptr->key, ptr);	//key값과 그 주소 출력
			else	//없다면
				printf("\n Cannot find the node [%d]\n", key);	//발견하지 못했다 출력
			break;

		case 'i': case 'I':	//i 입력시
			inorderTraversal(head->left);	//중위 순회
			break;
		case 'p': case 'P':	//p 입력시
			preorderTraversal(head->left);	//전위 순회
			break;
		case 't': case 'T':	//t 입력시
			postorderTraversal(head->left);	//후위 순회
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
	if(*h != NULL)	//트리가 비어있지 않다면
		freeBST(*h);	//할당된 노드 제거하기

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));	//헤드 노드 생성
	//헤드 노드 초기화
	(*h)->left = NULL;	
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}

void inorderTraversal(Node* ptr)	//중위 순회
{
	if(ptr) {	//ptr이 널이 아니면
		inorderTraversal(ptr->left);	//왼쪽 서브 트리 이동
		printf(" [%d] ", ptr->key);	//현재 노드 처리
		inorderTraversal(ptr->right);	//오른쪽 서브 트리 이동
	}
}

void preorderTraversal(Node* ptr)	//전위 순회
{
	if(ptr) {	//ptr이 널이 아니면
		printf(" [%d] ", ptr->key);	//현재 노드 처리
		preorderTraversal(ptr->left);	//왼쪽 서브 트리 이동
		preorderTraversal(ptr->right);	//오른쪽 서브 트리 이동
	}
}

void postorderTraversal(Node* ptr)	//후위 순회
{
	if(ptr) {	//ptr이 널이 아니면
		postorderTraversal(ptr->left);	//왼쪽 서브 트리 이동
		postorderTraversal(ptr->right);	//오른쪽 서브 트리 이동
		printf(" [%d] ", ptr->key);	//현재 노드 처리
	}
}

int insert(Node* head, int key)	//이진 탐색 트리의 노드 삽입
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

	Node* ptr = head->left;	//왼쪽 자식 노드를 가리키는 ptr 노드 생성

	Node* parentNode = NULL;	//parentNode 생성
	while(ptr != NULL) {	//ptr이 널이 아닐 동안

		if(ptr->key == key) return 1;	//입력한 key 값을 갖는 노드가 존재하면 1 리턴

		parentNode = ptr;	//parentNode를 ptr로 초기화

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

int deleteLeafNode(Node* head, int key)	//단말 노드 삭제
{	
	if (head == NULL) {	//헤드가 널이면
		printf("\n Nothing to delete!!\n");
		return -1;	//-1 리턴
	}

	if (head->left == NULL) {	//헤드의 왼쪽 자식노드가 널이면
		printf("\n Nothing to delete!!\n");
		return -1;	//-1 리턴
	}

	Node* ptr = head->left;	//왼쪽 자식노드 가리키는 ptr 선언

	Node* parentNode = head;	//head 가리키는 parent노드 선언

	while(ptr != NULL) {	//ptr이 널이 아닐 동안

		if(ptr->key == key) {	//ptr의 키값이 입력한 key값과 같다면
			if(ptr->left == NULL && ptr->right == NULL) {	//ptr의 왼쪽, 오른쪽 자식노드가 비어있다면(단말노드면)

				if(parentNode == head)	//parent노드가 head면
					head->left = NULL;	//왼쪽 자식 노드 널로 초기화

				if(parentNode->left == ptr)	//parent노드의 왼쪽 자식 노드가 ptr과 같다면
					parentNode->left = NULL;	//널로 초기화(삭제)
				else	//parent노드의 오른쪽 자식 노드가 ptr과 같다면
					parentNode->right = NULL;	//널로 초기화(삭제)

				free(ptr);	//ptr 할당 해제
			}
			else {	//ptr의 왼쪽이나 오른쪽 자식노드가 비어있지 않다면(단말노드가 아니면)
				printf("the node [%d] is not a leaf \n", ptr->key);	//key값이 단말노드가 아님을 출력
			}
			return 1;
		}

		parentNode = ptr;	//parent노드를 ptr로 초기화

		if(ptr->key < key)	//ptr의 키값이 입력한 key값 보다 작다면
			ptr = ptr->right;	//ptr을 오른쪽 자식노드로 이동
		else	//ptr의 키값이 입력한 key값 보다 크다면
			ptr = ptr->left;	//ptr을 왼쪽 자식노드로 이동
	}

	printf("Cannot find the node for key [%d]\n ", key);	//일치하는 key값이 없을 경우 출력

	return 1;
}

Node* searchRecursive(Node* ptr, int key)	//이진 탐색 트리의 노드 탐색(Recursive)
{
	if(ptr == NULL)	//ptr이 널이면
		return NULL;	//널 리턴

	if(ptr->key < key)	//ptr의 키값이 입력한 key값보다 작다면
		ptr = searchRecursive(ptr->right, key);	//오른쪽 자식노드로 이동하여 탐색함수 호출 
	else if(ptr->key > key)	//ptr의 키값이 입력한 key값보다 작다면
		ptr = searchRecursive(ptr->left, key);	//왼쪽 자식노드로 이동하여 탐색함수 호출

	return ptr;	//ptr의 키값이 입력한 key값과 같다면 ptr리턴
}

Node* searchIterative(Node* head, int key)	//이진 탐색 트리의 노드 탐색(Iterative)
{
	Node* ptr = head->left;	//왼쪽 자식노드 가리키는 ptr 선언

	while(ptr != NULL)	//ptr이 널이 아닐 동안
	{
		if(ptr->key == key)	//ptr의 키값이 입력한 key값과 같다면
			return ptr;	//ptr 리턴

		if(ptr->key < key) ptr = ptr->right;	//작다면 ptr을 오른쪽 자식노드로 이동
		else	//크거나 같다면
			ptr = ptr->left;	//ptr을 왼쪽 자식노드로 이동
	}

	return NULL;	//없으면 널 리턴
}

void freeNode(Node* ptr)	//한 노드 할당 해제
{
	if(ptr) {	//ptr이 널이 아니면
		freeNode(ptr->left);	//ptr의 왼쪽 자식노드 할당 해제
		freeNode(ptr->right);	//ptr의 오른쪽 자식노드 할당 해제
		free(ptr);	//ptr 할당 해제
	}
}

int freeBST(Node* head)	//트리 할당 해제
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
