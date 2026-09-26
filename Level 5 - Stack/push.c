// This is the simple program to push an element onto a stack using array in C programming language.

#include<stdio.h>

#define MAX 100

int main() {
    int stack[MAX];

    int top = -1;
    
    int value; // Variable to store user input


    // =====================    PUSH OPERATION    ======================

    printf("Enter value to push: ");
    scanf("%d", &value);  // Read value from user

    // Check if stack is full before pushing
    // top == MAX - 1 means all slots (0 to MAX - 1) are occupied
    
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return 0;
    }

     
    top++; // Increment top to point to the next available slot

     
    stack[top] = value; // Insert the new value at the top position

    printf("%d Pushed into stack.\n", value);


   // =====================    DISPLAY REMAINING ELEMENTS    ======================

    printf("Stack Elements:\n");    

    for(int i = top; i >= 0; i--) printf("%d\n", stack[i]);

    return 0;
}



//                                                          =====================    Explanation    ======================


// This program demonstrates the push operation on a stack implemented using an array.

// Step 1: Initialize stack array and set top = -1 (empty stack).

// Step 2: Read a value from the user to push onto the stack.

// Step 3: Check for stack overflow condition (top == MAX - 1).

//         - If top has reached the last valid index, no more elements can be added.

//         - This prevents writing beyond the array bounds.

// Step 4: Increment top to move to the next available position.

// Step 5: Store the new value at stack[top].

// Step 6: Print confirmation message showing the value was pushed.


//                                                          =====================    DRY RUN    ======================


// Initial state: stack array allocated, top = -1 (empty)

// User enters value: 50

// Check overflow: top (-1) != MAX - 1 (99), so stack is not full

// Increment top: top becomes 0

// Store value: stack[0] = 50

// Output: "50 Pushed into stack."

// Final state: stack = [50, _, _, ...], top = 0


// Time Complexity = O(1)
// Reason: All operations (input, comparison, increment, assignment) are constant time.

// Space Complexity = O(MAX) = O(1)
// Reason: We allocate a fixed array of 100 integers. Extra variables (top, value) use O(1) space.