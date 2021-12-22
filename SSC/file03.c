#include <stdio.h>
#define VAR 10
int main() {
  char arr[VAR] = {"hi"};
  printf("%s\n", arr);
  
#define A  //A가 define 된다면 ifdefA ~endif 까지 실행 뒤에는 주석 처리
#ifdef A
printf("AAAA \n");
#endif
#ifdef B
printf("BBBB \n");
#endif
  return 0;
}
/*
#ifdef  매크로 이름 
(매크로 이름)이 정의되었다면 이 부분이 코드에 포함되고 그렇지 않다면 코드에
포함되지 않는다.
여러가지 모드를 만들 때 사용할 수 있음. 예를 들어 어떤 계산기는 int만
어떤 계산기는 float을 사용할 때, #define #ifdef ~ #endif 를 쓸 수 있음.
#endif
*/