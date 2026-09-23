// This is the simple program to demonstrate deletion at the beginning of a linked list in C programming language.

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

struct Node* deleteFromBeginning(struct Node* head) { // Function to delete a node from the beginning of the linked list

    if(head == NULL) { // If the linked list is empty, there is nothing to delete, so we return the head as it is (which is NULL)

        printf("List is empty. Cannot delete from beginning.\n");
        return head;
    }

    struct Node* temp = head; // Store the node to be deleted

    head = head -> next; // Update the head of the linked list to point to the next node, effectively removing the first node from the list

    free(temp); // Free the memory allocated for the deleted node to avoid memory leaks

    return head;
}



int main() {

    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head -> next = second;
    second -> next  = third;
    third -> next  = NULL;

    head = deleteFromBeginning(head); // Delete the node from the beginning of the linked list

    // Traverse and print the linked list to verify the deletion

    struct Node* temp = head;

    printf("Linked List after deletion from the beginning: ");

    while(temp != NULL) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }

    printf("NULL \n");
    return 0;
}


//                            =====================    Explanation    =====================

// In the 'deleteFromBeginning' function, we first check if the linked list is empty (i.e., if the head is NULL). If it is empty, we print a message indicating that deletion cannot be performed and return the head as it is (which is NULL).

// If the linked list is not empty, we update the head of the linked list to point to the next node, effectively removing the first node from the list.

// Finally, we free the memory allocated for the deleted node using the free() function to avoid memory leaks and return the updated head of the linked list.


//                           ======================    DRY RUN       ======================

// Initial linked list: 10 -> 20 -> 30 -> NULL (head = 10)

// Delete the node from the beginning of the linked list:

// temp  = head (temp points to the node with value 10)
// head = head -> next (head now points to the node with value 20)
// free(temp) (the node with value 10 is deleted and its memory is freed)

// Final linked list after deletion: 20 -> 30 -> NULL (head = 20)



// Time Complexity = O(1) since the node which has to be deleted is head itself
// Space Complexity = O(N) (for storing the nodes in memory)