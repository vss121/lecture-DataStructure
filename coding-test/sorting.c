#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 13

int selectionSort(int *arr)
{
	int min;
	int minidx;
	
	for(int i=0; i<MAX_ARRAY_SIZE; i++) {
		minidx = i;
		min = arr[i];	
		
		for(int j=i+1; j<MAX_ARRAY_SIZE; j++) {
			if(min > arr[j]) {
				min = arr[j];
				minidx = j;
			}
		}
		arr[minidx] = arr[i];	//위치
		arr[i] = min;
	}
}

int insertionSort(int *a)	//re
{
	int i, j, t;
	
	for(i=1; i<MAX_ARRAY_SIZE; i++) {
		t=a[i];
		j=i;
		while(a[j-1]>t && j>0)
		{
			a[j]=a[j-1];
			j--;
		}
		a[j] = t;
	}
	
}

int quickSort(int *a, int n) {	//re
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
}

int bubbleSort(int *a)	//버블 정렬
{
	int t;
	
	for(int i=0; i< MAX_ARRAY_SIZE; i++) {
		for(int j=0; j<MAX_ARRAY_SIZE-i-1; j++) {
			if(a[j]>a[j+1]) {
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			} 
		}
	}
}

int main() {
	
	srand(time(NULL));
	int *array = NULL;
	array = (int*)malloc(sizeof(int)*MAX_ARRAY_SIZE);
	
	for(int i=0; i< MAX_ARRAY_SIZE; i++) {	//initialize
		array[i] = rand() % MAX_ARRAY_SIZE;
	}
	
	for(int i=0; i< MAX_ARRAY_SIZE; i++) {	//print
		printf("%5d", array[i]);
	}
	printf("\n");
	
	//selectionSort(array);
	
	insertionSort(array);
	
	//bubbleSort(array);
	
	//quickSort(array, MAX_ARRAY_SIZE);
	
	for(int i=0; i< MAX_ARRAY_SIZE; i++) {	//print
		printf("%5d", array[i]);
	}
	
	free(array);
		
}
