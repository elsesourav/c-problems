/*
 * QUESTION iv:
 * Write a C program to demonstrate different formatting specifiers in C.
 *
 * PROGRAM DESCRIPTION:
 * This program showcases various format specifiers available in C's printf() function:
 * - Integer specifiers: %d, %i, %u, %ld, %lld
 * - Floating-point specifiers: %f, %lf, %e, %E, %g, %G
 * - Character specifiers: %c
 * - String specifiers: %s
 * - Pointer specifiers: %p
 * - Special formatting: width, precision, flags
 *
 * HOW TO SOLVE:
 * 1. Declare variables of different data types
 * 2. Use appropriate format specifiers for each type:
 *    - %d or %i: signed decimal integer
 *    - %u: unsigned decimal integer
 *    - %f: floating-point number
 *    - %e/%E: scientific notation
 *    - %g/%G: shortest representation (%f or %e)
 *    - %c: character
 *    - %s: string
 *    - %p: pointer address
 * 3. Combine specifiers with width, precision, and flags
 */

#include <stdio.h>

int main() {
   // Variable declarations
   int decimalNum;
   unsigned int unsignedNum;
   long longNum;
   float floatNum;
   double doubleNum;
   char character;
   char string[100];

   // Input from user
   printf("Enter an integer: ");
   scanf("%d", &decimalNum);

   printf("Enter an unsigned integer: ");
   scanf("%u", &unsignedNum);

   printf("Enter a long integer: ");
   scanf("%ld", &longNum);

   printf("Enter a float number: ");
   scanf("%f", &floatNum);

   printf("Enter a double number: ");
   scanf("%lf", &doubleNum);

   printf("Enter a character: ");
   scanf(" %c", &character);

   printf("Enter a string: ");
   scanf("%s", string);

   // Display different format specifiers
   printf("\n=== INTEGER FORMAT SPECIFIERS ===\n");
   printf("%%d (decimal):              %d\n", decimalNum);
   printf("%%i (integer):              %i\n", decimalNum);
   printf("%%u (unsigned):             %u\n", unsignedNum);
   printf("%%ld (long decimal):        %ld\n", longNum);
   printf("%%5d (width 5):             %5d\n", decimalNum);
   printf("%%-5d (left-aligned):       %-5d|\n", decimalNum);
   printf("%%05d (zero-padded):        %05d\n", decimalNum);

   printf("\n=== FLOATING-POINT FORMAT SPECIFIERS ===\n");
   printf("%%f (float):                %f\n", floatNum);
   printf("%%lf (double):              %lf\n", doubleNum);
   printf("%%.2f (2 decimals):         %.2f\n", floatNum);
   printf("%%.4f (4 decimals):         %.4f\n", doubleNum);
   printf("%%e (scientific):           %e\n", floatNum);
   printf("%%E (SCIENTIFIC):           %E\n", doubleNum);
   printf("%%g (shortest):             %g\n", floatNum);
   printf("%%G (SHORTEST):             %G\n", doubleNum);
   printf("%%10.3f (width 10, 3 dec):  %10.3f\n", floatNum);

   printf("\n=== CHARACTER & STRING FORMAT SPECIFIERS ===\n");
   printf("%%c (character):            %c\n", character);
   printf("%%d (char as ASCII):        %d\n", character);
   printf("%%s (string):               %s\n", string);
   printf("%%10s (width 10):           %10s\n", string);
   printf("%%-10s (left-aligned):      %-10s|\n", string);
   printf("%%.5s (first 5 chars):      %.5s\n", string);

   printf("\n=== POINTER & SPECIAL SPECIFIERS ===\n");
   printf("%%p (pointer address):      %p\n", (void *)&decimalNum);
   printf("%%%% (percent sign):        %%\n");

   printf("\n=== MIXED FORMAT SPECIFIERS ===\n");
   printf("Hex: %x, Octal: %o, Decimal: %d\n", decimalNum, decimalNum, decimalNum);
   printf("With prefixes: %#x, %#o, %d\n", decimalNum, decimalNum, decimalNum);
   printf("Signed: %+d, Space: % d\n", decimalNum, decimalNum);
   printf("Float: %f, Scientific: %e, Auto: %g\n", doubleNum, doubleNum, doubleNum);

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Integer: 42
 *   Unsigned: 100
 *   Long: 999999
 *   Float: 3.14159
 *   Double: 2.71828
 *   Character: A
 *   String: Hello
 * Output:
 * === INTEGER FORMAT SPECIFIERS ===
 * %d (decimal):              42
 * %i (integer):              42
 * %u (unsigned):             100
 * %ld (long decimal):        999999
 * %5d (width 5):                42
 * %-5d (left-aligned):       42   |
 * %05d (zero-padded):        00042
 *
 * === FLOATING-POINT FORMAT SPECIFIERS ===
 * %f (float):                3.141590
 * %lf (double):              2.718280
 * %.2f (2 decimals):         3.14
 * %.4f (4 decimals):         2.7183
 * %e (scientific):           3.141590e+00
 * %E (SCIENTIFIC):           2.718280E+00
 * %g (shortest):             3.14159
 * %G (SHORTEST):             2.71828
 * %10.3f (width 10, 3 dec):      3.142
 *
 * === CHARACTER & STRING FORMAT SPECIFIERS ===
 * %c (character):            A
 * %d (char as ASCII):        65
 * %s (string):               Hello
 * %10s (width 10):                Hello
 * %-10s (left-aligned):      Hello     |
 * %.5s (first 5 chars):      Hello
 *
 * === POINTER & SPECIAL SPECIFIERS ===
 * %p (pointer address):      0x7ffeeb2a3c4c
 * %% (percent sign):        %
 *
 * === MIXED FORMAT SPECIFIERS ===
 * Hex: 2a, Octal: 52, Decimal: 42
 * With prefixes: 0x2a, 052, 42
 * Signed: +42, Space:  42
 * Float: 2.718280, Scientific: 2.718280e+00, Auto: 2.71828
 *
 * Example 2:
 * Input:
 *   Integer: -25
 *   Unsigned: 65535
 *   Long: 1234567890
 *   Float: 123.456
 *   Double: 9876.54321
 *   Character: Z
 *   String: Program
 * Output:
 * === INTEGER FORMAT SPECIFIERS ===
 * %d (decimal):              -25
 * %i (integer):              -25
 * %u (unsigned):             65535
 * %ld (long decimal):        1234567890
 * %5d (width 5):               -25
 * %-5d (left-aligned):       -25  |
 * %05d (zero-padded):        -0025
 *
 * === FLOATING-POINT FORMAT SPECIFIERS ===
 * %f (float):                123.456001
 * %lf (double):              9876.543210
 * %.2f (2 decimals):         123.46
 * %.4f (4 decimals):         9876.5432
 * %e (scientific):           1.234560e+02
 * %E (SCIENTIFIC):           9.876543E+03
 * %g (shortest):             123.456
 * %G (SHORTEST):             9876.54
 * %10.3f (width 10, 3 dec):    123.456
 *
 * === CHARACTER & STRING FORMAT SPECIFIERS ===
 * %c (character):            Z
 * %d (char as ASCII):        90
 * %s (string):               Program
 * %10s (width 10):              Program
 * %-10s (left-aligned):      Program   |
 * %.5s (first 5 chars):      Progr
 *
 * === POINTER & SPECIAL SPECIFIERS ===
 * %p (pointer address):      0x7ffeeb2a3c4c
 * %% (percent sign):        %
 *
 * === MIXED FORMAT SPECIFIERS ===
 * Hex: ffffffe7, Octal: 37777777747, Decimal: -25
 * With prefixes: 0xffffffe7, 037777777747, -25
 * Signed: -25, Space: -25
 * Float: 9876.543210, Scientific: 9.876543e+03, Auto: 9876.54
 *
 * Example 3:
 * Input:
 *   Integer: 255
 *   Unsigned: 4294967295
 *   Long: 9999999999
 *   Float: 0.00123
 *   Double: 1000000.5
 *   Character: 5
 *   String: C_Programming
 * Output:
 * === INTEGER FORMAT SPECIFIERS ===
 * %d (decimal):              255
 * %i (integer):              255
 * %u (unsigned):             4294967295
 * %ld (long decimal):        9999999999
 * %5d (width 5):               255
 * %-5d (left-aligned):       255  |
 * %05d (zero-padded):        00255
 *
 * === FLOATING-POINT FORMAT SPECIFIERS ===
 * %f (float):                0.001230
 * %lf (double):              1000000.500000
 * %.2f (2 decimals):         0.00
 * %.4f (4 decimals):         1000000.5000
 * %e (scientific):           1.230000e-03
 * %E (SCIENTIFIC):           1.000000E+06
 * %g (shortest):             0.00123
 * %G (SHORTEST):             1.00000E+06
 * %10.3f (width 10, 3 dec):      0.001
 *
 * === CHARACTER & STRING FORMAT SPECIFIERS ===
 * %c (character):            5
 * %d (char as ASCII):        53
 * %s (string):               C_Programming
 * %10s (width 10):           C_Programming
 * %-10s (left-aligned):      C_Programming|
 * %.5s (first 5 chars):      C_Pro
 *
 * === POINTER & SPECIAL SPECIFIERS ===
 * %p (pointer address):      0x7ffeeb2a3c4c
 * %% (percent sign):        %
 *
 * === MIXED FORMAT SPECIFIERS ===
 * Hex: ff, Octal: 377, Decimal: 255
 * With prefixes: 0xff, 0377, 255
 * Signed: +255, Space:  255
 * Float: 1000000.500000, Scientific: 1.000000e+06, Auto: 1.00000e+06
 */
