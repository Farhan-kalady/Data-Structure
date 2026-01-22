#include <stdio.h>
#include <stdlib.h>
#define SIZE 5   // maximum size of circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Insert into circular queue
void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) // first element
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}

// Delete from circular queue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }
    int val = queue[front];
    if (front == rear) // only one element
        front = rear = -1;
    else
        front = (front + 1) % SIZE;

    printf("%d deleted from queue\n", val);
}

// Display elements
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Count elements
void count() {
    if (front == -1) {
        printf("Number of elements: 0\n");
        return;
    }
    int cnt = (rear >= front) ? (rear - front + 1) : (SIZE - front + rear + 1);
    printf("Number of elements: %d\n", cnt);
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Count\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            count();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
