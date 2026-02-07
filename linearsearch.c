#include<stdio.h>
int main()
{
    int arr[60],i,x,n,flag=0;
    printf("Enter the Number of Elements :\n");
    scanf("%d",&n);
    printf("\n Enter the Elements :\n ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the Element to Search :\n");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(arr[i]==x){
        printf("Element %d Found at the postion %d\n",x,i+1);
        flag=1;
        break;
    }
    }

    if(flag==0)
    printf("Elemnt not Found in the array");
    return 0;
}

// #include<stdio.h>   // Standard Input Output header file for printf and scanf

// int main()
// {
//     int arr[60], i, x, n, flag = 0;  
//     // arr[60] -> array of max 60 integers
//     // i -> loop counter
//     // x -> element to search
//     // n -> number of elements entered by user
//     // flag -> to check whether element is found (0 = not found, 1 = found)

//     printf("Enter the Number of Elements :\n");
//     scanf("%d", &n);   // Taking the size of array from user

//     printf("\n Enter the Elements :\n ");
//     for(i = 0; i < n; i++)   // Loop to take array input
//     {
//         scanf("%d", &arr[i]);
//     }

//     printf("Enter the Element to Search :\n");
//     scanf("%d", &x);   // Taking the element to search

//     for(i = 0; i < n; i++)   // Loop through array to search element
//     {
//         if(arr[i] == x)   // Check if current element matches search element
//         {
//             printf("Element %d Found at the position %d\n", x, i + 1);
//             // Printing element and position (i+1 because array index starts from 0)
//             flag = 1;  // Mark as found
//             break;     // Exit loop as soon as element is found
//         }
//     }

//     if(flag == 0)   // If element never found in loop
//         printf("Element not Found in the array");

//     return 0;  // Exit program successfully
// }

