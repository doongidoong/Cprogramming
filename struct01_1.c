#include <stdio.h>

// ����ü ���� ����ü
#include <stdio.h>
struct Human {
  int age;    /* ���� */
  int height; /* Ű */
  int weight; /* ������ */
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

  printf("Psi �� ���� ���� \n");
  printf("����   : %d \n", Psi.age);
  printf("Ű     : %d \n", Psi.height);
  printf("������ : %d \n", Psi.weight);
  printf("%s", psf->member);
  return 0;
}