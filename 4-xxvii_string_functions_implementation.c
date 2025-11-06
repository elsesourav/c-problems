/*
 * QUESTION xxvii:
 * Write a C program to implement strlen(), strcpy(), strcat(), and strcmp() functions.
 *
 * PROGRAM DESCRIPTION:
 * This program demonstrates the implementation of four fundamental string
 * manipulation functions from scratch (without using string.h functions):
 *
 * 1. strlen() - Returns the length of a string
 * 2. strcpy() - Copies one string to another
 * 3. strcat() - Concatenates (appends) one string to another
 * 4. strcmp() - Compares two strings lexicographically
 *
 * HOW TO SOLVE:
 * 1. strlen() implementation:
 *    - Loop through string until null terminator '\0'
 *    - Count each character
 * 2. strcpy() implementation:
 *    - Copy each character from source to destination
 *    - Include null terminator
 * 3. strcat() implementation:
 *    - Find end of destination string
 *    - Append source string from that point
 * 4. strcmp() implementation:
 *    - Compare characters one by one
 *    - Return difference if characters don't match
 *    - Return 0 if strings are equal
 */

#include <stdio.h>

// Custom implementation of strlen()
int myStrlen(char str[]) {
   int length = 0;
   while (str[length] != '\0') {
      length++;
   }
   return length;
}

// Custom implementation of strcpy()
void myStrcpy(char dest[], char src[]) {
   int i = 0;
   while (src[i] != '\0') {
      dest[i] = src[i];
      i++;
   }
   dest[i] = '\0'; // Add null terminator
}

// Custom implementation of strcat()
void myStrcat(char dest[], char src[]) {
   int i = 0, j = 0;

   // Find end of destination string
   while (dest[i] != '\0') {
      i++;
   }

   // Append source string
   while (src[j] != '\0') {
      dest[i] = src[j];
      i++;
      j++;
   }
   dest[i] = '\0'; // Add null terminator
}

// Custom implementation of strcmp()
int myStrcmp(char str1[], char str2[]) {
   int i = 0;

   while (str1[i] != '\0' && str2[i] != '\0') {
      if (str1[i] != str2[i]) {
         return str1[i] - str2[i];
      }
      i++;
   }

   // If we reached here, one or both strings ended
   return str1[i] - str2[i];
}

