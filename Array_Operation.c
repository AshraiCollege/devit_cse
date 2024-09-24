#include <stdio.h>

#define MAX 100  // Maximum size of the array

// Function prototypes
void createArray(int arr[], int n);
void displayArray(int arr[], int n);
void insertElement(int arr[], int *n, int elem, int pos);
void deleteElement(int arr[], int *n, int pos);

int main() {
    int arr[MAX], n, choice, elem, pos;

    // Step a: Creating an Array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    createArray(arr, n);

    while (1) {
        // Menu for array operations
        printf("\nArray Operations Menu:\n");
        printf("1. Display Array Elements\n");
        printf("2. Insert an Element\n");
        printf("3. Delete an Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Step b: Display Array
                displayArray(arr, n);
                break;

            case 2:
                // Step c: Insert an Element
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                printf("Enter the position to insert the element (1 to %d): ", n + 1);
                scanf("%d", &pos);

                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                } else {
                    insertElement(arr, &n, elem, pos);
                    printf("Element inserted successfully.\n");
                }
                break;

            case 3:
                // Step d: Delete an Element
                printf("Enter the position of the element to delete (1 to %d): ", n);
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    deleteElement(arr, &n, pos);
                    printf("Element deleted successfully.\n");
                }
                break;

            case 4:
                // Exit the program
                return 0;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

// Function to create an array
void createArray(int arr[], int n) {
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to display the array elements
void displayArray(int arr[], int n) {
    printf("\nArray elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: %d\n", i + 1, arr[i]);
    }
}

// Function to insert an element at a given position
void insertElement(int arr[], int *n, int elem, int pos) {
    // Shift elements to the right to make space for the new element
    for (int i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = elem;
    (*n)++;
}

// Function to delete an element at a given position
void deleteElement(int arr[], int *n, int pos) {
    // Shift elements to the left to fill the gap
    for (int i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}
