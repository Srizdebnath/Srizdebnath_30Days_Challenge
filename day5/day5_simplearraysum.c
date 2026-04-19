#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    
    int sum = 0;
    int element;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &element) != 1) {
            break;
        }
        sum += element;
    }
    printf("%d\n", sum);
    
    return 0;
}
