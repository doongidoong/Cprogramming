#include <stdio.h>
struct TEST {
  int age;
  int gender;
  char name[20];
};
int set_human(struct TEST *a, int age, int gender, const char *name);
char copy_str(char *dest, const char *src);

int main() {
  struct TEST human;

  set_human(&human, 10, 1, "Lee"); // �Լ��� ������ ���� �ٲٷ��� �ּҰ��� �����Ͽ�����.

  printf("AGE : %d // Gender : %d // Name : %s \n", human.age, human.gender,
         human.name);
  return 0;
}
  int set_human(struct TEST *a, int age, int gender, const char *name){
      a->age = age;
      a->gender = gender;
      copy_str(a->name, name); // (*a).name�� ���� name�� ������ ����, �Է� ���� ���� ���� ������ ���  
      return 0; 
  }
  // name�� �����.
  char copy_str(char *str1, const char *str2){
      while (*str2){
          *str1 = *str2;
          str1++;
          str2++;
      }
      *str1 = '\0';
      return 1;
  }