#include <stdio.h>

struct student {        //student 구조체 선언
    char lastName[13];  //char형 배열 선언  /* 13 bytes */
    int studentId;      //int형 변수 선언   /* 4 bytes */
    short grade;        //short형 변수 선언 /* 2 bytes */
};
int main()
{
    printf("[----- [김예경] [2021039010] -----]\n");
    struct student pst;                                         //student 타입의 pst 선언
    printf("size of student = %ld\n", sizeof(struct student));  //student 구조체의 크기 출력 (24bytes)
    printf("size of int = %ld\n", sizeof(int));                 //int형 크기 출력 (4bytes)
    printf("size of short = %ld\n", sizeof(short));             //short형 크기 출력 (2bytes)
    return 0;
}