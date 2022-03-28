#include <stdio.h>

void print1 (int *ptr, int rows);   //print1 ����� ���� �Լ�

int main()
{
    printf("[----- [�迹��] [2021039010] -----]\n");
    int one[] = {0, 1, 2, 3, 4};    //int�� �迭 ����
    printf("one = %p\n", one);      //one == &one == &one[0]
    printf("&one = %p\n", &one);    //one == &one == &one[0]
    printf("&one[0] = %p\n", &one[0]);  //one == &one == &one[0]
    printf("\n");

    print1(&one[0], 5); //one�� �� ���ҵ��� �ּҰ��� �� ����ϴ� �Լ� ����

    return 0;
}

void print1 (int *ptr, int rows)
{/* print out a one-dimensional array using a pointer */
    int i;
    printf ("Address \t Contents\n"); 
    for (i = 0; i < rows; i++)  //0 ~ rows-1���� �ݺ��ϸ�
        printf("%p \t %5d\n", ptr + i, *(ptr + i)); // (ptr+i)�� *(ptr+i)���
    printf("\n");
}