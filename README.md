📚 Data Structures in C --- Practice Roadmap

A beginner-friendly, exam-oriented repository for learning and
implementing Data Structures and Algorithms in C step by step.

This repository is designed for students who do not want to only read
Data Structures theory, but want to understand the logic, write the C
code themselves, dry-run it, analyze complexity, and practice until they
can implement each structure independently.

The repository follows a structured progression from basic array
operations to stacks, queues, priority queues, linked lists, and their
practical applications.

🎯 What This Repository Is About

The main goal is to build a strong foundation in Data Structures using
C programming.

For every topic, the learning process follows:

Understand the concept
        ↓
See the data structure
        ↓
Understand the operation
        ↓
Write the algorithm
        ↓
Implement it in C
        ↓
Dry-run with an example
        ↓
Analyze time & space complexity
        ↓
Practice without looking at the solution

This repository is especially useful for:

🎓 Mid-semester and university exam preparation

💻 C programming practice

🧠 DSA fundamentals

🔍 Understanding how common data structures actually work

🧪 Hands-on implementation practice

🚀 Building a foundation for advanced DSA

🗺️ Complete Learning Roadmap

The repository is organized into progressive levels.

Level 1  → Arrays
Level 2  → Stack
Level 3  → Queue
Level 4  → Circular Queue
Level 5  → Priority Queue
Level 6  → Singly Linked List
Level 7  → Doubly Linked List
Level 8  → Circular Linked List
Level 9  → Stack & Queue using Linked List
Level 10 → Expression Applications

The order is intentional.

Each level introduces concepts that are reused in the next level.

🟢 Level 1 --- Arrays

Arrays are the starting point because they introduce the basic idea of
storing and manipulating collections of data.

Topics Covered

1.1 Array Traversal

Learn how to visit every element of an array.

Example:

10 20 30 40 50

Traversal:

10 → 20 → 30 → 40 → 50

1.2 Array Insertion

Learn how to insert an element at a particular position.

Example:

Before:
10 20 30 40

Insert 25

After:
10 20 25 30 40

The elements after the insertion position must be shifted to the right.

1.3 Array Deletion

Learn how to remove an element from a particular position.

Example:

Before:
10 20 30 40

Delete 20

After:
10 30 40

The remaining elements are shifted to the left.

1.4 Linear Search

Check elements one by one until the required element is found.

10 → 20 → 30 → 40
             ↑
           Found

Time complexity:

Best Case  : O(1)
Average    : O(n)
Worst Case : O(n)

1.5 Binary Search

Binary Search repeatedly divides a sorted array into two halves.

Time complexity:

Best Case  : O(1)
Average    : O(log n)
Worst Case : O(log n)

⚠️ Binary Search requires the data to be sorted.

🟡 Level 2 --- Stack

A Stack follows:

LIFO --- Last In, First Out

Think about a stack of plates.

The last plate placed on top is the first plate removed.

Basic Representation

       TOP
        ↓
      [30]
      [20]
      [10]

Operations

2.1 PUSH

Adds an element to the top.

PUSH(40)

      [40] ← TOP
      [30]
      [20]
      [10]

Time complexity:

O(1)

2.2 POP

Removes the top element.

POP()

      [30] ← TOP
      [20]
      [10]

Time complexity:

O(1)

2.3 PEEK / TOP

Returns the top element without removing it.

Time complexity:

O(1)

2.4 DISPLAY

Displays the elements of the stack.

Time complexity:

O(n)

Important Conditions

Overflow

Occurs when an element is inserted into a full stack.

top == MAX - 1

Underflow

Occurs when an element is removed from an empty stack.

top == -1

Stack Complexity

Operation     Time

PUSH          O(1)
POP           O(1)
PEEK          O(1)
DISPLAY       O(n)

🔵 Level 3 --- Queue

A Queue follows:

FIFO --- First In, First Out

Think about people standing in a line.

The person who enters first leaves first.

Representation

FRONT                    REAR
  ↓                        ↓
[10] [20] [30] [40]

Operations

3.1 ENQUEUE

Adds an element at the rear.

ENQUEUE(50)

FRONT                         REAR
  ↓                             ↓
[10] [20] [30] [40] [50]

