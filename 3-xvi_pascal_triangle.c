/*
 * QUESTION xvi:
 * Write a C program to generate Pascal's triangle for n rows.
 *
 * PROGRAM DESCRIPTION:
 * Pascal's triangle is a triangular array of binomial coefficients.
 * Each number is the sum of the two numbers directly above it.
 * Structure:
 *           1
 *         1   1
 *       1   2   1
 *     1   3   3   1
 *   1   4   6   4   1
 *
 * Each element can be calculated using the binomial coefficient formula:
 * C(n, r) = n! / (r! * (n-r)!)
 *
 * HOW TO SOLVE:
 * 1. Input number of rows (n) from the user
 * 2. Use nested loops:
 *    - Outer loop: Iterate through rows (i from 0 to n-1)
 *    - Inner loop: Calculate and print values for each position
 * 3. Methods to calculate values:
 *    - Method 1: Use binomial coefficient formula C(n,r)
 *    - Method 2: Use the property that each element = previous element * (row-col) / col
 * 4. Add proper spacing for pyramid appearance
 * 5. Print each row with appropriate formatting
 */

#include <stdio.h>

// Function to calculate factorial
long long factorial(int n) {
   long long fact = 1;
   for (int i = 2; i <= n; i++) {
      fact *= i;
   }
   return fact;
}

// Function to calculate binomial coefficient C(n, r)
long long binomialCoeff(int n, int r) {
   return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
   int n, i, j, spaces;
   long long coef;

   // Input number of rows
   printf("Enter the number of rows for Pascal's Triangle: ");
   scanf("%d", &n);

   if (n <= 0) {
      printf("Error: Number of rows must be positive!\n");
      return 1;
   }

   printf("\n========================================\n");
   printf("   Pascal's Triangle (n = %d)\n", n);
   printf("========================================\n\n");

   // Method 1: Using Binomial Coefficient
   printf("--- Method 1: Using Binomial Coefficient ---\n\n");
   for (i = 0; i < n; i++) {
      // Print leading spaces for pyramid shape
      for (spaces = 0; spaces < n - i - 1; spaces++) {
         printf("   ");
      }

      // Print values in the row
      for (j = 0; j <= i; j++) {
         printf("%6lld", binomialCoeff(i, j));
      }
      printf("\n");
   }

   // Method 2: Using iterative calculation (more efficient)
   printf("\n--- Method 2: Using Iterative Calculation ---\n\n");
   for (i = 0; i < n; i++) {
      // Print leading spaces
      for (spaces = 0; spaces < n - i - 1; spaces++) {
         printf("   ");
      }

      coef = 1;
      for (j = 0; j <= i; j++) {
         printf("%6lld", coef);
         // Calculate next coefficient: C(i, j+1) = C(i, j) * (i-j) / (j+1)
         coef = coef * (i - j) / (j + 1);
      }
      printf("\n");
   }

   // Compact display
   printf("\n--- Compact Display ---\n\n");
   for (i = 0; i < n; i++) {
      // Print leading spaces
      for (spaces = 0; spaces < n - i - 1; spaces++) {
         printf(" ");
      }

      coef = 1;
      for (j = 0; j <= i; j++) {
         printf("%lld ", coef);
         coef = coef * (i - j) / (j + 1);
      }
      printf("\n");
   }

   printf("\n========================================\n");
   printf("Properties of Pascal's Triangle:\n");
   printf("- Each row starts and ends with 1\n");
   printf("- Each number is sum of two above it\n");
   printf("- Row n contains binomial coefficients\n");
   printf("- Symmetrical about the center\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: n = 5
 * Output:
 * ========================================
 *    Pascal's Triangle (n = 5)
 * ========================================
 *
 * --- Method 1: Using Binomial Coefficient ---
 *
 *                1
 *             1     1
 *          1     2     1
 *       1     3     3     1
 *    1     4     6     4     1
 *
 * --- Method 2: Using Iterative Calculation ---
 *
 *                1
 *             1     1
 *          1     2     1
 *       1     3     3     1
 *    1     4     6     4     1
 *
 * --- Compact Display ---
 *
 *     1
 *    1 1
 *   1 2 1
 *  1 3 3 1
 * 1 4 6 4 1
 *
 * ========================================
 * Properties of Pascal's Triangle:
 * - Each row starts and ends with 1
 * - Each number is sum of two above it
 * - Row n contains binomial coefficients
 * - Symmetrical about the center
 * ========================================
 *
 * Example 2:
 * Input: n = 7
 * Output:
 * ========================================
 *    Pascal's Triangle (n = 7)
 * ========================================
 *
 * --- Method 1: Using Binomial Coefficient ---
 *
 *                      1
 *                   1     1
 *                1     2     1
 *             1     3     3     1
 *          1     4     6     4     1
 *       1     5    10    10     5     1
 *    1     6    15    20    15     6     1
 *
 * --- Method 2: Using Iterative Calculation ---
 *
 *                      1
 *                   1     1
 *                1     2     1
 *             1     3     3     1
 *          1     4     6     4     1
 *       1     5    10    10     5     1
 *    1     6    15    20    15     6     1
 *
 * --- Compact Display ---
 *
 *       1
 *      1 1
 *     1 2 1
 *    1 3 3 1
 *   1 4 6 4 1
 *  1 5 10 10 5 1
 * 1 6 15 20 15 6 1
 *
 * ========================================
 * Properties of Pascal's Triangle:
 * - Each row starts and ends with 1
 * - Each number is sum of two above it
 * - Row n contains binomial coefficients
 * - Symmetrical about the center
 * ========================================
 *
 * Example 3:
 * Input: n = 3
 * Output:
 * ========================================
 *    Pascal's Triangle (n = 3)
 * ========================================
 *
 * --- Method 1: Using Binomial Coefficient ---
 *
 *          1
 *       1     1
 *    1     2     1
 *
 * --- Method 2: Using Iterative Calculation ---
 *
 *          1
 *       1     1
 *    1     2     1
 *
 * --- Compact Display ---
 *
 *   1
 *  1 1
 * 1 2 1
 *
 * ========================================
 * Properties of Pascal's Triangle:
 * - Each row starts and ends with 1
 * - Each number is sum of two above it
 * - Row n contains binomial coefficients
 * - Symmetrical about the center
 * ========================================
 */
