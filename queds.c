#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX],front=-1,rear=-1;

void enqueue(){
    int value;
    if(rear==MAX-1)
    {
        printf("THE queue if Full \n");
    }
    else
    {
        printf("Enter the Value to Be inserted :\n");
        scanf("%d",&value);
        if(front==-1)
        front=0;
        queue[++rear]=value;
    }
}

void dequeue()
    {
    if(front==-1||front >rear)
    printf("Queue is Empty\n");
    else{
        printf("Dequeued : %d",queue[front++]);
    }
}

void display()
{
int i;
if(front==-1||front >rear)
printf("\nThe queue is empty \n");
else{

    for(i=front;i<=rear;i++)
printf("%d ",queue[i]);
}
}

int main(){
    int ch;
    
    while (1)
    {
    printf("Enter the Option \n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.display\n");
    printf("4.Exit\n");
    scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
        display ();
        break;
        case 4:
        exit(0);
        default:
        printf("Invalid Option \n");
            break;
        }
    }

}

// #include<stdio.h>   // Standard input-output library
// #include<stdlib.h>  // For exit() function

// #define MAX 100     // Maximum size of the queue

// // Declaring queue as an array with size MAX
// // front = index of first element
// // rear = index of last element
// int queue[MAX], front = -1, rear = -1;

// // Function to insert (enqueue) an element in the queue
// void enqueue(){
//     int value;
//     if(rear == MAX - 1)  // If rear reaches end of array
//     {
//         printf("The queue is Full \n");  // Overflow condition
//     }
//     else
//     {
//         printf("Enter the Value to be inserted :\n");
//         scanf("%d", &value);

//         if(front == -1)   // If queue is initially empty
//             front = 0;    // Set front to 0 when inserting first element

//         queue[++rear] = value;  // Increase rear and insert the value
//     }
// }

// // Function to delete (dequeue) an element from the queue
// void dequeue(){
//     if(front == -1 || front > rear) // If queue is empty
//         printf("Queue is Empty\n");
//     else{
//         printf("Dequeued : %d\n", queue[front]); // Print removed element
//         front++;   // Move front to next element
//     }
// }

// // Function to display the queue elements
// void display(){
//     int i;
//     if(front == -1 || front > rear) // If queue is empty
//         printf("\nThe queue is empty \n");
//     else{
//         printf("Queue elements: ");
//         for(i = front; i <= rear; i++) // Print from front to rear
//             printf("%d ", queue[i]);
//         printf("\n");
//     }
// }

// // Main function
// int main(){
//     int ch;
    
//     while (1) // Infinite loop until user exits
//     {
//         printf("\nEnter the Option \n");
//         printf("1. Enqueue (Insert)\n");
//         printf("2. Dequeue (Remove)\n");
//         printf("3. Display\n");
//         printf("4. Exit\n");
//         scanf("%d", &ch);

//         switch (ch) // Menu-driven choice
//         {
//             case 1:
//                 enqueue();  // Call insert
//                 break;
//             case 2:
//                 dequeue();  // Call delete
//                 break;
//             case 3:
//                 display();  // Call display
//                 break;
//             case 4:
//                 exit(0);    // Exit program
//             default:
//                 printf("Invalid Option \n");
//                 break;
//         }
//     }
// }
