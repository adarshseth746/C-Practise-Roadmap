// This is the simple program to demonstrate array searching in C programming language.

#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 4, 5, 6};
    int target = 3;

    int n = sizeof(arr) / sizeof(arr[0]);
   
    int eleFnd = 0;

    int posIdx = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            eleFnd = 1;
            posIdx = i;
            break;
        }
    }

    if(eleFnd) printf("Element %d found at index %d\n", target, posIdx);
    else printf("Element %d not found in the array\n", target);

    return 0;
}


//                         =======================    Explanation    =======================

// The program initializes an array with 5 elements and then searches for a target value (3) in the array.

// It uses a for loop to iterate through the array and checks if the current element is equal to the target value. 

// If it finds the target value, it sets a flag (eleFnd) to 1 and stores the index (posIdx) of the found element. If the target value is not found, it prints a message indicating that the element is not present in the array.

//                        ======================       DRY RUN            ======================
// Initial array: [1, 2, 4, 5, 6]
// Target value: 3

// i = 0: arr[0] (1) != target (3) => continue
// i = 1: arr[1] (2) != target (3) => continue
// i = 2: arr[2] (4) != target (3) => continue
// i = 3: arr[3] (5) != target (3) => continue
// i = 4: arr[4] (6) != target (3) => continue

// Final output: Element 3 not found in the array

// Initial array: [1, 2, 3, 5, 6]
// Target value: 3

// i = 0: arr[0] (1) != target (3) => continue
// i = 1: arr[1] (2) != target (3) => continue
// i = 2: arr[2] (3) == target (3) => eleFnd = 1, posIdx = 2, break
// Final output: Element 3 found at index 2


// Note: The program uses a 'Linear Search' algorithm to find the target value in the array. This algorithm has a time complexity of O(n), where n is the number of elements in the array.