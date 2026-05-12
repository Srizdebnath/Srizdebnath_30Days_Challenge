#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int freq;
    char data;
    struct node *left;
    struct node *right;
} node;

void decode_huff(node *root, char *s) {
    node *current = root;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data);
            current = root; 
        }
    }
    printf("\n");
}

typedef struct {
    node **data;
    int size;
    int capacity;
} MinHeap;

MinHeap* create_heap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (node**)malloc(sizeof(node*) * (capacity + 1));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void push(MinHeap* heap, node* n) {
    heap->size++;
    int i = heap->size;
    heap->data[i] = n;
    while (i > 1 && heap->data[i]->freq < heap->data[i / 2]->freq) {
        node* temp = heap->data[i];
        heap->data[i] = heap->data[i / 2];
        heap->data[i / 2] = temp;
        i /= 2;
    }
}

node* pop(MinHeap* heap) {
    if (heap->size == 0) return NULL;
    node* min_node = heap->data[1];
    heap->data[1] = heap->data[heap->size];
    heap->size--;
    
    int i = 1;
    while (2 * i <= heap->size) {
        int smallest = 2 * i;
        if (smallest + 1 <= heap->size && heap->data[smallest + 1]->freq < heap->data[smallest]->freq) {
            smallest++;
        }
        if (heap->data[i]->freq <= heap->data[smallest]->freq) break;
        node* temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;
        i = smallest;
    }
    return min_node;
}

node* create_node(int freq, char data, node* left, node* right) {
    node* temp = (node*)malloc(sizeof(node));
    temp->freq = freq;
    temp->data = data;
    temp->left = left;
    temp->right = right;
    return temp;
}

char codes[256][100];
void generate_codes(node* root, char* code, int depth) {
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        strcpy(codes[(unsigned char)root->data], code);
        return;
    }
    if (root->left) {
        code[depth] = '0';
        generate_codes(root->left, code, depth + 1);
    }
    if (root->right) {
        code[depth] = '1';
        generate_codes(root->right, code, depth + 1);
    }
}

int main() {
    char s[1000];
    if (scanf("%s", s) != 1) return 0;
    
    int freq[256] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        freq[(unsigned char)s[i]]++;
    }
    
    int distinct = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) distinct++;
    }
    
    MinHeap* heap = create_heap(distinct);
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            push(heap, create_node(freq[i], (char)i, NULL, NULL));
        }
    }
    
    while (heap->size > 1) {
        node* left = pop(heap);
        node* right = pop(heap);
        node* combined = create_node(left->freq + right->freq, '\0', left, right);
        push(heap, combined);
    }
    
    node* root = pop(heap);

    char code[100];
    generate_codes(root, code, 0);
    
    char encoded_s[10000] = "";
    for (int i = 0; i < len; i++) {
        strcat(encoded_s, codes[(unsigned char)s[i]]);
    }
    
    decode_huff(root, encoded_s);
    
    return 0;
}
