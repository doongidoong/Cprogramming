/* memcmp �Լ� */

#include <stdio.h>
#include <string.h>

int main() {
    //memcpy �Լ��� �޸��� Ư���� �κ����� ���� �� ������ �κ��� �ٸ� �޸� �������� �������ִ� �Լ�
    char str[50] = "I love Chewing C hahaha";
    char str2[50];
    char str3[50];

    memcpy(str2, str, strlen(str) + 1);
    memcpy(str3, "hello", 6);

    printf("%s \n", str);
    printf("%s \n", str2);
    printf("%s \n", str3);

    //memmove �Լ��� �޸��� Ư���� �κ��� ������ �ٸ� �κ����� �Ű��ִ� ������ �մϴ�. �� �� '�ű��' �� �ؼ� ���� ������ �ִ� �����Ͱ� ��������� �ʽ��ϴ�.

    printf("%s \n", str);
    printf("memmove ���� \n");
    memmove(str + 23, str + 17, 6);
    printf("%s", str);


    //memcmp �Լ��� ���캸���� �սô�. �̴� �̸������� ����� ������ �ǵ��� �� ���� �޸� ������ ���� ���ϴ� �Լ��Դϴ�. 
    // �޸��� �� �κ��� ���ϴ� ��ŭ ��, ���ٸ� 0, �ٸ��ٸ� ����� ���� 0 �� �ƴ� ���� ����
    int arr[10] = {1, 2, 3, 4, 5};
    int arr2[10] = {1, 2, 3, 4, 5};

    if (memcmp(arr, arr2, 5) == 0)
        printf("arr �� arr2 �� ��ġ! \n");
    else
        printf("arr �� arr2 �� ��ġ ���� \n");

   

  return 0;
}