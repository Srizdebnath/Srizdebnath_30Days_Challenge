#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert( struct node* root, int data ) {
	if(root == NULL) {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
	} else {
		struct node* cur;
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
		return root;
	}
}

struct QueueItem {
    struct node* n;
    int hd;
};

void topView(struct node *root) {
    if (root == NULL) return;

    int map[1001];
    int visited[1001] = {0};
    int min_hd = 500, max_hd = 500;

 
    struct QueueItem queue[1001];
    int head = 0, tail = 0;

    queue[tail++] = (struct QueueItem){root, 500};

    while (head < tail) {
        struct QueueItem current = queue[head++];
        struct node* currNode = current.n;
        int currHd = current.hd;

        if (!visited[currHd]) {
            visited[currHd] = 1;
            map[currHd] = currNode->data;
            
            if (currHd < min_hd) min_hd = currHd;
            if (currHd > max_hd) max_hd = currHd;
        }

        if (currNode->left) {
            queue[tail++] = (struct QueueItem){currNode->left, currHd - 1};
        }
        if (currNode->right) {
            queue[tail++] = (struct QueueItem){currNode->right, currHd + 1};
        }
    }

    for (int i = min_hd; i <= max_hd; i++) {
        if (visited[i]) {
            printf("%d ", map[i]);
        }
    }
    printf("\n");
}

int main() {
    struct node* root = NULL;
    int t;
    int data;

    if (scanf("%d", &t) != 1) return 0;

    while(t-- > 0) {
        if (scanf("%d", &data) != 1) break;
        root = insert(root, data);
    }
  
	topView(root);
    return 0;
}
