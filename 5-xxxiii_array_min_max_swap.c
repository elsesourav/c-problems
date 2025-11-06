/*
 * QUESTION xxxiii:
 * Write a C program to interchange the biggest and smallest number
 * in a one dimensional array using function.
 *
 * PROGRAM DESCRIPTION:
 * This program finds the largest and smallest elements in an array
 * and swaps their positions. For example:
 * - Array: [5, 2, 9, 1, 7]
 * - Smallest: 1 (at index 3), Largest: 9 (at index 2)
 * - After swap: [5, 2, 1, 9, 7]
 *
 * The program uses separate functions to:
 * 1. Find the index of the smallest element
 * 2. Find the index of the largest element
 * 3. Swap elements at two positions
 * 4. Display the array
 *
 * HOW TO SOLVE:
 * 1. Input array size and elements
 * 2. Create function to find minimum element's index
 * 3. Create function to find maximum element's index
 * 4. Create function to swap two elements
 * 5. Display array before swap
 * 6. Find positions of min and max
 * 7. Swap the elements at those positions
 * 8. Display array after swap
 * 9. Handle edge cases (all same elements, two elements, etc.)
 */

#include <stdio.h>

// Function to display array
void displayArray(int arr[], int size) {
   printf("[");
   for (int i = 0; i < size; i++) {
      printf("%d", arr[i]);
      if (i < size - 1) {
         printf(", ");
      }
   }
   printf("]\n");
}

// Function to find index of smallest element
int findMinIndex(int arr[], int size) {
   int minIndex = 0;
   for (int i = 1; i < size; i++) {
      if (arr[i] < arr[minIndex]) {
         minIndex = i;
      }
   }
   return minIndex;
}

// Function to find index of largest element
int findMaxIndex(int arr[], int size) {
   int maxIndex = 0;
   for (int i = 1; i < size; i++) {
      if (arr[i] > arr[maxIndex]) {
         maxIndex = i;
      }
   }
   return maxIndex;
}

// Function to swap two elements in array
void swap(int arr[], int index1, int index2) {
   int temp = arr[index1];
   arr[index1] = arr[index2];
   arr[index2] = temp;
}

// Function to interchange min and max
void interchangeMinMax(int arr[], int size) {
   int minIndex = findMinIndex(arr, size);
   int maxIndex = findMaxIndex(arr, size);

   printf("\n--- Finding Min and Max ---\n");
   printf("Smallest element: %d at index %d\n", arr[minIndex], minIndex);
   printf("Largest element:  %d at index %d\n", arr[maxIndex], maxIndex);

   if (minIndex == maxIndex) {
      printf("\nNote: All elements are the same. No swap needed.\n");
      return;
   }

   printf("\n--- Swapping ---\n");
   printf("Swapping arr[%d] = %d with arr[%d] = %d\n",
          minIndex, arr[minIndex], maxIndex, arr[maxIndex]);

   swap(arr, minIndex, maxIndex);

   printf("Swap completed successfully!\n");
}

