#include <stdio.h>
#define INF 10000


typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head;

void addFront(Node *root, int data){ //  헤드가 가르키는 것을 내가 만든게 가르키고 헤드가 만든 것을 가르킴
    Node *node =(Node*)malloc(sizeof(Node));
    node ->data = data;
    node ->next = root ->next;
    root ->next = node;
}

void removeFront(Node *root){ // ㅁ-> ㅁ-> ㅁ->
    Node *node = root->next;
    root->next = node->next;
    free(node);
}
void freeAll(Node *root) { // 연결 리스트 메모리 해제 함수
    Node *cur = root->next;
    while(cur){
        Node *next = cur->next;
        free(cur);
        cur = next; 
    }
}
void showAll(Node *root) { //연결 리스트 전체 출력 함수
    Node *cur = root->next;
    while(cur!=NULL){
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
