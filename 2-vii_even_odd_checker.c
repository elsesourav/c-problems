/*
 * QUESTION vii:
 * Write a C program to find whether a number is even or odd.
 *
 * PROGRAM DESCRIPTION:
 * This program takes an integer as input and determines whether it is
 * an even number or an odd number. A number is even if it is divisible
 * by 2 (remainder is 0), otherwise it is odd.
 *
 * HOW TO SOLVE:
 * 1. Declare an integer variable to store the number
 * 2. Read the number from user input
 * 3. Use modulus operator (%) to find remainder when divided by 2:
 *    - If number % 2 == 0, the number is EVEN
 *    - If number % 2 != 0 (or == 1), the number is ODD
 * 4. Use if-else statement to check the condition
 * 5. Display whether the number is even or odd
 * 6. Note: Works for negative numbers too (same logic applies)
 */

#include <stdio.h>

int main() {
   int number;

   // Input number
   printf("Enter an integer number: ");
   scanf("%d", &number);

   // Check if even or odd using modulus operator
   printf("\n--- Even/Odd Checker ---\n");
   printf("Number entered: %d\n", number);

   if (number % 2 == 0) {
      printf("Result: %d is an EVEN number.\n", number);
      printf("Explanation: %d is divisible by 2 (remainder = 0)\n", number);
   } else {
      printf("Result: %d is an ODD number.\n", number);
      printf("Explanation: %d is not divisible by 2 (remainder = 1)\n", number);
   }

   // Additional information
   printf("\nMathematical Info:\n");
   printf("%d ÷ 2 = %d (quotient), remainder = %d\n", number, number / 2, number % 2);

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: 10
 * Output:
 * --- Even/Odd Checker ---
 * Number entered: 10
 * Result: 10 is an EVEN number.
 * Explanation: 10 is divisible by 2 (remainder = 0)
 *
 * Mathematical Info:
 * 10 ÷ 2 = 5 (quotient), remainder = 0
 *
 * Example 2:
 * Input: 7
 * Output:
 * --- Even/Odd Checker ---
 * Number entered: 7
 * Result: 7 is an ODD number.
 * Explanation: 7 is not divisible by 2 (remainder = 1)
 *
 * Mathematical Info:
 * 7 ÷ 2 = 3 (quotient), remainder = 1
 *
 * Example 3:
 * Input: -15
 * Output:
 * --- Even/Odd Checker ---
 * Number entered: -15
 * Result: -15 is an ODD number.
 * Explanation: -15 is not divisible by 2 (remainder = 1)
 *
 * Mathematical Info:
 * -15 ÷ 2 = -7 (quotient), remainder = -1
 */
