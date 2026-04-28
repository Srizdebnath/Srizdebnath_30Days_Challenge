/*
 * Day 14: Implement a Queue using two Stacks
 * 
 * Approach:
 * 1. We use two stacks: 'in' (for input/enqueue) and 'out' (for output/dequeue/peek).
 * 2. Enqueue (Type 1): Always push the new element onto the 'in' stack. 
 *    - Time Complexity: O(1)
 * 3. Dequeue (Type 2) & Peek (Type 3):
 *    - If the 'out' stack is empty, move all elements from the 'in' stack to the 'out' stack.
 *    - This reversal ensures that the first element pushed into 'in' is now at the top of 'out'.
 *    - Pop or Peek from the 'out' stack.
 *    - Time Complexity: Amortized O(1), as each element is moved at most once between stacks.
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100005

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = val;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1;
}

typedef struct {
    Stack in;
    Stack out;
} Queue;

void initQueue(Queue *q) {
    initStack(&q->in);
    initStack(&q->out);
}

void enqueue(Queue *q, int x) {
    push(&q->in, x);
}

void moveElements(Queue *q) {
    if (isEmpty(&q->out)) {
        while (!isEmpty(&q->in)) {
            push(&q->out, pop(&q->in));
        }
    }
}

void dequeue(Queue *q) {
    moveElements(q);
    pop(&q->out);
}

int peekQueue(Queue *q) {
    moveElements(q);
    return peek(&q->out);
}

int main() {
    int q_count;
    if (scanf("%d", &q_count) != 1) return 0;

    Queue q;
    initQueue(&q);

    while (q_count--) {
        int type;
        if (scanf("%d", &type) != 1) break;

        if (type == 1) {
            int x;
            if (scanf("%d", &x) != 1) break;
            enqueue(&q, x);
        } else if (type == 2) {
            dequeue(&q);
        } else if (type == 3) {
            printf("%d\n", peekQueue(&q));
        }
    }

    return 0;
}
