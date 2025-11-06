/*
 * QUESTION iii:
 * Write a C program to display numbers with left and right justification.
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates text alignment (justification) in C:
 * - Right justification: Number is aligned to the right (default behavior)
 * - Left justification: Number is aligned to the left (using minus sign)
 * The program shows how to align both integers and floating-point numbers
 * within a specified field width.
 *
 * HOW TO SOLVE:
 * 1. For right justification (default):
 *    - Use %nd format specifier where n is the field width
 *    - Example: %10d will right-align in 10 character width
 * 2. For left justification:
 *    - Use %-nd format specifier (negative sign for left align)
 *    - Example: %-10d will left-align in 10 character width
 * 3. Can combine with precision for floating-point numbers
 * 4. Use vertical bars (|) to visualize the alignment clearly
 */

#include <stdio.h>

int main() {
   int intNumber;
   float floatNumber;
   char text[50];

   printf("Enter an integer number: ");
   scanf("%d", &intNumber);

   printf("Enter a floating-point number: ");
   scanf("%f", &floatNumber);

   printf("Enter a text string: ");
   scanf("%s", text);

   printf("\n--- Right Justification (Default) ---\n");
   printf("|%15d| (Integer with width 15)\n", intNumber);
   printf("|%15.2f| (Float with width 15, 2 decimals)\n", floatNumber);
   printf("|%20s| (String with width 20)\n", text);

   printf("\n--- Left Justification (Using -) ---\n");
   printf("|%-15d| (Integer with width 15)\n", intNumber);
   printf("|%-15.2f| (Float with width 15, 2 decimals)\n", floatNumber);
   printf("|%-20s| (String with width 20)\n", text);

   printf("\n--- Comparison Side by Side ---\n");
   printf("RIGHT: |%12d| LEFT: |%-12d|\n", intNumber, intNumber);
   printf("RIGHT: |%12.3f| LEFT: |%-12.3f|\n", floatNumber, floatNumber);
   printf("RIGHT: |%15s| LEFT: |%-15s|\n", text, text);

   printf("\n--- Different Widths ---\n");
   printf("Width 10:  |%10d| vs |%-10d|\n", intNumber, intNumber);
   printf("Width 15:  |%15d| vs |%-15d|\n", intNumber, intNumber);
   printf("Width 20:  |%20d| vs |%-20d|\n", intNumber, intNumber);

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Integer: 12345
 *   Float: 67.89
 *   String: Hello
 * Output:
 * --- Right Justification (Default) ---
 * |          12345| (Integer with width 15)
 * |          67.89| (Float with width 15, 2 decimals)
 * |               Hello| (String with width 20)
 *
 * --- Left Justification (Using -) ---
 * |12345          | (Integer with width 15)
 * |67.89          | (Float with width 15, 2 decimals)
 * |Hello               | (String with width 20)
 *
 * --- Comparison Side by Side ---
 * RIGHT: |       12345| LEFT: |12345       |
 * RIGHT: |       67.890| LEFT: |67.890      |
 * RIGHT: |          Hello| LEFT: |Hello          |
 *
 * --- Different Widths ---
 * Width 10:  |     12345| vs |12345     |
 * Width 15:  |          12345| vs |12345          |
 * Width 20:  |               12345| vs |12345               |
 *
 * Example 2:
 * Input:
 *   Integer: 9
 *   Float: 3.14159
 *   String: C
 * Output:
 * --- Right Justification (Default) ---
 * |              9| (Integer with width 15)
 * |           3.14| (Float with width 15, 2 decimals)
 * |                   C| (String with width 20)
 *
 * --- Left Justification (Using -) ---
 * |9              | (Integer with width 15)
 * |3.14           | (Float with width 15, 2 decimals)
 * |C                   | (String with width 20)
 *
 * --- Comparison Side by Side ---
 * RIGHT: |           9| LEFT: |9           |
 * RIGHT: |        3.142| LEFT: |3.142       |
 * RIGHT: |              C| LEFT: |C              |
 *
 * --- Different Widths ---
 * Width 10:  |         9| vs |9         |
 * Width 15:  |              9| vs |9              |
 * Width 20:  |                   9| vs |9                   |
 *
 * Example 3:
 * Input:
 *   Integer: 999999
 *   Float: 1234.5678
 *   String: Programming
 * Output:
 * --- Right Justification (Default) ---
 * |         999999| (Integer with width 15)
 * |        1234.57| (Float with width 15, 2 decimals)
 * |         Programming| (String with width 20)
 *
 * --- Left Justification (Using -) ---
 * |999999         | (Integer with width 15)
 * |1234.57        | (Float with width 15, 2 decimals)
 * |Programming         | (String with width 20)
 *
 * --- Comparison Side by Side ---
 * RIGHT: |      999999| LEFT: |999999      |
 * RIGHT: |    1234.568| LEFT: |1234.568    |
 * RIGHT: |    Programming| LEFT: |Programming    |
 *
 * --- Different Widths ---
 * Width 10:  |    999999| vs |999999    |
 * Width 15:  |         999999| vs |999999         |
 * Width 20:  |              999999| vs |999999              |
 */
