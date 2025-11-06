/*
 * QUESTION xiv:
 * Write a C program to find GCD and LCM of two integral numbers.
 *
 * PROGRAM DESCRIPTION:
 * This program finds two important mathematical values for two integers:
 * - GCD (Greatest Common Divisor): Largest number that divides both numbers
 * - LCM (Least Common Multiple): Smallest number that is divisible by both
 *
 * The program uses Euclidean algorithm for GCD and the relationship:
 * LCM(a, b) = (a × b) / GCD(a, b)
 *
 * HOW TO SOLVE:
 * 1. Input two positive integers from the user
 * 2. For GCD, use Euclidean Algorithm:
 *    - Method 1: Repeatedly divide and take remainder
 *      while (b != 0) { temp = b; b = a % b; a = temp; }
 *      GCD is in 'a' when b becomes 0
 *    - Method 2: Subtraction method (slower)
 * 3. For LCM:
 *    - Use formula: LCM = (num1 × num2) / GCD
 *    - Store original values before finding GCD
 * 4. Display both GCD and LCM
 * 5. Optionally show the step-by-step calculation process
 */

#include <stdio.h>

int main() {
   int num1, num2, a, b, temp;
   int gcd, lcm;

   // Input two numbers
   printf("Enter first positive integer: ");
   scanf("%d", &num1);
   printf("Enter second positive integer: ");
   scanf("%d", &num2);

   if (num1 <= 0 || num2 <= 0) {
      printf("\nError: Both numbers must be positive integers!\n");
      return 1;
   }

   printf("\n========================================\n");
   printf("  GCD and LCM Calculator\n");
   printf("========================================\n");
   printf("Numbers: %d and %d\n\n", num1, num2);

   // Store original values
   a = num1;
   b = num2;

   // Calculate GCD using Euclidean Algorithm
   printf("--- Finding GCD (Euclidean Algorithm) ---\n");
   while (b != 0) {
      printf("GCD(%d, %d) -> ", a, b);
      temp = b;
      b = a % b;
      a = temp;
      if (b != 0) {
         printf("GCD(%d, %d)\n", a, b);
      }
   }
   gcd = a;
   printf("GCD = %d\n\n", gcd);

   // Calculate LCM using formula
   lcm = (num1 * num2) / gcd;

   printf("--- Finding LCM (Using Formula) ---\n");
   printf("LCM(a, b) = (a × b) / GCD(a, b)\n");
   printf("LCM(%d, %d) = (%d × %d) / %d\n", num1, num2, num1, num2, gcd);
   printf("LCM(%d, %d) = %d / %d\n", num1, num2, num1 * num2, gcd);
   printf("LCM = %d\n\n", lcm);

   // Display results
   printf("========================================\n");
   printf("RESULTS:\n");
   printf("========================================\n");
   printf("Numbers:          %d and %d\n", num1, num2);
   printf("GCD (HCF):        %d\n", gcd);
   printf("LCM:              %d\n", lcm);
   printf("========================================\n");

   // Verification
   printf("\nVerification:\n");
   printf("%d is divisible by %d: %d ÷ %d = %d\n", num1, gcd, num1, gcd, num1 / gcd);
   printf("%d is divisible by %d: %d ÷ %d = %d\n", num2, gcd, num2, gcd, num2 / gcd);
   printf("%d is divisible by %d: %d ÷ %d = %d\n", lcm, num1, lcm, num1, lcm / num1);
   printf("%d is divisible by %d: %d ÷ %d = %d\n", lcm, num2, lcm, num2, lcm / num2);

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   First number: 12
 *   Second number: 18
 * Output:
 * ========================================
 *   GCD and LCM Calculator
 * ========================================
 * Numbers: 12 and 18
 *
 * --- Finding GCD (Euclidean Algorithm) ---
 * GCD(12, 18) -> GCD(18, 12)
 * GCD(18, 12) -> GCD(12, 6)
 * GCD(12, 6) -> GCD = 6
 *
 * --- Finding LCM (Using Formula) ---
 * LCM(a, b) = (a × b) / GCD(a, b)
 * LCM(12, 18) = (12 × 18) / 6
 * LCM(12, 18) = 216 / 6
 * LCM = 36
 *
 * ========================================
 * RESULTS:
 * ========================================
 * Numbers:          12 and 18
 * GCD (HCF):        6
 * LCM:              36
 * ========================================
 *
 * Verification:
 * 12 is divisible by 6: 12 ÷ 6 = 2
 * 18 is divisible by 6: 18 ÷ 6 = 3
 * 36 is divisible by 12: 36 ÷ 12 = 3
 * 36 is divisible by 18: 36 ÷ 18 = 2
 *
 * Example 2:
 * Input:
 *   First number: 48
 *   Second number: 18
 * Output:
 * ========================================
 *   GCD and LCM Calculator
 * ========================================
 * Numbers: 48 and 18
 *
 * --- Finding GCD (Euclidean Algorithm) ---
 * GCD(48, 18) -> GCD(18, 12)
 * GCD(18, 12) -> GCD(12, 6)
 * GCD(12, 6) -> GCD = 6
 *
 * --- Finding LCM (Using Formula) ---
 * LCM(a, b) = (a × b) / GCD(a, b)
 * LCM(48, 18) = (48 × 18) / 6
 * LCM(48, 18) = 864 / 6
 * LCM = 144
 *
 * ========================================
 * RESULTS:
 * ========================================
 * Numbers:          48 and 18
 * GCD (HCF):        6
 * LCM:              144
 * ========================================
 *
 * Verification:
 * 48 is divisible by 6: 48 ÷ 6 = 8
 * 18 is divisible by 6: 18 ÷ 6 = 3
 * 144 is divisible by 48: 144 ÷ 48 = 3
 * 144 is divisible by 18: 144 ÷ 18 = 8
 *
 * Example 3:
 * Input:
 *   First number: 7
 *   Second number: 13
 * Output:
 * ========================================
 *   GCD and LCM Calculator
 * ========================================
 * Numbers: 7 and 13
 *
 * --- Finding GCD (Euclidean Algorithm) ---
 * GCD(7, 13) -> GCD(13, 7)
 * GCD(13, 7) -> GCD(7, 6)
 * GCD(7, 6) -> GCD(6, 1)
 * GCD(6, 1) -> GCD = 1
 *
 * --- Finding LCM (Using Formula) ---
 * LCM(a, b) = (a × b) / GCD(a, b)
 * LCM(7, 13) = (7 × 13) / 1
 * LCM(7, 13) = 91 / 1
 * LCM = 91
 *
 * ========================================
 * RESULTS:
 * ========================================
 * Numbers:          7 and 13
 * GCD (HCF):        1
 * LCM:              91
 * ========================================
 *
 * Verification:
 * 7 is divisible by 1: 7 ÷ 1 = 7
 * 13 is divisible by 1: 13 ÷ 1 = 13
 * 91 is divisible by 7: 91 ÷ 7 = 13
 * 91 is divisible by 13: 91 ÷ 13 = 7
 */
