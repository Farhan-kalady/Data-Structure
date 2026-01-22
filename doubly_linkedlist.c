#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL; // First node
struct Node *tail = NULL; // Last node

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at Beginning
void insertBegin(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning.\n", value);
}

// Insert at End
void insertEnd(int value) {
    struct Node *newNode = createNode(value);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Inserted %d at end.\n", value);
}

// Delete from Beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    if (head == tail) { // Only one element
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// Delete from End
void deleteEnd() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = tail;
    if (head == tail) { // Only one element
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}

// Traverse from Beginning
void traverseFromBegin() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Traversal (Beginning -> End): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Traverse from End
void traverseFromEnd() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = tail;
    printf("Traversal (End -> Beginning): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Count number of elements
void countNodes() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total nodes = %d\n", count);
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Traverse from Beginning\n");
        printf("6. Traverse from End\n");
        printf("7. Count Nodes\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBegin(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                deleteBegin();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                traverseFromBegin();
                break;
            case 6:
                traverseFromEnd();
                break;
            case 7:
                countNodes();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
