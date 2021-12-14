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
    struct TEST t1 = {8,"none","none2"};
    struct TEST *pt;
    pt = &t1;
    printf("%d %s %s\n", pt->a,pt->b,pt->c);
    pt->a=10;
    pt->b="string";
    printf("%d %s %s\n", pt->a,pt->b,t1.c);
    
    strcpy(t1.c,"복사한 값");
    printf("%d %s %s\n", pt->a,pt->b,t1.c);
    
    int i=0;
    struct Pointertest p1;
    struct Pointertest *pp;
    pp= &p1;
    (*pp).num = 1;
    p1.numpointer = &i;
    printf("%d %d\n", p1.num, *(p1.numpointer));
  
    /*
  -> 가 * 보다 우선순위가 높으므로 먼저 해석하게 된다.
  *(p1.numpointer) => *((*pp).numpointer) => *pp.numpointer
   */
    *pp->numpointer = 2;

    printf("%d %d\n", p1.num, *((*pp).numpointer));
    



    return 0;
}