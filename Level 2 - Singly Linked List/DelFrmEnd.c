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

struct Node* deleteFromEnd(struct Node* head) { // Function to delete a node from the end of the linked list

    if(head == NULL) { // If the linked list is empty, there is nothing to delete, so we return the head as it is (which is NULL)

        printf("List is empty. Cannot delete from end.\n");
        return head;
    }

    struct Node* temp = head; // Store the node to be deleted
    
    struct Node* prev = NULL; // Create a pointer to keep track of the previous node (which will be NULL for the first node)

    while(temp -> next) {
        prev = temp; // Move the previous pointer to the current node
        temp = temp -> next; // Move the temporary pointer to the next node in the linked list
    }

    prev -> next  = temp -> next; // Update the previous node's next pointer to skip the node to be deleted (which is the last node in this case)
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

    head = deleteFromEnd(head); // Delete the node from the end of the linked list

    // Traverse and print the linked list to verify the deletion

    struct Node* temp = head;

    printf("Linked List after deletion from the end: ");

    while(temp != NULL) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }

    printf("NULL \n");
    return 0;
}


//                            =====================    Explanation    =====================

// In the 'deleteFromEnd' function, we first check if the linked list is empty (i.e., if the head is NULL). If it is empty, we print a message indicating that deletion cannot be performed and return the head as it is (which is NULL).

// If the linked list is not empty, we traverse the list to find the last node and its previous node.

// Then, we update the previous node's next pointer to NULL, effectively removing the last node from the list.

// Finally, we free the memory allocated for the deleted node using the free() function to avoid memory leaks and return the updated head of the linked list.

// How actually 'prev' did the job of deleting the last node? Let's understand it step by step:

// 1. We start with the head of the linked list and initialize 'temp' to point to the head node and 'prev' to NULL.

// 2. We enter a while loop that continues until 'temp' reaches the last node (when 'temp->next' is NULL).

// 3. Inside the loop, we update 'prev' to point to the current 'temp' node and then move 'temp' to the next node in the list so that 'temp' eventually points to the last node and 'prev' points to the second-to-last node.

// 4. After the loop, 'prev' points to the second-to-last node, and 'temp' points to the last node. We then update 'prev->next' to temp -> next which is NULL, effectively removing the last node from the list. Finally, we free the memory allocated for 'temp' (the last node) to avoid memory leaks.


//                           ======================    DRY RUN       ======================

// Initial linked list: 10 -> 20 -> 30 -> NULL (head = 10)

// Delete the node from the beginning of the linked list:

// temp  = head (temp points to the node with value 10)
// head = head -> next (head now points to the node with value 20)
// free(temp) (the node with value 10 is deleted and its memory is freed)

// Final linked list after deletion: 20 -> 30 -> NULL (head = 20)