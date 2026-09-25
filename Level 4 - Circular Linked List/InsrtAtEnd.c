// This is the simple program to insert a node at END of a circular singly linked list in C programming language.

#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = value;
    newNode -> next  = NULL;

    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int value) {

    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = value; 

    newNode -> next = head; // New node's next points to head (to maintain circularity)
     
    struct Node* temp = head;

    while(temp -> next != head) {
        temp = temp -> next;
    }

    temp -> next = newNode; // Last node now points to new node (new node becomes new last)

    return head; // Head remains unchanged when inserting at end
}


int main() {
    struct Node* head = NULL;
    
    struct Node* temp;

    // Create first node

    head = createNode(10);

    // Create second node

    head -> next = createNode(20);

    // Create third node

    head -> next -> next = createNode(30);


    // Last node points back to head
    
    head -> next -> next -> next = head;

    head = insertAtEnd(head, 50);

    // Traversal
    
    temp = head; // Start from head

    do {

        printf("%d <-> ", temp->data);

        temp = temp->next;

    } while(temp != head); // Stop when we come back to head (circular condition)

    printf("HEAD\n");

    return 0;
}





//                          =====================    Explanation    ======================

// insertAtEnd(head, value) inserts a new node at the END of a circular singly linked list.

// Step 1: Create newNode and store value in it.

// Step 2: Set newNode -> next = head.

//         - In a circular list, the last node must point back to head.

//         - So the new last node (newNode) must have its next pointing to head.


// Step 3: Use temp to traverse from head until the last node (where temp->next == head).

//         - This loop finds the current last node before insertion.


// Step 4: Set temp -> next = newNode.

//         - The old last node now points to newNode.

//         - newNode becomes the new last node, and its next already points to head.

// Step 5: Return head (head does not change when inserting at end).


//                          =====================    DRY RUN    ======================



// Initial circular linked list: 10 -> 20 -> 30 -> back to 10 (head = 10)

// Call insertAtEnd(head, 50)

// Create newNode with data = 50

// Set newNode -> next = head  =>  50->next = 10

// temp starts at head (10)

// Loop: temp -> next != head

//   - temp = 10: temp -> next = 20 (≠ head) → move temp to 20

//   - temp = 20: temp -> next = 30 (≠ head) → move temp to 30

//   - temp = 30: temp -> next = 10 (= head) → loop stops, temp is last node (30)

// Set temp -> next = newNode  =>  30 -> next = 50 (old last now points to new node)

// Final circular list: 10 -> 20 -> 30 -> 50 -> back to 10

// Traversal prints: 10 <-> 20 <-> 30 <-> 50 <-> HEAD


// Time Complexity = O(N)
// Reason: We traverse from head to the last node to find where to insert.

// Space Complexity = O(N)
// Reason: The list stores N nodes in memory. Extra variables (temp, head, newNode) use O(1) auxiliary space.
