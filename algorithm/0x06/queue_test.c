#include <stdio.h>

int dat[1000005];
int head = 0, tail = 0;

void push(int x){
    dat[tail++] = x;
}

void pop(){
    head++;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}

void test(){
  push(10); push(20); push(30);
  printf("%d\n", front()); // 10
  printf("%d\n", back()); // 30
  pop(); pop();
  push(15); push(25);
  printf("%d\n", front()); // 30
  printf("%d\n", back()); // 25
}

int main(void) {
  test();  
}
