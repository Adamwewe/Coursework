#include <stdio.h>
# include <stdbool.h> // for fancy bool
// memory

/* RAM is a sequence of boxes, each box is a bit where:
    * 0 is false // not full
    * 1 is true  // full
 * bits in memory are grouped into sets of eight (byte)
    * each byte has been labeled with a number (address)
    * the address of a bite is a unique reference in the computer's memory
    * one byte (groups of 8bits) are also stored and referenced uniquely
* The above is essential to understand in order to be able to create variables and use pointers
 */


/*
 * C has the following types available:
    * int --> no decimals, only integral numbers. Hex also accepted
    * float --> decimals possible, floating point numbers.
    * NOTE! C interprets constant by default as double, to force it as a float add "f" in the end: 12.2f
    * double --> Same as float but with twice the precision therefore requiring more memory.
    * char
    * _Bool --> Logical: 0--> false 1--> True
 * The main difference between the above is of course the values they can hold and the space occupied in memory
 * Other special types:
    * Enum: A type which can only be of a certain type
        * For example: enum primaryColor: {red, yellow, blue}
        * enum day {monday, tuesday, wednesday, [...], Sunday}
        * enums can be even more powerful by specifying specific index values:
            * {up, down, left=10, right}--> up has an index of zero, left has an index of 1, right would be equal to index 11
    * Char: Single characters
    * Escape characters: represent actions
    * Example char x = '\n'
    *

 */

int declare()
{
    int foo_int = 2;
    float foo_float = 3.0;
    double foo_double;
    _Bool foo_bool = 0; // old one
    bool  foo_fancy_bool = true; // new bool after c99

    foo_double = 4.0000000000;

    printf("Integer var = %i \n", foo_int);
    printf("Float var = %f \n", foo_float);
    printf("Double var = %g \n", foo_double);
    printf("Double var alternative = %e \n", foo_double);
    printf("Bool var = %i \n", foo_bool);

    return 0;
}

/* When declaring vars, one can also make the declarations short, long or unsigned
 * These declarations allow the user to save/provide more memory when needed
 */


int declare_modified()
{
    short int foo_short = -1;
    long int foo_long = 0;
    unsigned int foo_un = 1; // unsigned means no negative values allowed!!!!

    return 0;
}

int declare_special(){
    enum foo_enum {red, blue, green};
    enum foo_enum color;
    color = red;
    char foo_char = 'F';

    printf("Char var = %c", foo_char);

    return 0;
}

/* Now in order to visualize all the above types we need to do specify a format before printing
 * %i --> Integer
 * %f --> Floating
 * %e --> Double
 * %g --> Double
 * %c --> Chars
 * %i --> Bool
 */


/* Command line arguments
 * passing from command line is fairly easy as main () will always be the entry point
    * You just need to set the main() parameters as seen in the example below
 */


int main(int argc, char *argv[])
{   int nbArgs = argc;
    char *argument1 = argv[0];
    char *argument2 = argv[1];

    printf("Number of Arguments %d", nbArgs);
    printf("Argument 1 is the program name: %s", argument1);
    printf("Argument 2 is the command line argument; %s", argument2);

    printf("Hello, World!\n");
    declare();
    declare_modified();
    declare_special();
    return 0;
}

