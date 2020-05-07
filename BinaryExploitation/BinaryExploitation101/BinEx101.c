#include <stdio.h>
#include <stdlib.h>

#define FLAG_SIZE 64

/* Function prototype for `initialize`
 *     Allows `main` to call it without the definition.  Usually you see these
 * in a separate header file.  It also tells you that it "returns" a "char *"
 * (left side of the function name) and takes "void" (a synonym for nothing) as
 * the parameters (what's inside the parenthesis).
 */
char *initialize(void);





/* A "struct" definition.
 *     This creates a reusable "type" that packages other types (like pointers,
 * integers, floats, and even other structs) into a well-defined representation
 * in memory.  While there are lots of rules to ensure fields are correctly
 * "aligned" in memory, the important concept here is that fields earlier in
 * the definition of the struct are "lower" in memory.
 */
struct dynamic_strings {
  char *flag;
  char *numbers[10];
};
/* EXPLANATION:
 *
 * "char *flag;"
 * `flag` is a "pointer" to a "char" - a signed, single byte numbers which are
 * commonly used to represent text "strings".
 *
 * "char *numbers[10];"
 * `numbers` is an "array" of "char pointers".  An array just means that the
 * type on the left "char *" is repeated a number of times (10 in this case).
 * This is an example of a "static" sized array which means it will always
 * have 10 slots in it.  We can access the slots through the notation
 *     array[index]
 * where "array" is replaced by the variable name (numbers in this case) and
 * "index" is replaced with the position you want to access (starting with 0).
 * In other words, numbers[0] is the first element, numbers[1] is the second,
 * and so on.
 *
 * Under the hood, the compiler & computer convert this into arithmetic
 * composed of applying an offset to the "base" (first element of the array).
 * Going back to "array[index]", the compiler essentially converts this into
 * accessing the memory at (where array_type is the "type" of each element):
 *     array + sizeof(array_type) * index
 * A consequence of this construction is that the compiler and computer
 * allow code like "array[-1]" which will access an "element" immediately
 * before the first.  Accesses like this are frequrently unintentional and
 * can often allow hackers to exploit the program for their own purposes.
 *
 * For this specific instance,
 *     numbers[-1] == flag
 * which should be an early indication of where we should focus our efforts
 * for exploiting this program.
 */





/* This is the `main` function.  Every C program will have one (and most
 * languages define some kind of equivalent).  This is generally, but not
 * always, a good place to start when analyzing a program since it is the
 * logical start point for the code a programmer wrote.
 */
void main(void) {
  /* The next two lines define two "variables" that we use to store and
   * reference values later.  In C, an "int" is a 32-bit, signed integer.
   */
  int first;
  int second;


  /* This section of code creates a new "instance" of our struct we defined
   * above.  It also "initializes" it by setting "flag" (the first field) to
   * the return value of `initialize` and the "numbers" array to point to the
   * strings defined in line.  You should notice that there are exactly 10
   * strings given inside the curly braces which matches the size of "numbers".
   */
  struct dynamic_strings s = {
    initialize(),
    {
      "zero",
      "one",
      "two",
      "three",
      "four",
      "five",
      "six",
      "seven",
      "eight",
      "nine"
    }
  };


  /* This section of code prompts the user for input and then reads it in as
   * an integer.  If the input was either not an integer or negative, it prints
   * an appropriate error code and exits.
   */
  puts("Give me a number:\r");         /* Prompt for input */
  if (!scanf("%d", &first)) {          /* Read input and store in `first` */
    /* `scanf` return a non-zero number (C for "true") on success, this means
     * `!scanf(...)` can be read as "scanf was not successful" since the '!'
     * symbol means a logical negation (i.e. the opposite "truth value" of
     * what it was).  That means we only execute the next two lines if the
     * user did not enter a valid number (empty or had non-numeric characters).
     */
    puts("Error: unrecognized input\r");
    exit(1); /* Exiting with a number other than 0 generally indicates a program
              * error occurred.
              */
  }
  if (first <= 0) { /* Checks if the inputted number is negative */
    puts("Error: input must be positive\r");
    exit(1);
  }

  /* Repeat the process for "second" */
  puts("Give me another number:\r");
  if (!scanf("%d", &second)) {
    puts("Error: unrecognized input\r");
    exit(1);
  }
  if (second <= 0) {
    puts("Error: input must be positive\r");
    exit(1);
  }


  /*************************************************************
   ********************** VULNERABLE CODE **********************
   *************************************************************/
  int tmp = first * second;
  /* In some languages (e.g. Python 3) there are no issues with the line above
   * and it will always match the intuitive meaning: `tmp` equals the product
   * of the two integers that were passed in and is therefore positive.
   *
   * However, this is not how C (or most languages with fixed-width integers)
   * works.  Instead the calculation can "overflow" the highest expressible
   * integer and wrap around to the lowest expressible integer and keep going.
   * In other words, it is entirely possible to get a negative number for
   * `tmp` by multiplying two numbers that are less than INT_MAX (2147483647).
   *
   * In the line below, we create the vulnerability by using `tmp` to access
   * the "numbers" array in our struct.  In C the modulo operator (%) (also
   * known as "remainder"), has the same sign as the left-hand side.  This
   * means if `tmp` is negative, we will end up accessing memory that is
   * outside of the array.
   *
   * How can we leverage this to print the flag?
   */
  printf("%d * %d = %d which ends in a '%s'\r\n",
         first, second, tmp, s.numbers[tmp % 10]);
}





/* For the purposes of this problem (and many of the other CTF problems), this
 * is basically boilerplate code.  If you're interested in better understanding
 * what this code is doing, you can read more about each of the function calls
 * by typing `man 3 <function>` into a UNIX terminal (such as our shell server).
 * This will give you the function information for the calls.
 */
char *initialize(void) {
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);

  char *flag = malloc(FLAG_SIZE);
  FILE *file;
  file = fopen("flag.txt", "r");
  if (file == NULL) {
    puts("Error: could not open the flag\r");
    exit(0);
  }
  fgets(flag, FLAG_SIZE, file);
  fclose(file);
  return flag;
}
