#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char arr[100];
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 
        'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    int index[26] ;
    int i = 0;
    scanf("%s", arr);
    for (int j = 0; j < 26; j++) {
        index[j] = -1;
    }
   
    while (arr[i]) {
        for (int j = 0; j < 26; j++) {
            if ((alphabet[j] == arr[i])&&(index[j]==-1)){
                index[j] = i;
            }
        }
        i++;
    }
    for (int j = 0; j < 26; j++) {
        printf("%d ", index[j]);
    }

}