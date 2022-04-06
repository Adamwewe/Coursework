#include <stdio.h>

// Expressions and statements:
    // Expressions: combination of operators and operands
        // operands are what an operator operates on
        // operands can be constants, variables, or combinations of the two
        // every expression has a value
    // Statements: building blocks of a program (declaration)
        // A program is a series of statements with special syntax ending with a semicolon
        // a complete instruction to the computer
    // Compound statements:
        // two or more statements grouped together by enclosing them in braces (basically blocks of code)


// Operators:
    // logical: return boolean results
        // &&: Logical AND
        // ||: Logical OR
        // !: Logical NOT
    // arithmetic:
        // other than the usual operators here are some you might not think of:
            // ++ Increment operator: Increases the integer value by one
            // -- Decrement operator: Decreases the integer value by one

    // Other operators:
        // Assignment (=, +=, -=, *=, %=)
        // Relational (<, >, !=)
        // Bitwise operators (<<, >>, ~)
            // Bits are useful to store data that involves one of two choices
            // For example: you could use a single integer variable to store severable characteristics of a person:
                // male/female? --> one bit
                // three other bits to specify a language: French?German?English?
                // another bit for the salary --> 50 000$ or more
                // in four bits we have a substantial amount of data recorded
            // Byte = 8 bits
                // Integer = 4 bytes (32 bits)
                // Binary numbers have corresponding decimal values
                // each position of a binary number has a value
                // look at a bit table to recall!
            // now the operators:
                // &: Binary AND operator copies a bit to the result if it exists in both operands
                // |: Binary OR Operator copies a bit if it exists in either operand
                // ^: Binary XOR Operator copies the bit if it exists in either operand
                // ~: Binary Ones Complement operator is unary and has the effect of "flipping" bits
                // <<: Binary Left shift Operator. The left operands value is moved left by the number of bits
                    // specified by the right operand
                // >>: Binary right shift operator. The left operands value is moved right by the number of bits
                    // specified by the right operand
                // for all the above, just review a simple Truth table

int main() {
    // important!!! The difference between prefix and postfix!!
        // prefix = ++a
        // postfix = a++
    // The difference between the two is when the incrementation will occur:
        // "a++" --> increments in the next line of code
        // "++a" --> increments before the statement is executed

    int a = 33;
    int b = 33;
    printf("everything has a value of 33! \n");

    printf("prefix a: %d \n", ++a);
    printf("postfix b: %d \n", b++);


    // now for some binary fun:

    unsigned int c = 60; // 0011 1100
    unsigned int d = 13; // 0000 1101
    int result = 0;

    result = c & d; // should return 12
        // 0000 1100
    printf("result for AND is %d \n", result);

    result = c | d; // should return 61
    // 0011 1101
    printf("result for OR is %d \n", result);

    result = c << 2; // remember that it is coming from a 32bit number:
    // 0000 0000 0000 0000 0000 0000 0011 1100
    // 1111 0000
    printf("result for shifted by 2 is %d \n", result);

    // now we shift by 4:
    result = a << 4;
    printf("result for shifting by 4 is %d \n", result);



    return 0;
}


// Type conversions:
    // Like any other language you can convert data types
        // it can either be automatic (implicit version)
        // or explicit by the program itself
    // DO NOT ABUSE OF TYPE MIXING!
        // Only do it if you have no choice
    // but if it has to be done, here how you cast in operations:
        // (int) 21.51 + (int) 26.99 <==> 21 + 26
// Another interesting operator is sizeof() which returns the nb of bytes occupied in memory per variable
    // size of is actually an operator, not a func and evaluated at compile time
// Finally the last operator, the asterisk "*"
    // Not to be confused with the multiplication, but when it occurs before a single variable it refers
    // to dereferencing a pointer --> E.G *a
//Last Last oe is ?
    // a ternary operator to evaluate conditions
        // if condition is true ? then value X: Otherwise value Y

// Operator Precedence:
    // How to evaluate order of the precedence?
    // the normal math rules apply: 7 + 3 * 2 = 13 (multiplication has a higher precedence)

    // What if two operators have the same precedence?
        // Then the associativity rules are applied
        // If they share an operand, they are executed according to the order in which they occur in the statement
        // order is from left to right
        // 1 == 2 != 3 --> ((1 == 2) != 3)
        // (1 == 2) Executes first resulting into 0 (false), then (0!=3) executes resulting into 1 (true)
        // You can find precedence level tables online, but its not really important, just use parentheses to avoid unexpected behavior

