#include <stdio.h>

int func1(int N) {  //O(N)
    int sum = 0;
    for(int i =1; i<=N; i++)
        if(i%3==0 || i%5==0) sum += i;
    return sum;    
}
int func2(int arr[], int N) { //O(N^2)
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if(arr[i] + arr[j]==100) return 1;
        }
    }
    return 0;
}
int func3(int N) {  //O(sqrt(N))
    for(int i=1; i*i<=N; i++) { //
        if(i*i == N) return 1;
    }
    return 0;
}
int func4(int N) {  //O(lgN)
    int i=1;
    while(i*2<=N) i*=2;
    return i; 
}
int main() {
   
}