Time complexity:

O(1)

3.2 DEQUEUE

Removes an element from the front.

DEQUEUE()

FRONT                    REAR
  ↓                        ↓
[20] [30] [40] [50]

Time complexity:

O(1)

3.3 DISPLAY

Displays all queue elements.

Time complexity:

O(n)

Important Conditions

Overflow

Queue is full.

Underflow

Queue is empty.

🟣 Level 4 --- Circular Queue

A simple linear queue can waste array space.

Example:

[ ] [ ] [30] [40] [50]
          ↑          ↑
        FRONT       REAR

The first positions are empty, but a simple linear queue may not reuse
them.

A Circular Queue solves this problem by connecting the last position
back to the first.

Circular Representation

        [0]
     ↙       ↘
   [4]       [1]
     ↖       ↙
       [3] → [2]

The modulo operator is important:

(rear + 1) % MAX

and:

(front + 1) % MAX

Operations

4.1 ENQUEUE

Insert at the rear.

4.2 DEQUEUE

Delete from the front.

4.3 DISPLAY

Visit elements from front to rear while respecting the circular
structure.

Complexity

Operation     Time

ENQUEUE       O(1)
DEQUEUE       O(1)
DISPLAY       O(n)

🟠 Level 5 --- Priority Queue

A Priority Queue does not simply follow normal FIFO ordering.

Each element has a priority.

Example:

Value   Priority
10         2
20         1
30         3

If a smaller number means higher priority:

20 → Priority 1
10 → Priority 2
30 → Priority 3

So 20 is processed first.

Operations

5.1 INSERT

Add an element with its priority.

5.2 DELETE

Remove the element with the highest priority according to the chosen
priority rule.

5.3 PEEK

View the highest-priority element without deleting it.

5.4 DISPLAY

Display the elements and their priorities.

Common Implementations

A Priority Queue can be implemented using:

Array

Linked List

Heap

This repository focuses first on the simpler implementations so that the
underlying logic is easy to understand.

Complexity

Complexity depends on the implementation.

For a simple unsorted array implementation:

Operation                   Typical Time

Insert                              O(1)
Delete highest priority             O(n)
Peek highest priority               O(n)
Display                             O(n)

🔴 Level 6 --- Singly Linked List

A Linked List stores data in dynamically allocated nodes.

A singly linked-list node contains:

+--------+--------+
|  DATA  |  NEXT  |
+--------+--------+

Example:

HEAD
 ↓
[10|•] → [20|•] → [30|NULL]

Unlike arrays, linked-list nodes do not need to occupy consecutive
memory locations.

C Node Structure

struct Node {
    int data;
    struct Node *next;
};

Operations

6.1 Create a Node

Allocate memory dynamically using malloc().

6.2 Traversal

Visit each node from HEAD until NULL.

10 → 20 → 30 → NULL

Time:

O(n)

6.3 Searching

Check each node until the required value is found.

Time:

O(n)

6.4 Insertion at Beginning

Before:

HEAD → 20 → 30 → NULL

After inserting 10:

HEAD → 10 → 20 → 30 → NULL

Time:

O(1)

6.5 Insertion at End

Traverse to the last node and attach the new node.

Time:

O(n)

If a tail pointer is maintained, insertion can be O(1).

6.6 Insertion After a Specified Node

Example:

10 → 20 → 30

Insert 25 after 20:

10 → 20 → 25 → 30

The pointer changes are:

newNode->next = temp->next;
temp->next = newNode;

6.7 Deletion at Beginning

Remove the first node.

Time:

O(1)

6.8 Deletion at End

Find the last node and remove it.

Time:

O(n)

6.9 Deletion of a Specified Node

Find the required node and reconnect the previous node to the next node.

Time:

O(n)

Singly Linked List Complexity

Operation                   Time

Traversal                   O(n)
Search                      O(n)
Insert Beginning            O(1)
Insert End                O(n)*
Delete Beginning            O(1)
Delete End                  O(n)
Delete Specified Node       O(n)

* O(1) when a suitable tail pointer is maintained.

🟤 Level 7 --- Doubly Linked List

A Doubly Linked List stores three pieces of information:

+------+-------+------+
| PREV | DATA  | NEXT |
+------+-------+------+

