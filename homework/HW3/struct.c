#include <stdio.h>

struct student1 {   //student1 구조체 선언
    char lastName;  //char형 변수
    int studentId;  //int형 변수
    char grade;     //char형 변수
};
typedef struct {    //typedef 사용한 student2 구조체 선언
    char lastName;  //char형 변수
    int studentId;  //int형 변수
    char grade;     //char형 변수
} student2;

    int main() {
    printf("[----- [김예경] [2021039010] -----]\n");
    struct student1 st1 = {'A', 100, 'A'};      //student1 타입의 st1 선언 및 초기화. struct 키워드를 붙여야 함(typedef 사용하지 않음)

    printf("st1.lastName = %c\n", st1.lastName);    //st1의 lastName 출력
    printf("st1.studentId = %d\n", st1.studentId);  //st1의 studentId 출력
    printf("st1.grade = %c\n", st1.grade);          //st1의 grade 출력

    student2 st2 = {'B', 200, 'B'};             //student2 타입의 st2 선언 및 초기화. struct 키워드 붙이지 않아도 됨(typedef 사용)

    printf("\nst2.lastName = %c\n", st2.lastName);  //st2의 lastName 출력
    printf("st2.studentId = %d\n", st2.studentId);  //st2의 studentId 출력
    printf("st2.grade = %c\n", st2.grade);          //st2의 grade 출력

    student2 st3;   //student2 타입의 st3 선언
    
    st3 = st2;      //st2를 st3에 대입 ("구조치환")

    printf("\nst3.lastName = %c\n", st3.lastName);  //st3의 lastName 출력
    printf("st3.studentId = %d\n", st3.studentId);  //st3의 studentId 출력
    printf("st3.grade = %c\n", st3.grade);          //st3의 grade 출력

    /*equality test*/ //전체 구조의 동등성 검사
    /*
    if(st3 == st2) //컴파일 오류
        printf("equal\n");
    else
        printf("not equal\n");
    */
    return 0;
}