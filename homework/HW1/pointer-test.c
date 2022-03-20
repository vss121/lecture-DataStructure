#include <stdio.h>

int main() 
{
    int i, *p; //같은 타입의 변수 i와 포인터 p 선언

    i = 10; //i를 10으로 초기화

    printf("value of i = %d\n", i); //i의 값(=10) 출력
    printf("address of i = %p\n", &i);  //i의 주소값(&i)을 출력
    printf("value of p = %p\n", p); //포인터 p에 저장된 값 출력(자동으로 0으로 초기화됨)
    printf("address of p = %p\n", &p);  //포인터 p의 메모리 상 주소(&p) 출력

    p = &i; //포인터 p에 i의 주소를 대입하여 초기화

    printf("\n\n----- after p = &i ------------\n\n");

    printf("value of p = %p\n", p); //포인터 p의 값은 i의 주소값이다(p = &i)
    printf("address of p = %p\n", &p); //포인터 p의 메모리 상 주소(&p) 출력
    printf("dereferencing *p = %d\n", *p); //*p는 포인터 p가 가리키고 있는 주소에 저장된 값 i(=10)이다

    return 0;
}
