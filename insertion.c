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

//Menambahkan node dari depan
Node *insertAtTheBeginning(Node *head, int data){
    Node *temp = createNode(data);
    temp->next = head;
    return temp;
}

//Menambahkan node dari belakang
Node *insertAtTheEnd(Node *head, int data){
    Node *temp = createNode(data);

    if(head == NULL){
        return temp;
    }

    Node *ptr = head;
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}

//Menambahkan di posisi tertentu
Node *insertAtPosition(Node *head, int data, int position){
    if (position < 1){
        printf("Posisi %d tidak valid\n", position);
        return head;
    }
    if (position == 1){
        return insertAtTheBeginning(head, data);
    }
    
    Node *ptr = head;
    for (int i = 1; i < position - 1 && ptr != NULL; i++){
        ptr = ptr->next;
    }
    if (ptr == NULL){
        printf("Posisi %d melebihi panjang list!\n", position);
        return head;
    }
    
    Node *temp = createNode(data);
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

int main() {
    Node *head = createNode(10);
    Node *kedua = createNode(20);
    Node *ketiga = createNode(30);

    head->next = kedua;
    kedua->next = ketiga;

    printList(head);

    //Menambahkan dari depan
    head = insertAtTheBeginning(head, 5);
    printList(head);

    //Menambahkan dari belakang
    head = insertAtTheEnd(head, 35);
    printList(head);
    
    //Menambahkan di posisi tertentu
    head = insertAtPosition(head, 15, 3);
    printList(head);

}