#include <stdio.h>
#include <string.h>
#define MAX 1000005

int dat[MAX];
int head = 0, tail = 0;

void push(int x){
    dat[tail++] = x;
}

void pop(){
    if (head==tail) printf("없음\n");
    else head++;
}
int size() {
    return tail-head;
}
int empty() {
    if (head==tail) return 1;
    else return 0;
}
int front(){
    if (head==tail) printf("없음\n");
    else return dat[head];
}


int main(void) {
    int N; scanf("%d", &N); //카드개수
    for(int i=1; i<=N; i++) push(i);
    while(size()!= 1) {
        pop();
        int tmp = front();
        push(tmp);
        pop();
    }
    printf("%d", front());
}
