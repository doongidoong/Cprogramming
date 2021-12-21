#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
    } Node;
Node *head;

void addFront(Node *root, int data){ // 연결 리스트 추가 함수

    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = root -> next;
    root->next = node;
}
void removeFront(Node *root) { // 연결 리스트 삭제 함수
    Node *front = root->next;
    root->next = front->next; //루트의 다음 로드가 프론트의 다음 노드, 즉 다음 다음 노드
    free(front);
}
void freeAll(Node *root) { // 연결 리스트 메모리 해제 함수
    Node *cur = head->next;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}
void showAll(Node *root) { //연결 리스트 전체 출력 함수
        Node *cur = head->next;
        while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}


int main(void) {
    head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    addFront(head, 2);
    addFront(head, 1);
    addFront(head, 7);
    addFront(head, 9);
    addFront(head, 8);
    removeFront(head);
    showAll(head);
    freeAll(head);
    system("pause");
    return 0;
}
