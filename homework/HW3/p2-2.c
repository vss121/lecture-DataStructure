#include <stdio.h>

void print1 (int *ptr, int rows);   //print1 사용자 정의 함수

int main()
{
    printf("[----- [김예경] [2021039010] -----]\n");
    int one[] = {0, 1, 2, 3, 4};    //int형 배열 선언
    printf("one = %p\n", one);      //one == &one == &one[0]
    printf("&one = %p\n", &one);    //one == &one == &one[0]
    printf("&one[0] = %p\n", &one[0]);  //one == &one == &one[0]
    printf("\n");

    print1(&one[0], 5); //one의 각 원소들의 주소값과 값 출력하는 함수 실행

    return 0;
}

void print1 (int *ptr, int rows)
{/* print out a one-dimensional array using a pointer */
    int i;
    printf ("Address \t Contents\n"); 
    for (i = 0; i < rows; i++)  //0 ~ rows-1까지 반복하며
        printf("%p \t %5d\n", ptr + i, *(ptr + i)); // (ptr+i)와 *(ptr+i)출력
    printf("\n");
}