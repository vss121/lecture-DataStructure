#include <stdio.h>
int main()
{
    printf("[----- [�迹��] [2021039010] -----]\n");
    char charType;  //���ڸ� �����ϴ� char type�� ���� ����
    int integerType;  //������ �����ϴ� int type�� ���� ����
    float floatType;  //�Ǽ��� �����ϴ� float type�� ���� ����
    double doubleType;  //�Ǽ��� �����ϴ� double type�� ���� ����
    //sizeof(ǥ����)�� �������� ������ ũ�⸦ ����.
    printf("Size of char: %ld byte\n",sizeof(charType));  //char���� ���� charType�� ũ��� 1byte��
    printf("Size of int: %ld bytes\n",sizeof(integerType));  //int���� ���� integerType�� ũ��� 4bytes��
    printf("Size of float: %ld bytes\n",sizeof(floatType));  //float���� ���� floatType�� ũ��� 4bytes��
    printf("Size of double: %ld bytes\n",sizeof(doubleType));  //double���� ���� doubleType�� ũ��� 8bytes��
    printf("-----------------------------------------\n");
    //sizeof(�ڷ���)�� �������� �ڷ����� ũ�⸦ ����.
    printf("Size of char: %ld byte\n",sizeof(char));  //char �ڷ����� ũ��� 1byte��
    printf("Size of int: %ld bytes\n",sizeof(int));  //int �ڷ����� ũ��� 4bytes��
    printf("Size of float: %ld bytes\n",sizeof(float));  //float �ڷ����� ũ��� 4bytes��
    printf("Size of double: %ld bytes\n",sizeof(double));  //double �ڷ����� ũ��� 8bytes��
    printf("-----------------------------------------\n");
    //sizeof() �����ڷ� �������� ũ�⸦ ����.
    printf("Size of char*: %ld byte\n",sizeof(char*));  //char�� ������ ����Ű�� ������(�ּҰ�)�� ũ��� 4bytes��
    printf("Size of int*: %ld bytes\n",sizeof(int*));  //int�� ������ ����Ű�� ������(�ּҰ�)�� ũ��� 4bytes��
    printf("Size of float*: %ld bytes\n",sizeof(float*));  //float�� ������ ����Ű�� ������(�ּҰ�)�� ũ��� 4bytes��
    printf("Size of double*: %ld bytes\n",sizeof(double*));  //double�� ������ ����Ű�� ������(�ּҰ�)�� ũ��� 4bytes��
    return 0;
}