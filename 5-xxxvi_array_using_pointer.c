/*
 * QUESTION xxxvi:
 * Write a C program to read and display an integer array using pointer.
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates how to use pointers to manipulate arrays.
 * In C, arrays and pointers are closely related:
 * - Array name represents the base address (pointer to first element)
 * - arr[i] is equivalent to *(arr + i)
 * - &arr[i] is equivalent to (arr + i)
 *
 * The program shows:
 * 1. Reading array elements using pointers
 * 2. Displaying array elements using pointers
 * 3. Pointer arithmetic (ptr++, ptr + i)
 * 4. Dereferencing pointers (*ptr)
 * 5. Address calculations
 *
 * HOW TO SOLVE:
 * 1. Declare an integer array
 * 2. Declare a pointer to integer
 * 3. Point the pointer to the array (ptr = arr)
 * 4. Use pointer arithmetic to traverse array
 * 5. Read elements: *(ptr + i) or *ptr (with ptr++)
 * 6. Display elements using pointer notation
 * 7. Show addresses and values at each position
 * 8. Demonstrate different pointer access methods
 */

#include <stdio.h>

// Function to read array using pointer
void readArray(int *ptr, int size) {
   printf("Enter %d elements:\n", size);
   for (int i = 0; i < size; i++) {
      printf("Element [%d]: ", i);
      scanf("%d", ptr + i); // Same as scanf("%d", &ptr[i])
   }
}

// Function to display array using pointer (Method 1: pointer + index)
void displayArrayMethod1(int *ptr, int size) {
   printf("Method 1 - Using *(ptr + i):\n");
   for (int i = 0; i < size; i++) {
      printf("  arr[%d] = %d (at address %p)\n", i, *(ptr + i), (void *)(ptr + i));
   }
}

// Function to display array using pointer (Method 2: pointer increment)
void displayArrayMethod2(int *ptr, int size) {
   printf("Method 2 - Using *ptr and ptr++:\n");
   int *temp = ptr; // Save original pointer
   for (int i = 0; i < size; i++) {
      printf("  arr[%d] = %d (at address %p)\n", i, *temp, (void *)temp);
      temp++; // Move to next element
   }
}

// Function to display array using pointer (Method 3: array subscript)
void displayArrayMethod3(int *ptr, int size) {
   printf("Method 3 - Using ptr[i] (subscript notation):\n");
   for (int i = 0; i < size; i++) {
      printf("  arr[%d] = %d (at address %p)\n", i, ptr[i], (void *)&ptr[i]);
   }
}

// Function to find sum using pointer
int findSum(int *ptr, int size) {
   int sum = 0;
   for (int i = 0; i < size; i++) {
      sum += *(ptr + i);
   }
   return sum;
}

// Function to find max using pointer
int findMax(int *ptr, int size) {
   int max = *ptr; // First element
   for (int i = 1; i < size; i++) {
      if (*(ptr + i) > max) {
         max = *(ptr + i);
      }
   }
   return max;
}

// Function to reverse array using pointers
void reverseArray(int *ptr, int size) {
   int *start = ptr;
   int *end = ptr + size - 1;

   while (start < end) {
      // Swap elements
      int temp = *start;
      *start = *end;
      *end = temp;

      start++;
      end--;
   }
}

