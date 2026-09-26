// This is the simple program to demonstrate push and pop operations on a stack using array in C programming language.


#include<stdio.h>

#define MAX 100


int main() {
    
    int stack[MAX];

    int top = -1;


    // =====================    PUSH OPERATION    ======================

    stack[++top] = 10;  
    stack[++top] = 20;  
    stack[++top] = 30; 
    
    

    // =====================    POP OPERATION    ======================

    
    if(top == -1) { // Check for stack underflow before popping

        printf("Stack Underflow !\n");
        return 0;
    }

    
    int deletedElement = stack[top]; // Retrieve top element and decrement top
    top--;

    printf("Pooped element: %d\n", deletedElement);


    // =====================    DISPLAY REMAINING ELEMENTS    ======================
 

    if (top == -1) printf("Stack is now empty.\n");

    else {

        printf("Stack Elements:\n");

        for (int i = top; i >= 0; i--) printf("%d\n", stack[i]);

    }

    return 0;
}


//                                          =====================    Explanation    ======================


// This program demonstrates pushing 3 elements, popping 1, then displaying the rest.

// PUSH SECTION:

// Step 1: Push 10 using pre-increment (++top = 0, stack[0] = 10).
// Step 2: Push 20 using pre-increment (++top = 1, stack[1] = 20).
// Step 3: Push 30 using pre-increment (++top = 2, stack[2] = 30).

//         - After all pushes: stack = [10, 20, 30], top = 2
//
// POP SECTION:

// Step 4: Check for underflow (top == -1) before popping.

// Step 5: Retrieve stack[top] (stack[2] = 30), decrement top to 1.

// Step 6: Print the popped element (30).


// DISPLAY SECTION:

// Step 7: Check if stack is empty (top == -1).

// Step 8: If not empty, loop from top (1) down to 0 and print remaining elements.




//                                          =====================    DRY RUN    ======================


// Initial state: stack array allocated, top = -1 (empty)

// PUSH:

//   - stack[++top] = 10: top becomes 0, stack[0] = 10
//   - stack[++top] = 20: top becomes 1, stack[1] = 20
//   - stack[++top] = 30: top becomes 2, stack[2] = 30

// Current state: stack = [10, 20, 30], top = 2

//

// POP:

//   - Check underflow: top (2) != -1, so stack is not empty
//   - deletedElement = stack[2] = 30
//   - top--: top becomes 1

//   - Output: "Popped element: 30"

// Current state: stack logically = [10, 20], top = 1

//
// DISPLAY:

//   - Check: top (1) != -1, so stack is not empty
//   - Loop from i = 1 to 0:
//       i = 1: print stack[1] = 20
//       i = 0: print stack[0] = 10

// Final output:

// Popped element: 30
// Stack Elements:
// 20
// 10


// Time Complexity = O(N)
// Reason: Push and pop are O(1), but display loop iterates through N elements in worst case.

// Space Complexity = O(MAX) = O(1)
// Reason: We allocate a fixed array of 100 integers. Extra variables (top, deletedElement, i) use O(1) space.