// This is the simple program to convert an 'infix' expression to 'postfix' using a stack in C programming language.


#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

 
void push(char value) { // Push an operator into the stack
    stack[++top] = value;
}

 
char pop() { // Pop an operator from the stack
    return stack[top--];
}


int precedence(char operator) { // Return the priority of an operator
    if (operator == '^')
        return 3;

    if (operator == '*' || operator == '/')
        return 2;

    if (operator == '+' || operator == '-')
        return 1;

    return 0;
}

int main() {

    char infix[MAX];
    char postfix[MAX];

    int i = 0;
    int j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

     
    while (infix[i] != '\0') {  // Process every character of the infix expression

        char ch = infix[i];

        
        if (isalnum(ch)) {  // If operand(letter or digit), directly add it to postfix
            postfix[j++] = ch; 
        }

        
        else if (ch == '(') {  // If opening bracket, push it
            push(ch);
        }

        
        else if (ch == ')') {  // If closing bracket

             
            while (top != -1 && stack[top] != '(') { // Pop until opening bracket is found
                postfix[j++] = pop();
            }

             
            if (top != -1) // Remove the opening bracket
                pop();
        }

         
        else { // If operator

            
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {  // Pop higher/equal priority operators

                postfix[j++] = pop();
            }

            
            push(ch);  // Push current operator
        }

        i++;
    }

     
    while (top != -1) { // Pop remaining operators
        postfix[j++] = pop(); 
    }

    
    postfix[j] = '\0'; // Add string terminator

    printf("Postfix expression: %s\n", postfix);

    return 0;
}




//                                      =====================    Explanation    ======================

// This program converts an infix expression to postfix using a stack.

// Step 1: Read infix expression from user.
// Step 2: Scan each character from left to right.

// Step 3: If operand (letter/digit), add directly to postfix output.
// Step 4: If '(', push onto stack.

// Step 5: If ')', pop and add to postfix until '(' is found, then discard '('.
// Step 6: If operator, pop higher/equal precedence operators from stack to postfix, then push current operator.

// Step 7: After scanning entire expression, pop all remaining operators from stack to postfix.
// Step 8: Add null terminator and print the final postfix expression.

//                                      =====================    DRY RUN    ======================

// Input: a+b*c

// Initial: top = -1, postfix = "", stack = []
//
// i=0, ch='a' (operand):
//   - postfix[j++] = 'a' → postfix = "a"
//   - stack = []

//
// i=1, ch='+' (operator):
//   - Stack empty, so no pop
//   - push('+') → stack = ['+']
//   - postfix = "a"

//
// i=2, ch='b' (operand):
//   - postfix[j++] = 'b' → postfix = "ab"
//   - stack = ['+']

//
// i=3, ch='*' (operator):
//   - Check precedence: precedence('*') = 2, precedence('+') = 1
//   - 2 >= 1 is false, so no pop
//   - push('*') → stack = ['+', '*']
//   - postfix = "ab"

//
// i=4, ch='c' (operand):
//   - postfix[j++] = 'c' → postfix = "abc"
//   - stack = ['+', '*']

//
// i=5, ch='\0' (end of string):
//   - Exit main while loop

//
// Pop remaining operators:
//   - pop('*') → postfix = "abc*"
//   - pop('+') → postfix = "abc*+"
//   - stack = []

//
// Add null terminator: postfix = "abc*+\0"
// Final output: Postfix expression: abc*+

// Time Complexity = O(N)
// Reason: Each character is processed once, and each operator is pushed and popped at most once.

// Space Complexity = O(N)
// Reason: Stack and output arrays store up to N characters in worst case.