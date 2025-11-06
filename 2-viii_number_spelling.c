/*
 * QUESTION viii:
 * Write a C program to display spellings of numbers 1-10 on entry.
 *
 * PROGRAM DESCRIPTION:
 * This program takes a number (1-10) as input from the user and displays
 * its spelling in words. For example, if user enters 5, it displays "Five".
 * If the number is outside the range 1-10, it shows an error message.
 *
 * HOW TO SOLVE:
 * 1. Declare an integer variable to store the number
 * 2. Read the number from user input
 * 3. Use switch-case statement to match the number:
 *    - Create cases for 1 to 10
 *    - Each case prints the corresponding spelling
 *    - Include a default case for invalid input
 * 4. Alternative: Can use if-else ladder instead of switch
 * 5. Display the spelling or error message
 */

#include <stdio.h>

int main() {
   int number;

   // Input number
   printf("Enter a number (1-10): ");
   scanf("%d", &number);

   printf("\n--- Number to Spelling Converter ---\n");
   printf("Number entered: %d\n", number);
   printf("Spelling: ", number);

   // Using switch-case to display spelling
   switch (number) {
   case 1:
      printf("One\n");
      break;
   case 2:
      printf("Two\n");
      break;
   case 3:
      printf("Three\n");
      break;
   case 4:
      printf("Four\n");
      break;
   case 5:
      printf("Five\n");
      break;
   case 6:
      printf("Six\n");
      break;
   case 7:
      printf("Seven\n");
      break;
   case 8:
      printf("Eight\n");
      break;
   case 9:
      printf("Nine\n");
      break;
   case 10:
      printf("Ten\n");
      break;
   default:
      printf("Invalid!\n");
      printf("\nError: Please enter a number between 1 and 10 only.\n");
      return 1;
   }

   printf("\nThank you for using the spelling converter!\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: 5
 * Output:
 * --- Number to Spelling Converter ---
 * Number entered: 5
 * Spelling: Five
 *
 * Thank you for using the spelling converter!
 *
 * Example 2:
 * Input: 10
 * Output:
 * --- Number to Spelling Converter ---
 * Number entered: 10
 * Spelling: Ten
 *
 * Thank you for using the spelling converter!
 *
 * Example 3:
 * Input: 15
 * Output:
 * --- Number to Spelling Converter ---
 * Number entered: 15
 * Spelling: Invalid!
 *
 * Error: Please enter a number between 1 and 10 only.
 */
