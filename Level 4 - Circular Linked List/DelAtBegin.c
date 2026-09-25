// This is the simple program to delete the first node of a circular linked list in C programming language.

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

struct Node* delAtBegin(struct Node* head) {

    if (head == NULL) {
        printf("Linked list is empty \n");
        return NULL;
    }

    struct Node* temp = head;

    while(temp -> next != head) {

        temp = temp -> next;
    }

    struct Node* oldHead = head;  // Save old head to free it

    temp -> next = head -> next;  // Last node points to new head

    head = head -> next;   // Move head to new first node

    free(oldHead);   // Free the OLD head, not the new one

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

    head = delAtBegin(head);

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

// delAtBegin(head) deletes the first node of a circular linked list.

// Step 1: Check if head is NULL (list empty). If yes, print message and return NULL.

// Step 2: Use temp to traverse from head until the last node (where temp -> next == head).

//         - This finds the node whose next currently points to head.


// Step 3: Save old head in oldHead pointer so we can free it later.

// Step 4: Set temp -> next = head->next.

//         - The last node now points to the second node (new head).

//         - This maintains the circular structure after deletion.

// Step 5: Move head to head -> next (second node becomes new head).

// Step 6: Free oldHead (the original first node) to remove it from memory.

// Step 7: Return the new head so main() can update its head pointer.


//                      =====================    DRY RUN    ======================


// Initial circular linked list: 10 -> 20 -> 30 -> back to 10 (head = 10)

// Call delAtBegin(head)

// temp starts at head (10)

// Loop: temp -> next != head

//   - temp = 10: temp -> next = 20 (≠ head) → move temp to 20

//   - temp = 20: temp -> next = 30 (≠ head) → move temp to 30

//   - temp = 30: temp -> next = 10 (= head) → loop stops, temp is last node (30)

// oldHead = head  =>  oldHead = 10

// temp -> next = head -> next  =>  30 -> next = 20 (last node now points to new head)

// head = head -> next        =>  head = 20 (new head is node 20)

// free(oldHead)            =>  node 10 is deleted from memory

// Final circular list: 20 -> 30 -> back to 20

// Traversal prints: 20 <-> 30 <-> HEAD


// Time Complexity = O(N)
// Reason: We traverse from head to the last node to update its next pointer.

// Space Complexity = O(N)
// Reason: The list stores N nodes in memory. Extra variables (temp, head, oldHead) use O(1) auxiliary space.
