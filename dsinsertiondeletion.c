#include <stdio.h>   // Standard input-output header file

int main() {
    int n, i, a[50], ch, pos, item;  
    // n = size of array
    // i = loop counter
    // a[50] = array with max 50 elements
    // ch = choice for menu
    // pos = position to insert/delete
    // item = element to be inserted

    printf("\nEnter the limit: ");  
    // Asking user for the number of elements in the array
    scanf("%d", &n);  

    printf("\nEnter the array elements: ");  
    // Input array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);  
        // Read each element into array
    }

    while (1) {   // Infinite loop so user can perform multiple operations until exit
        printf("\n\nThe array elements are:\n");
        for (i = 0; i < n; i++) {
            printf("%d\t", a[i]);  // Print array elements
        }
        printf("\n");

        // Menu for array operations
        printf("\nEnter your choice:\n1. Insert\n2. Delete\n3. Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {   // Switch case to handle different choices
            case 1:  // Insert operation
                if (n >= 50) {  
                    // Check if array is full
                    printf("Array is full, cannot insert!\n");
                    break;
                }
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);  // Input element to insert

                printf("Enter the position (1-%d): ", n + 1);
                scanf("%d", &pos);   // Input position to insert

                if (pos < 1 || pos > n + 1) {
                    // Validate position
                    printf("Invalid position!\n");
                    break;
                }

                // Shift elements to the right to make space
                for (i = n; i >= pos; i--) {
                    a[i] = a[i - 1];
                }

                a[pos - 1] = item;  // Insert element at position
                n++;                // Increase size of array
                printf("Element inserted successfully!\n");
                break;

            case 2:  // Delete operation
                if (n <= 0) {
                    // Check if array is empty
                    printf("Array is empty, cannot delete!\n");
                    break;
                }
                printf("Enter the position (1-%d) to be deleted: ", n);
                scanf("%d", &pos);  // Input position to delete

                if (pos < 1 || pos > n) {
                    // Validate position
                    printf("Invalid position!\n");
                    break;
                }

                // Shift elements left to overwrite the deleted element
                for (i = pos - 1; i < n - 1; i++) {
                    a[i] = a[i + 1];
                }

                n--;  // Decrease size of array
                printf("Element deleted successfully!\n");
                break;

            case 3:  // Exit option
                printf("Exiting program...\n");
                return 0;  // Terminate program

            default:  // Handle invalid choice
                printf("ERROR: Invalid choice\n");
        }
    }

    return 0;  // End of main function
}
