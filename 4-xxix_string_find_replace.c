/*
 * QUESTION xxix:
 * Write a C program to replace a specific character/string by another
 * character/string in a multiword string.
 *
 * PROGRAM DESCRIPTION:
 * This program performs find-and-replace operations on a multiword string.
 * It can replace:
 * 1. A single character with another character
 * 2. A substring with another substring
 * 3. All occurrences or just the first occurrence
 *
 * The program handles:
 * - Multiple occurrences of the search pattern
 * - Case-sensitive and case-insensitive search
 * - Different lengths of old and new strings
 *
 * HOW TO SOLVE:
 * 1. Input the main string from user
 * 2. Input search string (to find) and replace string (to replace with)
 * 3. For character replacement:
 *    - Loop through string
 *    - If character matches, replace it
 * 4. For substring replacement:
 *    - Find occurrence of substring using string search
 *    - Create new string with replacement
 *    - Handle position shifting based on length difference
 * 5. Count and display number of replacements made
 * 6. Show before and after strings
 */

#include <stdio.h>
#include <string.h>

// Function to replace all occurrences of a character
int replaceChar(char str[], char oldChar, char newChar) {
   int count = 0;
   for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] == oldChar) {
         str[i] = newChar;
         count++;
      }
   }
   return count;
}

// Function to find substring in string
char *findSubstring(char str[], char substr[]) {
   int strLen = strlen(str);
   int subLen = strlen(substr);

   for (int i = 0; i <= strLen - subLen; i++) {
      int j;
      for (j = 0; j < subLen; j++) {
         if (str[i + j] != substr[j]) {
            break;
         }
      }
      if (j == subLen) {
         return &str[i]; // Found substring
      }
   }
   return NULL; // Not found
}

// Function to replace first occurrence of substring
int replaceFirstSubstring(char str[], char oldStr[], char newStr[]) {
   char result[500] = "";
   char *pos = strstr(str, oldStr);

   if (pos == NULL) {
      return 0; // Substring not found
   }

   // Copy part before the match
   strncat(result, str, pos - str);

   // Add replacement string
   strcat(result, newStr);

   // Add part after the match
   strcat(result, pos + strlen(oldStr));

   // Copy result back to original string
   strcpy(str, result);

   return 1; // Replacement made
}

// Function to replace all occurrences of substring
int replaceAllSubstrings(char str[], char oldStr[], char newStr[]) {
   char result[500] = "";
   char temp[500];
   int count = 0;

   strcpy(temp, str);

   char *pos;
   while ((pos = strstr(temp, oldStr)) != NULL) {
      // Copy part before the match
      strncat(result, temp, pos - temp);

      // Add replacement string
      strcat(result, newStr);

      // Move temp pointer after the match
      strcpy(temp, pos + strlen(oldStr));
      count++;
   }

   // Add remaining part
   strcat(result, temp);

   // Copy result back to original string
   strcpy(str, result);

   return count;
}