Example:

NULL ← 10 ⇄ 20 ⇄ 30 → NULL

C Node Structure

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

Main Operations

Insert at beginning

Insert at end

Delete from beginning

Delete from end

Forward traversal

Backward traversal

Main Advantage

Traversal is possible in both directions.

Forward:
10 → 20 → 30

Backward:
30 → 20 → 10

Main Limitation

Each node needs an additional prev pointer, so it requires more memory
than a singly linked list.

🟢 Level 8 --- Circular Linked List

In a Circular Linked List, the last node points back to the first node.

       ┌─────────────────┐
       ↓                 │
10 → 20 → 30 → 40 ──────┘

There is no NULL at the end.

Traversal

Instead of:

while(temp != NULL)

we normally stop when we reach HEAD again:

do {
    printf("%d ", temp->data);
    temp = temp->next;
} while(temp != head);

Applications

Circular linked lists are useful in situations such as:

Round-robin scheduling

Repeated/cyclic processing

Circular buffers

Multiplayer turn systems

🔷 Level 9 --- Stack and Queue Using Linked Lists

The same Stack and Queue concepts can be implemented using linked lists.

9.1 Stack Using Linked List

Use the head as TOP.

TOP
 ↓
30
 ↓
20
 ↓
10
 ↓
NULL

PUSH

Insert at the beginning.

O(1)

POP

Delete from the beginning.

O(1)

Advantage

The stack can grow dynamically until available memory is exhausted,
instead of being restricted to a fixed array size.

9.2 Queue Using Linked List

Maintain:

FRONT
  ↓
10 → 20 → 30 → NULL
              ↑
             REAR

ENQUEUE

Insert at the rear.

O(1)

DEQUEUE

Delete from the front.

O(1)

Maintaining both front and rear pointers is important for efficient
operations.

🧩 Level 10 --- Expression Applications

Stacks become particularly useful when solving arithmetic expressions.

10.1 Infix Expression

Operator appears between operands.

A + B

10.2 Postfix Expression

Operator appears after operands.

A B +

10.3 Infix → Postfix

Example:

A + B * (C - D) / E

Postfix:

A B C D - * E / +

Basic Idea

Scan the expression from left to right.

Add operands directly to output.

Push operators into the stack.

Use operator precedence to decide when to pop.

Handle parentheses.

Pop remaining operators at the end.

Time complexity:

O(n)

Space complexity:

O(n)

🧮 Postfix Evaluation

Example:

5 6 2 + * 12 4 / -

Stack Process

5       → [5]
6       → [5, 6]
2       → [5, 6, 2]
+       → [5, 8]
*       → [40]
12      → [40, 12]
4       → [40, 12, 4]
/       → [40, 3]
-       → [37]

Final result:

37

Algorithm

If operand:
    PUSH it

If operator:
    POP b
    POP a
    result = a operator b
    PUSH result

Final POP = answer

Time:

O(n)

Space:

O(n)

📊 Master Complexity Table

Data Structure / Operation     Time Complexity

Array Traversal                           O(n)
Array Insertion                           O(n)
Array Deletion                            O(n)
Linear Search                             O(n)
Binary Search                         O(log n)
Stack PUSH                                O(1)
Stack POP                                 O(1)
Stack PEEK                                O(1)
Stack DISPLAY                             O(n)
Queue ENQUEUE                             O(1)
Queue DEQUEUE                             O(1)
Queue DISPLAY                             O(n)
Circular Queue ENQUEUE                    O(1)
Circular Queue DEQUEUE                    O(1)
Circular Queue DISPLAY                    O(n)
Priority Queue Insert*                   O(1)
Priority Queue Delete*                   O(n)
Linked List Traversal                     O(n)
Linked List Search                        O(n)
LL Insert Beginning                       O(1)
LL Insert End                             O(n)
LL Delete Beginning                       O(1)
LL Delete End                             O(n)
LL Delete Specified                       O(n)
Infix → Postfix                           O(n)
Postfix Evaluation                        O(n)

* Based on the simple unsorted-array priority queue implementation
used for practice.

🧠 Complexity Notations

Big-O --- O()

Describes an upper-bound growth rate and is commonly used when
discussing worst-case performance.

