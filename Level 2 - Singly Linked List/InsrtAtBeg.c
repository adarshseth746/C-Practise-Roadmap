// This is the simple program to demonstrate insertion at the beginning of a linked list in C programming language.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode -> data = val;
    newNode -> next = NULL;

    return newNode;
}

struct Node* insertAtBegin(struct Node* head, int value) { // Function to insert a new node at the beginning of the linked list

    struct Node* newNode = createNode(value); // Create a new node with the given value

    // Imp Step: Link the new node to the current head of the linked list

    newNode -> next = head; // Set the next pointer of the new node to point to the current head of the linked list

    head = newNode; // Update the head of the linked list to point to the new node, making it the new first node in the list

    // Why we first link the new node to the current 'head' before updating the 'head' ? Because if we update the 'head' first, we will lose the reference to the original list, and the new node will not be linked to the existing nodes. By linking the new node to the current 'head' first, we ensure that the new node is properly connected to the existing list before changing the 'head' pointer.

    // 10 -> 20 -> 30 -> NULL (head = 10)
    // New node = 5,  5 -> next = 10 -> 20 -> 30 -> NULL
    // Then update 'head' = 5 -> 10 -> 20 -> 30 -> NULL

    return head;
}


int main() {

    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head -> next = second;
    second -> next  = third;
    third -> next  = NULL;

    head = insertAtBegin(head, 5); // Insert a new node with value 5 at the beginning of the linked list

    // Traverse and print the linked list to verify the insertion

    struct Node* temp = head;

    printf("Linked List after insertion at the beginning: ");

    while(temp != NULL) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }

    printf("NULL \n");
    return 0;
}


//                             =====================    Explanation    =====================

// In the 'insertAtBegin' function, we first create a new node with the given value. 

// Then, we link the new node to the current 'head' of the linked list by setting the 'next' pointer of the new node to point to the current 'head'.

// After that, we update the 'head' of the linked list to point to the new node, making it the new first node in the linked list.

// Finally, we return the updated 'head' of the linked list to reflect the changes made by the insertion operation.


//                             ======================    DRY RUN       ======================

// Initial linked list: 10 -> 20 -> 30 -> NULL (head = 10)

// Insert a new node with value 5 at the beginning of the linked list: 

// Create a new node with value 5: 5 -> NULL

// Link the new node to the current head: newNode -> next = head (5 -> 10 -> 20 -> 30 -> NULL)
// Update the head to point to the new node: head = newNode (head = 5 -> 10 -> 20 -> 30 -> NULL)

// Final linked list after insertion: 5 -> 10 -> 20 -> 30 -> NULL


// Time Complexity = O(1) since we are inserting at the beginning of the linked list
// Space Complexity = O(N) (for storing the nodes in memory)