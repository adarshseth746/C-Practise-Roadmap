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

struct Node* delAtEnd(struct Node* head) {

    if (head == NULL) {
        printf("Linked list is empty \n");        
        return NULL;
    }


    struct Node* temp = head;

    while(temp -> next -> next != head) {

        temp = temp -> next;
    }


    struct Node* nodeToDelete = temp -> next;  // Save the last node

    temp -> next = head;  // Link second last node directly to head

    free(nodeToDelete);  // Free the SAVED last node

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

    head = delAtEnd(head);

    // Traversal
    
    temp = head; // Start from head

    do {

        printf("%d <-> ", temp->data);

        temp = temp->next;

    } while(temp != head); // Stop when we come back to head (circular condition)

    printf("HEAD\n");

    return 0;
}




//                              =====================    Explanation    ======================


// delAtEnd(head) deletes the LAST node of a circular linked list.

// Step 1: Check if head is NULL (list empty). If yes, print message and return NULL.


// Step 2: Handle special case where list has only one node (head->next == head).

//         - Free that single node and return NULL.


// Step 3: Use temp to traverse until the SECOND LAST node.

//         - Condition: temp -> next -> next != head

//         - This stops when temp -> next is the last node and temp->next->next is head.


// Step 4: Save the last node in nodeToDelete pointer (temp -> next).


// Step 5: Set temp -> next = head.

//         - The second last node now points directly to head.

//         - This removes the last node from the circular chain.

// Step 6: Free nodeToDelete to remove the last node from memory.

// Step 7: Return head (head does not change when deleting from end).



//                              =====================    DRY RUN    ======================



// Initial circular singly linked list: 10 -> 20 -> 30 -> back to 10 (head = 10)

// Call delAtEnd(head)

// temp starts at head (10)

// Loop: temp -> next -> next != head
 
//   - temp = 10: temp -> next = 20, temp -> next -> next = 30 (≠ head) → move temp to 20

//   - temp = 20: temp -> next = 30, temp -> next -> next = 10 (= head) → loop stops

// Now temp is at second last node (20)

// nodeToDelete = temp -> next  =>  nodeToDelete = 30 (save last node)

// temp -> next = head  =>  20 -> next = 10 (second last now points to head)

// free(nodeToDelete)  =>  node 30 is deleted from memory

// Final circular list: 10 -> 20 -> back to 10

// Traversal prints: 10 <-> 20 <-> HEAD


// Time Complexity = O(N)
// Reason: We traverse from head to the second last node.

// Space Complexity = O(N)
// Reason: The list stores N nodes in memory. Extra variables (temp, head, nodeToDelete) use O(1) auxiliary space.