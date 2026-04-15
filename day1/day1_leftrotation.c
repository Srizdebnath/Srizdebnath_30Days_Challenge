#include <stdio.h>
#include <stdlib.h>

/**
 * Problem: Left Rotation
 * Day 1 of 30 Days DSA Challenge
 * 
 * Description:
 * A left rotation operation on an array of size n shifts each element 1 unit to the left.
 * Elements that fall off the left end reappear at the right end.
 * Given an integer d, rotate the array d steps to the left.
 * 
 * Approach:
 * To perform d left rotations on an array of size n, the element at index 'i' 
 * moves to index '(i + n - d) % n'. 
 * Conversely, the element that will be at index '0' after rotation is the one 
 * originally at index 'd % n'.
 */

void rotateLeft(int n, int d, int *arr) {
    // If d > n, rotating n times brings it back to original state
    d = d % n;
    
    // Print starting from index d to n-1
    for (int i = d; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Then print from index 0 to d-1
    for (int i = 0; i < d; i++) {
        printf("%d%s", arr[i], (i == d - 1) ? "" : " ");
    }
    printf("\n");
}

int main() {
    int n, d;
    
    // Read n and d
    if (scanf("%d %d", &n, &d) != 2) {
        return 0;
    }
    
    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }
    
    // Read the array elements
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            break;
        }
    }
    
    // Perform rotation and print result
    rotateLeft(n, d, arr);
    
    // Free allocated memory
    free(arr);
    
    return 0;
}
