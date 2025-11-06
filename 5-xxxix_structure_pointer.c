/*
 * QUESTION xxxix:
 * Write a C program to read and display the contents of a structure variable
 * using pointer to a structure.
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates the use of structure pointers in C.
 * It shows how to:
 * - Access structure members using pointer (-> operator)
 * - Pass structures to functions using pointers
 * - Dynamically allocate memory for structures
 * - Manipulate structure data through pointers
 *
 * Structure pointer concepts:
 * - ptr->member is equivalent to (*ptr).member
 * - Arrow operator (->) is used to access members via pointer
 * - More efficient to pass structure pointer than entire structure
 *
 * The program creates a Student structure with:
 * - Roll number
 * - Name
 * - Marks in multiple subjects
 * - Grade
 *
 * HOW TO SOLVE:
 * 1. Define a structure (e.g., Student)
 * 2. Declare structure variable and pointer to structure
 * 3. Point the pointer to the structure variable
 * 4. Use -> operator to access and modify members
 * 5. Create functions that accept structure pointers
 * 6. Demonstrate both . and -> operators
 * 7. Show address and memory layout
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
typedef struct {
   int rollNumber;
   char name[50];
   int age;
   float marks[5]; // Marks in 5 subjects
   float total;
   float average;
   char grade;
} Student;

// Structure to represent a point (for additional demonstration)
typedef struct {
   int x;
   int y;
} Point;

// Function to read student data using pointer
void readStudent(Student *ptr) {
   printf("Enter Student Details:\n");

   printf("  Roll Number: ");
   scanf("%d", &ptr->rollNumber);

   printf("  Name: ");
   getchar(); // Clear newline
   fgets(ptr->name, sizeof(ptr->name), stdin);
   ptr->name[strcspn(ptr->name, "\n")] = '\0'; // Remove newline

   printf("  Age: ");
   scanf("%d", &ptr->age);

   printf("  Enter marks in 5 subjects:\n");
   ptr->total = 0;
   for (int i = 0; i < 5; i++) {
      printf("    Subject %d: ", i + 1);
      scanf("%f", &ptr->marks[i]);
      ptr->total += ptr->marks[i];
   }

   // Calculate average
   ptr->average = ptr->total / 5.0;

   // Assign grade based on average
   if (ptr->average >= 90) {
      ptr->grade = 'A';
   } else if (ptr->average >= 80) {
      ptr->grade = 'B';
   } else if (ptr->average >= 70) {
      ptr->grade = 'C';
   } else if (ptr->average >= 60) {
      ptr->grade = 'D';
   } else if (ptr->average >= 50) {
      ptr->grade = 'E';
   } else {
      ptr->grade = 'F';
   }
}

// Function to display student data using pointer
void displayStudent(Student *ptr) {
   printf("\n========================================\n");
   printf("  Student Information\n");
   printf("========================================\n\n");

   printf("Roll Number:  %d\n", ptr->rollNumber);
   printf("Name:         %s\n", ptr->name);
   printf("Age:          %d years\n", ptr->age);

   printf("\nMarks:\n");
   for (int i = 0; i < 5; i++) {
      printf("  Subject %d:  %.2f", i + 1, ptr->marks[i]);

      // Show bar graph
      printf("  [");
      int bars = (int)(ptr->marks[i] / 5);
      for (int j = 0; j < bars; j++) {
         printf("■");
      }
      printf("]\n");
   }

   printf("\nResults:\n");
   printf("  Total:      %.2f / 500.00\n", ptr->total);
   printf("  Average:    %.2f%%\n", ptr->average);
   printf("  Grade:      %c\n", ptr->grade);

   // Performance assessment
   printf("\nPerformance: ");
   if (ptr->average >= 90) {
      printf("Excellent! Outstanding performance!\n");
   } else if (ptr->average >= 80) {
      printf("Very Good! Keep up the good work!\n");
   } else if (ptr->average >= 70) {
      printf("Good. Room for improvement.\n");
   } else if (ptr->average >= 60) {
      printf("Satisfactory. Need more effort.\n");
   } else if (ptr->average >= 50) {
      printf("Pass. Significant improvement needed.\n");
   } else {
      printf("Fail. Major improvement required.\n");
   }
}

// Function to display structure using both . and -> operators
void demonstrateAccess(Student *ptr, Student student) {
   printf("\n========================================\n");
   printf("  Demonstrating Structure Access\n");
   printf("========================================\n\n");

   printf("Using DOT operator (.):\n");
   printf("  student.rollNumber = %d\n", student.rollNumber);
   printf("  student.name = %s\n", student.name);
   printf("  student.average = %.2f\n", student.average);

   printf("\nUsing ARROW operator (->):\n");
   printf("  ptr->rollNumber = %d\n", ptr->rollNumber);
   printf("  ptr->name = %s\n", ptr->name);
   printf("  ptr->average = %.2f\n", ptr->average);

   printf("\nUsing (*ptr).member notation:\n");
   printf("  (*ptr).rollNumber = %d\n", (*ptr).rollNumber);
   printf("  (*ptr).name = %s\n", (*ptr).name);
   printf("  (*ptr).average = %.2f\n", (*ptr).average);

   printf("\nNote: ptr->member is equivalent to (*ptr).member\n");
}

// Function to display memory layout
void displayMemoryLayout(Student *ptr) {
   printf("\n========================================\n");
   printf("  Memory Layout and Addresses\n");
   printf("========================================\n\n");

   printf("Structure Address: %p\n", (void *)ptr);
   printf("Size of Student:   %lu bytes\n\n", sizeof(Student));

   printf("Member Addresses:\n");
   printf("  rollNumber:  %p (offset: %lu)\n",
          (void *)&ptr->rollNumber,
          (char *)&ptr->rollNumber - (char *)ptr);
   printf("  name:        %p (offset: %lu)\n",
          (void *)&ptr->name,
          (char *)&ptr->name - (char *)ptr);
   printf("  age:         %p (offset: %lu)\n",
          (void *)&ptr->age,
          (char *)&ptr->age - (char *)ptr);
   printf("  marks[0]:    %p (offset: %lu)\n",
          (void *)&ptr->marks[0],
          (char *)&ptr->marks[0] - (char *)ptr);
   printf("  total:       %p (offset: %lu)\n",
          (void *)&ptr->total,
          (char *)&ptr->total - (char *)ptr);
   printf("  average:     %p (offset: %lu)\n",
          (void *)&ptr->average,
          (char *)&ptr->average - (char *)ptr);
   printf("  grade:       %p (offset: %lu)\n",
          (void *)&ptr->grade,
          (char *)&ptr->grade - (char *)ptr);
}

// Additional demonstration with Point structure
void demonstratePoint() {
   printf("\n========================================\n");
   printf("  Additional Demo: Point Structure\n");
   printf("========================================\n\n");

   Point p1 = {10, 20};
   Point *pPtr = &p1;

   printf("Point p1 created at (%d, %d)\n", p1.x, p1.y);
   printf("Address of p1: %p\n\n", (void *)&p1);

   printf("Accessing via pointer:\n");
   printf("  pPtr->x = %d\n", pPtr->x);
   printf("  pPtr->y = %d\n", pPtr->y);

   printf("\nModifying via pointer:\n");
   pPtr->x = 50;
   pPtr->y = 60;
   printf("  After pPtr->x = 50; pPtr->y = 60;\n");
   printf("  Point is now at (%d, %d)\n", p1.x, p1.y);
   printf("  Original p1 is modified!\n");

   // Dynamic allocation
   printf("\nDynamic allocation of Point:\n");
   Point *p2 = (Point *)malloc(sizeof(Point));
   p2->x = 100;
   p2->y = 200;
   printf("  Dynamically allocated point at (%d, %d)\n", p2->x, p2->y);
   printf("  Address: %p\n", (void *)p2);

   free(p2);
   printf("  Memory freed.\n");
}

int main() {
   Student student1;
   Student *ptr;

   printf("========================================\n");
   printf("  Structure Pointer Demonstration\n");
   printf("========================================\n\n");

   printf("This program demonstrates accessing\n");
   printf("structure members using pointers.\n\n");

   // Point to the structure
   ptr = &student1;

   printf("Structure variable address: %p\n", (void *)&student1);
   printf("Pointer value (points to):  %p\n", (void *)ptr);
   printf("They are the same! ✓\n\n");

   // Read student data using pointer
   readStudent(ptr);

   // Display student data using pointer
   displayStudent(ptr);

   // Demonstrate different access methods
   demonstrateAccess(ptr, student1);

   // Display memory layout
   displayMemoryLayout(ptr);

   // Additional demonstration
   demonstratePoint();

   printf("\n========================================\n");
   printf("  Key Concepts Summary\n");
   printf("========================================\n\n");

   printf("Structure Pointer Syntax:\n");
   printf("  Declaration:   Student *ptr;\n");
   printf("  Assignment:    ptr = &student1;\n");
   printf("  Access member: ptr->member\n");
   printf("  Equivalent to: (*ptr).member\n\n");

   printf("Advantages of Structure Pointers:\n");
   printf("  ✓ Efficient - passes address, not entire structure\n");
   printf("  ✓ Can modify original structure in functions\n");
   printf("  ✓ Enables dynamic memory allocation\n");
   printf("  ✓ Useful for linked data structures\n\n");

   printf("Operators:\n");
   printf("  .  (dot)      - Access member of structure variable\n");
   printf("  -> (arrow)    - Access member via structure pointer\n");
   printf("  &  (address)  - Get address of structure\n");
   printf("  *  (dereference) - Get value at pointer address\n");

   printf("\n========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Roll: 101
 *   Name: John Doe
 *   Age: 20
 *   Marks: 85, 90, 78, 92, 88
 * Output:
 * ========================================
 *   Structure Pointer Demonstration
 * ========================================
 *
 * This program demonstrates accessing
 * structure members using pointers.
 *
 * Structure variable address: 0x7ffeeb3a8c00
 * Pointer value (points to):  0x7ffeeb3a8c00
 * They are the same! ✓
 *
 * Enter Student Details:
 *   Roll Number: 101
 *   Name: John Doe
 *   Age: 20
 *   Enter marks in 5 subjects:
 *     Subject 1: 85
 *     Subject 2: 90
 *     Subject 3: 78
 *     Subject 4: 92
 *     Subject 5: 88
 *
 * ========================================
 *   Student Information
 * ========================================
 *
 * Roll Number:  101
 * Name:         John Doe
 * Age:          20 years
 *
 * Marks:
 *   Subject 1:  85.00  [■■■■■■■■■■■■■■■■■]
 *   Subject 2:  90.00  [■■■■■■■■■■■■■■■■■■]
 *   Subject 3:  78.00  [■■■■■■■■■■■■■■■]
 *   Subject 4:  92.00  [■■■■■■■■■■■■■■■■■■]
 *   Subject 5:  88.00  [■■■■■■■■■■■■■■■■■]
 *
 * Results:
 *   Total:      433.00 / 500.00
 *   Average:    86.60%
 *   Grade:      B
 *
 * Performance: Very Good! Keep up the good work!
 *
 * ========================================
 *   Demonstrating Structure Access
 * ========================================
 *
 * Using DOT operator (.):
 *   student.rollNumber = 101
 *   student.name = John Doe
 *   student.average = 86.60
 *
 * Using ARROW operator (->):
 *   ptr->rollNumber = 101
 *   ptr->name = John Doe
 *   ptr->average = 86.60
 *
 * Using (*ptr).member notation:
 *   (*ptr).rollNumber = 101
 *   (*ptr).name = John Doe
 *   (*ptr).average = 86.60
 *
 * Note: ptr->member is equivalent to (*ptr).member
 *
 * ========================================
 *   Memory Layout and Addresses
 * ========================================
 *
 * Structure Address: 0x7ffeeb3a8c00
 * Size of Student:   96 bytes
 *
 * Member Addresses:
 *   rollNumber:  0x7ffeeb3a8c00 (offset: 0)
 *   name:        0x7ffeeb3a8c04 (offset: 4)
 *   age:         0x7ffeeb3a8c36 (offset: 54)
 *   marks[0]:    0x7ffeeb3a8c3c (offset: 60)
 *   total:       0x7ffeeb3a8c50 (offset: 80)
 *   average:     0x7ffeeb3a8c54 (offset: 84)
 *   grade:       0x7ffeeb3a8c58 (offset: 88)
 *
 * ========================================
 *   Additional Demo: Point Structure
 * ========================================
 *
 * Point p1 created at (10, 20)
 * Address of p1: 0x7ffeeb3a8bf8
 *
 * Accessing via pointer:
 *   pPtr->x = 10
 *   pPtr->y = 20
 *
 * Modifying via pointer:
 *   After pPtr->x = 50; pPtr->y = 60;
 *   Point is now at (50, 60)
 *   Original p1 is modified!
 *
 * Dynamic allocation of Point:
 *   Dynamically allocated point at (100, 200)
 *   Address: 0x7fa8d8c05a00
 *   Memory freed.
 *
 * ========================================
 *   Key Concepts Summary
 * ========================================
 *
 * Structure Pointer Syntax:
 *   Declaration:   Student *ptr;
 *   Assignment:    ptr = &student1;
 *   Access member: ptr->member
 *   Equivalent to: (*ptr).member
 *
 * Advantages of Structure Pointers:
 *   ✓ Efficient - passes address, not entire structure
 *   ✓ Can modify original structure in functions
 *   ✓ Enables dynamic memory allocation
 *   ✓ Useful for linked data structures
 *
 * Operators:
 *   .  (dot)      - Access member of structure variable
 *   -> (arrow)    - Access member via structure pointer
 *   &  (address)  - Get address of structure
 *   *  (dereference) - Get value at pointer address
 *
 * ========================================
 */