Examples:

O(1)      Constant
O(log n)  Logarithmic
O(n)      Linear
O(n log n)
O(n²)     Quadratic

A useful order to remember:

O(1)
  ↓
O(log n)
  ↓
O(n)
  ↓
O(n log n)
  ↓
O(n²)

Big-Ω --- Ω()

Represents a lower-bound growth rate.

Example:

Linear Search has a best case of:

Ω(1)

when the first element is the target.

Big-Θ --- Θ()

Represents a tight asymptotic bound when the upper and lower bounds grow
at the same rate.

🧪 How to Practice This Repository

Do not simply copy the programs.

For every operation, use this process:

Step 1 --- Understand

Ask:

What problem does this operation solve?

Step 2 --- Draw

Draw the structure before writing code.

Example:

TOP
 ↓
30
20
10

Step 3 --- Write the Logic

Write the operation in plain English.

Example:

1. Check whether stack is full.
2. Increase TOP.
3. Store the new element.

Step 4 --- Write the C Code

Only after understanding the pointer/index changes.

Step 5 --- Dry Run

Use a small example:

10
20
30

Track every change in:

top

front

rear

head

temp

prev

next

Step 6 --- Analyze Complexity

Always ask:

How many times can the loop run?
Does the operation require traversal?
How much additional memory is used?

Step 7 --- Rebuild Without Looking

Close the solution and write the program again from memory.

This is the most important step.

📝 Exam Preparation Strategy

For a theory question, use:

Definition
    ↓
Diagram
    ↓
Operations
    ↓
Algorithm
    ↓
Example
    ↓
Complexity
    ↓
Advantages / Limitations
    ↓
Applications

For a programming question:

Problem
    ↓
Logic
    ↓
Algorithm
    ↓
C Program
    ↓
Sample Output
    ↓
Complexity

🎯 Important Things to Memorize

You do not need to memorize every line of code.

Understand these core patterns.

Stack

INSERT → TOP
DELETE → TOP

LIFO

Queue

INSERT → REAR
DELETE → FRONT

FIFO

Singly Linked List

DATA → NEXT

Doubly Linked List

PREV ← DATA → NEXT

Circular Linked List

LAST → FIRST

Binary Search

Sorted Array
+
Divide by 2
=
O(log n)

🚀 Recommended Practice Challenges

After learning each structure, try implementing it without looking at
the solution.

Array Challenges

Insert at beginning

Insert at end

Insert at any position

Delete from beginning

Delete from end

Delete from any position

Linear search

Binary search

Stack Challenges

Implement PUSH

Implement POP

Implement PEEK

Detect overflow

Detect underflow

Reverse a string using a stack

Check balanced parentheses

Queue Challenges

Implement ENQUEUE

Implement DEQUEUE

Implement circular queue

Detect overflow/underflow

Implement queue using linked list

Priority Queue Challenges

Insert with priority

Delete highest-priority element

Display in priority order

Handle equal priorities

Linked List Challenges

Insert at beginning

Insert at end

Insert after a node

Delete beginning

Delete end

Delete a specific value

Search

Count nodes

Reverse a linked list

Implement stack using linked list

Implement queue using linked list

📂 Suggested Repository Structure

A clean repository can follow this structure:

Data-Structures-in-C/
│
├── README.md
│
├── Level-1-Arrays/
│   ├── Traversal.c
│   ├── Insertion.c
│   ├── Deletion.c
│   ├── LinearSearch.c
│   └── BinarySearch.c
│
├── Level-2-Stack/
│   ├── Push.c
│   ├── Pop.c
│   ├── Peek.c
│   ├── Display.c
│   └── Stack.c
│
├── Level-3-Queue/
│   ├── Enqueue.c
│   ├── Dequeue.c
│   ├── Display.c
│   └── Queue.c
│
├── Level-4-Circular-Queue/
│   ├── Enqueue.c
│   ├── Dequeue.c
│   └── Display.c
│
├── Level-5-Priority-Queue/
│   ├── Insert.c
│   ├── Delete.c
│   └── Display.c
│
├── Level-6-Singly-Linked-List/
│   ├── Create.c
│   ├── Traversal.c
│   ├── Search.c
│   ├── InsertBeginning.c
│   ├── InsertEnd.c
│   ├── InsertAfter.c
│   ├── DeleteBeginning.c
│   ├── DeleteEnd.c
│   └── DeleteSpecific.c
│
├── Level-7-Doubly-Linked-List/
│   ├── InsertBeginning.c
│   ├── InsertEnd.c
│   ├── DeleteBeginning.c
│   ├── DeleteEnd.c
│   ├── ForwardTraversal.c
│   └── BackwardTraversal.c
│
├── Level-8-Circular-Linked-List/
│   ├── Insert.c
│   ├── Delete.c
│   └── Traversal.c
│
├── Level-9-Linked-List-Applications/
│   ├── StackUsingLinkedList.c
│   └── QueueUsingLinkedList.c
│
└── Level-10-Expression-Applications/
    ├── InfixToPostfix.c
    └── PostfixEvaluation.c

