#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE			13	/* prime number */
#define MAX_HASH_TABLE_SIZE 	MAX_ARRAY_SIZE

/* 필요에 따라 함수 추가 가능 */
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);
/* recursive function으로 구현 */
int quickSort(int *a, int n);


/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);

/* array a에대 한 hash table을 만든다. */
int hashing(int *a, int **ht);

/* hash table에서 key를 찾아 hash table의 index return */
int search(int *ht, int key);


int main()
{
	char command;	//command 입력받을 변수 선언
	int *array = NULL;	//배열 포인터
	int *hashtable = NULL;	//해시테이블 가리키는 포인터
	int key = -1;	//입력받을 key값
	int index = -1;
	printf("[----- [김예경] [2021039010] -----]\n");
	srand(time(NULL));

	do{
		printf("----------------------------------------------------------------\n");
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&array);	//초기화
			break;
		case 'q': case 'Q':
			freeArray(array);	//할당 해제
			break;
		case 's': case 'S':
			selectionSort(array);	//선택 정렬
			break;
		case 'i': case 'I':
			insertionSort(array);	//삽입 정렬
			break;
		case 'b': case 'B':
			bubbleSort(array);	//버블 정렬
			break;
		case 'l': case 'L':
			shellSort(array);	//셸 정렬
			break;
		case 'k': case 'K':
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);	//정렬 전
			quickSort(array, MAX_ARRAY_SIZE);	//퀵 정렬
			printf("----------------------------------------------------------------\n");
			printArray(array);	//정렬 후

			break;

		case 'h': case 'H':
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);	//해싱 전
			hashing(array, &hashtable);	//해싱
			printArray(hashtable);	//해싱 후
			break;

		case 'e': case 'E':
			printf("Your Key = ");
			scanf("%d", &key);	//key 입력받고
			printArray(hashtable);	//해시테이블 출력
			index = search(hashtable, key);	//해시테이블에서 탐색
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);	//결과 출력
			break;

		case 'p': case 'P':
			printArray(array);	//배열 출력
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initialize(int** a)	//초기화
{
	int *temp = NULL;

	/* array가 NULL인 경우 메모리 할당 */
	if(*a == NULL) {
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*a = temp;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else
		temp = *a;

	/* 랜덤값을 배열의 값으로 저장 */
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		temp[i] = rand() % MAX_ARRAY_SIZE;

	return 0;
}

int freeArray(int *a)	//메모리 할당 해제
{
	if(a != NULL)	//a가 널이 아니면
		free(a);	//a의 메모리 할당 해제
	return 0;
}

void printArray(int *a)	//배열 출력
{
	if (a == NULL) {	//a가 널이면
		printf("nothing to print.\n");	//출력할 수 없음
		return;
	}
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)	//0~MAX_ARRAY_SIZE만큼 반복하며
		printf("a[%02d] ", i);	//배열의 인덱스 출력
	printf("\n");
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)	//0~MAX_ARRAY_SIZE만큼 반복하며
		printf("%5d ", a[i]);	//배열의 값 출력
	printf("\n");
}


int selectionSort(int *a)	//선택정렬
{
	int min;	//최소값 저장할 변수
	int minindex;	//최소값 인덱스 저장할 변수
	int i, j;

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);	//정렬 전 배열 출력

	for (i = 0; i < MAX_ARRAY_SIZE; i++)	//0~MAX_ARRAY_SIZE만큼 반복하며
	{
		minindex = i;	//i를 최소값 인덱스로 저장
		min = a[i];		//a[i]를 최소값으로 저장
		for(j = i+1; j < MAX_ARRAY_SIZE; j++)	//i+1~MAX_ARRAY_SIZE만큼 반복하며
		{
			if (min > a[j])	//최소값이 정렬되지 않은 배열의 한 값보다 크다면
			{
				min = a[j];	//min값 수정
				minindex = j;	//minindex값 수정
			}
		}
		a[minindex] = a[i];	//최종으로 최소값 위치에 i값 넣고
		a[i] = min;	//i위치에 최소값 넣음
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);	//정렬 후 배열 출력
	return 0;
}

int insertionSort(int *a)	//삽입정렬
{
	int i, j, t;

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);	//정렬 전 배열 출력

	for(i = 1; i < MAX_ARRAY_SIZE; i++)	//1~MAX_ARRAY_SIZE만큼 반복하며
	{
		t = a[i];	//삽입할 원소
		j = i;	//인덱스 저장
		while (a[j-1] > t && j > 0)		//삽입할 원소가 배열의 값보다 작을 동안 반복
		{
			a[j] = a[j-1];	//오른쪽으로 한 칸 이동
			j--;	//인덱스 값 감소
		}
		a[j] = t;	//삽입할 자리에 t 넣기
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);	//정렬 후 배열 출력

	return 0;
}

