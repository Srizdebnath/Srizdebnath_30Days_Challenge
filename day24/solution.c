#include <stdio.h>
#include <stdlib.h>

long long largestRectangle(int n, int *h) {
    int *stack = (int *)malloc((n + 1) * sizeof(int));
    int top = -1;
    long long max_area = 0;
    int i = 0;

    while (i < n) {
        if (top == -1 || h[i] >= h[stack[top]]) {
            stack[++top] = i++;
        } else {
            int tp = stack[top--];
            long long area = (long long)h[tp] * (top == -1 ? i : i - stack[top] - 1);
            if (area > max_area) {
                max_area = area;
            }
        }
    }
    while (top != -1) {
        int tp = stack[top--];
        long long area = (long long)h[tp] * (top == -1 ? i : i - stack[top] - 1);
        if (area > max_area) {
            max_area = area;
        }
    }

    free(stack);
    return max_area;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *h = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &h[i]) != 1) break;
    }

    printf("%lld\n", largestRectangle(n, h));

    free(h);
    return 0;
}
