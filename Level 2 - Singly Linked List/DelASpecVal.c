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

struct Node* deleteNode(struct Node* head, int targetVal) { // Function to delete a node from the end of the linked list

    if(head == NULL) { // If the linked list is empty, there is nothing to delete, so we return the head as it is (which is NULL)

        printf("List is empty. Cannot delete from any value.\n");
        return head;
    }

    struct Node* temp = head; // Store the node to be deleted
    
    struct Node* prev = NULL; // Create a pointer to keep track of the previous node (which will be NULL for the first node)

    while(temp != NULL && temp -> data != targetVal) {
        prev = temp; // Move the previous pointer to the current node
        temp = temp -> next; // Move the temporary pointer to the next node in the linked list
    }

    // There are 3 cases after condition check:

    //  1. If the target value is not found in the linked list (temp == NULL) 

    if(temp == NULL) { // If the target value is not found in the linked list

        printf("Value %d not found in the list. Cannot delete.\n", targetVal);

        return head;
    }

    //  2. If the target value is found at the head of the linked list (prev == NULL and temp != NULL)

    if(prev == NULL) { // If the target value is found at the head of the linked list

        head = head -> next; // Update the head of the linked list to point to the next node, effectively removing the first node from the list
    } 

    //  3. If the target value is found somewhere in the middle or end of the linked list (prev != NULL and temp != NULL)

    else {
        prev -> next  = temp -> next; // Update the previous node's next pointer to skip the node to be deleted
    }

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

    head = deleteNode(head, 20); // Delete the node with value 20 from the linked list

    // Traverse and print the linked list to verify the deletion

    struct Node* temp = head;

    printf("Linked List after deletion: ");

    while(temp != NULL) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }

    printf("NULL \n");
    return 0;
}


//                            =====================    Explanation    =====================

// In the 'deleteNode' function, we first check if the linked list is empty (i.e., if the head is NULL). If it is empty, we print a message indicating that deletion cannot be performed and return the head as it is (which is NULL).

// If the linked list is not empty, we traverse the list to find the node with the target value and its previous node.

// Then, we update the previous node's next pointer to skip the node to be deleted, effectively removing it from the list.

// Finally, we free the memory allocated for the deleted node using the free() function to avoid memory leaks and return the updated head of the linked list.

// MOST IMPORTANTLY, notice that 3 cases are handled in the code:
// 1. If the target value is not found in the linked list (temp == NULL)
// 2. If the target value is found at the head of the linked list (prev == NULL and temp != NULL)
// 3. If the target value is found somewhere in the middle or end of the linked list (prev != NULL and temp != NULL)


//                           ======================    DRY RUN       ======================

// Initial linked list: 10 -> 20 -> 30 -> NULL (head = 10)

// Delete the node from the beginning of the linked list:

// temp  = head (temp points to the node with value 10)
// head = head -> next (head now points to the node with value 20)
// free(temp) (the node with value 10 is deleted and its memory is freed)

// Final linked list after deletion: 20 -> 30 -> NULL (head = 20)

// Time Complexity
// For Best Case, when the element is present at the first position = O(1)
// For Average and Worst  Case, when the element is present at the middle or last position = O(n)

// Space Complexity = O(N) (for storing the nodes in memory)