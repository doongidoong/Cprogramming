#include <stdio.h>
typedef struct { // �л� ����ü ����
int a, b;
} test;


int main(){
    test st;
    test *ptr;
    ptr = &st;
    (*ptr).a = 1;
    (*ptr).b = 2;
    printf("%d %d",(*ptr).a,st.b);
    printf(" �߳����±���!");
    return 0;
}