int main() {
   char str1[100], str2[100], str3[200];
   int length, cmpResult;

   printf("========================================\n");
   printf("  String Function Implementation\n");
   printf("========================================\n\n");

   // Demonstrate strlen()
   printf("--- 1. strlen() - String Length ---\n\n");
   printf("Enter a string: ");
   scanf(" %[^\n]", str1);

   length = myStrlen(str1);
   printf("Length of \"%s\" = %d\n\n", str1, length);

   // Demonstrate strcpy()
   printf("--- 2. strcpy() - String Copy ---\n\n");
   printf("Source string: \"%s\"\n", str1);
   myStrcpy(str2, str1);
   printf("After copying to str2: \"%s\"\n", str2);
   printf("Copy successful!\n\n");

   // Demonstrate strcat()
   printf("--- 3. strcat() - String Concatenation ---\n\n");
   printf("Enter first string: ");
   scanf(" %[^\n]", str1);
   printf("Enter second string: ");
   scanf(" %[^\n]", str2);

   myStrcpy(str3, str1); // Copy first string to str3
   printf("\nBefore concatenation:\n");
   printf("String 1: \"%s\"\n", str1);
   printf("String 2: \"%s\"\n", str2);

   myStrcat(str3, str2); // Concatenate str2 to str3
   printf("\nAfter concatenation (str1 + str2):\n");
   printf("Result: \"%s\"\n\n", str3);

   // Demonstrate strcmp()
   printf("--- 4. strcmp() - String Comparison ---\n\n");
   printf("Enter first string: ");
   scanf(" %[^\n]", str1);
   printf("Enter second string: ");
   scanf(" %[^\n]", str2);

   cmpResult = myStrcmp(str1, str2);

   printf("\nComparing: \"%s\" vs \"%s\"\n", str1, str2);
   printf("Result: %d\n", cmpResult);

   if (cmpResult == 0) {
      printf("Interpretation: Strings are EQUAL\n");
   } else if (cmpResult < 0) {
      printf("Interpretation: \"%s\" comes BEFORE \"%s\"\n", str1, str2);
   } else {
      printf("Interpretation: \"%s\" comes AFTER \"%s\"\n", str1, str2);
   }

   printf("\n========================================\n");
   printf("  Function Summary\n");
   printf("========================================\n");
   printf("strlen(str):       Returns length of string\n");
   printf("strcpy(dest, src): Copies src to dest\n");
   printf("strcat(dest, src): Appends src to dest\n");
   printf("strcmp(s1, s2):    Compares two strings\n");
   printf("                   Returns: 0 (equal)\n");
   printf("                           <0 (s1 < s2)\n");
   printf("                           >0 (s1 > s2)\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   strlen test: "Hello"
 *   strcat: "Hello" and " World"
 *   strcmp: "apple" and "banana"
 * Output:
 * ========================================
 *   String Function Implementation
 * ========================================
 *
 * --- 1. strlen() - String Length ---
 *
 * Enter a string: Hello
 * Length of "Hello" = 5
 *
 * --- 2. strcpy() - String Copy ---
 *
 * Source string: "Hello"
 * After copying to str2: "Hello"
 * Copy successful!
 *
 * --- 3. strcat() - String Concatenation ---
 *
 * Enter first string: Hello
 * Enter second string:  World
 *
 * Before concatenation:
 * String 1: "Hello"
 * String 2: " World"
 *
 * After concatenation (str1 + str2):
 * Result: "Hello World"
 *
 * --- 4. strcmp() - String Comparison ---
 *
 * Enter first string: apple
 * Enter second string: banana
 *
 * Comparing: "apple" vs "banana"
 * Result: -1
 * Interpretation: "apple" comes BEFORE "banana"
 *
 * ========================================
 *   Function Summary
 * ========================================
 * strlen(str):       Returns length of string
 * strcpy(dest, src): Copies src to dest
 * strcat(dest, src): Appends src to dest
 * strcmp(s1, s2):    Compares two strings
 *                    Returns: 0 (equal)
 *                            <0 (s1 < s2)
 *                            >0 (s1 > s2)
 * ========================================
 *
 * Example 2:
 * Input:
 *   strlen test: "Programming"
 *   strcat: "C" and " Language"
 *   strcmp: "hello" and "hello"
 * Output:
 * ========================================
 *   String Function Implementation
 * ========================================
 *
 * --- 1. strlen() - String Length ---
 *
 * Enter a string: Programming
 * Length of "Programming" = 11
 *
 * --- 2. strcpy() - String Copy ---
 *
 * Source string: "Programming"
 * After copying to str2: "Programming"
 * Copy successful!
 *
 * --- 3. strcat() - String Concatenation ---
 *
 * Enter first string: C
 * Enter second string:  Language
 *
 * Before concatenation:
 * String 1: "C"
 * String 2: " Language"
 *
 * After concatenation (str1 + str2):
 * Result: "C Language"
 *
 * --- 4. strcmp() - String Comparison ---
 *
 * Enter first string: hello
 * Enter second string: hello
 *
 * Comparing: "hello" vs "hello"
 * Result: 0
 * Interpretation: Strings are EQUAL
 *
 * ========================================
 *   Function Summary
 * ========================================
 * strlen(str):       Returns length of string
 * strcpy(dest, src): Copies src to dest
 * strcat(dest, src): Appends src to dest
 * strcmp(s1, s2):    Compares two strings
 *                    Returns: 0 (equal)
 *                            <0 (s1 < s2)
 *                            >0 (s1 > s2)
 * ========================================
 *
 * Example 3:
 * Input:
 *   strlen test: "ABC"
 *   strcat: "Good" and " Morning"
 *   strcmp: "zebra" and "apple"
 * Output:
 * ========================================
 *   String Function Implementation
 * ========================================
 *
 * --- 1. strlen() - String Length ---
 *
 * Enter a string: ABC
 * Length of "ABC" = 3
 *
 * --- 2. strcpy() - String Copy ---
 *
 * Source string: "ABC"
 * After copying to str2: "ABC"
 * Copy successful!
 *
 * --- 3. strcat() - String Concatenation ---
 *
 * Enter first string: Good
 * Enter second string:  Morning
 *
 * Before concatenation:
 * String 1: "Good"
 * String 2: " Morning"
 *
 * After concatenation (str1 + str2):
 * Result: "Good Morning"
 *
 * --- 4. strcmp() - String Comparison ---
 *
 * Enter first string: zebra
 * Enter second string: apple
 *
 * Comparing: "zebra" vs "apple"
 * Result: 25
 * Interpretation: "zebra" comes AFTER "apple"
 *
 * ========================================
 *   Function Summary
 * ========================================
 * strlen(str):       Returns length of string
 * strcpy(dest, src): Copies src to dest
 * strcat(dest, src): Appends src to dest
 * strcmp(s1, s2):    Compares two strings
 *                    Returns: 0 (equal)
 *                            <0 (s1 < s2)
 *                            >0 (s1 > s2)
 * ========================================
 */
