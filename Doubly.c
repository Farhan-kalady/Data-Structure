#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;// to store data
    struct Node* next; // to connect to the next Node
    struct Node* prev; // to connect to the previsous node
};

struct Node* head = NULL;//intilizing head and tail as NULL (default)
struct Node* tail = NULL;

void InsertionEnd(int value) {//to insert at the end
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    printf("%d inserted at the end.\n", value);
}

void InsertionBegin(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }

    printf("%d inserted at the beginning.\n", value);
}


void DeletionBegin() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }

    free(temp);
    printf("Element deleted from the beginning.\n");
}

void DeletionFront() {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = tail;

    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    free(temp);
    printf("Element deleted from the end.\n");
}


void DisplayStart() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List from start: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void DisplayEnd() {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = tail;
    printf("List from end: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void Count() {
    int count = 0;

    if (head == NULL) {
        printf("The list is empty. Nothing to count.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total number of nodes: %d\n", count);
}

int main() {
    int ch, value;

    while (1) {
        printf("\n==== Doubly Linked List Menu ====\n");
        printf("1. Insertion at the End\n");
        printf("2. Insertion at the Beginning\n");
        printf("3. Deletion from the Beginning\n");
        printf("4. Deletion from the End\n");
        printf("5. Display from the Start\n");
        printf("6. Display from the End\n");
        printf("7. Count Nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                InsertionEnd(value);
                break;

            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                InsertionBegin(value);
                break;

            case 3:
                DeletionBegin();
                break;

            case 4:
                DeletionFront();
                break;

            case 5:
                DisplayStart();
                break;

            case 6:
                DisplayEnd();
                break;

            case 7:
                Count();
                break;

            case 8:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
