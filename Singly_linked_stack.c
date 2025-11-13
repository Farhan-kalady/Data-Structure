#include<stdio.h>
#include<stdlib.h>

struct Node
	{
	int data;
	struct Node* next;
	};

struct Node* top=NULL;

struct Node* createNode(int value)
	{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
/*	if (!newNode) 
		{
        	printf("Memory allocation failed!\n");
        	return NULL;
    		} */
	newNode->data=value;
	newNode->next=NULL;
	return newNode;
	}
void push(int value) 
	{
	struct Node* newNode=createNode(value);
/*	if (!newNode) 
	return;*/
	newNode->next=top;
	top=newNode;
	printf("Node with value %d Pushed to the stack.\n", value);
	}

void pop() 
	{
	if (top == NULL) 
		{
	        printf("Stack Underflow. Cannot Pop\n");
        	return;
    		}	
    	struct Node* temp = top;
    	top = top->next;
    	printf("%d Popped from stack.\n", temp->data);
    	free(temp);
	}
void traverse()  
	{
    	if (top == NULL) 
    		{
        	printf("Stack is empty.\n");
        	return;
    		}	
    	struct Node* temp = top;
    	printf("\nStack elements: \n");
    	while (temp != NULL) 
    		{
        	printf("\n\t%d  ", temp->data);
        	temp = temp->next;
    		}
    	printf("\n");
	}	
int count() 
	{
    	int cnt = 0;
    	struct Node* temp = top;
    	while (temp != NULL) 
    		{
        	cnt++;
        	temp = temp->next;
    		}
    	return cnt;
	}
int main() 
	{
    	int choice, value, pos;
    	printf("\n--- Singly Linked Stack Menu ---\n\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Traverse (Display)\n");
        printf("4. Count Elements\n");
        printf("5. Exit\n");
        	
    	while (1) 
    		{
        	printf("Enter your choice: ");
        	scanf("%d", &choice);
        	switch(choice) 
        		{
            		case 1:
                printf("Enter value to push: ");
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
                printf("Total elements in stack: %d\n", count());
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        		}
    		}
	}	
    		
