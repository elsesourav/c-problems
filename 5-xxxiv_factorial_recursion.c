/*
 * QUESTION xxxiv:
 * Write a C program to calculate factorial of any given number using recursion.
 *
 * PROGRAM DESCRIPTION:
 * This program calculates the factorial of a number using recursive function.
 * Recursion is a technique where a function calls itself to solve a problem.
 *
 * Factorial is defined as:
 * - n! = n × (n-1) × (n-2) × ... × 2 × 1
 * - 0! = 1 (by definition)
 * - 5! = 5 × 4 × 3 × 2 × 1 = 120
 *
 * Recursive definition:
 * - Base case: factorial(0) = 1, factorial(1) = 1
 * - Recursive case: factorial(n) = n × factorial(n-1)
 *
 * For example:
 * factorial(5) = 5 × factorial(4)
 *              = 5 × (4 × factorial(3))
 *              = 5 × (4 × (3 × factorial(2)))
 *              = 5 × (4 × (3 × (2 × factorial(1))))
 *              = 5 × (4 × (3 × (2 × 1)))
 *              = 120
 *
 * HOW TO SOLVE:
 * 1. Create a recursive function factorial(n)
 * 2. Define base case: if n == 0 or n == 1, return 1
 * 3. Define recursive case: return n × factorial(n-1)
 * 4. Input a number from user
 * 5. Call recursive function
 * 6. Display result with recursion trace
 * 7. Handle negative numbers (factorial not defined)
 */

#include <stdio.h>

// Global variable to track recursion depth (for visualization)
int recursionDepth = 0;

// Recursive function to calculate factorial
unsigned long long factorialRecursive(int n) {
   // Increment depth for visualization
   recursionDepth++;

   // Print recursion trace
   for (int i = 0; i < recursionDepth - 1; i++) {
      printf("  ");
   }
   printf("→ factorial(%d) called\n", n);

   // Base case
   if (n == 0 || n == 1) {
      for (int i = 0; i < recursionDepth - 1; i++) {
         printf("  ");
      }
      printf("← factorial(%d) returns 1 (base case)\n", n);
      recursionDepth--;
      return 1;
   }

   // Recursive case
   unsigned long long result = n * factorialRecursive(n - 1);

   for (int i = 0; i < recursionDepth - 1; i++) {
      printf("  ");
   }
   printf("← factorial(%d) returns %d × factorial(%d) = %llu\n",
          n, n, n - 1, result);

   recursionDepth--;
   return result;
}

// Simple recursive factorial (without trace)
unsigned long long factorial(int n) {
   if (n == 0 || n == 1) {
      return 1;
   }
   return n * factorial(n - 1);
}

// Iterative version for comparison
unsigned long long factorialIterative(int n) {
   unsigned long long result = 1;
   for (int i = 2; i <= n; i++) {
      result *= i;
   }
   return result;
}