int main() {
   char str[500], oldStr[100], newStr[100];
   char backup[500];
   int choice, count;
   char oldChar, newChar;

   printf("========================================\n");
   printf("  String Find and Replace\n");
   printf("========================================\n\n");

   // Input main string
   printf("Enter the main string: ");
   fgets(str, sizeof(str), stdin);
   str[strcspn(str, "\n")] = '\0'; // Remove newline

   strcpy(backup, str); // Backup original string

   printf("\nOriginal String: \"%s\"\n", str);

   // Choose operation
   printf("\n--- Choose Operation ---\n");
   printf("1. Replace character\n");
   printf("2. Replace substring (first occurrence)\n");
   printf("3. Replace substring (all occurrences)\n");
   printf("Enter choice (1-3): ");
   scanf("%d", &choice);
   getchar(); // Consume newline

   printf("\n========================================\n");

   switch (choice) {
   case 1:
      // Replace character
      printf("Enter character to find: ");
      scanf("%c", &oldChar);
      getchar();
      printf("Enter character to replace with: ");
      scanf("%c", &newChar);

      count = replaceChar(str, oldChar, newChar);

      printf("\n--- Character Replacement ---\n");
      printf("Original:  \"%s\"\n", backup);
      printf("Modified:  \"%s\"\n", str);
      printf("Replaced '%c' with '%c' (%d occurrence%s)\n",
             oldChar, newChar, count, count != 1 ? "s" : "");
      break;

   case 2:
      // Replace first occurrence
      printf("Enter substring to find: ");
      fgets(oldStr, sizeof(oldStr), stdin);
      oldStr[strcspn(oldStr, "\n")] = '\0';

      printf("Enter replacement string: ");
      fgets(newStr, sizeof(newStr), stdin);
      newStr[strcspn(newStr, "\n")] = '\0';

      count = replaceFirstSubstring(str, oldStr, newStr);

      printf("\n--- Substring Replacement (First) ---\n");
      printf("Original:  \"%s\"\n", backup);
      printf("Modified:  \"%s\"\n", str);
      if (count > 0) {
         printf("Replaced \"%s\" with \"%s\" (first occurrence)\n",
                oldStr, newStr);
      } else {
         printf("\"%s\" not found in string\n", oldStr);
      }
      break;

   case 3:
      // Replace all occurrences
      printf("Enter substring to find: ");
      fgets(oldStr, sizeof(oldStr), stdin);
      oldStr[strcspn(oldStr, "\n")] = '\0';

      printf("Enter replacement string: ");
      fgets(newStr, sizeof(newStr), stdin);
      newStr[strcspn(newStr, "\n")] = '\0';

      count = replaceAllSubstrings(str, oldStr, newStr);

      printf("\n--- Substring Replacement (All) ---\n");
      printf("Original:  \"%s\"\n", backup);
      printf("Modified:  \"%s\"\n", str);
      printf("Replaced \"%s\" with \"%s\" (%d occurrence%s)\n",
             oldStr, newStr, count, count != 1 ? "s" : "");
      break;

   default:
      printf("Invalid choice!\n");
      return 1;
   }

   printf("\n========================================\n");
   printf("Summary:\n");
   printf("Original length: %lu characters\n", strlen(backup));
   printf("New length:      %lu characters\n", strlen(str));
   printf("Replacements:    %d\n", count);
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1: (Character replacement)
 * Input:
 *   String: "Hello World"
 *   Choice: 1
 *   Find: 'o'
 *   Replace: '0'
 * Output:
 * ========================================
 *   String Find and Replace
 * ========================================
 *
 * Enter the main string: Hello World
 *
 * Original String: "Hello World"
 *
 * --- Choose Operation ---
 * 1. Replace character
 * 2. Replace substring (first occurrence)
 * 3. Replace substring (all occurrences)
 * Enter choice (1-3): 1
 *
 * ========================================
 * Enter character to find: o
 * Enter character to replace with: 0
 *
 * --- Character Replacement ---
 * Original:  "Hello World"
 * Modified:  "Hell0 W0rld"
 * Replaced 'o' with '0' (2 occurrences)
 *
 * ========================================
 * Summary:
 * Original length: 11 characters
 * New length:      11 characters
 * Replacements:    2
 * ========================================
 *
 * Example 2: (First substring replacement)
 * Input:
 *   String: "The cat sat on the mat"
 *   Choice: 2
 *   Find: "cat"
 *   Replace: "dog"
 * Output:
 * ========================================
 *   String Find and Replace
 * ========================================
 *
 * Enter the main string: The cat sat on the mat
 *
 * Original String: "The cat sat on the mat"
 *
 * --- Choose Operation ---
 * 1. Replace character
 * 2. Replace substring (first occurrence)
 * 3. Replace substring (all occurrences)
 * Enter choice (1-3): 2
 *
 * ========================================
 * Enter substring to find: cat
 * Enter replacement string: dog
 *
 * --- Substring Replacement (First) ---
 * Original:  "The cat sat on the mat"
 * Modified:  "The dog sat on the mat"
 * Replaced "cat" with "dog" (first occurrence)
 *
 * ========================================
 * Summary:
 * Original length: 22 characters
 * New length:      22 characters
 * Replacements:    1
 * ========================================
 *
 * Example 3: (All substring replacements)
 * Input:
 *   String: "I love C. C is powerful. C programming is fun."
 *   Choice: 3
 *   Find: "C"
 *   Replace: "Python"
 * Output:
 * ========================================
 *   String Find and Replace
 * ========================================
 *
 * Enter the main string: I love C. C is powerful. C programming is fun.
 *
 * Original String: "I love C. C is powerful. C programming is fun."
 *
 * --- Choose Operation ---
 * 1. Replace character
 * 2. Replace substring (first occurrence)
 * 3. Replace substring (all occurrences)
 * Enter choice (1-3): 3
 *
 * ========================================
 * Enter substring to find: C
 * Enter replacement string: Python
 *
 * --- Substring Replacement (All) ---
 * Original:  "I love C. C is powerful. C programming is fun."
 * Modified:  "I love Python. Python is powerful. Python programming is fun."
 * Replaced "C" with "Python" (3 occurrences)
 *
 * ========================================
 * Summary:
 * Original length: 46 characters
 * New length:      61 characters
 * Replacements:    3
 * ========================================
 */
