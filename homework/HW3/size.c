#include<stdio.h>
#include<stdlib.h>
void main()
{
    int **x;    //���������� ����
    printf("[----- [�迹��] [2021039010] -----]\n");
    printf("sizeof(x) = %lu\n", sizeof(x));         // x�� �ּҸ� ����(���⼭�� 4byte)
    printf("sizeof(*x) = %lu\n", sizeof(*x));       // *x�� �ּҸ� ����(���⼭�� 4byte)
    printf("sizeof(**x) = %lu\n", sizeof(**x));     // **x�� int�� �� == 4byte
}