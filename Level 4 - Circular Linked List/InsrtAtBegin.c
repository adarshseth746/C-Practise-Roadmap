// This is the simple program to insert a node at beginning of a circular linked list in C programming language.

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

struct Node* insertAtBegin(struct Node* head, int value) {

    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = value;

    // Empty list

    if(head == NULL) {
        newNode -> next = newNode;
        return newNode;
    }

    // New node points to old head

    newNode -> next = head;

    // Find last node
     
    struct Node* temp = head;

    while(temp -> next != head) {
        temp = temp -> next;
    }

    // (Very Important) Last node now points to new head

    temp -> next = newNode;
 
    // New node becomes head

    head = newNode;

    return head;
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

    head = insertAtBegin(head, 50);

    // Traversal

    temp = head; // Start from head

    do {

        printf("%d <-> ", temp->data);

        temp = temp->next;

    } while(temp != head); // Stop when we come back to head (circular condition)

    printf("HEAD\n");

    return 0;
}

//                                  =====================    Explanation    ======================



// insertAtBegin(head, value) inserts a new node at the beginning of a circular linked list.

// Step 1: Create newNode and store value in it.

// Step 2: If list is empty (head == NULL):

//         - Make newNode->next = newNode (node points to itself, forming a one-node circle).

//         - Return newNode as the new head.


// Step 3: If list is not empty:

//         - Set newNode -> next = head (new node points forward to old head).

//         - Use temp to traverse from head until the last node (where temp->next == head).

//         - This loop finds the node whose next currently points to head.


// Step 4: (Very Important) Set temp->next = newNode.

//         - The last node must now point to the new head to keep the list circular.

//         - Without this step, the circle would break and the last node would still point to old head.


// Step 5: Update head = newNode (new node becomes the new head).

// Step 6: Return the updated head.



//                              =====================    DRY RUN    ======================
 

// Initial circular singly linked list: 10 -> 20 -> 30 -> back to 10 (head = 10)

// Call insertAtBegin(head, 50)

// Create newNode with data = 50

// List is not empty, so:

//   - newNode -> next = head  =>  50 -> next = 10

//   - temp starts at head (10)

//   - Loop: temp -> next != head

//        temp = 10: temp -> next = 20 (≠ head) → move temp to 20

//        temp = 20: temp -> next = 30 (≠ head) → move temp to 30

//        temp = 30: temp -> next = 10 (= head) → loop stops, temp is last node (30)

//   - temp -> next = newNode  =>  30 -> next = 50 (last node now points to new head)

//   - head = newNode        =>  head = 50

// Final circular list: 50 -> 10 -> 20 -> 30 -> back to 50

// Traversal prints: 50 <-> 10 <-> 20 <-> 30 <-> HEAD


// Time Complexity = O(N)
// Reason: We traverse from head to the last node to update its next pointer.


// Space Complexity = O(N)
// Reason: The list stores N nodes in memory. Extra variables (temp, head, newNode) use O(1) auxiliary space.