#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode();
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
struct Node*search(struct Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }
    if (value < root->data)
    {
        return search(root->left, value);
    }
    return search(root->right, value);
}

struct Node *inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

struct Node *preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->data);
        preorder(root->right);
    }
}

struct Node *postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}

int main
{
    struct Node *root = NULL;
    int value, choice;

    while (1)
    {
        printf("\n--Binary Search tree menu--\n");
        printf("1.Insert\n2.Search \n3.Inorder \n4.Preorder \n5.Postorder \n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter value to search:");
            scanf("%d",&value);
            if (search(root, value) != NULL)
                printf("%d found in the tree.\n", value);
            else
                printf("%d not found in the tree.\n", value);
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
            printf("Inavalid") ;       

        }
    }
    return 0;
}
