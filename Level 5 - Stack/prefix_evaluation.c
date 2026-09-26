// This is the simple program to evaluate a prefix expression using a stack in C programming language.

#include<stdio.h>
#include<ctype.h>
#include<string.h>


#define MAX 100

int stack[MAX];

int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}


int main() {

    char prefix[MAX];

    printf("Enter postfix expression: ");

    scanf("%s", &prefix);

    int i = strlen(prefix) - 1; // Process each character from right to left

    while(i >= 0) {

        char ch = prefix[i];

        if(isdigit(ch)) push(ch - '0');

       else { 
            
            int operand2 = pop(); 
            int operand1 = pop(); 

            int result;


            switch(ch) {
                case '+':
                result = operand1 + operand2;
                break;

                case '-':
                result = operand1 - operand2;
                break;

                case '*':
                result = operand1 * operand2;
                break;

                case '/':
                result = operand1 / operand2;
                break;

                default:
                printf("Invalid Elements:\n");
                return 0;
            }

            push(result); // Push the result back onto stack
        }

        i--;
    }


    printf("Result: %d\n", pop());

}




//                                  =====================    Explanation    ======================

// This program evaluates a prefix (Polish Notation) expression using a stack.

// Step 1: Read prefix expression as a string from the user.

// Step 2: Start scanning from RIGHT to LEFT (end of string to beginning).

// Step 3: If digit, convert from char to int (ch - '0') and push onto stack.

// Step 4: If operator (+, -, *, /), pop two operands from stack.

//         - First pop gives operand2 (right operand).

//         - Second pop gives operand1 (left operand).

//         - Perform the operation and push the result back onto stack.

// Step 5: After processing all characters, the final result is the only value left in stack.

// Step 6: Print the result.

// Why scan RIGHT to LEFT for prefix?

// - In prefix notation, operators come BEFORE their operands (e.g., + 2 3 means 2+3).
// - Scanning right to left ensures we see operands first, then operators.
// - This is similar to postfix evaluation (left to right), but reversed direction.



//                                  =====================    DRY RUN    ======================

// Input: *+235
// Meaning: (2 + 3) * 5 = 5 * 5 = 25
// Prefix: * + 2 3 5  →  *(+(2,3), 5)


// String: *+235
// Index:  01234
// Length = 5, so i starts at 4 (rightmost character)
//
// Initial: top = -1, stack = []
//
// i=4, ch='5' (digit):
//   - push('5' - '0') → push(5)
//   - stack = [5]


//
// i=3, ch='3' (digit):
//   - push('3' - '0') → push(3)
//   - stack = [5, 3]


//
// i=2, ch='2' (digit):
//   - push('2' - '0') → push(2)
//   - stack = [5, 3, 2]


//
// i=1, ch='+' (operator):
//   - operand2 = pop() → 2
//   - operand1 = pop() → 3
//   - result = 3 + 2 = 5
//   - push(5)
//   - stack = [5, 5]


//
// i=0, ch='*' (operator):
//   - operand2 = pop() → 5
//   - operand1 = pop() → 5
//   - result = 5 * 5 = 25
//   - push(25)
//   - stack = [25]


//
// i=-1 (end of loop):

//   - Exit while loop
//
// Final: pop() → 25

// Output: Result: 25

// Time Complexity = O(N)
// Reason: Each character is processed once, and each operand is pushed and popped at most once.

// Space Complexity = O(N)
// Reason: Stack stores up to N/2 operands in worst case (all digits before operators).