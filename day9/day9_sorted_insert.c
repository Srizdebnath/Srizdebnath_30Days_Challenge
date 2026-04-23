#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedListNode {
    int data;
    struct DoublyLinkedListNode* next;
    struct DoublyLinkedListNode* prev;
} DoublyLinkedListNode;

DoublyLinkedListNode* create_node(int data) {
    DoublyLinkedListNode* node = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* new_node = create_node(data);
    
    // Case 1: Empty list
    if (head == NULL) {
        return new_node;
    }
    
    // Case 2: Insert before the head
    if (data <= head->data) {
        new_node->next = head;
        head->prev = new_node;
        return new_node;
    }
    
    DoublyLinkedListNode* current = head;
    
    // Case 3: Insert in the middle or at the end
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    
    // Now current points to the node after which new_node should be inserted
    // OR current is the last node and data is greater than all existing nodes
    
    new_node->next = current->next;
    new_node->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = new_node;
    }
    current->next = new_node;
    
    return head;
}

void print_list(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

void free_list(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* current = head;
    while (current != NULL) {
        DoublyLinkedListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) break;
        
        DoublyLinkedListNode* head = NULL;
        DoublyLinkedListNode* tail = NULL;
        
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            DoublyLinkedListNode* node = create_node(val);
            if (head == NULL) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }
        
        int data;
        scanf("%d", &data);
        
        head = sortedInsert(head, data);
        print_list(head);
        free_list(head);
    }
    
    return 0;
}
