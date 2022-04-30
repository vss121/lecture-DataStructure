#include <stdio.h>

int dat[1000005];
int pos = 0;

void push(int x){
    dat[pos++] = x;
}

void pop(){
    pos--;
}

int top(){
    return dat[pos-1];
}

void test(){
  push(5); push(4); push(3);
  printf("%d\n",top()) ; // 3
  pop(); pop();
  printf("%d\n",top()) ; // 5
  push(10); push(12);
  printf("%d\n",top()) ; // 12
  pop();
  printf("%d\n",top()) ; // 10
}

int main(void) {
	test();
}
