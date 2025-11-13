#include<stdio.h>
#include<stdlib.h>

struct Node
	{
	int data;
	struct Node* next;
	};

struct Node* head=NULL;

struct Node* createNode(int value)
	{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=NULL;
	return newNode;
	}
void insertAtBeginning(int value) 
	{
	struct Node* newNode=createNode(value);
	newNode->next=head;
	head=newNode;
	printf("Inserted %d at the beginning.\n", value);
	}
void insertAtEnd(int value) 
	{
	struct Node* newNode=createNode(value);
	if (head == NULL) 
		{
        	head = newNode;
        	printf("Inserted %d as first node.\n", value);
        	return;
    		}
    	struct Node* temp=head;
    	while(temp->next!=NULL)
    		temp=temp->next;
    	
    	temp->next = newNode;
    	printf("Inserted %d at the end.\n", value);
	}
void insertAtPosition(int value, int pos) 
	{
    	struct Node* newNode = createNode(value);
    	if (pos == 1) 
    		{
	        newNode->next = head;
        	head = newNode;
        	printf("Inserted %d at position %d.\n", value, pos);
        	return;
    		}
    	struct Node* temp = head;
    	for (int i = 1; temp != NULL && i < pos-1; i++) 
    		{
        	temp = temp->next;
    		}
    	 if (temp == NULL) 
    	 	{
       		printf("Position out of range!\n");
        	return;
    		}
    	newNode->next = temp->next;
    	temp->next = newNode;
    	printf("Inserted %d at position %d.\n", value, pos);
	}	
void deleteFromBeginning() 
	{
	if (head == NULL) 
		{
	        printf("List is empty.\n");
        	return;
    		}	
    	struct Node* temp = head;
    	head = head->next;
    	printf("Deleted node with value %d from beginning.\n", temp->data);
    	free(temp);
	}
void deleteFromEnd() 
	{
	if (head == NULL) 
		{
	        printf("List is empty.\n");
        	return;
    		}
	struct Node* temp = head;
    	struct Node* prev = NULL;
    	while (temp->next != NULL) 
    		{
        	prev = temp;
        	temp = temp->next;
    		}
	if (prev == NULL) 
		{
        	head = NULL; // Only one element
    		} 
    	else 
    		{
        	prev->next = NULL;
    		}
    	printf("Deleted node with value %d from end.\n", temp->data);
    	free(temp);
	}
void deleteValue(int value) 
	{
    	if (head == NULL) 
    		{
        	printf("List is empty.\n");
        	return;
    		}
    	struct Node* temp = head;
    	struct Node* prev = NULL;
    	while (temp != NULL && temp->data != value) 
    		{
        	prev = temp;
        	temp = temp->next;
    		}
    	if (temp == NULL) 
    		{
        	printf("Value %d not found!\n", value);
        	return;
    		}
	if (prev == NULL) 
		{
        	head = temp->next; // deleting first node
    		} 
    	else
    		{
        	prev->next = temp->next;
    		}
	printf("Deleted node with value %d.\n", value);
    	free(temp);
	}
void display() 
	{
    	if (head == NULL) 
    		{
        	printf("List is empty.\n");
        	return;
    		}	
    	struct Node* temp = head;
    	printf("Linked List: ");
    	while (temp != NULL) 
    		{
        	printf("%d -> ", temp->data);
        	temp = temp->next;
    		}
    	printf("NULL\n");
	}	
void countNodes() 
	{
    	int count = 0;
    	struct Node* temp = head;
    	while (temp != NULL) 
    		{
        	count++;
        	temp = temp->next;
    		}
    	printf("Total number of nodes: %d\n", count);
	}
int main() 
	{
    	int choice, value, pos;
    	printf("\n--- Singly Linked List Menu ---\n");
        	printf("1. Insert at Beginning\n");
        	printf("2. Insert at End\n");
        	printf("3. Insert at Position\n");
        	printf("4. Delete from Beginning\n");
        	printf("5. Delete from End\n");
        	printf("6. Delete Specific Value\n");
        	printf("7. Display\n");
        	printf("8. Count Nodes\n");
        	printf("9. Exit\n");
        	
    	while (1) 
    		{
        	printf("Enter your choice: ");
        	scanf("%d", &choice);
        	switch(choice) 
        		{
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
                	printf("Enter value and position: ");
                	scanf("%d%d", &value, &pos);
                	insertAtPosition(value, pos);
                	break;
            		case 4:
                	deleteFromBeginning();
                	break;
            		case 5:
                	deleteFromEnd();
                	break;
            		case 6:
                	printf("Enter value to delete: ");
                	scanf("%d", &value);
                	deleteValue(value);
                	break;
            		case 7:
                	display();
                	break;
            		case 8:
                	countNodes();
                	break;
            		case 9:
                	printf("Exiting program.\n");
                	return 0;
            		default:
                	printf("Invalid choice! Try again.\n");
        		}
    		}
	}	
    		
    		
    		
    		
    		
    		
