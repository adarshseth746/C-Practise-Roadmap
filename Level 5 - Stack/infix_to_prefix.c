// This is the simple program to convert an infix expression to prefix using a stack in C programming language.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];

int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

 
void reverse(char str[]) // Reverse a string in place
{
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char infix[MAX];   
    char prefix[MAX];  

    printf("Enter infix expression: ");
    scanf("%s", infix);

    
    reverse(infix);  // Step 1: Reverse the infix expression

     
    for (int i = 0; infix[i] != '\0'; i++) // Step 2: Swap brackets after reversing
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    int i = 0; // Index for reversed infix
    int j = 0; // Index for prefix output


    while (infix[i] != '\0') // Step 3: Convert reversed expression to postfix (which becomes prefix after final reverse)
    {
        char ch = infix[i];

       
        if (isalnum(ch))
        {
            prefix[j++] = ch;
        }

        
        else if (ch == '(')
        {
            push(ch);
        }

        
        else if (ch == ')')
        {
           
            while (top != -1 && stack[top] != '(')
            {
                prefix[j++] = pop();
            }
            // Remove the opening bracket
            if (top != -1)
                pop();
        }

        else
        {
           
            while (top != -1 && precedence(stack[top]) > precedence(ch))
            {
                prefix[j++] = pop();
            }
            push(ch);
        }

        i++;
    }

    while (top != -1)
    {
        prefix[j++] = pop();
    }

    prefix[j] = '\0'; 

     
    reverse(prefix); // Step 4: Reverse the result to get final prefix expression

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

//                                      =====================    Explanation    ======================

// This program converts infix to prefix using three main steps.

// Step 1: Reverse the infix expression (left to right becomes right to left).

// Step 2: Swap all '(' with ')' and vice versa (because reversing flips bracket meaning).

// Step 3: Convert the modified expression to postfix using stack logic.
//         - Operands go directly to prefix output.
//         - Operators are managed using stack with precedence rules.
//         - Note: For prefix, we use > (not >=) when comparing precedence.

// Step 4: Reverse the postfix result to get the final prefix expression.



//                                      =====================    DRY RUN    ======================

// Input: A+B*C
//
// Step 1: Reverse infix
//   - Original: A+B*C
//   - Reversed: C*B+A
//
// Step 2: Swap brackets
//   - No brackets in C*B+A, so no change
//   - Modified expression: C*B+A
//
// Step 3: Convert to postfix (scanning left to right)
// Initial: top = -1, prefix = "", stack = []
//
// i=0, ch='C' (operand):
//   - prefix[j++] = 'C' → prefix = "C"
//   - stack = []
//
// i=1, ch='*' (operator):
//   - Stack empty, so no pop
//   - push('*') → stack = ['*']
//   - prefix = "C"
//
// i=2, ch='B' (operand):
//   - prefix[j++] = 'B' → prefix = "CB"
//   - stack = ['*']
//
// i=3, ch='+' (operator):
//   - precedence('*') = 2, precedence('+') = 1
//   - 2 > 1 is true, so pop '*' → prefix = "CB*"
//   - Stack now empty, push '+' → stack = ['+']
//   - prefix = "CB*"
//
// i=4, ch='A' (operand):
//   - prefix[j++] = 'A' → prefix = "CB*A"
//   - stack = ['+']
//
// i=5, ch='\0' (end of string):
//   - Exit main while loop
//
// Pop remaining operators:
//   - pop('+') → prefix = "CB*A+"
//   - stack = []
//
// Step 4: Reverse the result
//   - "CB*A+" reversed → "+A*BC"

//
// Final output: Prefix expression: +A*BC
// (Which means: +(A, *(B, C)) or A + (B * C) in prefix notation)


// Time Complexity = O(N)
// Reason: We reverse twice (O(N) each) and scan the expression once (O(N)).

// Space Complexity = O(N)
// Reason: Stack and output arrays store up to N characters.