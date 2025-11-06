/*
 * QUESTION xxxviii:
 * Write a C program to read, display, add and subtract two times
 * defined using hour, minutes and values of seconds.
 *
 * PROGRAM DESCRIPTION:
 * This program uses structures to represent time (hours:minutes:seconds)
 * and performs arithmetic operations on time values.
 *
 * Time structure contains:
 * - hours (0-23 for 24-hour format, or 1-12 for 12-hour format)
 * - minutes (0-59)
 * - seconds (0-59)
 *
 * Operations:
 * 1. Read time from user with validation
 * 2. Display time in different formats
 * 3. Add two times (handling carry-over)
 * 4. Subtract two times (handling borrow)
 * 5. Convert between formats (12-hour and 24-hour)
 *
 * HOW TO SOLVE:
 * 1. Define a structure for time with hour, minute, second
 * 2. Create functions to:
 *    - Read and validate time input
 *    - Display time in various formats
 *    - Add two times (handle seconds->minutes->hours overflow)
 *    - Subtract two times (handle borrow operations)
 *    - Normalize time (ensure valid ranges)
 * 3. Handle edge cases (midnight, noon, negative results)
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent time
typedef struct {
   int hours;
   int minutes;
   int seconds;
} Time;

// Function to read time from user
Time readTime(const char *label) {
   Time t;

   printf("%s\n", label);

   do {
      printf("  Enter hours (0-23): ");
      scanf("%d", &t.hours);
      if (t.hours < 0 || t.hours > 23) {
         printf("  Invalid! Hours must be 0-23.\n");
      }
   } while (t.hours < 0 || t.hours > 23);

   do {
      printf("  Enter minutes (0-59): ");
      scanf("%d", &t.minutes);
      if (t.minutes < 0 || t.minutes > 59) {
         printf("  Invalid! Minutes must be 0-59.\n");
      }
   } while (t.minutes < 0 || t.minutes > 59);

   do {
      printf("  Enter seconds (0-59): ");
      scanf("%d", &t.seconds);
      if (t.seconds < 0 || t.seconds > 59) {
         printf("  Invalid! Seconds must be 0-59.\n");
      }
   } while (t.seconds < 0 || t.seconds > 59);

   return t;
}

// Function to display time in 24-hour format
void displayTime24(Time t) {
   printf("%02d:%02d:%02d", t.hours, t.minutes, t.seconds);
}

// Function to display time in 12-hour format
void displayTime12(Time t) {
   int hour12 = t.hours % 12;
   if (hour12 == 0)
      hour12 = 12;

   printf("%02d:%02d:%02d %s", hour12, t.minutes, t.seconds,
          t.hours < 12 ? "AM" : "PM");
}

// Function to normalize time (handle overflows and underflows)
Time normalizeTime(Time t) {
   // Handle negative seconds
   while (t.seconds < 0) {
      t.seconds += 60;
      t.minutes--;
   }

   // Handle seconds overflow
   while (t.seconds >= 60) {
      t.seconds -= 60;
      t.minutes++;
   }

   // Handle negative minutes
   while (t.minutes < 0) {
      t.minutes += 60;
      t.hours--;
   }

   // Handle minutes overflow
   while (t.minutes >= 60) {
      t.minutes -= 60;
      t.hours++;
   }

   // Handle negative hours
   while (t.hours < 0) {
      t.hours += 24;
   }

   // Handle hours overflow
   while (t.hours >= 24) {
      t.hours -= 24;
   }

   return t;
}

// Function to add two times
Time addTime(Time t1, Time t2) {
   Time result;

   result.seconds = t1.seconds + t2.seconds;
   result.minutes = t1.minutes + t2.minutes;
   result.hours = t1.hours + t2.hours;

   // Normalize the result
   result = normalizeTime(result);

   return result;
}

// Function to subtract two times (t1 - t2)
Time subtractTime(Time t1, Time t2) {
   Time result;

   result.seconds = t1.seconds - t2.seconds;
   result.minutes = t1.minutes - t2.minutes;
   result.hours = t1.hours - t2.hours;

   // Normalize the result
   result = normalizeTime(result);

   return result;
}

// Function to convert time to total seconds
int timeToSeconds(Time t) {
   return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

// Function to convert seconds to time
Time secondsToTime(int totalSeconds) {
   Time t;

   // Handle negative seconds
   while (totalSeconds < 0) {
      totalSeconds += 86400; // Add 24 hours in seconds
   }

   totalSeconds = totalSeconds % 86400; // Wrap around 24 hours

   t.hours = totalSeconds / 3600;
   totalSeconds %= 3600;
   t.minutes = totalSeconds / 60;
   t.seconds = totalSeconds % 60;

   return t;
}

// Function to display detailed addition
void displayAddition(Time t1, Time t2, Time result) {
   printf("Addition Details:\n");
   printf("  Time 1:     ");
   displayTime24(t1);
   printf("\n");

   printf("  Time 2:   + ");
   displayTime24(t2);
   printf("\n");

   printf("  %s\n", "----------");

   printf("  Result:     ");
   displayTime24(result);
   printf("\n\n");

   printf("Step by step:\n");
   printf("  Seconds: %2d + %2d = %2d", t1.seconds, t2.seconds,
          t1.seconds + t2.seconds);
   if (t1.seconds + t2.seconds >= 60) {
      printf(" → %2d seconds, carry 1 minute\n", result.seconds);
   } else {
      printf(" → %2d seconds\n", result.seconds);
   }

   printf("  Minutes: %2d + %2d", t1.minutes, t2.minutes);
   if (t1.seconds + t2.seconds >= 60) {
      printf(" + 1 (carry)");
   }
   printf(" = %2d", t1.minutes + t2.minutes + (t1.seconds + t2.seconds >= 60 ? 1 : 0));
   if (t1.minutes + t2.minutes + (t1.seconds + t2.seconds >= 60 ? 1 : 0) >= 60) {
      printf(" → %2d minutes, carry 1 hour\n", result.minutes);
   } else {
      printf(" → %2d minutes\n", result.minutes);
   }

   printf("  Hours:   %2d + %2d", t1.hours, t2.hours);
   int minCarry = (t1.minutes + t2.minutes + (t1.seconds + t2.seconds >= 60 ? 1 : 0)) >= 60 ? 1 : 0;
   if (minCarry) {
      printf(" + 1 (carry)");
   }
   printf(" = %2d → %2d hours\n", t1.hours + t2.hours + minCarry, result.hours);
}

// Function to display detailed subtraction
void displaySubtraction(Time t1, Time t2, Time result) {
   printf("Subtraction Details:\n");
   printf("  Time 1:     ");
   displayTime24(t1);
   printf("\n");

   printf("  Time 2:   - ");
   displayTime24(t2);
   printf("\n");

   printf("  %s\n", "----------");

   printf("  Result:     ");
   displayTime24(result);
   printf("\n\n");

   printf("Step by step:\n");
   printf("  Seconds: %2d - %2d", t1.seconds, t2.seconds);
   if (t1.seconds < t2.seconds) {
      printf(" → borrow 1 minute → %2d - %2d = %2d seconds\n",
             t1.seconds + 60, t2.seconds, result.seconds);
   } else {
      printf(" = %2d seconds\n", result.seconds);
   }

   int secBorrow = (t1.seconds < t2.seconds) ? 1 : 0;
   printf("  Minutes: %2d - %2d", t1.minutes, t2.minutes);
   if (secBorrow) {
      printf(" - 1 (borrow)");
   }
   if (t1.minutes - secBorrow < t2.minutes) {
      printf(" → borrow 1 hour → %2d - %2d = %2d minutes\n",
             t1.minutes - secBorrow + 60, t2.minutes, result.minutes);
   } else {
      printf(" = %2d minutes\n", result.minutes);
   }
}

int main() {
   Time time1, time2, sum, difference;

   printf("========================================\n");
   printf("  Time Addition and Subtraction\n");
   printf("========================================\n\n");

   printf("This program performs arithmetic operations\n");
   printf("on time values (HH:MM:SS format)\n\n");

   // Read first time
   time1 = readTime("Enter First Time:");

   printf("\n");

   // Read second time
   time2 = readTime("Enter Second Time:");

   printf("\n========================================\n");
   printf("  Input Times\n");
   printf("========================================\n\n");

   printf("Time 1 (24-hour): ");
   displayTime24(time1);
   printf("\n");
   printf("Time 1 (12-hour): ");
   displayTime12(time1);
   printf("\n\n");

   printf("Time 2 (24-hour): ");
   displayTime24(time2);
   printf("\n");
   printf("Time 2 (12-hour): ");
   displayTime12(time2);
   printf("\n");

   // Addition
   printf("\n========================================\n");
   printf("  ADDITION: Time1 + Time2\n");
   printf("========================================\n\n");

   sum = addTime(time1, time2);
   displayAddition(time1, time2, sum);

   printf("Result in different formats:\n");
   printf("  24-hour: ");
   displayTime24(sum);
   printf("\n");
   printf("  12-hour: ");
   displayTime12(sum);
   printf("\n");

   // Subtraction
   printf("\n========================================\n");
   printf("  SUBTRACTION: Time1 - Time2\n");
   printf("========================================\n\n");

   difference = subtractTime(time1, time2);
   displaySubtraction(time1, time2, difference);

   printf("Result in different formats:\n");
   printf("  24-hour: ");
   displayTime24(difference);
   printf("\n");
   printf("  12-hour: ");
   displayTime12(difference);
   printf("\n");

   // Additional information
   printf("\n========================================\n");
   printf("  Time Difference Analysis\n");
   printf("========================================\n\n");

   int seconds1 = timeToSeconds(time1);
   int seconds2 = timeToSeconds(time2);
   int diffSeconds = abs(seconds1 - seconds2);

   printf("Time 1 in seconds: %d seconds\n", seconds1);
   printf("Time 2 in seconds: %d seconds\n", seconds2);
   printf("Absolute difference: %d seconds\n", diffSeconds);
   printf("                   = %d hours, %d minutes, %d seconds\n",
          diffSeconds / 3600, (diffSeconds % 3600) / 60, diffSeconds % 60);

   printf("\n========================================\n");
   printf("  Summary\n");
   printf("========================================\n");
   printf("Time 1:       ");
   displayTime24(time1);
   printf("\n");
   printf("Time 2:       ");
   displayTime24(time2);
   printf("\n");
   printf("Sum:          ");
   displayTime24(sum);
   printf("\n");
   printf("Difference:   ");
   displayTime24(difference);
   printf("\n");
   printf("========================================\n");

   return 0;
}

/*
 * SAMPLE INPUT/OUTPUT:
 *
 * Example 1:
 * Input:
 *   Time 1: 10:30:45
 *   Time 2: 05:25:30
 * Output:
 * ========================================
 *   Time Addition and Subtraction
 * ========================================
 *
 * This program performs arithmetic operations
 * on time values (HH:MM:SS format)
 *
 * Enter First Time:
 *   Enter hours (0-23): 10
 *   Enter minutes (0-59): 30
 *   Enter seconds (0-59): 45
 *
 * Enter Second Time:
 *   Enter hours (0-23): 5
 *   Enter minutes (0-59): 25
 *   Enter seconds (0-59): 30
 *
 * ========================================
 *   Input Times
 * ========================================
 *
 * Time 1 (24-hour): 10:30:45
 * Time 1 (12-hour): 10:30:45 AM
 *
 * Time 2 (24-hour): 05:25:30
 * Time 2 (12-hour): 05:25:30 AM
 *
 * ========================================
 *   ADDITION: Time1 + Time2
 * ========================================
 *
 * Addition Details:
 *   Time 1:     10:30:45
 *   Time 2:   + 05:25:30
 *   ----------
 *   Result:     15:56:15
 *
 * Step by step:
 *   Seconds: 45 + 30 = 75 → 15 seconds, carry 1 minute
 *   Minutes: 30 + 25 + 1 (carry) = 56 → 56 minutes
 *   Hours:   10 +  5 = 15 → 15 hours
 *
 * Result in different formats:
 *   24-hour: 15:56:15
 *   12-hour: 03:56:15 PM
 *
 * ========================================
 *   SUBTRACTION: Time1 - Time2
 * ========================================
 *
 * Subtraction Details:
 *   Time 1:     10:30:45
 *   Time 2:   - 05:25:30
 *   ----------
 *   Result:     05:05:15
 *
 * Step by step:
 *   Seconds: 45 - 30 = 15 seconds
 *   Minutes: 30 - 25 = 5 minutes
 *
 * Result in different formats:
 *   24-hour: 05:05:15
 *   12-hour: 05:05:15 AM
 *
 * ========================================
 *   Time Difference Analysis
 * ========================================
 *
 * Time 1 in seconds: 37845 seconds
 * Time 2 in seconds: 19530 seconds
 * Absolute difference: 18315 seconds
 *                    = 5 hours, 5 minutes, 15 seconds
 *
 * ========================================
 *   Summary
 * ========================================
 * Time 1:       10:30:45
 * Time 2:       05:25:30
 * Sum:          15:56:15
 * Difference:   05:05:15
 * ========================================
 *
 * Example 2:
 * Input:
 *   Time 1: 23:50:40
 *   Time 2: 00:25:35
 * Output:
 * ========================================
 *   Time Addition and Subtraction
 * ========================================
 *
 * This program performs arithmetic operations
 * on time values (HH:MM:SS format)
 *
 * Enter First Time:
 *   Enter hours (0-23): 23
 *   Enter minutes (0-59): 50
 *   Enter seconds (0-59): 40
 *
 * Enter Second Time:
 *   Enter hours (0-23): 0
 *   Enter minutes (0-59): 25
 *   Enter seconds (0-59): 35
 *
 * ========================================
 *   Input Times
 * ========================================
 *
 * Time 1 (24-hour): 23:50:40
 * Time 1 (12-hour): 11:50:40 PM
 *
 * Time 2 (24-hour): 00:25:35
 * Time 2 (12-hour): 12:25:35 AM
 *
 * ========================================
 *   ADDITION: Time1 + Time2
 * ========================================
 *
 * Addition Details:
 *   Time 1:     23:50:40
 *   Time 2:   + 00:25:35
 *   ----------
 *   Result:     00:16:15
 *
 * Step by step:
 *   Seconds: 40 + 35 = 75 → 15 seconds, carry 1 minute
 *   Minutes: 50 + 25 + 1 (carry) = 76 → 16 minutes, carry 1 hour
 *   Hours:   23 +  0 + 1 (carry) = 24 → 00 hours
 *
 * Result in different formats:
 *   24-hour: 00:16:15
 *   12-hour: 12:16:15 AM
 *
 * ========================================
 *   SUBTRACTION: Time1 - Time2
 * ========================================
 *
 * Subtraction Details:
 *   Time 1:     23:50:40
 *   Time 2:   - 00:25:35
 *   ----------
 *   Result:     23:25:05
 *
 * Step by step:
 *   Seconds: 40 - 35 = 5 seconds
 *   Minutes: 50 - 25 = 25 minutes
 *
 * Result in different formats:
 *   24-hour: 23:25:05
 *   12-hour: 11:25:05 PM
 *
 * ========================================
 *   Time Difference Analysis
 * ========================================
 *
 * Time 1 in seconds: 86040 seconds
 * Time 2 in seconds: 1535 seconds
 * Absolute difference: 84505 seconds
 *                    = 23 hours, 28 minutes, 25 seconds
 *
 * ========================================
 *   Summary
 * ========================================
 * Time 1:       23:50:40
 * Time 2:       00:25:35
 * Sum:          00:16:15
 * Difference:   23:25:05
 * ========================================
 */
