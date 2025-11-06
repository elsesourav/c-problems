/*
 * QUESTION xviii:
 * Write a C program to generate all prime numbers within a given range.
 *
 * PROGRAM DESCRIPTION:
 * A prime number is a natural number greater than 1 that has no positive
 * divisors other than 1 and itself. This program finds all prime numbers
 * between a given starting and ending range.
 *
 * Examples: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37...
 * Note: 2 is the only even prime number.
 *
 * HOW TO SOLVE:
 * 1. Input the range: start and end values
 * 2. For each number in the range:
 *    a. Check if number <= 1 (not prime)
 *    b. Check if number == 2 (prime)
 *    c. Check if number is even (not prime, except 2)
 *    d. For odd numbers, check divisibility from 3 to √n
 *       - Only check odd divisors (3, 5, 7, ...)
 *       - If divisible by any, it's not prime
 *       - If not divisible by any, it's prime
 * 3. Optimization: Only check up to square root of number
 * 4. Display all prime numbers found
 * 5. Count and display total number of primes
 */

#include <math.h>
#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
   if (num <= 1) {
      return 0; // Not prime
   }
   if (num == 2) {
      return 1; // 2 is prime
   }
   if (num % 2 == 0) {
      return 0; // Even numbers (except 2) are not prime
   }

   // Check odd divisors from 3 to sqrt(num)
   int limit = sqrt(num);
   for (int i = 3; i <= limit; i += 2) {
      if (num % i == 0) {
         return 0; // Found a divisor, not prime
      }
   }

   return 1; // Prime number
}

int main() {
   int start, end, count = 0;
   int i, col = 0;

   // Input range
   printf("Enter the starting range: ");
   scanf("%d", &start);
   printf("Enter the ending range: ");
   scanf("%d", &end);

   if (start > end) {
      printf("\nError: Starting range must be less than or equal to ending range!\n");
      return 1;
   }

   if (start < 0) {
      printf("\nNote: Prime numbers are positive. Starting from 2.\n");
      start = 2;
   }

   printf("\n========================================\n");
   printf("  Prime Numbers from %d to %d\n", start, end);
   printf("========================================\n\n");

   // Find and display prime numbers
   printf("Prime numbers in the range:\n");
   printf("----------------------------------------\n");

   for (i = start; i <= end; i++) {
      if (isPrime(i)) {
         printf("%6d", i);
         count++;
         col++;

         // Print 10 numbers per row
         if (col % 10 == 0) {
            printf("\n");
         }
      }
   }

   if (col % 10 != 0) {
      printf("\n");
   }

   printf("----------------------------------------\n\n");

   // Statistics
   printf("========================================\n");
   printf("STATISTICS:\n");
   printf("========================================\n");
   printf("Range:              %d to %d\n", start, end);
   printf("Total numbers:      %d\n", end - start + 1);
   printf("Prime numbers:      %d\n", count);
   printf("Composite numbers:  %d\n", (end - start + 1) - count);

   if (count > 0) {
      printf("\nFirst prime:        ");
      for (i = start; i <= end; i++) {
         if (isPrime(i)) {
            printf("%d\n", i);
            break;
         }
      }

      printf("Last prime:         ");
      for (i = end; i >= start; i--) {
         if (isPrime(i)) {
            printf("%d\n", i);
            break;
         }
      }
   }

   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Starting range: 1
 *   Ending range: 50
 * Output:
 * ========================================
 *   Prime Numbers from 1 to 50
 * ========================================
 *
 * Prime numbers in the range:
 * ----------------------------------------
 *      2     3     5     7    11    13    17    19    23    29
 *     31    37    41    43    47
 * ----------------------------------------
 *
 * ========================================
 * STATISTICS:
 * ========================================
 * Range:              1 to 50
 * Total numbers:      50
 * Prime numbers:      15
 * Composite numbers:  35
 *
 * First prime:        2
 * Last prime:         47
 * ========================================
 *
 * Example 2:
 * Input:
 *   Starting range: 100
 *   Ending range: 200
 * Output:
 * ========================================
 *   Prime Numbers from 100 to 200
 * ========================================
 *
 * Prime numbers in the range:
 * ----------------------------------------
 *    101   103   107   109   113   127   131   137   139   149
 *    151   157   163   167   173   179   181   191   193   197
 *    199
 * ----------------------------------------
 *
 * ========================================
 * STATISTICS:
 * ========================================
 * Range:              100 to 200
 * Total numbers:      101
 * Prime numbers:      21
 * Composite numbers:  80
 *
 * First prime:        101
 * Last prime:         199
 * ========================================
 *
 * Example 3:
 * Input:
 *   Starting range: 10
 *   Ending range: 30
 * Output:
 * ========================================
 *   Prime Numbers from 10 to 30
 * ========================================
 *
 * Prime numbers in the range:
 * ----------------------------------------
 *     11    13    17    19    23    29
 * ----------------------------------------
 *
 * ========================================
 * STATISTICS:
 * ========================================
 * Range:              10 to 30
 * Total numbers:      21
 * Prime numbers:      6
 * Composite numbers:  15
 *
 * First prime:        11
 * Last prime:         29
 * ========================================
 */
