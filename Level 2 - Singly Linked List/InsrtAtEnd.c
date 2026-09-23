// This is the simple program to demonstrate insertion at the end of a linked list in C programming language.

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

struct Node* insertAtEnd(struct Node* head, int value) { // Function to insert a new node at the end of the linked list

    struct Node* newNode = createNode(value); // Create a new node with the given value

    if(head == NULL) {
        return newNode; // If the linked list is empty, return the new node as the head of the list
    }

    struct Node* temp = head; // Create a temporary pointer to traverse the linked list starting from the head node

    while(temp -> next != NULL) { // Traverse the linked list until the last node (when temp -> next becomes NULL)

        temp = temp -> next; // Move the temporary pointer to the next node in the linked list
    } 

    temp -> next = newNode; // Link the last node of the linked list to the new node, effectively inserting it at the end of the list

    return head; // Return the head of the linked list (which remains unchanged)
}


int main() {

    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head -> next = second;
    second -> next  = third;
    third -> next  = NULL;

    head = insertAtEnd(head, 40); // Insert a new node with value 40 at the end of the linked list

    // Traverse and print the linked list to verify the insertion

    struct Node* temp = head;

    printf("Linked List after insertion at the end: ");

    while(temp != NULL) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }

    printf("NULL \n");
    return 0;
}


//                             =====================    Explanation    =====================

// In the 'insertAtEnd' function, we first create a new node with the given value. 

// Then, we traverse the linked list to find the last node and link the new node to it.

// Finally, we return the head of the linked list to reflect the changes made by the insertion operation.



//                             ======================    DRY RUN       ======================

// Initial linked list: 10 -> 20 -> 30 -> NULL (head = 10)

// Insert a new node with value 40 at the end of the linked list: 

// Create a new node with value 40: 40 -> NULL

// Link the last visited node's next pointer to the new node: temp -> next = newNode (10 -> 20 -> 30 -> 40 -> NULL)

// head remains unchanged, still pointing to the first node (10)

// Final linked list after insertion: 10 -> 20 -> 30 -> 40 -> NULL


// Time Complexity = O(N) since we need to traverse the linked list to find the last node and then insert the new node at the end of the list

// Space Complexity = O(N) (for storing the nodes in memory)