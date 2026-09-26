// This is the simple program to find the size of a stack using array in C programming language.

// This simply calculates and displays the current number of elements in the stack.

#include<stdio.h>

#define MAX 100

int main() {

    int stack[MAX];

    int top = -1;

    // =====================    PUSH OPERATION    ======================
    

    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;
    stack[++top] = 40;


    int stack_size = top + 1;


    printf("Stack size: %d\n", stack_size);

    return 0;
}


//                      =====================    Explanation    ======================

// This program pushes 4 elements and calculates the current stack size.

// Step 1: Push 10, 20, 30, 40 onto the stack using pre-increment.

// Step 2: After all pushes, top = 3 (index of last element).

// Step 3: Calculate size as top + 1 (converting 0-based index to count).

// Step 4: Print the stack size (4 elements).



// Time Complexity = O(1)
// Reason: All operations are constant time, no loops involved.

// Space Complexity = O(MAX) = O(1)
// Reason: Fixed array of 100 integers. Extra variables use O(1) space.
