/*
 * QUESTION xiii:
 * Write a C program to add first 'n' natural, even, and odd numbers using
 * different loop structures.
 *
 * PROGRAM DESCRIPTION:
 * This program calculates the sum of:
 * 1. First n natural numbers (1, 2, 3, ..., n)
 * 2. First n even numbers (2, 4, 6, ..., 2n)
 * 3. First n odd numbers (1, 3, 5, ..., 2n-1)
 * Each calculation is demonstrated using different loop structures:
 * for loop, while loop, and do-while loop.
 *
 * HOW TO SOLVE:
 * 1. Input the value of n from the user
 * 2. For natural numbers sum:
 *    - Initialize sum = 0
 *    - Loop from i = 1 to n
 *    - Add i to sum in each iteration
 *    - Formula: Sum = n(n+1)/2
 * 3. For even numbers sum:
 *    - Initialize sum = 0
 *    - Loop from i = 2 to 2*n with step 2, OR
 *    - Loop from i = 1 to n and add 2*i
 *    - Formula: Sum = n(n+1)
 * 4. For odd numbers sum:
 *    - Initialize sum = 0
 *    - Loop from i = 1 to 2*n-1 with step 2, OR
 *    - Loop from i = 1 to n and add (2*i-1)
 *    - Formula: Sum = n²
 * 5. Demonstrate each using different loop types
 */

#include <stdio.h>

