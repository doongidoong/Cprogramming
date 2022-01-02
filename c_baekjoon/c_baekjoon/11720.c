#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char arr[100];
    int size;
    int num = 0;
    scanf("%d", &size);
    scanf("%s", arr);
    for (int i = 0; i < size; i++) {
        num += arr[i] - 48;
    }

    printf("%d", num);
    return 0;


}