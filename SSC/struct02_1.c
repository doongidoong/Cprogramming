#include <stdio.h>
#include <string.h>
// 구조체, 포인터 마음껏 가지고 놀기
struct TEST{
    int a;
    char *b;
    char c[30];

} ;
struct Pointertest{
    int num;
    int *numpointer;
};

int main(){
    struct TEST t1 = {8,"none","none2"}; //구조체 초기화 값
    struct TEST *pt; // 구조체 포인터
    pt = &t1;
    printf("%d %s %s\n", pt->a,pt->b,pt->c);
    pt->a=10;
    pt->b="string";
    strcpy(t1.c,"복사한 값");
    printf("%d %s %s\n", pt->a,pt->b,t1.c);
    
    int i=0;
    struct Pointertest p1;
    struct Pointertest *pp;
    pp= &p1;
    (*pp).num = 1;
    p1.numpointer = &i;
    printf("포인터 다루기 %d %d\n", p1.num, *(p1.numpointer));
    /*
  -> 가 * 보다 우선순위가 높으므로 먼저 해석하게 된다.
  *(p1.numpointer) => *((*pp).numpointer) => *pp.numpointer
   */
    *pp->numpointer = 2;
    printf("포인터 다루기 %d %d\n", p1.num, *((*pp).numpointer));
    
    
    // 구조체 복사
    struct TEST t2;
    t2 = t1;
    printf("구조체 복사: %d %s %s\n", t2.a,t2.b,t1.c);
    
    return 0;
}