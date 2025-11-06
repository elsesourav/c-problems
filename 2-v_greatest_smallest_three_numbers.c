/*
 * QUESTION v:
 * Write a C program to find the greatest and smallest of three numbers.
 *
 * PROGRAM DESCRIPTION:
 * This program takes three numbers as input from the user and determines
 * which number is the greatest (maximum) and which is the smallest (minimum)
 * among them. It uses conditional statements (if-else) to compare the numbers.
 *
 * HOW TO SOLVE:
 * 1. Declare three variables to store the input numbers
 * 2. Read three numbers from the user
 * 3. Use nested if-else statements or logical operators to compare:
 *    - For greatest: Compare each number with others using > operator
 *    - For smallest: Compare each number with others using < operator
 * 4. Alternative approach: Use ternary operator (? :) for compact code
 * 5. Display the greatest and smallest numbers
 */

#include <stdio.h>

int main() {
   float num1, num2, num3;
   float greatest, smallest;

   // Input three numbers
   printf("Enter three numbers: ");
   scanf("%f %f %f", &num1, &num2, &num3);

   // Method 1: Using if-else statements to find greatest
   if (num1 >= num2 && num1 >= num3) {
      greatest = num1;
   } else if (num2 >= num1 && num2 >= num3) {
      greatest = num2;
   } else {
      greatest = num3;
   }

   // Using if-else statements to find smallest
   if (num1 <= num2 && num1 <= num3) {
      smallest = num1;
   } else if (num2 <= num1 && num2 <= num3) {
      smallest = num2;
   } else {
      smallest = num3;
   }

   printf("\n--- Results ---\n");
   printf("Numbers entered: %.2f, %.2f, %.2f\n", num1, num2, num3);
   printf("Greatest number: %.2f\n", greatest);
   printf("Smallest number: %.2f\n", smallest);
   printf("Difference: %.2f\n", greatest - smallest);

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: 25 10 30
 * Output:
 * --- Results ---
 * Numbers entered: 25.00, 10.00, 30.00
 * Greatest number: 30.00
 * Smallest number: 10.00
 * Difference: 20.00
 *
 * Example 2:
 * Input: 5.5 5.5 5.5
 * Output:
 * --- Results ---
 * Numbers entered: 5.50, 5.50, 5.50
 * Greatest number: 5.50
 * Smallest number: 5.50
 * Difference: 0.00
 *
 * Example 3:
 * Input: -10 20 -5
 * Output:
 * --- Results ---
 * Numbers entered: -10.00, 20.00, -5.00
 * Greatest number: 20.00
 * Smallest number: -10.00
 * Difference: 30.00
 */
