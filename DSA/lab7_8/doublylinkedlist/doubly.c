#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

void listTraversal(Node* head) {
    printf("Linked list: NULL<->");
    while (head != NULL) {
        printf("%d<->", head->data);
        head = head->next;
    }
    if (head == NULL)
        printf("NULL\n");
}

// Function to create Node
Node* createNode(int data) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    return ptr;
}

// Function to insert a node at the front of a doubly linked list
Node* insertAtFront(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->prev = NULL;
    newNode->next = head;
    // previous of head is newNode
    head->prev = newNode;
    head = newNode;
    return head;
}

// Function to insert a node at given index of a doubly linked list
void insertAtIndex(Node* head, int data, int index) {
    Node* newNode = createNode(data);
    Node* p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    newNode->next = p->next;
    p->next->prev = newNode;
    p->next = newNode;
    newNode->prev = p;
}

// Function to insert a node at the end of a doubly linked list
void insertAtEnd(Node* head, int data) {
    Node* ptr = head;
    Node* newNode = createNode(data);
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = NULL;
}

// Function to delete a node from the front of a doubly linked list
Node* deletefromFront(Node* head) {
    Node* p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
    return head;
}

// Function to delete a node at given index of a doubly linked list
void deleteAtIndex(Node* head, int index) {
    Node* p = head;
    Node* q = head->next;
    int i = 0;
    for (i = 0; i < index - 1; i++) {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    q->next->prev = p;
    free(q);
}

// Function to delete a node from the end of a doubly linked list
void deleteFromEnd(Node* head) {
    Node* p = head;
    Node* q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}

int main() {
    // initialize an empty node
    Node* head = NULL, * first = NULL, * second = NULL, * third = NULL;

    first = createNode(7);
    second = createNode(8);
    third = createNode(9);

    first->prev = NULL;
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = NULL;

    head = first;
    head = insertAtFront(head, 6);
    insertAtIndex(head, 11, 1);
    insertAtEnd(head, 9);

    printf("\nAfter insertion:\n");
    listTraversal(head);

    head = deletefromFront(head);
    deleteAtIndex(head, 1);
    deleteFromEnd(head);

    printf("\nAfter deletion:\n");
    listTraversal(head);
}