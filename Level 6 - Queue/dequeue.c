// This is the simple program to delete an element from a queue using an array in C programming language.


#include<stdio.h>
#define MAX 100



int main() {

    int queue[MAX];
    
    int front = -1; 

    int rear = -1;


    queue[++rear] = 10;

    front = 0;

    queue[++rear] = 20;
    queue[++rear] = 30;


    //                           ===================== UNDERFLOW CHECK ======================

    if(front == -1 || front > rear) {
        printf("Queue Underflow ! \n");
        return 0;
    }


    //                                            ======================   DEQUEUE  ======================

    // Delete element from front of queue

    int delEle = queue[front];  // Store deleted element (queue[0] = 10)

    front++;  // Move front to next element (front becomes 1)


    // If queue becomes empty after deletion, reset front and rear to -1

    if(front > rear) {
        front = -1;
        rear = -1;
    }


    //                                      =====================  DISPLAY ELEMENTS  AFTER DEQUEUE   ======================


    for(int i = front; i <= rear; i++) printf("%d ", queue[i]);     
}



// =====================    Explanation    ======================

// This program demonstrates deleting (dequeuing) an element from a queue using an array.

// Step 1: Declare an array 'queue' of size MAX to store elements.

// Step 2: Initialize front and rear to -1 (indicating empty queue).

// Step 3: Enqueue three elements (10, 20, 30) by incrementing rear and storing values.

// Step 4: Set front to 0 to mark the start of the queue.

// Step 5: Check for underflow condition (front == -1 || front > rear means queue is empty).

// Step 6: Store the front element in delEle (element to be deleted).

// Step 7: Increment front to remove the element from the queue.

// Step 8: If queue becomes empty (front > rear), reset front and rear to -1.

// Step 9: Display remaining elements from new front to rear.



// =====================    DRY RUN    ======================

// Initial state:
//   front = -1, rear = -1
//   queue = [?, ?, ?, ...] (uninitialized)

//
// Enqueue 10:
//   ++rear → rear = 0
//   queue[0] = 10
//   queue = [10, ?, ?, ...]
//   front = -1, rear = 0

//
// Set front = 0:
//   front = 0, rear = 0
//
// Enqueue 20:
//   ++rear → rear = 1
//   queue[1] = 20
//   queue = [10, 20, ?, ...]
//   front = 0, rear = 1

//
// Enqueue 30:
//   ++rear → rear = 2
//   queue[2] = 30
//   queue = [10, 20, 30, ...]
//   front = 0, rear = 2

//
// Check underflow:
//   front == -1? → 0 == -1? → false
//   front > rear? → 0 > 2? → false
//   Condition is false, so queue is NOT empty (no underflow)

//
// Delete element:
//   delEle = queue[front] → queue[0] → 10
//   front++ → front = 1

//
// Check if empty after deletion:
//   front > rear? → 1 > 2? → false (queue still has elements)
//   So front and rear remain unchanged (front=1, rear=2)

//
// Display elements (for i = front to rear):
//   i = 1: print queue[1] → 20
//   i = 2: print queue[2] → 30
//
// Output:
//   20 30
//
// Final state:

//   front = 1, rear = 2
//   queue = [10, 20, 30, ...] (10 is logically deleted, but still in array)
//   Remaining elements: 20, 30

// Time Complexity = O(N)
// Reason: Display loop iterates from front to rear (N elements).

// Space Complexity = O(MAX)
// Reason: Array of size MAX is allocated for the queue.