/*
 * QUESTION xvii:
 * Write a C program to add the series 1 + (1+2) + (1+2+3) + … + (1+2+3+…+n).
 *
 * PROGRAM DESCRIPTION:
 * This program calculates the sum of a nested series where:
 * - Term 1 = 1
 * - Term 2 = 1 + 2 = 3
 * - Term 3 = 1 + 2 + 3 = 6
 * - Term 4 = 1 + 2 + 3 + 4 = 10
 * - Term n = 1 + 2 + 3 + ... + n
 *
 * Final sum = Sum of all terms
 * Each term itself is the sum of first k natural numbers = k(k+1)/2
 *
 * Total sum = Σ(k=1 to n) [k(k+1)/2] = n(n+1)(n+2)/6
 *
 * HOW TO SOLVE:
 * 1. Input the value of n from the user
 * 2. Method 1 - Using nested loops:
 *    - Outer loop: i from 1 to n (each term)
 *    - Inner loop: j from 1 to i (sum for that term)
 *    - Add each term's sum to total
 * 3. Method 2 - Using single loop with formula:
 *    - Each term = i(i+1)/2
 *    - Add all terms
 * 4. Method 3 - Direct formula:
 *    - Sum = n(n+1)(n+2)/6
 * 5. Display step-by-step calculation and final result
 */

#include <stdio.h>

