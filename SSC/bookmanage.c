#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int add_book(char(*book_name)[30], char(*auth_name)[30],
    char(*publ_name)[30], int* borrowed, int* num_total_book);
int search_book(char(*book_name)[30], char(*auth_name)[30],
    char(*publ_name)[30], int num_total_book, int *borrowed);

int compare(char* str1, char* str2);
int include(char* str1, char* str2);
int borrow_book(int* borrowed);
int return_book(int* borrowed);


int main() {
    int user_choice;        /* ������ ������ �޴� */
    int num_total_book = 0; /* ���� å�� �� */

    /* ���� å, ����, ���ǻ縦 ������ �迭 ����. å�� �ִ� ������ 100 ��*/
    char book_name[100][30], auth_name[100][30], publ_name[100][30];
    /* ���ȴ��� ���¸� ǥ�� */
    int borrowed[100] = { 0 };

    while (1) {
        printf("���� ���� ���α׷� \n");
        printf("�޴��� �����ϼ��� \n");
        printf("1. å�� ���� �߰��ϱ� \n");
        printf("2. å�� �˻��ϱ� \n");
        printf("3. å�� ������ \n");
        printf("4. å�� �ݳ��ϱ� \n");
        printf("5. ���α׷� ���� \n");

        printf("����� ������ : ");
        scanf("%d", &user_choice);

        if (user_choice == 1) {
            /* å�� ���� �߰��ϴ� �Լ� ȣ�� */
            add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
        }
        else if (user_choice == 2) {
            /* å�� �˻��ϴ� �Լ� ȣ�� */
            search_book(book_name, auth_name, publ_name, num_total_book, borrowed);
        }
        else if (user_choice == 3) {
            /* å�� ������ �Լ� ȣ�� */
            borrow_book(borrowed);
        }
        else if (user_choice == 4) {
            /* å�� �ݳ��ϴ� �Լ� ȣ�� */
            return_book(borrowed);
        }
        else if (user_choice == 5) {
            /* ���α׷��� �����Ѵ�. */
            break;
        }
    }

    return 0;
}
/* å�� �߰��ϴ� �Լ�*/
int add_book(char(*book_name)[30], char(*auth_name)[30],
    char(*publ_name)[30], int* borrowed, int* num_total_book) {
    printf("�߰��� å�� ���� : ");
    scanf("%s", book_name[*num_total_book]);

    printf("�߰��� å�� ���� : ");
    scanf("%s", auth_name[*num_total_book]);

    printf("�߰��� å�� ���ǻ� : ");
    scanf("%s", publ_name[*num_total_book]);

    borrowed[*num_total_book] = 0; /* �������� ����*/
    printf("�߰� �Ϸ�! \n");
    (*num_total_book)++;

    return 0;
}
/* å�� �˻��ϴ� �Լ� */
int search_book(char(*book_name)[30], char(*auth_name)[30],
    char(*publ_name)[30], int num_total_book, int *borrowed) {
    int user_input; /* ������� �Է��� �޴´�. */
    int i;
    char user_search[30];

    printf("��� ������ �˻� �� ���ΰ���? \n");
    printf("1. å ���� �˻� \n");
    printf("2. ������ �˻� \n");
    printf("3. ���ǻ� �˻� \n");
    scanf("%d", &user_input);

    printf("�˻��� �ܾ �Է����ּ��� : ");
    scanf("%s", user_search);

    printf("�˻� ��� \n");

    if (user_input == 1) {
        /*

        i �� 0 ���� num_total_book ���� ���鼭 ������ å ������
        ����ڰ� �Է��� �˻���� ���ϰ� �ִ�.

        */
        for (i = 0; i < num_total_book; i++) {
            if (include(book_name[i], user_search)) {
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s  �ݳ�����: %d \n", i,
                    book_name[i], auth_name[i], publ_name[i], borrowed[i]);
            }
        }

    }
    else if (user_input == 2) {
        /*

        i �� 0 ���� num_total_book ���� ���鼭 ������ ������ �̸���
        ����ڰ� �Է��� �˻���� ���ϰ� �ִ�.

        */
        for (i = 0; i < num_total_book; i++) {
            if (include(auth_name[i], user_search)) {
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s  �ݳ�����: %d \n", i,
                    book_name[i], auth_name[i], publ_name[i], borrowed[i]);
            }
        }

    }
    else if (user_input == 3) {
        /*

        i �� 0 ���� num_total_book ���� ���鼭 ������ ���ǻ縦
        ����ڰ� �Է��� �˻���� ���ϰ� �ִ�.

        */
        for (i = 0; i < num_total_book; i++) {
            if (include(publ_name[i], user_search)) {
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s  �ݳ�����: %d \n", i,
                    book_name[i], auth_name[i], publ_name[i], borrowed[i]);
            }
        }
    }

    return 0;
}
int compare(char* str1, char* str2) {
    char *checkstr = str1;
    while (*checkstr) {
        if (*checkstr != *str2) {
            return 0;
        }
        checkstr++;
        str2++;
        if (*str2 == '\0') return 1;
    }

    return 0;
}

int include(char* str1, char* str2) {
    int check = 0;
    while (*str1) {
        if (*str1 == *str2) {
            check = compare(str1, str2);
        }
        str1++;
    }
    return check;
}


int borrow_book(int* borrowed) {
    /* ����ڷ� ���� å��ȣ�� ���� ����*/
    int book_num;

    printf("���� å�� ��ȣ�� �����ּ��� \n");
    printf("å ��ȣ : ");
    scanf("%d", &book_num);

    if (borrowed[book_num] == 1) {
        printf("�̹� ����� å�Դϴ�! \n");
    }
    else {
        printf("å�� ���������� ����Ǿ����ϴ�. \n");
        borrowed[book_num] = 1;
    }

    return 0;
}

int return_book(int* borrowed) {
    /* �ݳ��� å�� ��ȣ */
    int num_book;

    printf("�ݳ��� å�� ��ȣ�� ���ּ��� \n");
    printf("å ��ȣ : ");
    scanf("%d", &num_book);

    if (borrowed[num_book] == 0) {
        printf("�̹� �ݳ��Ǿ� �ִ� �����Դϴ�\n");
    }
    else {
        borrowed[num_book] = 0;
        printf("���������� �ݳ��Ǿ����ϴ�\n");
    }

    return 0;
}