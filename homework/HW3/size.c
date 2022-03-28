#include<stdio.h>
#include<stdlib.h>
void main()
{
    int **x;    //이중포인터 선언
    printf("[----- [김예경] [2021039010] -----]\n");
    printf("sizeof(x) = %lu\n", sizeof(x));         // x는 주소를 저장(여기서는 4byte)
    printf("sizeof(*x) = %lu\n", sizeof(*x));       // *x도 주소를 저장(여기서는 4byte)
    printf("sizeof(**x) = %lu\n", sizeof(**x));     // **x는 int형 값 == 4byte
}