int main() {
   int size;
   int arr[100];
   int *ptr;

   printf("========================================\n");
   printf("  Integer Array Using Pointers\n");
   printf("========================================\n\n");

   printf("This program demonstrates array manipulation\n");
   printf("using pointers in various ways.\n\n");

   // Input array size
   printf("Enter the size of array (max 100): ");
   scanf("%d", &size);

   if (size <= 0 || size > 100) {
      printf("Error: Size must be between 1 and 100\n");
      return 1;
   }

   // Point to array
   ptr = arr; // arr is same as &arr[0]

   printf("\n========================================\n");
   printf("  Reading Array Using Pointer\n");
   printf("========================================\n\n");

   readArray(ptr, size);

   printf("\n========================================\n");
   printf("  Pointer Concepts\n");
   printf("========================================\n\n");

   printf("Array name:      arr\n");
   printf("Array address:   %p\n", (void *)arr);
   printf("Pointer value:   %p (points to arr[0])\n", (void *)ptr);
   printf("First element:   *ptr = %d\n", *ptr);
   printf("Second element:  *(ptr+1) = %d\n", *(ptr + 1));
   printf("\nRelationship:\n");
   printf("  arr[i]  ≡  *(arr + i)  ≡  *(ptr + i)  ≡  ptr[i]\n");
   printf("  &arr[i] ≡  (arr + i)   ≡  (ptr + i)\n");

   printf("\n========================================\n");
   printf("  Display Methods Using Pointers\n");
   printf("========================================\n\n");

   // Method 1
   displayArrayMethod1(ptr, size);
   printf("\n");

   // Method 2
   displayArrayMethod2(ptr, size);
   printf("\n");

   // Method 3
   displayArrayMethod3(ptr, size);

   printf("\n========================================\n");
   printf("  Pointer Arithmetic Demonstration\n");
   printf("========================================\n\n");

   printf("Starting pointer: %p (points to arr[0])\n\n", (void *)ptr);

   printf("Pointer arithmetic:\n");
   for (int i = 0; i < size; i++) {
      printf("  ptr + %d = %p, value = %d\n",
             i, (void *)(ptr + i), *(ptr + i));
   }

   printf("\nSize of int: %lu bytes\n", sizeof(int));
   printf("Address difference between elements: %lu bytes\n",
          (unsigned long)((char *)(ptr + 1) - (char *)ptr));

   printf("\n========================================\n");
   printf("  Array Operations Using Pointers\n");
   printf("========================================\n\n");

   int sum = findSum(ptr, size);
   int max = findMax(ptr, size);

   printf("Sum of elements:  %d\n", sum);
   printf("Maximum element:  %d\n", max);
   printf("Average:          %.2f\n", (float)sum / size);

   printf("\n========================================\n");
   printf("  Reversing Array Using Pointers\n");
   printf("========================================\n\n");

   printf("Before reverse: ");
   for (int i = 0; i < size; i++) {
      printf("%d ", *(ptr + i));
   }
   printf("\n");

   reverseArray(ptr, size);

   printf("After reverse:  ");
   for (int i = 0; i < size; i++) {
      printf("%d ", *(ptr + i));
   }
   printf("\n");

   printf("\n========================================\n");
   printf("  Memory Layout\n");
   printf("========================================\n\n");

   printf("Index  Address        Value\n");
   printf("-----  -------------  -----\n");
   for (int i = 0; i < size; i++) {
      printf("%-5d  %p  %5d\n", i, (void *)(ptr + i), *(ptr + i));
   }

   printf("\n========================================\n");
   printf("  Summary\n");
   printf("========================================\n");
   printf("Array size: %d elements\n", size);
   printf("Total memory: %lu bytes\n", size * sizeof(int));
   printf("Pointer used: Successfully!\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Size: 5
 *   Elements: 10, 20, 30, 40, 50
 * Output:
 * ========================================
 *   Integer Array Using Pointers
 * ========================================
 *
 * This program demonstrates array manipulation
 * using pointers in various ways.
 *
 * Enter the size of array (max 100): 5
 *
 * ========================================
 *   Reading Array Using Pointer
 * ========================================
 *
 * Enter 5 elements:
 * Element [0]: 10
 * Element [1]: 20
 * Element [2]: 30
 * Element [3]: 40
 * Element [4]: 50
 *
 * ========================================
 *   Pointer Concepts
 * ========================================
 *
 * Array name:      arr
 * Array address:   0x7ffeeb3a8c60
 * Pointer value:   0x7ffeeb3a8c60 (points to arr[0])
 * First element:   *ptr = 10
 * Second element:  *(ptr+1) = 20
 *
 * Relationship:
 *   arr[i]  ≡  *(arr + i)  ≡  *(ptr + i)  ≡  ptr[i]
 *   &arr[i] ≡  (arr + i)   ≡  (ptr + i)
 *
 * ========================================
 *   Display Methods Using Pointers
 * ========================================
 *
 * Method 1 - Using *(ptr + i):
 *   arr[0] = 10 (at address 0x7ffeeb3a8c60)
 *   arr[1] = 20 (at address 0x7ffeeb3a8c64)
 *   arr[2] = 30 (at address 0x7ffeeb3a8c68)
 *   arr[3] = 40 (at address 0x7ffeeb3a8c6c)
 *   arr[4] = 50 (at address 0x7ffeeb3a8c70)
 *
 * Method 2 - Using *ptr and ptr++:
 *   arr[0] = 10 (at address 0x7ffeeb3a8c60)
 *   arr[1] = 20 (at address 0x7ffeeb3a8c64)
 *   arr[2] = 30 (at address 0x7ffeeb3a8c68)
 *   arr[3] = 40 (at address 0x7ffeeb3a8c6c)
 *   arr[4] = 50 (at address 0x7ffeeb3a8c70)
 *
 * Method 3 - Using ptr[i] (subscript notation):
 *   arr[0] = 10 (at address 0x7ffeeb3a8c60)
 *   arr[1] = 20 (at address 0x7ffeeb3a8c64)
 *   arr[2] = 30 (at address 0x7ffeeb3a8c68)
 *   arr[3] = 40 (at address 0x7ffeeb3a8c6c)
 *   arr[4] = 50 (at address 0x7ffeeb3a8c70)
 *
 * ========================================
 *   Pointer Arithmetic Demonstration
 * ========================================
 *
 * Starting pointer: 0x7ffeeb3a8c60 (points to arr[0])
 *
 * Pointer arithmetic:
 *   ptr + 0 = 0x7ffeeb3a8c60, value = 10
 *   ptr + 1 = 0x7ffeeb3a8c64, value = 20
 *   ptr + 2 = 0x7ffeeb3a8c68, value = 30
 *   ptr + 3 = 0x7ffeeb3a8c6c, value = 40
 *   ptr + 4 = 0x7ffeeb3a8c70, value = 50
 *
 * Size of int: 4 bytes
 * Address difference between elements: 4 bytes
 *
 * ========================================
 *   Array Operations Using Pointers
 * ========================================
 *
 * Sum of elements:  150
 * Maximum element:  50
 * Average:          30.00
 *
 * ========================================
 *   Reversing Array Using Pointers
 * ========================================
 *
 * Before reverse: 10 20 30 40 50
 * After reverse:  50 40 30 20 10
 *
 * ========================================
 *   Memory Layout
 * ========================================
 *
 * Index  Address        Value
 * -----  -------------  -----
 * 0      0x7ffeeb3a8c60     50
 * 1      0x7ffeeb3a8c64     40
 * 2      0x7ffeeb3a8c68     30
 * 3      0x7ffeeb3a8c6c     20
 * 4      0x7ffeeb3a8c70     10
 *
 * ========================================
 *   Summary
 * ========================================
 * Array size: 5 elements
 * Total memory: 20 bytes
 * Pointer used: Successfully!
 * ========================================
 */
