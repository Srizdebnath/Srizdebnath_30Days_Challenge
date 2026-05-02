#include <stdio.h>
#include <string.h>

/**
 * Number Line Jumps (Kangaroo)
 * 
 * Problem:
 * Two kangaroos start at positions x1 and x2 and move at rates v1 and v2.
 * Determine if they will ever meet at the same location at the same time.
 * 
 * Mathematical Logic:
 * x1 + n*v1 = x2 + n*v2
 * n*(v1 - v2) = x2 - x1
 * n = (x2 - x1) / (v1 - v2)
 * 
 * Condition for "YES":
 * 1. v1 > v2 (since x1 < x2, the first kangaroo must be faster)
 * 2. (x2 - x1) % (v1 - v2) == 0 (must meet at an integer jump count)
 */
char* kangaroo(int x1, int v1, int x2, int v2) {
    // According to constraints: x1 < x2
    // If v1 <= v2, the first kangaroo will never catch up.
    if (v1 <= v2) {
        return "NO";
    }
    
    // Check if the relative distance is divisible by relative speed
    if ((x2 - x1) % (v1 - v2) == 0) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int x1, v1, x2, v2;
    
    // Read input: x1 v1 x2 v2
    if (scanf("%d %d %d %d", &x1, &v1, &x2, &v2) == 4) {
        printf("%s\n", kangaroo(x1, v1, x2, v2));
    }
    
    return 0;
}
