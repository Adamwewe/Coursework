#include <stdio.h>
# include <stdlib.h>
# include <math.h>

// functions, subroutines, procedures, methods...
    // you're familiar with all this, lets see now what we can learn
    // in c and java you have the following naming logic in the headers:
        // datatype, function name, parameter
        // of course as you already know, you cannot use a reserved name and no function overload
        // CamelCase your function name as always


// function prototypes are cool things in c so you don't have to put main at the bottom
    // prototypes are outside of the main scope and allow us to define the functions at the bottom like this:

void foo();
void multiplyTwoNumbers(int x, int y);
float return_square(float x);
int static_var();

// Challenge 1:

unsigned int gcd(int x1, int x2);
float abs_nb(float x);
float square_root(float x);


int main() {
    foo();
    multiplyTwoNumbers(2, 3);
    int sq = 4;

    float result = return_square(sq);
    printf("square of %d is %lf  \n", sq, result);

    printf("static 1st call: %d \n", static_var());
    printf("static 2nd call: %d \n", static_var());
    printf("static 3rd call: %d \n", static_var());

    // gcd:

    unsigned int x1 = 2;
    unsigned int x2 = 4;

    printf("greatest common divisor is %u \n", gcd(x1, x2));

    // absolute val
    float x = -18;
    printf("absolute value of %lf is: %lf \n", x, abs_nb(x));

    // sqrt function:

    float y = -78;
    printf("SQRT of %lf is %lf: ", y, square_root(y));

    return 0;
}

void foo(){

    // now it will be called from main although it is defined underneath
}


// Function arguments:
    // u know most of this but here are some c-specific quirks:
        // when passing an array as an argument to a function
            // you must also pass an additional argument specifying the size of the array
            // the function has no means of knowing how many elements there are in there

void multiplyTwoNumbers (int x, int y) // void means return nothing!

{
    int result = x * y;
    printf("The product of %d and %d is: %d \n", x, y, (x*y));

}

// returning data works the same as any other language

float return_square(float x)
{

    float square = x*x;
    return square;
}

// Static variables:
    // Can preserve their value even after they are out of their scope
    // remains in memory while the program is running

int static_var()

{
    static int count = 0;
    count ++;
    return count;
}

// Challenge 1:


unsigned int gcd(int x1, int x2)
{
    if (x2 == 0)
        return x1;
    return gcd(x2,x1%x2);


}

float abs_nb(float x)
{
    int res = abs(x);
    return res;
}

float square_root(float x)
{
    if (x < 0)
        return sqrt(abs_nb(x));

    return sqrt(x);

}