int main() {
   int size;
   int arr[100];

   printf("========================================\n");
   printf("  Min-Max Interchange in Array\n");
   printf("========================================\n\n");

   printf("This program swaps the positions of\n");
   printf("the smallest and largest elements\n");
   printf("in an array.\n\n");

   // Input array size
   printf("Enter the size of array: ");
   scanf("%d", &size);

   if (size <= 0 || size > 100) {
      printf("Error: Size must be between 1 and 100\n");
      return 1;
   }

   // Input array elements
   printf("Enter %d elements:\n", size);
   for (int i = 0; i < size; i++) {
      printf("Element [%d]: ", i);
      scanf("%d", &arr[i]);
   }

   printf("\n========================================\n");
   printf("  Array Before Swap\n");
   printf("========================================\n\n");

   printf("Array: ");
   displayArray(arr, size);

   // Display array with indices
   printf("\nIndex: ");
   for (int i = 0; i < size; i++) {
      printf("%3d ", i);
   }
   printf("\nValue: ");
   for (int i = 0; i < size; i++) {
      printf("%3d ", arr[i]);
   }
   printf("\n");

   // Perform interchange
   interchangeMinMax(arr, size);

   printf("\n========================================\n");
   printf("  Array After Swap\n");
   printf("========================================\n\n");

   printf("Array: ");
   displayArray(arr, size);

   // Display array with indices
   printf("\nIndex: ");
   for (int i = 0; i < size; i++) {
      printf("%3d ", i);
   }
   printf("\nValue: ");
   for (int i = 0; i < size; i++) {
      printf("%3d ", arr[i]);
   }
   printf("\n");

   // Summary
   printf("\n========================================\n");
   printf("  Summary\n");
   printf("========================================\n");
   printf("Operation: Interchange min and max\n");
   printf("Array size: %d elements\n");
   printf("Result: Successfully swapped!\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Size: 5
 *   Elements: 5, 2, 9, 1, 7
 * Output:
 * ========================================
 *   Min-Max Interchange in Array
 * ========================================
 *
 * This program swaps the positions of
 * the smallest and largest elements
 * in an array.
 *
 * Enter the size of array: 5
 * Enter 5 elements:
 * Element [0]: 5
 * Element [1]: 2
 * Element [2]: 9
 * Element [3]: 1
 * Element [4]: 7
 *
 * ========================================
 *   Array Before Swap
 * ========================================
 *
 * Array: [5, 2, 9, 1, 7]
 *
 * Index:   0   1   2   3   4
 * Value:   5   2   9   1   7
 *
 * --- Finding Min and Max ---
 * Smallest element: 1 at index 3
 * Largest element:  9 at index 2
 *
 * --- Swapping ---
 * Swapping arr[3] = 1 with arr[2] = 9
 * Swap completed successfully!
 *
 * ========================================
 *   Array After Swap
 * ========================================
 *
 * Array: [5, 2, 1, 9, 7]
 *
 * Index:   0   1   2   3   4
 * Value:   5   2   1   9   7
 *
 * ========================================
 *   Summary
 * ========================================
 * Operation: Interchange min and max
 * Array size: 5 elements
 * Result: Successfully swapped!
 * ========================================
 *
 * Example 2:
 * Input:
 *   Size: 7
 *   Elements: 10, 45, 23, 67, 12, 89, 34
 * Output:
 * ========================================
 *   Min-Max Interchange in Array
 * ========================================
 *
 * This program swaps the positions of
 * the smallest and largest elements
 * in an array.
 *
 * Enter the size of array: 7
 * Enter 7 elements:
 * Element [0]: 10
 * Element [1]: 45
 * Element [2]: 23
 * Element [3]: 67
 * Element [4]: 12
 * Element [5]: 89
 * Element [6]: 34
 *
 * ========================================
 *   Array Before Swap
 * ========================================
 *
 * Array: [10, 45, 23, 67, 12, 89, 34]
 *
 * Index:   0   1   2   3   4   5   6
 * Value:  10  45  23  67  12  89  34
 *
 * --- Finding Min and Max ---
 * Smallest element: 10 at index 0
 * Largest element:  89 at index 5
 *
 * --- Swapping ---
 * Swapping arr[0] = 10 with arr[5] = 89
 * Swap completed successfully!
 *
 * ========================================
 *   Array After Swap
 * ========================================
 *
 * Array: [89, 45, 23, 67, 12, 10, 34]
 *
 * Index:   0   1   2   3   4   5   6
 * Value:  89  45  23  67  12  10  34
 *
 * ========================================
 *   Summary
 * ========================================
 * Operation: Interchange min and max
 * Array size: 7 elements
 * Result: Successfully swapped!
 * ========================================
 *
 * Example 3:
 * Input:
 *   Size: 4
 *   Elements: 5, 5, 5, 5
 * Output:
 * ========================================
 *   Min-Max Interchange in Array
 * ========================================
 *
 * This program swaps the positions of
 * the smallest and largest elements
 * in an array.
 *
 * Enter the size of array: 4
 * Enter 4 elements:
 * Element [0]: 5
 * Element [1]: 5
 * Element [2]: 5
 * Element [3]: 5
 *
 * ========================================
 *   Array Before Swap
 * ========================================
 *
 * Array: [5, 5, 5, 5]
 *
 * Index:   0   1   2   3
 * Value:   5   5   5   5
 *
 * --- Finding Min and Max ---
 * Smallest element: 5 at index 0
 * Largest element:  5 at index 0
 *
 * Note: All elements are the same. No swap needed.
 *
 * ========================================
 *   Array After Swap
 * ========================================
 *
 * Array: [5, 5, 5, 5]
 *
 * Index:   0   1   2   3
 * Value:   5   5   5   5
 *
 * ========================================
 *   Summary
 * ========================================
 * Operation: Interchange min and max
 * Array size: 4 elements
 * Result: Successfully swapped!
 * ========================================
 */
