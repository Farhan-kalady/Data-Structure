#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order
#define MAX 100
struct Node* queue[MAX];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == MAX - 1) return;
    queue[++rear] = node;
    if (front == -1) front = 0;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

int isQueueEmpty() {
    return front == -1 || front > rear;
}

// Insert node in level order
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Reset queue
    front = rear = -1;
    enqueue(*root);

    while (!isQueueEmpty()) {
        struct Node* temp = dequeue();

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            enqueue(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            enqueue(temp->right);
        }
    }
}

// Traversals
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Delete deepest node helper
void deleteDeepest(struct Node* root, struct Node* delNode) {
    front = rear = -1;
    enqueue(root);

    struct Node* temp;

    while (!isQueueEmpty()) {
        temp = dequeue();
        if (temp->left) {
            if (temp->left == delNode) {
                free(temp->left);
                temp->left = NULL;
                return;
            } else {
                enqueue(temp->left);
            }
        }
        if (temp->right) {
            if (temp->right == delNode) {
                free(temp->right);
                temp->right = NULL;
                return;
            } else {
                enqueue(temp->right);
            }
        }
    }
}

// Delete a node by key
void deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            root = NULL;
            printf("Node deleted.\n");
        } else {
            printf("Node not found.\n");
        }
        return;
    }

    front = rear = -1;
    enqueue(root);

    struct Node* temp;
    struct Node* keyNode = NULL;

    while (!isQueueEmpty()) {
        temp = dequeue();
        if (temp->data == key) {
            keyNode = temp;
        }
        if (temp->left) enqueue(temp->left);
        if (temp->right) enqueue(temp->right);
    }

    if (keyNode != NULL) {
        int x = temp->data;
        deleteDeepest(root, temp);
        keyNode->data = x;
        printf("Node deleted.\n");
    } else {
        printf("Node not found.\n");
    }
}

// Display menu
void printMenu() {
    printf("\n--- Binary Tree Operations ---\n");
    printf("1. Insert Node\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Delete Node\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(&root, val);
                printf("Node inserted.\n");
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(root, val);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
