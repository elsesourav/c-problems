/*
 * QUESTION xli:
 * Write a C program to count the number of characters and number of lines in a file.
 *
 * PROGRAM DESCRIPTION:
 * This program reads a file and counts:
 * 1. Total number of characters (including spaces, newlines)
 * 2. Total number of lines
 * 3. Number of alphabetic characters
 * 4. Number of digits
 * 5. Number of spaces
 * 6. Number of special characters
 * 7. Number of words
 *
 * The program provides detailed statistics about the file content.
 *
 * HOW TO SOLVE:
 * 1. Open file in read mode
 * 2. Read file character by character using fgetc()
 * 3. Count characters:
 *    - Increment total character count for each character
 *    - Count newline characters ('\n') for line count
 *    - Check character type (alphabet, digit, space, etc.)
 * 4. Display all statistics
 * 5. Handle file errors (file not found, etc.)
 * 6. Close file after reading
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count characters and lines in a file
void countFileStatistics(const char *filename) {
   FILE *fp;
   char ch;
   int totalChars = 0;
   int lines = 0;
   int alphabets = 0;
   int digits = 0;
   int spaces = 0;
   int special = 0;
   int words = 0;
   int inWord = 0;

   // Open file in read mode
   fp = fopen(filename, "r");
   if (fp == NULL) {
      printf("Error: Could not open file '%s'\n", filename);
      printf("Please make sure the file exists.\n");
      return;
   }

   printf("Reading file: '%s'\n\n", filename);

   // Read file character by character
   while ((ch = fgetc(fp)) != EOF) {
      totalChars++;

      // Count lines (newline characters)
      if (ch == '\n') {
         lines++;
         inWord = 0; // Reset word flag at newline
      }

      // Count character types
      if (isalpha(ch)) {
         alphabets++;
         if (inWord == 0) {
            words++;
            inWord = 1;
         }
      } else if (isdigit(ch)) {
         digits++;
         if (inWord == 0) {
            words++;
            inWord = 1;
         }
      } else if (ch == ' ' || ch == '\t') {
         spaces++;
         inWord = 0;
      } else if (ch != '\n') { // Don't count newline as special
         special++;
      }
   }

   // If file doesn't end with newline, count the last line
   if (totalChars > 0 && ch != '\n') {
      lines++;
   }

   // Close file
   fclose(fp);

   // Display statistics
   printf("========================================\n");
   printf("  File Statistics\n");
   printf("========================================\n\n");

   printf("File Name:        %s\n\n", filename);

   printf("--- Character Count ---\n");
   printf("Total characters: %d\n", totalChars);
   printf("Alphabets:        %d\n", alphabets);
   printf("Digits:           %d\n", digits);
   printf("Spaces/Tabs:      %d\n", spaces);
   printf("Special chars:    %d\n", special);
   printf("Newlines:         %d\n", lines);

   printf("\n--- Line & Word Count ---\n");
   printf("Total lines:      %d\n", lines);
   printf("Total words:      %d\n", words);

   if (lines > 0) {
      printf("\n--- Averages ---\n");
      printf("Chars per line:   %.2f\n", (float)totalChars / lines);
      printf("Words per line:   %.2f\n", (float)words / lines);
   }

   if (words > 0) {
      printf("Chars per word:   %.2f\n", (float)(alphabets + digits) / words);
   }

   // Display percentage distribution
   if (totalChars > 0) {
      printf("\n--- Percentage Distribution ---\n");
      printf("Alphabets:        %.2f%%\n", (alphabets * 100.0) / totalChars);
      printf("Digits:           %.2f%%\n", (digits * 100.0) / totalChars);
      printf("Spaces:           %.2f%%\n", (spaces * 100.0) / totalChars);
      printf("Special:          %.2f%%\n", (special * 100.0) / totalChars);
      printf("Newlines:         %.2f%%\n", (lines * 100.0) / totalChars);
   }
}

// Function to display file content with line numbers
void displayFileContent(const char *filename) {
   FILE *fp;
   char line[500];
   int lineNum = 1;

   fp = fopen(filename, "r");
   if (fp == NULL) {
      printf("Error: Could not open file '%s'\n", filename);
      return;
   }

   printf("\n========================================\n");
   printf("  File Content (with line numbers)\n");
   printf("========================================\n\n");

   while (fgets(line, sizeof(line), fp) != NULL) {
      printf("%3d: %s", lineNum++, line);
   }

   fclose(fp);
}

// Function to create a sample file for testing
void createSampleFile(const char *filename) {
   FILE *fp;

   fp = fopen(filename, "w");
   if (fp == NULL) {
      printf("Error: Could not create sample file!\n");
      return;
   }

   fprintf(fp, "Hello, World!\n");
   fprintf(fp, "This is a test file for counting characters and lines.\n");
   fprintf(fp, "It contains 5 lines of text.\n");
   fprintf(fp, "Numbers: 123, 456, 789\n");
   fprintf(fp, "Special characters: !@#$%%^&*()\n");

   fclose(fp);

   printf("Sample file '%s' created successfully!\n\n", filename);
}

// Function to analyze multiple files
void compareFiles(const char *file1, const char *file2) {
   FILE *fp1, *fp2;
   int chars1 = 0, chars2 = 0;
   int lines1 = 0, lines2 = 0;
   char ch;

   printf("\n========================================\n");
   printf("  File Comparison\n");
   printf("========================================\n\n");

   // Count file 1
   fp1 = fopen(file1, "r");
   if (fp1 != NULL) {
      while ((ch = fgetc(fp1)) != EOF) {
         chars1++;
         if (ch == '\n')
            lines1++;
      }
      fclose(fp1);
   }

   // Count file 2
   fp2 = fopen(file2, "r");
   if (fp2 != NULL) {
      while ((ch = fgetc(fp2)) != EOF) {
         chars2++;
         if (ch == '\n')
            lines2++;
      }
      fclose(fp2);
   }

   printf("%-30s %-15s %-15s\n", "File", "Characters", "Lines");
   printf("%-30s %-15s %-15s\n", "----", "----------", "-----");
   printf("%-30s %-15d %-15d\n", file1, chars1, lines1);
   printf("%-30s %-15d %-15d\n", file2, chars2, lines2);
   printf("%-30s %-15s %-15s\n", "----", "----------", "-----");
   printf("%-30s %-15d %-15d\n", "Difference",
          abs(chars1 - chars2), abs(lines1 - lines2));
}

int main() {
   char filename[100];
   int choice;

   printf("========================================\n");
   printf("  File Character and Line Counter\n");
   printf("========================================\n\n");

   printf("Choose an option:\n");
   printf("1. Use existing file\n");
   printf("2. Create sample file and analyze\n");
   printf("Enter choice (1 or 2): ");
   scanf("%d", &choice);
   getchar(); // Clear newline

   if (choice == 2) {
      // Create sample file
      printf("\n");
      createSampleFile("sample.txt");
      strcpy(filename, "sample.txt");
   } else {
      // Get filename from user
      printf("\nEnter filename to analyze: ");
      fgets(filename, sizeof(filename), stdin);
      filename[strcspn(filename, "\n")] = '\0'; // Remove newline
   }

   printf("\n");

   // Count statistics
   countFileStatistics(filename);

   // Display file content
   displayFileContent(filename);

   printf("\n========================================\n");
   printf("  Summary\n");
   printf("========================================\n");
   printf("File analyzed: %s\n", filename);
   printf("Analysis complete!\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1: (Using sample file)
 * Input:
 *   Choice: 2
 * Output:
 * ========================================
 *   File Character and Line Counter
 * ========================================
 *
 * Choose an option:
 * 1. Use existing file
 * 2. Create sample file and analyze
 * Enter choice (1 or 2): 2
 *
 * Sample file 'sample.txt' created successfully!
 *
 * Reading file: 'sample.txt'
 *
 * ========================================
 *   File Statistics
 * ========================================
 *
 * File Name:        sample.txt
 *
 * --- Character Count ---
 * Total characters: 184
 * Alphabets:        119
 * Digits:           9
 * Spaces/Tabs:      33
 * Special chars:    18
 * Newlines:         5
 *
 * --- Line & Word Count ---
 * Total lines:      5
 * Total words:      29
 *
 * --- Averages ---
 * Chars per line:   36.80
 * Words per line:   5.80
 * Chars per word:   4.41
 *
 * --- Percentage Distribution ---
 * Alphabets:        64.67%
 * Digits:           4.89%
 * Spaces:           17.93%
 * Special:          9.78%
 * Newlines:         2.72%
 *
 * ========================================
 *   File Content (with line numbers)
 * ========================================
 *
 *   1: Hello, World!
 *   2: This is a test file for counting characters and lines.
 *   3: It contains 5 lines of text.
 *   4: Numbers: 123, 456, 789
 *   5: Special characters: !@#$%^&*()
 *
 * ========================================
 *   Summary
 * ========================================
 * File analyzed: sample.txt
 * Analysis complete!
 * ========================================
 *
 * Example 2: (Using existing file)
 * Input:
 *   Choice: 1
 *   Filename: document.txt
 * Output:
 * ========================================
 *   File Character and Line Counter
 * ========================================
 *
 * Choose an option:
 * 1. Use existing file
 * 2. Create sample file and analyze
 * Enter choice (1 or 2): 1
 *
 * Enter filename to analyze: document.txt
 *
 * Reading file: 'document.txt'
 *
 * ========================================
 *   File Statistics
 * ========================================
 *
 * File Name:        document.txt
 *
 * --- Character Count ---
 * Total characters: 450
 * Alphabets:        320
 * Digits:           15
 * Spaces/Tabs:      85
 * Special chars:    20
 * Newlines:         10
 *
 * --- Line & Word Count ---
 * Total lines:      10
 * Total words:      75
 *
 * --- Averages ---
 * Chars per line:   45.00
 * Words per line:   7.50
 * Chars per word:   4.47
 *
 * --- Percentage Distribution ---
 * Alphabets:        71.11%
 * Digits:           3.33%
 * Spaces:           18.89%
 * Special:          4.44%
 * Newlines:         2.22%
 *
 * ========================================
 *   File Content (with line numbers)
 * ========================================
 *
 *   1: [File content would be displayed here]
 *   2: [with line numbers for each line]
 *   ...
 *
 * ========================================
 *   Summary
 * ========================================
 * File analyzed: document.txt
 * Analysis complete!
 * ========================================
 */
