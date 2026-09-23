// This is the simple program to create a doubly linked list in C programming language.

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next ;

    struct Node* prev ; // The 'prev' pointer is used to store the address of the previous node in the doubly linked list. It allows traversal in both forward and backward directions, making it a doubly linked list.
    
};



struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = val;

    newNode -> prev  = NULL; // The previous pointer of the new node is set to NULL because it is not linked to any previous node yet.

    newNode -> next  = NULL;

    return newNode;

}


int main() {
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);  



    head -> next = second; // Link the first node to the second node
    second -> prev = head; // Link the second node back to the first node

    second -> next = third; // Link the second node to the third node
    third -> prev = second; // Link the third node back to the second node

    third -> next = NULL; // The next pointer of the last node is set to NULL to indicate the end of the list


    printf("Forward Traversal: ");

    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d", temp -> data);

        if(temp -> next != NULL) printf(" < - > ");        

        temp = temp -> next;
    }

    printf(" < - > NULL\n");



    printf("Backward Traversal: ");

    temp = third; // start from the last node for backward traversal

    while(temp != NULL) {
        printf("%d", temp -> data);

        if(temp -> prev != NULL) printf(" < - > ");

        temp = temp -> prev; // move to the previous node for backward traversal
    }

    printf(" < - > NULL\n");

}






//                             =====================    Explanation    =====================


// The structure is the same as a singly linked list: it has data and next.

// We add only one extra pointer: prev.

// next stores the address of the next node.

// prev stores the address of the previous node.

// createNode() works almost exactly like it does for a singly linked list; the only addition is newNode -> prev = NULL.

// head -> next = second links 10 forward to 20.

// second -> prev = head links 20 backward to 10.

// We make both connections between adjacent nodes because this is a doubly linked list.

// The final linked list is:

// NULL <- 10 <-> 20 <-> 30 -> NULL

// The first node’s prev is NULL, because no node exists before it.

// The last node’s next is NULL, because no node exists after it.



// Time Complxity = O(N)
// Time Complxity = O(N)