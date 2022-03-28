#include <stdio.h>
#include <stdlib.h>

void main()
{
    printf("[----- [�迹��] [2021039010] -----]\n");

    int list[5];  //int�� �迭 ����
    int *plist[5] = {NULL};  //int�� ������ �迭 �����ϰ�, NULL�� �ʱ�ȭ�Ѵ�.

    plist[0] = (int *)malloc(sizeof(int));  //plist[0]�� 4byte int ũ���� ���� �޸� �Ҵ�

    list[0] = 1;    //list[0]�� 1 ����
    list[1] = 100;  //list[1]�� 100 ����

    *plist[0] = 200;    //*plist[0](plist[0]�� ����Ű�� �ִ� ��)�� 200 ����

    printf("value of list[0] = %d\n", list[0]);  //list[0]�� ���� 1�̴� (by line 13)
    printf("address of list[0] = %p\n", &list[0]);  //list[0]�� �ּ� == list�� �ּ�
    printf("value of list = %p\n", list);   //list == list�� �ּ� (�迭�� �̸��� �迭�� �ּ�)
    printf("address of list (&list) = %p\n", &list);    //list�� �ּ�(line19, 20, 21�� ���� ����)

    printf("----------------------------------------\n\n");
    printf("value of list[1] = %d\n", list[1]); //list[1]�� ���� 100�̴� (by line14)
    printf("address of list[1] = %p\n", &list[1]);  //list[1]�� �ּ� == list�� �ּ� + 4byte(int�� ũ�� ��ŭ)
    printf("value of *(list+1) = %d\n", *(list + 1));   //*(list+1) == (list+1)�� ����Ű�� �� == list[1] == 100
    printf("address of list+1 = %p\n", list+1); //list+1 == list[1]�� �ּ� (line25�� ����)

    printf("----------------------------------------\n\n");
    printf("value of *plist[0] = %d\n", *plist[0]); //*plist[0]�� ���� 200�̴� (by line16)
    printf("&plist[0] = %p\n", &plist[0]);  //&plist[0] == plist[0]�� �ּ� (line9���� ����� ������ �迭�� �ּ�)
    printf("&plist = %p\n", &plist);        //&plist == &plist[0]
    printf("plist = %p\n", plist);          //plist == &plist == &plist[0] (line 31, 32, 33�� ���� ����.)
    printf("plist[0] = %p\n", plist[0]);    //plist[0] == line11���� �������� �Ҵ�� ������ �ּҰ�
    printf("plist[1] = %p\n", plist[1]);    //plist[1] ==  NULL (by line9)
    printf("plist[2] = %p\n", plist[2]);    //plist[2] ==  NULL (by line9)
    printf("plist[3] = %p\n", plist[3]);    //plist[3] ==  NULL (by line9)
    printf("plist[4] = %p\n", plist[4]);    //plist[4] ==  NULL (by line9)
    free(plist[0]); //heap ������ �Ҵ�� �޸𸮸� ������Ų��
}