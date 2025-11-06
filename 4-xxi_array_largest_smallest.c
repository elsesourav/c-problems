/*
 * QUESTION xxi:
 * Write a C program to find the largest and smallest numbers from array elements.
 *
 * PROGRAM DESCRIPTION:
 * This program takes an array of numbers as input and finds both the
 * largest (maximum) and smallest (minimum) elements from the array.
 * It also displays the positions (indices) where these elements are found.
 *
 * HOW TO SOLVE:
 * 1. Declare an array and input the size from user
 * 2. Read array elements from the user
 * 3. Initialize largest and smallest with first element:
 *    - largest = arr[0]
 *    - smallest = arr[0]
 * 4. Loop through array from index 1 to n-1:
 *    - If arr[i] > largest, update largest = arr[i]
 *    - If arr[i] < smallest, update smallest = arr[i]
 * 5. Keep track of positions (indices) as well
 * 6. Display the results with positions
 * 7. Show additional statistics like difference, range, etc.
 */

#include <stdio.h>

int main() {
   int n, i;
   int largest, smallest;
   int largestPos, smallestPos;

   // Input array size
   printf("Enter the number of elements in array: ");
   scanf("%d", &n);

   if (n <= 0) {
      printf("Error: Array size must be positive!\n");
      return 1;
   }

   int arr[n];

   // Input array elements
   printf("Enter %d elements:\n", n);
   for (i = 0; i < n; i++) {
      printf("Element %d: ", i + 1);
      scanf("%d", &arr[i]);
   }

   // Initialize with first element
   largest = smallest = arr[0];
   largestPos = smallestPos = 0;

   // Find largest and smallest
   for (i = 1; i < n; i++) {
      if (arr[i] > largest) {
         largest = arr[i];
         largestPos = i;
      }
      if (arr[i] < smallest) {
         smallest = arr[i];
         smallestPos = i;
      }
   }

   // Display results
   printf("\n========================================\n");
   printf("  Array Analysis\n");
   printf("========================================\n\n");

   printf("Array elements: [ ");
   for (i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("]\n\n");

   printf("--- Results ---\n");
   printf("Largest element:   %d (at position %d, index %d)\n",
          largest, largestPos + 1, largestPos);
   printf("Smallest element:  %d (at position %d, index %d)\n",
          smallest, smallestPos + 1, smallestPos);

   printf("\n--- Statistics ---\n");
   printf("Array size:        %d\n", n);
   printf("Range:             %d (largest - smallest)\n", largest - smallest);
   printf("Sum of extremes:   %d (largest + smallest)\n", largest + smallest);

   // Count occurrences
   int largestCount = 0, smallestCount = 0;
   printf("\n--- Occurrences ---\n");
   printf("Largest (%d) appears at: ", largest);
   for (i = 0; i < n; i++) {
      if (arr[i] == largest) {
         printf("%d ", i);
         largestCount++;
      }
   }
   printf("(%d time%s)\n", largestCount, largestCount > 1 ? "s" : "");

   printf("Smallest (%d) appears at: ", smallest);
   for (i = 0; i < n; i++) {
      if (arr[i] == smallest) {
         printf("%d ", i);
         smallestCount++;
      }
   }
   printf("(%d time%s)\n", smallestCount, smallestCount > 1 ? "s" : "");

   printf("\n========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Number of elements: 7
 *   Elements: 45, 12, 78, 23, 9, 56, 34
 * Output:
 * ========================================
 *   Array Analysis
 * ========================================
 *
 * Array elements: [ 45 12 78 23 9 56 34 ]
 *
 * --- Results ---
 * Largest element:   78 (at position 3, index 2)
 * Smallest element:  9 (at position 5, index 4)
 *
 * --- Statistics ---
 * Array size:        7
 * Range:             69 (largest - smallest)
 * Sum of extremes:   87 (largest + smallest)
 *
 * --- Occurrences ---
 * Largest (78) appears at: 2 (1 time)
 * Smallest (9) appears at: 4 (1 time)
 *
 * ========================================
 *
 * Example 2:
 * Input:
 *   Number of elements: 5
 *   Elements: 100, 50, 100, 25, 50
 * Output:
 * ========================================
 *   Array Analysis
 * ========================================
 *
 * Array elements: [ 100 50 100 25 50 ]
 *
 * --- Results ---
 * Largest element:   100 (at position 1, index 0)
 * Smallest element:  25 (at position 4, index 3)
 *
 * --- Statistics ---
 * Array size:        5
 * Range:             75 (largest - smallest)
 * Sum of extremes:   125 (largest + smallest)
 *
 * --- Occurrences ---
 * Largest (100) appears at: 0 2 (2 times)
 * Smallest (25) appears at: 3 (1 time)
 *
 * ========================================
 *
 * Example 3:
 * Input:
 *   Number of elements: 4
 *   Elements: -10, -5, -20, -3
 * Output:
 * ========================================
 *   Array Analysis
 * ========================================
 *
 * Array elements: [ -10 -5 -20 -3 ]
 *
 * --- Results ---
 * Largest element:   -3 (at position 4, index 3)
 * Smallest element:  -20 (at position 3, index 2)
 *
 * --- Statistics ---
 * Array size:        4
 * Range:             17 (largest - smallest)
 * Sum of extremes:   -23 (largest + smallest)
 *
 * --- Occurrences ---
 * Largest (-3) appears at: 3 (1 time)
 * Smallest (-20) appears at: 2 (1 time)
 *
 * ========================================
 */
