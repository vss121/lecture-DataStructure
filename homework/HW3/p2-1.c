#include <stdio.h>

#define MAX_SIZE 100    //100을 MAX_SIZE로 정의 (매크로)

float sum(float [], int);   //sum 사용자 정의 함수 선언
float input[MAX_SIZE], answer;  //전역으로 float형 배열 input, 변수 answer 선언
int i;  //전역으로 int형 변수 선언

void main(void)
{
    printf("[----- [김예경] [2021039010] -----]\n");
    //0~99까지의 값을 배열 input에 차례대로 대입
    for(i=0; i < MAX_SIZE; i++) 
        input[i] = i;
    /* for checking call by reference */
    printf("address of input = %p\n", input);   //input의 주소 출력
    answer = sum(input, MAX_SIZE);              //input(배열)의 모든 원소의 합을 구해서 answer에 대입
    printf("The sum is: %f\n", answer);         //answer의 값 출력
}
float sum(float list[], int n)  //배열 원소들의 합을 구하는 함수
{
    printf("value of list = %p\n", list);       //list(배열)의 주소
    printf("address of list = %p\n\n", &list);  //&list == list의 주소
    int i;
    float tempsum = 0;  //tempsum을 0으로 초기화
    for(i = 0; i < n; i++)  // 0 ~ n-1 까지 반복하며
        tempsum += list[i]; // tempsum에 누적해서 더함
    return tempsum; //tempsum을 return함
}