/*
 * QUESTION xliii:
 * Write a C program to write records of students to a file using
 * array of structures and display them accordingly.
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates file handling with structures:
 * 1. Define a Student structure with multiple fields
 * 2. Create an array of Student structures
 * 3. Accept student data from user
 * 4. Write all records to a file (binary and text formats)
 * 5. Read records from file
 * 6. Display records in formatted manner
 * 7. Search and sort operations on file records
 *
 * Features:
 * - Binary file operations for efficient storage
 * - Text file operations for human-readable format
 * - Display with formatting and statistics
 * - Search by roll number or name
 * - Sort by marks or name
 *
 * HOW TO SOLVE:
 * 1. Define Student structure with fields (roll, name, marks, etc.)
 * 2. Create array of structures
 * 3. Input student data:
 *    - Read number of students
 *    - Input details for each student
 * 4. Write to file:
 *    - Open file in write mode ("wb" for binary, "w" for text)
 *    - Use fwrite() for binary or fprintf() for text
 *    - Write entire array or record by record
 * 5. Read from file:
 *    - Open file in read mode ("rb" for binary, "r" for text)
 *    - Use fread() for binary or fscanf() for text
 *    - Read into array of structures
 * 6. Display records:
 *    - Format output with proper alignment
 *    - Show statistics (average, highest, lowest)
 * 7. Close files properly
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define BINARY_FILE "students.dat"
#define TEXT_FILE "students.txt"

// Student structure definition
typedef struct {
   int rollNumber;
   char name[NAME_LENGTH];
   int age;
   float marks[3]; // Marks in 3 subjects
   float total;
   float percentage;
   char grade;
} Student;

// Function to calculate total, percentage, and grade
void calculateResults(Student *s) {
   s->total = s->marks[0] + s->marks[1] + s->marks[2];
   s->percentage = s->total / 3.0;

   if (s->percentage >= 90)
      s->grade = 'A';
   else if (s->percentage >= 80)
      s->grade = 'B';
   else if (s->percentage >= 70)
      s->grade = 'C';
   else if (s->percentage >= 60)
      s->grade = 'D';
   else if (s->percentage >= 50)
      s->grade = 'E';
   else
      s->grade = 'F';
}

// Function to input student data
void inputStudent(Student *s, int rollNo) {
   s->rollNumber = rollNo;

   printf("\n--- Student %d ---\n", rollNo);

   printf("Enter name: ");
   getchar(); // Clear newline from previous input
   fgets(s->name, NAME_LENGTH, stdin);
   s->name[strcspn(s->name, "\n")] = '\0'; // Remove newline

   printf("Enter age: ");
   scanf("%d", &s->age);

   printf("Enter marks in 3 subjects:\n");
   for (int i = 0; i < 3; i++) {
      printf("  Subject %d: ", i + 1);
      scanf("%f", &s->marks[i]);
   }

   calculateResults(s);
}

// Function to display a single student record
void displayStudent(Student s, int index) {
   printf("│ %-3d │ %-4d │ %-20s │ %-3d │",
          index, s.rollNumber, s.name, s.age);

   for (int i = 0; i < 3; i++) {
      printf(" %5.1f │", s.marks[i]);
   }

   printf(" %6.1f │ %6.2f%% │ %5c │\n",
          s.total, s.percentage, s.grade);
}

// Function to display all students in formatted table
void displayAllStudents(Student students[], int count) {
   printf("\n========================================");
   printf("========================================");
   printf("========================================\n");
   printf("                              STUDENT RECORDS\n");
   printf("========================================");
   printf("========================================");
   printf("========================================\n\n");

   printf("┌─────┬──────┬──────────────────────┬─────┬───────┬───────┬───────┬────────┬──────────┬───────┐\n");
   printf("│ No. │ Roll │ Name                 │ Age │ Sub-1 │ Sub-2 │ Sub-3 │ Total  │ Percent  │ Grade │\n");
   printf("├─────┼──────┼──────────────────────┼─────┼───────┼───────┼───────┼────────┼──────────┼───────┤\n");

   for (int i = 0; i < count; i++) {
      displayStudent(students[i], i + 1);
   }

   printf("└─────┴──────┴──────────────────────┴─────┴───────┴───────┴───────┴────────┴──────────┴───────┘\n");
}

// Function to write students to binary file
int writeStudentsBinary(Student students[], int count) {
   FILE *fp;

   fp = fopen(BINARY_FILE, "wb");
   if (fp == NULL) {
      printf("Error: Cannot create binary file!\n");
      return 0;
   }

   // Write count first
   fwrite(&count, sizeof(int), 1, fp);

   // Write all student records
   fwrite(students, sizeof(Student), count, fp);

   fclose(fp);

   printf("\n✓ %d student records written to '%s' (binary format)\n", count, BINARY_FILE);
   return 1;
}

// Function to read students from binary file
int readStudentsBinary(Student students[]) {
   FILE *fp;
   int count;

   fp = fopen(BINARY_FILE, "rb");
   if (fp == NULL) {
      printf("Error: Cannot open binary file!\n");
      return 0;
   }

   // Read count first
   fread(&count, sizeof(int), 1, fp);

   // Read all student records
   fread(students, sizeof(Student), count, fp);

   fclose(fp);

   printf("\n✓ %d student records read from '%s' (binary format)\n", count, BINARY_FILE);
   return count;
}

// Function to write students to text file
int writeStudentsText(Student students[], int count) {
   FILE *fp;

   fp = fopen(TEXT_FILE, "w");
   if (fp == NULL) {
      printf("Error: Cannot create text file!\n");
      return 0;
   }

   // Write header
   fprintf(fp, "STUDENT RECORDS\n");
   fprintf(fp, "===============\n\n");
   fprintf(fp, "Total Students: %d\n\n", count);

   // Write each student record
   for (int i = 0; i < count; i++) {
      fprintf(fp, "Student %d:\n", i + 1);
      fprintf(fp, "  Roll Number: %d\n", students[i].rollNumber);
      fprintf(fp, "  Name: %s\n", students[i].name);
      fprintf(fp, "  Age: %d\n", students[i].age);
      fprintf(fp, "  Subject 1: %.1f\n", students[i].marks[0]);
      fprintf(fp, "  Subject 2: %.1f\n", students[i].marks[1]);
      fprintf(fp, "  Subject 3: %.1f\n", students[i].marks[2]);
      fprintf(fp, "  Total: %.1f\n", students[i].total);
      fprintf(fp, "  Percentage: %.2f%%\n", students[i].percentage);
      fprintf(fp, "  Grade: %c\n", students[i].grade);
      fprintf(fp, "\n");
   }

   fclose(fp);

   printf("✓ %d student records written to '%s' (text format)\n", count, TEXT_FILE);
   return 1;
}

// Function to display statistics
void displayStatistics(Student students[], int count) {
   if (count == 0) {
      printf("\nNo students to analyze!\n");
      return;
   }

   float totalPercentage = 0;
   float highest = students[0].percentage;
   float lowest = students[0].percentage;
   int highestIndex = 0, lowestIndex = 0;
   int gradeCount[6] = {0}; // A, B, C, D, E, F

   for (int i = 0; i < count; i++) {
      totalPercentage += students[i].percentage;

      if (students[i].percentage > highest) {
         highest = students[i].percentage;
         highestIndex = i;
      }

      if (students[i].percentage < lowest) {
         lowest = students[i].percentage;
         lowestIndex = i;
      }

      // Count grades
      switch (students[i].grade) {
      case 'A':
         gradeCount[0]++;
         break;
      case 'B':
         gradeCount[1]++;
         break;
      case 'C':
         gradeCount[2]++;
         break;
      case 'D':
         gradeCount[3]++;
         break;
      case 'E':
         gradeCount[4]++;
         break;
      case 'F':
         gradeCount[5]++;
         break;
      }
   }

   printf("\n========================================\n");
   printf("  CLASS STATISTICS\n");
   printf("========================================\n\n");

   printf("Total Students: %d\n\n", count);

   printf("--- Performance ---\n");
   printf("Average Percentage: %.2f%%\n", totalPercentage / count);
   printf("Highest Score: %.2f%% (%s)\n", highest, students[highestIndex].name);
   printf("Lowest Score: %.2f%% (%s)\n", lowest, students[lowestIndex].name);

   printf("\n--- Grade Distribution ---\n");
   printf("Grade A (90-100): %d students\n", gradeCount[0]);
   printf("Grade B (80-89):  %d students\n", gradeCount[1]);
   printf("Grade C (70-79):  %d students\n", gradeCount[2]);
   printf("Grade D (60-69):  %d students\n", gradeCount[3]);
   printf("Grade E (50-59):  %d students\n", gradeCount[4]);
   printf("Grade F (0-49):   %d students\n", gradeCount[5]);

   printf("\n--- Pass/Fail ---\n");
   int passed = count - gradeCount[5];
   printf("Passed: %d (%.1f%%)\n", passed, (passed * 100.0) / count);
   printf("Failed: %d (%.1f%%)\n", gradeCount[5], (gradeCount[5] * 100.0) / count);
}

// Function to search student by roll number
void searchByRoll(Student students[], int count, int rollNo) {
   printf("\n========================================\n");
   printf("  SEARCH RESULT (Roll Number: %d)\n", rollNo);
   printf("========================================\n");

   for (int i = 0; i < count; i++) {
      if (students[i].rollNumber == rollNo) {
         printf("\n✓ Student Found!\n\n");
         printf("Roll Number: %d\n", students[i].rollNumber);
         printf("Name: %s\n", students[i].name);
         printf("Age: %d\n", students[i].age);
         printf("Marks: %.1f, %.1f, %.1f\n",
                students[i].marks[0], students[i].marks[1], students[i].marks[2]);
         printf("Total: %.1f\n", students[i].total);
         printf("Percentage: %.2f%%\n", students[i].percentage);
         printf("Grade: %c\n", students[i].grade);
         return;
      }
   }

   printf("\n✗ Student with Roll Number %d not found!\n", rollNo);
}

// Function to sort students by percentage (descending)
void sortByPercentage(Student students[], int count) {
   Student temp;

   for (int i = 0; i < count - 1; i++) {
      for (int j = 0; j < count - i - 1; j++) {
         if (students[j].percentage < students[j + 1].percentage) {
            temp = students[j];
            students[j] = students[j + 1];
            students[j + 1] = temp;
         }
      }
   }

   printf("\n✓ Students sorted by percentage (highest to lowest)\n");
}

// Function to create sample data
void createSampleData(Student students[], int *count) {
   *count = 5;

   // Student 1
   students[0].rollNumber = 101;
   strcpy(students[0].name, "Alice Johnson");
   students[0].age = 20;
   students[0].marks[0] = 85.0;
   students[0].marks[1] = 90.0;
   students[0].marks[2] = 88.0;
   calculateResults(&students[0]);

   // Student 2
   students[1].rollNumber = 102;
   strcpy(students[1].name, "Bob Smith");
   students[1].age = 21;
   students[1].marks[0] = 92.0;
   students[1].marks[1] = 95.0;
   students[1].marks[2] = 93.0;
   calculateResults(&students[1]);

   // Student 3
   students[2].rollNumber = 103;
   strcpy(students[2].name, "Carol Williams");
   students[2].age = 19;
   students[2].marks[0] = 78.0;
   students[2].marks[1] = 82.0;
   students[2].marks[2] = 75.0;
   calculateResults(&students[2]);

   // Student 4
   students[3].rollNumber = 104;
   strcpy(students[3].name, "David Brown");
   students[3].age = 22;
   students[3].marks[0] = 65.0;
   students[3].marks[1] = 70.0;
   students[3].marks[2] = 68.0;
   calculateResults(&students[3]);

   // Student 5
   students[4].rollNumber = 105;
   strcpy(students[4].name, "Emma Davis");
   students[4].age = 20;
   students[4].marks[0] = 45.0;
   students[4].marks[1] = 50.0;
   students[4].marks[2] = 48.0;
   calculateResults(&students[4]);

   printf("\n✓ Sample data created for %d students\n", *count);
}

int main() {
   Student students[MAX_STUDENTS];
   int count = 0;
   int choice;

   printf("========================================\n");
   printf("  Student Records File Management\n");
   printf("========================================\n\n");

   printf("Choose data input method:\n");
   printf("1. Enter student data manually\n");
   printf("2. Use sample data\n");
   printf("Enter choice (1 or 2): ");
   scanf("%d", &choice);

   if (choice == 2) {
      createSampleData(students, &count);
   } else {
      printf("\nEnter number of students: ");
      scanf("%d", &count);

      if (count <= 0 || count > MAX_STUDENTS) {
         printf("Invalid number of students!\n");
         return 1;
      }

      for (int i = 0; i < count; i++) {
         inputStudent(&students[i], 101 + i);
      }
   }

   // Display entered data
   displayAllStudents(students, count);

   // Write to binary file
   printf("\n========================================\n");
   printf("  WRITING TO FILES\n");
   printf("========================================\n");
   writeStudentsBinary(students, count);
   writeStudentsText(students, count);

   // Read from binary file and display
   printf("\n========================================\n");
   printf("  READING FROM FILE\n");
   printf("========================================\n");

   Student readStudents[MAX_STUDENTS];
   int readCount = readStudentsBinary(readStudents);

   if (readCount > 0) {
      printf("\nDisplaying records read from file:\n");
      displayAllStudents(readStudents, readCount);
   }

   // Display statistics
   displayStatistics(readStudents, readCount);

   // Search example
   printf("\n========================================\n");
   printf("  SEARCH DEMONSTRATION\n");
   printf("========================================\n");
   searchByRoll(readStudents, readCount, 103);

   // Sort and display
   printf("\n========================================\n");
   printf("  SORTING DEMONSTRATION\n");
   printf("========================================\n");
   sortByPercentage(readStudents, readCount);
   displayAllStudents(readStudents, readCount);

   printf("\n========================================\n");
   printf("  SUMMARY\n");
   printf("========================================\n");
   printf("Total students processed: %d\n", count);
   printf("Files created:\n");
   printf("  • %s (binary format)\n", BINARY_FILE);
   printf("  • %s (text format)\n", TEXT_FILE);
   printf("Operations performed:\n");
   printf("  ✓ Data input\n");
   printf("  ✓ File writing (binary & text)\n");
   printf("  ✓ File reading\n");
   printf("  ✓ Statistics calculation\n");
   printf("  ✓ Search by roll number\n");
   printf("  ✓ Sorting by percentage\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1: (Using sample data)
 * Input:
 *   Choice: 2
 * Output:
 * ========================================
 *   Student Records File Management
 * ========================================
 *
 * Choose data input method:
 * 1. Enter student data manually
 * 2. Use sample data
 * Enter choice (1 or 2): 2
 *
 * ✓ Sample data created for 5 students
 *
 * ================================================================================================================================================
 *                               STUDENT RECORDS
 * ================================================================================================================================================
 *
 * ┌─────┬──────┬──────────────────────┬─────┬───────┬───────┬───────┬────────┬──────────┬───────┐
 * │ No. │ Roll │ Name                 │ Age │ Sub-1 │ Sub-2 │ Sub-3 │ Total  │ Percent  │ Grade │
 * ├─────┼──────┼──────────────────────┼─────┼───────┼───────┼───────┼────────┼──────────┼───────┤
 * │ 1   │ 101  │ Alice Johnson        │ 20  │  85.0 │  90.0 │  88.0 │  263.0 │  87.67%  │   B   │
 * │ 2   │ 102  │ Bob Smith            │ 21  │  92.0 │  95.0 │  93.0 │  280.0 │  93.33%  │   A   │
 * │ 3   │ 103  │ Carol Williams       │ 19  │  78.0 │  82.0 │  75.0 │  235.0 │  78.33%  │   C   │
 * │ 4   │ 104  │ David Brown          │ 22  │  65.0 │  70.0 │  68.0 │  203.0 │  67.67%  │   D   │
 * │ 5   │ 105  │ Emma Davis           │ 20  │  45.0 │  50.0 │  48.0 │  143.0 │  47.67%  │   F   │
 * └─────┴──────┴──────────────────────┴─────┴───────┴───────┴───────┴────────┴──────────┴───────┘
 *
 * ========================================
 *   WRITING TO FILES
 * ========================================
 *
 * ✓ 5 student records written to 'students.dat' (binary format)
 * ✓ 5 student records written to 'students.txt' (text format)
 *
 * ========================================
 *   READING FROM FILE
 * ========================================
 *
 * ✓ 5 student records read from 'students.dat' (binary format)
 *
 * Displaying records read from file:
 *
 * ================================================================================================================================================
 *                               STUDENT RECORDS
 * ================================================================================================================================================
 *
 * ┌─────┬──────┬──────────────────────┬─────┬───────┬───────┬───────┬────────┬──────────┬───────┐
 * │ No. │ Roll │ Name                 │ Age │ Sub-1 │ Sub-2 │ Sub-3 │ Total  │ Percent  │ Grade │
 * ├─────┼──────┼──────────────────────┼─────┼───────┼───────┼───────┼────────┼──────────┼───────┤
 * │ 1   │ 101  │ Alice Johnson        │ 20  │  85.0 │  90.0 │  88.0 │  263.0 │  87.67%  │   B   │
 * │ 2   │ 102  │ Bob Smith            │ 21  │  92.0 │  95.0 │  93.0 │  280.0 │  93.33%  │   A   │
 * │ 3   │ 103  │ Carol Williams       │ 19  │  78.0 │  82.0 │  75.0 │  235.0 │  78.33%  │   C   │
 * │ 4   │ 104  │ David Brown          │ 22  │  65.0 │  70.0 │  68.0 │  203.0 │  67.67%  │   D   │
 * │ 5   │ 105  │ Emma Davis           │ 20  │  45.0 │  50.0 │  48.0 │  143.0 │  47.67%  │   F   │
 * └─────┴──────┴──────────────────────┴─────┴───────┴───────┴───────┴────────┴──────────┴───────┘
 *
 * ========================================
 *   CLASS STATISTICS
 * ========================================
 *
 * Total Students: 5
 *
 * --- Performance ---
 * Average Percentage: 74.93%
 * Highest Score: 93.33% (Bob Smith)
 * Lowest Score: 47.67% (Emma Davis)
 *
 * --- Grade Distribution ---
 * Grade A (90-100): 1 students
 * Grade B (80-89):  1 students
 * Grade C (70-79):  1 students
 * Grade D (60-69):  1 students
 * Grade E (50-59):  0 students
 * Grade F (0-49):   1 students
 *
 * --- Pass/Fail ---
 * Passed: 4 (80.0%)
 * Failed: 1 (20.0%)
 *
 * ========================================
 *   SEARCH DEMONSTRATION
 * ========================================
 *
 * ========================================
 *   SEARCH RESULT (Roll Number: 103)
 * ========================================
 *
 * ✓ Student Found!
 *
 * Roll Number: 103
 * Name: Carol Williams
 * Age: 19
 * Marks: 78.0, 82.0, 75.0
 * Total: 235.0
 * Percentage: 78.33%
 * Grade: C
 *
 * ========================================
 *   SORTING DEMONSTRATION
 * ========================================
 *
 * ✓ Students sorted by percentage (highest to lowest)
 *
 * ================================================================================================================================================
 *                               STUDENT RECORDS
 * ================================================================================================================================================
 *
 * ┌─────┬──────┬──────────────────────┬─────┬───────┬───────┬───────┬────────┬──────────┬───────┐
 * │ No. │ Roll │ Name                 │ Age │ Sub-1 │ Sub-2 │ Sub-3 │ Total  │ Percent  │ Grade │
 * ├─────┼──────┼──────────────────────┼─────┼───────┼───────┼───────┼────────┼──────────┼───────┤
 * │ 1   │ 102  │ Bob Smith            │ 21  │  92.0 │  95.0 │  93.0 │  280.0 │  93.33%  │   A   │
 * │ 2   │ 101  │ Alice Johnson        │ 20  │  85.0 │  90.0 │  88.0 │  263.0 │  87.67%  │   B   │
 * │ 3   │ 103  │ Carol Williams       │ 19  │  78.0 │  82.0 │  75.0 │  235.0 │  78.33%  │   C   │
 * │ 4   │ 104  │ David Brown          │ 22  │  65.0 │  70.0 │  68.0 │  203.0 │  67.67%  │   D   │
 * │ 5   │ 105  │ Emma Davis           │ 20  │  45.0 │  50.0 │  48.0 │  143.0 │  47.67%  │   F   │
 * └─────┴──────┴──────────────────────┴─────┴───────┴───────┴───────┴────────┴──────────┴───────┘
 *
 * ========================================
 *   SUMMARY
 * ========================================
 * Total students processed: 5
 * Files created:
 *   • students.dat (binary format)
 *   • students.txt (text format)
 * Operations performed:
 *   ✓ Data input
 *   ✓ File writing (binary & text)
 *   ✓ File reading
 *   ✓ Statistics calculation
 *   ✓ Search by roll number
 *   ✓ Sorting by percentage
 * ========================================
 */
