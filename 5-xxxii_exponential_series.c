/*
 * QUESTION xxxii:
 * Write a C program to find the sum of the series:
 * 1 + (x/1!) + (x²/2!) + … + (xⁿ/n!) for n ≥ 1, x ≥ 0 using function.
 *
 * PROGRAM DESCRIPTION:
 * This program calculates the exponential series (Taylor series for e^x):
 *
 * e^x = 1 + x/1! + x²/2! + x³/3! + ... + xⁿ/n!
 *
 * This is the Taylor series expansion of the exponential function.
 * For example:
 * - e^1 ≈ 1 + 1 + 0.5 + 0.167 + ... = 2.71828...
 * - e^2 ≈ 1 + 2 + 2 + 1.333 + ... = 7.38906...
 *
 * The program uses functions to:
 * 1. Calculate factorial
 * 2. Calculate power (x^n)
 * 3. Calculate each term of series
 * 4. Sum the series up to n terms
 *
 * HOW TO SOLVE:
 * 1. Create function to calculate factorial
 * 2. Create function to calculate power (x^n)
 * 3. Create function to calculate a term: x^i / i!
 * 4. Create function to sum the series
 * 5. Input x and n from user
 * 6. Calculate sum = 1 + x/1! + x²/2! + ... + xⁿ/n!
 * 7. Display each term and running sum
 * 8. Compare with actual e^x value using math.h
 */

#include <math.h>
#include <stdio.h>

// Function to calculate factorial
unsigned long long factorial(int num) {
   if (num == 0 || num == 1) {
      return 1;
   }
   unsigned long long fact = 1;
   for (int i = 2; i <= num; i++) {
      fact *= i;
   }
   return fact;
}

// Function to calculate power (base^exponent)
double power(double base, int exponent) {
   if (exponent == 0) {
      return 1.0;
   }
   double result = 1.0;
   for (int i = 0; i < exponent; i++) {
      result *= base;
   }
   return result;
}

// Function to calculate a single term: x^i / i!
double calculateTerm(double x, int i) {
   if (i == 0) {
      return 1.0;
   }
   return power(x, i) / factorial(i);
}

// Function to calculate sum of the series
double exponentialSeries(double x, int n) {
   double sum = 0.0;
   for (int i = 0; i <= n; i++) {
      sum += calculateTerm(x, i);
   }
   return sum;
}

// Optimized function to avoid recalculating powers and factorials
double exponentialSeriesOptimized(double x, int n) {
   double sum = 1.0;  // First term is always 1
   double term = 1.0; // Current term

   for (int i = 1; i <= n; i++) {
      term *= x / i; // term = term × (x/i)
      sum += term;
   }

   return sum;
}

// Function to display detailed calculation
void displayCalculation(double x, int n) {
   double sum = 0.0;

   printf("--- Term-by-Term Calculation ---\n\n");
   printf("Series: 1 + (x/1!) + (x²/2!) + ... + (xⁿ/n!)\n");
   printf("Where x = %.2f, n = %d\n\n", x, n);

   printf("%-6s %-15s %-15s %-15s %-15s\n",
          "Term", "Power (x^i)", "Factorial", "Value", "Running Sum");
   printf("-------------------------------------------------------------------\n");

   for (int i = 0; i <= n; i++) {
      double termValue = calculateTerm(x, i);
      sum += termValue;

      if (i == 0) {
         printf("%-6d %-15s %-15s %-15.10f %-15.10f\n",
                i, "x^0 = 1", "0! = 1", termValue, sum);
      } else {
         char powerStr[20], factStr[20];
         sprintf(powerStr, "%.2f^%d = %.4f", x, i, power(x, i));
         sprintf(factStr, "%d! = %llu", i, factorial(i));
         printf("%-6d %-15s %-15s %-15.10f %-15.10f\n",
                i, powerStr, factStr, termValue, sum);
      }
   }

   printf("-------------------------------------------------------------------\n");
   printf("Final Sum: %.10f\n", sum);
}

