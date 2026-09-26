// This is the simple program to diplay a stack in C programming language.

#include<stdio.h>

#define MAX 100


int main() {

    int stack[MAX];
    int top = -1;

    // Push elements onto the stack
    // Pre-increment (++top) increments top first, then uses the new index

    stack[++top] = 10;  // top becomes 0, stack[0] = 10
    stack[++top] = 20;  // top becomes 1, stack[1] = 20
    stack[++top] = 30;  // top becomes 2, stack[2] = 30

    // Check if stack is empty before displaying

    if(top == -1) {
        printf("Stack is empty !");
        return 0;
    }  


    // =====================    DISPLAY ELEMENTS    =====================

    printf("Stack Elements:\n");
    
    // Start from TOP since Stack follows LIFO (Last In First Out)
    // Traverse from top index down to 0 to display elements in stack order

    for(int i = top; i >= 0; i--) printf("%d\n", stack[i]);
    return 0;
}

//                                             =====================    Explanation    ======================


// This program demonstrates pushing elements onto a stack and displaying them in LIFO order.

// Step 1: Initialize stack array and set top = -1 (empty stack).

// Step 2: Push 10, 20, 30 onto the stack using pre-increment operator.

//         - ++top increments top before using it as index.

//         - First push: top = 0, stack[0] = 10
//         - Second push: top = 1, stack[1] = 20
//         - Third push: top = 2, stack[2] = 30

// Step 3: Check if stack is empty (top == -1) before displaying.

//         - If empty, print message and exit early.

// Step 4: Display elements from top to bottom (LIFO order).

//         - Loop starts at top index (2) and decrements down to 0.

//         - This shows the most recently added element first (30, then 20, then 10).


//                                                   =====================    DRY RUN    ======================


// Initial state: stack array allocated, top = -1 (empty)

// Push 10: ++top makes top = 0, stack[0] = 10
// Push 20: ++top makes top = 1, stack[1] = 20
// Push 30: ++top makes top = 2, stack[2] = 30

// Current stack: [10, 20, 30] with top = 2

// Check empty: top (2) != -1, so stack is not empty, continue

// Display loop:
//   - i = 2: print stack[2] = 30
//   - i = 1: print stack[1] = 20
//   - i = 0: print stack[0] = 10


// Final output:

// Stack Elements:
// 30
// 20
// 10

// Time Complexity = O(N)
// Reason: We iterate through all N elements once to display them.

// Space Complexity = O(MAX) = O(1)
// Reason: We allocate a fixed array of 100 integers. Extra variables (top, i) use O(1) space.