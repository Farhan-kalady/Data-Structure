#include<stdio.h> 
#include<stdlib.h>
int main ()
{
    int ch, arr[20],i,n,pos,x;
    printf("Enter the number of Elements :\n");
    scanf("%d",&n);
    printf("Enter the %d number of Elements :\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nInitial Array\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    while(1)
    {
        printf("\n__________MENU_________\n");
        printf("1.Insert\n");
        printf("2.display\n");
        printf("3.exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Postion of the Element To be Inserted :\n");
            scanf("%d",&pos);
            printf("Enter the Element :\n");
            scanf("%d",&x);
            for(i=n;i>=pos;i--)
            {
            arr[i]=arr[i-1];           
            }
            arr[pos-1]=x;
            n++;
            break;
        case 2:
            printf("\nCurrent Array\n");
            for(i=0;i<n;i++)
            {
                printf("%d",arr[i]);
            }
            break;
        case 3:
            exit(0);
        default:
        printf("\n Invalid Choice");
            break;
        }
    }

}
// #include<stdio.h>      // Standard Input Output library for printf, scanf
// #include<stdlib.h>     // Standard library for exit() function

// int main ()
// {
//     int ch, arr[20], i, n, pos, x;  // ch=choice, arr=array, n=size, pos=position, x=element

//     // Taking array size from user
//     printf("Enter the number of Elements :\n");
//     scanf("%d",&n);

//     // Input array elements
//     printf("Enter the %d number of Elements :\n",n);
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&arr[i]);
//     }

//     // Display the initial array
//     printf("\nInitial Array\n");
//     for(i=0;i<n;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     printf("\n");

//     // Menu loop runs until user exits
//     while(1)
//     {
//         // Menu options
//         printf("\n__________MENU_________\n");
//         printf("1.Insert\n");
//         printf("2.Display\n");
//         printf("3.Exit\n");
//         scanf("%d",&ch);

//         // Switch case for choices
//         switch (ch)
//         {
//         case 1:  // Insertion
//             printf("Enter the Position of the Element To be Inserted :\n");
//             scanf("%d",&pos);

//             printf("Enter the Element :\n");
//             scanf("%d",&x);

//             // Shift elements to the right to make space
//             for(i=n;i>=pos;i--)
//             {
//                 arr[i]=arr[i-1];           
//             }

//             // Place the new element at the given position
//             arr[pos-1]=x;

//             // Increase size of array
//             n++;
//             break;

//         case 2:  // Display
//             printf("\nCurrent Array\n");
//             for(i=0;i<n;i++)
//             {
//                 printf("%d ",arr[i]);
//             }
//             break;

//         case 3:  // Exit program
//             exit(0);

//         default: // Invalid choice handling
//             printf("\n Invalid Choice");
//             break;
//         }
//     }

// }
