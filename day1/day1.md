# Day 1: Left Rotation

## Problem Statement
A left rotation operation on an array shifts each element to the left by one position. Elements that "fall off" the left end are added back to the right end. Given an array of $n$ integers and a number $d$, perform $d$ left rotations.

## Approach
1. **Effective Rotations**: Since rotating an array of size $n$ by $n$ positions results in the original array, we only need to perform $d \pmod n$ rotations.
2. **Printing Strategy**: Instead of actually shifting elements in memory (which would take $O(n \cdot d)$ time or $O(n)$ space for a copy), we can print the rotated result directly:
   - The element at original index $d$ becomes the new first element.
   - Iterate from index $d$ to $n-1$ and print each element.
   - Then, iterate from index $0$ to $d-1$ and print each element.
3. **Complexity**:
   - **Time**: $O(n)$ - one pass to read and one pass to print.
   - **Space**: $O(n)$ for storing the array.

## Sample Execution
- **Input**: `5 4`, `1 2 3 4 5`
- **Output**: `5 1 2 3 4`
