#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int count = 0;

// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % MAX_SIZE);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to insert an element into the queue
void enqueue() {
    if (isFull()) {
        printf("\nQueue is full! Cannot enqueue.\n");
    } else {
        int data;
        printf("Enter data to enqueue: ");
        scanf("%d", &data);
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = data;
        count++;
        printf("%d enqueued successfully.\n", data);
    }
}

// Function to delete an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("\nQueue is empty! Cannot dequeue.\n");
    } else {
        int data = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        count--;
        printf("%d dequeued successfully.\n", data);
    }
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("\nQueue is empty! Nothing to display.\n");
    } else {
        printf("\nCircular Queue elements are: ");
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[i]);
        printf("\n");
    }
}

// Function to count the number of elements in the queue
void count_elements() {
    printf("Number of elements in the queue: %d\n", count);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Count Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                count_elements();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}