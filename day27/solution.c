#include <stdio.h>
#include <stdlib.h>

long long arrayManipulation(int n, int m, int queries[][3]) {
    long long *diff = (long long *)calloc(n + 2, sizeof(long long));
    if (!diff) return 0;

    for (int i = 0; i < m; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        diff[a] += k;
        if (b + 1 <= n) {
            diff[b + 1] -= k;
        }
    }

    long long max_val = 0;
    long long current_val = 0;
    for (int i = 1; i <= n; i++) {
        current_val += diff[i];
        if (current_val > max_val) {
            max_val = current_val;
        }
    }

    free(diff);
    return max_val;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    long long *diff = (long long *)calloc(n + 2, sizeof(long long));
    if (!diff) return 1;

    for (int i = 0; i < m; i++) {
        int a, b, k;
        if (scanf("%d %d %d", &a, &b, &k) != 3) break;
        diff[a] += k;
        if (b + 1 <= n) {
            diff[b + 1] -= k;
        }
    }

    long long max_val = 0;
    long long current_val = 0;
    for (int i = 1; i <= n; i++) {
        current_val += diff[i];
        if (current_val > max_val) {
            max_val = current_val;
        }
    }

    printf("%lld\n", max_val);

    free(diff);
    return 0;
}
