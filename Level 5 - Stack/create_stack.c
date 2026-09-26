// This is the simple program to create a stack using array in C programming language.

#include<stdio.h>

#define MAX 100


int main() {

    // Declare an array to store the stack elements
    // This array acts as the underlying storage for our stack

    int stack[MAX];

    // `top = -1` means the stack is currently empty.
    // top is an index pointer that tracks the position of the topmost element
    // -1 indicates no valid element exists yet (0-based indexing)

    int top = -1;

    printf("Stack created successfully \n ");
    printf("Initial top = %d\n", top);

    return 0;
}
//                                          =====================    Explanation    ======================

// This program initializes a static stack using a fixed-size array.

// Step 1: Define MAX = 100 to set the maximum number of elements the stack can hold.

// Step 2: Declare stack[MAX] array which will store all stack elements.

// Step 3: Initialize top = -1 to indicate the stack is empty.

//         - In 0-based indexing, valid indices are 0 to MAX-1.

//         - top = -1 means no element has been pushed yet.

//         - When we push the first element, top will become 0.

// Step 4: Print confirmation messages to verify stack initialization.




//                                          =====================    DRY RUN    ======================

// Program starts execution

// MAX is set to 100 (stack can hold up to 100 elements)

// stack array is allocated in memory with 100 integer slots

// top is initialized to -1 (empty stack indicator)

// Output: "Stack created successfully"

// Output: "Initial top = -1"

// Program ends


// Time Complexity = O(1)
// Reason: All operations (array declaration, variable initialization, printing) are constant time.

// Space Complexity = O(MAX) = O(1)
// Reason: We allocate a fixed array of 100 integers regardless of actual elements stored.
//         Since MAX is a constant, this is considered O(1) space.


