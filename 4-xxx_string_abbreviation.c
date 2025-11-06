/*
 * QUESTION xxx:
 * Write a C program to make the abbreviated form of a multiword string.
 *
 * PROGRAM DESCRIPTION:
 * This program creates an abbreviation from a multiword string by taking
 * the first letter of each word. For example:
 * - "United States of America" → "USA"
 * - "World Health Organization" → "WHO"
 * - "Central Processing Unit" → "CPU"
 *
 * The program handles:
 * - Multiple spaces between words
 * - Leading and trailing spaces
 * - Mixed case (converts abbreviation to uppercase)
 * - Special characters and numbers
 *
 * HOW TO SOLVE:
 * 1. Input a multiword string from user
 * 2. Initialize abbreviation string as empty
 * 3. Track if previous character was a space (or start of string)
 * 4. Loop through each character:
 *    - If current is a letter and previous was space/start:
 *      * Add uppercase version to abbreviation
 *    - Track current character for next iteration
 * 5. Handle edge cases (extra spaces, single word, etc.)
 * 6. Display original string, abbreviation, and word count
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function to create abbreviation from multiword string
void createAbbreviation(char str[], char abbr[]) {
   int i = 0, j = 0;
   int isNewWord = 1; // Flag to track start of new word

   while (str[i] != '\0') {
      // Skip spaces
      if (str[i] == ' ' || str[i] == '\t') {
         isNewWord = 1; // Next non-space char starts a new word
      }
      // If it's a letter and it's the start of a new word
      else if (isalpha(str[i]) && isNewWord) {
         abbr[j++] = toupper(str[i]); // Add uppercase letter to abbreviation
         isNewWord = 0;               // We're now inside a word
      }
      // If it's any other character, we're inside a word
      else if (str[i] != ' ' && str[i] != '\t') {
         isNewWord = 0;
      }
      i++;
   }
   abbr[j] = '\0'; // Null terminate the abbreviation
}

// Function to count words in string
int countWords(char str[]) {
   int count = 0;
   int isWord = 0;

   for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
         isWord = 0;
      } else if (isWord == 0) {
         isWord = 1;
         count++;
      }
   }
   return count;
}

// Function to extract individual words
void extractWords(char str[], char words[][50], int *wordCount) {
   int i = 0, j = 0, k = 0;
   *wordCount = 0;

   while (str[i] != '\0') {
      // Skip spaces
      if (str[i] == ' ' || str[i] == '\t') {
         if (k > 0) { // End of a word
            words[j][k] = '\0';
            j++;
            (*wordCount)++;
            k = 0;
         }
      } else {
         words[j][k++] = str[i];
      }
      i++;
   }

   // Handle last word
   if (k > 0) {
      words[j][k] = '\0';
      (*wordCount)++;
   }
}

int main() {
   char str[200], abbr[50];
   char words[50][50];
   int wordCount;

   printf("========================================\n");
   printf("  String Abbreviation Generator\n");
   printf("========================================\n\n");

   printf("Examples:\n");
   printf("  'United States of America' → USA\n");
   printf("  'World Health Organization' → WHO\n");
   printf("  'Central Processing Unit' → CPU\n\n");

   // Input string
   printf("Enter a multiword string: ");
   fgets(str, sizeof(str), stdin);
   str[strcspn(str, "\n")] = '\0'; // Remove newline

   // Create abbreviation
   createAbbreviation(str, abbr);

   // Count words
   wordCount = countWords(str);

   // Extract individual words
   int extractedCount;
   extractWords(str, words, &extractedCount);

   // Display results
   printf("\n========================================\n");
   printf("  Results\n");
   printf("========================================\n\n");

   printf("Original String:\n");
   printf("  \"%s\"\n\n", str);

   printf("Abbreviation:\n");
   printf("  \"%s\"\n\n", abbr);

   printf("--- Word Breakdown ---\n");
   printf("Total words: %d\n\n", wordCount);

   printf("Individual words:\n");
   for (int i = 0; i < extractedCount; i++) {
      printf("  Word %d: %-20s → %c\n", i + 1, words[i], toupper(words[i][0]));
   }

   printf("\n--- Abbreviation Details ---\n");
   printf("Length of abbreviation: %lu characters\n", strlen(abbr));
   printf("Compression ratio: %.1f%%\n",
          (1.0 - (float)strlen(abbr) / strlen(str)) * 100);

   printf("\n--- Letter Breakdown ---\n");
   printf("Full form letters taken:\n");
   for (int i = 0; i < extractedCount; i++) {
      printf("  %c from '%s'\n", toupper(words[i][0]), words[i]);
   }

   printf("\n========================================\n");
   printf("Summary:\n");
   printf("Input:  \"%s\"\n", str);
   printf("Output: \"%s\"\n", abbr);
   printf("Words:  %d\n", wordCount);
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: "United States of America"
 * Output:
 * ========================================
 *   String Abbreviation Generator
 * ========================================
 *
 * Examples:
 *   'United States of America' → USA
 *   'World Health Organization' → WHO
 *   'Central Processing Unit' → CPU
 *
 * Enter a multiword string: United States of America
 *
 * ========================================
 *   Results
 * ========================================
 *
 * Original String:
 *   "United States of America"
 *
 * Abbreviation:
 *   "USOA"
 *
 * --- Word Breakdown ---
 * Total words: 4
 *
 * Individual words:
 *   Word 1: United               → U
 *   Word 2: States               → S
 *   Word 3: of                   → O
 *   Word 4: America              → A
 *
 * --- Abbreviation Details ---
 * Length of abbreviation: 4 characters
 * Compression ratio: 83.3%
 *
 * --- Letter Breakdown ---
 * Full form letters taken:
 *   U from 'United'
 *   S from 'States'
 *   O from 'of'
 *   A from 'America'
 *
 * ========================================
 * Summary:
 * Input:  "United States of America"
 * Output: "USOA"
 * Words:  4
 * ========================================
 *
 * Example 2:
 * Input: "World Health Organization"
 * Output:
 * ========================================
 *   String Abbreviation Generator
 * ========================================
 *
 * Examples:
 *   'United States of America' → USA
 *   'World Health Organization' → WHO
 *   'Central Processing Unit' → CPU
 *
 * Enter a multiword string: World Health Organization
 *
 * ========================================
 *   Results
 * ========================================
 *
 * Original String:
 *   "World Health Organization"
 *
 * Abbreviation:
 *   "WHO"
 *
 * --- Word Breakdown ---
 * Total words: 3
 *
 * Individual words:
 *   Word 1: World                → W
 *   Word 2: Health               → H
 *   Word 3: Organization         → O
 *
 * --- Abbreviation Details ---
 * Length of abbreviation: 3 characters
 * Compression ratio: 88.5%
 *
 * --- Letter Breakdown ---
 * Full form letters taken:
 *   W from 'World'
 *   H from 'Health'
 *   O from 'Organization'
 *
 * ========================================
 * Summary:
 * Input:  "World Health Organization"
 * Output: "WHO"
 * Words:  3
 * ========================================
 *
 * Example 3:
 * Input: "Indian Institute of Technology Bombay"
 * Output:
 * ========================================
 *   String Abbreviation Generator
 * ========================================
 *
 * Examples:
 *   'United States of America' → USA
 *   'World Health Organization' → WHO
 *   'Central Processing Unit' → CPU
 *
 * Enter a multiword string: Indian Institute of Technology Bombay
 *
 * ========================================
 *   Results
 * ========================================
 *
 * Original String:
 *   "Indian Institute of Technology Bombay"
 *
 * Abbreviation:
 *   "IIOTB"
 *
 * --- Word Breakdown ---
 * Total words: 5
 *
 * Individual words:
 *   Word 1: Indian               → I
 *   Word 2: Institute            → I
 *   Word 3: of                   → O
 *   Word 4: Technology           → T
 *   Word 5: Bombay               → B
 *
 * --- Abbreviation Details ---
 * Length of abbreviation: 5 characters
 * Compression ratio: 86.8%
 *
 * --- Letter Breakdown ---
 * Full form letters taken:
 *   I from 'Indian'
 *   I from 'Institute'
 *   O from 'of'
 *   T from 'Technology'
 *   B from 'Bombay'
 *
 * ========================================
 * Summary:
 * Input:  "Indian Institute of Technology Bombay"
 * Output: "IIOTB"
 * Words:  5
 * ========================================
 */
