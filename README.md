# C Programming - Complete Exercise Library

A comprehensive collection of 43 C programming exercises covering fundamental to advanced concepts, organized in 6 sections with detailed implementations.

---

## 📚 Table of Contents

- [Section 1: Format Specifiers (i-iv)](#section-1-format-specifiers)
- [Section 2: Control Structures (v-x)](#section-2-control-structures)
- [Section 3: Loops & Patterns (xi-xix)](#section-3-loops--patterns)
- [Section 4: Arrays, Matrices & Strings (xxi-xxx)](#section-4-arrays-matrices--strings)
- [Section 5: Functions, Pointers & Structures (xxxi-xxxix)](#section-5-functions-pointers--structures)
- [Section 6: File Handling (xl-xliv)](#section-6-file-handling)

---

<div align="center">

## Section `1`: Format Specifiers

</div>

### **[`i)` Number Format Display](https://github.com/elsesourav/c-problems/blob/main/1-i_number_format_display.c)**

**Question:**  
Write a C program to display a number in hexadecimal, decimal, and octal formats.

**Description:**  
This program takes an integer input from the user and displays it in three different number formats: Hexadecimal (base 16), Decimal (base 10), and Octal (base 8).

**How to Solve:**

1. Declare an integer variable to store the input number
2. Use scanf() to read the number from user
3. Use printf() with format specifiers:
   - %d or %i for decimal
   - %x for hexadecimal (lowercase)
   - %X for hexadecimal (uppercase)
   - %o for octal
4. Display the number in all three formats

**[Code:](https://github.com/elsesourav/c-problems/blob/main/1-i_number_format_display.c)**

```c
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
```

**Example:**

```
Input: 255
Output:
--- Number Format Display ---
Decimal format:           255
Hexadecimal (lowercase):  ff
Hexadecimal (uppercase):  FF
Octal format:             377

--- With Prefixes ---
Hexadecimal with prefix:  0xff
Hexadecimal with prefix:  0XFF
Octal with prefix:        0377
```

---

### **[`ii)` Leading and Trailing Zeros](https://github.com/elsesourav/c-problems/blob/main/1-ii_leading_trailing_zeros.c)**

**Question:**  
Write a C program to display numbers with leading zeros and trailing zeros.

**Description:**  
This program demonstrates how to format numbers with leading zeros (padding zeros before the number) and trailing zeros (displaying decimal numbers with specific decimal places).

**How to Solve:**

1. For leading zeros with integers:
   - Use %0nd format specifier where n is the total width
   - Example: %05d will display number with 5 digits, padding with zeros
2. For trailing zeros with floating-point numbers:
   - Use %.nf format specifier where n is decimal places
   - Example: %.3f will display 3 digits after decimal point
3. Combine both for complete formatting control

**[Code:](https://github.com/elsesourav/c-problems/blob/main/1-ii_leading_trailing_zeros.c)**

```c
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
```

**Example:**

```
Input:
  Integer: 42
  Float: 3.14
Output:
--- Leading Zeros (Integer) ---
Original number:          42
With 5 digits (leading):  00042
With 8 digits (leading):  00000042
With 10 digits (leading): 0000000042

--- Trailing Zeros (Float) ---
Original number:          3.140000
With 2 decimal places:    3.14
With 4 decimal places:    3.1400
With 6 decimal places:    3.140000

--- Combined (Leading + Trailing) ---
Width 10, 2 decimals:           3.14
Width 12, 3 decimals:     0003.140
Width 15, 5 decimals:     00003.14000
```

---

### **[`iii)` Left and Right Justification](https://github.com/elsesourav/c-problems/blob/main/1-iii_left_right_justification.c)**

**Question:**  
Write a C program to display numbers with left and right justification.

**Description:**  
This program demonstrates text alignment (justification) in C: Right justification (number is aligned to the right - default) and Left justification (number is aligned to the left using minus sign).

**How to Solve:**

1. For right justification (default):
   - Use %nd format specifier where n is the field width
   - Example: %10d will right-align in 10 character width
2. For left justification:
   - Use %-nd format specifier (negative sign for left align)
   - Example: %-10d will left-align in 10 character width
3. Can combine with precision for floating-point numbers
4. Use vertical bars (|) to visualize the alignment clearly

**[Code:](https://github.com/elsesourav/c-problems/blob/main/1-iii_left_right_justification.c)**

```c
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

   return 0;
}
```

**Example:**

```
Input:
  Integer: 12345
  Float: 67.89
  String: Hello
Output:
--- Right Justification (Default) ---
|          12345| (Integer with width 15)
|          67.89| (Float with width 15, 2 decimals)
|               Hello| (String with width 20)

--- Left Justification (Using -) ---
|12345          | (Integer with width 15)
|67.89          | (Float with width 15, 2 decimals)
|Hello               | (String with width 20)

--- Comparison Side by Side ---
RIGHT: |       12345| LEFT: |12345       |
RIGHT: |       67.890| LEFT: |67.890      |
RIGHT: |          Hello| LEFT: |Hello          |
```

---

### **[`iv)` Different Format Specifiers](https://github.com/elsesourav/c-problems/blob/main/1-iv_different_format_specifiers.c)**

**Question:**  
Write a C program to demonstrate different formatting specifiers in C.

**Description:**  
This program showcases various format specifiers available in C's printf() function including integer, floating-point, character, string, and pointer specifiers with special formatting options.

**How to Solve:**

1. Declare variables of different data types
2. Use appropriate format specifiers for each type:
   - %d or %i: signed decimal integer
   - %u: unsigned decimal integer
   - %f: floating-point number
   - %e/%E: scientific notation
   - %g/%G: shortest representation
   - %c: character
   - %s: string
   - %p: pointer address
3. Combine specifiers with width, precision, and flags

**[Code:](https://github.com/elsesourav/c-problems/blob/main/1-iv_different_format_specifiers.c)**

```c
#include <stdio.h>

int main() {
   int decimalNum;
   unsigned int unsignedNum;
   long longNum;
   float floatNum;
   double doubleNum;
   char character;
   char string[100];

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

   printf("\n=== CHARACTER & STRING FORMAT SPECIFIERS ===\n");
   printf("%%c (character):            %c\n", character);
   printf("%%d (char as ASCII):        %d\n", character);
   printf("%%s (string):               %s\n", string);
   printf("%%10s (width 10):           %10s\n", string);
   printf("%%-10s (left-aligned):      %-10s|\n", string);

   return 0;
}
```

**Example:**

```
Input:
  Integer: 42
  Unsigned: 100
  Long: 999999
  Float: 3.14159
  Double: 2.71828
  Character: A
  String: Hello
Output:
=== INTEGER FORMAT SPECIFIERS ===
%d (decimal):              42
%i (integer):              42
%u (unsigned):             100
%ld (long decimal):        999999
%5d (width 5):                42
%-5d (left-aligned):       42   |
%05d (zero-padded):        00042

=== FLOATING-POINT FORMAT SPECIFIERS ===
%f (float):                3.141590
%lf (double):              2.718280
%.2f (2 decimals):         3.14
%.4f (4 decimals):         2.7183
%e (scientific):           3.141590e+00
%E (SCIENTIFIC):           2.718280E+00
```

---

<div align="center">

## Section `2`: Control Structures

</div>

### **[`v)` Greatest and Smallest of Three Numbers](https://github.com/elsesourav/c-problems/blob/main/2-v_greatest_smallest_three_numbers.c)**

**Question:**  
Write a C program to find the greatest and smallest of three numbers.

**Description:**  
This program takes three numbers as input from the user and determines which number is the greatest (maximum) and which is the smallest (minimum) among them using conditional statements.

**How to Solve:**

1. Declare three variables to store the input numbers
2. Read three numbers from the user
3. Use nested if-else statements or logical operators to compare:
   - For greatest: Compare each number with others using > operator
   - For smallest: Compare each number with others using < operator
4. Alternative approach: Use ternary operator (? :) for compact code
5. Display the greatest and smallest numbers

**[Code:](https://github.com/elsesourav/c-problems/blob/main/2-v_greatest_smallest_three_numbers.c)**

```c
#include <stdio.h>

int main() {
   float num1, num2, num3;
   float greatest, smallest;

   printf("Enter three numbers: ");
   scanf("%f %f %f", &num1, &num2, &num3);

   // Find greatest
   if (num1 >= num2 && num1 >= num3) {
      greatest = num1;
   } else if (num2 >= num1 && num2 >= num3) {
      greatest = num2;
   } else {
      greatest = num3;
   }

   // Find smallest
   if (num1 <= num2 && num1 <= num3) {
      smallest = num1;
   } else if (num2 <= num1 && num2 <= num3) {
      smallest = num2;
   } else {
      smallest = num3;
   }

   printf("\n--- Results ---\n");
   printf("Numbers entered: %.2f, %.2f, %.2f\n", num1, num2, num3);
   printf("Greatest number: %.2f\n", greatest);
   printf("Smallest number: %.2f\n", smallest);
   printf("Difference: %.2f\n", greatest - smallest);

   return 0;
}
```

**Example:**

```
Input: 25 10 30
Output:
--- Results ---
Numbers entered: 25.00, 10.00, 30.00
Greatest number: 30.00
Smallest number: 10.00
Difference: 20.00
```

---

### **[`vi)` Grade Classification](https://github.com/elsesourav/c-problems/blob/main/2-vi_grade_classification.c)**

**Question:**  
Write a C program to display pass class, second class, or distinction according to the marks entered from the keyboard.

**Description:**  
This program takes marks as input and classifies the result into different categories: Distinction (≥75), First Class (60-74), Second Class (50-59), Pass Class (40-49), or Fail (<40).

**How to Solve:**

1. Declare a variable to store marks (integer or float)
2. Read marks from the user
3. Validate that marks are in valid range (0-100)
4. Use if-else ladder to check marks range and classify
5. Display the appropriate classification message

**[Code:](https://github.com/elsesourav/c-problems/blob/main/2-vi_grade_classification.c)**

```c
#include <stdio.h>

int main() {
   float marks;

   printf("Enter marks obtained (0-100): ");
   scanf("%f", &marks);

   if (marks < 0 || marks > 100) {
      printf("\nError: Invalid marks! Marks should be between 0 and 100.\n");
      return 1;
   }

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
```

**Example:**

```
Input: 85
Output:
--- Result Classification ---
Marks obtained: 85.00
Grade: DISTINCTION
Performance: Excellent! Outstanding achievement.
```

---

### **[`vii)` Even or Odd Checker](https://github.com/elsesourav/c-problems/blob/main/2-vii_even_odd_checker.c)**

**Question:**  
Write a C program to find whether a number is even or odd.

**Description:**  
This program takes an integer as input and determines whether it is an even number or an odd number. A number is even if it is divisible by 2 (remainder is 0), otherwise it is odd.

**How to Solve:**

1. Declare an integer variable to store the number
2. Read the number from user input
3. Use modulus operator (%) to find remainder when divided by 2:
   - If number % 2 == 0, the number is EVEN
   - If number % 2 != 0, the number is ODD
4. Use if-else statement to check the condition
5. Display whether the number is even or odd

**[Code:](https://github.com/elsesourav/c-problems/blob/main/2-vii_even_odd_checker.c)**

```c
#include <stdio.h>

int main() {
   int number;

   printf("Enter an integer number: ");
   scanf("%d", &number);

   printf("\n--- Even/Odd Checker ---\n");
   printf("Number entered: %d\n", number);

   if (number % 2 == 0) {
      printf("Result: %d is an EVEN number.\n", number);
      printf("Explanation: %d is divisible by 2 (remainder = 0)\n", number);
   } else {
      printf("Result: %d is an ODD number.\n", number);
      printf("Explanation: %d is not divisible by 2 (remainder = 1)\n", number);
   }

   printf("\nMathematical Info:\n");
   printf("%d ÷ 2 = %d (quotient), remainder = %d\n", number, number / 2, number % 2);

   return 0;
}
```

**Example:**

```
Input: 10
Output:
--- Even/Odd Checker ---
Number entered: 10
Result: 10 is an EVEN number.
Explanation: 10 is divisible by 2 (remainder = 0)

Mathematical Info:
10 ÷ 2 = 5 (quotient), remainder = 0
```

---

### **[`viii)` Number Spelling](https://github.com/elsesourav/c-problems/blob/main/2-viii_number_spelling.c)**

**Question:**  
Write a C program to display spellings of numbers 1-10 on entry.

**Description:**  
This program takes a number (1-10) as input from the user and displays its spelling in words. For example, if user enters 5, it displays "Five". If the number is outside the range 1-10, it shows an error message.

**How to Solve:**

1. Declare an integer variable to store the number
2. Read the number from user input
3. Use switch-case statement to match the number
4. Create cases for 1 to 10, each printing the corresponding spelling
5. Include a default case for invalid input

**[Code:](https://github.com/elsesourav/c-problems/blob/main/2-viii_number_spelling.c)**

```c
#include <stdio.h>

int main() {
   int number;

   printf("Enter a number (1-10): ");
   scanf("%d", &number);

   printf("\n--- Number to Spelling Converter ---\n");
   printf("Number entered: %d\n", number);
   printf("Spelling: ", number);

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

   return 0;
}
```

**Example:**

```
Input: 5
Output:
--- Number to Spelling Converter ---
Number entered: 5
Spelling: Five
```

---

### **[`ix)` Calculator Menu](https://github.com/elsesourav/c-problems/blob/main/2-ix_calculator_menu.c)**

**Question:**  
Write a C program to implement and display a menu to execute 1. ADD, 2. SUBTRACT, 3. MULTIPLICATION, 4. DIVISION using switch case.

**Description:**  
This program creates a simple calculator with a menu-driven interface. It displays a menu with 4 arithmetic operations, user selects an operation, enters two numbers, and the program performs the selected operation using switch-case.

**How to Solve:**

1. Display a menu with operation choices (1-4)
2. Read user's choice
3. Read two numbers from the user
4. Use switch-case statement with choice as the selector
5. Perform the selected operation and display result
6. Include error handling for division by zero

**[Code:](https://github.com/elsesourav/c-problems/blob/main/2-ix_calculator_menu.c)**

```c
#include <stdio.h>

int main() {
   int choice;
   float num1, num2, result;

   printf("========================================\n");
   printf("       CALCULATOR MENU\n");
   printf("========================================\n");
   printf("1. ADD\n");
   printf("2. SUBTRACT\n");
   printf("3. MULTIPLICATION\n");
   printf("4. DIVISION\n");
   printf("========================================\n");
   printf("Enter your choice (1-4): ");
   scanf("%d", &choice);

   printf("Enter first number: ");
   scanf("%f", &num1);
   printf("Enter second number: ");
   scanf("%f", &num2);

   printf("\n--- Calculation Result ---\n");

   switch (choice) {
   case 1:
      result = num1 + num2;
      printf("Operation: ADDITION\n");
      printf("%.2f + %.2f = %.2f\n", num1, num2, result);
      break;
   case 2:
      result = num1 - num2;
      printf("Operation: SUBTRACTION\n");
      printf("%.2f - %.2f = %.2f\n", num1, num2, result);
      break;
   case 3:
      result = num1 * num2;
      printf("Operation: MULTIPLICATION\n");
      printf("%.2f × %.2f = %.2f\n", num1, num2, result);
      break;
   case 4:
      if (num2 == 0) {
         printf("Error: Division by zero!\n");
         return 1;
      }
      result = num1 / num2;
      printf("Operation: DIVISION\n");
      printf("%.2f ÷ %.2f = %.2f\n", num1, num2, result);
      break;
   default:
      printf("Error: Invalid choice!\n");
      return 1;
   }

   return 0;
}
```

**Example:**

```
Input:
  Choice: 1
  First number: 25
  Second number: 15
Output:
========================================
       CALCULATOR MENU
========================================
1. ADD
2. SUBTRACT
3. MULTIPLICATION
4. DIVISION
========================================
Enter your choice (1-4): 1

--- Calculation Result ---
Operation: ADDITION
25.00 + 15.00 = 40.00
```

---

### **[`x)` Quadratic Equation Roots](https://github.com/elsesourav/c-problems/blob/main/2-x_quadratic_equation_roots.c)**

**Question:**  
Write a C program to check whether there exist real roots of a quadratic equation and if they exist, find them.

**Description:**  
This program solves a quadratic equation of the form ax² + bx + c = 0. It checks if real roots exist by calculating the discriminant (D = b² - 4ac), then finds the roots if they exist using the quadratic formula.

**How to Solve:**

1. Input coefficients a, b, and c from the user
2. Check if a != 0 (otherwise it's not quadratic)
3. Calculate discriminant: D = b² - 4ac
4. Use if-else to check discriminant value:
   - If D > 0: Two distinct real roots
   - If D = 0: Two equal real roots
   - If D < 0: No real roots (complex)
5. Use sqrt() function from math.h library

**[Code:](https://github.com/elsesourav/c-problems/blob/main/2-x_quadratic_equation_roots.c)**

```c
#include <math.h>
#include <stdio.h>

int main() {
   float a, b, c;
   float discriminant, root1, root2, realPart, imagPart;

   printf("Quadratic Equation: ax² + bx + c = 0\n");
   printf("========================================\n");
   printf("Enter coefficient a: ");
   scanf("%f", &a);
   printf("Enter coefficient b: ");
   scanf("%f", &b);
   printf("Enter coefficient c: ");
   scanf("%f", &c);

   if (a == 0) {
      printf("\nError: 'a' cannot be zero for a quadratic equation!\n");
      return 1;
   }

   discriminant = (b * b) - (4 * a * c);
   printf("\nDiscriminant (D) = %.2f\n\n", discriminant);

   if (discriminant > 0) {
      printf("Nature: Two DISTINCT REAL roots exist\n\n");
      root1 = (-b + sqrt(discriminant)) / (2 * a);
      root2 = (-b - sqrt(discriminant)) / (2 * a);
      printf("Root 1 = %.2f\n", root1);
      printf("Root 2 = %.2f\n", root2);
   } else if (discriminant == 0) {
      printf("Nature: Two EQUAL REAL roots exist\n\n");
      root1 = -b / (2 * a);
      printf("Root 1 = Root 2 = %.2f\n", root1);
   } else {
      printf("Nature: NO REAL roots exist\n");
      printf("The equation has COMPLEX roots.\n\n");
      realPart = -b / (2 * a);
      imagPart = sqrt(-discriminant) / (2 * a);
      printf("Root 1 = %.2f + %.2fi\n", realPart, imagPart);
      printf("Root 2 = %.2f - %.2fi\n", realPart, imagPart);
   }

   return 0;
}
```

**Example:**

```
Input:
  a = 1
  b = -5
  c = 6
Output:
Quadratic Equation: ax² + bx + c = 0
========================================
Discriminant (D) = 1.00

Nature: Two DISTINCT REAL roots exist

Root 1 = 3.00
Root 2 = 2.00
```
