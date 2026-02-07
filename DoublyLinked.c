/*Doubly Linked List- Creation, Insert operations through beginning, Insert operations 
through end, Delete operations from beginning, Delete operations from end, Traversal 
from beginning, Traversal from end, Display from both side, Count number of 
elements.*/ 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL, *tail = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    printf("%d inserted at beginning\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);

    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    printf("%d inserted at end\n", value);
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("%d deleted from beginning\n", temp->data);

    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = tail;
    printf("%d deleted from end\n", temp->data);

    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    free(temp);
}

// Display list from beginning
void displayFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("List from beginning: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display list from end
void displayFromEnd() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = tail;
    printf("List from end: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Count total nodes
void countNodes() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total nodes: %d\n", count);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display from Beginning\n");
        printf("6. Display from End\n");
        printf("7. Count Nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                displayFromBeginning();
                break;
            case 6:
                displayFromEnd();
                break;
            case 7:
                countNodes();
                break;
            case 8:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


/*
--- Sample Output for Doubly Linked List ---
Enter your choice: 1
Enter value: 50
50 inserted at beginning
Enter your choice: 1
Enter value: 30
30 inserted at beginning
Enter your choice: 2
Enter value: 70
70 inserted at end
Enter your choice: 5
List from beginning: 30 50 70 
Enter your choice: 6
List from end: 70 50 30 
Enter your choice: 3
30 deleted from beginning
Enter your choice: 4
70 deleted from end
Enter your choice: 7
Total nodes: 1
Enter your choice: 8
Exiting program...
*/