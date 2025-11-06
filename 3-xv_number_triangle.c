/*
 * QUESTION xv:
 * Write a C program to generate a simple number triangle for n rows.
 *
 * PROGRAM DESCRIPTION:
 * This program generates various patterns of number triangles for n rows.
 * Different patterns include:
 * 1. Right-angled triangle with sequential numbers
 * 2. Right-angled triangle with row numbers
 * 3. Pyramid (centered) triangle
 * 4. Inverted triangles
 * Each pattern demonstrates nested loops and spacing control.
 *
 * HOW TO SOLVE:
 * 1. Input the number of rows (n) from the user
 * 2. Use nested loops:
 *    - Outer loop: Controls rows (i from 1 to n)
 *    - Inner loop: Controls numbers in each row
 * 3. For right-angled triangle:
 *    - Row 1: Print 1 number
 *    - Row 2: Print 2 numbers
 *    - Row i: Print i numbers
 * 4. For pyramid triangle:
 *    - Add spaces before numbers for centering
 *    - Spaces = n - i for row i
 * 5. Number patterns can be:
 *    - Sequential: 1, 2, 3, 4, 5...
 *    - Row-wise: Each row prints same number
 *    - Column-wise: Print column number in each position
 */

#include <stdio.h>

int main() {
   int n, i, j, num, spaces;

   // Input number of rows
   printf("Enter the number of rows: ");
   scanf("%d", &n);

   if (n <= 0) {
      printf("Error: Number of rows must be positive!\n");
      return 1;
   }

   printf("\n========================================\n");
   printf("  Number Triangle Patterns (n = %d)\n", n);
   printf("========================================\n\n");

   // Pattern 1: Right-angled triangle with sequential numbers
   printf("--- Pattern 1: Sequential Numbers ---\n");
   num = 1;
   for (i = 1; i <= n; i++) {
      for (j = 1; j <= i; j++) {
         printf("%d ", num++);
      }
      printf("\n");
   }

   // Pattern 2: Right-angled triangle with row numbers
   printf("\n--- Pattern 2: Row Numbers ---\n");
   for (i = 1; i <= n; i++) {
      for (j = 1; j <= i; j++) {
         printf("%d ", i);
      }
      printf("\n");
   }

   // Pattern 3: Right-angled triangle with column numbers
   printf("\n--- Pattern 3: Column Numbers ---\n");
   for (i = 1; i <= n; i++) {
      for (j = 1; j <= i; j++) {
         printf("%d ", j);
      }
      printf("\n");
   }

   // Pattern 4: Pyramid (centered) triangle
   printf("\n--- Pattern 4: Centered Pyramid ---\n");
   for (i = 1; i <= n; i++) {
      // Print leading spaces
      for (spaces = 1; spaces <= n - i; spaces++) {
         printf("  ");
      }
      // Print numbers
      for (j = 1; j <= i; j++) {
         printf("%d ", j);
      }
      // Print reverse numbers
      for (j = i - 1; j >= 1; j--) {
         printf("%d ", j);
      }
      printf("\n");
   }

   // Pattern 5: Inverted right-angled triangle
   printf("\n--- Pattern 5: Inverted Triangle ---\n");
   for (i = n; i >= 1; i--) {
      for (j = 1; j <= i; j++) {
         printf("%d ", j);
      }
      printf("\n");
   }

   // Pattern 6: Floyd's Triangle
   printf("\n--- Pattern 6: Floyd's Triangle ---\n");
   num = 1;
   for (i = 1; i <= n; i++) {
      for (j = 1; j <= i; j++) {
         printf("%-4d", num++);
      }
      printf("\n");
   }

   printf("\n========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: n = 5
 * Output:
 * ========================================
 *   Number Triangle Patterns (n = 5)
 * ========================================
 *
 * --- Pattern 1: Sequential Numbers ---
 * 1
 * 2 3
 * 4 5 6
 * 7 8 9 10
 * 11 12 13 14 15
 *
 * --- Pattern 2: Row Numbers ---
 * 1
 * 2 2
 * 3 3 3
 * 4 4 4 4
 * 5 5 5 5 5
 *
 * --- Pattern 3: Column Numbers ---
 * 1
 * 1 2
 * 1 2 3
 * 1 2 3 4
 * 1 2 3 4 5
 *
 * --- Pattern 4: Centered Pyramid ---
 *         1
 *       1 2 1
 *     1 2 3 2 1
 *   1 2 3 4 3 2 1
 * 1 2 3 4 5 4 3 2 1
 *
 * --- Pattern 5: Inverted Triangle ---
 * 1 2 3 4 5
 * 1 2 3 4
 * 1 2 3
 * 1 2
 * 1
 *
 * --- Pattern 6: Floyd's Triangle ---
 * 1
 * 2   3
 * 4   5   6
 * 7   8   9   10
 * 11  12  13  14  15
 *
 * ========================================
 *
 * Example 2:
 * Input: n = 3
 * Output:
 * ========================================
 *   Number Triangle Patterns (n = 3)
 * ========================================
 *
 * --- Pattern 1: Sequential Numbers ---
 * 1
 * 2 3
 * 4 5 6
 *
 * --- Pattern 2: Row Numbers ---
 * 1
 * 2 2
 * 3 3 3
 *
 * --- Pattern 3: Column Numbers ---
 * 1
 * 1 2
 * 1 2 3
 *
 * --- Pattern 4: Centered Pyramid ---
 *     1
 *   1 2 1
 * 1 2 3 2 1
 *
 * --- Pattern 5: Inverted Triangle ---
 * 1 2 3
 * 1 2
 * 1
 *
 * --- Pattern 6: Floyd's Triangle ---
 * 1
 * 2   3
 * 4   5   6
 *
 * ========================================
 *
 * Example 3:
 * Input: n = 4
 * Output:
 * ========================================
 *   Number Triangle Patterns (n = 4)
 * ========================================
 *
 * --- Pattern 1: Sequential Numbers ---
 * 1
 * 2 3
 * 4 5 6
 * 7 8 9 10
 *
 * --- Pattern 2: Row Numbers ---
 * 1
 * 2 2
 * 3 3 3
 * 4 4 4 4
 *
 * --- Pattern 3: Column Numbers ---
 * 1
 * 1 2
 * 1 2 3
 * 1 2 3 4
 *
 * --- Pattern 4: Centered Pyramid ---
 *       1
 *     1 2 1
 *   1 2 3 2 1
 * 1 2 3 4 3 2 1
 *
 * --- Pattern 5: Inverted Triangle ---
 * 1 2 3 4
 * 1 2 3
 * 1 2
 * 1
 *
 * --- Pattern 6: Floyd's Triangle ---
 * 1
 * 2   3
 * 4   5   6
 * 7   8   9   10
 *
 * ========================================
 */
