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
    printf("%x \n", *(char *)p); //리틀 에디안에 의해 78 56 34 12식으로 출력
    byte--;

    p = (char *)p + 1;
  } while (p && byte); //p나 byte가 0이 될때까지 출력

  return 0;
}