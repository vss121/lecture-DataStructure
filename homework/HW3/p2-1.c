#include <stdio.h>

#define MAX_SIZE 100    //100�� MAX_SIZE�� ���� (��ũ��)

float sum(float [], int);   //sum ����� ���� �Լ� ����
float input[MAX_SIZE], answer;  //�������� float�� �迭 input, ���� answer ����
int i;  //�������� int�� ���� ����

void main(void)
{
    printf("[----- [�迹��] [2021039010] -----]\n");
    //0~99������ ���� �迭 input�� ���ʴ�� ����
    for(i=0; i < MAX_SIZE; i++) 
        input[i] = i;
    /* for checking call by reference */
    printf("address of input = %p\n", input);   //input�� �ּ� ���
    answer = sum(input, MAX_SIZE);              //input(�迭)�� ��� ������ ���� ���ؼ� answer�� ����
    printf("The sum is: %f\n", answer);         //answer�� �� ���
}
float sum(float list[], int n)  //�迭 ���ҵ��� ���� ���ϴ� �Լ�
{
    printf("value of list = %p\n", list);       //list(�迭)�� �ּ�
    printf("address of list = %p\n\n", &list);  //&list == list�� �ּ�
    int i;
    float tempsum = 0;  //tempsum�� 0���� �ʱ�ȭ
    for(i = 0; i < n; i++)  // 0 ~ n-1 ���� �ݺ��ϸ�
        tempsum += list[i]; // tempsum�� �����ؼ� ����
    return tempsum; //tempsum�� return��
}