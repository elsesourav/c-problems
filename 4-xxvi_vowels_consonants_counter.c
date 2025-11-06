/*
 * QUESTION xxvi:
 * Write a C program to find the number of vowels and consonants in a string.
 *
 * PROGRAM DESCRIPTION:
 * This program takes a string as input and counts the number of vowels
 * and consonants present in it. Vowels are: a, e, i, o, u (case-insensitive)
 * and consonants are all other alphabetic characters.
 *
 * The program also counts:
 * - Total alphabetic characters
 * - Digits
 * - Special characters and spaces
 *
 * HOW TO SOLVE:
 * 1. Input a string from the user (can use gets, fgets, or scanf)
 * 2. Initialize counters: vowels=0, consonants=0, digits=0, special=0
 * 3. Loop through each character of the string:
 *    - Convert to lowercase for easy comparison
 *    - Check if character is vowel (a,e,i,o,u)
 *    - Else check if it's an alphabet (consonant)
 *    - Else check if it's a digit
 *    - Else it's a special character
 * 4. Display all counts
 * 5. Show percentage distribution
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function to check if a character is vowel
int isVowel(char ch) {
   ch = tolower(ch);
   return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
   char str[200];
   int vowels = 0, consonants = 0, digits = 0, spaces = 0, special = 0;
   int i, length;

   printf("========================================\n");
   printf("  Vowel and Consonant Counter\n");
   printf("========================================\n\n");

   // Input string
   printf("Enter a string: ");
   fgets(str, sizeof(str), stdin);

   // Remove newline character if present
   str[strcspn(str, "\n")] = '\0';

   length = strlen(str);

   // Count vowels, consonants, digits, and special characters
   for (i = 0; i < length; i++) {
      if (isalpha(str[i])) {
         if (isVowel(str[i])) {
            vowels++;
         } else {
            consonants++;
         }
      } else if (isdigit(str[i])) {
         digits++;
      } else if (str[i] == ' ') {
         spaces++;
      } else {
         special++;
      }
   }

   // Display results
   printf("\n========================================\n");
   printf("  Analysis Results\n");
   printf("========================================\n\n");

   printf("Input String: \"%s\"\n", str);
   printf("String Length: %d characters\n\n", length);

   printf("--- Character Breakdown ---\n");
   printf("Vowels:            %d\n", vowels);
   printf("Consonants:        %d\n", consonants);
   printf("Alphabets (Total): %d\n", vowels + consonants);
   printf("Digits:            %d\n", digits);
   printf("Spaces:            %d\n", spaces);
   printf("Special chars:     %d\n\n", special);

   // Display vowel and consonant details
   printf("--- Vowel Details ---\n");
   printf("Vowels found: ");
   for (i = 0; i < length; i++) {
      if (isalpha(str[i]) && isVowel(str[i])) {
         printf("%c ", str[i]);
      }
   }
   if (vowels == 0)
      printf("None");
   printf("\n\n");

   printf("--- Consonant Details ---\n");
   printf("Consonants found: ");
   for (i = 0; i < length; i++) {
      if (isalpha(str[i]) && !isVowel(str[i])) {
         printf("%c ", str[i]);
      }
   }
   if (consonants == 0)
      printf("None");
   printf("\n\n");

   // Percentage distribution
   if (length > 0) {
      printf("--- Percentage Distribution ---\n");
      printf("Vowels:       %.2f%%\n", (vowels * 100.0) / length);
      printf("Consonants:   %.2f%%\n", (consonants * 100.0) / length);
      printf("Digits:       %.2f%%\n", (digits * 100.0) / length);
      printf("Spaces:       %.2f%%\n", (spaces * 100.0) / length);
      printf("Special:      %.2f%%\n", (special * 100.0) / length);
   }

   printf("\n========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: "Hello World"
 * Output:
 * ========================================
 *   Vowel and Consonant Counter
 * ========================================
 *
 * Enter a string: Hello World
 *
 * ========================================
 *   Analysis Results
 * ========================================
 *
 * Input String: "Hello World"
 * String Length: 11 characters
 *
 * --- Character Breakdown ---
 * Vowels:            3
 * Consonants:        7
 * Alphabets (Total): 10
 * Digits:            0
 * Spaces:            1
 * Special chars:     0
 *
 * --- Vowel Details ---
 * Vowels found: e o o
 *
 * --- Consonant Details ---
 * Consonants found: H l l W r l d
 *
 * --- Percentage Distribution ---
 * Vowels:       27.27%
 * Consonants:   63.64%
 * Digits:       0.00%
 * Spaces:       9.09%
 * Special:      0.00%
 *
 * ========================================
 *
 * Example 2:
 * Input: "Programming in C 2025!"
 * Output:
 * ========================================
 *   Vowel and Consonant Counter
 * ========================================
 *
 * Enter a string: Programming in C 2025!
 *
 * ========================================
 *   Analysis Results
 * ========================================
 *
 * Input String: "Programming in C 2025!"
 * String Length: 22 characters
 *
 * --- Character Breakdown ---
 * Vowels:            5
 * Consonants:        11
 * Alphabets (Total): 16
 * Digits:            4
 * Spaces:            3
 * Special chars:     1
 *
 * --- Vowel Details ---
 * Vowels found: o a i i
 *
 * --- Consonant Details ---
 * Consonants found: P r g r m m n g n C
 *
 * --- Percentage Distribution ---
 * Vowels:       22.73%
 * Consonants:   50.00%
 * Digits:       18.18%
 * Spaces:       13.64%
 * Special:      4.55%
 *
 * ========================================
 *
 * Example 3:
 * Input: "AEIOU are vowels"
 * Output:
 * ========================================
 *   Vowel and Consonant Counter
 * ========================================
 *
 * Enter a string: AEIOU are vowels
 *
 * ========================================
 *   Analysis Results
 * ========================================
 *
 * Input String: "AEIOU are vowels"
 * String Length: 16 characters
 *
 * --- Character Breakdown ---
 * Vowels:            9
 * Consonants:        5
 * Alphabets (Total): 14
 * Digits:            0
 * Spaces:            2
 * Special chars:     0
 *
 * --- Vowel Details ---
 * Vowels found: A E I O U a e o e
 *
 * --- Consonant Details ---
 * Consonants found: r v w l s
 *
 * --- Percentage Distribution ---
 * Vowels:       56.25%
 * Consonants:   31.25%
 * Digits:       0.00%
 * Spaces:       12.50%
 * Special:      0.00%
 *
 * ========================================
 */
