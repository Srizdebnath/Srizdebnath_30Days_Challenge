#include <stdio.h>
#include <stdlib.h>

int solve() {
    int n, m;
    long long maxSum;
    if (scanf("%d %d %lld", &n, &m, &maxSum) != 3) return 0;

    long long *a = (long long *)malloc(n * sizeof(long long));
    long long *b = (long long *)malloc(m * sizeof(long long));

    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < m; i++) scanf("%lld", &b[i]);

    int i = 0, j = 0;
    long long currentSum = 0;
    int maxCount = 0;
    while (i < n && currentSum + a[i] <= maxSum) {
        currentSum += a[i];
        i++;
    }
    maxCount = i;
    while (j < m) {
        currentSum += b[j];
        j++;
        
        while (currentSum > maxSum && i > 0) {
            i--;
            currentSum -= a[i];
        }

        if (currentSum <= maxSum) {
            if (i + j > maxCount) {
                maxCount = i + j;
            }
        } else {
            break;
        }
    }

    free(a);
    free(b);
    return maxCount;
}

int main() {
    int g;
    if (scanf("%d", &g) != 1) return 0;
    while (g--) {
        printf("%d\n", solve());
    }
    return 0;
}
