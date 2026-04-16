# Day 2: Print in Reverse

## Problem Statement
Given a pointer to the head of a singly-linked list, print each `data` value from the reversed list. If the given list is empty, do not print anything.

## Approach
To print a linked list in reverse without actually reversing the list in memory, we can use a **recursive approach**:

1. **Base Case**: If the current node (`llist`) is `NULL`, return (reaching the end of the list).
2. **Recursive Step**: Call the function recursively for the next node (`llist->next`).
3. **Print Step**: After the recursive call returns (which means all subsequent nodes have already been printed), print the `data` of the current node.


This ensures that the last node is printed first, then the second-to-last, and so on, back to the head.

## Complexity
- **Time Complexity**: $O(n)$ where $n$ is the number of nodes in the linked list, as we visit each node exactly once.
- **Space Complexity**: $O(n)$ due to the recursion stack. Given the constraint $n \le 1000$, this is well within safe limits.

## Sample Execution
- **Input**: `1 -> 2 -> 3 -> NULL`
- **Output**:
  ```
  3
  2
  1
  ```
