/*
 * QUESTION ii:
 * Write a C program to display numbers with leading zeros and trailing zeros.
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates how to format numbers with:
 * - Leading zeros: Padding zeros before the number
 * - Trailing zeros: Displaying decimal numbers with specific decimal places
 * The program takes an integer and a floating-point number as input and
 * displays them with different zero padding.
 *
 * HOW TO SOLVE:
 * 1. For leading zeros with integers:
 *    - Use %0nd format specifier where n is the total width
 *    - Example: %05d will display number with 5 digits, padding with zeros
 * 2. For trailing zeros with floating-point numbers:
 *    - Use %.nf format specifier where n is decimal places
 *    - Example: %.3f will display 3 digits after decimal point
 * 3. Combine both for complete formatting control
 */

#include <stdio.h>

int main() {
   int intNumber;
   float floatNumber;

   printf("Enter an integer number: ");
   scanf("%d", &intNumber);

   printf("Enter a floating-point number: ");
   scanf("%f", &floatNumber);

   printf("\n--- Leading Zeros (Integer) ---\n");
   printf("Original number:          %d\n", intNumber);
   printf("With 5 digits (leading):  %05d\n", intNumber);
   printf("With 8 digits (leading):  %08d\n", intNumber);
   printf("With 10 digits (leading): %010d\n", intNumber);

   printf("\n--- Trailing Zeros (Float) ---\n");
   printf("Original number:          %f\n", floatNumber);
   printf("With 2 decimal places:    %.2f\n", floatNumber);
   printf("With 4 decimal places:    %.4f\n", floatNumber);
   printf("With 6 decimal places:    %.6f\n", floatNumber);

   printf("\n--- Combined (Leading + Trailing) ---\n");
   printf("Width 10, 2 decimals:     %10.2f\n", floatNumber);
   printf("Width 12, 3 decimals:     %012.3f\n", floatNumber);
   printf("Width 15, 5 decimals:     %015.5f\n", floatNumber);

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Integer: 42
 *   Float: 3.14
 * Output:
 * --- Leading Zeros (Integer) ---
 * Original number:          42
 * With 5 digits (leading):  00042
 * With 8 digits (leading):  00000042
 * With 10 digits (leading): 0000000042
 *
 * --- Trailing Zeros (Float) ---
 * Original number:          3.140000
 * With 2 decimal places:    3.14
 * With 4 decimal places:    3.1400
 * With 6 decimal places:    3.140000
 *
 * --- Combined (Leading + Trailing) ---
 * Width 10, 2 decimals:           3.14
 * Width 12, 3 decimals:     0003.140
 * Width 15, 5 decimals:     00003.14000
 *
 * Example 2:
 * Input:
 *   Integer: 987
 *   Float: 12.5
 * Output:
 * --- Leading Zeros (Integer) ---
 * Original number:          987
 * With 5 digits (leading):  00987
 * With 8 digits (leading):  00000987
 * With 10 digits (leading): 0000000987
 *
 * --- Trailing Zeros (Float) ---
 * Original number:          12.500000
 * With 2 decimal places:    12.50
 * With 4 decimal places:    12.5000
 * With 6 decimal places:    12.500000
 *
 * --- Combined (Leading + Trailing) ---
 * Width 10, 2 decimals:          12.50
 * Width 12, 3 decimals:     0012.500
 * Width 15, 5 decimals:     00012.50000
 *
 * Example 3:
 * Input:
 *   Integer: 7
 *   Float: 123.456789
 * Output:
 * --- Leading Zeros (Integer) ---
 * Original number:          7
 * With 5 digits (leading):  00007
 * With 8 digits (leading):  00000007
 * With 10 digits (leading): 0000000007
 *
 * --- Trailing Zeros (Float) ---
 * Original number:          123.456787
 * With 2 decimal places:    123.46
 * With 4 decimal places:    123.4568
 * With 6 decimal places:    123.456787
 *
 * --- Combined (Leading + Trailing) ---
 * Width 10, 2 decimals:         123.46
 * Width 12, 3 decimals:     0123.457
 * Width 15, 5 decimals:     00123.45679
 */
