// This is the simple program to demonstrate linked list traversal in C programming language.

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

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

int main()
{
    struct Node *head = createNode(10);
    struct Node *second = createNode(20);
    struct Node *third = createNode(30);

    head->next = second;
    second->next = third;
    third->next = NULL;

    // Traverse and print the linked list

    struct Node *temp = head; // Initially we set temp to head, so that we can traverse the linked list from the beginning

    // Why we are using 'temp' instead of directly saying print head -> data and move head -> next ? Because if we use head, then after traversing the linked list, head will point to NULL, and we will lose the reference to the linked list. So, we use 'temp' to traverse the linked list, and 'head' will still point to the first node of the linked list.

    printf("Linked List: ");

    while (temp != NULL)
    { // Imp Condition: Traverse the linked list until the end (when temp becomes NULL)

        printf("%d -> ", temp->data); // Print the data of the current node and an arrow to indicate the link to the next node
        temp = temp->next;            // Move the temporary pointer to the next node in the linked list
    }
    printf("NULL\n");
    return 0;
}

//                              =====================    Explanation    =====================

// We have created a singly linked list with three nodes having values 10, 20, and 30.

// We have linked the nodes in such a way that head points to the first node, second points to the second node, and third points to the third node. The next pointer of the last node (third) is set to NULL, indicating the end of the linked list.

// We have used a temporary pointer 'temp' to traverse the linked list. We start from the head and keep moving to the next node until we reach the end of the linked list (when temp becomes NULL).

// During each iteration, we print the data of the current node followed by an arrow to indicate the link to the next node. Finally, we print "NULL" to indicate the end of the linked list.


//                               ======================    DRY RUN       ======================

// Same as the previous dry run, the output will be: 10 -> 20 -> 30 -> NULL



// Time Complexity = O(N) since we need to traverse the linked list to find the last node
// Space Complexity = O(N) (for storing the nodes in memory)