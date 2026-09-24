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


struct Node* delAtBegin(struct Node* head) {
    if(head == NULL) {

        printf("Linked list is empty \n");

        return NULL;
    }   


    struct Node* temp = head;

    head = head -> next; // Move head to the next node

    head -> prev = NULL; // Set the previous pointer of the new head to NULL

    free(temp); // Free the memory of the old head node
    
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


    head = delAtBegin(head); 

    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d", temp -> data);

        if(temp -> next != NULL) printf(" < - > ");        

        temp = temp -> next;
    }

    printf(" < - > NULL\n");   
}


//                                  ====================    Explanation    ======================


// delAtBegin(head) deletes the first node of the doubly linked list.

// Step 1: Check if head is NULL (list empty). If yes, print message and return NULL.

// Step 2: Store current head in temp so we can free it later.

// Step 3: Move head to head -> next (second node becomes new head).

// Step 4: If new head exists, set head -> prev = NULL (no node before new head).

// Step 5: Free temp (old head node) to remove it from memory.

// Step 6: Return new head so main() can update its head pointer.



//                                  =====================    DRY RUN    ======================

// Initial doubly linked list: 10 <-> 20 <-> 30 <-> NULL (head = 10)

// temp = head (node 10)

// head = head -> next  =>  head now points to node 20

// head -> prev = NULL  =>  node 20's prev becomes NULL

// free(temp)  =>  node 10 is deleted from memory

// Final list: NULL <- 20 <-> 30 -> NULL

// Forward traversal prints: 20 < - > 30 < - > NULL

// Time Complexity = O(1)
// Space Complexity = O(N)
    