You can modify the folder names according to the actual files in the
repository.

🛠️ How to Compile and Run

If GCC is installed:

gcc filename.c -o program

Run on Windows:

program.exe

Run on Linux/macOS:

./program

For example:

gcc Stack.c -o Stack

Then:

Stack.exe

💻 Requirements

You only need basic tools:

C compiler such as GCC/MinGW

VS Code or another code editor

Terminal / Command Prompt

Basic knowledge of C programming

Recommended C topics before starting:

Variables

Data types

Operators

Conditions

Loops

Functions

Arrays

Pointers

Structures

Dynamic memory allocation

For linked lists, you should especially understand:

struct
pointer
malloc()
free()

📚 What You Will Learn

After completing this repository, you should be comfortable with:

Arrays and their basic operations

Searching

Stack implementation

Queue implementation

Circular queues

Priority queues

Pointers

Structures

Dynamic memory allocation

Singly linked lists

Doubly linked lists

Circular linked lists

Stack using linked lists

Queue using linked lists

Expression conversion

Postfix evaluation

Algorithm analysis

Time complexity

Space complexity

Basic problem-solving patterns

🏁 Final Goal

The goal is not:

"I memorized the code."

The goal is:

"I understand why every line of the code exists, and I can implement
the structure myself."

By the end, you should be able to look at a problem and identify:

What data structure is required?
          ↓
What operation is required?
          ↓
What data should move?
          ↓
Which pointer/index changes?
          ↓
What is the time complexity?
          ↓
Can I implement it in C?

🤝 For Students

This repository is built as a learning resource.

If you are a beginner, don't rush through all levels.

A better approach is:

Learn → Code → Break → Debug → Understand → Recode

Getting errors is part of the process.

Especially with pointers and linked lists, your first implementation may
not work perfectly. Debugging those mistakes is part of learning how the
data structure actually works.

⭐ Quick Revision

Before an exam, remember:

ARRAY
↓
Index-based storage

STACK
↓
LIFO
↓
PUSH / POP / PEEK

QUEUE
↓
FIFO
↓
ENQUEUE / DEQUEUE

CIRCULAR QUEUE
↓
Reuse empty positions
↓
Modulo %

PRIORITY QUEUE
↓
Priority-based processing

SINGLY LL
↓
DATA + NEXT

DOUBLY LL
↓
PREV + DATA + NEXT

CIRCULAR LL
↓
LAST → FIRST

STACK USING LL
↓
TOP = HEAD

QUEUE USING LL
↓
FRONT + REAR

INFIX → POSTFIX
↓
STACK

POSTFIX EVALUATION
↓
STACK

🌟 Keep Building

Data Structures become much easier when you stop treating them as a
collection of definitions and start seeing them as tools for
organizing and manipulating information.

Build one structure at a time.

Understand the pointers.

Dry-run the operations.

Write the code yourself.

Then move to the next level.

Strong fundamentals → Better problem solving → Stronger DSA. 🚀

📌 Repository Status

This repository is structured as a progressive practice roadmap and can
be expanded with:

More practice problems

Menu-driven implementations

Better input handling

Complexity notes

Dry-run examples

Interview-style questions

LeetCode/GFG-style problems

Mini projects using data structures

Keep practicing. Keep debugging. Keep building. 💻
