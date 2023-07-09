//quicksort
#include <stdio.h>
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start]; // Select the first element as the pivot
    int count = 0;
    
    // Count the number of elements smaller than or equal to the pivot
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count; // Final position of the pivot
    swap(&arr[pivotIndex], &arr[start]); // Place the pivot at its final position
    
    int i = start;
    int j = end;
    
    // Partition the array around the pivot
    while (i < pivotIndex && j > pivotIndex)  // Find the first element from the left greater than the pivot
    {                   
        while (arr[i] <= pivot) {
            i++;
        }
        
        // Find the first element from the right smaller than or equal to the pivot
        while (arr[j] > pivot) {
            j--;
        }
        
        // Swap the elements if they are on the wrong side of the pivot
        if (i < pivotIndex && j > pivotIndex) {
            swap(&arr[i++], &arr[j--]);
        }
    }
    
    return pivotIndex; // Return the final position of the pivot
}

void quickSort(int arr[], int start, int end) {
    if (start >= end)
        return; // Base case: array with 0 or 1 element is already sorted
    int p = partition(arr, start, end); // Partition the array
    quickSort(arr, start, p - 1); // Recursively sort the left subarray
    quickSort(arr, p + 1, end); // Recursively sort the right subarray
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 3, 4, 2, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