int main() {
   double x;
   int n;

   printf("========================================\n");
   printf("  Exponential Series Calculator\n");
   printf("========================================\n\n");

   printf("Series: e^x = 1 + x/1! + x²/2! + x³/3! + ... + xⁿ/n!\n\n");

   printf("This calculates the Taylor series expansion\n");
   printf("of the exponential function e^x\n\n");

   // Input values
   printf("Enter value of x (x ≥ 0): ");
   scanf("%lf", &x);
   printf("Enter number of terms n (n ≥ 1): ");
   scanf("%d", &n);

   // Validation
   if (x < 0) {
      printf("\nError: x must be non-negative (x ≥ 0)!\n");
      return 1;
   }

   if (n < 1) {
      printf("\nError: n must be at least 1 (n ≥ 1)!\n");
      return 1;
   }

   printf("\n========================================\n");
   printf("  Calculation Details\n");
   printf("========================================\n\n");

   // Display detailed calculation for smaller n
   if (n <= 15) {
      displayCalculation(x, n);
   } else {
      printf("Using optimized calculation for n > 15...\n");
   }

   // Calculate using optimized method
   double seriesSum = exponentialSeriesOptimized(x, n);
   double actualValue = exp(x); // Actual e^x using math library
   double error = fabs(actualValue - seriesSum);
   double errorPercent = (error / actualValue) * 100;

   printf("\n========================================\n");
   printf("  Results Summary\n");
   printf("========================================\n\n");

   printf("Input Parameters:\n");
   printf("  x = %.4f\n", x);
   printf("  n = %d terms\n\n", n);

   printf("Series Formula:\n");
   printf("  Sum = 1");
   for (int i = 1; i <= (n < 5 ? n : 4); i++) {
      printf(" + (%.2f^%d/%d!)", x, i, i);
   }
   if (n > 4) {
      printf(" + ...");
   }
   printf("\n\n");

   printf("Results:\n");
   printf("  Series Sum (calculated):  %.10f\n", seriesSum);
   printf("  Actual e^%.4f (from math.h): %.10f\n", x, actualValue);
   printf("  Absolute Error:           %.10f\n", error);
   printf("  Relative Error:           %.6f%%\n\n", errorPercent);

   // Convergence information
   printf("--- Convergence Analysis ---\n");
   if (errorPercent < 0.001) {
      printf("✓ Excellent approximation! (< 0.001%% error)\n");
   } else if (errorPercent < 0.1) {
      printf("✓ Very good approximation (< 0.1%% error)\n");
   } else if (errorPercent < 1.0) {
      printf("○ Good approximation (< 1%% error)\n");
   } else {
      printf("○ Fair approximation (%.3f%% error)\n", errorPercent);
      printf("  Consider using more terms for better accuracy\n");
   }

   printf("\n--- Mathematical Insight ---\n");
   printf("The series converges to e^x as n → ∞\n");
   printf("For x = %.2f, the series approximates e^%.2f\n", x, x);
   printf("Number of terms used: %d\n", n + 1);
   printf("Accuracy achieved: %.6f%%\n", 100 - errorPercent);

   printf("\n========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: x = 1, n = 5
 * Output:
 * ========================================
 *   Exponential Series Calculator
 * ========================================
 *
 * Series: e^x = 1 + x/1! + x²/2! + x³/3! + ... + xⁿ/n!
 *
 * This calculates the Taylor series expansion
 * of the exponential function e^x
 *
 * Enter value of x (x ≥ 0): 1
 * Enter number of terms n (n ≥ 1): 5
 *
 * ========================================
 *   Calculation Details
 * ========================================
 *
 * --- Term-by-Term Calculation ---
 *
 * Series: 1 + (x/1!) + (x²/2!) + ... + (xⁿ/n!)
 * Where x = 1.00, n = 5
 *
 * Term   Power (x^i)     Factorial       Value           Running Sum
 * -------------------------------------------------------------------
 * 0      x^0 = 1         0! = 1          1.0000000000    1.0000000000
 * 1      1.00^1 = 1.0000 1! = 1          1.0000000000    2.0000000000
 * 2      1.00^2 = 1.0000 2! = 2          0.5000000000    2.5000000000
 * 3      1.00^3 = 1.0000 3! = 6          0.1666666667    2.6666666667
 * 4      1.00^4 = 1.0000 4! = 24         0.0416666667    2.7083333333
 * 5      1.00^5 = 1.0000 5! = 120        0.0083333333    2.7166666667
 * -------------------------------------------------------------------
 * Final Sum: 2.7166666667
 *
 * ========================================
 *   Results Summary
 * ========================================
 *
 * Input Parameters:
 *   x = 1.0000
 *   n = 5 terms
 *
 * Series Formula:
 *   Sum = 1 + (1.00^1/1!) + (1.00^2/2!) + (1.00^3/3!) + (1.00^4/4!)
 *
 * Results:
 *   Series Sum (calculated):  2.7166666667
 *   Actual e^1.0000 (from math.h): 2.7182818285
 *   Absolute Error:           0.0016151618
 *   Relative Error:           0.059423%
 *
 * --- Convergence Analysis ---
 * ✓ Very good approximation (< 0.1% error)
 *
 * --- Mathematical Insight ---
 * The series converges to e^x as n → ∞
 * For x = 1.00, the series approximates e^1.00
 * Number of terms used: 6
 * Accuracy achieved: 99.940577%
 *
 * ========================================
 *
 * Example 2:
 * Input: x = 2, n = 10
 * Output:
 * ========================================
 *   Exponential Series Calculator
 * ========================================
 *
 * Series: e^x = 1 + x/1! + x²/2! + x³/3! + ... + xⁿ/n!
 *
 * This calculates the Taylor series expansion
 * of the exponential function e^x
 *
 * Enter value of x (x ≥ 0): 2
 * Enter number of terms n (n ≥ 1): 10
 *
 * ========================================
 *   Calculation Details
 * ========================================
 *
 * --- Term-by-Term Calculation ---
 *
 * Series: 1 + (x/1!) + (x²/2!) + ... + (xⁿ/n!)
 * Where x = 2.00, n = 10
 *
 * Term   Power (x^i)     Factorial       Value           Running Sum
 * -------------------------------------------------------------------
 * 0      x^0 = 1         0! = 1          1.0000000000    1.0000000000
 * 1      2.00^1 = 2.0000 1! = 1          2.0000000000    3.0000000000
 * 2      2.00^2 = 4.0000 2! = 2          2.0000000000    5.0000000000
 * 3      2.00^3 = 8.0000 3! = 6          1.3333333333    6.3333333333
 * 4      2.00^4 = 16.0000 4! = 24         0.6666666667    7.0000000000
 * 5      2.00^5 = 32.0000 5! = 120        0.2666666667    7.2666666667
 * 6      2.00^6 = 64.0000 6! = 720        0.0888888889    7.3555555556
 * 7      2.00^7 = 128.0000 7! = 5040       0.0253968254    7.3809523810
 * 8      2.00^8 = 256.0000 8! = 40320      0.0063492063    7.3873015873
 * 9      2.00^9 = 512.0000 9! = 362880     0.0014109347    7.3887125220
 * 10     2.00^10 = 1024.0000 10! = 3628800   0.0002822581    7.3889947802
 * -------------------------------------------------------------------
 * Final Sum: 7.3889947802
 *
 * ========================================
 *   Results Summary
 * ========================================
 *
 * Input Parameters:
 *   x = 2.0000
 *   n = 10 terms
 *
 * Series Formula:
 *   Sum = 1 + (2.00^1/1!) + (2.00^2/2!) + (2.00^3/3!) + (2.00^4/4!) + ...
 *
 * Results:
 *   Series Sum (calculated):  7.3889947802
 *   Actual e^2.0000 (from math.h): 7.3890560989
 *   Absolute Error:           0.0000613187
 *   Relative Error:           0.000830%
 *
 * --- Convergence Analysis ---
 * ✓ Excellent approximation! (< 0.001% error)
 *
 * --- Mathematical Insight ---
 * The series converges to e^x as n → ∞
 * For x = 2.00, the series approximates e^2.00
 * Number of terms used: 11
 * Accuracy achieved: 99.999170%
 *
 * ========================================
 *
 * Example 3:
 * Input: x = 0.5, n = 8
 * Output:
 * ========================================
 *   Exponential Series Calculator
 * ========================================
 *
 * Series: e^x = 1 + x/1! + x²/2! + x³/3! + ... + xⁿ/n!
 *
 * This calculates the Taylor series expansion
 * of the exponential function e^x
 *
 * Enter value of x (x ≥ 0): 0.5
 * Enter number of terms n (n ≥ 1): 8
 *
 * ========================================
 *   Calculation Details
 * ========================================
 *
 * --- Term-by-Term Calculation ---
 *
 * Series: 1 + (x/1!) + (x²/2!) + ... + (xⁿ/n!)
 * Where x = 0.50, n = 8
 *
 * Term   Power (x^i)     Factorial       Value           Running Sum
 * -------------------------------------------------------------------
 * 0      x^0 = 1         0! = 1          1.0000000000    1.0000000000
 * 1      0.50^1 = 0.5000 1! = 1          0.5000000000    1.5000000000
 * 2      0.50^2 = 0.2500 2! = 2          0.1250000000    1.6250000000
 * 3      0.50^3 = 0.1250 3! = 6          0.0208333333    1.6458333333
 * 4      0.50^4 = 0.0625 4! = 24         0.0026041667    1.6484375000
 * 5      0.50^5 = 0.0312 5! = 120        0.0002604167    1.6486979167
 * 6      0.50^6 = 0.0156 6! = 720        0.0000217014    1.6487196181
 * 7      0.50^7 = 0.0078 7! = 5040       0.0000015501    1.6487211682
 * 8      0.50^8 = 0.0039 8! = 40320      0.0000000969    1.6487212651
 * -------------------------------------------------------------------
 * Final Sum: 1.6487212651
 *
 * ========================================
 *   Results Summary
 * ========================================
 *
 * Input Parameters:
 *   x = 0.5000
 *   n = 8 terms
 *
 * Series Formula:
 *   Sum = 1 + (0.50^1/1!) + (0.50^2/2!) + (0.50^3/3!) + (0.50^4/4!) + ...
 *
 * Results:
 *   Series Sum (calculated):  1.6487212651
 *   Actual e^0.5000 (from math.h): 1.6487212707
 *   Absolute Error:           0.0000000056
 *   Relative Error:           0.000000%
 *
 * --- Convergence Analysis ---
 * ✓ Excellent approximation! (< 0.001% error)
 *
 * --- Mathematical Insight ---
 * The series converges to e^x as n → ∞
 * For x = 0.50, the series approximates e^0.50
 * Number of terms used: 9
 * Accuracy achieved: 100.000000%
 *
 * ========================================
 */
