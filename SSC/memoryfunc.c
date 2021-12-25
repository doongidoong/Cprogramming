/* memcmp 함수 */

#include <stdio.h>
#include <string.h>

int main() {
    //memcpy 함수는 메모리의 특정한 부분으로 부터 얼마 까지의 부분을 다른 메모리 영역으로 복사해주는 함수
    char str[50] = "I love Chewing C hahaha";
    char str2[50];
    char str3[50];

    memcpy(str2, str, strlen(str) + 1);
    memcpy(str3, "hello", 6);

    printf("%s \n", str);
    printf("%s \n", str2);
    printf("%s \n", str3);

    //memmove 함수는 메모리의 특정한 부분의 내용을 다른 부분으로 옮겨주는 역할을 합니다. 이 때 '옮긴다' 고 해서 이전 공간에 있던 데이터가 사라지지는 않습니다.

    printf("%s \n", str);
    printf("memmove 이후 \n");
    memmove(str + 23, str + 17, 6);
    printf("%s", str);


    //memcmp 함수를 살펴보도록 합시다. 이는 이름에서도 충분히 짐작이 되듯이 두 개의 메모리 공간을 서로 비교하는 함수입니다. 
    // 메모리의 두 부분을 원하는 만큼 비교, 같다면 0, 다르다면 결과에 따라 0 이 아닌 값을 리턴
    int arr[10] = {1, 2, 3, 4, 5};
    int arr2[10] = {1, 2, 3, 4, 5};

    if (memcmp(arr, arr2, 5) == 0)
        printf("arr 과 arr2 는 일치! \n");
    else
        printf("arr 과 arr2 는 일치 안함 \n");

   

  return 0;
}