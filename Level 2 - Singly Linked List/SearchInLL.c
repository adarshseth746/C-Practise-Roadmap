// This is the simple program to demonstrate search operation in the linked list in C programming language.

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *createNode(int value) {
    struct Node *newNode;
    
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

struct Node* searchInLL(struct Node *head, int targetVal) {
    struct Node* temp = head;

    while(temp != NULL) {

        // Imp Step: Check if the current node's data matches the target value. If it does, return the pointer to that node.

        if(temp->data == targetVal) return temp;
        temp = temp->next;
    }

    // If the target value is not found in the linked list, return NULL to indicate that the search was unsuccessful.

    return NULL;
}

int main() {
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head->next = second;
    second->next = third;
    third->next = NULL;

    struct Node* foundVal = searchInLL(head, 10); // Search for the target value 10 in the linked list

    if(foundVal != NULL) printf("Target Found !"); // Most Importantly, returned value will be a pointer to the node containing the target value, not the value itself. Hence, we check if the returned pointer is not NULL to determine if the target was found.

    else printf("Target Not Found !");

    return 0;
}






//                             =====================    Explanation    =====================

// The 'searchInLL' function takes the head of the linked list and the target value to search for as input parameters.

// It traverses the linked list using 'temp' and checks if the data of each node matches the target value.

// If a match is found, it returns the pointer to that node. If the end of the list is reached without finding the target value, it returns NULL to indicate that the search was unsuccessful.

// In the 'main' function, we create a linked list with three nodes containing values 10, 20, and 30. We then call the 'searchInLL' function to search for the target value 10 in the linked list. If the target is found, we print "Target Found !", otherwise we print "Target Not Found !".



//                            ======================    DRY RUN       ======================


// Initial linked list: 10 -> 20 -> 30 -> NULL (head = 10)

// temp = head 10: Check if temp->data (10) == targetVal (10) -> True, return pointer to node containing 10


// Let's have another instance where our target is 15

// Initial linked list: 10 -> 20 -> 30 -> NULL (head = 10)

// temp = head 10: Check if temp->data (10) == targetVal (15) -> False, move to next node
// temp = second 20: Check if temp->data (20) == targetVal (15) -> False, move to next node
// temp = third 30: Check if temp->data (30) == targetVal (15) -> False, move to next node
// temp = NULL: End of list reached, return NULL to indicate that the target value was not found in the linked list.



// Time Complexity :

// If the target value is found at the head of the linked list, the time complexity is O(1) since we only need to check the first node.
// If the target value is found at the end of the linked list or not found at all, the time complexity is O(N) since we need to traverse the entire linked list to find the target value or determine that it is not present.

// Space Complexity = O(N) (for storing the nodes in memory)