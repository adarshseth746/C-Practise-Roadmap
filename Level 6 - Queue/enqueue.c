// This is the simple program to insert an element into a queue using an array in C programming language.


#include<stdio.h>
#define MAX 100



int main() {

    int queue[MAX];
    
    int front = -1; 

    int rear = -1;

 
    int value;  // Variable to store the value to be inserted

    printf("Enter value to insert: "); 

    scanf("%d", &value);
 
    //                                      ====================== OVERFLOW CHECK   ======================


    if(rear == MAX - 1) { // If rear is at last position (MAX-1), no empty space remains in queue

        printf("Queue Overflow !\n");

        return 0;
    }

    if(front == -1) front = 0;  // If queue is empty (front == -1), set front to 0

    rear++;

    //                                      ======================  ENQUEUE  ======================

    queue[rear] = value;


    printf("%d inserted into the queue \n", value);


    //                                      ====================== DISPLAY ELEMENTS   ======================


    for(int i = front; i <= rear; i++) printf("%d ", queue[i]);

    return 0;
}






//                      =====================    Explanation    ======================

// This program demonstrates inserting (enqueueing) an element into a queue using an array.

// Step 1: Declare an array 'queue' of size MAX to store elements.

// Step 2: Initialize front and rear to -1 (indicating empty queue).

// Step 3: Read the value to be inserted from the user.

// Step 4: Check for overflow condition (rear == MAX-1 means queue is full).

// Step 5: If queue is empty (front == -1), set front to 0.

// Step 6: Increment rear to point to next available position.

// Step 7: Store the new value at queue[rear].

// Step 8: Display all elements from front to rear.


//                      =====================    DRY RUN    ======================

// Case 1: Inserting first element (queue is empty)
// Initial state:
//   front = -1, rear = -1
//   queue = [?, ?, ?, ...] (uninitialized)



// User input: value = 10
//
// Overflow check:
//   rear == MAX-1? → -1 == 99? → false (no overflow)
//
// Check if empty:
//   front == -1? → true
//   Set front = 0

//
// Increment rear:
//   rear++ → rear = 0

//
// Insert value:
//   queue[0] = 10
//   queue = [10, ?, ?, ...]
//   front = 0, rear = 0

//
// Display (for i = front to rear):
//   i = 0: print queue[0] → 10

//
// Output:
//   Enter value to insert: 10
//   10 inserted into the queue
//   10
//
// ---------------------------------------------------------
//
// Case 2: Inserting second element (queue already has elements)
// Assume queue already has: [10, 20, ?, ...] with front=0, rear=1
//
// User input: value = 30
//
// Overflow check:
//   rear == MAX-1? → 1 == 99? → false (no overflow)
//
// Check if empty:
//   front == -1? → 0 == -1? → false (skip)
//
// Increment rear:
//   rear++ → rear = 2
//
// Insert value:
//   queue[2] = 30
//   queue = [10, 20, 30, ...]
//   front = 0, rear = 2
//
// Display (for i = front to rear):
//   i = 0: print queue[0] → 10
//   i = 1: print queue[1] → 20
//   i = 2: print queue[2] → 30

//
// Output:
//   Enter value to insert: 30
//   30 inserted into the queue
//   10 20 30

// Time Complexity = O(N)
// Reason: Display loop iterates from front to rear (N elements).

// Space Complexity = O(MAX)
// Reason: Array of size MAX is allocated for the queue.