int main() {
   int n, i, sum;

   // Input
   printf("Enter the value of n: ");
   scanf("%d", &n);

   if (n <= 0) {
      printf("Error: n must be a positive integer!\n");
      return 1;
   }

   printf("\n========================================\n");
   printf("  Sum Calculations for n = %d\n", n);
   printf("========================================\n\n");

   // ===== NATURAL NUMBERS =====
   printf("--- 1. Sum of First %d NATURAL Numbers ---\n", n);
   printf("Natural numbers: 1, 2, 3, ..., %d\n\n", n);

   // Using FOR loop
   sum = 0;
   for (i = 1; i <= n; i++) {
      sum += i;
   }
   printf("Using FOR loop:      Sum = %d\n", sum);

   // Using WHILE loop
   sum = 0;
   i = 1;
   while (i <= n) {
      sum += i;
      i++;
   }
   printf("Using WHILE loop:    Sum = %d\n", sum);

   // Using DO-WHILE loop
   sum = 0;
   i = 1;
   do {
      sum += i;
      i++;
   } while (i <= n);
   printf("Using DO-WHILE loop: Sum = %d\n", sum);

   // Using formula
   printf("Using Formula:       Sum = n(n+1)/2 = %d\n\n", (n * (n + 1)) / 2);

   // ===== EVEN NUMBERS =====
   printf("--- 2. Sum of First %d EVEN Numbers ---\n", n);
   printf("Even numbers: 2, 4, 6, ..., %d\n\n", 2 * n);

   // Using FOR loop
   sum = 0;
   for (i = 1; i <= n; i++) {
      sum += 2 * i;
   }
   printf("Using FOR loop:      Sum = %d\n", sum);

   // Using WHILE loop
   sum = 0;
   i = 2;
   int count = 1;
   while (count <= n) {
      sum += i;
      i += 2;
      count++;
   }
   printf("Using WHILE loop:    Sum = %d\n", sum);

   // Using DO-WHILE loop
   sum = 0;
   i = 2;
   count = 1;
   do {
      sum += i;
      i += 2;
      count++;
   } while (count <= n);
   printf("Using DO-WHILE loop: Sum = %d\n", sum);

   // Using formula
   printf("Using Formula:       Sum = n(n+1) = %d\n\n", n * (n + 1));

   // ===== ODD NUMBERS =====
   printf("--- 3. Sum of First %d ODD Numbers ---\n", n);
   printf("Odd numbers: 1, 3, 5, ..., %d\n\n", 2 * n - 1);

   // Using FOR loop
   sum = 0;
   for (i = 1; i <= n; i++) {
      sum += 2 * i - 1;
   }
   printf("Using FOR loop:      Sum = %d\n", sum);

   // Using WHILE loop
   sum = 0;
   i = 1;
   count = 1;
   while (count <= n) {
      sum += i;
      i += 2;
      count++;
   }
   printf("Using WHILE loop:    Sum = %d\n", sum);

   // Using DO-WHILE loop
   sum = 0;
   i = 1;
   count = 1;
   do {
      sum += i;
      i += 2;
      count++;
   } while (count <= n);
   printf("Using DO-WHILE loop: Sum = %d\n", sum);

   // Using formula
   printf("Using Formula:       Sum = n² = %d\n\n", n * n);

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
 *   Sum Calculations for n = 5
 * ========================================
 *
 * --- 1. Sum of First 5 NATURAL Numbers ---
 * Natural numbers: 1, 2, 3, ..., 5
 *
 * Using FOR loop:      Sum = 15
 * Using WHILE loop:    Sum = 15
 * Using DO-WHILE loop: Sum = 15
 * Using Formula:       Sum = n(n+1)/2 = 15
 *
 * --- 2. Sum of First 5 EVEN Numbers ---
 * Even numbers: 2, 4, 6, ..., 10
 *
 * Using FOR loop:      Sum = 30
 * Using WHILE loop:    Sum = 30
 * Using DO-WHILE loop: Sum = 30
 * Using Formula:       Sum = n(n+1) = 30
 *
 * --- 3. Sum of First 5 ODD Numbers ---
 * Odd numbers: 1, 3, 5, ..., 9
 *
 * Using FOR loop:      Sum = 25
 * Using WHILE loop:    Sum = 25
 * Using DO-WHILE loop: Sum = 25
 * Using Formula:       Sum = n² = 25
 *
 * ========================================
 *
 * Example 2:
 * Input: n = 10
 * Output:
 * ========================================
 *   Sum Calculations for n = 10
 * ========================================
 *
 * --- 1. Sum of First 10 NATURAL Numbers ---
 * Natural numbers: 1, 2, 3, ..., 10
 *
 * Using FOR loop:      Sum = 55
 * Using WHILE loop:    Sum = 55
 * Using DO-WHILE loop: Sum = 55
 * Using Formula:       Sum = n(n+1)/2 = 55
 *
 * --- 2. Sum of First 10 EVEN Numbers ---
 * Even numbers: 2, 4, 6, ..., 20
 *
 * Using FOR loop:      Sum = 110
 * Using WHILE loop:    Sum = 110
 * Using DO-WHILE loop: Sum = 110
 * Using Formula:       Sum = n(n+1) = 110
 *
 * --- 3. Sum of First 10 ODD Numbers ---
 * Odd numbers: 1, 3, 5, ..., 19
 *
 * Using FOR loop:      Sum = 100
 * Using WHILE loop:    Sum = 100
 * Using DO-WHILE loop: Sum = 100
 * Using Formula:       Sum = n² = 100
 *
 * ========================================
 *
 * Example 3:
 * Input: n = 1
 * Output:
 * ========================================
 *   Sum Calculations for n = 1
 * ========================================
 *
 * --- 1. Sum of First 1 NATURAL Numbers ---
 * Natural numbers: 1, 2, 3, ..., 1
 *
 * Using FOR loop:      Sum = 1
 * Using WHILE loop:    Sum = 1
 * Using DO-WHILE loop: Sum = 1
 * Using Formula:       Sum = n(n+1)/2 = 1
 *
 * --- 2. Sum of First 1 EVEN Numbers ---
 * Even numbers: 2, 4, 6, ..., 2
 *
 * Using FOR loop:      Sum = 2
 * Using WHILE loop:    Sum = 2
 * Using DO-WHILE loop: Sum = 2
 * Using Formula:       Sum = n(n+1) = 2
 *
 * --- 3. Sum of First 1 ODD Numbers ---
 * Odd numbers: 1, 3, 5, ..., 1
 *
 * Using FOR loop:      Sum = 1
 * Using WHILE loop:    Sum = 1
 * Using DO-WHILE loop: Sum = 1
 * Using Formula:       Sum = n² = 1
 *
 * ========================================
 */
