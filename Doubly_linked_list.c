#include<stdio.h>
#include<stdlib.h>

struct Node
	{
	int data;
	struct Node* next;
	struct Node *prev;
	};

struct Node* head=NULL;
int totalNodes=0;

struct Node* createNode(int value)
	{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	 if (!newNode) 
	 	{
        	printf("Memory allocation failed!\n");
        	exit(1);
    		}
	newNode->data=value;
	newNode->prev=NULL;
	newNode->next=NULL;
	return newNode;
	}
void insertAtBeginning(int value) 
	{
	struct Node* newNode=createNode(value);
	if(head == NULL) 
		{
	        head = newNode;
    		}
    	else
    		{
		newNode->next=head;
		head->prev = newNode;
		head=newNode;
		}
	totalNodes++; 
	printf("Inserted %d at the beginning.\n", value);
	}
void insertAtEnd(int value) 
	{
	struct Node* newNode=createNode(value);
	if (head == NULL) 
		{
        	head = newNode;
    		}
    	else
    		{
    	
    		struct Node* temp=head;
    		while(temp->next!=NULL)
    			temp=temp->next;
    	
    		temp->next = newNode;
    		newNode->prev=temp;
    		}
    	totalNodes++;
    	printf("Inserted %d at the end.\n", value);
	}
void insertAtPosition(int value, int pos) 
	{
    	if (pos == 1|| pos > totalNodes + 1) 
    		{
    		printf("Invalid position!\n");
        	return;
        	}
        if (pos == 1) 
        {
        insertAtBeginning(value);
        return;
    	}
    	if (pos == totalNodes + 1) 
    	{
        insertAtEnd(value);
        return;
    	}
	struct Node* newNode = createNode(value);
    	struct Node* temp = head;
    	for (int i = 1; i < pos-1; i++) 
    		{
        	temp = temp->next;
    		}
    	newNode->next = temp->next;
    	newNode->prev = temp;
    	temp->next->prev = newNode;
    	temp->next = newNode;
    	
    	totalNodes++;
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
    	if (head != NULL)
        	head->prev = NULL;

    	printf("Deleted node with value %d from beginning.\n", temp->data);
    	free(temp);
    	totalNodes--;
	}
void deleteFromEnd() 
	{
	if (head == NULL) 
		{
	        printf("List is empty.\n");
        	return;
    		}
	struct Node* temp = head;
	if (temp->next == NULL) 
	{
        	head = NULL;
        	printf("Deleted %d from the end.\n", temp->data);
        	free(temp);
        	totalNodes--;
        	return;
    	}
    	while (temp->next != NULL)
        	temp = temp->next;

    	temp->prev->next = NULL;
    	printf("Deleted %d from the end.\n", temp->data);
    	free(temp);
    	totalNodes--;
	}
void deleteByValue(int value) 
	{
    	if (head == NULL) 
    		{
        	printf("List is empty.\n");
        	return;
    		}
    	struct Node* temp = head;
    	while (temp != NULL && temp->data != value) 
        	temp = temp->next;
        if (temp == NULL) 
        {
        	printf("Value %d not found in the list.\n", value);
        	return;
    	}
    	if (temp == head) 
    		{
        	head = head->next;
        	if (head != NULL)
            	head->prev = NULL;
    		}
    	else if (temp->next == NULL) 
    		{
        	temp->prev->next = NULL;
    		}
    	else 
    		{
        	temp->prev->next = temp->next;
        	temp->next->prev = temp->prev;
    		}
    	printf("Deleted node with value %d.\n", temp->data);
    	free(temp);
    	totalNodes--;
	}
void traverseForward() 
	{
    		if (head == NULL) {
        	printf("List is empty!\n");
        	return;
    	}

    	struct Node *temp = head;
    	printf("Forward Traversal: ");
    	while (temp != NULL) 
    		{
        	printf("%d ", temp->data);
        	temp = temp->next;
    		}
    	printf("\n");
	}
void traverseBackward() 
	{
    	if (head == NULL) 
    		{
        	printf("List is empty!\n");
        	return;
    	}
    	struct Node *temp = head;
    	while (temp->next != NULL)
        	temp = temp->next;
    	printf("Backward Traversal: ");
    	while (temp != NULL) 
    		{
        	printf("%d ", temp->data);
        	temp = temp->prev;
    		}
    	printf("\n");
	}
  
void display() 
	{
    	traverseForward();
    	traverseBackward();
	}	
void countNodes() 
	{
    	printf("Total nodes in the list: %d\n", totalNodes);
	}
int main() 
	{
	    int choice, value, position;
	    printf("\n--- Doubly Linked List Menu ---\n");
	    printf("1. Insert at Beginning\n");
	    printf("2. Insert at End\n");
            printf("3. Insert at Specific Position\n");
            printf("4. Delete from Beginning\n");
            printf("5. Delete from End\n");
            printf("6. Delete by Specific Value\n");
            printf("7. Traverse Forward\n");
            printf("8. Traverse Backward\n");
            printf("9. Display from Both Sides\n");
            printf("10. Count Nodes\n");
            printf("11. Exit\n");
            while (1) 
            	{
        	printf("Enter your choice: ");
 	        scanf("%d", &choice);
        	switch (choice) 
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
                	scanf("%d %d", &value, &position);
                	insertAtPosition(value, position);
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
                	deleteByValue(value);
                	break;

            		case 7:
                	traverseForward();
                	break;

            		case 8:
                	traverseBackward();
                	break;

            		case 9:
                	display();
                	break;

            		case 10:
                	countNodes();
                	break;

            		case 11:
                	printf("Exiting program...\n");
                	exit(0);

            		default:
                	printf("Invalid choice! Try again.\n");
        		}
    		}

    	return 0;
	}    		
    		
    		
    		
    		
