#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;
    void push()
    {
        int value;
        if(top==MAX-1)
        {
            printf("Overflow\\n");
        }
        else
        {
            printf("Enter Value\n");
            scanf("%d",&value);
            stack[++top]=value;
        }
    }

    void pop()
    {
     if(top==-1)
     {
        printf("Stack Underflow Condition");
     }
     else
     {
        printf("Popped %d\n",stack[top--]);

     }  

    }

    void display()

    {   if(top==-1){
        
        printf("There is nothing to display ...");

    }
    else{
        int i;
        printf("The current Stack Values are :");
        for(i=top;i>=0;i--)
        {
        printf("%d\n",stack[i]);
        }
        
}
    }
int main ()
{
    int arr[100],ch;
    while(1){
        printf("\nEnter the Choice\n");
    printf("1.Push\n\n");
    printf("2.Pop\n\n");
    printf("3.display\n\n");
    printf("4.exit\n\n");
    scanf("%d",&ch);
    printf("  \n");
    switch(ch)
    {
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(0);
        break;
        default :
        printf("Invlaid Option , Try Again.");
        break;
    }
    }
}


// #include<stdio.h>    // Standard Input/Output library (for printf, scanf)
// #include<stdlib.h>   // Standard library (for exit function)

// #define MAX 100      // Defining maximum size of the stack as 100

// int stack[MAX];      // Declaring stack as an array of size MAX
// int top = -1;        // Variable to keep track of the top of the stack (-1 means stack is empty)


// // Function to insert (push) an element into the stack
// void push()
// {
//     int value;
//     if(top == MAX - 1)   // If top reaches MAX-1, stack is full
//     {
//         printf("Overflow\n");  // Stack Overflow condition
//     }
//     else
//     {
//         printf("Enter Value\n");
//         scanf("%d", &value);   // Take input from user
//         stack[++top] = value;  // Increment top, then store value at that index
//     }
// }


// // Function to remove (pop) an element from the stack
// void pop()
// {
//     if(top == -1)   // If top is -1, stack is empty
//     {
//         printf("Stack Underflow Condition");  // Stack Underflow
//     }
//     else
//     {
//         printf("Popped %d\n", stack[top--]);  
//         // Print top element and then decrement top
//     }  
// }


// // Function to display elements of stack
// void display()
// {   
//     if(top == -1)  // If stack is empty
//     {
//         printf("There is nothing to display ...");
//     }
//     else
//     {
//         int i;
//         printf("The current Stack Values are :\n");
//         for(i = top; i >= 0; i--)   // Print from top to bottom
//         {
//             printf("%d\n", stack[i]);
//         }
//     }
// }


// // Main function
// int main ()
// {
//     int ch;   // Variable to store user's choice

//     while(1)   // Infinite loop (program runs until user selects Exit)
//     {
//         // Menu options
//         printf("\nEnter the Choice\n");
//         printf("1.Push\n\n");
//         printf("2.Pop\n\n");
//         printf("3.Display\n\n");
//         printf("4.Exit\n\n");

//         scanf("%d", &ch);   // Take user choice as input
//         printf("  \n");

//         switch(ch)   // Based on choice, call the required function
//         {
//             case 1:
//                 push();    // Call push function
//                 break;
//             case 2:
//                 pop();     // Call pop function
//                 break;
//             case 3:
//                 display(); // Call display function
//                 break;
//             case 4:
//                 exit(0);   // Exit program
//                 break;
//             default:
//                 printf("Invalid Option, Try Again."); // Wrong input case
//                 break;
//         }
//     }
// }
