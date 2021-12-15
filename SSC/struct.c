#include <stdio.h>
typedef struct { // 학생 구조체 정의
int a, b;
} test;


int main(){
    test st;
    test *ptr;
    ptr = &st;
    (*ptr).a = 1;
    (*ptr).b = 2;
    printf("%d %d",(*ptr).a,st.b);
    printf(" 잘나오는구나!");
    return 0;
}