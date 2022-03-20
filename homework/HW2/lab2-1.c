#include <stdio.h>
int main()
{
    printf("[----- [김예경] [2021039010] -----]\n");
    char charType;  //문자를 저장하는 char type의 변수 선언
    int integerType;  //정수를 저장하는 int type의 변수 선언
    float floatType;  //실수를 저장하는 float type의 변수 선언
    double doubleType;  //실수를 저장하는 double type의 변수 선언
    //sizeof(표현식)의 형식으로 변수의 크기를 구함.
    printf("Size of char: %ld byte\n",sizeof(charType));  //char형인 변수 charType의 크기는 1byte다
    printf("Size of int: %ld bytes\n",sizeof(integerType));  //int형인 변수 integerType의 크기는 4bytes다
    printf("Size of float: %ld bytes\n",sizeof(floatType));  //float형인 변수 floatType의 크기는 4bytes다
    printf("Size of double: %ld bytes\n",sizeof(doubleType));  //double형인 변수 doubleType의 크기는 8bytes다
    printf("-----------------------------------------\n");
    //sizeof(자료형)의 형식으로 자료형의 크기를 구함.
    printf("Size of char: %ld byte\n",sizeof(char));  //char 자료형의 크기는 1byte다
    printf("Size of int: %ld bytes\n",sizeof(int));  //int 자료형의 크기는 4bytes다
    printf("Size of float: %ld bytes\n",sizeof(float));  //float 자료형의 크기는 4bytes다
    printf("Size of double: %ld bytes\n",sizeof(double));  //double 자료형의 크기는 8bytes다
    printf("-----------------------------------------\n");
    //sizeof() 연산자로 포인터의 크기를 구함.
    printf("Size of char*: %ld byte\n",sizeof(char*));  //char형 변수를 가리키는 포인터(주소값)의 크기는 4bytes다
    printf("Size of int*: %ld bytes\n",sizeof(int*));  //int형 변수를 가리키는 포인터(주소값)의 크기는 4bytes다
    printf("Size of float*: %ld bytes\n",sizeof(float*));  //float형 변수를 가리키는 포인터(주소값)의 크기는 4bytes다
    printf("Size of double*: %ld bytes\n",sizeof(double*));  //double형 변수를 가리키는 포인터(주소값)의 크기는 4bytes다
    return 0;
}