// This is the simple program to demonstrate array traversal in C programming language.

#include <stdio.h>
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};  

    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {  
        printf("%d ", arr[i]);
    }
    return 0;
}

//           =======================    Explanation    =======================

// The sizeof(arr) gives the total size of the array in bytes.
// The sizeof(arr[0]) gives 4 bytes divide the size of all elements in the array which is 20 bytes.
// The loop will run 5 times and print the elements of the array one by one.

//                         ======================       DRY RUN            ======================

// Initial array: [1, 2, 3, 4, 5]
// i = 0: print 1
// i = 1: print 2
// i = 2: print 3
// i = 3: print 4
// i = 4: print 5
// Final output: 1 2 3 4 5