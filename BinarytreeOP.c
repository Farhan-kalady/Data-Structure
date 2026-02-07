#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* root = NULL;



// Insert node (level order)
void insert(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    if (root == NULL) {
        root = newNode;
        return;
    }

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else queue[rear++] = temp->left;

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else queue[rear++] = temp->right;
    }
}

// Traversals
void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}
void preorder(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(struct Node* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

// Delete node (replace with deepest)
void deleteNode(int key) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            root = NULL;
        }
        return;
    }

    struct Node *keyNode = NULL, *temp, *last;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];
        if (temp->data == key) keyNode = temp;
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }

    if (keyNode) {
        last = temp; // last node
        keyNode->data = last->data;

        // remove last node
        front = rear = 0;
        queue[rear++] = root;
        while (front < rear) {
            temp = queue[front++];
            if (temp->left) {
                if (temp->left == last) {
                    free(temp->left);
                    temp->left = NULL;
                    return;
                }
                queue[rear++] = temp->left;
            }
            if (temp->right) {
                if (temp->right == last) {
                    free(temp->right);
                    temp->right = NULL;
                    return;
                }
                queue[rear++] = temp->right;
            }
        }
    }
}

// Menu
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
} 