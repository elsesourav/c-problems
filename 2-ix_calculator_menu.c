/*
 * QUESTION ix:
 * Write a C program to implement and display a menu to execute
 * 1. ADD, 2. SUBTRACT, 3. MULTIPLICATION, 4. DIVISION using switch case.
 *
 * PROGRAM DESCRIPTION:
 * This program creates a simple calculator with a menu-driven interface.
 * It displays a menu with 4 arithmetic operations (Add, Subtract, Multiply, Divide).
 * User selects an operation, enters two numbers, and the program performs
 * the selected operation using switch-case statement.
 *
 * HOW TO SOLVE:
 * 1. Display a menu with operation choices (1-4)
 * 2. Read user's choice
 * 3. Read two numbers from the user
 * 4. Use switch-case statement with choice as the selector:
 *    - case 1: Perform addition (num1 + num2)
 *    - case 2: Perform subtraction (num1 - num2)
 *    - case 3: Perform multiplication (num1 * num2)
 *    - case 4: Perform division (num1 / num2, check for divide by zero)
 *    - default: Invalid choice message
 * 5. Display the result
 * 6. Include error handling for division by zero
 */

#include <stdio.h>

int main() {
   int choice;
   float num1, num2, result;

   // Display menu
   printf("========================================\n");
   printf("       CALCULATOR MENU\n");
   printf("========================================\n");
   printf("1. ADD\n");
   printf("2. SUBTRACT\n");
   printf("3. MULTIPLICATION\n");
   printf("4. DIVISION\n");
   printf("========================================\n");
   printf("Enter your choice (1-4): ");
   scanf("%d", &choice);

   // Input two numbers
   printf("Enter first number: ");
   scanf("%f", &num1);
   printf("Enter second number: ");
   scanf("%f", &num2);

   printf("\n--- Calculation Result ---\n");

   // Perform operation using switch-case
   switch (choice) {
   case 1:
      result = num1 + num2;
      printf("Operation: ADDITION\n");
      printf("%.2f + %.2f = %.2f\n", num1, num2, result);
      break;

   case 2:
      result = num1 - num2;
      printf("Operation: SUBTRACTION\n");
      printf("%.2f - %.2f = %.2f\n", num1, num2, result);
      break;

   case 3:
      result = num1 * num2;
      printf("Operation: MULTIPLICATION\n");
      printf("%.2f × %.2f = %.2f\n", num1, num2, result);
      break;

   case 4:
      if (num2 == 0) {
         printf("Operation: DIVISION\n");
         printf("Error: Division by zero is not allowed!\n");
         return 1;
      }
      result = num1 / num2;
      printf("Operation: DIVISION\n");
      printf("%.2f ÷ %.2f = %.2f\n", num1, num2, result);
      break;

   default:
      printf("Error: Invalid choice!\n");
      printf("Please select a number between 1 and 4.\n");
      return 1;
   }

   printf("\nThank you for using the calculator!\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Choice: 1
 *   First number: 25
 *   Second number: 15
 * Output:
 * ========================================
 *        CALCULATOR MENU
 * ========================================
 * 1. ADD
 * 2. SUBTRACT
 * 3. MULTIPLICATION
 * 4. DIVISION
 * ========================================
 * Enter your choice (1-4): 1
 * Enter first number: 25
 * Enter second number: 15
 *
 * --- Calculation Result ---
 * Operation: ADDITION
 * 25.00 + 15.00 = 40.00
 *
 * Thank you for using the calculator!
 *
 * Example 2:
 * Input:
 *   Choice: 3
 *   First number: 7
 *   Second number: 8
 * Output:
 * ========================================
 *        CALCULATOR MENU
 * ========================================
 * 1. ADD
 * 2. SUBTRACT
 * 3. MULTIPLICATION
 * 4. DIVISION
 * ========================================
 * Enter your choice (1-4): 3
 * Enter first number: 7
 * Enter second number: 8
 *
 * --- Calculation Result ---
 * Operation: MULTIPLICATION
 * 7.00 × 8.00 = 56.00
 *
 * Thank you for using the calculator!
 *
 * Example 3:
 * Input:
 *   Choice: 4
 *   First number: 100
 *   Second number: 0
 * Output:
 * ========================================
 *        CALCULATOR MENU
 * ========================================
 * 1. ADD
 * 2. SUBTRACT
 * 3. MULTIPLICATION
 * 4. DIVISION
 * ========================================
 * Enter your choice (1-4): 4
 * Enter first number: 100
 * Enter second number: 0
 *
 * --- Calculation Result ---
 * Operation: DIVISION
 * Error: Division by zero is not allowed!
 */
