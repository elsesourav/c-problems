/*
 * QUESTION x:
 * Write a C program to check whether there exist real roots of a quadratic
 * equation and if they exist, find them.
 *
 * PROGRAM DESCRIPTION:
 * This program solves a quadratic equation of the form ax² + bx + c = 0.
 * It first checks if real roots exist by calculating the discriminant (D = b² - 4ac).
 * - If D > 0: Two distinct real roots exist
 * - If D = 0: Two equal real roots exist (one repeated root)
 * - If D < 0: No real roots exist (complex/imaginary roots)
 * If real roots exist, it calculates them using the quadratic formula.
 *
 * HOW TO SOLVE:
 * 1. Input coefficients a, b, and c from the user
 * 2. Check if a != 0 (otherwise it's not a quadratic equation)
 * 3. Calculate discriminant: D = b² - 4ac
 * 4. Use if-else to check discriminant value:
 *    - If D > 0: Calculate two roots using formula:
 *      root1 = (-b + √D) / (2a)
 *      root2 = (-b - √D) / (2a)
 *    - If D = 0: Calculate single root: root = -b / (2a)
 *    - If D < 0: Display that no real roots exist
 * 5. Use sqrt() function from math.h library to calculate square root
 * 6. Display the results with appropriate messages
 */

#include <math.h>
#include <stdio.h>

int main() {
   float a, b, c;
   float discriminant, root1, root2, realPart, imagPart;

   // Input coefficients
   printf("Quadratic Equation: ax² + bx + c = 0\n");
   printf("========================================\n");
   printf("Enter coefficient a: ");
   scanf("%f", &a);
   printf("Enter coefficient b: ");
   scanf("%f", &b);
   printf("Enter coefficient c: ");
   scanf("%f", &c);

   // Check if it's a valid quadratic equation
   if (a == 0) {
      printf("\nError: 'a' cannot be zero for a quadratic equation!\n");
      printf("This is a linear equation, not quadratic.\n");
      return 1;
   }

   printf("\n--- Equation Analysis ---\n");
   printf("Equation: %.2fx² + %.2fx + %.2f = 0\n", a, b, c);

   // Calculate discriminant
   discriminant = (b * b) - (4 * a * c);
   printf("Discriminant (D) = b² - 4ac\n");
   printf("D = (%.2f)² - 4(%.2f)(%.2f)\n", b, a, c);
   printf("D = %.2f\n\n", discriminant);

   // Check nature of roots based on discriminant
   if (discriminant > 0) {
      // Two distinct real roots
      printf("Nature: Two DISTINCT REAL roots exist (D > 0)\n\n");

      root1 = (-b + sqrt(discriminant)) / (2 * a);
      root2 = (-b - sqrt(discriminant)) / (2 * a);

      printf("--- Roots ---\n");
      printf("Root 1 = (-b + √D) / 2a = %.2f\n", root1);
      printf("Root 2 = (-b - √D) / 2a = %.2f\n", root2);

   } else if (discriminant == 0) {
      // Two equal real roots
      printf("Nature: Two EQUAL REAL roots exist (D = 0)\n\n");

      root1 = -b / (2 * a);

      printf("--- Roots ---\n");
      printf("Root 1 = Root 2 = -b / 2a = %.2f\n", root1);

   } else {
      // Complex roots (no real roots)
      printf("Nature: NO REAL roots exist (D < 0)\n");
      printf("The equation has COMPLEX/IMAGINARY roots.\n\n");

      realPart = -b / (2 * a);
      imagPart = sqrt(-discriminant) / (2 * a);

      printf("--- Complex Roots ---\n");
      printf("Root 1 = %.2f + %.2fi\n", realPart, imagPart);
      printf("Root 2 = %.2f - %.2fi\n", realPart, imagPart);
   }

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1: (Two distinct real roots)
 * Input:
 *   a = 1
 *   b = -5
 *   c = 6
 * Output:
 * Quadratic Equation: ax² + bx + c = 0
 * ========================================
 * Enter coefficient a: 1
 * Enter coefficient b: -5
 * Enter coefficient c: 6
 *
 * --- Equation Analysis ---
 * Equation: 1.00x² + -5.00x + 6.00 = 0
 * Discriminant (D) = b² - 4ac
 * D = (-5.00)² - 4(1.00)(6.00)
 * D = 1.00
 *
 * Nature: Two DISTINCT REAL roots exist (D > 0)
 *
 * --- Roots ---
 * Root 1 = (-b + √D) / 2a = 3.00
 * Root 2 = (-b - √D) / 2a = 2.00
 *
 * Example 2: (Two equal real roots)
 * Input:
 *   a = 1
 *   b = -4
 *   c = 4
 * Output:
 * Quadratic Equation: ax² + bx + c = 0
 * ========================================
 * Enter coefficient a: 1
 * Enter coefficient b: -4
 * Enter coefficient c: 4
 *
 * --- Equation Analysis ---
 * Equation: 1.00x² + -4.00x + 4.00 = 0
 * Discriminant (D) = b² - 4ac
 * D = (-4.00)² - 4(1.00)(4.00)
 * D = 0.00
 *
 * Nature: Two EQUAL REAL roots exist (D = 0)
 *
 * --- Roots ---
 * Root 1 = Root 2 = -b / 2a = 2.00
 *
 * Example 3: (No real roots)
 * Input:
 *   a = 1
 *   b = 2
 *   c = 5
 * Output:
 * Quadratic Equation: ax² + bx + c = 0
 * ========================================
 * Enter coefficient a: 1
 * Enter coefficient b: 2
 * Enter coefficient c: 5
 *
 * --- Equation Analysis ---
 * Equation: 1.00x² + 2.00x + 5.00 = 0
 * Discriminant (D) = b² - 4ac
 * D = (2.00)² - 4(1.00)(5.00)
 * D = -16.00
 *
 * Nature: NO REAL roots exist (D < 0)
 * The equation has COMPLEX/IMAGINARY roots.
 *
 * --- Complex Roots ---
 * Root 1 = -1.00 + 2.00i
 * Root 2 = -1.00 - 2.00i
 */
