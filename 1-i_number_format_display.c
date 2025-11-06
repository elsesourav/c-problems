/*
 * QUESTION i:
 * Write a C program to display a number in hexadecimal, decimal, and octal formats.
 *
 * PROGRAM DESCRIPTION:
 * This program takes an integer input from the user and displays it in three
 * different number formats:
 * - Hexadecimal (base 16)
 * - Decimal (base 10)
 * - Octal (base 8)
 *
 * HOW TO SOLVE:
 * 1. Declare an integer variable to store the input number
 * 2. Use scanf() to read the number from user
 * 3. Use printf() with format specifiers:
 *    - %d or %i for decimal
 *    - %x for hexadecimal (lowercase)
 *    - %X for hexadecimal (uppercase)
 *    - %o for octal
 * 4. Display the number in all three formats
 */

#include <stdio.h>

int main() {
   int number;

   printf("Enter an integer number: ");
   scanf("%d", &number);

   printf("\n--- Number Format Display ---\n");
   printf("Decimal format:           %d\n", number);
   printf("Hexadecimal (lowercase):  %x\n", number);
   printf("Hexadecimal (uppercase):  %X\n", number);
   printf("Octal format:             %o\n", number);

   // With prefixes (0x for hex, 0 for octal)
   printf("\n--- With Prefixes ---\n");
   printf("Hexadecimal with prefix:  %#x\n", number);
   printf("Hexadecimal with prefix:  %#X\n", number);
   printf("Octal with prefix:        %#o\n", number);

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: 255
 * Output:
 * --- Number Format Display ---
 * Decimal format:           255
 * Hexadecimal (lowercase):  ff
 * Hexadecimal (uppercase):  FF
 * Octal format:             377
 *
 * --- With Prefixes ---
 * Hexadecimal with prefix:  0xff
 * Hexadecimal with prefix:  0XFF
 * Octal with prefix:        0377
 *
 * Example 2:
 * Input: 100
 * Output:
 * --- Number Format Display ---
 * Decimal format:           100
 * Hexadecimal (lowercase):  64
 * Hexadecimal (uppercase):  64
 * Octal format:             144
 *
 * --- With Prefixes ---
 * Hexadecimal with prefix:  0x64
 * Hexadecimal with prefix:  0X64
 * Octal with prefix:        0144
 *
 * Example 3:
 * Input: 1024
 * Output:
 * --- Number Format Display ---
 * Decimal format:           1024
 * Hexadecimal (lowercase):  400
 * Hexadecimal (uppercase):  400
 * Octal format:             2000
 *
 * --- With Prefixes ---
 * Hexadecimal with prefix:  0x400
 * Hexadecimal with prefix:  0X400
 * Octal with prefix:        02000
 */
