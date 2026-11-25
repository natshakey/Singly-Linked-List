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

void printList (Node *head){
    Node *temp = head;
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node *deleteFirst(Node *head){
    if (head == NULL){
        printf("List kosong\n");
        return NULL;
    }
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//Menghapus dari belakang
Node *deleteLast(Node *head){
    if (head == NULL){
        printf("List kosong\n");
        return NULL;
    }
    if (head->next == NULL){
        free(head);
        return NULL;
    }

    Node *previous = head;
    Node *current = head->next;
    while (current->next != NULL){
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current);
    return head;
}

//Menghapus di posisi tertentu
Node *deleteAtPosition(Node *head, int position){
    if (head == NULL){
        printf("List kosong\n");
        return NULL;
    }
    if (position < 1){
        printf("Posisi %d tidak valid!\n", position);
        return head;
    }
    if (position == 1){
        return deleteFirst(head);
    }

    Node *previous = head;
    for (int i = 1; i < position - 1 && previous->next != NULL; i++){
        previous = previous->next;
    }
    
    Node *target = previous->next;
    if (target == NULL){
        printf("Posisi %d tidak valid\n", position);
        return head;
    }
    previous->next = target->next;
    free(target);
    return head;
}

int main() {
    Node *head = createNode(10);
    Node *kedua = createNode(20);
    Node *ketiga = createNode(30);
    Node *keempat = createNode(40);
    Node *kelima = createNode(50);

    head->next = kedua;
    kedua->next = ketiga;
    ketiga->next = keempat;
    keempat->next = kelima;

    printList(head);

    //Menghapus dari depan
    head = deleteFirst(head);
    printList(head);
    
    //Menghapus dari belakang
    head = deleteLast(head);
    printList(head);

    //Menghapus di posisi tertentu
    head = deleteAtPosition(head, 2);
    printList(head);

    //Menghapus semua list
    while (head != NULL){
        head = deleteFirst(head);
        printList(head);
    }

    head = deleteLast(head);

}