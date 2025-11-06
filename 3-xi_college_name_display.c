/*
 * QUESTION xi:
 * Write a C program to display our College name twenty times on screen.
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates the use of loops to display repetitive output.
 * It prints a college name (or any text) exactly 20 times on the screen.
 * This can be achieved using different types of loops: for, while, or do-while.
 *
 * HOW TO SOLVE:
 * 1. Define the college name as a string (can be hardcoded or input)
 * 2. Use a loop structure to iterate 20 times:
 *    - For loop: Initialize counter to 1, condition i <= 20, increment i++
 *    - While loop: Initialize counter before loop, check condition, increment inside
 *    - Do-while loop: Same as while but executes at least once
 * 3. Inside the loop, print the college name with iteration number
 * 4. Display all three implementations for comparison
 */

#include <stdio.h>

int main() {
   char collegeName[] = "ABC College of Engineering";
   int i;

   printf("========================================\n");
   printf("  College Name Display Program\n");
   printf("========================================\n\n");

   // Method 1: Using for loop
   printf("--- Method 1: Using FOR LOOP ---\n");
   for (i = 1; i <= 20; i++) {
      printf("%2d. %s\n", i, collegeName);
   }

   printf("\n--- Method 2: Using WHILE LOOP ---\n");
   i = 1;
   while (i <= 20) {
      printf("%2d. %s\n", i, collegeName);
      i++;
   }

   printf("\n--- Method 3: Using DO-WHILE LOOP ---\n");
   i = 1;
   do {
      printf("%2d. %s\n", i, collegeName);
      i++;
   } while (i <= 20);

   printf("\n========================================\n");
   printf("College name displayed 20 times!\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Output:
 * ========================================
 *   College Name Display Program
 * ========================================
 *
 * --- Method 1: Using FOR LOOP ---
 *  1. ABC College of Engineering
 *  2. ABC College of Engineering
 *  3. ABC College of Engineering
 *  4. ABC College of Engineering
 *  5. ABC College of Engineering
 *  6. ABC College of Engineering
 *  7. ABC College of Engineering
 *  8. ABC College of Engineering
 *  9. ABC College of Engineering
 * 10. ABC College of Engineering
 * 11. ABC College of Engineering
 * 12. ABC College of Engineering
 * 13. ABC College of Engineering
 * 14. ABC College of Engineering
 * 15. ABC College of Engineering
 * 16. ABC College of Engineering
 * 17. ABC College of Engineering
 * 18. ABC College of Engineering
 * 19. ABC College of Engineering
 * 20. ABC College of Engineering
 *
 * --- Method 2: Using WHILE LOOP ---
 *  1. ABC College of Engineering
 *  2. ABC College of Engineering
 *  ... (same as above)
 * 20. ABC College of Engineering
 *
 * --- Method 3: Using DO-WHILE LOOP ---
 *  1. ABC College of Engineering
 *  2. ABC College of Engineering
 *  ... (same as above)
 * 20. ABC College of Engineering
 *
 * ========================================
 * College name displayed 20 times!
 * ========================================
 */
