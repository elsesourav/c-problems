/*
 * QUESTION xix:
 * Write a C program to find all Armstrong numbers within 100 to 1000.
 *
 * PROGRAM DESCRIPTION:
 * An Armstrong number (also called Narcissistic number) is a number that is
 * equal to the sum of its own digits each raised to the power of the number
 * of digits.
 *
 * For 3-digit numbers (100-999):
 * A number ABC is Armstrong if: ABC = A³ + B³ + C³
 *
 * Examples:
 * - 153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ✓
 * - 370 = 3³ + 7³ + 0³ = 27 + 343 + 0 = 370 ✓
 * - 371 = 3³ + 7³ + 1³ = 27 + 343 + 1 = 371 ✓
 * - 407 = 4³ + 0³ + 7³ = 64 + 0 + 343 = 407 ✓
 *
 * HOW TO SOLVE:
 * 1. Loop through numbers from 100 to 999 (3-digit numbers)
 * 2. For each number:
 *    a. Extract individual digits
 *    b. Calculate sum of cubes of each digit
 *    c. Compare with original number
 *    d. If equal, it's an Armstrong number
 * 3. To extract digits:
 *    - Last digit: num % 10
 *    - Remove last digit: num / 10
 *    - Repeat until num becomes 0
 * 4. Display all Armstrong numbers found
 * 5. Show calculation details for verification
 */

#include <math.h>
#include <stdio.h>

// Function to count digits in a number
int countDigits(int num) {
   int count = 0;
   while (num != 0) {
      count++;
      num /= 10;
   }
   return count;
}

// Function to check if a number is Armstrong number
int isArmstrong(int num) {
   int originalNum = num;
   int digits = countDigits(num);
   int sum = 0;
   int remainder;

   while (num != 0) {
      remainder = num % 10;
      sum += pow(remainder, digits);
      num /= 10;
   }

   return (sum == originalNum);
}

// Function to display calculation for a number
void showCalculation(int num) {
   int originalNum = num;
   int digits = countDigits(num);
   int digit;
   int temp = num;

   printf("%d = ", originalNum);

   // Extract and display each digit's power
   int divisor = pow(10, digits - 1);
   for (int i = 0; i < digits; i++) {
      digit = temp / divisor;
      printf("%d^%d", digit, digits);

      if (i < digits - 1) {
         printf(" + ");
      }

      temp %= divisor;
      divisor /= 10;
   }

   // Calculate and display sum
   temp = originalNum;
   int sum = 0;
   printf(" = ");

   divisor = pow(10, digits - 1);
   for (int i = 0; i < digits; i++) {
      digit = temp / divisor;
      int power = pow(digit, digits);
      printf("%d", power);
      sum += power;

      if (i < digits - 1) {
         printf(" + ");
      }

      temp %= divisor;
      divisor /= 10;
   }

   printf(" = %d\n", sum);
}

int main() {
   int start = 100, end = 999;
   int count = 0;
   int i;

   printf("========================================\n");
   printf("  Armstrong Numbers (100 to 1000)\n");
   printf("========================================\n\n");

   printf("Definition: A number is Armstrong if it equals\n");
   printf("the sum of its digits raised to the power of\n");
   printf("the number of digits.\n\n");

   printf("For 3-digit numbers: ABC = A³ + B³ + C³\n\n");

   printf("========================================\n");
   printf("Searching for Armstrong numbers...\n");
   printf("========================================\n\n");

   // Find all Armstrong numbers in range
   for (i = start; i <= end; i++) {
      if (isArmstrong(i)) {
         count++;
         printf("Armstrong #%d: ", count);
         showCalculation(i);
         printf("\n");
      }
   }

   if (count == 0) {
      printf("No Armstrong numbers found in range %d to %d\n", start, end);
   }

   // Display summary
   printf("========================================\n");
   printf("SUMMARY:\n");
   printf("========================================\n");
   printf("Range searched:        %d to %d\n", start, end);
   printf("Total numbers checked: %d\n", end - start + 1);
   printf("Armstrong numbers:     %d\n", count);
   printf("========================================\n\n");

   // List all Armstrong numbers compactly
   if (count > 0) {
      printf("All Armstrong numbers in range:\n");
      printf("[ ");
      for (i = start; i <= end; i++) {
         if (isArmstrong(i)) {
            printf("%d ", i);
         }
      }
      printf("]\n\n");
   }

   // Additional information
   printf("========================================\n");
   printf("INTERESTING FACTS:\n");
   printf("========================================\n");
   printf("- Armstrong numbers are also called\n");
   printf("  Narcissistic numbers\n");
   printf("- Single digit numbers (0-9) are all\n");
   printf("  Armstrong numbers\n");
   printf("- There are only 4 Armstrong numbers\n");
   printf("  in the 3-digit range (100-999)\n");
   printf("- 1-digit: 0,1,2,3,4,5,6,7,8,9 (10 total)\n");
   printf("- 2-digit: None\n");
   printf("- 3-digit: 153, 370, 371, 407 (4 total)\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Output:
 * ========================================
 *   Armstrong Numbers (100 to 1000)
 * ========================================
 *
 * Definition: A number is Armstrong if it equals
 * the sum of its digits raised to the power of
 * the number of digits.
 *
 * For 3-digit numbers: ABC = A³ + B³ + C³
 *
 * ========================================
 * Searching for Armstrong numbers...
 * ========================================
 *
 * Armstrong #1: 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
 *
 * Armstrong #2: 370 = 3^3 + 7^3 + 0^3 = 27 + 343 + 0 = 370
 *
 * Armstrong #3: 371 = 3^3 + 7^3 + 1^3 = 27 + 343 + 1 = 371
 *
 * Armstrong #4: 407 = 4^3 + 0^3 + 7^3 = 64 + 0 + 343 = 407
 *
 * ========================================
 * SUMMARY:
 * ========================================
 * Range searched:        100 to 999
 * Total numbers checked: 900
 * Armstrong numbers:     4
 * ========================================
 *
 * All Armstrong numbers in range:
 * [ 153 370 371 407 ]
 *
 * ========================================
 * INTERESTING FACTS:
 * ========================================
 * - Armstrong numbers are also called
 *   Narcissistic numbers
 * - Single digit numbers (0-9) are all
 *   Armstrong numbers
 * - There are only 4 Armstrong numbers
 *   in the 3-digit range (100-999)
 * - 1-digit: 0,1,2,3,4,5,6,7,8,9 (10 total)
 * - 2-digit: None
 * - 3-digit: 153, 370, 371, 407 (4 total)
 * ========================================
 */
