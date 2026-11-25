#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Alokasi memori gagal!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Node *head = createNode(101);
    Node *kedua = createNode(102);
    Node *ketiga = createNode(103);

    head->next = kedua;
    kedua->next = ketiga;

    printf("Data pertama (head): %d\n", head->data);
    printf("Data kedua: %d\n", head->next->data);
    printf("Data ketiga: %d\n", head->next->next->data);

    if (ketiga->next == NULL){
        printf("\nNode ketiga adalah node terakhir\n");
    }

    free(ketiga);
    free(kedua);
    free(head);
    head = NULL;

    return 0;
}