// WAP TO IMPLEMENT ALL THE OPERATION OF SINGLY CIRCULAR LINKED LIST.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create Node
Node* createNode(int data) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    return ptr;
}
// Function to display all the elements of the circular singly linked list
void traverse(Node* last) {
    Node* p = last->next;
    printf("Element: ");
    do {
        printf("%d->", p->data);
        p = p->next;
    } while (p != last->next);
}

// Function to insert a node at the front of a circular singly linked list
Node* insertAtFront(Node* last, int data) {
    Node* newNode = createNode(data);
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

// Function to insert a node at given index of a circular singly linked list
Node* insertAtIndex(Node* last, int data, int index) {
    Node* newNode = createNode(data);
    Node* p = last->next;  // Start from the first node
    for (int i = 0; i < index - 1 && p != last;
        i++) {  // Traverse to the specified index
        p = p->next;
    }
    // Insert the new node after the current node
    newNode->next = p->next;
    newNode->data = data;
    p->next = newNode;
    return last;
}

// Function to insert a node at the end of a circular singly linked list
Node* insertAtEnd(Node* last, int data) {
    Node* newNode = createNode(data);
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;

    // update the last to the newNode
    last = newNode;
    return last;
}

// Function to delete a node from the front of a circular singly linked list
Node* deletefromFront(Node* last) {
    Node* firstNode = last->next;
    last->next = firstNode->next;
    free(firstNode);
    return last;
}

// Function to delete a node from the front of a circular singly linked list
Node* deleteAtIndex(Node* last, int index) {
    Node* p = last->next;
    Node* q = p->next;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return last;
}

// Function to delete a node from the end of a circular singly linked list
Node* deletefromEnd(Node* last) {
    Node* q = last->next;
    while (q->next != last) {
        q = q->next;
    }
    q->next = last->next;  // Here q->next points to first node
    free(last);
    return q;
}

int main() {
    Node* last;
    Node* first = NULL, * second = NULL, * third = NULL;

    first = createNode(7);
    second = createNode(8);
    third = createNode(9);

    first->next = second;
    second->next = third;
    third->next = first;

    last = third;

    // printf("\nBefore insertion\n");
    // traverse(last);

    last = insertAtFront(last, 90);
    last = insertAtIndex(last, 6, 3);
    last = insertAtEnd(last, 100);

    printf("\nAfter insertion: \n");
    traverse(last);

    // printf("\nBefore deletion:\n");
    // traverse(last);
    printf("\nAfter deletion:\n");
    last = deletefromFront(last);
    last = deleteAtIndex(last, 1);
    last = deletefromEnd(last);
    traverse(last);

    return 0;
}