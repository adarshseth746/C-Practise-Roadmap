// A Node contains:           ===================    DATA | NEXT   ==============

// This is the simple program to demonstrate how to create a singly linked list in C programming language.

#include<stdio.h>
#include <stdlib.h> // Include the standard library for memory allocation functions like malloc


struct Node {   // Define the structure of a node in the linked list
    int data;   // Data field to store the value of the node
    struct Node *next;  // Pointer to the next node in the linked list
};


struct Node* createNode(int val) { // Function to create a new node with the given value
    struct Node* newNode; // Declare a pointer to a new node


    newNode = (struct Node*)malloc(sizeof(struct Node)); // Most Imp: Allocate memory for the new node using malloc
   
    // Two important steps to initialize the new node

    newNode -> data = val; // Set the data of the new node to the given value
    newNode -> next = NULL; // Set the next pointer of the new node to NULL, indicating that it does not point to any other node yet

    return newNode; // Return the pointer (notice we said 'pointer' not data) to the newly created node
}

int main() {

    // Create nodes

    struct Node* head = createNode(10); // Create the head node with value 10, 20, 30
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    // Link nodes: head -> second -> third


    head -> next = second; // Link the head node to the second node
    second -> next  = third; // Link the second node to the third node
    third -> next  = NULL; // Optional: Set the next pointer of the third node to NULL, indicating that it is the last node in the list


    // Traverse and print the linked list, does not matter if you cannot get this, we will discuss how to traverse a linked list in the next level.

    struct Node* temp = head; // Create a temporary pointer to traverse the linked list starting from the head node 

    printf("Linked List: ");

    while(temp != NULL) { // Imp Condition: Traverse the linked list until the end (when temp becomes NULL)
         
        printf("%d -> ", temp -> data); // Print the data of the current node and an arrow to indicate the link to the next node
        temp = temp -> next; // Move the temporary pointer to the next node in the linked list
    }

    printf("NULL!\n");
}


//                              =====================    Explanation    =====================

// firstly, we define a structure called 'Node' that represents a single node in the linked list. Each node contains an integer data field and a pointer to the next node in the list.

// The 'createNode' function is responsible for creating a new node with the given value. It allocates memory for the new node using 'malloc', initializes its data field with the provided value, and sets its next pointer to NULL.

// In the 'main' function, we create three nodes (head, second, and third) using the 'createNode' function. We then link these nodes together to form a singly linked list by setting the next pointers accordingly.

// Finally, we traverse the linked list starting from the head node and print the data of each node until we reach the end of the list (when the next pointer is NULL). The output shows the values of the nodes in the order they are linked together.



//                               ======================    DRY RUN       ======================

// Create nodes: head (10), second (20), third (30)

// Link nodes: head -> second -> third (10 -> 20 -> 30)

// Traverse and print the linked list:

// temp = head: print temp -> data (10), move temp to temp -> next (second)
// temp = second: print temp -> data (20), move temp to temp -> next (third)
// temp = third: print temp -> data (30), move temp to temp -> next (NULL)

// Final output: Linked List: 10 -> 20 -> 30 -> NULL!


// Time Complexity = O(N) (for traversing the linked list)
// Space Complexity = O(N) (for storing the nodes in memory)