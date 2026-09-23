// This is the simple program to insert a node at the end of a doubly linked list in C programming language.

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

    newNode -> prev  = NULL; 

    newNode -> next  = NULL;

    return newNode;

}

struct Node* insertAtEnd(struct Node* head, int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = value;
    newNode -> next = NULL;   // It will be the last node
    newNode -> prev = NULL;   // Will be set properly below

    // If list is empty, new node becomes the head

    if (head == NULL) {

        return newNode;     // New node is now the only node (head)
    }

    // Find the last node

    struct Node* temp = head;

    while (temp -> next != NULL) {
        temp = temp -> next;
    }

    // Now temp is the last node

    // Link new node after temp

    temp -> next = newNode;   // Old last node points forward to new node

    newNode -> prev = temp;   // New node points back to old last node
    // newNode->next is already NULL

    return head;            // Head remains unchanged
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


    head = insertAtEnd(head, 200); // Insert a new node with value 200 at the end of the doubly linked list

    printf("Forward Traversal: ");

    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d", temp -> data);

        if(temp -> next != NULL) printf(" < - > ");        

        temp = temp -> next;
    }

    printf(" < - > NULL\n");

}



//                             =====================    Explanation    =====================


// insertAtEnd(head, value) does the following:

// Creates a new node using the same logic as createNode.

// Sets newNode -> next = NULL because it will become the last node.

// If the list is empty (head == NULL), returns newNode as the new head.

// Otherwise, traverses from head to find the current last node (temp).

// Sets temp -> next = newNode so the old last node points forward to the new node.

// Sets newNode -> prev = temp so the new node points back to the old last node.

// Returns the original head, since the head does not change when inserting at the end.

// This is the only change compared to basic node creation: we carefully update 'next' and 'prev' so the new node becomes the new tail while preserving the doubly linked structure.

// =====================    DRY RUN    ======================

// Initial doubly linked list: 10 <-> 20 <-> 30 <-> NULL (head = 10)

// Create newNode with data = 200, next = NULL, prev = NULL

// Traverse to find last node: temp ends at node 30

// Link: temp -> next = newNode  =>  30 -> next = 200
// Link: newNode -> prev = temp  =>  200 -> prev = 30
// Final list: NULL <- 10 <-> 20 <-> 30 <-> 200 -> NULL

// Forward traversal prints: 10 < - > 20 < - > 30 < - > 200 < - > NULL

// Time Complexity = O(N)
// Space Complexity = O(N)