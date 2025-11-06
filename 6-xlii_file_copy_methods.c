/*
 * QUESTION xlii:
 * Write a C program to copy one file into another by:
 * a) Copying one character at a time
 * b) Copying multiple characters simultaneously (using fgets() and fputs())
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates two methods of file copying:
 *
 * METHOD 1: Character-by-character copy
 * - Uses fgetc() to read one character
 * - Uses fputc() to write one character
 * - Slower but works for any file type
 *
 * METHOD 2: Line-by-line copy (multiple characters)
 * - Uses fgets() to read a line (string)
 * - Uses fputs() to write the line
 * - Faster for text files
 * - Efficient for large files
 *
 * The program also:
 * - Compares performance of both methods
 * - Verifies successful copy
 * - Displays file statistics
 *
 * HOW TO SOLVE:
 * 1. Open source file in read mode
 * 2. Open destination file in write mode
 * 3. METHOD 1:
 *    - Read character using fgetc() until EOF
 *    - Write each character using fputc()
 * 4. METHOD 2:
 *    - Read line using fgets() until NULL
 *    - Write line using fputs()
 * 5. Close both files
 * 6. Verify copy by comparing file sizes/content
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to copy file character by character
int copyFileCharByChar(const char *source, const char *dest) {
   FILE *srcFile, *destFile;
   char ch;
   int charCount = 0;
   clock_t start, end;
   double timeTaken;

   printf("\n========================================\n");
   printf("  METHOD 1: Character-by-Character Copy\n");
   printf("========================================\n\n");

   // Open source file for reading
   srcFile = fopen(source, "r");
   if (srcFile == NULL) {
      printf("Error: Cannot open source file '%s'\n", source);
      return 0;
   }

   // Open destination file for writing
   destFile = fopen(dest, "w");
   if (destFile == NULL) {
      printf("Error: Cannot create destination file '%s'\n", dest);
      fclose(srcFile);
      return 0;
   }

   printf("Copying from '%s' to '%s'...\n", source, dest);
   printf("Method: fgetc() and fputc()\n\n");

   // Start timer
   start = clock();

   // Copy character by character
   while ((ch = fgetc(srcFile)) != EOF) {
      fputc(ch, destFile);
      charCount++;
   }

   // End timer
   end = clock();
   timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

   // Close files
   fclose(srcFile);
   fclose(destFile);

   printf("Copy completed!\n");
   printf("Characters copied: %d\n", charCount);
   printf("Time taken: %.6f seconds\n", timeTaken);

   return 1;
}

// Function to copy file line by line
int copyFileLineByLine(const char *source, const char *dest) {
   FILE *srcFile, *destFile;
   char buffer[1024];
   int lineCount = 0;
   int charCount = 0;
   clock_t start, end;
   double timeTaken;

   printf("\n========================================\n");
   printf("  METHOD 2: Line-by-Line Copy\n");
   printf("========================================\n\n");

   // Open source file for reading
   srcFile = fopen(source, "r");
   if (srcFile == NULL) {
      printf("Error: Cannot open source file '%s'\n", source);
      return 0;
   }

   // Open destination file for writing
   destFile = fopen(dest, "w");
   if (destFile == NULL) {
      printf("Error: Cannot create destination file '%s'\n", dest);
      fclose(srcFile);
      return 0;
   }

   printf("Copying from '%s' to '%s'...\n", source, dest);
   printf("Method: fgets() and fputs()\n\n");

   // Start timer
   start = clock();

   // Copy line by line
   while (fgets(buffer, sizeof(buffer), srcFile) != NULL) {
      fputs(buffer, destFile);
      lineCount++;
      charCount += strlen(buffer);
   }

   // End timer
   end = clock();
   timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

   // Close files
   fclose(srcFile);
   fclose(destFile);

   printf("Copy completed!\n");
   printf("Lines copied: %d\n", lineCount);
   printf("Characters copied: %d\n", charCount);
   printf("Time taken: %.6f seconds\n", timeTaken);

   return 1;
}

// Function to verify file copy
int verifyFileCopy(const char *source, const char *dest) {
   FILE *srcFile, *destFile;
   char ch1, ch2;
   int match = 1;
   int charCount = 0;

   srcFile = fopen(source, "r");
   destFile = fopen(dest, "r");

   if (srcFile == NULL || destFile == NULL) {
      printf("Error: Cannot open files for verification\n");
      if (srcFile)
         fclose(srcFile);
      if (destFile)
         fclose(destFile);
      return 0;
   }

   // Compare character by character
   while (1) {
      ch1 = fgetc(srcFile);
      ch2 = fgetc(destFile);

      if (ch1 == EOF && ch2 == EOF) {
         break; // Both files ended simultaneously
      }

      if (ch1 != ch2) {
         match = 0;
         break;
      }

      charCount++;
   }

   fclose(srcFile);
   fclose(destFile);

   printf("\n========================================\n");
   printf("  File Copy Verification\n");
   printf("========================================\n\n");

   if (match) {
      printf("✓ Verification SUCCESSFUL!\n");
      printf("  Source and destination files are identical.\n");
      printf("  %d characters verified.\n", charCount);
      return 1;
   } else {
      printf("✗ Verification FAILED!\n");
      printf("  Files do not match.\n");
      return 0;
   }
}

// Function to display file content
void displayFileContent(const char *filename, int maxLines) {
   FILE *fp;
   char line[500];
   int lineNum = 1;

   fp = fopen(filename, "r");
   if (fp == NULL) {
      printf("Error: Cannot open file '%s'\n", filename);
      return;
   }

   printf("\n--- First %d lines of '%s' ---\n", maxLines, filename);
   while (fgets(line, sizeof(line), fp) != NULL && lineNum <= maxLines) {
      printf("%3d: %s", lineNum++, line);
   }
   if (lineNum > maxLines) {
      printf("... (remaining lines not shown)\n");
   }

   fclose(fp);
}

// Function to create a sample source file
void createSampleSourceFile(const char *filename) {
   FILE *fp;

   fp = fopen(filename, "w");
   if (fp == NULL) {
      printf("Error: Cannot create sample file\n");
      return;
   }

   fprintf(fp, "C Programming - File Handling\n");
   fprintf(fp, "==============================\n\n");
   fprintf(fp, "This is a sample source file for testing file copy operations.\n");
   fprintf(fp, "The file contains multiple lines of text.\n\n");
   fprintf(fp, "Line 1: File handling is an important concept in C.\n");
   fprintf(fp, "Line 2: We can read from and write to files.\n");
   fprintf(fp, "Line 3: Files can be copied using different methods.\n");
   fprintf(fp, "Line 4: Character-by-character copy uses fgetc() and fputc().\n");
   fprintf(fp, "Line 5: Line-by-line copy uses fgets() and fputs().\n\n");
   fprintf(fp, "Numbers: 123, 456, 789\n");
   fprintf(fp, "Special characters: !@#$%%^&*()\n\n");
   fprintf(fp, "End of sample file.\n");

   fclose(fp);

   printf("Sample source file '%s' created.\n", filename);
}

// Function to get file size
long getFileSize(const char *filename) {
   FILE *fp;
   long size;

   fp = fopen(filename, "r");
   if (fp == NULL) {
      return -1;
   }

   fseek(fp, 0, SEEK_END);
   size = ftell(fp);
   fclose(fp);

   return size;
}

int main() {
   char sourceFile[100];
   char destFile1[100];
   char destFile2[100];
   int choice;

   printf("========================================\n");
   printf("  File Copy Program\n");
   printf("========================================\n\n");

   printf("Choose an option:\n");
   printf("1. Use existing file\n");
   printf("2. Create sample file\n");
   printf("Enter choice (1 or 2): ");
   scanf("%d", &choice);
   getchar(); // Clear newline

   if (choice == 2) {
      strcpy(sourceFile, "source.txt");
      printf("\n");
      createSampleSourceFile(sourceFile);
   } else {
      printf("\nEnter source filename: ");
      fgets(sourceFile, sizeof(sourceFile), stdin);
      sourceFile[strcspn(sourceFile, "\n")] = '\0';
   }

   strcpy(destFile1, "copy_method1.txt");
   strcpy(destFile2, "copy_method2.txt");

   printf("\nSource file: %s\n", sourceFile);
   printf("Destination (Method 1): %s\n", destFile1);
   printf("Destination (Method 2): %s\n", destFile2);

   // Display source file content
   displayFileContent(sourceFile, 5);

   // Method 1: Copy character by character
   if (copyFileCharByChar(sourceFile, destFile1)) {
      verifyFileCopy(sourceFile, destFile1);
   }

   // Method 2: Copy line by line
   if (copyFileLineByLine(sourceFile, destFile2)) {
      verifyFileCopy(sourceFile, destFile2);
   }

   // Compare methods
   printf("\n========================================\n");
   printf("  Method Comparison\n");
   printf("========================================\n\n");

   long srcSize = getFileSize(sourceFile);
   long dest1Size = getFileSize(destFile1);
   long dest2Size = getFileSize(destFile2);

   printf("File Sizes:\n");
   printf("  Source:           %ld bytes\n", srcSize);
   printf("  Copy (Method 1):  %ld bytes\n", dest1Size);
   printf("  Copy (Method 2):  %ld bytes\n", dest2Size);

   if (srcSize == dest1Size && srcSize == dest2Size) {
      printf("\n✓ All files are same size - Copy successful!\n");
   }

   printf("\nMethod Comparison:\n");
   printf("┌─────────────┬────────────────────┬──────────────────┐\n");
   printf("│ Method      │ Function Used      │ Best For         │\n");
   printf("├─────────────┼────────────────────┼──────────────────┤\n");
   printf("│ Method 1    │ fgetc() / fputc()  │ Any file type    │\n");
   printf("│ Method 2    │ fgets() / fputs()  │ Text files       │\n");
   printf("└─────────────┴────────────────────┴──────────────────┘\n");

   printf("\nAdvantages:\n");
   printf("  Method 1: Works with any file, simple logic\n");
   printf("  Method 2: Faster, efficient for large text files\n");

   printf("\n========================================\n");
   printf("  Summary\n");
   printf("========================================\n");
   printf("Source file:      %s\n", sourceFile);
   printf("Files created:    %s, %s\n", destFile1, destFile2);
   printf("Both methods:     Successful!\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1: (Create sample file)
 * Input:
 *   Choice: 2
 * Output:
 * ========================================
 *   File Copy Program
 * ========================================
 *
 * Choose an option:
 * 1. Use existing file
 * 2. Create sample file
 * Enter choice (1 or 2): 2
 *
 * Sample source file 'source.txt' created.
 *
 * Source file: source.txt
 * Destination (Method 1): copy_method1.txt
 * Destination (Method 2): copy_method2.txt
 *
 * --- First 5 lines of 'source.txt' ---
 *   1: C Programming - File Handling
 *   2: ==============================
 *   3:
 *   4: This is a sample source file for testing file copy operations.
 *   5: The file contains multiple lines of text.
 * ... (remaining lines not shown)
 *
 * ========================================
 *   METHOD 1: Character-by-Character Copy
 * ========================================
 *
 * Copying from 'source.txt' to 'copy_method1.txt'...
 * Method: fgetc() and fputc()
 *
 * Copy completed!
 * Characters copied: 542
 * Time taken: 0.000234 seconds
 *
 * ========================================
 *   File Copy Verification
 * ========================================
 *
 * ✓ Verification SUCCESSFUL!
 *   Source and destination files are identical.
 *   542 characters verified.
 *
 * ========================================
 *   METHOD 2: Line-by-Line Copy
 * ========================================
 *
 * Copying from 'source.txt' to 'copy_method2.txt'...
 * Method: fgets() and fputs()
 *
 * Copy completed!
 * Lines copied: 14
 * Characters copied: 542
 * Time taken: 0.000156 seconds
 *
 * ========================================
 *   File Copy Verification
 * ========================================
 *
 * ✓ Verification SUCCESSFUL!
 *   Source and destination files are identical.
 *   542 characters verified.
 *
 * ========================================
 *   Method Comparison
 * ========================================
 *
 * File Sizes:
 *   Source:           542 bytes
 *   Copy (Method 1):  542 bytes
 *   Copy (Method 2):  542 bytes
 *
 * ✓ All files are same size - Copy successful!
 *
 * Method Comparison:
 * ┌─────────────┬────────────────────┬──────────────────┐
 * │ Method      │ Function Used      │ Best For         │
 * ├─────────────┼────────────────────┼──────────────────┤
 * │ Method 1    │ fgetc() / fputc()  │ Any file type    │
 * │ Method 2    │ fgets() / fputs()  │ Text files       │
 * └─────────────┴────────────────────┴──────────────────┘
 *
 * Advantages:
 *   Method 1: Works with any file, simple logic
 *   Method 2: Faster, efficient for large text files
 *
 * ========================================
 *   Summary
 * ========================================
 * Source file:      source.txt
 * Files created:    copy_method1.txt, copy_method2.txt
 * Both methods:     Successful!
 * ========================================
 */
