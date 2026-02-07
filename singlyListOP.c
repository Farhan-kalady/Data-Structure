// Single Linked List operations- Creation, Insertion, Deletion, Traversal, Count.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertNode(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Delete by value
void deleteNode(int value)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;

    // If first node is to be deleted
    if (head->data == value)
    {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display list
void displayList()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count nodes
void countNodes()
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Total nodes = %d\n", count);
}

// Main function
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Count Nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertNode(value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;
        case 3:
            displayList();
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

/* Sample Output:

--- Singly Linked List Menu ---
1. Insert Node
2. Delete Node
3. Display List
4. Count Nodes
5. Exit
Enter your choice: 1
Enter value: 10

--- Singly Linked List Menu ---
Enter your choice: 1
Enter value: 20

--- Singly Linked List Menu ---
Enter your choice: 3
List: 10 -> 20 -> NULL

--- Singly Linked List Menu ---
Enter your choice: 4
Total nodes = 2

--- Singly Linked List Menu ---
Enter your choice: 2
Enter value to delete: 10

--- Singly Linked List Menu ---
Enter your choice: 3
List: 20 -> NULL

--- Singly Linked List Menu ---
Enter your choice: 5

*/
