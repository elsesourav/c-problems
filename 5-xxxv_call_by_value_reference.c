/*
 * QUESTION xxxv:
 * Write a C program to demonstrate call by reference and call by value.
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates the difference between two parameter passing
 * mechanisms in C:
 *
 * 1. CALL BY VALUE:
 *    - A copy of the actual parameter is passed to the function
 *    - Changes made to the parameter inside the function do NOT affect
 *      the original variable
 *    - Default method in C
 *
 * 2. CALL BY REFERENCE:
 *    - The address (pointer) of the actual parameter is passed
 *    - Changes made to the parameter inside the function DO affect
 *      the original variable
 *    - Achieved using pointers in C
 *
 * Examples demonstrated:
 * - Swapping two numbers
 * - Modifying a value
 * - Incrementing a value
 *
 * HOW TO SOLVE:
 * 1. Create function using call by value (pass variables directly)
 * 2. Create function using call by reference (pass addresses using &)
 * 3. Demonstrate each method with examples
 * 4. Show how original values are/aren't affected
 * 5. Compare both methods with clear output
 */

#include <stdio.h>

// ========== CALL BY VALUE FUNCTIONS ==========

// Function to swap two numbers using call by value
void swapByValue(int a, int b) {
   printf("\n  Inside swapByValue():\n");
   printf("    Before swap: a = %d, b = %d\n", a, b);

   int temp = a;
   a = b;
   b = temp;

   printf("    After swap:  a = %d, b = %d\n", a, b);
   printf("    (Changes are LOCAL to this function)\n");
}

// Function to increment a number using call by value
void incrementByValue(int num) {
   printf("\n  Inside incrementByValue():\n");
   printf("    Before: num = %d\n", num);
   num++;
   printf("    After:  num = %d (incremented)\n", num);
   printf("    (Change is LOCAL to this function)\n");
}

// Function to modify a value using call by value
void modifyByValue(int x) {
   printf("\n  Inside modifyByValue():\n");
   printf("    Before: x = %d\n", x);
   x = x * 2;
   printf("    After:  x = %d (doubled)\n", x);
   printf("    (Change is LOCAL to this function)\n");
}

// ========== CALL BY REFERENCE FUNCTIONS ==========

// Function to swap two numbers using call by reference
void swapByReference(int *a, int *b) {
   printf("\n  Inside swapByReference():\n");
   printf("    Before swap: *a = %d, *b = %d\n", *a, *b);

   int temp = *a;
   *a = *b;
   *b = temp;

   printf("    After swap:  *a = %d, *b = %d\n", *a, *b);
   printf("    (Changes affect ORIGINAL variables)\n");
}

// Function to increment a number using call by reference
void incrementByReference(int *num) {
   printf("\n  Inside incrementByReference():\n");
   printf("    Before: *num = %d\n", *num);
   (*num)++;
   printf("    After:  *num = %d (incremented)\n", *num);
   printf("    (Change affects ORIGINAL variable)\n");
}

// Function to modify a value using call by reference
void modifyByReference(int *x) {
   printf("\n  Inside modifyByReference():\n");
   printf("    Before: *x = %d\n", *x);
   *x = (*x) * 2;
   printf("    After:  *x = %d (doubled)\n", *x);
   printf("    (Change affects ORIGINAL variable)\n");
}

