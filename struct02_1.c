#include <stdio.h>
#include <string.h>
// ����ü, ������ ������ ������ ���
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
    struct TEST t1 = {8,"none","none2"}; //����ü �ʱ�ȭ ��
    struct TEST *pt; // ����ü ������
    pt = &t1;
    printf("%d %s %s\n", pt->a,pt->b,pt->c);
    pt->a=10;
    pt->b="string";
    strcpy(t1.c,"������ ��");
    printf("%d %s %s\n", pt->a,pt->b,t1.c);
    
    int i=0;
    struct Pointertest p1;
    struct Pointertest *pp;
    pp= &p1;
    (*pp).num = 1;
    p1.numpointer = &i;
    printf("������ �ٷ�� %d %d\n", p1.num, *(p1.numpointer));
    /*
  -> �� * ���� �켱������ �����Ƿ� ���� �ؼ��ϰ� �ȴ�.
  *(p1.numpointer) => *((*pp).numpointer) => *pp.numpointer
   */
    *pp->numpointer = 2;
    printf("������ �ٷ�� %d %d\n", p1.num, *((*pp).numpointer));
    
    
    // ����ü ����
    struct TEST t2;
    t2 = t1;
    printf("����ü ����: %d %s %s\n", t2.a,t2.b,t1.c);
    
    return 0;
}