#include <stdio.h>


#include <stdio.h>
int read_char(void *p, int byte);
int main() {
  int arr[1] = {0x12345678};

  printf("%x \n", arr[0]);
  read_char(arr, 4);
}

int read_char(void *p, int byte) {
  do {
    printf("%x \n", *(char *)p); //��Ʋ ����ȿ� ���� 78 56 34 12������ ���
    byte--;

    p = (char *)p + 1;
  } while (p && byte); //p�� byte�� 0�� �ɶ����� ���

  return 0;
}