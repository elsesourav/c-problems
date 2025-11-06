/*
 * QUESTION xxiv:
 * Write a C program to calculate addition and subtraction of 2-dimensional matrices.
 *
 * PROGRAM DESCRIPTION:
 * This program performs matrix addition and subtraction operations on two
 * matrices of the same dimensions. Matrix addition/subtraction is performed
 * element-wise, meaning corresponding elements are added/subtracted.
 *
 * Matrix Addition: C[i][j] = A[i][j] + B[i][j]
 * Matrix Subtraction: C[i][j] = A[i][j] - B[i][j]
 *
 * Note: Matrices must have the same dimensions for addition/subtraction.
 *
 * HOW TO SOLVE:
 * 1. Input dimensions (rows and columns) from user
 * 2. Declare three matrices: A, B, and Result
 * 3. Input elements for matrix A using nested loops
 * 4. Input elements for matrix B using nested loops
 * 5. For Addition:
 *    - Loop through each position [i][j]
 *    - result[i][j] = A[i][j] + B[i][j]
 * 6. For Subtraction:
 *    - Loop through each position [i][j]
 *    - result[i][j] = A[i][j] - B[i][j]
 * 7. Display all matrices in proper format
 */

#include <stdio.h>

// Function to input matrix
void inputMatrix(int matrix[][10], int rows, int cols, char name[]) {
   printf("\nEnter elements for Matrix %s (%dx%d):\n", name, rows, cols);
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("Element [%d][%d]: ", i, j);
         scanf("%d", &matrix[i][j]);
      }
   }
}

// Function to display matrix
void displayMatrix(int matrix[][10], int rows, int cols, char name[]) {
   printf("\nMatrix %s:\n", name);
   for (int i = 0; i < rows; i++) {
      printf("    [ ");
      for (int j = 0; j < cols; j++) {
         printf("%4d ", matrix[i][j]);
      }
      printf("]\n");
   }
}

// Function to add two matrices
void addMatrices(int A[][10], int B[][10], int result[][10], int rows, int cols) {
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         result[i][j] = A[i][j] + B[i][j];
      }
   }
}

// Function to subtract two matrices
void subtractMatrices(int A[][10], int B[][10], int result[][10], int rows, int cols) {
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         result[i][j] = A[i][j] - B[i][j];
      }
   }
}

