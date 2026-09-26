// This is the simple program to implement a basic queue using an array in C programming language.


#include<stdio.h>
#define MAX 100



int main() {

    int queue[MAX];
    
    int front = -1; // Index of the front element (initially -1 for empty queue)

    int rear = -1; // Index of the rear element (initially -1 for empty queue)

    front = 0; // Set front to 0 (queue will start from index 0)


    // Enqueue elements (add to rear of queue)

    queue[++rear] = 10; // rear becomes 0, queue[0] = 10
    queue[++rear] = 20; // rear becomes 1, queue[0] = 20
    queue[++rear] = 30; // rear becomes 2, queue[0] = 30


    // Check if queue is empty
    // Queue is empty if front is -1 OR front has moved past rear


    if(front == -1 || front > rear) { 
        printf("Queue is empty.\n");
        return 0;
    }

    printf("Queue elements: ");

    //                                      ====================== DISPLAY ELEMENTS   ======================


    for(int i = front; i <= rear; i++) printf("%d ", queue[i]); 


    printf("\n");
    
}



//                                      =====================    Explanation    ======================

// This program demonstrates a basic queue implementation using an array.

// Step 1: Declare an array 'queue' of size MAX to store elements.

// Step 2: Initialize front and rear to -1 (indicating empty queue).

// Step 3: Set front to 0 (queue starts from index 0).

// Step 4: Enqueue three elements (10, 20, 30) by incrementing rear and storing values.

// Step 5: Check if queue is empty using condition (front == -1 || front > rear).

// Step 6: If not empty, display all elements from front index to rear index.




// Queue Properties:
// - FIFO (First In First Out): First element added is first to be removed.
// - front: Points to the first element in the queue.
// - rear: Points to the last element in the queue.
// - Elements are stored sequentially from front to rear.



// Note: This is a simplified version without explicit enqueue/dequeue functions.
//       In a complete implementation, you would have separate functions for:
//       - enqueue (add element at rear)
//       - dequeue (remove element from front)
//       - isEmpty (check if queue is empty)
//       - isFull (check if queue is full)



//                                      =====================    DRY RUN    ======================

// Initial state:
//   front = -1, rear = -1
//   queue = [?, ?, ?, ...] (uninitialized)


//
// After front = 0:
//   front = 0, rear = -1


//
// Enqueue 10:
//   ++rear → rear = 0
//   queue[0] = 10
//   queue = [10, ?, ?, ...]
//   front = 0, rear = 0




// Enqueue 20:
//   ++rear → rear = 1
//   queue[1] = 20
//   queue = [10, 20, ?, ...]
//   front = 0, rear = 1



// Enqueue 30:
//   ++rear → rear = 2
//   queue[2] = 30
//   queue = [10, 20, 30, ...]
//   front = 0, rear = 2



// Check if empty:
//   front == -1? → 0 == -1? → false
//   front > rear? → 0 > 2? → false
//   Condition is false, so queue is NOT empty


//
// Display elements (for i = front to rear):
//   i = 0: print queue[0] → 10
//   i = 1: print queue[1] → 20
//   i = 2: print queue[2] → 30


//
// Output: Queue elements: 10 20 30

// Time Complexity = O(N)
// Reason: Display loop iterates from front to rear (N elements).

// Space Complexity = O(MAX)
// Reason: Array of size MAX is allocated for the queue.