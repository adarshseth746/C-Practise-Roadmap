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

    printf("Top Element of queue: %d ", queue[front]);

}
