#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2, n3;
    if (scanf("%d %d %d", &n1, &n2, &n3) != 3) return 0;

    int *h1 = (int *)malloc(n1 * sizeof(int));
    int *h2 = (int *)malloc(n2 * sizeof(int));
    int *h3 = (int *)malloc(n3 * sizeof(int));

    long long sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0; i < n1; i++) {
        scanf("%d", &h1[i]);
        sum1 += h1[i];
    }
    for (int i = 0; i < n2; i++) {
        scanf("%d", &h2[i]);
        sum2 += h2[i];
    }
    for (int i = 0; i < n3; i++) {
        scanf("%d", &h3[i]);
        sum3 += h3[i];
    }

    int i1 = 0, i2 = 0, i3 = 0;

    while (1) {
        if (i1 == n1 || i2 == n2 || i3 == n3) {
            if (sum1 == sum2 && sum2 == sum3) break;
            if (i1 == n1) sum1 = 0;
            if (i2 == n2) sum2 = 0;
            if (i3 == n3) sum3 = 0;
        }

        if (sum1 == sum2 && sum2 == sum3) {
            break;
        }

        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i1++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[i2++];
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= h3[i3++];
        }
    }

    printf("%lld\n", sum1);

    free(h1);
    free(h2);
    free(h3);

    return 0;
}
