// This is the simple program to insert a node at beggining of a doubly linked list in C programming language.


#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next ;

    struct Node* prev ; // The 'prev' pointer is used to store the address of the previous node in the doubly linked list. It allows traversal in both forward and backward directions, making it a doubly linked list.
    
};



struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = val;

    newNode -> prev  = NULL; 

    newNode -> next  = NULL;

    return newNode;

}

struct Node* insertAtBegin(struct Node* head, int value) {

    if(head == NULL) return head; 

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = value; 
    newNode -> prev = NULL; // The previous pointer of the new node is set to NULL because it will be the first node in the list, and there is no previous node to link to.

    newNode -> next = head; // The next pointer of the new node is set to point to the current head of the list, effectively linking the new node to the existing list.

    head -> prev = newNode;

    head = newNode;
    return head;
}


int main() {
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);  



    head -> next = second; // Link the first node to the second node
    second -> prev = head; // Link the second node back to the first node

    second -> next = third; // Link the second node to the third node
    third -> prev = second; // Link the third node back to the second node

    third -> next = NULL; // The next pointer of the last node is set to NULL to indicate the end of the list


    head = insertAtBegin(head, 200); // Insert a new node with value 200 at the beginning of the doubly linked list

    printf("Forward Traversal: ");

    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d", temp -> data);

        if(temp -> next != NULL) printf(" < - > ");        

        temp = temp -> next;
    }

    printf(" < - > NULL\n");

}



//                             =====================    Explanation    =====================

// insertAtBegin(head, value) does the following:

// Creates a new node using the same logic as createNode.

// Sets newNode -> prev = NULL because it will become the first node.

// Sets newNode -> next = head so the new node points to the old head.

// Sets head -> prev = newNode so the old head points back to the new node.

// Updates head = newNode and returns the new head.

// This is the only change compared to basic node creation: we carefully update 'next' and 'prev' so the new node becomes the new head while preserving the doubly linked structure.
 



//                            ======================    DRY RUN       ======================

// Initial doubly linked list: 10 <-> 20 <-> 30 <-> NULL (head = 10)

// newNode = 200, newNode -> prev = NULL, newNode -> next = head (200 <-> 10 <-> 20 <-> 30 <-> NULL)


// Time Complexity = O(N)
// Space Complexity = O(N)