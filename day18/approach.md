# Day 18: Number Line Jumps - Approach

## Problem Overview
Two kangaroos are jumping on a number line in the positive direction. We need to determine if they will ever land on the same spot at the same time.

### Given:
- Kangaroo 1: Starting position $x_1$, jump distance $v_1$.
- Kangaroo 2: Starting position $x_2$, jump distance $v_2$.
- Constraints: $0 \le x_1 < x_2 \le 10,000$.

---

## Mathematical Derivation
Let $n$ be the number of jumps. The positions of the kangaroos after $n$ jumps can be represented as:
- Position of Kangaroo 1: $P_1 = x_1 + n \cdot v_1$
- Position of Kangaroo 2: $P_2 = x_2 + n \cdot v_2$

For them to meet, their positions must be equal at the same jump $n$:
$$x_1 + n \cdot v_1 = x_2 + n \cdot v_2$$

Rearranging the equation to solve for $n$:
$$n \cdot v_1 - n \cdot v_2 = x_2 - x_1$$
$$n \cdot (v_1 - v_2) = x_2 - x_1$$
$$n = \frac{x_2 - x_1}{v_1 - v_2}$$

---

## Implementation Logic
To return **"YES"**, the following conditions must be met:

### 1. Relative Speed Check ($v_1 > v_2$)
Since we are given $x_1 < x_2$, Kangaroo 1 starts behind Kangaroo 2. For Kangaroo 1 to catch up, it **must** be moving faster than Kangaroo 2. 
- If $v_1 \le v_2$, the distance between them will either stay the same or increase. In this case, we return **"NO"**.

### 2. Perfect Division Check ($(x_2 - x_1) \pmod{v_1 - v_2} = 0$)
Since $n$ represents the number of jumps, it must be a **whole number** (non-negative integer). 
- If $(x_2 - x_1)$ is not perfectly divisible by $(v_1 - v_2)$, it means they will cross each other's paths between jumps but never land on the same spot simultaneously.
- If the remainder is $0$, they meet exactly at jump $n$.

---

## Complexity Analysis
- **Time Complexity**: $O(1)$ - The solution uses a simple conditional check and arithmetic operations.
- **Space Complexity**: $O(1)$ - No additional data structures are used.
