// This is the simple program to demonstrate array sorting in C programming language.

#include <stdio.h>

int main() {
    int arr[5] = {3, 7, 1, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

//                              =======================    Explanation    =======================

// The program initializes an array with 5 elements and then sorts the array in ascending order using the bubble sort algorithm.

// Notice carefully that we use here the sorting algorithm called 'Bubble Sort'.

// How it works: This algorithm repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. After each pass, the largest unsorted element "bubbles" up to its correct position in the array that's why we decrement the range of comparison in each iteration. The process is repeated until the array is sorted.

// How actually swapping works: We use a temporary variable to hold the value of one of the elements while we swap them. This prevents data loss during the swap operation since we have not any 'swap' function in C programming language.

// Example of swapping two numbers using a temporary variable:
// int a = 5, b = 10;
// int temp = a; // Store the value of 'a' in 'temp'
// a = b; // Assign the value of 'b' to 'a'
// b = temp; // Assign the value of 'temp' (original 'a') to 'b'


//                         ======================       DRY RUN            ======================

// Initial array: [3, 7, 1, 4, 8]

// i = 0, j = 0: Compare arr[0] (3) and arr[1] (7) since 3 < 7 => No swap arr: [3, 7, 1, 4, 8]
// i = 0, j = 1: Compare arr[1] (7) and arr[2] (1) since 7 > 1 => Swap => [3, 1, 7, 4, 8]

// i = 0, j = 2: Compare arr[2] (7) and arr[3] (4) since 7 > 4 => Swap => [3, 1, 4, 7, 8]
// i = 0, j = 3: Compare arr[3] (7) and arr[4] (8) since 7 < 8 => No swap arr: [3, 1, 4, 7, 8]

// i = 1, j = 0: Compare arr[0] (3) and arr[1] (1) since 3 > 1 => Swap => [1, 3, 4, 7, 8]
// i = 1, j = 1: Compare arr[1] (3) and arr[2] (4) since 3 < 4 => No swap arr: [1, 3, 4, 7, 8]

// i = 1, j = 2: Compare arr[2] (4) and arr[3] (7) since 4 < 7 => No swap  arr: [1, 3, 4, 7, 8]
// i = 2, j = 0: Compare arr[0] (1) and arr[1] (3) since 1 < 3 => No swap  arr: [1, 3, 4, 7, 8]

// i = 2, j = 1: Compare arr[1] (3) and arr[2] (4) since 3 < 4 => No swap arr: [1, 3, 4, 7, 8]
// i = 3, j = 0: Compare arr[0] (1) and arr[1] (3) since 1 < 3 => No swap arr: [1, 3, 4, 7, 8]

// Final sorted array: [1, 3, 4, 7, 8]


// Time Complexity = O(N^2)
// Space Complexity = O(1)