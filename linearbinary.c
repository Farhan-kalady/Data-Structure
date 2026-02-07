#include <stdio.h>
#include <stdlib.h>

// Linear Search
void linear(int arr[], int n, int x) { 
    int i, position = 0;
    for(i = 0; i < n; i++) {
        if(arr[i] == x) {
            printf("Element %d found @ Location %d\n", x, i+1);
            position = 1;
            break;
        } 
    }
    if(position == 0) {
        printf("Item %d not Found\n", x);
    }
}

// Binary Search (array must be sorted)
void binary(int arr[], int n, int x) {
    int mid, low = 0, high = n - 1, flag = 0;

    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == x) {
            printf("Item %d is found @ Location %d\n", x, mid+1);
            flag = 1;
            break;
        } 
        else if(arr[mid] < x) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    if(flag == 0) {
        printf("Item %d not Found\n", x);
    }
}

// Simple Bubble Sort for Binary Search
void sortArray(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[40], i, n, ch, x;

    printf("Enter the Number of Elements: ");
    scanf("%d", &n);

    printf("Enter the Elements: \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array for binary search
    sortArray(arr, n);

    while(1) {
        printf("\nEnter the Element to Search: ");
        scanf("%d", &x);
        printf("1. Linear Search \n");
        printf("2. Binary Search \n");
        printf("3. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                linear(arr, n, x);
                break;
            case 2:
                binary(arr, n, x);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
}