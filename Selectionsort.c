// #include<stdio.h>
// int main()
// {
//     int arr[40],temp,i,j,n,low;
//     printf("Enter Enter number of Elemnts to Be Sorted\n");
//     scanf("%d",&n);
//     printf("Enter the %d Number of  Elements  :",n);
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&arr[i]);
//         }
//         printf("---------------:Unsorted Arry :---------------------------\n");
//      for(i=0;i<n;i++)
//     {
//         printf("%d ",arr[i]);
//      }
//      printf("\n");

//      printf("========Sorted Array======= \n");

//      for(i=0;i<n;i++)
//      {
//         low=i;
//         for(j=i;j<n;j++)
//         {
//             if(arr[j]<arr[low])
//             {
//                 low=j;
//             }
//         }
//         temp=arr[i];
//         arr[i]=arr[low];
//         arr[low]=temp;

//      }
//        printf("---------------:sorted Arry :---------------------------\n");
//      for(i=0;i<n;i++)
//     {
//         printf("%d ",arr[i]);
//      }
//      printf("\n");

// }

#include<stdio.h>  // Standard input-output header file

int main()   // Main function where program execution begins
{
    int arr[40], temp, i, j, n, low;  // Declare an array of size 40 and variables for loop and swapping

    printf("Enter Enter number of Elemnts to Be Sorted\n");  // Prompt user to enter number of elements
    scanf("%d", &n);  // Read the number of elements from user

    printf("Enter the %d Number of  Elements  :", n);  // Ask user to enter the elements
    for(i = 0; i < n; i++)   // Loop to read 'n' elements
    {
        scanf("%d", &arr[i]);  // Store each entered element in the array
    }

    printf("---------------:Unsorted Arry :---------------------------\n");  // Display message for unsorted array
    for(i = 0; i < n; i++)   // Loop to print unsorted array
    {
        printf("%d ", arr[i]);  // Print each element
    }
    printf("\n");  // New line

    printf("========Sorted Array======= \n");  // Message before sorting process

    // Selection Sort Algorithm starts
    for(i = 0; i < n; i++)   // Outer loop to move boundary of unsorted array
    {
        low = i;  // Assume the current index 'i' has the smallest element
        for(j = i; j < n; j++)   // Inner loop to find the smallest element in remaining array
        {
            if(arr[j] < arr[low])  // Compare current element with assumed minimum
            {
                low = j;  // Update index of smallest element
            }
        }
        temp = arr[i];       // Swap the smallest element with the first element of unsorted part
        arr[i] = arr[low];
        arr[low] = temp;
    }

    printf("---------------:sorted Arry :---------------------------\n");  // Display message for sorted array
    for(i = 0; i < n; i++)   // Loop to print sorted array
    {
        printf("%d ", arr[i]);  // Print each element
    }
    printf("\n");  // New line

}  // End of main function
