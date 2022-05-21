#include <stdio.h>
#include <stdlib.h>		//malloc() 이용

#define MAX_QUEUE_SIZE 4	//큐의 크기를 4로 정의

typedef char element;	//char형인 element(원소) 정의
typedef struct {		//QueueType(구조체)로 queue(배열), front, rear 묶음
	element queue[MAX_QUEUE_SIZE];	//1차원 배열 queue 선언
	int front, rear;				//정수형인 front, rear 선언
}QueueType;

QueueType *createQueue();	//원형 큐 생성
int freeQueue(QueueType *cQ);	//원형 큐 동적 메모리 할당 해제
int isEmpty(QueueType *cQ);	//원형 큐가 공백인지 확인
int isFull(QueueType *cQ);	//원형 큐가 가득 차있는지 확인
void enQueue(QueueType *cQ, element item);	//원형 큐에 원소 삽입
void deQueue(QueueType *cQ, element* item);	//원형 큐에 원소 삭제
void printQ(QueueType *cQ);	//원형 큐에 들어가 있는 원소 출력
void debugQ(QueueType *cQ);	//원형 큐 디버그
element getElement();		//원형 큐의 원소 얻기

int main(void)
{
	printf("[----- [김예경] [2021039010] -----]");
	QueueType *cQ = createQueue();	//QueueType형인 포인터 변수 cQ를 선언
	element data;					//element(char)형인 data 선언
	char command;					//명령어 저장할 변수 command 선언

	do{	//계속 반복
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);		//명령어를 입력받음

		switch(command) {		//switch문을 이용해 조건 판단
		case 'i': case 'I':		//i나 I를 입력했을 경우
			data = getElement();	//data에 getElement()로 원소를 입력받음
			enQueue(cQ, data);		//원형 큐(cQ)에 원소(data) 삽입
			break;
		case 'd': case 'D':		//d나 D를 입력했을 경우
			deQueue(cQ, &data);		//원형 큐(cQ)에 원소(data) 삭제
			break;
		case 'p': case 'P':		//p나 P를 입력했을 경우
			printQ(cQ);				//cQ를 출력
			break;
		case 'b': case 'B':		//b나 B를 입력했을 경우
			debugQ(cQ);				//cQ를 디버그
			break;
		case 'q': case 'Q':		//q나 Q를 입력했을 경우
   	        freeQueue(cQ);			//cQ 동적 메모리 할당 해제
			break;
		default:				//그 외의 것을 입력했을 경우
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");	//경고문구 출력
			break;
		}
	//q나 Q를 입력할 때까지 반복
	}while(command != 'q' && command != 'Q');

	return 1;
}
//원형 큐 생성
QueueType *createQueue()
{
	QueueType *cQ;		//QueueType형인 포인터 변수 cQ를 선언
	cQ = (QueueType *)malloc(sizeof(QueueType));	//QueueType의 크기만큼 cQ에 동적 메모리 할당
	cQ->front = 0;		//front의 초깃값을 0으로 설정
	cQ->rear = 0;		//rear의 초깃값을 0으로 설정
	return cQ;			//cQ 반환
}
//원형 큐 동적 메모리 할당 해제
int freeQueue(QueueType *cQ)
{
    if(cQ == NULL) return 1;	//cQ가 NULL일 경우 동적 할당 해제하지 않고 1 return
    free(cQ);	//cQ의 동적 할당 해제
    return 1;
}
//원형 큐의 원소 얻기
element getElement()
{
	element item;				//element(char)형인 item 선언
	printf("Input element = ");
	scanf(" %c", &item);		//item에 입력한 값 저장
	return item;				//item 반환
}

//원형 큐가 공백인지 확인
int isEmpty(QueueType *cQ)
{	
	if(cQ->front == cQ -> rear) {	//원형 큐가 비었을 경우 (front와 rear이 같은 위치일 경우)
		printf("원형큐가 비었습니다");
		return 1;					//1을 return
	}
	else return 0;					//원형 큐가 비어있지 않을 경우 0을 return
}

//원형 큐가 가득 차있는지 확인
int isFull(QueueType *cQ)
{
   if(cQ->front == ((cQ -> rear+1)%MAX_QUEUE_SIZE)) {	//원형 큐가 가득 차있을 경우(front와 ((rear+1)%크기)가 같은 위치일 경우)
		printf("원형큐가 가득 찼습니다");
		return 1;					//1을 return
	}
	else return 0;					//원형 큐가 가득 차있지 않을 경우 0을 return
}

//원형 큐에 원소 삽입
void enQueue(QueueType *cQ, element item)
{
	if (isFull(cQ)) return; //원형 큐가 가득 차있을 경우 삽입 중단
	else {	//원형 큐가 가득 차있지 않을 경우 삽입 연산 진행
		cQ->rear = (cQ->rear+1)%MAX_QUEUE_SIZE;	//rear을 한 칸 이동시킴
		cQ->queue[cQ->rear] = item;	//queue의 rear 위치에 item원소 삽입
	}
}

//원형 큐에 원소 삭제
void deQueue(QueueType *cQ, element *item)
{
	if(isEmpty(cQ)) return;		//원형 큐가 비었을 경우 삭제 연산 중단
	else {						//원형 큐가 비어있지 않을 경우 삭제 연산 진행
		cQ -> front = (cQ->front+1)%MAX_QUEUE_SIZE;	//front을 한 칸 이동시킴
		*item = cQ -> queue[cQ->front];	//*item에 삭제한 원소인 큐[front] 값 저장
		return;
	}
}

//원형 큐에 들어가 있는 원소 출력
void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;	//큐의 첫번째 원소의 위치
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;	//큐의 마지막 원소+1의 위치

	printf("Circular Queue : [");

	i = first;
	while(i != last){	//큐의 첫번째 원소에서 마지막 원소가 될때까지
		printf("%3c", cQ->queue[i]);	//큐의 원소를 출력
		i = (i+1)%MAX_QUEUE_SIZE;		//인덱스를 1씩 증가시킴

	}
	printf(" ]\n");
}

//원형 큐 디버그
void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)	//i=0 ~ 크기-1까지 반복하며
	{
		if(i == cQ->front) {	//i가 front의 위치이면 
			printf("  [%d] = front\n", i);	//front라 출력
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);	//그 외는 큐의 원소들을 출력

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);	//front, rear 출력
}
