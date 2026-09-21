// This is the simple program to demonstrate array deletion in C programming language.

#include <stdio.h>
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int n = 5;

    int pos = 2;

    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

//           =======================    Explanation    =======================

// The program initializes an array with 5 elements and then deletes the value at position 2.

// It shifts the elements to the left to fill the gap from the line 'arr[i] = arr[i + 1];' and then prints the updated array.


//                         ======================       DRY RUN            ======================

// Initial array: [1, 2, 3, 4, 5]

// i = 2: arr[2] = arr[3] => [1, 2, 4, 4, 5]

// i = 3: arr[3] = arr[4] => [1, 2, 4, 5, 5]

// Now, n = 4 => [1, 2, 4, 5]

// Final output: 1 2 4 5