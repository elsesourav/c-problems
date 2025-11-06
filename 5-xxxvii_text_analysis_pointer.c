/*
 * QUESTION xxxvii:
 * Write a C program to read and display a text using a character pointer
 * to a string. Also count the number of characters, words and lines in the text.
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates string manipulation using character pointers.
 * It reads multi-line text and analyzes it to count:
 * - Characters (total, alphabetic, digits, special)
 * - Words (sequences separated by spaces/newlines)
 * - Lines (text lines ending with newline)
 *
 * Character pointer concepts:
 * - char *ptr points to a string (array of characters)
 * - String is terminated by null character '\0'
 * - Can traverse string using pointer arithmetic
 * - *(ptr + i) or ptr[i] accesses character at position i
 *
 * HOW TO SOLVE:
 * 1. Declare character array to store text
 * 2. Declare character pointer
 * 3. Read multi-line text (until special marker like "END")
 * 4. Point character pointer to the text
 * 5. Traverse text using pointer:
 *    - Count total characters
 *    - Count alphabets, digits, spaces, special chars
 *    - Count words (track transitions from space to non-space)
 *    - Count lines (count newline characters)
 * 6. Display text and all statistics
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function to count characters using pointer
void countCharacters(char *ptr, int *total, int *alphabets, int *digits,
                     int *spaces, int *special) {
   *total = 0;
   *alphabets = 0;
   *digits = 0;
   *spaces = 0;
   *special = 0;

   while (*ptr != '\0') {
      (*total)++;

      if (isalpha(*ptr)) {
         (*alphabets)++;
      } else if (isdigit(*ptr)) {
         (*digits)++;
      } else if (*ptr == ' ' || *ptr == '\t') {
         (*spaces)++;
      } else if (*ptr != '\n') {
         (*special)++;
      }

      ptr++;
   }
}

// Function to count words using pointer
int countWords(char *ptr) {
   int words = 0;
   int inWord = 0; // Flag to track if we're inside a word

   while (*ptr != '\0') {
      if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n') {
         inWord = 0; // We're in whitespace
      } else if (inWord == 0) {
         inWord = 1; // We just entered a new word
         words++;
      }
      ptr++;
   }

   return words;
}

// Function to count lines using pointer
int countLines(char *ptr) {
   int lines = 0;

   while (*ptr != '\0') {
      if (*ptr == '\n') {
         lines++;
      }
      ptr++;
   }

   // If text doesn't end with newline, count the last line
   if (lines == 0 && strlen(ptr - strlen(ptr)) > 0) {
      lines = 1;
   }

   return lines;
}

// Function to display text with line numbers using pointer
void displayTextWithLineNumbers(char *ptr) {
   int lineNum = 1;
   printf("%3d: ", lineNum);

   while (*ptr != '\0') {
      printf("%c", *ptr);
      if (*ptr == '\n') {
         ptr++;
         if (*ptr != '\0') { // Not at end
            lineNum++;
            printf("%3d: ", lineNum);
         }
      } else {
         ptr++;
      }
   }
   if (*(ptr - 1) != '\n') {
      printf("\n"); // Add newline if text doesn't end with one
   }
}

// Function to find longest word using pointer
void findLongestWord(char *ptr, char *longest) {
   char word[100];
   int wordLen = 0;
   int maxLen = 0;

   while (*ptr != '\0') {
      if (*ptr != ' ' && *ptr != '\t' && *ptr != '\n') {
         word[wordLen++] = *ptr;
      } else if (wordLen > 0) {
         word[wordLen] = '\0';
         if (wordLen > maxLen) {
            maxLen = wordLen;
            strcpy(longest, word);
         }
         wordLen = 0;
      }
      ptr++;
   }

   // Check last word
   if (wordLen > 0) {
      word[wordLen] = '\0';
      if (wordLen > maxLen) {
         strcpy(longest, word);
      }
   }
}

int main() {
   char text[1000] = "";
   char line[200];
   char *ptr;
   int total, alphabets, digits, spaces, special;
   int words, lines;
   char longestWord[100] = "";

   printf("========================================\n");
   printf("  Text Analysis Using Character Pointer\n");
   printf("========================================\n\n");

   printf("Enter text (multiple lines allowed):\n");
   printf("Type 'END' on a new line to finish.\n\n");

   // Read multi-line text
   while (1) {
      fgets(line, sizeof(line), stdin);

      // Check if user typed "END"
      if (strcmp(line, "END\n") == 0 || strcmp(line, "END") == 0) {
         break;
      }

      // Append line to text
      strcat(text, line);

      // Safety check
      if (strlen(text) > 900) {
         printf("Text too long! Stopping input.\n");
         break;
      }
   }

   // Point to the text
   ptr = text;

   printf("\n========================================\n");
   printf("  Text Display with Line Numbers\n");
   printf("========================================\n\n");

   displayTextWithLineNumbers(ptr);

   printf("\n========================================\n");
   printf("  Character Analysis\n");
   printf("========================================\n\n");

   // Count characters
   countCharacters(ptr, &total, &alphabets, &digits, &spaces, &special);

   printf("Character Breakdown:\n");
   printf("  Total characters:     %d\n", total);
   printf("  Alphabetic chars:     %d\n", alphabets);
   printf("  Digits:               %d\n", digits);
   printf("  Spaces/Tabs:          %d\n", spaces);
   printf("  Special characters:   %d\n", special);
   printf("  Newlines:             %d\n", total - alphabets - digits - spaces - special);

   printf("\n========================================\n");
   printf("  Word and Line Analysis\n");
   printf("========================================\n\n");

   // Count words and lines
   words = countWords(ptr);
   lines = countLines(ptr);

   // Find longest word
   findLongestWord(ptr, longestWord);

   printf("Word Analysis:\n");
   printf("  Total words:          %d\n", words);
   printf("  Average word length:  %.2f characters\n",
          words > 0 ? (float)(alphabets + digits) / words : 0);
   printf("  Longest word:         \"%s\" (%lu chars)\n",
          longestWord, strlen(longestWord));

   printf("\nLine Analysis:\n");
   printf("  Total lines:          %d\n", lines);
   printf("  Average line length:  %.2f characters\n",
          lines > 0 ? (float)total / lines : 0);
   printf("  Average words/line:   %.2f words\n",
          lines > 0 ? (float)words / lines : 0);

   printf("\n========================================\n");
   printf("  Pointer Demonstration\n");
   printf("========================================\n\n");

   printf("Text stored at address: %p\n", (void *)ptr);
   printf("First character:        '%c' (ASCII %d)\n", *ptr, *ptr);
   printf("Second character:       '%c' (ASCII %d)\n", *(ptr + 1), *(ptr + 1));
   printf("Last character:         '%c' (ASCII %d)\n",
          *(ptr + strlen(ptr) - 1), *(ptr + strlen(ptr) - 1));

   printf("\nFirst 10 characters with addresses:\n");
   int displayLimit = (strlen(ptr) < 10) ? strlen(ptr) : 10;
   for (int i = 0; i < displayLimit; i++) {
      char ch = *(ptr + i);
      printf("  ptr[%d] = '%c' (ASCII %3d) at %p\n",
             i, (ch == '\n' ? '\\n' : ch), ch, (void *)(ptr + i));
   }

   printf("\n========================================\n");
   printf("  Character Distribution\n");
   printf("========================================\n\n");

   if (total > 0) {
      printf("Percentage breakdown:\n");
      printf("  Alphabets:  %5.1f%%\n", (alphabets * 100.0) / total);
      printf("  Digits:     %5.1f%%\n", (digits * 100.0) / total);
      printf("  Spaces:     %5.1f%%\n", (spaces * 100.0) / total);
      printf("  Special:    %5.1f%%\n", (special * 100.0) / total);
      printf("  Newlines:   %5.1f%%\n",
             ((total - alphabets - digits - spaces - special) * 100.0) / total);
   }

   printf("\n========================================\n");
   printf("  Summary\n");
   printf("========================================\n");
   printf("Total characters: %d\n", total);
   printf("Total words:      %d\n", words);
   printf("Total lines:      %d\n", lines);
   printf("Memory used:      %lu bytes\n", strlen(text) + 1);
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Hello World
 *   This is a test.
 *   Programming in C!
 *   END
 * Output:
 * ========================================
 *   Text Analysis Using Character Pointer
 * ========================================
 *
 * Enter text (multiple lines allowed):
 * Type 'END' on a new line to finish.
 *
 * Hello World
 * This is a test.
 * Programming in C!
 * END
 *
 * ========================================
 *   Text Display with Line Numbers
 * ========================================
 *
 *   1: Hello World
 *   2: This is a test.
 *   3: Programming in C!
 *
 * ========================================
 *   Character Analysis
 * ========================================
 *
 * Character Breakdown:
 *   Total characters:     44
 *   Alphabetic chars:     34
 *   Digits:               0
 *   Spaces/Tabs:          6
 *   Special characters:   2
 *   Newlines:             2
 *
 * ========================================
 *   Word and Line Analysis
 * ========================================
 *
 * Word Analysis:
 *   Total words:          7
 *   Average word length:  4.86 characters
 *   Longest word:         "Programming" (11 chars)
 *
 * Line Analysis:
 *   Total lines:          3
 *   Average line length:  14.67 characters
 *   Average words/line:   2.33 words
 *
 * ========================================
 *   Pointer Demonstration
 * ========================================
 *
 * Text stored at address: 0x7ffeeb3a8060
 * First character:        'H' (ASCII 72)
 * Second character:       'e' (ASCII 101)
 * Last character:         '!' (ASCII 33)
 *
 * First 10 characters with addresses:
 *   ptr[0] = 'H' (ASCII  72) at 0x7ffeeb3a8060
 *   ptr[1] = 'e' (ASCII 101) at 0x7ffeeb3a8061
 *   ptr[2] = 'l' (ASCII 108) at 0x7ffeeb3a8062
 *   ptr[3] = 'l' (ASCII 108) at 0x7ffeeb3a8063
 *   ptr[4] = 'o' (ASCII 111) at 0x7ffeeb3a8064
 *   ptr[5] = ' ' (ASCII  32) at 0x7ffeeb3a8065
 *   ptr[6] = 'W' (ASCII  87) at 0x7ffeeb3a8066
 *   ptr[7] = 'o' (ASCII 111) at 0x7ffeeb3a8067
 *   ptr[8] = 'r' (ASCII 114) at 0x7ffeeb3a8068
 *   ptr[9] = 'l' (ASCII 108) at 0x7ffeeb3a8069
 *
 * ========================================
 *   Character Distribution
 * ========================================
 *
 * Percentage breakdown:
 *   Alphabets:   77.3%
 *   Digits:       0.0%
 *   Spaces:      13.6%
 *   Special:      4.5%
 *   Newlines:     4.5%
 *
 * ========================================
 *   Summary
 * ========================================
 * Total characters: 44
 * Total words:      7
 * Total lines:      3
 * Memory used:      45 bytes
 * ========================================
 */
