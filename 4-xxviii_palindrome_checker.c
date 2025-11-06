/*
 * QUESTION xxviii:
 * Write a C program to check whether a string is palindrome or not.
 *
 * PROGRAM DESCRIPTION:
 * A palindrome is a word, phrase, or sequence that reads the same backward
 * as forward. This program checks if a given string is a palindrome.
 *
 * Examples of palindromes:
 * - "madam" (reads same forwards and backwards)
 * - "racecar"
 * - "noon"
 * - "level"
 *
 * The program checks both:
 * 1. Case-sensitive palindrome (exact match)
 * 2. Case-insensitive palindrome (ignoring case)
 *
 * HOW TO SOLVE:
 * 1. Input a string from the user
 * 2. Method 1 - Using two pointers:
 *    - Place one pointer at start, one at end
 *    - Compare characters at both positions
 *    - Move pointers towards center
 *    - If any mismatch, not palindrome
 * 3. Method 2 - Reverse and compare:
 *    - Create a reversed copy of string
 *    - Compare original with reversed
 * 4. For case-insensitive check, convert to lowercase first
 * 5. Display results with detailed analysis
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function to check palindrome using two-pointer method
int isPalindrome(char str[]) {
   int left = 0;
   int right = strlen(str) - 1;

   while (left < right) {
      if (str[left] != str[right]) {
         return 0; // Not palindrome
      }
      left++;
      right--;
   }
   return 1; // Palindrome
}

// Function to check case-insensitive palindrome
int isPalindromeCaseInsensitive(char str[]) {
   int left = 0;
   int right = strlen(str) - 1;

   while (left < right) {
      if (tolower(str[left]) != tolower(str[right])) {
         return 0; // Not palindrome
      }
      left++;
      right--;
   }
   return 1; // Palindrome
}

// Function to reverse a string
void reverseString(char str[], char reversed[]) {
   int length = strlen(str);
   int i, j = 0;

   for (i = length - 1; i >= 0; i--) {
      reversed[j] = str[i];
      j++;
   }
   reversed[j] = '\0';
}

// Function to convert string to lowercase
void toLowerCase(char str[], char lower[]) {
   int i = 0;
   while (str[i] != '\0') {
      lower[i] = tolower(str[i]);
      i++;
   }
   lower[i] = '\0';
}

int main() {
   char str[100], reversed[100], lower[100];
   int result, resultCI;

   printf("========================================\n");
   printf("  Palindrome Checker\n");
   printf("========================================\n\n");

   printf("What is a Palindrome?\n");
   printf("A word/phrase that reads the same\n");
   printf("backwards as forwards.\n");
   printf("Examples: madam, racecar, noon, level\n\n");

   // Input string
   printf("Enter a string: ");
   scanf("%s", str);

   // Check palindrome (case-sensitive)
   result = isPalindrome(str);

   // Check palindrome (case-insensitive)
   resultCI = isPalindromeCaseInsensitive(str);

   // Reverse the string for display
   reverseString(str, reversed);

   // Convert to lowercase for display
   toLowerCase(str, lower);

   // Display results
   printf("\n========================================\n");
   printf("  Analysis Results\n");
   printf("========================================\n\n");

   printf("Original string:  \"%s\"\n", str);
   printf("Reversed string:  \"%s\"\n", reversed);
   printf("Lowercase:        \"%s\"\n\n", lower);

   printf("--- Case-Sensitive Check ---\n");
   if (result) {
      printf("✓ \"%s\" is a PALINDROME\n", str);
      printf("  (reads same forwards and backwards)\n");
   } else {
      printf("✗ \"%s\" is NOT a palindrome\n", str);
      printf("  (forwards: %s, backwards: %s)\n", str, reversed);
   }

   printf("\n--- Case-Insensitive Check ---\n");
   if (resultCI) {
      printf("✓ \"%s\" is a PALINDROME (ignoring case)\n", str);
   } else {
      printf("✗ \"%s\" is NOT a palindrome (even ignoring case)\n", str);
   }

   // Character-by-character comparison display
   printf("\n--- Character Comparison ---\n");
   int length = strlen(str);
   printf("Position: ");
   for (int i = 0; i < length; i++) {
      printf("%3d ", i);
   }
   printf("\nForward:  ");
   for (int i = 0; i < length; i++) {
      printf("  %c ", str[i]);
   }
   printf("\nBackward: ");
   for (int i = length - 1; i >= 0; i--) {
      printf("  %c ", str[i]);
   }
   printf("\nMatch:    ");
   for (int i = 0; i < length; i++) {
      if (str[i] == str[length - 1 - i]) {
         printf("  ✓ ");
      } else {
         printf("  ✗ ");
      }
   }
   printf("\n");

   printf("\n========================================\n");
   printf("Summary:\n");
   printf("Length: %d characters\n", length);
   printf("Case-sensitive palindrome: %s\n", result ? "YES" : "NO");
   printf("Case-insensitive palindrome: %s\n", resultCI ? "YES" : "NO");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input: "madam"
 * Output:
 * ========================================
 *   Palindrome Checker
 * ========================================
 *
 * What is a Palindrome?
 * A word/phrase that reads the same
 * backwards as forwards.
 * Examples: madam, racecar, noon, level
 *
 * Enter a string: madam
 *
 * ========================================
 *   Analysis Results
 * ========================================
 *
 * Original string:  "madam"
 * Reversed string:  "madam"
 * Lowercase:        "madam"
 *
 * --- Case-Sensitive Check ---
 * ✓ "madam" is a PALINDROME
 *   (reads same forwards and backwards)
 *
 * --- Case-Insensitive Check ---
 * ✓ "madam" is a PALINDROME (ignoring case)
 *
 * --- Character Comparison ---
 * Position:   0   1   2   3   4
 * Forward:    m   a   d   a   m
 * Backward:   m   a   d   a   m
 * Match:      ✓   ✓   ✓   ✓   ✓
 *
 * ========================================
 * Summary:
 * Length: 5 characters
 * Case-sensitive palindrome: YES
 * Case-insensitive palindrome: YES
 * ========================================
 *
 * Example 2:
 * Input: "hello"
 * Output:
 * ========================================
 *   Palindrome Checker
 * ========================================
 *
 * What is a Palindrome?
 * A word/phrase that reads the same
 * backwards as forwards.
 * Examples: madam, racecar, noon, level
 *
 * Enter a string: hello
 *
 * ========================================
 *   Analysis Results
 * ========================================
 *
 * Original string:  "hello"
 * Reversed string:  "olleh"
 * Lowercase:        "hello"
 *
 * --- Case-Sensitive Check ---
 * ✗ "hello" is NOT a palindrome
 *   (forwards: hello, backwards: olleh)
 *
 * --- Case-Insensitive Check ---
 * ✗ "hello" is NOT a palindrome (even ignoring case)
 *
 * --- Character Comparison ---
 * Position:   0   1   2   3   4
 * Forward:    h   e   l   l   o
 * Backward:   o   l   l   e   h
 * Match:      ✗   ✗   ✓   ✗   ✗
 *
 * ========================================
 * Summary:
 * Length: 5 characters
 * Case-sensitive palindrome: NO
 * Case-insensitive palindrome: NO
 * ========================================
 *
 * Example 3:
 * Input: "Racecar"
 * Output:
 * ========================================
 *   Palindrome Checker
 * ========================================
 *
 * What is a Palindrome?
 * A word/phrase that reads the same
 * backwards as forwards.
 * Examples: madam, racecar, noon, level
 *
 * Enter a string: Racecar
 *
 * ========================================
 *   Analysis Results
 * ========================================
 *
 * Original string:  "Racecar"
 * Reversed string:  "racecaR"
 * Lowercase:        "racecar"
 *
 * --- Case-Sensitive Check ---
 * ✗ "Racecar" is NOT a palindrome
 *   (forwards: Racecar, backwards: racecaR)
 *
 * --- Case-Insensitive Check ---
 * ✓ "Racecar" is a PALINDROME (ignoring case)
 *
 * --- Character Comparison ---
 * Position:   0   1   2   3   4   5   6
 * Forward:    R   a   c   e   c   a   r
 * Backward:   r   a   c   e   c   a   R
 * Match:      ✗   ✓   ✓   ✓   ✓   ✓   ✗
 *
 * ========================================
 * Summary:
 * Length: 7 characters
 * Case-sensitive palindrome: NO
 * Case-insensitive palindrome: YES
 * ========================================
 */
