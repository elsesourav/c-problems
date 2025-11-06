/*
 * QUESTION xxii:
 * Write a C program to sort array elements in ascending and descending order.
 *
 * PROGRAM DESCRIPTION:
 * This program sorts an array of numbers in both ascending (smallest to largest)
 * and descending (largest to smallest) order. Multiple sorting algorithms are
 * demonstrated including Bubble Sort and Selection Sort.
 *
 * Sorting algorithms used:
 * - Bubble Sort: Compare adjacent elements and swap if needed
 * - Selection Sort: Find minimum/maximum and place in correct position
 *
 * HOW TO SOLVE:
 * 1. Input array size and elements
 * 2. For Bubble Sort (Ascending):
 *    - Outer loop: n-1 passes
 *    - Inner loop: Compare adjacent elements
 *    - If arr[j] > arr[j+1], swap them
 *    - After each pass, largest element moves to end
 * 3. For Bubble Sort (Descending):
 *    - Same logic but swap if arr[j] < arr[j+1]
 * 4. For Selection Sort:
 *    - Find minimum (or maximum) from unsorted portion
 *    - Swap with first element of unsorted portion
 * 5. Display original, ascending, and descending arrays
 */

#include <stdio.h>
#include <string.h>

// Function to display array
void displayArray(int arr[], int n, char *label) {
   printf("%s: [ ", label);
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("]\n");
}

// Function to copy array
void copyArray(int source[], int dest[], int n) {
   for (int i = 0; i < n; i++) {
      dest[i] = source[i];
   }
}

