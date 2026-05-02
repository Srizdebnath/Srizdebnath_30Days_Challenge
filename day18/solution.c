#include <stdio.h>
#include <string.h>
char* kangaroo(int x1, int v1, int x2, int v2) {
    if (v1 <= v2) {
        return "NO";
    }

    if ((x2 - x1) % (v1 - v2) == 0) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int x1, v1, x2, v2;

    if (scanf("%d %d %d %d", &x1, &v1, &x2, &v2) == 4) {
        printf("%s\n", kangaroo(x1, v1, x2, v2));
    }
    
    return 0;
}
