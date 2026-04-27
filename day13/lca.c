#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    } else {
        struct node* cur;
        if (data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
        return root;
    }
}

/* you only have to complete the function given below.
node is defined as 

struct node {
    int data;
    struct node *left;
    struct node *right;
};

*/
struct node *lca(struct node *root, int v1, int v2) {
    if (root == NULL) {
        return NULL;
    }

    // If both v1 and v2 are smaller than root, then LCA lies in left
    if (v1 < root->data && v2 < root->data) {
        return lca(root->left, v1, v2);
    }

    // If both v1 and v2 are greater than root, then LCA lies in right
    if (v1 > root->data && v2 > root->data) {
        return lca(root->right, v1, v2);
    }

    // If one is smaller and other is greater, or root matches one of them,
    // then root is the Lowest Common Ancestor.
    return root;
}

int main() {
    struct node* root = NULL;
    int t;
    int data;

    if (scanf("%d", &t) != 1) return 0;

    while (t-- > 0) {
        if (scanf("%d", &data) != 1) break;
        root = insert(root, data);
    }

    int v1;
    int v2;
    if (scanf("%d %d", &v1, &v2) != 2) return 0;

    struct node *ans = lca(root, v1, v2);
    if (ans != NULL) {
        printf("%d", ans->data);
    }

    return 0;
}
