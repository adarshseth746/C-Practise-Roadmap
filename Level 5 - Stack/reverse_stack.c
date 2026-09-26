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
    stack[++top] = 50;
    stack[++top] = 60;

    printf("Original stack:\n");

    for(int i = top; i >= 0; i--) printf("%d\n", stack[i]);

    printf("\n");


    // =====================    REVERSE OPERATION    ======================

    int start = 0, end = top;

    while(start < end) {
        int temp = stack[start];
        stack[start] = stack[end];

        stack[end] = temp;

        start++;
        end--;
    }


    // =====================    DISPLAY ELEMENTS    =====================

    printf("Reversed elements:\n");      

    for(int i = top; i >= 0; i--) printf("%d\n", stack[i]);
}