// This is the simple program to show the top element of a stack using array in C programming language.

// This simply displays the top element of the stack without removing it.

#include<stdio.h>

#define MAX 100

int main() {
    int stack[MAX];

    int top = -1;

    // =====================    PUSH OPERATION    ======================
    
    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;

    if(top == -1) {
        printf("Stack is empty.\n");
        return 0;
    }

    // =====================    PEEK OPERATION    ======================

    printf("Top Element: \n%d ", stack[top]);


   // =====================    DISPLAY ELEMENTS    ======================

    printf("Stack Elements:\n");    

    for(int i = top; i >= 0; i--) printf("%d\n", stack[i]);

    return 0;
}

// Time Complexity = O(1)
// Reason: All operations are constant time, no loops involved.

// Space Complexity = O(MAX) = O(1)
// Reason: Fixed array of 100 integers. Extra variables use O(1) space.