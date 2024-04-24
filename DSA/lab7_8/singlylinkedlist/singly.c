// WAP TO IMPLEMENT THE OPERATION OF SINGLY LINKED LIST USING C.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to display all the elements of singly linked list
void listTraversal(Node* head) {
    printf("Elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to create Node
Node* createNode(int data) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    return ptr;
}

// Funtion to insert a node at the front of singly linked list
Node* insertAtFront(Node* head, int data) {
    Node* ptr = createNode(data);
    ptr->next = head;
    return ptr;
}

// Funtion to insert a node at a given index of singly linked list
Node* insertAtIndex(Node* head, int data, int index) {
    Node* ptr = createNode(data);
    Node* p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Funtion to insert a node at the end of singly linked list
Node* insertAtEnd(Node* head, int data) {
    Node* ptr = createNode(data);
    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Funtion to delete a node from the front of singly linked list
Node* deletefromFront(Node* head) {
    Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Funtion to delete a node from a given index of singly linked list
Node* deleteAtIndex(Node* head, int index) {
    Node* ptr = head;
    Node* ptr1 = head->next;
    for (int i = 0; i < index - 1; i++) {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    ptr->next = ptr1->next;
    free(ptr1);
    return head;
}

// Funtion to delete a node from the end of singly linked list
Node* deletefromEnd(Node* head) {
    Node* ptr = head;
    Node* ptr1 = head->next;
    while (ptr1->next != NULL) {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    ptr->next = NULL;
    free(ptr1);
    return head;
}

int main() {
    Node* head, * first, * second, * third;

    first = createNode(7);
    second = createNode(8);
    third = createNode(9);

    first->next = second;
    second->next = third;
    third->next = NULL;

    head = first;

    printf("Before insertion:\n");
    listTraversal(head);
    head = insertAtFront(head, 11);
    head = insertAtIndex(head, 39, 3);
    head = insertAtEnd(head, 90);
    printf("\nAfter insertion:\n");
    listTraversal(head);

    printf("\nBefore deletion:\n");
    listTraversal(head);
    head = deletefromFront(head);
    head = deleteAtIndex(head, 3);
    head = deletefromEnd(head);
    printf("\nAfter deletion:\n");
    listTraversal(head);

    return 0;
}