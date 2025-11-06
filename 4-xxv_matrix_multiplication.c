/*
 * QUESTION xxv:
 * Write a C program to calculate multiplication of 2-dimensional matrices.
 *
 * PROGRAM DESCRIPTION:
 * This program performs matrix multiplication on two matrices. Matrix
 * multiplication is different from element-wise operations. For two matrices
 * A (m×n) and B (n×p), the result C (m×p) is calculated as:
 * C[i][j] = Σ(k=0 to n-1) A[i][k] * B[k][j]
 *
 * Important condition: Number of columns in first matrix must equal
 * number of rows in second matrix.
 *
 * If A is m×n and B is n×p, then C will be m×p
 *
 * HOW TO SOLVE:
 * 1. Input dimensions of both matrices
 * 2. Verify that columns of A = rows of B
 * 3. Input elements for both matrices
 * 4. Initialize result matrix with zeros
 * 5. Use three nested loops for multiplication:
 *    - Outer loop: iterate through rows of A (i)
 *    - Middle loop: iterate through columns of B (j)
 *    - Inner loop: perform dot product (k)
 *      result[i][j] += A[i][k] * B[k][j]
 * 6. Display all matrices with proper formatting
 * 7. Show step-by-step calculation for verification
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
   printf("\nMatrix %s (%dx%d):\n", name, rows, cols);
   for (int i = 0; i < rows; i++) {
      printf("    [ ");
      for (int j = 0; j < cols; j++) {
         printf("%4d ", matrix[i][j]);
      }
      printf("]\n");
   }
}

// Function to multiply two matrices
void multiplyMatrices(int A[][10], int B[][10], int result[][10],
                      int r1, int c1, int r2, int c2) {
   // Initialize result matrix with zeros
   for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
         result[i][j] = 0;
      }
   }

   // Perform multiplication
   for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
         for (int k = 0; k < c1; k++) {
            result[i][j] += A[i][k] * B[k][j];
         }
      }
   }
}

// Function to show detailed calculation for one element
void showCalculation(int A[][10], int B[][10], int row, int col,
                     int c1, int result) {
   printf("\nCalculation for Result[%d][%d]:\n", row, col);
   printf("  = ");
   for (int k = 0; k < c1; k++) {
      printf("A[%d][%d] × B[%d][%d]", row, k, k, col);
      if (k < c1 - 1)
         printf(" + ");
   }
   printf("\n  = ");
   for (int k = 0; k < c1; k++) {
      printf("(%d × %d)", A[row][k], B[k][col]);
      if (k < c1 - 1)
         printf(" + ");
   }
   printf("\n  = ");
   for (int k = 0; k < c1; k++) {
      printf("%d", A[row][k] * B[k][col]);
      if (k < c1 - 1)
         printf(" + ");
   }
   printf("\n  = %d\n", result);
}

int main() {
   int A[10][10], B[10][10], result[10][10];
   int r1, c1, r2, c2;

   printf("========================================\n");
   printf("  Matrix Multiplication\n");
   printf("========================================\n\n");

   // Input dimensions for first matrix
   printf("Enter dimensions of Matrix A:\n");
   printf("Number of rows: ");
   scanf("%d", &r1);
   printf("Number of columns: ");
   scanf("%d", &c1);

   // Input dimensions for second matrix
   printf("\nEnter dimensions of Matrix B:\n");
   printf("Number of rows: ");
   scanf("%d", &r2);
   printf("Number of columns: ");
   scanf("%d", &c2);

   // Validate dimensions
   if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0 ||
       r1 > 10 || c1 > 10 || r2 > 10 || c2 > 10) {
      printf("\nError: Invalid dimensions! (1-10 allowed)\n");
      return 1;
   }

   if (c1 != r2) {
      printf("\n========================================\n");
      printf("ERROR: Matrix multiplication not possible!\n");
      printf("========================================\n");
      printf("Columns of Matrix A (%d) must equal\n", c1);
      printf("Rows of Matrix B (%d)\n", r2);
      printf("\nFor A(%dx%d) × B(%dx%d):\n", r1, c1, r2, c2);
      printf("Columns of A must = Rows of B\n");
      printf("========================================\n");
      return 1;
   }

   // Input matrices
   inputMatrix(A, r1, c1, "A");
   inputMatrix(B, r2, c2, "B");

   // Perform multiplication
   multiplyMatrices(A, B, result, r1, c1, r2, c2);

   // Display results
   printf("\n========================================\n");
   printf("  Input Matrices\n");
   printf("========================================");
   displayMatrix(A, r1, c1, "A");
   displayMatrix(B, r2, c2, "B");

   printf("\n========================================\n");
   printf("  Matrix Multiplication (A × B)\n");
   printf("========================================");
   displayMatrix(result, r1, c2, "Result");

   // Show dimensions
   printf("\n========================================\n");
   printf("  Dimension Analysis\n");
   printf("========================================\n");
   printf("Matrix A:      %d × %d\n", r1, c1);
   printf("Matrix B:      %d × %d\n", r2, c2);
   printf("Result (A×B):  %d × %d\n", r1, c2);
   printf("========================================\n");

   // Show sample calculations
   printf("\n========================================\n");
   printf("  Sample Calculations\n");
   printf("========================================");
   showCalculation(A, B, 0, 0, c1, result[0][0]);

   if (r1 > 1 && c2 > 1) {
      showCalculation(A, B, 1, 1, c1, result[1][1]);
   }

   printf("\n========================================\n");
   printf("Matrix Multiplication Rule:\n");
   printf("For A(m×n) × B(n×p):\n");
   printf("- Result will be C(m×p)\n");
   printf("- Columns of A must equal rows of B\n");
   printf("- C[i][j] = Σ A[i][k] × B[k][j]\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Matrix A (2×2): 1, 2, 3, 4
 *   Matrix B (2×2): 5, 6, 7, 8
 * Output:
 * ========================================
 *   Matrix Multiplication
 * ========================================
 *
 * Enter dimensions of Matrix A:
 * Number of rows: 2
 * Number of columns: 2
 *
 * Enter dimensions of Matrix B:
 * Number of rows: 2
 * Number of columns: 2
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
 * Matrix A (2x2):
 *     [    1    2 ]
 *     [    3    4 ]
 *
 * Matrix B (2x2):
 *     [    5    6 ]
 *     [    7    8 ]
 *
 * ========================================
 *   Matrix Multiplication (A × B)
 * ========================================
 * Matrix Result (2x2):
 *     [   19   22 ]
 *     [   43   50 ]
 *
 * ========================================
 *   Dimension Analysis
 * ========================================
 * Matrix A:      2 × 2
 * Matrix B:      2 × 2
 * Result (A×B):  2 × 2
 * ========================================
 *
 * ========================================
 *   Sample Calculations
 * ========================================
 * Calculation for Result[0][0]:
 *   = A[0][0] × B[0][0] + A[0][1] × B[1][0]
 *   = (1 × 5) + (2 × 7)
 *   = 5 + 14
 *   = 19
 *
 * Calculation for Result[1][1]:
 *   = A[1][0] × B[0][1] + A[1][1] × B[1][1]
 *   = (3 × 6) + (4 × 8)
 *   = 18 + 32
 *   = 50
 *
 * ========================================
 * Matrix Multiplication Rule:
 * For A(m×n) × B(n×p):
 * - Result will be C(m×p)
 * - Columns of A must equal rows of B
 * - C[i][j] = Σ A[i][k] × B[k][j]
 * ========================================
 *
 * Example 2:
 * Input:
 *   Matrix A (2×3): 1, 2, 3, 4, 5, 6
 *   Matrix B (3×2): 7, 8, 9, 10, 11, 12
 * Output:
 * ========================================
 *   Matrix Multiplication
 * ========================================
 *
 * Enter dimensions of Matrix A:
 * Number of rows: 2
 * Number of columns: 3
 *
 * Enter dimensions of Matrix B:
 * Number of rows: 3
 * Number of columns: 2
 *
 * Enter elements for Matrix A (2x3):
 * Element [0][0]: 1
 * Element [0][1]: 2
 * Element [0][2]: 3
 * Element [1][0]: 4
 * Element [1][1]: 5
 * Element [1][2]: 6
 *
 * Enter elements for Matrix B (3x2):
 * Element [0][0]: 7
 * Element [0][1]: 8
 * Element [1][0]: 9
 * Element [1][1]: 10
 * Element [2][0]: 11
 * Element [2][1]: 12
 *
 * ========================================
 *   Input Matrices
 * ========================================
 * Matrix A (2x3):
 *     [    1    2    3 ]
 *     [    4    5    6 ]
 *
 * Matrix B (3x2):
 *     [    7    8 ]
 *     [    9   10 ]
 *     [   11   12 ]
 *
 * ========================================
 *   Matrix Multiplication (A × B)
 * ========================================
 * Matrix Result (2x2):
 *     [   58   64 ]
 *     [  139  154 ]
 *
 * ========================================
 *   Dimension Analysis
 * ========================================
 * Matrix A:      2 × 3
 * Matrix B:      3 × 2
 * Result (A×B):  2 × 2
 * ========================================
 *
 * ========================================
 *   Sample Calculations
 * ========================================
 * Calculation for Result[0][0]:
 *   = A[0][0] × B[0][0] + A[0][1] × B[1][0] + A[0][2] × B[2][0]
 *   = (1 × 7) + (2 × 9) + (3 × 11)
 *   = 7 + 18 + 33
 *   = 58
 *
 * Calculation for Result[1][1]:
 *   = A[1][0] × B[0][1] + A[1][1] × B[1][1] + A[1][2] × B[2][1]
 *   = (4 × 8) + (5 × 10) + (6 × 12)
 *   = 32 + 50 + 72
 *   = 154
 *
 * ========================================
 * Matrix Multiplication Rule:
 * For A(m×n) × B(n×p):
 * - Result will be C(m×p)
 * - Columns of A must equal rows of B
 * - C[i][j] = Σ A[i][k] × B[k][j]
 * ========================================
 *
 * Example 3 (Invalid):
 * Input:
 *   Matrix A (2×3)
 *   Matrix B (2×2)
 * Output:
 * ========================================
 *   Matrix Multiplication
 * ========================================
 *
 * Enter dimensions of Matrix A:
 * Number of rows: 2
 * Number of columns: 3
 *
 * Enter dimensions of Matrix B:
 * Number of rows: 2
 * Number of columns: 2
 *
 * ========================================
 * ERROR: Matrix multiplication not possible!
 * ========================================
 * Columns of Matrix A (3) must equal
 * Rows of Matrix B (2)
 *
 * For A(2x3) × B(2x2):
 * Columns of A must = Rows of B
 * ========================================
 */
