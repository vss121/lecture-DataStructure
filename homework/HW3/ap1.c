#include <stdio.h>
#include <stdlib.h>

void main()
{
    printf("[----- [김예경] [2021039010] -----]\n");

    int list[5];  //int형 배열 선언
    int *plist[5] = {NULL};  //int형 포인터 배열 선언하고, NULL로 초기화한다.

    plist[0] = (int *)malloc(sizeof(int));  //plist[0]에 4byte int 크기의 동적 메모리 할당

    list[0] = 1;    //list[0]에 1 대입
    list[1] = 100;  //list[1]에 100 대입

    *plist[0] = 200;    //*plist[0](plist[0]이 가리키고 있는 곳)에 200 대입

    printf("value of list[0] = %d\n", list[0]);  //list[0]의 값은 1이다 (by line 13)
    printf("address of list[0] = %p\n", &list[0]);  //list[0]의 주소 == list의 주소
    printf("value of list = %p\n", list);   //list == list의 주소 (배열의 이름은 배열의 주소)
    printf("address of list (&list) = %p\n", &list);    //list의 주소(line19, 20, 21이 서로 같다)

    printf("----------------------------------------\n\n");
    printf("value of list[1] = %d\n", list[1]); //list[1]의 값은 100이다 (by line14)
    printf("address of list[1] = %p\n", &list[1]);  //list[1]의 주소 == list의 주소 + 4byte(int형 크기 만큼)
    printf("value of *(list+1) = %d\n", *(list + 1));   //*(list+1) == (list+1)이 가리키는 값 == list[1] == 100
    printf("address of list+1 = %p\n", list+1); //list+1 == list[1]의 주소 (line25와 같다)

    printf("----------------------------------------\n\n");
    printf("value of *plist[0] = %d\n", *plist[0]); //*plist[0]의 값은 200이다 (by line16)
    printf("&plist[0] = %p\n", &plist[0]);  //&plist[0] == plist[0]의 주소 (line9에서 선언된 포인터 배열의 주소)
    printf("&plist = %p\n", &plist);        //&plist == &plist[0]
    printf("plist = %p\n", plist);          //plist == &plist == &plist[0] (line 31, 32, 33이 서로 같다.)
    printf("plist[0] = %p\n", plist[0]);    //plist[0] == line11에서 동적으로 할당된 공간의 주소값
    printf("plist[1] = %p\n", plist[1]);    //plist[1] ==  NULL (by line9)
    printf("plist[2] = %p\n", plist[2]);    //plist[2] ==  NULL (by line9)
    printf("plist[3] = %p\n", plist[3]);    //plist[3] ==  NULL (by line9)
    printf("plist[4] = %p\n", plist[4]);    //plist[4] ==  NULL (by line9)
    free(plist[0]); //heap 영역에 할당된 메모리를 해제시킨다
}