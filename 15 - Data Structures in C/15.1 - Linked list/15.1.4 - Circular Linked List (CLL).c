#include <stdio.h>
#include <stdlib.h>



struct Node{

    int data;
    struct Node* next;

};

//Create new node
struct Node* createNode(int value){


    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;

};

// Insert at end
void insertEnd(struct Node** head, int value){

    struct Node* newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        newNode->next = *head; // Point to itself
    }
    struct Node* temp = *head;
    while(temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;

}


void display(struct Node* head){

    if(head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while (temp != head);
    printf("(Back to head)\n");


}


int main(){
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    printf("Circular Linked list: \n");
    display(head);


    return 0;
}
