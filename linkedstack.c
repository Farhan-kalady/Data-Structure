#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL; // Stack top

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Push (Insert at top)
void push(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    printf("Pushed %d\n", value);
}

// Pop (Delete from top)
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! (Empty Stack)\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped %d\n", temp->data);
    top = top->next;
    free(temp);
}

// Traverse (Display stack elements)
void traverse() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack (Top -> Bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Count nodes in stack
void countNodes() {
    int count = 0;
    struct Node *temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total elements in stack = %d\n", count);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack using Linked List Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Traverse\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                traverse();
                break;
            case 4:
                countNodes();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

