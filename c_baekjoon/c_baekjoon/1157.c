#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char arr[1000000];
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
        'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    int index[26] = { 0 };
    int i = 0;
    scanf("%s", arr);

    while (arr[i]) {
        if (arr[i] >= 65 && arr[i] <= 96) {
            arr[i] += 32;
        }
        for (int j = 0; j < 26; j++) {
            if ((alphabet[j] == arr[i])) {
                index[j] += 1;
            }
        }
        i++;
    }
    int maxn = 0;
    int order;
    for (int j = 0; j < 26; j++) {
        if (maxn < index[j]) {
            maxn = index[j];
            order = j;
        }
    }
    int check = 0;
    for (int j = 0; j < 26; j++) {
        if (maxn == index[j]) {
            check++;
        }
    }
    if (check > 1) {
        printf("?");
    }
    else {
        printf("%c", alphabet[order]-32);
    }
    return 0;
}