int bubbleSort(int *a)	//버블 정렬
{
	int i, j, t;

	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);	//정렬 전 배열 출력

	for(i = 0; i < MAX_ARRAY_SIZE; i++)	//0~MAX_ARRAY_SIZE만큼 반복하며
	{
		for (j = 0; j < MAX_ARRAY_SIZE; j++)	//0~MAX_ARRAY_SIZE만큼 반복하며
		{
			if (a[j-1] > a[j])	//왼쪽이 오른쪽 보다 크면
			{	//둘의 값 바꾸기
				t = a[j-1];	
				a[j-1] = a[j];
				a[j] = t;
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);	//정렬 후 배열 출력

	return 0;
}

int shellSort(int *a)	//셸 정렬
{
	int i, j, k, h, v;

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);	//정렬 전 배열 출력

	for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2)	//h를 2씩 나누면서
	{
		for (i = 0; i < h; i++)	//0~h까지 반복하면서
		{
			for(j = i + h; j < MAX_ARRAY_SIZE; j += h)	//j가 MAX_ARRAY_SIZE될 때까지
			{
				v = a[j];	//v를 a[j]로 초기화
				k = j;	//k를 j로 초기화
				while (k > h-1 && a[k-h] > v)	//k가 h-1보다 크고 a[k-h]가 v보다 클 동안
				{
					a[k] = a[k-h];	//h만큼 감소
					k -= h;	//h만큼 감소
				}
				a[k] = v;	//a[k]를 v로 바꿈
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a);	//정렬 후 배열 출력

	return 0;
}

int quickSort(int *a, int n)	//퀵 정렬
{
	int v, t;
	int i, j;

	if (n > 1)	//n이 1보다 클 동안
	{
		v = a[n-1];	//v를 피봇으로 선언
		i = -1;
		j = n - 1;

		while(1)
		{
			while(a[++i] < v);	//피봇보다 작은 키 찾기
			while(a[--j] > v);	//피봇보다 큰 키 찾기

			if (i >= j) break;	//i가 j이상이면 반복문 탈출
			//a[i]와 a[j]값 교환
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		//a[i]와 a[n-1] 교환
		t = a[i];
		a[i] = a[n-1];
		a[n-1] = t;

		quickSort(a, i);	//왼쪽 부분집합을 정렬
		quickSort(a+i+1, n-i-1);	//오른쪽 부분집합을 정렬
	}


	return 0;
}

int hashCode(int key) {	//key를 MAX_HASH_TABLE_SIZE로 나눔 (제산)
   return key % MAX_HASH_TABLE_SIZE;
}

int hashing(int *a, int **ht)	//해싱하는 부분
{
	int *hashtable = NULL;	//해시테이블 생성

	/* hash table이 NULL인 경우 메모리 할당 */
	if(*ht == NULL) {
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*ht = hashtable;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else {
		hashtable = *ht;	/* hash table이 NULL이 아닌경우, table 재활용, reset to -1 */
	}

	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		hashtable[i] = -1;	//해시테이블 초기화

	int key = -1;	//키
	int hashcode = -1;	//해시코드
	int index = -1;	//인덱스
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)	//0~MAX_ARRAY_SIZE만큼 반복하며
	{
		key = a[i];	//a[i]를 key로 
		hashcode = hashCode(key);	//hashcode 저장

		if (hashtable[hashcode] == -1)	//비었다면
		{
			hashtable[hashcode] = key;	//해시테이블에 키 집어넣기
		} else 	{	//비어있지 않았다면

			index = hashcode;	//인덱스 저장

			while(hashtable[index] != -1)	//-1이 아닌 동안
			{
				index = (++index) % MAX_HASH_TABLE_SIZE;	//인덱스의 값을 증가시켜 테이블의 크기로 나누어 저장

			}
			hashtable[index] = key;		//해당 인덱스에 키 넣기
		}
	}

	return 0;
}

int search(int *ht, int key)	//탐색하는 부분
{
	int index = hashCode(key);	//인덱스에 key에 대한 hashCode 저장

	if(ht[index] == key)	//해당 키를 발견했으면
		return index;	//인덱스 리턴

	while(ht[++index] != key)	//인덱스를 변화시키면서 key 값이 나올 때까지
	{
		index = index % MAX_HASH_TABLE_SIZE;	//인덱스를 해시테이블 크기로 나눔
	}
	return index;	//인덱스 리턴
}


