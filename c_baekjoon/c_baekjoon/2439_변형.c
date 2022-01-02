#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int star = 0;
    while (star < 10) {
        for (int i = 0; i < 9 - star; i++) {
            printf(" ");
        }
        for (int i = 0;  i < 1+2*star; i++) {
            printf("*");
        }
        star++;
        printf("\n");
    }
    star--;
    while (star > 0) {
        star--;
        for (int i = 0; i<9 - star; i++) {
            printf(" ");
        }
        for (int i = 0; i < 1 + 2 * star; i++) {
            printf("*");
        }
        
        printf("\n");
    }
   
    return 0;
}