/*
 * QUESTION xliv:
 * Write a text menu-driven program to:
 * - Append a record
 * - Edit a particular record
 * - Display a predefined record
 * - Delete a particular record
 * from a previously created student file.
 *
 * PROGRAM DESCRIPTION:
 * This is a complete Student Database Management System with menu-driven interface.
 *
 * Features:
 * 1. ADD NEW RECORD - Append student to file
 * 2. DISPLAY ALL RECORDS - Show all students in formatted table
 * 3. SEARCH RECORD - Find student by roll number
 * 4. EDIT RECORD - Modify existing student details
 * 5. DELETE RECORD - Remove student from database
 * 6. DISPLAY STATISTICS - Show class performance stats
 * 7. SORT RECORDS - Sort by roll number or percentage
 * 8. EXIT - Close program
 *
 * File Operations:
 * - Binary file for efficient storage (students.dat)
 * - Read all records into memory
 * - Modify in memory
 * - Write back entire file
 *
 * HOW TO SOLVE:
 * 1. Define Student structure
 * 2. Create menu-driven interface with loop
 * 3. Implement functions for each operation:
 *
 *    ADD RECORD:
 *    - Read existing records from file
 *    - Input new student data
 *    - Append to array
 *    - Write entire array back to file
 *
 *    DISPLAY RECORDS:
 *    - Read all records from file
 *    - Display in formatted table
 *
 *    SEARCH RECORD:
 *    - Read all records
 *    - Search by roll number
 *    - Display if found
 *
 *    EDIT RECORD:
 *    - Read all records
 *    - Find record by roll number
 *    - Modify fields
 *    - Write back to file
 *
 *    DELETE RECORD:
 *    - Read all records
 *    - Find and remove from array
 *    - Write remaining records to file
 *
 * 4. Use switch-case for menu selection
 * 5. Validate input and handle errors
 * 6. Provide user-friendly messages
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define DATABASE_FILE "student_database.dat"

// Student structure
typedef struct {
   int rollNumber;
   char name[NAME_LENGTH];
   int age;
   char course[30];
   float marks[3];
   float total;
   float percentage;
   char grade;
} Student;

// Global variables
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void displayMenu();
void addRecord();
void displayAllRecords();
void searchRecord();
void editRecord();
void deleteRecord();
void displayStatistics();
void sortRecords();
int loadFromFile();
int saveToFile();
void calculateResults(Student *s);
void displayStudent(Student s, int index);
void displayTableHeader();
void displayTableFooter();
int findByRollNumber(int rollNo);
void clearInputBuffer();
void pressEnterToContinue();

// Main function
int main() {
   int choice;

   printf("╔════════════════════════════════════════════╗\n");
   printf("║   STUDENT DATABASE MANAGEMENT SYSTEM       ║\n");
   printf("╚════════════════════════════════════════════╝\n\n");

   // Load existing data
   loadFromFile();

   while (1) {
      displayMenu();
      printf("\nEnter your choice: ");

      if (scanf("%d", &choice) != 1) {
         clearInputBuffer();
         printf("\n✗ Invalid input! Please enter a number.\n");
         pressEnterToContinue();
         continue;
      }

      clearInputBuffer();

      switch (choice) {
      case 1:
         addRecord();
         break;
      case 2:
         displayAllRecords();
         break;
      case 3:
         searchRecord();
         break;
      case 4:
         editRecord();
         break;
      case 5:
         deleteRecord();
         break;
      case 6:
         displayStatistics();
         break;
      case 7:
         sortRecords();
         break;
      case 8:
         printf("\n╔════════════════════════════════════════════╗\n");
         printf("║  Thank you for using Student Database!     ║\n");
         printf("║  All changes saved to file.                ║\n");
         printf("╚════════════════════════════════════════════╝\n\n");
         return 0;
      default:
         printf("\n✗ Invalid choice! Please select 1-8.\n");
         pressEnterToContinue();
      }
   }

   return 0;
}

// Display main menu
void displayMenu() {
   printf("\n");
   printf("╔════════════════════════════════════════════╗\n");
   printf("║              MAIN MENU                     ║\n");
   printf("╠════════════════════════════════════════════╣\n");
   printf("║  1. Add New Student Record                 ║\n");
   printf("║  2. Display All Records                    ║\n");
   printf("║  3. Search Record (by Roll Number)         ║\n");
   printf("║  4. Edit Record                            ║\n");
   printf("║  5. Delete Record                          ║\n");
   printf("║  6. Display Statistics                     ║\n");
   printf("║  7. Sort Records                           ║\n");
   printf("║  8. Exit                                   ║\n");
   printf("╚════════════════════════════════════════════╝\n");
   printf("\nTotal Records: %d\n", studentCount);
}

// Add new student record
void addRecord() {
   printf("\n╔════════════════════════════════════════════╗\n");
   printf("║         ADD NEW STUDENT RECORD             ║\n");
   printf("╚════════════════════════════════════════════╝\n\n");

   if (studentCount >= MAX_STUDENTS) {
      printf("✗ Database is full! Cannot add more students.\n");
      pressEnterToContinue();
      return;
   }

   Student newStudent;

   // Input roll number
   printf("Enter Roll Number: ");
   scanf("%d", &newStudent.rollNumber);
   clearInputBuffer();

   // Check if roll number already exists
   if (findByRollNumber(newStudent.rollNumber) != -1) {
      printf("\n✗ Roll number %d already exists!\n", newStudent.rollNumber);
      pressEnterToContinue();
      return;
   }

   // Input name
   printf("Enter Name: ");
   fgets(newStudent.name, NAME_LENGTH, stdin);
   newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

   // Input age
   printf("Enter Age: ");
   scanf("%d", &newStudent.age);
   clearInputBuffer();

   // Input course
   printf("Enter Course: ");
   fgets(newStudent.course, 30, stdin);
   newStudent.course[strcspn(newStudent.course, "\n")] = '\0';

   // Input marks
   printf("Enter marks for 3 subjects:\n");
   for (int i = 0; i < 3; i++) {
      printf("  Subject %d: ", i + 1);
      scanf("%f", &newStudent.marks[i]);
   }
   clearInputBuffer();

   // Calculate results
   calculateResults(&newStudent);

   // Add to array
   students[studentCount] = newStudent;
   studentCount++;

   // Save to file
   if (saveToFile()) {
      printf("\n✓ Student record added successfully!\n");
      printf("  Roll Number: %d\n", newStudent.rollNumber);
      printf("  Name: %s\n", newStudent.name);
      printf("  Percentage: %.2f%%\n", newStudent.percentage);
      printf("  Grade: %c\n", newStudent.grade);
   }

   pressEnterToContinue();
}

// Display all records
void displayAllRecords() {
   printf("\n╔════════════════════════════════════════════════════════════");
   printf("════════════════════════════════════════════════════════════╗\n");
   printf("║                         ALL STUDENT RECORDS                ");
   printf("                                                            ║\n");
   printf("╚════════════════════════════════════════════════════════════");
   printf("════════════════════════════════════════════════════════════╝\n\n");

   if (studentCount == 0) {
      printf("✗ No records found in database!\n");
      pressEnterToContinue();
      return;
   }

   displayTableHeader();

   for (int i = 0; i < studentCount; i++) {
      displayStudent(students[i], i + 1);
   }

   displayTableFooter();

   printf("\nTotal Records: %d\n", studentCount);
   pressEnterToContinue();
}

// Search record by roll number
void searchRecord() {
   printf("\n╔════════════════════════════════════════════╗\n");
   printf("║           SEARCH STUDENT RECORD            ║\n");
   printf("╚════════════════════════════════════════════╝\n\n");

   int rollNo;
   printf("Enter Roll Number to search: ");
   scanf("%d", &rollNo);
   clearInputBuffer();

   int index = findByRollNumber(rollNo);

   if (index == -1) {
      printf("\n✗ Student with Roll Number %d not found!\n", rollNo);
   } else {
      printf("\n✓ Student Found!\n\n");
      displayTableHeader();
      displayStudent(students[index], index + 1);
      displayTableFooter();
   }

   pressEnterToContinue();
}

// Edit existing record
void editRecord() {
   printf("\n╔════════════════════════════════════════════╗\n");
   printf("║           EDIT STUDENT RECORD              ║\n");
   printf("╚════════════════════════════════════════════╝\n\n");

   int rollNo;
   printf("Enter Roll Number to edit: ");
   scanf("%d", &rollNo);
   clearInputBuffer();

   int index = findByRollNumber(rollNo);

   if (index == -1) {
      printf("\n✗ Student with Roll Number %d not found!\n", rollNo);
      pressEnterToContinue();
      return;
   }

   printf("\n--- Current Details ---\n");
   printf("Roll Number: %d\n", students[index].rollNumber);
   printf("Name: %s\n", students[index].name);
   printf("Age: %d\n", students[index].age);
   printf("Course: %s\n", students[index].course);
   printf("Marks: %.1f, %.1f, %.1f\n",
          students[index].marks[0],
          students[index].marks[1],
          students[index].marks[2]);

   printf("\n--- Enter New Details ---\n");

   // Edit name
   printf("New Name (press Enter to keep '%s'): ", students[index].name);
   char newName[NAME_LENGTH];
   fgets(newName, NAME_LENGTH, stdin);
   if (newName[0] != '\n') {
      newName[strcspn(newName, "\n")] = '\0';
      strcpy(students[index].name, newName);
   }

   // Edit age
   printf("New Age (current: %d, 0 to skip): ", students[index].age);
   int newAge;
   scanf("%d", &newAge);
   if (newAge > 0) {
      students[index].age = newAge;
   }
   clearInputBuffer();

   // Edit course
   printf("New Course (press Enter to keep '%s'): ", students[index].course);
   char newCourse[30];
   fgets(newCourse, 30, stdin);
   if (newCourse[0] != '\n') {
      newCourse[strcspn(newCourse, "\n")] = '\0';
      strcpy(students[index].course, newCourse);
   }

   // Edit marks
   printf("Update marks? (y/n): ");
   char choice;
   scanf("%c", &choice);
   clearInputBuffer();

   if (tolower(choice) == 'y') {
      printf("Enter new marks for 3 subjects:\n");
      for (int i = 0; i < 3; i++) {
         printf("  Subject %d: ", i + 1);
         scanf("%f", &students[index].marks[i]);
      }
      clearInputBuffer();

      // Recalculate results
      calculateResults(&students[index]);
   }

   // Save to file
   if (saveToFile()) {
      printf("\n✓ Record updated successfully!\n");
   }

   pressEnterToContinue();
}

// Delete a record
void deleteRecord() {
   printf("\n╔════════════════════════════════════════════╗\n");
   printf("║          DELETE STUDENT RECORD             ║\n");
   printf("╚════════════════════════════════════════════╝\n\n");

   int rollNo;
   printf("Enter Roll Number to delete: ");
   scanf("%d", &rollNo);
   clearInputBuffer();

   int index = findByRollNumber(rollNo);

   if (index == -1) {
      printf("\n✗ Student with Roll Number %d not found!\n", rollNo);
      pressEnterToContinue();
      return;
   }

   // Show record to be deleted
   printf("\n--- Record to be Deleted ---\n");
   printf("Roll Number: %d\n", students[index].rollNumber);
   printf("Name: %s\n", students[index].name);
   printf("Course: %s\n", students[index].course);

   // Confirm deletion
   printf("\nAre you sure you want to delete this record? (y/n): ");
   char confirm;
   scanf("%c", &confirm);
   clearInputBuffer();

   if (tolower(confirm) != 'y') {
      printf("\n✗ Deletion cancelled.\n");
      pressEnterToContinue();
      return;
   }

   // Shift records to fill the gap
   for (int i = index; i < studentCount - 1; i++) {
      students[i] = students[i + 1];
   }
   studentCount--;

   // Save to file
   if (saveToFile()) {
      printf("\n✓ Record deleted successfully!\n");
      printf("  Total records now: %d\n", studentCount);
   }

   pressEnterToContinue();
}

// Display statistics
void displayStatistics() {
   printf("\n╔════════════════════════════════════════════╗\n");
   printf("║          CLASS STATISTICS                  ║\n");
   printf("╚════════════════════════════════════════════╝\n\n");

   if (studentCount == 0) {
      printf("✗ No records to analyze!\n");
      pressEnterToContinue();
      return;
   }

   float totalPercentage = 0;
   float highest = students[0].percentage;
   float lowest = students[0].percentage;
   int highestIndex = 0, lowestIndex = 0;
   int gradeCount[6] = {0};

   for (int i = 0; i < studentCount; i++) {
      totalPercentage += students[i].percentage;

      if (students[i].percentage > highest) {
         highest = students[i].percentage;
         highestIndex = i;
      }

      if (students[i].percentage < lowest) {
         lowest = students[i].percentage;
         lowestIndex = i;
      }

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

   printf("Total Students: %d\n\n", studentCount);

   printf("--- Performance Summary ---\n");
   printf("Average Percentage: %.2f%%\n", totalPercentage / studentCount);
   printf("Highest Score: %.2f%% - %s (Roll: %d)\n",
          highest, students[highestIndex].name, students[highestIndex].rollNumber);
   printf("Lowest Score: %.2f%% - %s (Roll: %d)\n",
          lowest, students[lowestIndex].name, students[lowestIndex].rollNumber);

   printf("\n--- Grade Distribution ---\n");
   printf("  A (90-100): %2d students (%.1f%%)\n",
          gradeCount[0], (gradeCount[0] * 100.0) / studentCount);
   printf("  B (80-89):  %2d students (%.1f%%)\n",
          gradeCount[1], (gradeCount[1] * 100.0) / studentCount);
   printf("  C (70-79):  %2d students (%.1f%%)\n",
          gradeCount[2], (gradeCount[2] * 100.0) / studentCount);
   printf("  D (60-69):  %2d students (%.1f%%)\n",
          gradeCount[3], (gradeCount[3] * 100.0) / studentCount);
   printf("  E (50-59):  %2d students (%.1f%%)\n",
          gradeCount[4], (gradeCount[4] * 100.0) / studentCount);
   printf("  F (0-49):   %2d students (%.1f%%)\n",
          gradeCount[5], (gradeCount[5] * 100.0) / studentCount);

   int passed = studentCount - gradeCount[5];
   printf("\n--- Pass/Fail Statistics ---\n");
   printf("  Passed: %d students (%.1f%%)\n",
          passed, (passed * 100.0) / studentCount);
   printf("  Failed: %d students (%.1f%%)\n",
          gradeCount[5], (gradeCount[5] * 100.0) / studentCount);

   pressEnterToContinue();
}

// Sort records
void sortRecords() {
   printf("\n╔════════════════════════════════════════════╗\n");
   printf("║            SORT RECORDS                    ║\n");
   printf("╚════════════════════════════════════════════╝\n\n");

   if (studentCount == 0) {
      printf("✗ No records to sort!\n");
      pressEnterToContinue();
      return;
   }

   printf("Sort by:\n");
   printf("1. Roll Number (ascending)\n");
   printf("2. Percentage (descending)\n");
   printf("3. Name (alphabetical)\n");
   printf("\nEnter choice: ");

   int choice;
   scanf("%d", &choice);
   clearInputBuffer();

   Student temp;

   switch (choice) {
   case 1: // Sort by roll number
      for (int i = 0; i < studentCount - 1; i++) {
         for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].rollNumber > students[j + 1].rollNumber) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
      printf("\n✓ Records sorted by Roll Number!\n");
      break;

   case 2: // Sort by percentage
      for (int i = 0; i < studentCount - 1; i++) {
         for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].percentage < students[j + 1].percentage) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
      printf("\n✓ Records sorted by Percentage (highest first)!\n");
      break;

   case 3: // Sort by name
      for (int i = 0; i < studentCount - 1; i++) {
         for (int j = 0; j < studentCount - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
      printf("\n✓ Records sorted by Name (alphabetically)!\n");
      break;

   default:
      printf("\n✗ Invalid choice!\n");
      pressEnterToContinue();
      return;
   }

   saveToFile();

   printf("\nSorted records:\n");
   displayTableHeader();
   for (int i = 0; i < studentCount; i++) {
      displayStudent(students[i], i + 1);
   }
   displayTableFooter();

   pressEnterToContinue();
}

// Calculate total, percentage, and grade
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

// Display table header
void displayTableHeader() {
   printf("┌─────┬──────┬──────────────────────┬─────┬────────────────┬───────┬───────┬───────┬────────┬──────────┬───────┐\n");
   printf("│ No. │ Roll │ Name                 │ Age │ Course         │ Sub-1 │ Sub-2 │ Sub-3 │ Total  │ Percent  │ Grade │\n");
   printf("├─────┼──────┼──────────────────────┼─────┼────────────────┼───────┼───────┼───────┼────────┼──────────┼───────┤\n");
}

// Display table footer
void displayTableFooter() {
   printf("└─────┴──────┴──────────────────────┴─────┴────────────────┴───────┴───────┴───────┴────────┴──────────┴───────┘\n");
}

// Display single student
void displayStudent(Student s, int index) {
   printf("│ %-3d │ %-4d │ %-20s │ %-3d │ %-14s │",
          index, s.rollNumber, s.name, s.age, s.course);

   for (int i = 0; i < 3; i++) {
      printf(" %5.1f │", s.marks[i]);
   }

   printf(" %6.1f │ %6.2f%% │ %5c │\n",
          s.total, s.percentage, s.grade);
}

// Find student by roll number
int findByRollNumber(int rollNo) {
   for (int i = 0; i < studentCount; i++) {
      if (students[i].rollNumber == rollNo) {
         return i;
      }
   }
   return -1;
}

// Load records from file
int loadFromFile() {
   FILE *fp = fopen(DATABASE_FILE, "rb");

   if (fp == NULL) {
      printf("ℹ No existing database found. Starting with empty database.\n");
      studentCount = 0;
      return 0;
   }

   fread(&studentCount, sizeof(int), 1, fp);
   fread(students, sizeof(Student), studentCount, fp);
   fclose(fp);

   printf("✓ Loaded %d records from database.\n", studentCount);
   return studentCount;
}

// Save records to file
int saveToFile() {
   FILE *fp = fopen(DATABASE_FILE, "wb");

   if (fp == NULL) {
      printf("✗ Error: Cannot save to file!\n");
      return 0;
   }

   fwrite(&studentCount, sizeof(int), 1, fp);
   fwrite(students, sizeof(Student), studentCount, fp);
   fclose(fp);

   return 1;
}

// Clear input buffer
void clearInputBuffer() {
   int c;
   while ((c = getchar()) != '\n' && c != EOF)
      ;
}

// Wait for user to press Enter
void pressEnterToContinue() {
   printf("\nPress Enter to continue...");
   getchar();
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example Usage Session:
 *
 * ╔════════════════════════════════════════════╗
 * ║   STUDENT DATABASE MANAGEMENT SYSTEM       ║
 * ╚════════════════════════════════════════════╝
 *
 * ℹ No existing database found. Starting with empty database.
 *
 * ╔════════════════════════════════════════════╗
 * ║              MAIN MENU                     ║
 * ╠════════════════════════════════════════════╣
 * ║  1. Add New Student Record                 ║
 * ║  2. Display All Records                    ║
 * ║  3. Search Record (by Roll Number)         ║
 * ║  4. Edit Record                            ║
 * ║  5. Delete Record                          ║
 * ║  6. Display Statistics                     ║
 * ║  7. Sort Records                           ║
 * ║  8. Exit                                   ║
 * ╚════════════════════════════════════════════╝
 *
 * Total Records: 0
 *
 * Enter your choice: 1
 *
 * ╔════════════════════════════════════════════╗
 * ║         ADD NEW STUDENT RECORD             ║
 * ╚════════════════════════════════════════════╝
 *
 * Enter Roll Number: 101
 * Enter Name: Alice Johnson
 * Enter Age: 20
 * Enter Course: Computer Science
 * Enter marks for 3 subjects:
 *   Subject 1: 85
 *   Subject 2: 90
 *   Subject 3: 88
 *
 * ✓ Student record added successfully!
 *   Roll Number: 101
 *   Name: Alice Johnson
 *   Percentage: 87.67%
 *   Grade: B
 *
 * Press Enter to continue...
 *
 * [After adding more records and selecting option 2]
 *
 * ╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
 * ║                         ALL STUDENT RECORDS                                                                        ║
 * ╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
 *
 * ┌─────┬──────┬──────────────────────┬─────┬────────────────┬───────┬───────┬───────┬────────┬──────────┬───────┐
 * │ No. │ Roll │ Name                 │ Age │ Course         │ Sub-1 │ Sub-2 │ Sub-3 │ Total  │ Percent  │ Grade │
 * ├─────┼──────┼──────────────────────┼─────┼────────────────┼───────┼───────┼───────┼────────┼──────────┼───────┤
 * │ 1   │ 101  │ Alice Johnson        │ 20  │ Computer Sci.  │  85.0 │  90.0 │  88.0 │  263.0 │  87.67%  │   B   │
 * │ 2   │ 102  │ Bob Smith            │ 21  │ Electronics    │  92.0 │  95.0 │  93.0 │  280.0 │  93.33%  │   A   │
 * │ 3   │ 103  │ Carol Williams       │ 19  │ Mathematics    │  78.0 │  82.0 │  75.0 │  235.0 │  78.33%  │   C   │
 * └─────┴──────┴──────────────────────┴─────┴────────────────┴───────┴───────┴───────┴────────┴──────────┴───────┘
 *
 * Total Records: 3
 *
 * Press Enter to continue...
 *
 * [Selecting option 6 for statistics]
 *
 * ╔════════════════════════════════════════════╗
 * ║          CLASS STATISTICS                  ║
 * ╚════════════════════════════════════════════╝
 *
 * Total Students: 3
 *
 * --- Performance Summary ---
 * Average Percentage: 86.44%
 * Highest Score: 93.33% - Bob Smith (Roll: 102)
 * Lowest Score: 78.33% - Carol Williams (Roll: 103)
 *
 * --- Grade Distribution ---
 *   A (90-100):  1 students (33.3%)
 *   B (80-89):   1 students (33.3%)
 *   C (70-79):   1 students (33.3%)
 *   D (60-69):   0 students (0.0%)
 *   E (50-59):   0 students (0.0%)
 *   F (0-49):    0 students (0.0%)
 *
 * --- Pass/Fail Statistics ---
 *   Passed: 3 students (100.0%)
 *   Failed: 0 students (0.0%)
 *
 * Press Enter to continue...
 */