// Bubble Sort - Ascending
void bubbleSortAscending(int arr[], int n) {
   int i, j, temp;
   for (i = 0; i < n - 1; i++) {
      for (j = 0; j < n - i - 1; j++) {
         if (arr[j] > arr[j + 1]) {
            // Swap
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

// Bubble Sort - Descending
void bubbleSortDescending(int arr[], int n) {
   int i, j, temp;
   for (i = 0; i < n - 1; i++) {
      for (j = 0; j < n - i - 1; j++) {
         if (arr[j] < arr[j + 1]) {
            // Swap
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

// Selection Sort - Ascending
void selectionSortAscending(int arr[], int n) {
   int i, j, minIdx, temp;
   for (i = 0; i < n - 1; i++) {
      minIdx = i;
      for (j = i + 1; j < n; j++) {
         if (arr[j] < arr[minIdx]) {
            minIdx = j;
         }
      }
      // Swap minimum element with first element
      temp = arr[minIdx];
      arr[minIdx] = arr[i];
      arr[i] = temp;
   }
}

// Selection Sort - Descending
void selectionSortDescending(int arr[], int n) {
   int i, j, maxIdx, temp;
   for (i = 0; i < n - 1; i++) {
      maxIdx = i;
      for (j = i + 1; j < n; j++) {
         if (arr[j] > arr[maxIdx]) {
            maxIdx = j;
         }
      }
      // Swap maximum element with first element
      temp = arr[maxIdx];
      arr[maxIdx] = arr[i];
      arr[i] = temp;
   }
}

int main() {
   int n, i, choice;

   // Input array size
   printf("Enter the number of elements: ");
   scanf("%d", &n);

   if (n <= 0) {
      printf("Error: Array size must be positive!\n");
      return 1;
   }

   int arr[n], tempArr[n];

   // Input array elements
   printf("Enter %d elements:\n", n);
   for (i = 0; i < n; i++) {
      printf("Element %d: ", i + 1);
      scanf("%d", &arr[i]);
   }

   printf("\n========================================\n");
   printf("  Array Sorting Program\n");
   printf("========================================\n\n");

   displayArray(arr, n, "Original Array");

   // Bubble Sort - Ascending
   printf("\n--- Method 1: Bubble Sort ---\n\n");
   copyArray(arr, tempArr, n);
   bubbleSortAscending(tempArr, n);
   displayArray(tempArr, n, "Ascending Order ");

   copyArray(arr, tempArr, n);
   bubbleSortDescending(tempArr, n);
   displayArray(tempArr, n, "Descending Order");

   // Selection Sort
   printf("\n--- Method 2: Selection Sort ---\n\n");
   copyArray(arr, tempArr, n);
   selectionSortAscending(tempArr, n);
   displayArray(tempArr, n, "Ascending Order ");

   copyArray(arr, tempArr, n);
   selectionSortDescending(tempArr, n);
   displayArray(tempArr, n, "Descending Order");

   // Interactive sorting
   printf("\n--- Interactive Sorting ---\n");
   printf("Choose sorting order:\n");
   printf("1. Ascending Order\n");
   printf("2. Descending Order\n");
   printf("Enter choice (1 or 2): ");
   scanf("%d", &choice);

   printf("\n");
   if (choice == 1) {
      bubbleSortAscending(arr, n);
      displayArray(arr, n, "Sorted (Ascending)");
   } else if (choice == 2) {
      bubbleSortDescending(arr, n);
      displayArray(arr, n, "Sorted (Descending)");
   } else {
      printf("Invalid choice!\n");
   }

   printf("\n========================================\n");
   printf("Sorting Algorithm Information:\n");
   printf("========================================\n");
   printf("Bubble Sort:\n");
   printf("  - Time Complexity: O(n²)\n");
   printf("  - Space Complexity: O(1)\n");
   printf("  - Stable: Yes\n\n");
   printf("Selection Sort:\n");
   printf("  - Time Complexity: O(n²)\n");
   printf("  - Space Complexity: O(1)\n");
   printf("  - Stable: No\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Number of elements: 6
 *   Elements: 64, 34, 25, 12, 22, 11
 *   Choice: 1
 * Output:
 * ========================================
 *   Array Sorting Program
 * ========================================
 *
 * Original Array: [ 64 34 25 12 22 11 ]
 *
 * --- Method 1: Bubble Sort ---
 *
 * Ascending Order : [ 11 12 22 25 34 64 ]
 * Descending Order: [ 64 34 25 22 12 11 ]
 *
 * --- Method 2: Selection Sort ---
 *
 * Ascending Order : [ 11 12 22 25 34 64 ]
 * Descending Order: [ 64 34 25 22 12 11 ]
 *
 * --- Interactive Sorting ---
 * Choose sorting order:
 * 1. Ascending Order
 * 2. Descending Order
 * Enter choice (1 or 2): 1
 *
 * Sorted (Ascending): [ 11 12 22 25 34 64 ]
 *
 * ========================================
 * Sorting Algorithm Information:
 * ========================================
 * Bubble Sort:
 *   - Time Complexity: O(n²)
 *   - Space Complexity: O(1)
 *   - Stable: Yes
 *
 * Selection Sort:
 *   - Time Complexity: O(n²)
 *   - Space Complexity: O(1)
 *   - Stable: No
 * ========================================
 *
 * Example 2:
 * Input:
 *   Number of elements: 5
 *   Elements: 5, 2, 8, 1, 9
 *   Choice: 2
 * Output:
 * ========================================
 *   Array Sorting Program
 * ========================================
 *
 * Original Array: [ 5 2 8 1 9 ]
 *
 * --- Method 1: Bubble Sort ---
 *
 * Ascending Order : [ 1 2 5 8 9 ]
 * Descending Order: [ 9 8 5 2 1 ]
 *
 * --- Method 2: Selection Sort ---
 *
 * Ascending Order : [ 1 2 5 8 9 ]
 * Descending Order: [ 9 8 5 2 1 ]
 *
 * --- Interactive Sorting ---
 * Choose sorting order:
 * 1. Ascending Order
 * 2. Descending Order
 * Enter choice (1 or 2): 2
 *
 * Sorted (Descending): [ 9 8 5 2 1 ]
 *
 * ========================================
 * Sorting Algorithm Information:
 * ========================================
 * Bubble Sort:
 *   - Time Complexity: O(n²)
 *   - Space Complexity: O(1)
 *   - Stable: Yes
 *
 * Selection Sort:
 *   - Time Complexity: O(n²)
 *   - Space Complexity: O(1)
 *   - Stable: No
 * ========================================
 *
 * Example 3:
 * Input:
 *   Number of elements: 4
 *   Elements: 100, 50, 75, 25
 *   Choice: 1
 * Output:
 * ========================================
 *   Array Sorting Program
 * ========================================
 *
 * Original Array: [ 100 50 75 25 ]
 *
 * --- Method 1: Bubble Sort ---
 *
 * Ascending Order : [ 25 50 75 100 ]
 * Descending Order: [ 100 75 50 25 ]
 *
 * --- Method 2: Selection Sort ---
 *
 * Ascending Order : [ 25 50 75 100 ]
 * Descending Order: [ 100 75 50 25 ]
 *
 * --- Interactive Sorting ---
 * Choose sorting order:
 * 1. Ascending Order
 * 2. Descending Order
 * Enter choice (1 or 2): 1
 *
 * Sorted (Ascending): [ 25 50 75 100 ]
 *
 * ========================================
 * Sorting Algorithm Information:
 * ========================================
 * Bubble Sort:
 *   - Time Complexity: O(n²)
 *   - Space Complexity: O(1)
 *   - Stable: Yes
 *
 * Selection Sort:
 *   - Time Complexity: O(n²)
 *   - Space Complexity: O(1)
 *   - Stable: No
 * ========================================
 */
