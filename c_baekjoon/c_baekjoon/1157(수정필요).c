#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char arr[100];
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
        'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    int index[26] = { 0 };
    int i = 0;
    scanf("%s", arr);
  
    while (arr[i]) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            arr[i] += 32;
        }
        for (int j = 0; j < 26; j++) {
            if ((alphabet[j] == arr[i])) {
                index[j] += 1 ;
            }
        }
        i++;
    }
    int maxn = 0;
    int j;
    for (j = 0; j < 26; j++) {
        if (maxn < index[j]) {
            index[j] = maxn;
        }
    }
    int count = 0;
    for (int k = 0; k < 26; k++) {
        if (maxn == index[k]) {
            count++;
        }
    }
    if (count > 1) {
        printf("?");
        return 0;
    }
    else { 
        printf("%c", alphabet[j - 1]);
        return 0; }
}