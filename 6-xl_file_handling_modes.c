/*
 * QUESTION xl:
 * Write a C program for handling unformatted and formatted files
 * in different operational modes.
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates various file handling modes in C:
 *
 * File Opening Modes:
 * - "r"   - Read mode (file must exist)
 * - "w"   - Write mode (creates new, overwrites existing)
 * - "a"   - Append mode (creates new, appends to existing)
 * - "r+"  - Read/Write mode (file must exist)
 * - "w+"  - Read/Write mode (creates new, overwrites existing)
 * - "a+"  - Read/Append mode (creates new, appends to existing)
 *
 * File I/O Functions:
 * FORMATTED:
 * - fprintf() - Write formatted data to file
 * - fscanf()  - Read formatted data from file
 *
 * UNFORMATTED (Character-based):
 * - fputc()   - Write a character
 * - fgetc()   - Read a character
 *
 * UNFORMATTED (String-based):
 * - fputs()   - Write a string
 * - fgets()   - Read a string
 *
 * UNFORMATTED (Block-based):
 * - fwrite()  - Write binary data
 * - fread()   - Read binary data
 *
 * HOW TO SOLVE:
 * 1. Demonstrate formatted file operations (fprintf, fscanf)
 * 2. Demonstrate unformatted file operations (fputc, fgetc, fputs, fgets)
 * 3. Show different file opening modes
 * 4. Handle file operations with error checking
 * 5. Display file contents after operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to demonstrate formatted file writing
void demonstrateFormattedWrite() {
   FILE *fp;

   printf("\n========================================\n");
   printf("  FORMATTED FILE WRITE (fprintf)\n");
   printf("========================================\n\n");

   fp = fopen("formatted_data.txt", "w");
   if (fp == NULL) {
      printf("Error: Could not create file!\n");
      return;
   }

   printf("Writing formatted data to 'formatted_data.txt'...\n\n");

   // Write formatted data
   fprintf(fp, "Student Records\n");
   fprintf(fp, "%-10s %-20s %-5s %-8s\n", "Roll", "Name", "Age", "Marks");
   fprintf(fp, "%-10s %-20s %-5s %-8s\n", "----", "----", "---", "-----");
   fprintf(fp, "%-10d %-20s %-5d %-8.2f\n", 101, "Alice Johnson", 20, 85.5);
   fprintf(fp, "%-10d %-20s %-5d %-8.2f\n", 102, "Bob Smith", 21, 92.3);
   fprintf(fp, "%-10d %-20s %-5d %-8.2f\n", 103, "Carol Williams", 19, 78.9);

   fclose(fp);

   printf("Data written successfully!\n");
   printf("Format: fprintf(fp, format_string, variables)\n");
}

// Function to demonstrate formatted file reading
void demonstrateFormattedRead() {
   FILE *fp;
   char line[100];

   printf("\n========================================\n");
   printf("  FORMATTED FILE READ (fscanf)\n");
   printf("========================================\n\n");

   fp = fopen("formatted_data.txt", "r");
   if (fp == NULL) {
      printf("Error: Could not open file!\n");
      return;
   }

   printf("Reading from 'formatted_data.txt':\n\n");

   // Read and display entire file
   while (fgets(line, sizeof(line), fp) != NULL) {
      printf("%s", line);
   }

   fclose(fp);
   printf("\nFile read successfully!\n");
}

// Function to demonstrate unformatted character I/O
void demonstrateUnformattedChar() {
   FILE *fp;
   char ch;
   char text[] = "Hello, File Handling in C!";

   printf("\n========================================\n");
   printf("  UNFORMATTED CHAR I/O (fputc/fgetc)\n");
   printf("========================================\n\n");

   // Writing character by character
   fp = fopen("char_data.txt", "w");
   if (fp == NULL) {
      printf("Error: Could not create file!\n");
      return;
   }

   printf("Writing characters to 'char_data.txt'...\n");
   printf("Text: \"%s\"\n\n", text);

   for (int i = 0; text[i] != '\0'; i++) {
      fputc(text[i], fp);
   }
   fputc('\n', fp);

   fclose(fp);
   printf("Characters written using fputc()!\n");

   // Reading character by character
   fp = fopen("char_data.txt", "r");
   if (fp == NULL) {
      printf("Error: Could not open file!\n");
      return;
   }

   printf("\nReading characters using fgetc():\n");
   printf("Content: \"");

   while ((ch = fgetc(fp)) != EOF) {
      if (ch != '\n') {
         printf("%c", ch);
      }
   }
   printf("\"\n");

   fclose(fp);
}

// Function to demonstrate unformatted string I/O
void demonstrateUnformattedString() {
   FILE *fp;
   char line[100];

   printf("\n========================================\n");
   printf("  UNFORMATTED STRING I/O (fputs/fgets)\n");
   printf("========================================\n\n");

   // Writing strings
   fp = fopen("string_data.txt", "w");
   if (fp == NULL) {
      printf("Error: Could not create file!\n");
      return;
   }

   printf("Writing strings to 'string_data.txt'...\n\n");

   fputs("Line 1: This is the first line.\n", fp);
   fputs("Line 2: File handling is important.\n", fp);
   fputs("Line 3: C provides powerful file operations.\n", fp);

   fclose(fp);
   printf("Strings written using fputs()!\n");

   // Reading strings
   fp = fopen("string_data.txt", "r");
   if (fp == NULL) {
      printf("Error: Could not open file!\n");
      return;
   }

   printf("\nReading strings using fgets():\n\n");

   int lineNum = 1;
   while (fgets(line, sizeof(line), fp) != NULL) {
      printf("  [%d] %s", lineNum++, line);
   }

   fclose(fp);
}

// Function to demonstrate different file modes
void demonstrateFileModes() {
   FILE *fp;
   char buffer[100];

   printf("\n========================================\n");
   printf("  FILE OPENING MODES DEMONSTRATION\n");
   printf("========================================\n\n");

   // Mode: "w" - Write (creates/overwrites)
   printf("1. Mode 'w' (Write - creates/overwrites):\n");
   fp = fopen("mode_demo.txt", "w");
   fprintf(fp, "Initial content written in 'w' mode.\n");
   fclose(fp);
   printf("   File created and written.\n\n");

   // Mode: "a" - Append
   printf("2. Mode 'a' (Append):\n");
   fp = fopen("mode_demo.txt", "a");
   fprintf(fp, "This line appended in 'a' mode.\n");
   fclose(fp);
   printf("   Content appended to file.\n\n");

   // Mode: "r" - Read
   printf("3. Mode 'r' (Read):\n");
   fp = fopen("mode_demo.txt", "r");
   printf("   Content:\n");
   while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      printf("   %s", buffer);
   }
   fclose(fp);
   printf("\n");

   // Mode: "r+" - Read/Write
   printf("4. Mode 'r+' (Read/Write - file must exist):\n");
   fp = fopen("mode_demo.txt", "r+");
   fprintf(fp, "Modified"); // Overwrites from beginning
   fclose(fp);
   printf("   File modified from beginning.\n\n");

   // Read modified content
   fp = fopen("mode_demo.txt", "r");
   printf("   Modified content:\n");
   while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      printf("   %s", buffer);
   }
   fclose(fp);
}

// Function to demonstrate binary file operations
void demonstrateBinaryFiles() {
   FILE *fp;
   int numbers[] = {10, 20, 30, 40, 50};
   int read_numbers[5];

   printf("\n========================================\n");
   printf("  BINARY FILE I/O (fwrite/fread)\n");
   printf("========================================\n\n");

   // Writing binary data
   fp = fopen("binary_data.bin", "wb");
   if (fp == NULL) {
      printf("Error: Could not create binary file!\n");
      return;
   }

   printf("Writing binary data to 'binary_data.bin'...\n");
   printf("Data: ");
   for (int i = 0; i < 5; i++) {
      printf("%d ", numbers[i]);
   }
   printf("\n\n");

   fwrite(numbers, sizeof(int), 5, fp);
   fclose(fp);
   printf("Binary data written using fwrite()!\n");

   // Reading binary data
   fp = fopen("binary_data.bin", "rb");
   if (fp == NULL) {
      printf("Error: Could not open binary file!\n");
      return;
   }

   fread(read_numbers, sizeof(int), 5, fp);
   fclose(fp);

   printf("\nReading binary data using fread():\n");
   printf("Data: ");
   for (int i = 0; i < 5; i++) {
      printf("%d ", read_numbers[i]);
   }
   printf("\n\nData matches! Binary I/O successful!\n");
}

// Function to display file mode summary
void displayModeSummary() {
   printf("\n========================================\n");
   printf("  FILE MODE SUMMARY\n");
   printf("========================================\n\n");

   printf("┌──────┬─────────────────────────────────────────────────┐\n");
   printf("│ Mode │ Description                                     │\n");
   printf("├──────┼─────────────────────────────────────────────────┤\n");
   printf("│  r   │ Read only (file must exist)                     │\n");
   printf("│  w   │ Write only (creates/overwrites)                 │\n");
   printf("│  a   │ Append (creates/appends to end)                 │\n");
   printf("│  r+  │ Read & Write (file must exist)                  │\n");
   printf("│  w+  │ Read & Write (creates/overwrites)               │\n");
   printf("│  a+  │ Read & Append (creates/appends)                 │\n");
   printf("│  rb  │ Read binary                                     │\n");
   printf("│  wb  │ Write binary                                    │\n");
   printf("│  ab  │ Append binary                                   │\n");
   printf("└──────┴─────────────────────────────────────────────────┘\n");
}

int main() {
   printf("========================================\n");
   printf("  File Handling Demonstration\n");
   printf("========================================\n");
   printf("\nThis program demonstrates:\n");
   printf("  • Formatted file I/O\n");
   printf("  • Unformatted file I/O\n");
   printf("  • Different file opening modes\n");
   printf("  • Binary file operations\n");

   // Demonstrate formatted file operations
   demonstrateFormattedWrite();
   demonstrateFormattedRead();

   // Demonstrate unformatted file operations
   demonstrateUnformattedChar();
   demonstrateUnformattedString();

   // Demonstrate file modes
   demonstrateFileModes();

   // Demonstrate binary files
   demonstrateBinaryFiles();

   // Display summary
   displayModeSummary();

   printf("\n========================================\n");
   printf("  Function Summary\n");
   printf("========================================\n\n");

   printf("FORMATTED I/O:\n");
   printf("  fprintf(fp, format, ...) - Write formatted data\n");
   printf("  fscanf(fp, format, ...)  - Read formatted data\n\n");

   printf("UNFORMATTED I/O (Character):\n");
   printf("  fputc(char, fp)          - Write a character\n");
   printf("  fgetc(fp)                - Read a character\n\n");

   printf("UNFORMATTED I/O (String):\n");
   printf("  fputs(string, fp)        - Write a string\n");
   printf("  fgets(buffer, size, fp)  - Read a string\n\n");

   printf("UNFORMATTED I/O (Binary):\n");
   printf("  fwrite(ptr, size, n, fp) - Write binary data\n");
   printf("  fread(ptr, size, n, fp)  - Read binary data\n\n");

   printf("FILE OPERATIONS:\n");
   printf("  fopen(name, mode)        - Open file\n");
   printf("  fclose(fp)               - Close file\n");
   printf("  feof(fp)                 - Check end of file\n");
   printf("  rewind(fp)               - Reset file pointer\n");
   printf("  fseek(fp, offset, whence) - Move file pointer\n");

   printf("\n========================================\n");
   printf("Files created in this demonstration:\n");
   printf("  • formatted_data.txt\n");
   printf("  • char_data.txt\n");
   printf("  • string_data.txt\n");
   printf("  • mode_demo.txt\n");
   printf("  • binary_data.bin\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Output:
 * ========================================
 *   File Handling Demonstration
 * ========================================
 *
 * This program demonstrates:
 *   • Formatted file I/O
 *   • Unformatted file I/O
 *   • Different file opening modes
 *   • Binary file operations
 *
 * ========================================
 *   FORMATTED FILE WRITE (fprintf)
 * ========================================
 *
 * Writing formatted data to 'formatted_data.txt'...
 *
 * Data written successfully!
 * Format: fprintf(fp, format_string, variables)
 *
 * ========================================
 *   FORMATTED FILE READ (fscanf)
 * ========================================
 *
 * Reading from 'formatted_data.txt':
 *
 * Student Records
 * Roll       Name                 Age   Marks
 * ----       ----                 ---   -----
 * 101        Alice Johnson        20    85.50
 * 102        Bob Smith            21    92.30
 * 103        Carol Williams       19    78.90
 *
 * File read successfully!
 *
 * ========================================
 *   UNFORMATTED CHAR I/O (fputc/fgetc)
 * ========================================
 *
 * Writing characters to 'char_data.txt'...
 * Text: "Hello, File Handling in C!"
 *
 * Characters written using fputc()!
 *
 * Reading characters using fgetc():
 * Content: "Hello, File Handling in C!"
 *
 * ========================================
 *   UNFORMATTED STRING I/O (fputs/fgets)
 * ========================================
 *
 * Writing strings to 'string_data.txt'...
 *
 * Strings written using fputs()!
 *
 * Reading strings using fgets():
 *
 *   [1] Line 1: This is the first line.
 *   [2] Line 2: File handling is important.
 *   [3] Line 3: C provides powerful file operations.
 *
 * ========================================
 *   FILE OPENING MODES DEMONSTRATION
 * ========================================
 *
 * 1. Mode 'w' (Write - creates/overwrites):
 *    File created and written.
 *
 * 2. Mode 'a' (Append):
 *    Content appended to file.
 *
 * 3. Mode 'r' (Read):
 *    Content:
 *    Initial content written in 'w' mode.
 *    This line appended in 'a' mode.
 *
 * 4. Mode 'r+' (Read/Write - file must exist):
 *    File modified from beginning.
 *
 *    Modified content:
 *    Modified content written in 'w' mode.
 *    This line appended in 'a' mode.
 *
 * ========================================
 *   BINARY FILE I/O (fwrite/fread)
 * ========================================
 *
 * Writing binary data to 'binary_data.bin'...
 * Data: 10 20 30 40 50
 *
 * Binary data written using fwrite()!
 *
 * Reading binary data using fread():
 * Data: 10 20 30 40 50
 *
 * Data matches! Binary I/O successful!
 *
 * ========================================
 *   FILE MODE SUMMARY
 * ========================================
 *
 * ┌──────┬─────────────────────────────────────────────────┐
 * │ Mode │ Description                                     │
 * ├──────┼─────────────────────────────────────────────────┤
 * │  r   │ Read only (file must exist)                     │
 * │  w   │ Write only (creates/overwrites)                 │
 * │  a   │ Append (creates/appends to end)                 │
 * │  r+  │ Read & Write (file must exist)                  │
 * │  w+  │ Read & Write (creates/overwrites)               │
 * │  a+  │ Read & Append (creates/appends)                 │
 * │  rb  │ Read binary                                     │
 * │  wb  │ Write binary                                    │
 * │  ab  │ Append binary                                   │
 * └──────┴─────────────────────────────────────────────────┘
 *
 * ========================================
 *   Function Summary
 * ========================================
 *
 * FORMATTED I/O:
 *   fprintf(fp, format, ...) - Write formatted data
 *   fscanf(fp, format, ...)  - Read formatted data
 *
 * UNFORMATTED I/O (Character):
 *   fputc(char, fp)          - Write a character
 *   fgetc(fp)                - Read a character
 *
 * UNFORMATTED I/O (String):
 *   fputs(string, fp)        - Write a string
 *   fgets(buffer, size, fp)  - Read a string
 *
 * UNFORMATTED I/O (Binary):
 *   fwrite(ptr, size, n, fp) - Write binary data
 *   fread(ptr, size, n, fp)  - Read binary data
 *
 * FILE OPERATIONS:
 *   fopen(name, mode)        - Open file
 *   fclose(fp)               - Close file
 *   feof(fp)                 - Check end of file
 *   rewind(fp)               - Reset file pointer
 *   fseek(fp, offset, whence) - Move file pointer
 *
 * ========================================
 * Files created in this demonstration:
 *   • formatted_data.txt
 *   • char_data.txt
 *   • string_data.txt
 *   • mode_demo.txt
 *   • binary_data.bin
 * ========================================
 */
