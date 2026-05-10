#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* create_heap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (long long*)malloc(sizeof(long long) * (capacity + 1));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, long long val) {
    heap->size++;
    int i = heap->size;
    heap->data[i] = val;
    while (i > 1 && heap->data[i] < heap->data[i / 2]) {
        swap(&heap->data[i], &heap->data[i / 2]);
        i /= 2;
    }
}

long long pop(MinHeap* heap) {
    if (heap->size == 0) return -1;
    long long min_val = heap->data[1];
    heap->data[1] = heap->data[heap->size];
    heap->size--;
    
    int i = 1;
    while (2 * i <= heap->size) {
        int smallest = 2 * i;
        if (smallest + 1 <= heap->size && heap->data[smallest + 1] < heap->data[smallest]) {
            smallest++;
        }
        if (heap->data[i] <= heap->data[smallest]) break;
        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }
    return min_val;
}

int main() {
    int n;
    long long k;
    if (scanf("%d %lld", &n, &k) != 2) return 0;
    
    MinHeap* heap = create_heap(n);
    for (int i = 0; i < n; i++) {
        long long val;
        if (scanf("%lld", &val) == 1) {
            push(heap, val);
        }
    }
    
    int operations = 0;
    int possible = 1;
    while (heap->size > 0 && heap->data[1] < k) {
        if (heap->size < 2) {
            possible = 0;
            break;
        }
        long long first = pop(heap);
        long long second = pop(heap);
        long long new_sweetness = first + 2 * second;
        push(heap, new_sweetness);
        operations++;
    }
    
    if (!possible) {
        printf("-1\n");
    } else {
        printf("%d\n", operations);
    }
    
    free(heap->data);
    free(heap);
    return 0;
}
