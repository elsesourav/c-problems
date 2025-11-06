/*
 * QUESTION xxxi:
 * Write a C program to calculate the value of nCr, where n ≥ r using function.
 *
 * PROGRAM DESCRIPTION:
 * This program calculates combinations (nCr) which represents the number
 * of ways to choose r items from n items without regard to order.
 *
 * Formula: nCr = n! / (r! × (n-r)!)
 *
 * Where:
 * - n! is the factorial of n
 * - r! is the factorial of r
 * - (n-r)! is the factorial of (n-r)
 *
 * Examples:
 * - 5C2 = 5!/(2!×3!) = 120/(2×6) = 10
 * - 10C3 = 10!/(3!×7!) = 120
 * - 6C6 = 1 (choosing all items)
 * - 6C0 = 1 (choosing no items)
 *
 * HOW TO SOLVE:
 * 1. Create a function to calculate factorial of a number
 * 2. Create a function to calculate nCr using the formula
 * 3. Input n and r from user
 * 4. Validate that n ≥ r ≥ 0
 * 5. Calculate nCr = n! / (r! × (n-r)!)
 * 6. Display the result with detailed calculation steps
 * 7. Handle edge cases (r=0, r=n, etc.)
 */

#include <stdio.h>

// Function to calculate factorial
unsigned long long factorial(int num) {
   unsigned long long fact = 1;
   for (int i = 1; i <= num; i++) {
      fact *= i;
   }
   return fact;
}

// Function to calculate nCr using factorial method
unsigned long long nCr_factorial(int n, int r) {
   return factorial(n) / (factorial(r) * factorial(n - r));
}

// Optimized function to calculate nCr (to avoid overflow for large numbers)
unsigned long long nCr_optimized(int n, int r) {
   // nCr = nC(n-r), choose smaller value for efficiency
   if (r > n - r) {
      r = n - r;
   }

   unsigned long long result = 1;

   // Calculate C(n, r) using: C(n, r) = n × (n-1) × ... × (n-r+1) / r!
   for (int i = 0; i < r; i++) {
      result *= (n - i);
      result /= (i + 1);
   }

   return result;
}

// Function to display calculation steps
void displayCalculation(int n, int r) {
   printf("--- Calculation Steps ---\n\n");
   printf("Formula: nCr = n! / (r! × (n-r)!)\n\n");

   unsigned long long n_fact = factorial(n);
   unsigned long long r_fact = factorial(r);
   unsigned long long nr_fact = factorial(n - r);

   printf("Step 1: Calculate factorials\n");
   printf("  n!     = %d! = %llu\n", n, n_fact);
   printf("  r!     = %d! = %llu\n", r, r_fact);
   printf("  (n-r)! = (%d-%d)! = %d! = %llu\n", n, r, n - r, nr_fact);

   printf("\nStep 2: Apply formula\n");
   printf("  %dC%d = %llu / (%llu × %llu)\n", n, r, n_fact, r_fact, nr_fact);
   printf("       = %llu / %llu\n", n_fact, r_fact * nr_fact);
   printf("       = %llu\n", nCr_factorial(n, r));
}

