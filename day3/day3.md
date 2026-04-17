# Day 3: Equal Stacks

## Problem Description
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they are all the same height, then return the height.

### Example
`h1 = [1, 2, 1, 1]`
`h2 = [1, 1, 2]`
`h3 = [1, 1]`

- Total heights: `h1 = 5`, `h2 = 4`, `h3 = 2`.
- Remove from `h1`: `1, 2` -> height becomes `2`.
- Remove from `h2`: `1, 1` -> height becomes `2`.
- All stacks are now height `2`. Return `2`.

### Constraints
- $0 < n1, n2, n3 \le 10^5$
- $0 < \text{height of any cylinder} \le 100$

### Input Format
- The first line contains three space-separated integers, $n1$, $n2$, and $n3$.
- The subsequent lines describe the respective heights of each cylinder in a stack from top to bottom.
