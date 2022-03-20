#include <stdio.h>
int main()
{
    printf("[----- [�迹��] [2021039010] -----]\n");
    int i;  //int�� ���� ����
    int *ptr; //���� ������ ����
    int **dptr;  //���� ������ ����
    i = 1234;  //���� i�� 1234�� �ʱ�ȭ
    printf("[checking values before ptr = &i] \n");  //ptr�� �ʱ�ȭ�ϱ� �� �� Ȯ��
    printf("value of i == %d\n", i); //i�� ���� 1234�� �ʱ�ȭ�����Ƿ� i=1234
    printf("address of i == %p\n", &i);  //i�� �ּ�
    printf("value of ptr == %p\n", ptr);  //ptr�� ��(�ڵ����� NULL���� �ʱ�ȭ��)
    printf("address of ptr == %p\n", &ptr);  //ptr�� �ּ�
    ptr = &i; /* ptr is now holding the address of i */ //ptr�� &i�� �ʱ�ȭ
    printf("\n[checking values after ptr = &i] \n");  //ptr�� �ʱ�ȭ�� �� �� Ȯ��
    printf("value of i == %d\n", i);  //i�� �� = 1234
    printf("address of i == %p\n", &i);  //i�� �ּ�
    printf("value of ptr == %p\n", ptr);  //ptr�� ��(=&i)(=����i�� �ּ�)
    printf("address of ptr == %p\n", &ptr);  //ptr�� �ּ�
    printf("value of *ptr == %d\n", *ptr);  //*ptr(=ptr�� ����Ű�� �ִ� ����)(= i)�� ��
    dptr = &ptr; /* dptr is now holding the address of ptr */  //dptr�� &ptr�� �ʱ�ȭ
    printf("\n[checking values after dptr = &ptr] \n");  //dptr�� �ʱ�ȭ�� �� �� Ȯ��
    printf("value of i == %d\n", i);  //i�� �� = 1234
    printf("address of i == %p\n", &i);  //i�� �ּ�
    printf("value of ptr == %p\n", ptr);  //ptr�� ��(=&i)(=����i�� �ּ�)
    printf("address of ptr == %p\n", &ptr);  //ptr�� �ּ�
    printf("value of *ptr == %d\n", *ptr);  //*ptr(=ptr�� ����Ű�� �ִ� ����)(= i)�� ��
    printf("value of dptr == %p\n", dptr);  //dptr(= &ptr)(= ptr�� �ּ�)�� ��
    printf("address of ptr == %p\n", &dptr);  //dptr�� �ּ�
    printf("value of *dptr == %p\n", *dptr);  //*dptr(=dptr�� ����Ű�� �ִ� ����)(=ptr�� ��)(=i�� �ּ�)�� ��
    printf("value of **dptr == %d\n", **dptr);  //**dptr(=*dptr(= ptr)�� ����Ű�� �ִ� ����)(= i)�� ��
    *ptr = 7777; /* changing the value of *ptr */  //*ptr(ptr�� ����Ű�� ������ �� = i�� ��)�� 7777�� �ʱ�ȭ
    printf("\n[after *ptr = 7777] \n");  //*ptr=7777�� �� ��
    printf("value of i == %d\n", i);  //i�� ��(= *ptr)(= **dptr)(= 7777)
    printf("value of *ptr == %d\n", *ptr);  //i�� ��(= *ptr)(= **dptr)(= 7777)
    printf("value of **dptr == %d\n", **dptr);  //i�� ��(= *ptr)(= **dptr)(= 7777)
    **dptr = 8888; /* changing the value of **dptr */  //**dptr(=*dptr(= ptr)�� ����Ű�� �ִ� ����)(= i)�� ���� 8888�� �ʱ�ȭ
    printf("\n[after **dptr = 8888] \n");  //**dptr�� 8888�� �ʱ�ȭ�� ��
    printf("value of i == %d\n", i);  //i�� ��(= *ptr)(= **dptr)(= 8888)
    printf("value of *ptr == %d\n", *ptr);  //i�� ��(= *ptr)(= **dptr)(= 8888)
    printf("value of **dptr == %d\n", **dptr);  //i�� ��(= *ptr)(= **dptr)(= 8888)
    return 0;
}