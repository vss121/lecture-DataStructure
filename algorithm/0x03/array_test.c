#include <stdio.h>

void insert(int idx, int num, int arr[], int len){
    for(int i=len; i>idx; i--) arr[i] = arr[i-1];
    arr[idx] = num;
}

void erase(int idx, int arr[], int len){
    for(int i=idx; i<len-1; i++) arr[i] = arr[i+1];
}

void printArr(int arr[], int len){
  for(int i = 0; i < len; i++) printf("%d ", arr[i]);
  printf("\n\n");
}

void insert_test(){
  printf("***** insert_test *****\n");
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); len++;// 10 20 30 40
  printArr(arr, len);
  insert(1, 50, arr, len); len++; // 10 50 20 30 40
  printArr(arr, len);
  insert(0, 15, arr, len); len++;// 15 10 50 20 30 40
  printArr(arr, len);
}

void erase_test(){
  printf("***** erase_test *****\n");
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); len--;// 10 50 40 30 20
  printArr(arr, len);
  erase(1, arr, len); len--;// 10 40 30 20
  printArr(arr, len);
  erase(3, arr, len); len--;// 10 40 30
  printArr(arr, len);
}

int main(void) {
  insert_test();
  erase_test();
}