int main() {
   int num1, num2, value;

   printf("========================================\n");
   printf("  Call by Value vs Call by Reference\n");
   printf("========================================\n\n");

   printf("This program demonstrates the difference between:\n");
   printf("1. Call by Value - passes copy of variable\n");
   printf("2. Call by Reference - passes address of variable\n\n");

   // ========== DEMONSTRATION 1: SWAP FUNCTION ==========
   printf("========================================\n");
   printf("  DEMONSTRATION 1: Swap Two Numbers\n");
   printf("========================================\n\n");

   printf("Enter two numbers:\n");
   printf("Number 1: ");
   scanf("%d", &num1);
   printf("Number 2: ");
   scanf("%d", &num2);

   // Call by Value
   printf("\n--- Using CALL BY VALUE ---\n");
   printf("Before calling swapByValue(): num1 = %d, num2 = %d\n", num1, num2);
   swapByValue(num1, num2);
   printf("After calling swapByValue():  num1 = %d, num2 = %d\n", num1, num2);
   printf("✗ Original values UNCHANGED!\n");

   // Call by Reference
   printf("\n--- Using CALL BY REFERENCE ---\n");
   printf("Before calling swapByReference(): num1 = %d, num2 = %d\n", num1, num2);
   swapByReference(&num1, &num2);
   printf("After calling swapByReference():  num1 = %d, num2 = %d\n", num1, num2);
   printf("✓ Original values CHANGED!\n");

   // ========== DEMONSTRATION 2: INCREMENT FUNCTION ==========
   printf("\n========================================\n");
   printf("  DEMONSTRATION 2: Increment a Number\n");
   printf("========================================\n\n");

   printf("Enter a number: ");
   scanf("%d", &value);

   // Call by Value
   printf("\n--- Using CALL BY VALUE ---\n");
   printf("Before calling incrementByValue(): value = %d\n", value);
   incrementByValue(value);
   printf("After calling incrementByValue():  value = %d\n", value);
   printf("✗ Original value UNCHANGED!\n");

   // Call by Reference
   printf("\n--- Using CALL BY REFERENCE ---\n");
   printf("Before calling incrementByReference(): value = %d\n", value);
   incrementByReference(&value);
   printf("After calling incrementByReference():  value = %d\n", value);
   printf("✓ Original value CHANGED!\n");

   // ========== DEMONSTRATION 3: MODIFY FUNCTION ==========
   printf("\n========================================\n");
   printf("  DEMONSTRATION 3: Double a Number\n");
   printf("========================================\n\n");

   printf("Enter a number: ");
   scanf("%d", &value);

   // Call by Value
   printf("\n--- Using CALL BY VALUE ---\n");
   printf("Before calling modifyByValue(): value = %d\n", value);
   modifyByValue(value);
   printf("After calling modifyByValue():  value = %d\n", value);
   printf("✗ Original value UNCHANGED!\n");

   // Call by Reference
   printf("\n--- Using CALL BY REFERENCE ---\n");
   printf("Before calling modifyByReference(): value = %d\n", value);
   modifyByReference(&value);
   printf("After calling modifyByReference():  value = %d\n", value);
   printf("✓ Original value CHANGED!\n");

   // ========== COMPARISON TABLE ==========
   printf("\n========================================\n");
   printf("  Comparison Summary\n");
   printf("========================================\n\n");

   printf("┌─────────────────────┬──────────────────┬──────────────────┐\n");
   printf("│ Feature             │ Call by Value    │ Call by Reference│\n");
   printf("├─────────────────────┼──────────────────┼──────────────────┤\n");
   printf("│ What is passed?     │ Copy of value    │ Address (pointer)│\n");
   printf("│ Function syntax     │ func(int x)      │ func(int *x)     │\n");
   printf("│ Function call       │ func(var)        │ func(&var)       │\n");
   printf("│ Access in function  │ x                │ *x               │\n");
   printf("│ Original modified?  │ NO ✗             │ YES ✓            │\n");
   printf("│ Memory used         │ More (copy)      │ Less (address)   │\n");
   printf("│ Use case            │ Read-only ops    │ Modify original  │\n");
   printf("└─────────────────────┴──────────────────┴──────────────────┘\n");

   printf("\n========================================\n");
   printf("  Key Concepts\n");
   printf("========================================\n\n");

   printf("CALL BY VALUE:\n");
   printf("  • Default method in C\n");
   printf("  • Safe - original data protected\n");
   printf("  • Cannot return multiple values\n");
   printf("  • Example: int func(int x)\n\n");

   printf("CALL BY REFERENCE:\n");
   printf("  • Uses pointers\n");
   printf("  • Can modify original data\n");
   printf("  • Can return multiple values\n");
   printf("  • Example: void func(int *x)\n\n");

   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Swap: num1=10, num2=20
 *   Increment: value=5
 *   Modify: value=8
 * Output:
 * ========================================
 *   Call by Value vs Call by Reference
 * ========================================
 *
 * This program demonstrates the difference between:
 * 1. Call by Value - passes copy of variable
 * 2. Call by Reference - passes address of variable
 *
 * ========================================
 *   DEMONSTRATION 1: Swap Two Numbers
 * ========================================
 *
 * Enter two numbers:
 * Number 1: 10
 * Number 2: 20
 *
 * --- Using CALL BY VALUE ---
 * Before calling swapByValue(): num1 = 10, num2 = 20
 *
 *   Inside swapByValue():
 *     Before swap: a = 10, b = 20
 *     After swap:  a = 20, b = 10
 *     (Changes are LOCAL to this function)
 * After calling swapByValue():  num1 = 10, num2 = 20
 * ✗ Original values UNCHANGED!
 *
 * --- Using CALL BY REFERENCE ---
 * Before calling swapByReference(): num1 = 10, num2 = 20
 *
 *   Inside swapByReference():
 *     Before swap: *a = 10, *b = 20
 *     After swap:  *a = 20, *b = 10
 *     (Changes affect ORIGINAL variables)
 * After calling swapByReference():  num1 = 20, num2 = 10
 * ✓ Original values CHANGED!
 *
 * ========================================
 *   DEMONSTRATION 2: Increment a Number
 * ========================================
 *
 * Enter a number: 5
 *
 * --- Using CALL BY VALUE ---
 * Before calling incrementByValue(): value = 5
 *
 *   Inside incrementByValue():
 *     Before: num = 5
 *     After:  num = 6 (incremented)
 *     (Change is LOCAL to this function)
 * After calling incrementByValue():  value = 5
 * ✗ Original value UNCHANGED!
 *
 * --- Using CALL BY REFERENCE ---
 * Before calling incrementByReference(): value = 5
 *
 *   Inside incrementByReference():
 *     Before: *num = 5
 *     After:  *num = 6 (incremented)
 *     (Change affects ORIGINAL variable)
 * After calling incrementByReference():  value = 6
 * ✓ Original value CHANGED!
 *
 * ========================================
 *   DEMONSTRATION 3: Double a Number
 * ========================================
 *
 * Enter a number: 8
 *
 * --- Using CALL BY VALUE ---
 * Before calling modifyByValue(): value = 8
 *
 *   Inside modifyByValue():
 *     Before: x = 8
 *     After:  x = 16 (doubled)
 *     (Change is LOCAL to this function)
 * After calling modifyByValue():  value = 8
 * ✗ Original value UNCHANGED!
 *
 * --- Using CALL BY REFERENCE ---
 * Before calling modifyByReference(): value = 8
 *
 *   Inside modifyByReference():
 *     Before: *x = 8
 *     After:  *x = 16 (doubled)
 *     (Change affects ORIGINAL variable)
 * After calling modifyByReference():  value = 16
 * ✓ Original value CHANGED!
 *
 * ========================================
 *   Comparison Summary
 * ========================================
 *
 * ┌─────────────────────┬──────────────────┬──────────────────┐
 * │ Feature             │ Call by Value    │ Call by Reference│
 * ├─────────────────────┼──────────────────┼──────────────────┤
 * │ What is passed?     │ Copy of value    │ Address (pointer)│
 * │ Function syntax     │ func(int x)      │ func(int *x)     │
 * │ Function call       │ func(var)        │ func(&var)       │
 * │ Access in function  │ x                │ *x               │
 * │ Original modified?  │ NO ✗             │ YES ✓            │
 * │ Memory used         │ More (copy)      │ Less (address)   │
 * │ Use case            │ Read-only ops    │ Modify original  │
 * └─────────────────────┴──────────────────┴──────────────────┘
 *
 * ========================================
 *   Key Concepts
 * ========================================
 *
 * CALL BY VALUE:
 *   • Default method in C
 *   • Safe - original data protected
 *   • Cannot return multiple values
 *   • Example: int func(int x)
 *
 * CALL BY REFERENCE:
 *   • Uses pointers
 *   • Can modify original data
 *   • Can return multiple values
 *   • Example: void func(int *x)
 *
 * ========================================
 */