int main() {
   int A[10][10], B[10][10], sum[10][10], diff[10][10];
   int rows, cols, i, j;

   printf("========================================\n");
   printf("  Matrix Addition & Subtraction\n");
   printf("========================================\n\n");

   // Input matrix dimensions
   printf("Enter number of rows: ");
   scanf("%d", &rows);
   printf("Enter number of columns: ");
   scanf("%d", &cols);

   if (rows <= 0 || cols <= 0 || rows > 10 || cols > 10) {
      printf("\nError: Invalid dimensions! (1-10 allowed)\n");
      return 1;
   }

   // Input matrices
   inputMatrix(A, rows, cols, "A");
   inputMatrix(B, rows, cols, "B");

   // Perform operations
   addMatrices(A, B, sum, rows, cols);
   subtractMatrices(A, B, diff, rows, cols);

   // Display results
   printf("\n========================================\n");
   printf("  Input Matrices\n");
   printf("========================================");
   displayMatrix(A, rows, cols, "A");
   displayMatrix(B, rows, cols, "B");

   printf("\n========================================\n");
   printf("  Matrix Addition (A + B)\n");
   printf("========================================");
   displayMatrix(sum, rows, cols, "Sum");

   printf("\n========================================\n");
   printf("  Matrix Subtraction (A - B)\n");
   printf("========================================");
   displayMatrix(diff, rows, cols, "Difference");

   // Show operation step-by-step for first element
   printf("\n========================================\n");
   printf("  Sample Calculation (First Element)\n");
   printf("========================================\n");
   printf("Addition:    A[0][0] + B[0][0] = %d + %d = %d\n",
          A[0][0], B[0][0], sum[0][0]);
   printf("Subtraction: A[0][0] - B[0][0] = %d - %d = %d\n",
          A[0][0], B[0][0], diff[0][0]);
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Rows: 2, Columns: 2
 *   Matrix A: 1, 2, 3, 4
 *   Matrix B: 5, 6, 7, 8
 * Output:
 * ========================================
 *   Matrix Addition & Subtraction
 * ========================================
 *
 * Enter number of rows: 2
 * Enter number of columns: 2
 *
 * Enter elements for Matrix A (2x2):
 * Element [0][0]: 1
 * Element [0][1]: 2
 * Element [1][0]: 3
 * Element [1][1]: 4
 *
 * Enter elements for Matrix B (2x2):
 * Element [0][0]: 5
 * Element [0][1]: 6
 * Element [1][0]: 7
 * Element [1][1]: 8
 *
 * ========================================
 *   Input Matrices
 * ========================================
 * Matrix A:
 *     [    1    2 ]
 *     [    3    4 ]
 *
 * Matrix B:
 *     [    5    6 ]
 *     [    7    8 ]
 *
 * ========================================
 *   Matrix Addition (A + B)
 * ========================================
 * Matrix Sum:
 *     [    6    8 ]
 *     [   10   12 ]
 *
 * ========================================
 *   Matrix Subtraction (A - B)
 * ========================================
 * Matrix Difference:
 *     [   -4   -4 ]
 *     [   -4   -4 ]
 *
 * ========================================
 *   Sample Calculation (First Element)
 * ========================================
 * Addition:    A[0][0] + B[0][0] = 1 + 5 = 6
 * Subtraction: A[0][0] - B[0][0] = 1 - 5 = -4
 * ========================================
 *
 * Example 2:
 * Input:
 *   Rows: 3, Columns: 3
 *   Matrix A: 1, 2, 3, 4, 5, 6, 7, 8, 9
 *   Matrix B: 9, 8, 7, 6, 5, 4, 3, 2, 1
 * Output:
 * ========================================
 *   Matrix Addition & Subtraction
 * ========================================
 *
 * Enter number of rows: 3
 * Enter number of columns: 3
 *
 * Enter elements for Matrix A (3x3):
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
 * Enter elements for Matrix B (3x3):
 * Element [0][0]: 9
 * Element [0][1]: 8
 * Element [0][2]: 7
 * Element [1][0]: 6
 * Element [1][1]: 5
 * Element [1][2]: 4
 * Element [2][0]: 3
 * Element [2][1]: 2
 * Element [2][2]: 1
 *
 * ========================================
 *   Input Matrices
 * ========================================
 * Matrix A:
 *     [    1    2    3 ]
 *     [    4    5    6 ]
 *     [    7    8    9 ]
 *
 * Matrix B:
 *     [    9    8    7 ]
 *     [    6    5    4 ]
 *     [    3    2    1 ]
 *
 * ========================================
 *   Matrix Addition (A + B)
 * ========================================
 * Matrix Sum:
 *     [   10   10   10 ]
 *     [   10   10   10 ]
 *     [   10   10   10 ]
 *
 * ========================================
 *   Matrix Subtraction (A - B)
 * ========================================
 * Matrix Difference:
 *     [   -8   -6   -4 ]
 *     [   -2    0    2 ]
 *     [    4    6    8 ]
 *
 * ========================================
 *   Sample Calculation (First Element)
 * ========================================
 * Addition:    A[0][0] + B[0][0] = 1 + 9 = 10
 * Subtraction: A[0][0] - B[0][0] = 1 - 9 = -8
 * ========================================
 *
 * Example 3:
 * Input:
 *   Rows: 2, Columns: 3
 *   Matrix A: 10, 20, 30, 40, 50, 60
 *   Matrix B: 5, 10, 15, 20, 25, 30
 * Output:
 * ========================================
 *   Matrix Addition & Subtraction
 * ========================================
 *
 * Enter number of rows: 2
 * Enter number of columns: 3
 *
 * Enter elements for Matrix A (2x3):
 * Element [0][0]: 10
 * Element [0][1]: 20
 * Element [0][2]: 30
 * Element [1][0]: 40
 * Element [1][1]: 50
 * Element [1][2]: 60
 *
 * Enter elements for Matrix B (2x3):
 * Element [0][0]: 5
 * Element [0][1]: 10
 * Element [0][2]: 15
 * Element [1][0]: 20
 * Element [1][1]: 25
 * Element [1][2]: 30
 *
 * ========================================
 *   Input Matrices
 * ========================================
 * Matrix A:
 *     [   10   20   30 ]
 *     [   40   50   60 ]
 *
 * Matrix B:
 *     [    5   10   15 ]
 *     [   20   25   30 ]
 *
 * ========================================
 *   Matrix Addition (A + B)
 * ========================================
 * Matrix Sum:
 *     [   15   30   45 ]
 *     [   60   75   90 ]
 *
 * ========================================
 *   Matrix Subtraction (A - B)
 * ========================================
 * Matrix Difference:
 *     [    5   10   15 ]
 *     [   20   25   30 ]
 *
 * ========================================
 *   Sample Calculation (First Element)
 * ========================================
 * Addition:    A[0][0] + B[0][0] = 10 + 5 = 15
 * Subtraction: A[0][0] - B[0][0] = 10 - 5 = 5
 * ========================================
 */
