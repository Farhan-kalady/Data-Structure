#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j,temp,arr[50];
    printf("Enter the Number of Elements to Be inserted :\n");
    scanf("%d",&n);
    printf("Enter the elements :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
     }
     printf("---------------:Unsorted Arry :---------------------------\n");
     for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
     }

    printf("\n");

     printf("========Sorted Array======= \n");
     for(i=0;i<n;i++)
     {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
     {
        printf("%d ",arr[i]);
     }
     return 0;
}

// #include<stdio.h>   // Standard input-output header file
// #include<stdlib.h>  // Standard library header (not needed here, but okay to include)

// int main(){
//     int n,i,j,temp,arr[50]; // n = number of elements, i/j = loop counters, temp = for swapping, arr[] = array
    
//     // Step 1: Input size of array
//     printf("Enter the Number of Elements to Be inserted :\n");
//     scanf("%d",&n);

//     // Step 2: Input array elements
//     printf("Enter the elements :\n");
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&arr[i]);
//     }

//     // Step 3: Print unsorted array
//     printf("---------------:Unsorted Array :---------------------------\n");
//     for(i=0;i<n;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     printf("\n");

//     // Step 4: Bubble Sort Algorithm
//     // Outer loop runs n times
//     for(i=0;i<n;i++)
//     {
//         // Inner loop runs till (n-i-1) because last i elements are already sorted
//         for(j=0;j<n-i-1;j++)
//         {
//             // If current element is greater than next element, swap them
//             if(arr[j]>arr[j+1])
//             {
//                 temp=arr[j];         // Store arr[j] in temp
//                 arr[j]=arr[j+1];     // Assign next element to current
//                 arr[j+1]=temp;       // Put temp in the next element
//             }
//         }
//     }

//     // Step 5: Print sorted array
//     printf("========Sorted Array======= \n");
//     for(i=0;i<n;i++)
//     {
//         printf("%d ",arr[i]);
//     }

//     return 0; // Successful program termination
// }
