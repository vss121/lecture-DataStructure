#include <stdio.h>

struct student {        //student ����ü ����
    char lastName[13];  //char�� �迭 ����  /* 13 bytes */
    int studentId;      //int�� ���� ����   /* 4 bytes */
    short grade;        //short�� ���� ���� /* 2 bytes */
};
int main()
{
    printf("[----- [�迹��] [2021039010] -----]\n");
    struct student pst;                                         //student Ÿ���� pst ����
    printf("size of student = %ld\n", sizeof(struct student));  //student ����ü�� ũ�� ��� (24bytes)
    printf("size of int = %ld\n", sizeof(int));                 //int�� ũ�� ��� (4bytes)
    printf("size of short = %ld\n", sizeof(short));             //short�� ũ�� ��� (2bytes)
    return 0;
}