int main() {
   int n, i, j;
   long long termSum, totalSum;

   // Input
   printf("Enter the value of n: ");
   scanf("%d", &n);

   if (n <= 0) {
      printf("Error: n must be a positive integer!\n");
      return 1;
   }

   printf("\n========================================\n");
   printf("  Series: 1 + (1+2) + (1+2+3) + ... + (1+2+...+n)\n");
   printf("  For n = %d\n", n);
   printf("========================================\n\n");

   // Method 1: Using nested loops
   printf("--- Method 1: Nested Loops (Step by Step) ---\n\n");
   totalSum = 0;

   for (i = 1; i <= n; i++) {
      termSum = 0;
      printf("Term %d: ", i);

      // Calculate sum for this term
      for (j = 1; j <= i; j++) {
         termSum += j;
         printf("%d", j);
         if (j < i)
            printf(" + ");
      }

      printf(" = %lld\n", termSum);
      totalSum += termSum;
   }

   printf("\nTotal Sum = %lld\n\n", totalSum);

   // Method 2: Using formula for each term
   printf("--- Method 2: Using Formula for Each Term ---\n\n");
   totalSum = 0;

   for (i = 1; i <= n; i++) {
      termSum = (i * (i + 1)) / 2;
      printf("Term %d = %d(%d+1)/2 = %lld\n", i, i, i, termSum);
      totalSum += termSum;
   }

   printf("\nTotal Sum = %lld\n\n", totalSum);

   // Method 3: Direct formula
   printf("--- Method 3: Direct Formula ---\n\n");
   printf("Formula: Sum = n(n+1)(n+2)/6\n");
   printf("Sum = %d × %d × %d / 6\n", n, n + 1, n + 2);
   printf("Sum = %d / 6\n", n * (n + 1) * (n + 2));
   totalSum = (n * (n + 1) * (n + 2)) / 6;
   printf("Sum = %lld\n\n", totalSum);

   // Display breakdown
   printf("========================================\n");
   printf("BREAKDOWN:\n");
   printf("========================================\n");
   printf("Number of terms (n):           %d\n", n);
   printf("First term:                    1\n");
   printf("Last term (1+2+...+%d):        %lld\n", n, (long long)(n * (n + 1)) / 2);
   printf("Total Sum:                     %lld\n", totalSum);
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: n = 4
 * Output:
 * ========================================
 *   Series: 1 + (1+2) + (1+2+3) + ... + (1+2+...+n)
 *   For n = 4
 * ========================================
 *
 * --- Method 1: Nested Loops (Step by Step) ---
 *
 * Term 1: 1 = 1
 * Term 2: 1 + 2 = 3
 * Term 3: 1 + 2 + 3 = 6
 * Term 4: 1 + 2 + 3 + 4 = 10
 *
 * Total Sum = 20
 *
 * --- Method 2: Using Formula for Each Term ---
 *
 * Term 1 = 1(1+1)/2 = 1
 * Term 2 = 2(2+1)/2 = 3
 * Term 3 = 3(3+1)/2 = 6
 * Term 4 = 4(4+1)/2 = 10
 *
 * Total Sum = 20
 *
 * --- Method 3: Direct Formula ---
 *
 * Formula: Sum = n(n+1)(n+2)/6
 * Sum = 4 × 5 × 6 / 6
 * Sum = 120 / 6
 * Sum = 20
 *
 * ========================================
 * BREAKDOWN:
 * ========================================
 * Number of terms (n):           4
 * First term:                    1
 * Last term (1+2+...+4):        10
 * Total Sum:                     20
 * ========================================
 *
 * Example 2:
 * Input: n = 5
 * Output:
 * ========================================
 *   Series: 1 + (1+2) + (1+2+3) + ... + (1+2+...+n)
 *   For n = 5
 * ========================================
 *
 * --- Method 1: Nested Loops (Step by Step) ---
 *
 * Term 1: 1 = 1
 * Term 2: 1 + 2 = 3
 * Term 3: 1 + 2 + 3 = 6
 * Term 4: 1 + 2 + 3 + 4 = 10
 * Term 5: 1 + 2 + 3 + 4 + 5 = 15
 *
 * Total Sum = 35
 *
 * --- Method 2: Using Formula for Each Term ---
 *
 * Term 1 = 1(1+1)/2 = 1
 * Term 2 = 2(2+1)/2 = 3
 * Term 3 = 3(3+1)/2 = 6
 * Term 4 = 4(4+1)/2 = 10
 * Term 5 = 5(5+1)/2 = 15
 *
 * Total Sum = 35
 *
 * --- Method 3: Direct Formula ---
 *
 * Formula: Sum = n(n+1)(n+2)/6
 * Sum = 5 × 6 × 7 / 6
 * Sum = 210 / 6
 * Sum = 35
 *
 * ========================================
 * BREAKDOWN:
 * ========================================
 * Number of terms (n):           5
 * First term:                    1
 * Last term (1+2+...+5):        15
 * Total Sum:                     35
 * ========================================
 *
 * Example 3:
 * Input: n = 10
 * Output:
 * ========================================
 *   Series: 1 + (1+2) + (1+2+3) + ... + (1+2+...+n)
 *   For n = 10
 * ========================================
 *
 * --- Method 1: Nested Loops (Step by Step) ---
 *
 * Term 1: 1 = 1
 * Term 2: 1 + 2 = 3
 * Term 3: 1 + 2 + 3 = 6
 * Term 4: 1 + 2 + 3 + 4 = 10
 * Term 5: 1 + 2 + 3 + 4 + 5 = 15
 * Term 6: 1 + 2 + 3 + 4 + 5 + 6 = 21
 * Term 7: 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28
 * Term 8: 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36
 * Term 9: 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
 * Term 10: 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55
 *
 * Total Sum = 220
 *
 * --- Method 2: Using Formula for Each Term ---
 *
 * Term 1 = 1(1+1)/2 = 1
 * Term 2 = 2(2+1)/2 = 3
 * Term 3 = 3(3+1)/2 = 6
 * Term 4 = 4(4+1)/2 = 10
 * Term 5 = 5(5+1)/2 = 15
 * Term 6 = 6(6+1)/2 = 21
 * Term 7 = 7(7+1)/2 = 28
 * Term 8 = 8(8+1)/2 = 36
 * Term 9 = 9(9+1)/2 = 45
 * Term 10 = 10(10+1)/2 = 55
 *
 * Total Sum = 220
 *
 * --- Method 3: Direct Formula ---
 *
 * Formula: Sum = n(n+1)(n+2)/6
 * Sum = 10 × 11 × 12 / 6
 * Sum = 1320 / 6
 * Sum = 220
 *
 * ========================================
 * BREAKDOWN:
 * ========================================
 * Number of terms (n):           10
 * First term:                    1
 * Last term (1+2+...+10):       55
 * Total Sum:                     220
 * ========================================
 */
