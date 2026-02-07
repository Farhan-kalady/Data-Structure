#include <stdio.h>  // Standard input-output header
#include <stdlib.h> // Standard library header for malloc and free

// Structure of a node in the binary tree
struct Node
{
    int data;           // Data stored in the node
    struct Node *left;  // Pointer to the left child node
    struct Node *right; // Pointer to the right child node
};

// Create a new node with given value
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = value;                                             // Set data to the given value
    newNode->left = NULL;                                              // Initialize left child pointer to NULL
    newNode->right = NULL;                                             // Initialize right child pointer to NULL
    return newNode;                                                    // Return pointer to the newly created node
}

// Structure for a node in the queue used for level order traversal
struct QueueNode
{
    struct Node *data;      // Pointer to the binary tree node
    struct QueueNode *next; // Pointer to the next queue node
};

// Queue structure with front and rear pointers for efficient enqueue/dequeue
struct Queue
{
    struct QueueNode *front, *rear; // Pointers to front and rear of the queue
};

// Create and initialize an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue)); // Allocate memory for queue
    q->front = q->rear = NULL;                                      // Initialize front and rear pointers to NULL
    return q;                                                       // Return pointer to the new queue
}

// Add a node to the rear of the queue (enqueue operation)
void enqueue(struct Queue *q, struct Node *node)
{
    struct QueueNode *temp = (struct QueueNode *)malloc(sizeof(struct QueueNode)); // Allocate new queue node
    temp->data = node;                                                             // Set data to the node being enqueued
    temp->next = NULL;                                                             // New node will be at the rear, so next is NULL

    if (q->rear == NULL)
    {                              // If queue is empty
        q->front = q->rear = temp; // Both front and rear point to the new node
        return;                    // Exit function
    }

    q->rear->next = temp; // Link current rear node's next to new node
    q->rear = temp;       // Update rear pointer to new node
}

// Remove and return a node from the front of the queue (dequeue operation)
struct Node *dequeue(struct Queue *q)
{
    if (q->front == NULL) // If queue is empty, nothing to dequeue
        return NULL;

    struct QueueNode *temp = q->front; // Store front queue node
    struct Node *node = temp->data;    // Extract binary tree node from queue node

    q->front = q->front->next; // Move front pointer to next node in queue

    if (q->front == NULL) // If queue becomes empty after dequeue
        q->rear = NULL;   // Update rear to NULL as well

    free(temp);  // Free memory of dequeued queue node
    return node; // Return dequeued binary tree node
}

// Check if the queue is empty
int isEmpty(struct Queue *q)
{
    return q->front == NULL; // Returns 1 if empty, 0 otherwise
}

// Insert a value into the binary tree using level-order traversal
struct Node *insert(struct Node *root, int value)
{
    struct Node *newNode = createNode(value); // Create a new node with the given value

    if (root == NULL)   // If tree is empty
        return newNode; // New node becomes the root

    struct Queue *q = createQueue(); // Create a queue for level order traversal
    enqueue(q, root);                // Start traversal from root node

    while (!isEmpty(q))
    {                                   // Loop until queue is empty
        struct Node *temp = dequeue(q); // Get the front node in queue

        if (temp->left == NULL)
        {                         // If left child is empty
            temp->left = newNode; // Insert new node here
            break;                // Break out of the loop
        }
        else
        {
            enqueue(q, temp->left); // Else add left child to queue for later processing
        }

        if (temp->right == NULL)
        {                          // If right child is empty
            temp->right = newNode; // Insert new node here
            break;                 // Break out of the loop
        }
        else
        {
            enqueue(q, temp->right); // Else add right child to queue for later processing
        }
    }

    free(q);     // Free the queue after insertion is done
    return root; // Return the root of the tree (unchanged)
}

// Inorder traversal (Left subtree -> Root -> Right subtree)
void inorder(struct Node *root)
{
    if (root == NULL)
        return; // Base case: if node is NULL, return

    inorder(root->left);       // Traverse left subtree
    printf("%d ", root->data); // Print current node's data
    inorder(root->right);      // Traverse right subtree
}

// Preorder traversal (Root -> Left subtree -> Right subtree)
void preorder(struct Node *root)
{
    if (root == NULL)
        return; // Base case

    printf("%d ", root->data); // Print current node's data
    preorder(root->left);      // Traverse left subtree
    preorder(root->right);     // Traverse right subtree
}

// Postorder traversal (Left subtree -> Right subtree -> Root)
void postorder(struct Node *root)
{
    if (root == NULL)
        return; // Base case

    postorder(root->left);     // Traverse left subtree
    postorder(root->right);    // Traverse right subtree
    printf("%d ", root->data); // Print current node's data
}

// Main function with menu-driven interface
int main()
{
    struct Node *root = NULL; // Initialize root of the tree as NULL
    int choice, value;        // Variables to store user choice and value

    while (1)
    { // Infinite loop for menu-driven program
        // Display menu options
        printf("\n=== Binary Tree Menu ===\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user's menu choice

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);        // Read value to insert
            root = insert(root, value); // Insert value into tree
            break;

        case 2:
            printf("Inorder: ");
            inorder(root); // Perform inorder traversal and print
            printf("\n");
            break;

        case 3:
            printf("Preorder: ");
            preorder(root); // Perform preorder traversal and print
            printf("\n");
            break;

        case 4:
            printf("Postorder: ");
            postorder(root); // Perform postorder traversal and print
            printf("\n");
            break;

        case 5:
            exit(0); // Exit the program

        default:
            printf("Invalid choice. Try again.\n"); // Handle invalid input
        }
    }

    return 0; // Program ends here (never reached due to infinite loop with exit)
}
