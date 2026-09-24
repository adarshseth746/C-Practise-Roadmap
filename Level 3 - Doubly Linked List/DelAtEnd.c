// This is the simple program to delete a node at beggining of a doubly linked list in C programming language.


#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int value) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));


    newNode -> data = value;
    newNode -> next  = NULL;
    newNode -> prev  = NULL;

    return newNode;
} 


struct Node* delAtEnd(struct Node* head) {
    if(head == NULL) {

        printf("Linked list is empty \n");

        return NULL;
    }   


    struct Node* temp = head;

    while(temp -> next != NULL) {
        temp = temp -> next; // Move temp forward until it reaches the last node
    }

    temp -> next = NULL; // Attempt to "remove" last node by setting its next to NULL (but does not free it)

    return head; // Return the new head of the list

}


int main() {
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);  


    head -> next = second; 
    second -> prev = head; 

    second -> next = third; 
    third -> prev = second; 

    third -> next = NULL;


    head = delAtEnd(head); 

    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d", temp -> data);

        if(temp -> next != NULL) printf(" < - > ");        

        temp = temp -> next;
    }

    printf(" < - > NULL\n");   
}


 
//                                       =====================    Explanation    ======================

// delAtBegin(head) is intended to delete the LAST node of the doubly linked list.

// Step 1: Check if head is NULL (list empty). If yes, print message and return NULL.

// Step 2: Use temp to traverse from head until the last node (where temp->next == NULL).

// Step 3: After the loop, temp points to the last node.

// Step 4: Set temp->next = NULL (this does not actually remove the node from the list).

// Step 5: Return head (head does not change when deleting from the end).

// Note: This version does NOT free the last node or update the new last node's next/prev correctly, so memory is leaked and the list structure is not fully fixed.




//                                       =====================    DRY RUN    ======================

// Initial doubly linked list: 10 <-> 20 <-> 30 <-> NULL (head = 10)

// temp starts at head (node 10)

// Loop moves temp: 10 → 20 → 30 (now temp -> next == NULL, so loop stops)

// temp is now at last node (30)

// temp -> next = NULL  =>  30 -> next is set to NULL (already NULL, so no real change)

// No free() is called and second->next is not updated, so node 30 remains in the list

// Final list: 10 <-> 20 <-> 30 <-> NULL

// Forward traversal prints: 10 < - > 20 < - > 30 < - > NULL



// Time Complexity = O(N)
// Reason: We traverse from head to the last node, visiting each node once.

// Space Complexity = O(N)
// Reason: The list stores N nodes in memory. Extra variables (temp, head) use O(1) auxiliary space.