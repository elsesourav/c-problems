/*
 * QUESTION xii:
 * Write a C program to demonstrate Continue and Break statements within loop structure.
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates two important loop control statements:
 * - BREAK: Exits the loop immediately when encountered
 * - CONTINUE: Skips the current iteration and moves to the next one
 * The program shows practical examples of both statements in different scenarios.
 *
 * HOW TO SOLVE:
 * 1. For BREAK demonstration:
 *    - Create a loop that runs from 1 to N
 *    - Use if condition to check a specific value
 *    - When condition is met, use break to exit the loop
 *    - Show that remaining iterations are skipped
 * 2. For CONTINUE demonstration:
 *    - Create a loop that runs from 1 to N
 *    - Use if condition to check certain values
 *    - When condition is met, use continue to skip that iteration
 *    - Show that loop continues with next iteration
 * 3. Provide practical examples like skipping even/odd numbers
 */

#include <stdio.h>

int main() {
   int i;

   printf("========================================\n");
   printf("  BREAK and CONTINUE Demonstration\n");
   printf("========================================\n\n");

   // Demonstration 1: BREAK statement
   printf("--- Example 1: BREAK Statement ---\n");
   printf("Print numbers 1-10, but STOP at 6\n\n");

   for (i = 1; i <= 10; i++) {
      if (i == 6) {
         printf("   [BREAK encountered at i = %d]\n", i);
         break; // Exit loop when i equals 6
      }
      printf("Number: %d\n", i);
   }
   printf("Loop terminated. Final value: i = %d\n\n", i);

   // Demonstration 2: CONTINUE statement
   printf("--- Example 2: CONTINUE Statement ---\n");
   printf("Print numbers 1-10, but SKIP multiples of 3\n\n");

   for (i = 1; i <= 10; i++) {
      if (i % 3 == 0) {
         printf("   [CONTINUE: Skipping %d (multiple of 3)]\n", i);
         continue; // Skip this iteration
      }
      printf("Number: %d\n", i);
   }
   printf("\n");

   // Demonstration 3: Print only ODD numbers using CONTINUE
   printf("--- Example 3: Print Only ODD Numbers ---\n");
   printf("Range: 1-15 (skip even numbers using CONTINUE)\n\n");

   for (i = 1; i <= 15; i++) {
      if (i % 2 == 0) {
         continue; // Skip even numbers
      }
      printf("%d ", i);
   }
   printf("\n\n");

   // Demonstration 4: Search and BREAK
   printf("--- Example 4: Search for Number ---\n");
   printf("Search for number 7 in range 1-20\n\n");

   int searchNum = 7;
   for (i = 1; i <= 20; i++) {
      printf("Checking: %d... ", i);
      if (i == searchNum) {
         printf("FOUND!\n");
         printf("   [Breaking the loop]\n");
         break;
      }
      printf("Not found\n");
   }
   printf("\n");

   // Demonstration 5: Combined BREAK and CONTINUE
   printf("--- Example 5: Combined Usage ---\n");
   printf("Print numbers 1-20, skip multiples of 4, stop at 17\n\n");

   for (i = 1; i <= 20; i++) {
      if (i == 17) {
         printf("   [BREAK at %d]\n", i);
         break;
      }
      if (i % 4 == 0) {
         printf("   [SKIP %d]\n", i);
         continue;
      }
      printf("%d ", i);
   }

   printf("\n\n========================================\n");
   printf("Demonstration completed!\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Output:
 * ========================================
 *   BREAK and CONTINUE Demonstration
 * ========================================
 *
 * --- Example 1: BREAK Statement ---
 * Print numbers 1-10, but STOP at 6
 *
 * Number: 1
 * Number: 2
 * Number: 3
 * Number: 4
 * Number: 5
 *    [BREAK encountered at i = 6]
 * Loop terminated. Final value: i = 6
 *
 * --- Example 2: CONTINUE Statement ---
 * Print numbers 1-10, but SKIP multiples of 3
 *
 * Number: 1
 * Number: 2
 *    [CONTINUE: Skipping 3 (multiple of 3)]
 * Number: 4
 * Number: 5
 *    [CONTINUE: Skipping 6 (multiple of 3)]
 * Number: 7
 * Number: 8
 *    [CONTINUE: Skipping 9 (multiple of 3)]
 * Number: 10
 *
 * --- Example 3: Print Only ODD Numbers ---
 * Range: 1-15 (skip even numbers using CONTINUE)
 *
 * 1 3 5 7 9 11 13 15
 *
 * --- Example 4: Search for Number ---
 * Search for number 7 in range 1-20
 *
 * Checking: 1... Not found
 * Checking: 2... Not found
 * Checking: 3... Not found
 * Checking: 4... Not found
 * Checking: 5... Not found
 * Checking: 6... Not found
 * Checking: 7... FOUND!
 *    [Breaking the loop]
 *
 * --- Example 5: Combined Usage ---
 * Print numbers 1-20, skip multiples of 4, stop at 17
 *
 * 1 2 3    [SKIP 4]
 * 5 6 7    [SKIP 8]
 * 9 10 11    [SKIP 12]
 * 13 14 15    [SKIP 16]
 *    [BREAK at 17]
 *
 * ========================================
 * Demonstration completed!
 * ========================================
 */
