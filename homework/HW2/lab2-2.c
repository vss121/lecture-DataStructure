#include <stdio.h>
int main()
{
    printf("[----- [김예경] [2021039010] -----]\n");
    int i;  //int형 변수 선언
    int *ptr; //단일 포인터 선언
    int **dptr;  //이중 포인터 선언
    i = 1234;  //변수 i를 1234로 초기화
    printf("[checking values before ptr = &i] \n");  //ptr를 초기화하기 전 값 확인
    printf("value of i == %d\n", i); //i의 값을 1234로 초기화했으므로 i=1234
    printf("address of i == %p\n", &i);  //i의 주소
    printf("value of ptr == %p\n", ptr);  //ptr의 값(자동으로 NULL으로 초기화됨)
    printf("address of ptr == %p\n", &ptr);  //ptr의 주소
    ptr = &i; /* ptr is now holding the address of i */ //ptr를 &i로 초기화
    printf("\n[checking values after ptr = &i] \n");  //ptr를 초기화한 후 값 확인
    printf("value of i == %d\n", i);  //i의 값 = 1234
    printf("address of i == %p\n", &i);  //i의 주소
    printf("value of ptr == %p\n", ptr);  //ptr의 값(=&i)(=변수i의 주소)
    printf("address of ptr == %p\n", &ptr);  //ptr의 주소
    printf("value of *ptr == %d\n", *ptr);  //*ptr(=ptr이 가리키고 있는 변수)(= i)의 값
    dptr = &ptr; /* dptr is now holding the address of ptr */  //dptr를 &ptr로 초기화
    printf("\n[checking values after dptr = &ptr] \n");  //dptr를 초기화한 후 값 확인
    printf("value of i == %d\n", i);  //i의 값 = 1234
    printf("address of i == %p\n", &i);  //i의 주소
    printf("value of ptr == %p\n", ptr);  //ptr의 값(=&i)(=변수i의 주소)
    printf("address of ptr == %p\n", &ptr);  //ptr의 주소
    printf("value of *ptr == %d\n", *ptr);  //*ptr(=ptr이 가리키고 있는 변수)(= i)의 값
    printf("value of dptr == %p\n", dptr);  //dptr(= &ptr)(= ptr의 주소)의 값
    printf("address of ptr == %p\n", &dptr);  //dptr의 주소
    printf("value of *dptr == %p\n", *dptr);  //*dptr(=dptr이 가리키고 있는 변수)(=ptr의 값)(=i의 주소)의 값
    printf("value of **dptr == %d\n", **dptr);  //**dptr(=*dptr(= ptr)이 가리키고 있는 변수)(= i)의 값
    *ptr = 7777; /* changing the value of *ptr */  //*ptr(ptr이 가리키는 변수의 값 = i의 값)을 7777로 초기화
    printf("\n[after *ptr = 7777] \n");  //*ptr=7777를 한 후
    printf("value of i == %d\n", i);  //i의 값(= *ptr)(= **dptr)(= 7777)
    printf("value of *ptr == %d\n", *ptr);  //i의 값(= *ptr)(= **dptr)(= 7777)
    printf("value of **dptr == %d\n", **dptr);  //i의 값(= *ptr)(= **dptr)(= 7777)
    **dptr = 8888; /* changing the value of **dptr */  //**dptr(=*dptr(= ptr)이 가리키고 있는 변수)(= i)의 값을 8888로 초기화
    printf("\n[after **dptr = 8888] \n");  //**dptr을 8888로 초기화한 후
    printf("value of i == %d\n", i);  //i의 값(= *ptr)(= **dptr)(= 8888)
    printf("value of *ptr == %d\n", *ptr);  //i의 값(= *ptr)(= **dptr)(= 8888)
    printf("value of **dptr == %d\n", **dptr);  //i의 값(= *ptr)(= **dptr)(= 8888)
    return 0;
}