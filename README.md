# C Programming - Complete Exercise Library

A comprehensive collection of 43 C programming exercises covering fundamental to advanced concepts, organized in 6 sections with detailed implementations.

---

## 📚 Table of Contents

- [Section 1: Format Specifiers (i-iv)](#section-1-format-specifiers)
- [Section 2: Control Structures (v-x)](#section-2-control-structures)
- [Section 3: Loops & Patterns (xi-xix)](#section-3-loops--patterns)
- [Section 4: Arrays, Matrices & Strings (xxi-xxx)](#section-4-arrays-matrices--strings)
- [Section 5: Functions, Pointers & Structures (xxxi-xxxix)](#section-5-functions-pointers--structures)
- [Section 6: File Handling (xl-xliv)](#section-6-file-handling)

---

## Section 1: Format Specifiers

### **i) Basic Input/Output Operations**

📁 **File:** `1-i_basic_io.c`

**Question:**  
Write a C program demonstrating basic input and output operations using different format specifiers.

**Description:**  
This program demonstrates various format specifiers in C including %d (integer), %f (float), %lf (double), %c (character), %s (string), and %u (unsigned). It shows how to properly read and display different data types with proper formatting.

**How to Solve:**

1. Declare variables of different data types (int, float, double, char, string)
2. Use printf() to prompt user for input
3. Use scanf() with appropriate format specifiers to read input
4. Display the values using printf() with proper formatting
5. Demonstrate precision control for floating-point numbers

---

### **ii) Size and Range of Data Types**

📁 **File:** `1-ii_sizeof_range.c`

**Question:**  
Write a C program to display the size and range of various data types.

**Description:**  
This program uses sizeof() operator to find the size of different data types in bytes. It also calculates and displays the minimum and maximum values that each data type can hold using limits.h header file.

**How to Solve:**

1. Include limits.h and float.h for predefined constants
2. Use sizeof() operator for each data type
3. Display size in bytes
4. Use macros like INT_MIN, INT_MAX, FLT_MIN, FLT_MAX for ranges
5. Format output in a readable table format

---

### **iii) ASCII Values**

📁 **File:** `1-iii_ascii_values.c`

**Question:**  
Write a C program to display ASCII values of characters and vice versa.

**Description:**  
This program demonstrates the relationship between characters and their ASCII values. It shows how to convert characters to ASCII codes and ASCII codes back to characters, including a complete ASCII table display.

**How to Solve:**

1. Read a character from user
2. Display its ASCII value using %d format specifier
3. Read an ASCII value and display corresponding character
4. Create a loop to display complete ASCII table (0-127)
5. Show both printable and non-printable characters

---

### **iv) Number System Conversions**

📁 **File:** `1-iv_number_systems.c`

**Question:**  
Write a C program to convert numbers between different number systems (Decimal, Binary, Octal, Hexadecimal).

**Description:**  
This program performs conversions between decimal, binary, octal, and hexadecimal number systems. It demonstrates bitwise operations and modular arithmetic for base conversions.

**How to Solve:**

1. **Decimal to Binary:** Repeatedly divide by 2, store remainders
2. **Decimal to Octal:** Repeatedly divide by 8, store remainders
3. **Decimal to Hexadecimal:** Repeatedly divide by 16, convert remainders to hex digits
4. **Binary/Octal/Hex to Decimal:** Multiply each digit by base^position and sum
5. Display all conversions with proper formatting

---

## Section 2: Control Structures

### **v) Leap Year Check**

📁 **File:** `2-v_leap_year.c`

**Question:**  
Write a C program to check whether a given year is a leap year or not.

**Description:**  
This program determines if a year is a leap year using the standard leap year rules: divisible by 4 but not by 100, OR divisible by 400.

**How to Solve:**

1. Read year from user
2. Check conditions:
   - If divisible by 400 → Leap year
   - Else if divisible by 100 → Not a leap year
   - Else if divisible by 4 → Leap year
   - Else → Not a leap year
3. Display result with explanation
4. Show next/previous leap years

**Example:**

```
Input: 2024
Output: 2024 is a Leap Year (divisible by 4 and not by 100)

Input: 1900
Output: 1900 is NOT a Leap Year (divisible by 100 but not by 400)

Input: 2000
Output: 2000 is a Leap Year (divisible by 400)
```

---

### **vi) Prime Number Check**

📁 **File:** `2-vi_prime_number.c`

**Question:**  
Write a C program to check whether a given number is prime or not.

**Description:**  
This program determines if a number is prime by checking divisibility. It uses an optimized approach checking only up to square root of the number.

**How to Solve:**

1. Read number from user
2. Handle special cases (numbers ≤ 1 are not prime, 2 is prime)
3. Check if even (not prime except 2)
4. Loop from 3 to √n with step 2
5. If any divisor found, not prime
6. Display result with factors if composite

**Example:**

```
Input: 17
Output: 17 is a PRIME number

Input: 24
Output: 24 is NOT a prime number
Factors: 1, 2, 3, 4, 6, 8, 12, 24
```

---

### **vii) Armstrong Number Check**

📁 **File:** `2-vii_armstrong_number.c`

**Question:**  
Write a C program to check if a number is an Armstrong number (narcissistic number).

**Description:**  
An Armstrong number is a number that equals the sum of its own digits each raised to the power of the number of digits. Example: 153 = 1³ + 5³ + 3³

**How to Solve:**

1. Read number and store original value
2. Count number of digits
3. Extract each digit using modulo 10
4. Calculate digit^(number of digits)
5. Sum all powered digits
6. Compare sum with original number

**Example:**

```
Input: 153
Output: 153 is an Armstrong number
Calculation: 1³ + 5³ + 3³ = 1 + 125 + 27 = 153

Input: 9474
Output: 9474 is an Armstrong number
Calculation: 9⁴ + 4⁴ + 7⁴ + 4⁴ = 6561 + 256 + 2401 + 256 = 9474
```

---

### **viii) Palindrome Check**

📁 **File:** `2-viii_palindrome.c`

**Question:**  
Write a C program to check if a number is a palindrome.

**Description:**  
A palindrome number reads the same forwards and backwards. This program reverses the number and compares it with the original.

**How to Solve:**

1. Read number and store original
2. Initialize reversed number to 0
3. Extract last digit using modulo 10
4. Build reversed number: reversed = reversed \* 10 + digit
5. Remove last digit: number = number / 10
6. Compare reversed with original

**Example:**

```
Input: 12321
Output: 12321 is a PALINDROME

Input: 12345
Output: 12345 is NOT a palindrome
Reversed: 54321
```

---

### **ix) Perfect Number Check**

📁 **File:** `2-ix_perfect_number.c`

**Question:**  
Write a C program to check if a number is a perfect number.

**Description:**  
A perfect number is a positive integer equal to the sum of its proper divisors (excluding itself). Example: 6 = 1 + 2 + 3

**How to Solve:**

1. Read number from user
2. Find all divisors from 1 to n/2
3. Sum all divisors
4. Compare sum with original number
5. Display all divisors

**Example:**

```
Input: 28
Output: 28 is a PERFECT number
Divisors: 1, 2, 4, 7, 14
Sum: 1 + 2 + 4 + 7 + 14 = 28

Input: 12
Output: 12 is NOT a perfect number
Divisors: 1, 2, 3, 4, 6
Sum: 16 (deficient number)
```

---

### **x) Grade Calculator**

📁 **File:** `2-x_grade_calculator.c`

**Question:**  
Write a C program to calculate percentage and assign grades based on marks.

**Description:**  
This program takes marks in multiple subjects, calculates total, percentage, and assigns letter grades based on percentage ranges.

**How to Solve:**

1. Input number of subjects and marks
2. Calculate total marks
3. Calculate percentage = (total / max_marks) × 100
4. Assign grade based on ranges:
   - A: 90-100%, B: 80-89%, C: 70-79%, D: 60-69%, F: <60%
5. Display result with pass/fail status

**Example:**

```
Input: 3 subjects: 85, 92, 78
Output:
Total: 255/300
Percentage: 85.00%
Grade: B
Status: PASSED
```

---

## Section 3: Loops & Patterns

### **xi) Fibonacci Series**

📁 **File:** `3-xi_fibonacci_series.c`

**Question:**  
Write a C program to generate Fibonacci series up to n terms.

**Description:**  
Fibonacci series: Each number is the sum of the previous two numbers. Series: 0, 1, 1, 2, 3, 5, 8, 13, 21...

**How to Solve:**

1. Initialize first two terms: a=0, b=1
2. Display first two terms
3. Loop for remaining terms:
   - Calculate next = a + b
   - Display next
   - Update: a = b, b = next
4. Show both iterative and recursive approaches

**Example:**

```
Input: 10 terms
Output: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
```

---

### **xii) Factorial Calculation**

📁 **File:** `3-xii_factorial.c`

**Question:**  
Write a C program to calculate factorial of a number.

**Description:**  
Factorial of n (n!) = n × (n-1) × (n-2) × ... × 1. Shows both iterative and recursive methods.

**How to Solve:**

1. Read number n
2. **Iterative method:**
   - Initialize factorial = 1
   - Loop from 1 to n, multiply each number
3. **Recursive method:**
   - Base case: if n=0 or n=1, return 1
   - Recursive case: return n × factorial(n-1)
4. Handle large numbers with long long

**Example:**

```
Input: 5
Output: 5! = 120
Calculation: 5 × 4 × 3 × 2 × 1 = 120

Input: 10
Output: 10! = 3628800
```

---

### **xiii) Sum of Digits**

📁 **File:** `3-xiii_sum_of_digits.c`

**Question:**  
Write a C program to find the sum of digits of a number.

**Description:**  
This program extracts each digit and calculates their sum. Also shows digit count and average.

**How to Solve:**

1. Read number
2. Initialize sum = 0, count = 0
3. While number > 0:
   - Extract last digit: digit = num % 10
   - Add to sum: sum += digit
   - Remove last digit: num /= 10
   - Increment count
4. Display sum, count, average

**Example:**

```
Input: 12345
Output:
Sum of digits: 15 (1+2+3+4+5)
Number of digits: 5
Average: 3.00
```

---

### **xiv) GCD and LCM**

📁 **File:** `3-xiv_gcd_lcm.c`

**Question:**  
Write a C program to find GCD (HCF) and LCM of two numbers.

**Description:**  
GCD is the greatest common divisor. LCM is the least common multiple. Uses Euclidean algorithm for efficiency.

**How to Solve:**

1. **GCD (Euclidean algorithm):**
   - While b ≠ 0:
     - temp = b
     - b = a % b
     - a = temp
   - GCD = a
2. **LCM formula:**
   - LCM = (num1 × num2) / GCD
3. Show step-by-step process

**Example:**

```
Input: 48, 18
Output:
GCD: 6
LCM: 144
Steps: 48%18=12, 18%12=6, 12%6=0 → GCD=6
```

---

### **xv) Number Patterns**

📁 **File:** `3-xv_number_patterns.c`

**Question:**  
Write a C program to print various number patterns.

**Description:**  
This program generates multiple number patterns including pyramids, triangles, and number sequences.

**How to Solve:**

1. Use nested loops (outer for rows, inner for columns)
2. **Pattern types:**
   - Right triangle
   - Pyramid
   - Inverted pyramid
   - Floyd's triangle
   - Pascal's triangle
3. Control spaces and numbers with loop variables

**Example Patterns:**

```
Right Triangle:    Pyramid:        Floyd's Triangle:
1                    1              1
1 2                 1 2 1           2 3
1 2 3              1 2 3 2 1        4 5 6
1 2 3 4           1 2 3 4 3 2 1     7 8 9 10
```

---

### **xvi) Star Patterns**

📁 **File:** `3-xvi_star_patterns.c`

**Question:**  
Write a C program to print various star patterns.

**Description:**  
Generates different star patterns including pyramids, diamonds, and hollow patterns.

**How to Solve:**

1. Use nested loops for rows and columns
2. Calculate spaces and stars based on row number
3. **Patterns include:**
   - Right triangle
   - Full pyramid
   - Inverted pyramid
   - Diamond
   - Hollow square/pyramid
4. Use symmetry for complex patterns

**Example Patterns:**

```
Pyramid:          Diamond:         Hollow Square:
    *                *             * * * * *
   ***              ***            *       *
  *****            *****           *       *
 *******          *******          *       *
*********          *****           * * * * *
                    ***
                     *
```

---

### **xvii) Prime Numbers in Range**

📁 **File:** `3-xvii_prime_range.c`

**Question:**  
Write a C program to display all prime numbers within a given range.

**Description:**  
This program finds and displays all prime numbers between two given numbers with count and sum.

**How to Solve:**

1. Input start and end range
2. For each number in range:
   - Check if prime (using prime checking algorithm)
   - If prime, display and count
3. Calculate sum of all primes
4. Display statistics

**Example:**

```
Input: Range 10 to 30
Output:
Prime numbers: 11, 13, 17, 19, 23, 29
Count: 6 primes
Sum: 112
```

---

### **xviii) Multiplication Table**

📁 **File:** `3-xviii_multiplication_table.c`

**Question:**  
Write a C program to display multiplication tables.

**Description:**  
Generates multiplication tables for one or multiple numbers with formatting.

**How to Solve:**

1. Input number or range
2. Nested loop:
   - Outer loop: for each number
   - Inner loop: multiply by 1 to 10
3. Format output in columns
4. Option for custom range

**Example:**

```
Multiplication Table of 5:
5 × 1 = 5
5 × 2 = 10
5 × 3 = 15
...
5 × 10 = 50
```

---

### **xix) Number Pyramid Patterns**

📁 **File:** `3-xix_pyramid_patterns.c`

**Question:**  
Write a C program to print advanced pyramid patterns with numbers.

**Description:**  
Creates complex number pyramids including palindromic numbers, centered patterns, and special sequences.

**How to Solve:**

1. **Palindrome pyramid:** Numbers increase then decrease
2. **Number diamond:** Combine upward and downward pyramids
3. Use spaces for centering
4. Control number sequences with loop variables

**Example:**

```
Palindrome Pyramid:
    1
   121
  12321
 1234321
123454321
```

---

## Section 4: Arrays, Matrices & Strings

### **xxi) Array Operations**

📁 **File:** `4-xxi_array_operations.c`

**Question:**  
Write a C program to perform basic operations on arrays.

**Description:**  
This program demonstrates array input, display, searching, insertion, deletion, and sorting operations.

**How to Solve:**

1. **Input:** Loop to read array elements
2. **Display:** Loop to print elements
3. **Search:** Linear search for element
4. **Insert:** Shift elements and insert at position
5. **Delete:** Shift elements to fill gap
6. **Sort:** Bubble sort or selection sort
7. **Reverse:** Swap elements from ends

**Example:**

```
Array: [5, 2, 8, 1, 9]
Operations:
- Search 8: Found at index 2
- Insert 6 at position 2: [5, 2, 6, 8, 1, 9]
- Delete position 4: [5, 2, 6, 8, 9]
- Sort: [2, 5, 6, 8, 9]
- Reverse: [9, 8, 6, 5, 2]
```

---

### **xxii) Matrix Operations**

📁 **File:** `4-xxii_matrix_operations.c`

**Question:**  
Write a C program to perform operations on matrices (addition, subtraction, multiplication).

**Description:**  
This program handles 2D arrays and performs matrix arithmetic operations with proper validation.

**How to Solve:**

1. **Input matrices:** Nested loop for rows and columns
2. **Addition/Subtraction:** Element-wise operation (requires same dimensions)
3. **Multiplication:**
   - Check if columns of A = rows of B
   - Result[i][j] = Σ(A[i][k] × B[k][j])
4. **Transpose:** Swap rows and columns
5. Display matrices in formatted grid

**Example:**

```
Matrix A (2×2):     Matrix B (2×2):
[1  2]              [5  6]
[3  4]              [7  8]

A + B:              A × B:
[6   8]             [19  22]
[10  12]            [43  50]
```

---

### **xxiii) Matrix Transpose**

📁 **File:** `4-xxiii_matrix_transpose.c`

**Question:**  
Write a C program to find the transpose of a matrix.

**Description:**  
Transpose converts rows to columns and columns to rows. Shows both in-place and new matrix methods.

**How to Solve:**

1. Input matrix (m×n)
2. Create transpose matrix (n×m)
3. For each element at [i][j], place at [j][i] in transpose
4. Display original and transposed matrix
5. For square matrices, show in-place transpose

**Key Concepts:**

- Matrix transpose
- Row-column interchange
- 2D array manipulation
- In-place operations

**Example:**

```
Original (3×2):     Transpose (2×3):
[1  2]              [1  3  5]
[3  4]              [2  4  6]
[5  6]
```

---

### **xxiv) Array Sorting**

📁 **File:** `4-xxiv_array_sorting.c`

**Question:**  
Write a C program implementing various sorting algorithms.

**Description:**  
Demonstrates multiple sorting algorithms with step-by-step visualization and performance comparison.

**How to Solve:**

1. **Bubble Sort:** Compare adjacent, swap if needed, repeat
2. **Selection Sort:** Find minimum, place at beginning
3. **Insertion Sort:** Insert each element at correct position
4. Show passes for each algorithm
5. Count comparisons and swaps

**Key Concepts:**

- Sorting algorithms
- Algorithm complexity
- Comparison and swapping
- Performance analysis

**Example:**

```
Original: [64, 34, 25, 12, 22]

Bubble Sort Steps:
Pass 1: [34, 25, 12, 22, 64]
Pass 2: [25, 12, 22, 34, 64]
Pass 3: [12, 22, 25, 34, 64]
Result: [12, 22, 25, 34, 64]
```

---

### **xxv) String Operations**

📁 **File:** `4-xxv_string_operations.c`

**Question:**  
Write a C program to perform various string operations without using library functions.

**Description:**  
Implements string operations from scratch: length, copy, concatenate, reverse, compare, palindrome check.

**How to Solve:**

1. **Length:** Count characters until '\0'
2. **Copy:** Character by character transfer
3. **Concatenate:** Append second string to first
4. **Reverse:** Swap characters from ends
5. **Compare:** Character by character comparison
6. **Palindrome:** Compare with reversed string

**Key Concepts:**

- String as character array
- Null terminator '\0'
- String manipulation
- Character comparison

**Example:**

```
String: "Hello"
Length: 5
Reverse: "olleH"
Concatenate with "World": "HelloWorld"
Compare with "Hello": Equal
Palindrome check: Not a palindrome
```

---

### **xxvi) String Palindrome**

📁 **File:** `4-xxvi_string_palindrome.c`

**Question:**  
Write a C program to check if a string is a palindrome (case-insensitive).

**Description:**  
Checks if string reads same forwards and backwards, ignoring case and spaces.

**How to Solve:**

1. Convert string to lowercase
2. Remove spaces
3. Compare characters from both ends
4. Move towards center
5. If all match, it's palindrome

**Key Concepts:**

- Case conversion
- String comparison
- Two-pointer technique
- Character manipulation

**Example:**

```
Input: "Madam"
Output: PALINDROME (case-insensitive)

Input: "A man a plan a canal Panama"
Output: PALINDROME (ignoring spaces)

Input: "Hello"
Output: NOT a palindrome
```

---

### **xxvii) Anagram Check**

📁 **File:** `4-xxvii_anagram_check.c`

**Question:**  
Write a C program to check if two strings are anagrams.

**Description:**  
Anagrams are words with same characters in different order. Example: "listen" and "silent".

**How to Solve:**

1. Remove spaces and convert to lowercase
2. Check if lengths are equal
3. **Method 1:** Sort both strings and compare
4. **Method 2:** Count frequency of each character
5. Compare frequency arrays

**Key Concepts:**

- Character frequency
- String sorting
- Comparison logic
- Array manipulation

**Example:**

```
Input: "listen", "silent"
Output: ANAGRAMS
Character count: l-1, i-1, s-1, t-1, e-1, n-1 (both same)

Input: "hello", "world"
Output: NOT anagrams
```

---

### **xxviii) Substring Search**

📁 **File:** `4-xxviii_substring_search.c`

**Question:**  
Write a C program to search for a substring within a string.

**Description:**  
Finds all occurrences of a pattern string within a text string using pattern matching.

**How to Solve:**

1. Scan through main string
2. At each position, try to match pattern
3. Compare character by character
4. If complete match, record position
5. Continue searching for multiple occurrences
6. Show all positions found

**Key Concepts:**

- Pattern matching
- String searching
- Index tracking
- Multiple occurrence handling

**Example:**

```
Text: "the quick brown fox jumps over the lazy dog"
Pattern: "the"
Output:
Found at position 0: "the"
Found at position 31: "the"
Total occurrences: 2
```

---

### **xxix) Word Count in String**

📁 **File:** `4-xxix_word_count.c`

**Question:**  
Write a C program to count words, characters, vowels, and consonants in a string.

**Description:**  
Analyzes a string to provide detailed statistics about its composition.

**How to Solve:**

1. **Words:** Count spaces + 1, or count transitions from space to non-space
2. **Characters:** Count all non-space characters
3. **Vowels:** Check if character is a, e, i, o, u (case-insensitive)
4. **Consonants:** Alphabetic characters that are not vowels
5. **Digits:** Check if character is 0-9
6. **Special characters:** Non-alphanumeric characters

**Key Concepts:**

- Character classification
- String parsing
- Counting logic
- Character types (ctype.h)

**Example:**

```
Input: "Hello World 123!"
Output:
Words: 2
Characters: 15
Vowels: 3 (e, o, o)
Consonants: 7 (H, l, l, W, r, l, d)
Digits: 3 (1, 2, 3)
Spaces: 2
Special chars: 1 (!)
```

---

### **xxx) String Reversal**

📁 **File:** `4-xxx_string_reversal.c`

**Question:**  
Write a C program to reverse a string and reverse words in a string.

**Description:**  
Demonstrates multiple reversal techniques: complete string reversal, word-by-word reversal, and sentence reversal.

**How to Solve:**

1. **Complete reversal:** Swap characters from both ends
2. **Word reversal:**
   - Reverse entire string
   - Reverse each word individually
3. **Sentence reversal:** Extract words and arrange in reverse order
4. Handle multiple spaces

**Key Concepts:**

- String manipulation
- Two-pointer technique
- Word extraction
- Multiple reversal methods

**Example:**

```
Input: "Hello World"

Complete reversal: "dlroW olleH"
Word-by-word reversal: "olleH dlroW"
Sentence reversal: "World Hello"
```

---

## Section 5: Functions, Pointers & Structures

### **xxxi) nCr Combination**

📁 **File:** `5-xxxi_nCr_combination.c`

**Question:**  
Write a C program to calculate nCr (combination) using functions.

**Description:**  
Calculates combinations using the formula: nCr = n! / (r! × (n-r)!)
Shows both standard and optimized methods.

**How to Solve:**

1. Create factorial() function
2. **Method 1:** Use formula directly with factorials
3. **Method 2:** Optimize by canceling common terms
4. Validate n ≥ r ≥ 0
5. Show calculation steps

**Key Concepts:**

- Function creation
- Factorial calculation
- Mathematical optimization
- Parameter passing

**Example:**

```
Input: n=5, r=2
Output: 5C2 = 10
Calculation: 5! / (2! × 3!) = 120 / (2 × 6) = 10
Combinations: (1,2), (1,3), (1,4), (1,5), (2,3), (2,4), (2,5), (3,4), (3,5), (4,5)
```

---

### **xxxii) Exponential Series**

📁 **File:** `5-xxxii_exponential_series.c`

**Question:**  
Write a C program to calculate e^x using Taylor series expansion.

**Description:**  
Calculates exponential function using series: e^x = 1 + x/1! + x²/2! + x³/3! + ...

**How to Solve:**

1. Initialize sum = 1, term = 1
2. Loop for n terms:
   - Calculate next term = (previous term × x) / i
   - Add to sum
   - Display each term
3. Compare with math.h exp() function
4. Show error percentage

**Key Concepts:**

- Series expansion
- Term calculation
- Accumulation
- Accuracy analysis

**Example:**

```
Input: x=2, terms=10
Output:
e^2 = 1 + 2/1! + 4/2! + 8/6! + ...
    = 1 + 2 + 2 + 1.333 + 0.667 + ...
    = 7.389
Actual (math.h): 7.389
Error: 0.001%
```

---

### **xxxiii) Array Min/Max Swap**

📁 **File:** `5-xxxiii_array_min_max_swap.c`

**Question:**  
Write a C program using functions to find and swap largest and smallest elements in an array.

**Description:**  
Uses separate functions to find minimum and maximum elements, then swaps their positions.

**How to Solve:**

1. **findMin() function:** Return index of minimum element
2. **findMax() function:** Return index of maximum element
3. **swap() function:** Exchange elements at two indices
4. Display array before and after swap
5. Show indices and values

**Key Concepts:**

- Function with array parameters
- Index tracking
- Swapping algorithm
- Modular programming

**Example:**

```
Original array: [5, 2, 8, 1, 9, 3]
Minimum: 1 at index 3
Maximum: 9 at index 4

After swap: [5, 2, 8, 9, 1, 3]
```

---

### **xxxiv) Factorial Recursion**

📁 **File:** `5-xxxiv_factorial_recursion.c`

**Question:**  
Write a C program to calculate factorial using recursion with visualization.

**Description:**  
Demonstrates recursive factorial calculation with detailed call stack visualization.

**How to Solve:**

1. **Base case:** if n == 0 or n == 1, return 1
2. **Recursive case:** return n × factorial(n-1)
3. Visualize recursion with indentation
4. Show call stack and return values
5. Compare with iterative method

**Key Concepts:**

- Recursion
- Base case and recursive case
- Call stack
- Recursion tree visualization

**Example:**

```
Input: 5
Recursion trace:
factorial(5)
  → 5 × factorial(4)
    → 4 × factorial(3)
      → 3 × factorial(2)
        → 2 × factorial(1)
          → 1 (base case)
        ← 2
      ← 6
    ← 24
  ← 120
Result: 120
```

---

### **xxxv) Call by Value vs Reference**

📁 **File:** `5-xxxv_call_by_value_reference.c`

**Question:**  
Write a C program to demonstrate call by value and call by reference.

**Description:**  
Shows the difference between passing values and addresses to functions with three examples: swap, increment, and array modification.

**How to Solve:**

1. **Call by value:**
   - Pass variable value
   - Changes don't affect original
2. **Call by reference:**
   - Pass variable address using &
   - Use pointer parameter (\*)
   - Changes affect original variable
3. Show side-by-side comparison

**Key Concepts:**

- Function parameters
- Pointers
- Address vs value
- Parameter passing mechanisms

**Example:**

```
Call by Value (swap):
Before: a=5, b=10
In function: a=10, b=5
After: a=5, b=10 (unchanged)

Call by Reference (swap):
Before: a=5, b=10
In function: *x=10, *y=5
After: a=10, b=5 (changed!)
```

---

### **xxxvi) Array Using Pointers**

📁 **File:** `5-xxxvi_array_using_pointer.c`

**Question:**  
Write a C program to access array elements using pointers.

**Description:**  
Demonstrates three methods of accessing arrays with pointers: \*(ptr+i), ptr++, and ptr[i].

**How to Solve:**

1. **Method 1:** \*(ptr + i) - pointer arithmetic
2. **Method 2:** ptr++ - increment pointer
3. **Method 3:** ptr[i] - array notation with pointer
4. Show memory addresses
5. Demonstrate pointer arithmetic
6. Calculate sum and average using pointers

**Key Concepts:**

- Pointer arithmetic
- Array-pointer relationship
- Dereferencing
- Memory addresses

**Example:**

```
Array: [10, 20, 30, 40, 50]

Method 1 - *(ptr+i):
Address: 0x1000, Value: 10
Address: 0x1004, Value: 20
Address: 0x1008, Value: 30
...

Pointer arithmetic:
ptr = 0x1000
ptr+1 = 0x1004 (moved 4 bytes)
*(ptr+2) = 30
```

---

### **xxxvii) Text Analysis with Pointers**

📁 **File:** `5-xxxvii_text_analysis_pointer.c`

**Question:**  
Write a C program to analyze multi-line text using character pointers.

**Description:**  
Reads multi-line text until "END" and analyzes it using pointer operations to count characters, words, lines, and find longest word.

**How to Solve:**

1. Read lines until "END"
2. Use character pointer to traverse text
3. Count:
   - Characters (including spaces)
   - Words (space-separated)
   - Lines (newline count)
4. Find longest word
5. Character distribution (frequency)

**Key Concepts:**

- Character pointers
- String traversal
- Multi-line input
- Text parsing

**Example:**

```
Input:
Hello World
This is a test
END

Output:
Characters: 24
Words: 6
Lines: 2
Longest word: "Hello" (5 chars)
Character distribution:
a: 1, d: 1, e: 2, H: 1, i: 2, l: 3, ...
```

---

### **xxxviii) Time Operations with Structures**

📁 **File:** `5-xxxviii_time_operations.c`

**Question:**  
Write a C program to perform arithmetic operations on time using structures.

**Description:**  
Defines a Time structure with hours, minutes, seconds and performs addition and subtraction with carry/borrow handling.

**How to Solve:**

1. Define Time structure with h, m, s
2. **Addition:**
   - Add seconds, if ≥60, carry to minutes
   - Add minutes, if ≥60, carry to hours
   - Add hours, if ≥24, wrap around
3. **Subtraction:**
   - Subtract seconds, if <0, borrow from minutes
   - Subtract minutes, if <0, borrow from hours
   - Handle negative results
4. Display in 12-hour and 24-hour formats

**Key Concepts:**

- Structure definition
- Structure operations
- Carry and borrow logic
- Time normalization

**Example:**

```
Time 1: 10:45:30
Time 2: 02:35:45

Addition:
10:45:30 + 02:35:45 = 13:21:15
Steps: 30+45=75s → 1m15s
       45+35+1=81m → 1h21m
       10+2+1=13h

Subtraction:
10:45:30 - 02:35:45 = 08:09:45
```

---

### **xxxix) Structure Pointers**

📁 **File:** `5-xxxix_structure_pointer.c`

**Question:**  
Write a C program to demonstrate structure pointers and member access.

**Description:**  
Shows how to access structure members using pointers with three methods: ptr->, (\*ptr)., and struct. Also demonstrates dynamic memory allocation.

**How to Solve:**

1. Define Student structure
2. Create structure variable and pointer
3. **Access methods:**
   - ptr->member (arrow operator)
   - (\*ptr).member (dereference then dot)
   - struct.member (direct access)
4. Show memory layout
5. Demonstrate malloc/free

**Key Concepts:**

- Structure pointers
- Arrow operator (->)
- Dynamic memory allocation
- Memory layout

**Example:**

```
Student structure:
Roll: 101
Name: "Alice"
Marks: [85, 90, 88]

Access methods:
ptr->roll = 101
(*ptr).name = "Alice"
student.marks[0] = 85

Memory layout:
Address 0x1000: roll (4 bytes)
Address 0x1004: name (50 bytes)
Address 0x1036: age (4 bytes)
...
```

---

## Section 6: File Handling

### **xl) File Handling Modes**

📁 **File:** `6-xl_file_handling_modes.c`

**Question:**  
Write a C program for handling unformatted and formatted files in different operational modes.

**Description:**  
Comprehensive demonstration of file I/O operations including formatted (fprintf/fscanf), unformatted (fputc/fgetc, fputs/fgets), binary (fwrite/fread), and all file opening modes.

**How to Solve:**

1. **Formatted I/O:**
   - fprintf() - write formatted data
   - fscanf() - read formatted data
2. **Unformatted Character I/O:**
   - fputc() - write character
   - fgetc() - read character
3. **Unformatted String I/O:**
   - fputs() - write string
   - fgets() - read string
4. **Binary I/O:**
   - fwrite() - write binary data
   - fread() - read binary data
5. **File Modes:**
   - r, w, a (text)
   - r+, w+, a+ (read/write)
   - rb, wb, ab (binary)

**Key Concepts:**

- File pointers
- File opening modes
- Formatted vs unformatted I/O
- Binary file operations
- Error handling

**Example:**

```
Formatted write (fprintf):
fprintf(fp, "Roll: %d, Name: %s, Marks: %.2f", 101, "Alice", 85.5);

Unformatted write (fputs):
fputs("Hello World\n", fp);

Binary write (fwrite):
fwrite(&student, sizeof(Student), 1, fp);

File modes:
"r"  - Read (file must exist)
"w"  - Write (creates/overwrites)
"a"  - Append (creates/appends)
"r+" - Read/Write (file must exist)
```

---

### **xli) Count Characters and Lines**

📁 **File:** `6-xli_count_chars_lines.c`

**Question:**  
Write a C program to count the number of characters and lines in a file.

**Description:**  
Reads a file and provides detailed statistics including total characters, lines, words, alphabets, digits, spaces, and special characters with percentage distribution.

**How to Solve:**

1. Open file in read mode
2. Read character by character using fgetc()
3. Count:
   - Total characters (including all)
   - Lines (count '\n')
   - Words (transitions from space to non-space)
   - Alphabets (isalpha())
   - Digits (isdigit())
   - Spaces (space and tab)
   - Special characters
4. Calculate percentages and averages
5. Display file content with line numbers

**Key Concepts:**

- Character-by-character reading
- Character classification
- Statistical analysis
- File traversal

**Example:**

```
File: sample.txt
Content:
1: Hello World!
2: This is line 2.
3: Numbers: 123

Statistics:
Total characters: 45
Lines: 3
Words: 7
Alphabets: 28 (62.2%)
Digits: 3 (6.7%)
Spaces: 6 (13.3%)
Special chars: 5 (11.1%)
Average chars per line: 15.0
```

---

### **xlii) File Copy Methods**

📁 **File:** `6-xlii_file_copy_methods.c`

**Question:**  
Write a C program to copy one file into another by:
a) Copying one character at a time
b) Copying multiple characters simultaneously (using fgets/fputs)

**Description:**  
Demonstrates two file copying methods with performance comparison and verification.

**How to Solve:**

1. **Method 1 - Character by character:**
   - Use fgetc() to read one character
   - Use fputc() to write one character
   - Loop until EOF
   - Count characters copied
2. **Method 2 - Line by line:**
   - Use fgets() to read a line (buffer)
   - Use fputs() to write the line
   - Loop until NULL
   - Count lines copied
3. Measure time for each method
4. Verify copy by comparing files
5. Display file sizes

**Key Concepts:**

- File copying
- fgetc/fputc vs fgets/fputs
- Performance comparison
- File verification
- Time measurement

**Example:**

```
Source: source.txt (542 bytes)

Method 1 (Character-by-character):
Characters copied: 542
Time taken: 0.000234 seconds

Method 2 (Line-by-line):
Lines copied: 14
Characters copied: 542
Time taken: 0.000156 seconds

Verification: ✓ Files are identical

Comparison:
Method 1: Works with any file, slower
Method 2: Faster for text files, efficient
```

---

### **xliii) Student Records File**

📁 **File:** `6-xliii_student_records_file.c`

**Question:**  
Write a C program to write records of students to a file using array of structures and display them accordingly.

**Description:**  
Complete student record management system using structures and files. Supports both binary and text file formats with comprehensive display and analysis features.

**How to Solve:**

1. Define Student structure:
   - Roll number, name, age, course
   - Marks array (3 subjects)
   - Total, percentage, grade
2. **Write to binary file:**
   - fwrite(students, sizeof(Student), count, fp)
3. **Write to text file:**
   - fprintf() for each field
4. **Read from binary file:**
   - fread(students, sizeof(Student), count, fp)
5. Display in formatted table
6. Calculate statistics
7. Search and sort operations

**Key Concepts:**

- Array of structures
- Binary file I/O
- Text file I/O
- Structure file operations
- Data persistence

**Example:**

```
Creating 5 student records...

Writing to files:
✓ students.dat (binary) - 500 bytes
✓ students.txt (text) - 850 bytes

Reading from file:
┌─────┬──────┬──────────────┬─────┬───────┬───────┬───────┬────────┬──────────┬───────┐
│ No. │ Roll │ Name         │ Age │ Sub-1 │ Sub-2 │ Sub-3 │ Total  │ Percent  │ Grade │
├─────┼──────┼──────────────┼─────┼───────┼───────┼───────┼────────┼──────────┼───────┤
│ 1   │ 101  │ Alice        │ 20  │  85.0 │  90.0 │  88.0 │  263.0 │  87.67%  │   B   │
│ 2   │ 102  │ Bob Smith    │ 21  │  92.0 │  95.0 │  93.0 │  280.0 │  93.33%  │   A   │
└─────┴──────┴──────────────┴─────┴───────┴───────┴───────┴────────┴──────────┴───────┘

Statistics:
Average: 85.5%
Highest: 93.33% (Bob Smith)
Pass rate: 100%
```

---

### **xliv) Student Database Menu System**

📁 **File:** `6-xliv_student_database_menu.c`

**Question:**  
Write a text menu-driven program to append a record, edit a particular record, display a predefined record, and delete a particular record from a previously created student file.

**Description:**  
Complete Student Database Management System with interactive menu interface supporting all CRUD operations (Create, Read, Update, Delete) with persistent file storage.

**How to Solve:**

1. **Menu Interface:**
   - Display menu with 8 options
   - Use switch-case for selection
   - Loop until exit
2. **Add Record:**
   - Input new student data
   - Check for duplicate roll number
   - Append to array and save to file
3. **Display Records:**
   - Load all records from file
   - Display in formatted table
4. **Search Record:**
   - Search by roll number
   - Display if found
5. **Edit Record:**
   - Find by roll number
   - Allow selective field updates
   - Save changes to file
6. **Delete Record:**
   - Find by roll number
   - Confirm deletion
   - Shift remaining records
   - Save to file
7. **Statistics:**
   - Calculate average, highest, lowest
   - Grade distribution
   - Pass/fail percentage
8. **Sort Records:**
   - By roll number, percentage, or name
   - Display sorted list

**Key Concepts:**

- Menu-driven programming
- CRUD operations
- File persistence
- Data validation
- Interactive user interface
- Search and sort
- Statistical analysis

**Example:**

```
╔════════════════════════════════════════════╗
║   STUDENT DATABASE MANAGEMENT SYSTEM       ║
╚════════════════════════════════════════════╝

✓ Loaded 3 records from database.

╔════════════════════════════════════════════╗
║              MAIN MENU                     ║
╠════════════════════════════════════════════╣
║  1. Add New Student Record                 ║
║  2. Display All Records                    ║
║  3. Search Record (by Roll Number)         ║
║  4. Edit Record                            ║
║  5. Delete Record                          ║
║  6. Display Statistics                     ║
║  7. Sort Records                           ║
║  8. Exit                                   ║
╚════════════════════════════════════════════╝

Total Records: 3

Enter your choice: 1

╔════════════════════════════════════════════╗
║         ADD NEW STUDENT RECORD             ║
╚════════════════════════════════════════════╝

Enter Roll Number: 104
Enter Name: David Brown
Enter Age: 22
Enter Course: Mathematics
Enter marks for 3 subjects:
  Subject 1: 78
  Subject 2: 82
  Subject 3: 85

✓ Student record added successfully!
  Roll Number: 104
  Name: David Brown
  Percentage: 81.67%
  Grade: B

[Selecting option 6 - Statistics]

╔════════════════════════════════════════════╗
║          CLASS STATISTICS                  ║
╚════════════════════════════════════════════╝

Total Students: 4

--- Performance Summary ---
Average Percentage: 84.50%
Highest Score: 93.33% - Bob Smith (Roll: 102)
Lowest Score: 78.33% - Carol Williams (Roll: 103)

--- Grade Distribution ---
  A (90-100):  1 students (25.0%)
  B (80-89):   2 students (50.0%)
  C (70-79):   1 students (25.0%)
  D (60-69):   0 students (0.0%)
  E (50-59):   0 students (0.0%)
  F (0-49):    0 students (0.0%)

--- Pass/Fail Statistics ---
  Passed: 4 students (100.0%)
  Failed: 0 students (0.0%)

[Selecting option 4 - Edit Record]

╔════════════════════════════════════════════╗
║           EDIT STUDENT RECORD              ║
╚════════════════════════════════════════════╝

Enter Roll Number to edit: 103

--- Current Details ---
Roll Number: 103
Name: Carol Williams
Age: 19
Course: Physics
Marks: 78.0, 82.0, 75.0

--- Enter New Details ---
New Name (press Enter to keep 'Carol Williams'):
New Age (current: 19, 0 to skip): 20
New Course (press Enter to keep 'Physics'): Computer Science
Update marks? (y/n): y
Enter new marks for 3 subjects:
  Subject 1: 85
  Subject 2: 88
  Subject 3: 82

✓ Record updated successfully!

[Selecting option 5 - Delete Record]

╔════════════════════════════════════════════╗
║          DELETE STUDENT RECORD             ║
╚════════════════════════════════════════════╝

Enter Roll Number to delete: 105

--- Record to be Deleted ---
Roll Number: 105
Name: Emma Davis
Course: Chemistry

Are you sure you want to delete this record? (y/n): y

✓ Record deleted successfully!
  Total records now: 3

[Selecting option 7 - Sort Records]

╔════════════════════════════════════════════╗
║            SORT RECORDS                    ║
╚════════════════════════════════════════════╝

Sort by:
1. Roll Number (ascending)
2. Percentage (descending)
3. Name (alphabetical)

Enter choice: 2

✓ Records sorted by Percentage (highest first)!

Sorted records:
┌─────┬──────┬──────────────────────┬─────┬────────────────┬───────┬───────┬───────┬────────┬──────────┬───────┐
│ No. │ Roll │ Name                 │ Age │ Course         │ Sub-1 │ Sub-2 │ Sub-3 │ Total  │ Percent  │ Grade │
├─────┼──────┼──────────────────────┼─────┼────────────────┼───────┼───────┼───────┼────────┼──────────┼───────┤
│ 1   │ 102  │ Bob Smith            │ 21  │ Electronics    │  92.0 │  95.0 │  93.0 │  280.0 │  93.33%  │   A   │
│ 2   │ 101  │ Alice Johnson        │ 20  │ Computer Sci.  │  85.0 │  90.0 │  88.0 │  263.0 │  87.67%  │   B   │
│ 3   │ 103  │ Carol Williams       │ 20  │ Computer Sci.  │  85.0 │  88.0 │  82.0 │  255.0 │  85.00%  │   B   │
└─────┴──────┴──────────────────────┴─────┴────────────────┴───────┴───────┴───────┴────────┴──────────┴───────┘

[Selecting option 8 - Exit]

╔════════════════════════════════════════════╗
║  Thank you for using Student Database!     ║
║  All changes saved to file.                ║
╚════════════════════════════════════════════╝
```

---

## 📊 Summary Statistics

### Programs by Section

| Section   | Topic                            | Programs | Files        |
| --------- | -------------------------------- | -------- | ------------ |
| 1         | Format Specifiers                | 4        | i - iv       |
| 2         | Control Structures               | 6        | v - x        |
| 3         | Loops & Patterns                 | 9        | xi - xix     |
| 4         | Arrays, Matrices & Strings       | 10       | xxi - xxx    |
| 5         | Functions, Pointers & Structures | 9        | xxxi - xxxix |
| 6         | File Handling                    | 5        | xl - xliv    |
| **Total** |                                  | **43**   | **i - xliv** |

### Concepts Covered

- ✅ Data types and format specifiers
- ✅ Input/Output operations
- ✅ Conditional statements (if-else, switch)
- ✅ Loops (for, while, do-while)
- ✅ Pattern printing
- ✅ Arrays (1D and 2D)
- ✅ Strings and string manipulation
- ✅ Functions and recursion
- ✅ Pointers and pointer arithmetic
- ✅ Structures and unions
- ✅ File handling (text and binary)
- ✅ Searching and sorting algorithms
- ✅ Mathematical operations
- ✅ Memory management

---

## 🚀 How to Use This Repository

### Compilation

Each program can be compiled using GCC:

```bash
gcc filename.c -o output
./output
```

For programs using math.h:

```bash
gcc filename.c -o output -lm
./output
```

### Program Naming Convention

Format: `[section]-[roman_numeral]_description.c`

Examples:

- `1-i_basic_io.c` - Section 1, Program i
- `3-xv_number_patterns.c` - Section 3, Program xv
- `6-xliv_student_database_menu.c` - Section 6, Program xliv

### Running Programs

1. Navigate to the directory containing the program
2. Compile the program
3. Run the executable
4. Follow the on-screen prompts

---

## 💡 Learning Path

### Beginner Level (Sections 1-2)

Start with basic I/O, data types, and simple control structures. Master:

- printf() and scanf()
- if-else statements
- Basic operators
- Simple calculations

### Intermediate Level (Sections 3-4)

Progress to loops, arrays, and strings. Focus on:

- Pattern printing
- Array manipulation
- String operations
- Algorithm implementation

### Advanced Level (Sections 5-6)

Move to functions, pointers, and file handling. Learn:

- Function design
- Pointer operations
- Structure usage
- File I/O
- Database management

---

## 🎯 Key Features

✨ **Comprehensive Coverage**: All fundamental C programming concepts  
📝 **Well Documented**: Each program includes detailed comments  
🔍 **Multiple Examples**: 2-3 input/output examples per program  
🎨 **Formatted Output**: Professional display with tables and boxes  
🛡️ **Error Handling**: Robust input validation and error checking  
📚 **Educational**: Step-by-step solution approaches included  
💻 **Production Ready**: Clean, compilable code following best practices

---

## 📖 Additional Resources

### Header Files Used

- `stdio.h` - Standard Input/Output
- `stdlib.h` - Standard Library
- `string.h` - String Operations
- `ctype.h` - Character Type Functions
- `math.h` - Mathematical Functions
- `limits.h` - Implementation-defined Limits
- `time.h` - Time and Date Functions

### Common Patterns

- Input validation
- Menu-driven interfaces
- Table formatting
- Error handling
- File operations
- Memory management

---

## 🤝 Contributing

This is a complete educational resource. Each program is:

- Fully functional
- Well-commented
- Tested
- Documented

---

## 📜 License

Educational use - Free to use for learning purposes.

---

## ✅ Completion Status

All **43 programs** are complete and ready to use!

**Section 1**: ✅ Complete (4/4)  
**Section 2**: ✅ Complete (6/6)  
**Section 3**: ✅ Complete (9/9)  
**Section 4**: ✅ Complete (10/10)  
**Section 5**: ✅ Complete (9/9)  
**Section 6**: ✅ Complete (5/5)

---

**Happy Coding! 🚀**

---

_Last Updated: November 6, 2025_  
_Total Programs: 43_  
_Total Sections: 6_  
_Coverage: Complete C Programming Fundamentals_
