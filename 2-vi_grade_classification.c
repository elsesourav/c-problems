/*
 * QUESTION vi:
 * Write a C program to display pass class, second class, or distinction
 * according to the marks entered from the keyboard.
 *
 * PROGRAM DESCRIPTION:
 * This program takes marks as input and classifies the result into different
 * categories based on the marks obtained:
 * - Distinction: Marks >= 75
 * - First Class: Marks >= 60 and < 75
 * - Second Class: Marks >= 50 and < 60
 * - Pass Class: Marks >= 40 and < 50
 * - Fail: Marks < 40
 *
 * HOW TO SOLVE:
 * 1. Declare a variable to store marks (integer or float)
 * 2. Read marks from the user
 * 3. Validate that marks are in valid range (0-100)
 * 4. Use if-else ladder to check marks range and classify:
 *    - Start from highest category (Distinction)
 *    - Use else-if for other categories in descending order
 * 5. Display the appropriate classification message
 */

#include <stdio.h>

int main() {
   float marks;

   // Input marks
   printf("Enter marks obtained (0-100): ");
   scanf("%f", &marks);

   // Validate marks range
   if (marks < 0 || marks > 100) {
      printf("\nError: Invalid marks! Marks should be between 0 and 100.\n");
      return 1;
   }

   // Classification based on marks
   printf("\n--- Result Classification ---\n");
   printf("Marks obtained: %.2f\n", marks);

   if (marks >= 75) {
      printf("Grade: DISTINCTION\n");
      printf("Performance: Excellent! Outstanding achievement.\n");
   } else if (marks >= 60) {
      printf("Grade: FIRST CLASS\n");
      printf("Performance: Very Good! Keep up the good work.\n");
   } else if (marks >= 50) {
      printf("Grade: SECOND CLASS\n");
      printf("Performance: Good! There's room for improvement.\n");
   } else if (marks >= 40) {
      printf("Grade: PASS CLASS\n");
      printf("Performance: Passed! Work harder next time.\n");
   } else {
      printf("Grade: FAIL\n");
      printf("Performance: Failed! Need to study more.\n");
   }

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: 85
 * Output:
 * --- Result Classification ---
 * Marks obtained: 85.00
 * Grade: DISTINCTION
 * Performance: Excellent! Outstanding achievement.
 *
 * Example 2:
 * Input: 65
 * Output:
 * --- Result Classification ---
 * Marks obtained: 65.00
 * Grade: FIRST CLASS
 * Performance: Very Good! Keep up the good work.
 *
 * Example 3:
 * Input: 52
 * Output:
 * --- Result Classification ---
 * Marks obtained: 52.00
 * Grade: SECOND CLASS
 * Performance: Good! There's room for improvement.
 *
 * Example 4:
 * Input: 42
 * Output:
 * --- Result Classification ---
 * Marks obtained: 42.00
 * Grade: PASS CLASS
 * Performance: Passed! Work harder next time.
 *
 * Example 5:
 * Input: 35
 * Output:
 * --- Result Classification ---
 * Marks obtained: 35.00
 * Grade: FAIL
 * Performance: Failed! Need to study more.
 */
