// This is the simple program to create and traverse a circular singly linked list in C programming language.

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

 // Traversal
    temp = head; // Start from head

    do {

        printf("%d <-> ", temp->data);

        temp = temp->next;

    } while(temp != head); // Stop when we come back to head (circular condition)

    printf("HEAD\n");

    return 0;
}

//                  =====================    Explanation    ======================


// createNode() works the same as before: it allocates memory, sets data, and sets next = NULL.

// We create three nodes: 10, 20, and 30, and link them as: 10 -> 20 -> 30.

// The key circular step is: head->next->next->next = head, which makes 30->next = head.

// Now the list is: 10 -> 20 -> 30 -> back to 10 (circular).


// Two necessary changes for traversal in a circular linked list:

// 1. Condition: while(temp != head) instead of while(temp != NULL)

//    - In a normal list, we stop when temp becomes NULL (end of list).
//    - In a circular list, there is no NULL at the end; the last node points back to head.

//    - So we stop when temp comes back to head (one full circle completed).


// 2. Use of do-while loop instead of while loop

//    - A do-while loop executes the body first, then checks the condition.

//    - Basic definition: A do-while loop is a post-test loop that guarantees at least one execution of the loop body before checking the condition.

//    - We need this because when temp = head, the condition (temp != head) is false initially.

//    - If we used a normal while loop, the body would never execute.

//    - With do-while, we print head's data first, then check if we've come back to head.




//              =====================    DRY RUN    ======================

// Initial circular singly linked list: 10 -> 20 -> 30 -> back to 10 (head = 10)

// temp = head (node 10)

// do-while loop starts:

//   - Print 10, move temp to next (node 20), check: temp != head (20 != 10) → continue

//   - Print 20, move temp to next (node 30), check: temp != head (30 != 10) → continue

//   - Print 30, move temp to next (back to node 10), check: temp != head (10 != 10) → false, stop

// Final output: 10 <-> 20 <-> 30 <-> HEAD


// Time Complexity = O(N)

// Reason: We visit each node exactly once before coming back to head.


// Space Complexity = O(N)

// Reason: The list stores N nodes in memory. Extra variables (temp, head) use O(1) auxiliary space.
