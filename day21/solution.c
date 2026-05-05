#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int left;
    int right;
} Node;

Node tree[1025];

void swapNodesAtDepth(int root, int currentDepth, int k) {
    if (root == -1) return;

    if (currentDepth % k == 0) {
        int temp = tree[root].left;
        tree[root].left = tree[root].right;
        tree[root].right = temp;
    }

    swapNodesAtDepth(tree[root].left, currentDepth + 1, k);
    swapNodesAtDepth(tree[root].right, currentDepth + 1, k);
}

void inorder(int root) {
    if (root == -1) return;
    inorder(tree[root].left);
    printf("%d ", root);
    inorder(tree[root].right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &tree[i].left, &tree[i].right);
    }

    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int k;
        scanf("%d", &k);
        swapNodesAtDepth(1, 1, k);
        inorder(1);
        printf("\n");
    }

    return 0;
}
