#include <stdio.h>
#include <string.h>

int dat[1000005];
int pos = -1;

void push(int x) {
    dat[++pos] = x;
}
void pop() {
    if (pos==-1) printf("-1\n");
    else printf("%d\n", dat[pos--]);
}
void top() {
    if (pos==-1) printf("-1\n");
    else printf("%d\n", dat[pos]);
}
void size() {
    printf("%d\n", pos+1);
}
void empty() {
    if (pos==-1) printf("1\n");
    else printf("0\n");
}

int main(void) {
	int N; scanf("%d", &N);
    char stack[10];
    for(int i=0; i<N; i++) {
        scanf("%s", &stack);
        if (strcmp(stack, "push") == 0) {
			int num;//문자 이후에 포함되어 있는 숫자
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(stack, "pop") == 0) {
			pop();
		}
		else if (strcmp(stack, "top") == 0) {
			top();
		}
		else if (strcmp(stack, "size") == 0) {
			size();
		}
		else if (strcmp(stack, "empty") == 0) {
			empty();
		}
    }
}
