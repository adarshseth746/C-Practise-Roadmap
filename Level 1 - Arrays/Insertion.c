// This is the simple program to demonstrate array insertion in C programming language.
#include <stdio.h>

int main()
{

    int arr[100] = {10, 20, 30, 40};
    int n = 4;

    int pos = 2;
    int value = 25;

    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    n++;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

//                         =======================    Explanation    =======================

// The program initializes an array with 4 elements and then inserts a new value (25) at position 2.
// It shifts the elements to the right to make space for the new value from the line 'arr[i] = arr[i - 1];' and then prints the updated array.

//                         ======================       DRY RUN            ======================

// Initial array: [10, 20, 30, 40]
// i = 4: arr[4] = arr[3] => [10, 20, 30, 40, 40]
// i = 3: arr[3] = arr[2] => [10, 20, 30, 30, 40]
// i = 2: arr[2] = arr[1] => [10, 20, 20, 30, 40]
// Now, arr[2] = 25 => [10, 20, 25, 30, 40]
// Final output: 10 20 25 30 40