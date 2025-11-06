/*
 * QUESTION xxiii:
 * Write a C program to enter elements for a 3×3 matrix and display them.
 *
 * PROGRAM DESCRIPTION:
 * This program creates a 3×3 matrix (2-dimensional array) and allows the
 * user to enter values for each element. The matrix is then displayed in
 * a proper matrix format with rows and columns aligned.
 *
 * A 3×3 matrix looks like:
 *     [ a11  a12  a13 ]
 *     [ a21  a22  a23 ]
 *     [ a31  a32  a33 ]
 *
 * HOW TO SOLVE:
 * 1. Declare a 2D array of size 3×3: int matrix[3][3]
 * 2. Use nested loops to input elements:
 *    - Outer loop: row index (i from 0 to 2)
 *    - Inner loop: column index (j from 0 to 2)
 *    - Input matrix[i][j]
 * 3. Use nested loops to display elements:
 *    - Outer loop: iterate through rows
 *    - Inner loop: iterate through columns in that row
 *    - Print each element with proper formatting
 * 4. Add formatting for better visual representation
 * 5. Show additional information like diagonal elements, sum, etc.
 */

#include <stdio.h>

int main() {
   int matrix[3][3];
   int i, j;
   int sum = 0;

   printf("========================================\n");
   printf("  3×3 Matrix Input and Display\n");
   printf("========================================\n\n");

   // Input matrix elements
   printf("Enter elements for 3×3 matrix:\n");
   printf("(Enter 9 values - row by row)\n\n");

   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         printf("Element [%d][%d]: ", i, j);
         scanf("%d", &matrix[i][j]);
         sum += matrix[i][j];
      }
   }

   // Display matrix
   printf("\n========================================\n");
   printf("  Matrix Display\n");
   printf("========================================\n\n");

   printf("The 3×3 Matrix is:\n\n");
   for (i = 0; i < 3; i++) {
      printf("    [ ");
      for (j = 0; j < 3; j++) {
         printf("%4d ", matrix[i][j]);
      }
      printf("]\n");
   }

   // Display in different formats
   printf("\n--- Alternative Display Format ---\n\n");
   for (i = 0; i < 3; i++) {
      printf("    | ");
      for (j = 0; j < 3; j++) {
         printf("%4d ", matrix[i][j]);
      }
      printf("|\n");
   }

   // Display matrix information
   printf("\n========================================\n");
   printf("  Matrix Information\n");
   printf("========================================\n");
   printf("Matrix Size:         3×3\n");
   printf("Total Elements:      9\n");
   printf("Sum of all elements: %d\n\n", sum);

   // Display diagonal elements
   printf("--- Diagonal Elements ---\n");
   printf("Principal Diagonal:  ");
   for (i = 0; i < 3; i++) {
      printf("%d ", matrix[i][i]);
   }
   printf("\n");

   printf("Secondary Diagonal:  ");
   for (i = 0; i < 3; i++) {
      printf("%d ", matrix[i][2 - i]);
   }
   printf("\n\n");

   // Display row-wise sum
   printf("--- Row-wise Sum ---\n");
   for (i = 0; i < 3; i++) {
      int rowSum = 0;
      for (j = 0; j < 3; j++) {
         rowSum += matrix[i][j];
      }
      printf("Row %d: %d\n", i, rowSum);
   }
   printf("\n");

   // Display column-wise sum
   printf("--- Column-wise Sum ---\n");
   for (j = 0; j < 3; j++) {
      int colSum = 0;
      for (i = 0; i < 3; i++) {
         colSum += matrix[i][j];
      }
      printf("Column %d: %d\n", j, colSum);
   }

   printf("\n========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Elements: 1, 2, 3, 4, 5, 6, 7, 8, 9
 * Output:
 * ========================================
 *   3×3 Matrix Input and Display
 * ========================================
 *
 * Enter elements for 3×3 matrix:
 * (Enter 9 values - row by row)
 *
 * Element [0][0]: 1
 * Element [0][1]: 2
 * Element [0][2]: 3
 * Element [1][0]: 4
 * Element [1][1]: 5
 * Element [1][2]: 6
 * Element [2][0]: 7
 * Element [2][1]: 8
 * Element [2][2]: 9
 *
 * ========================================
 *   Matrix Display
 * ========================================
 *
 * The 3×3 Matrix is:
 *
 *     [    1    2    3 ]
 *     [    4    5    6 ]
 *     [    7    8    9 ]
 *
 * --- Alternative Display Format ---
 *
 *     |    1    2    3 |
 *     |    4    5    6 |
 *     |    7    8    9 |
 *
 * ========================================
 *   Matrix Information
 * ========================================
 * Matrix Size:         3×3
 * Total Elements:      9
 * Sum of all elements: 45
 *
 * --- Diagonal Elements ---
 * Principal Diagonal:  1 5 9
 * Secondary Diagonal:  3 5 7
 *
 * --- Row-wise Sum ---
 * Row 0: 6
 * Row 1: 15
 * Row 2: 24
 *
 * --- Column-wise Sum ---
 * Column 0: 12
 * Column 1: 15
 * Column 2: 18
 *
 * ========================================
 *
 * Example 2:
 * Input:
 *   Elements: 10, 20, 30, 40, 50, 60, 70, 80, 90
 * Output:
 * ========================================
 *   3×3 Matrix Input and Display
 * ========================================
 *
 * Enter elements for 3×3 matrix:
 * (Enter 9 values - row by row)
 *
 * Element [0][0]: 10
 * Element [0][1]: 20
 * Element [0][2]: 30
 * Element [1][0]: 40
 * Element [1][1]: 50
 * Element [1][2]: 60
 * Element [2][0]: 70
 * Element [2][1]: 80
 * Element [2][2]: 90
 *
 * ========================================
 *   Matrix Display
 * ========================================
 *
 * The 3×3 Matrix is:
 *
 *     [   10   20   30 ]
 *     [   40   50   60 ]
 *     [   70   80   90 ]
 *
 * --- Alternative Display Format ---
 *
 *     |   10   20   30 |
 *     |   40   50   60 |
 *     |   70   80   90 |
 *
 * ========================================
 *   Matrix Information
 * ========================================
 * Matrix Size:         3×3
 * Total Elements:      9
 * Sum of all elements: 450
 *
 * --- Diagonal Elements ---
 * Principal Diagonal:  10 50 90
 * Secondary Diagonal:  30 50 70
 *
 * --- Row-wise Sum ---
 * Row 0: 60
 * Row 1: 150
 * Row 2: 240
 *
 * --- Column-wise Sum ---
 * Column 0: 120
 * Column 1: 150
 * Column 2: 180
 *
 * ========================================
 *
 * Example 3:
 * Input:
 *   Elements: 2, 4, 6, 8, 10, 12, 14, 16, 18
 * Output:
 * ========================================
 *   3×3 Matrix Input and Display
 * ========================================
 *
 * Enter elements for 3×3 matrix:
 * (Enter 9 values - row by row)
 *
 * Element [0][0]: 2
 * Element [0][1]: 4
 * Element [0][2]: 6
 * Element [1][0]: 8
 * Element [1][1]: 10
 * Element [1][2]: 12
 * Element [2][0]: 14
 * Element [2][1]: 16
 * Element [2][2]: 18
 *
 * ========================================
 *   Matrix Display
 * ========================================
 *
 * The 3×3 Matrix is:
 *
 *     [    2    4    6 ]
 *     [    8   10   12 ]
 *     [   14   16   18 ]
 *
 * --- Alternative Display Format ---
 *
 *     |    2    4    6 |
 *     |    8   10   12 |
 *     |   14   16   18 |
 *
 * ========================================
 *   Matrix Information
 * ========================================
 * Matrix Size:         3×3
 * Total Elements:      9
 * Sum of all elements: 90
 *
 * --- Diagonal Elements ---
 * Principal Diagonal:  2 10 18
 * Secondary Diagonal:  6 10 14
 *
 * --- Row-wise Sum ---
 * Row 0: 12
 * Row 1: 30
 * Row 2: 48
 *
 * --- Column-wise Sum ---
 * Column 0: 24
 * Column 1: 30
 * Column 2: 36
 *
 * ========================================
 */