int main() {
   int n, r;
   unsigned long long result;

   printf("========================================\n");
   printf("  Combination Calculator (nCr)\n");
   printf("========================================\n\n");

   printf("nCr: Number of ways to choose r items\n");
   printf("     from n items (order doesn't matter)\n\n");

   printf("Formula: nCr = n! / (r! × (n-r)!)\n\n");

   // Input values
   printf("Enter value of n: ");
   scanf("%d", &n);
   printf("Enter value of r: ");
   scanf("%d", &r);

   // Validation
   if (n < 0 || r < 0) {
      printf("\nError: n and r must be non-negative!\n");
      return 1;
   }

   if (r > n) {
      printf("\nError: r cannot be greater than n!\n");
      printf("Condition: n ≥ r must be satisfied\n");
      return 1;
   }

   printf("\n========================================\n");
   printf("  Results\n");
   printf("========================================\n\n");

   // Display calculation steps for smaller values
   if (n <= 12) {
      displayCalculation(n, r);
   } else {
      printf("Using optimized calculation for large values...\n");
   }

   // Calculate using optimized method
   result = nCr_optimized(n, r);

   printf("\n========================================\n");
   printf("  Final Answer\n");
   printf("========================================\n\n");

   printf("%dC%d = %llu\n", n, r, result);

   // Special cases explanation
   printf("\n--- Interpretation ---\n");
   if (r == 0) {
      printf("There is exactly 1 way to choose 0 items\n");
      printf("from %d items (choose nothing).\n", n);
   } else if (r == n) {
      printf("There is exactly 1 way to choose all %d items\n", n);
      printf("from %d items (choose everything).\n", n);
   } else if (r == 1) {
      printf("There are %d ways to choose 1 item\n", n);
      printf("from %d items.\n", n);
   } else if (r == n - 1) {
      printf("There are %d ways to choose %d items\n", n, r);
      printf("from %d items (same as choosing which 1 to leave out).\n", n);
   } else {
      printf("There are %llu ways to choose %d items\n", result, r);
      printf("from %d items without regard to order.\n", n);
   }

   // Additional information
   printf("\n--- Additional Information ---\n");
   printf("Property: %dC%d = %dC%d = %llu\n", n, r, n, n - r, result);
   printf("(Choosing r items is same as leaving out (n-r) items)\n");

   printf("\n========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: n = 5, r = 2
 * Output:
 * ========================================
 *   Combination Calculator (nCr)
 * ========================================
 *
 * nCr: Number of ways to choose r items
 *      from n items (order doesn't matter)
 *
 * Formula: nCr = n! / (r! × (n-r)!)
 *
 * Enter value of n: 5
 * Enter value of r: 2
 *
 * ========================================
 *   Results
 * ========================================
 *
 * --- Calculation Steps ---
 *
 * Formula: nCr = n! / (r! × (n-r)!)
 *
 * Step 1: Calculate factorials
 *   n!     = 5! = 120
 *   r!     = 2! = 2
 *   (n-r)! = (5-2)! = 3! = 6
 *
 * Step 2: Apply formula
 *   5C2 = 120 / (2 × 6)
 *       = 120 / 12
 *       = 10
 *
 * ========================================
 *   Final Answer
 * ========================================
 *
 * 5C2 = 10
 *
 * --- Interpretation ---
 * There are 10 ways to choose 2 items
 * from 5 items without regard to order.
 *
 * --- Additional Information ---
 * Property: 5C2 = 5C3 = 10
 * (Choosing r items is same as leaving out (n-r) items)
 *
 * ========================================
 *
 * Example 2:
 * Input: n = 10, r = 3
 * Output:
 * ========================================
 *   Combination Calculator (nCr)
 * ========================================
 *
 * nCr: Number of ways to choose r items
 *      from n items (order doesn't matter)
 *
 * Formula: nCr = n! / (r! × (n-r)!)
 *
 * Enter value of n: 10
 * Enter value of r: 3
 *
 * ========================================
 *   Results
 * ========================================
 *
 * --- Calculation Steps ---
 *
 * Formula: nCr = n! / (r! × (n-r)!)
 *
 * Step 1: Calculate factorials
 *   n!     = 10! = 3628800
 *   r!     = 3! = 6
 *   (n-r)! = (10-3)! = 7! = 5040
 *
 * Step 2: Apply formula
 *   10C3 = 3628800 / (6 × 5040)
 *        = 3628800 / 30240
 *        = 120
 *
 * ========================================
 *   Final Answer
 * ========================================
 *
 * 10C3 = 120
 *
 * --- Interpretation ---
 * There are 120 ways to choose 3 items
 * from 10 items without regard to order.
 *
 * --- Additional Information ---
 * Property: 10C3 = 10C7 = 120
 * (Choosing r items is same as leaving out (n-r) items)
 *
 * ========================================
 *
 * Example 3:
 * Input: n = 6, r = 0
 * Output:
 * ========================================
 *   Combination Calculator (nCr)
 * ========================================
 *
 * nCr: Number of ways to choose r items
 *      from n items (order doesn't matter)
 *
 * Formula: nCr = n! / (r! × (n-r)!)
 *
 * Enter value of n: 6
 * Enter value of r: 0
 *
 * ========================================
 *   Results
 * ========================================
 *
 * --- Calculation Steps ---
 *
 * Formula: nCr = n! / (r! × (n-r)!)
 *
 * Step 1: Calculate factorials
 *   n!     = 6! = 720
 *   r!     = 0! = 1
 *   (n-r)! = (6-0)! = 6! = 720
 *
 * Step 2: Apply formula
 *   6C0 = 720 / (1 × 720)
 *       = 720 / 720
 *       = 1
 *
 * ========================================
 *   Final Answer
 * ========================================
 *
 * 6C0 = 1
 *
 * --- Interpretation ---
 * There is exactly 1 way to choose 0 items
 * from 6 items (choose nothing).
 *
 * --- Additional Information ---
 * Property: 6C0 = 6C6 = 1
 * (Choosing r items is same as leaving out (n-r) items)
 *
 * ========================================
 */
