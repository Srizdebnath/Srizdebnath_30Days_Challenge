#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int *c = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &c[i]);
    }

    qsort(c, m, sizeof(int), compare);

   
    int max_dist = c[0]; 
    int last_dist = (n - 1) - c[m - 1];
    
    if (last_dist > max_dist) {
        max_dist = last_dist;
    }

    // Check gaps between stations
    for (int i = 0; i < m - 1; i++) {
        int gap = (c[i + 1] - c[i]) / 2;
        if (gap > max_dist) {
            max_dist = gap;
        }
    }

    printf("%d\n", max_dist);

    free(c);
    return 0;
}