int main() {
   int num;
   unsigned long long result;

   printf("========================================\n");
   printf("  Factorial Calculator (Recursion)\n");
   printf("========================================\n\n");

   printf("Factorial (n!) = n × (n-1) × ... × 2 × 1\n");
   printf("This program uses RECURSION to calculate factorial\n\n");

   printf("Examples:\n");
   printf("  5! = 5 × 4 × 3 × 2 × 1 = 120\n");
   printf("  0! = 1 (by definition)\n\n");

   // Input number
   printf("Enter a non-negative integer: ");
   scanf("%d", &num);

   // Validation
   if (num < 0) {
      printf("\nError: Factorial is not defined for negative numbers!\n");
      return 1;
   }

   if (num > 20) {
      printf("\nWarning: Factorial of numbers > 20 may cause overflow.\n");
      printf("Proceeding with calculation...\n");
   }

   printf("\n========================================\n");
   printf("  Recursion Trace\n");
   printf("========================================\n\n");

   printf("Showing how recursion works:\n\n");
   recursionDepth = 0;
   result = factorialRecursive(num);

   printf("\n========================================\n");
   printf("  Mathematical Expansion\n");
   printf("========================================\n\n");

   printf("%d! = ", num);
   if (num == 0 || num == 1) {
      printf("1\n");
   } else {
      for (int i = num; i >= 1; i--) {
         printf("%d", i);
         if (i > 1) {
            printf(" × ");
         }
      }
      printf("\n   = %llu\n", result);
   }

   printf("\n========================================\n");
   printf("  Recursion Explanation\n");
   printf("========================================\n\n");

   printf("Recursive formula:\n");
   printf("  factorial(n) = n × factorial(n-1)\n");
   printf("  factorial(0) = 1 (base case)\n");
   printf("  factorial(1) = 1 (base case)\n\n");

   if (num > 1) {
      printf("For %d!:\n", num);
      printf("  factorial(%d) = %d × factorial(%d)\n", num, num, num - 1);
      if (num > 2) {
         printf("               = %d × %d × factorial(%d)\n",
                num, num - 1, num - 2);
      }
      if (num > 3) {
         printf("               = %d × %d × %d × factorial(%d)\n",
                num, num - 1, num - 2, num - 3);
      }
      printf("               ...\n");
      printf("               = %llu\n", result);
   }

   printf("\n========================================\n");
   printf("  Final Result\n");
   printf("========================================\n\n");

   printf("%d! = %llu\n", num, result);

   // Comparison with iterative method
   printf("\n--- Verification ---\n");
   unsigned long long iterativeResult = factorialIterative(num);
   printf("Recursive result:  %llu\n", result);
   printf("Iterative result:  %llu\n", iterativeResult);
   if (result == iterativeResult) {
      printf("✓ Results match!\n");
   }

   // Additional information
   printf("\n--- Recursion vs Iteration ---\n");
   printf("Recursion:\n");
   printf("  + Elegant and simple code\n");
   printf("  + Mirrors mathematical definition\n");
   printf("  - Uses more memory (call stack)\n");
   printf("  - Slower due to function call overhead\n\n");
   printf("Iteration:\n");
   printf("  + More memory efficient\n");
   printf("  + Faster execution\n");
   printf("  - More code to write\n");

   printf("\n========================================\n");
   printf("Summary:\n");
   printf("Input: %d\n", num);
   printf("Factorial: %llu\n", result);
   printf("Method: Recursion\n");
   printf("Recursion depth: %d levels\n", num);
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: 5
 * Output:
 * ========================================
 *   Factorial Calculator (Recursion)
 * ========================================
 *
 * Factorial (n!) = n × (n-1) × ... × 2 × 1
 * This program uses RECURSION to calculate factorial
 *
 * Examples:
 *   5! = 5 × 4 × 3 × 2 × 1 = 120
 *   0! = 1 (by definition)
 *
 * Enter a non-negative integer: 5
 *
 * ========================================
 *   Recursion Trace
 * ========================================
 *
 * Showing how recursion works:
 *
 * → factorial(5) called
 *   → factorial(4) called
 *     → factorial(3) called
 *       → factorial(2) called
 *         → factorial(1) called
 *         ← factorial(1) returns 1 (base case)
 *       ← factorial(2) returns 2 × factorial(1) = 2
 *     ← factorial(3) returns 3 × factorial(2) = 6
 *   ← factorial(4) returns 4 × factorial(3) = 24
 * ← factorial(5) returns 5 × factorial(4) = 120
 *
 * ========================================
 *   Mathematical Expansion
 * ========================================
 *
 * 5! = 5 × 4 × 3 × 2 × 1
 *    = 120
 *
 * ========================================
 *   Recursion Explanation
 * ========================================
 *
 * Recursive formula:
 *   factorial(n) = n × factorial(n-1)
 *   factorial(0) = 1 (base case)
 *   factorial(1) = 1 (base case)
 *
 * For 5!:
 *   factorial(5) = 5 × factorial(4)
 *                = 5 × 4 × factorial(3)
 *                = 5 × 4 × 3 × factorial(2)
 *                ...
 *                = 120
 *
 * ========================================
 *   Final Result
 * ========================================
 *
 * 5! = 120
 *
 * --- Verification ---
 * Recursive result:  120
 * Iterative result:  120
 * ✓ Results match!
 *
 * --- Recursion vs Iteration ---
 * Recursion:
 *   + Elegant and simple code
 *   + Mirrors mathematical definition
 *   - Uses more memory (call stack)
 *   - Slower due to function call overhead
 *
 * Iteration:
 *   + More memory efficient
 *   + Faster execution
 *   - More code to write
 *
 * ========================================
 * Summary:
 * Input: 5
 * Factorial: 120
 * Method: Recursion
 * Recursion depth: 5 levels
 * ========================================
 *
 * Example 2:
 * Input: 0
 * Output:
 * ========================================
 *   Factorial Calculator (Recursion)
 * ========================================
 *
 * Factorial (n!) = n × (n-1) × ... × 2 × 1
 * This program uses RECURSION to calculate factorial
 *
 * Examples:
 *   5! = 5 × 4 × 3 × 2 × 1 = 120
 *   0! = 1 (by definition)
 *
 * Enter a non-negative integer: 0
 *
 * ========================================
 *   Recursion Trace
 * ========================================
 *
 * Showing how recursion works:
 *
 * → factorial(0) called
 * ← factorial(0) returns 1 (base case)
 *
 * ========================================
 *   Mathematical Expansion
 * ========================================
 *
 * 0! = 1
 *
 * ========================================
 *   Recursion Explanation
 * ========================================
 *
 * Recursive formula:
 *   factorial(n) = n × factorial(n-1)
 *   factorial(0) = 1 (base case)
 *   factorial(1) = 1 (base case)
 *
 * ========================================
 *   Final Result
 * ========================================
 *
 * 0! = 1
 *
 * --- Verification ---
 * Recursive result:  1
 * Iterative result:  1
 * ✓ Results match!
 *
 * --- Recursion vs Iteration ---
 * Recursion:
 *   + Elegant and simple code
 *   + Mirrors mathematical definition
 *   - Uses more memory (call stack)
 *   - Slower due to function call overhead
 *
 * Iteration:
 *   + More memory efficient
 *   + Faster execution
 *   - More code to write
 *
 * ========================================
 * Summary:
 * Input: 0
 * Factorial: 1
 * Method: Recursion
 * Recursion depth: 0 levels
 * ========================================
 *
 * Example 3:
 * Input: 10
 * Output:
 * ========================================
 *   Factorial Calculator (Recursion)
 * ========================================
 *
 * Factorial (n!) = n × (n-1) × ... × 2 × 1
 * This program uses RECURSION to calculate factorial
 *
 * Examples:
 *   5! = 5 × 4 × 3 × 2 × 1 = 120
 *   0! = 1 (by definition)
 *
 * Enter a non-negative integer: 10
 *
 * ========================================
 *   Recursion Trace
 * ========================================
 *
 * Showing how recursion works:
 *
 * → factorial(10) called
 *   → factorial(9) called
 *     → factorial(8) called
 *       → factorial(7) called
 *         → factorial(6) called
 *           → factorial(5) called
 *             → factorial(4) called
 *               → factorial(3) called
 *                 → factorial(2) called
 *                   → factorial(1) called
 *                   ← factorial(1) returns 1 (base case)
 *                 ← factorial(2) returns 2 × factorial(1) = 2
 *               ← factorial(3) returns 3 × factorial(2) = 6
 *             ← factorial(4) returns 4 × factorial(3) = 24
 *           ← factorial(5) returns 5 × factorial(4) = 120
 *         ← factorial(6) returns 6 × factorial(5) = 720
 *       ← factorial(7) returns 7 × factorial(6) = 5040
 *     ← factorial(8) returns 8 × factorial(7) = 40320
 *   ← factorial(9) returns 9 × factorial(8) = 362880
 * ← factorial(10) returns 10 × factorial(9) = 3628800
 *
 * ========================================
 *   Mathematical Expansion
 * ========================================
 *
 * 10! = 10 × 9 × 8 × 7 × 6 × 5 × 4 × 3 × 2 × 1
 *     = 3628800
 *
 * ========================================
 *   Recursion Explanation
 * ========================================
 *
 * Recursive formula:
 *   factorial(n) = n × factorial(n-1)
 *   factorial(0) = 1 (base case)
 *   factorial(1) = 1 (base case)
 *
 * For 10!:
 *   factorial(10) = 10 × factorial(9)
 *                 = 10 × 9 × factorial(8)
 *                 = 10 × 9 × 8 × factorial(7)
 *                 ...
 *                 = 3628800
 *
 * ========================================
 *   Final Result
 * ========================================
 *
 * 10! = 3628800
 *
 * --- Verification ---
 * Recursive result:  3628800
 * Iterative result:  3628800
 * ✓ Results match!
 *
 * --- Recursion vs Iteration ---
 * Recursion:
 *   + Elegant and simple code
 *   + Mirrors mathematical definition
 *   - Uses more memory (call stack)
 *   - Slower due to function call overhead
 *
 * Iteration:
 *   + More memory efficient
 *   + Faster execution
 *   - More code to write
 *
 * ========================================
 * Summary:
 * Input: 10
 * Factorial: 3628800
 * Method: Recursion
 * Recursion depth: 10 levels
 * ========================================
 */
