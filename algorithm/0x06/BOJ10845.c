#include <stdio.h>
#include <string.h>

int dat[1000005];
int head = 0, tail = 0;

void push(int x){
    dat[tail++] = x;
}

void pop(){
    if (head==tail) printf("-1\n");
    else printf("%d\n", dat[head++]);
}
void size() {
    printf("%d\n", tail-head);
}
void empty() {
    if (head==tail) printf("1\n");
    else printf("0\n");
}
void front(){
    if (head==tail) printf("-1\n");
    else printf("%d\n", dat[head]);
}

void back(){
    if (head==tail) printf("-1\n");
    else printf("%d\n", dat[tail-1]);
}

int main(void) {
    int N; scanf("%d", &N);
    char que[10];
    for(int i=0; i<N; i++) {
        scanf("%s", &que);
        if (strcmp(que, "push") == 0) {
			int num;//문자 이후에 포함되어 있는 숫자
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(que, "pop") == 0) {
			pop();
		}
		else if (strcmp(que, "size") == 0) {
			size();
		}
		else if (strcmp(que, "empty") == 0) {
			empty();
		}
        else if (strcmp(que, "front") == 0) {
			front();
		}
        else if (strcmp(que, "back") == 0) {
			back();
		}
    }
}
