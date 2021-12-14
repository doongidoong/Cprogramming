#include <stdio.h>

// 구조체 안의 구조체
#include <stdio.h>
struct Human {
  int age;    /* 나이 */
  int height; /* 키 */
  int weight; /* 몸무게 */
  struct family{
      char (*member);
  };
};
int main() {
  struct Human Psi;
  struct Human *ppsi;
  struct family PsiF;
  struct family *psf; 
  char (*name) ="GD"; 
  ppsi = &Psi;
  ppsi->age = 19;
  Psi.height = 185;
  Psi.weight = 80;

  psf = &PsiF;
  psf->member = name;  

  printf("Psi 에 대한 정보 \n");
  printf("나이   : %d \n", Psi.age);
  printf("키     : %d \n", Psi.height);
  printf("몸무게 : %d \n", Psi.weight);
  printf("%s", psf->member);
  return 0;
}