// This is the simple program to evaluate a postfix expression using a stack in C programming language.

#include<stdio.h>
#include<ctype.h>


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
    char postfix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", &postfix);

    int i = 0;


    while(postfix[i] != '\0') { // Process each character of the postfix expression
        char ch = postfix[i];

        // If character is a digit, convert to integer and push onto stack

        if(isdigit(ch)) push(ch - '0');   // '0' -> 0, '1' -> 1, ..., '9' -> 9

        
        else { // If character is an operator, pop two operands, evaluate, and push 
            
            int operand2 = pop(); // Second operand (top of stack)
            int operand1 = pop(); // First operand (below top)

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

        i++;
    }
   
    printf("Result: %d\n", pop()); // Final result is the only element left in stack

    return 0;
}




//                          =====================    Explanation    ======================

// This program evaluates a postfix (Reverse Polish Notation) expression using a stack.

// Step 1: Read postfix expression as a string from the user.

// Step 2: Scan each character from left to right.

// Step 3: If digit, convert from char to int (ch - '0') and push onto stack.

// Step 4: If operator (+, -, *, /), pop two operands from stack.

//         - First pop gives operand2 (right operand).

//         - Second pop gives operand1 (left operand).

//         - Perform the operation and push the result back onto stack.

// Step 5: After processing all characters, the final result is the only value left in stack.

// Step 6: Print the result.

// Note: Postfix evaluation works because operators always come after their operands,
//       so we can evaluate as we go using a stack to store intermediate results.




//                          =====================    DRY RUN    ======================

// Input: 23+5*
// Meaning: (2 + 3) * 5 = 5 * 5 = 25
//
// Initial: top = -1, stack = []
//
// i=0, ch='2' (digit):
//   - push('2' - '0') → push(2)
//   - stack = [2]


//
// i=1, ch='3' (digit):
//   - push('3' - '0') → push(3)
//   - stack = [2, 3]


//
// i=2, ch='+' (operator):
//   - operand2 = pop() → 3
//   - operand1 = pop() → 2
//   - result = 2 + 3 = 5
//   - push(5)
//   - stack = [5]


//
// i=3, ch='5' (digit):
//   - push('5' - '0') → push(5)
//   - stack = [5, 5]


//
// i=4, ch='*' (operator):
//   - operand2 = pop() → 5
//   - operand1 = pop() → 5
//   - result = 5 * 5 = 25
//   - push(25)
//   - stack = [25]


//
// i=5, ch='\0' (end of string):
//   - Exit while loop

//
// Final: pop() → 25

// Output: Result: 25

// Time Complexity = O(N)
// Reason: Each character is processed once, and each operand is pushed and popped at most once.

// Space Complexity = O(N)
// Reason: Stack stores up to N/2 operands in worst case (all digits before operators).