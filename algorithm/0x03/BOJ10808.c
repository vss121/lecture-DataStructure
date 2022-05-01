#include <stdio.h>
#include <string.h>

int main(void) {
    char str[105]; scanf("%s", str);
    int arr[26]={0};
    for(char i='a'; i<='z'; i++)
        for(int j=0; j<strlen(str); j++) 
            if(str[j]==i) arr[i-'a']++;
    for(int i=0; i<26; i++) printf("%d ", arr[i]);
}
