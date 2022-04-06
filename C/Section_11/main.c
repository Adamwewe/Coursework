#include <stdio.h>
#include <stddef.h>
#include <malloc.h>
#include <string.h>

// Pointer:
    // Is a variable whose value is a memory address
    // The value is the address of another location in memory that can contain a value
    // of course they can only point w.r.t a certain type
    // why use pointers?
        // Accessing data by means of variables is very limiting
        // with pointers, you can access variables directly from memory
            // this makes it easier to use arrays and strings
            // you can refer to the same space in memory in one location and the change can be seen from another (like globals)
            // can also save space by being able to share components in data structures
            // speed!!!
            // you can use pointers to get multiple values form the function
                // it can return only one value but byb passing arguments as pointers we can get more
                // than one value from the pointer
            // with pointers, dynamic memory can be created according to the program use
                // we can save memory from static (compile time) declarations
                // pointers allow to design and develop complex data structures


int pointer_intro();
int pointer_deref();
int challenge_1();
int using_pointers();
int const_modif();
int pointer_arrays();
int pointer_arithmetic();
int pointer_char();
int challenge_string();
int pass_reference(int *const x);
int dynamic_memory();
int challenge_memory();



int main() {
//    pointer_intro();
//    pointer_deref();
//    challenge_1();
//    using_pointers();
//    const_modif();
//    pointer_arrays();
//    pointer_arithmetic();
//    pointer_char();

    char test[] = "Adam";

    int result = challenge_string(test);

    printf("Length of string is: %d", result);

    int num = 5;

    pass_reference(&num);

    printf("Value of x is: %d\n", num);


    dynamic_memory();
    challenge_memory();

    return 0;
}

int pointer_intro()
{
    // here is how you declare a pointer:

    int * pnumber; // declaration contains a space
                   // dereferencing is without a space

    int *pi;
    char *pc;
    float *pf, *pg;

    // printing pointers is done with %p

    // you can also initialize a pointer as NULL:
    int * pnumber_2 = NULL;

    // want to initialize a variable wuth the address of a variable you already declared?
        // use the address of operator, &

    int number = 99; // variable declaration
    int * pnumber_auto = &number; // referencing a pointer to the address of number above

    // you can declare both variables and pointers at the same time:
        // pro tip: always start a variable with the pname:

    int *p_num, foonum;

    // Accessing pointer values:
        // use the inderection operator, *, to access the value of the variable ponited
        // by a pointer. AKA the dereference operator because you deref:
        // basically, whenever you see a "*" with a space and without a type declaration, it is a deref.


    int num = 15;
    int *pointer = &number;
    int result = 0;

    // with all declarations done, now the expressions
    result = *pointer+5; // returns 20

    // the expression *pointer will evaluate to the value stored at the address contained in the pointer
        // the value stored in number, 15, so result will be set to 15+5, which is 20.




    return 0;

}

int pointer_deref()
{
    int count = 10, x; // cool thing here, initialize within and declare after
    int *int_pointer;

    int_pointer = &count;
    x = *int_pointer;

    printf("Printing variable values: ");

    printf("count = %i, x = %i\n", count, x);

    // print the pointer value:

    printf("Printing pointer values: ");

    int nb2 = 0;
    int *pnumber2 = NULL;

    nb2 = 10;
    pnumber2 = &nb2;

    printf("pnumber's pointer value is: %p\n", pnumber2);

    // pointers occupy 8 bytes and the addresses have 16 hexadecimal digits
        // if a machine has a 64 bit os and compiler has 64 bit addresses
        // other compilers are 32 bit

    // now we can display the address
        // done with the & (address of) operator

    printf("Number's address: %p\n", &nb2); // var address in memory
    // you need to use(void*) to circumvent the warning
    printf("pnumber's address: %p \n", (void*)&pnumber2); // pointer address

    // what if we want to display the number of bytes a pointer is using
        // A pointer will occupy 8 bytes as the memory address is 64bits on my laptop
            // in 32 bit, it will be 32 bits as 8*4

    printf("pnumber's size is: %d bytes \n", (int)sizeof(pnumber2)); //use int to avoid warning


    return 0;
}

int challenge_1()

{
    int foo = 10;
    int *pFoo = NULL;


    pFoo = &foo;


    printf("Address of the pointer is: %p \n", &foo);
    printf("Value of the pointer is: %d \n", &pFoo);
    printf("Value of what the pointer is referring to is: %d\n", *pFoo);

    return 0;


}

int using_pointers()

{
    // you can perform pointer arithmetic:
        // use the + operator to add an integer to a pointer
        // increment the pointer by one
        // decrement the pointer by one
        // difference between two pointers
        // u can use relational operator to compare the values of two pointers
        // you can subtract one pointer from another
            // u can subtract an integer from a pointer
            // in an array you need to be careful not to get an out of bounds error


        // example:

        int number = 0;
        int *pnumber = NULL; // remember  is always used to access the contents of a pointer
        number = 10;
        pnumber = &number;
        *pnumber += 25;

        int value = 999;
        pnumber = &value;
        *pnumber +=25;

        // scan f with pointers

        int value_2 = 0;
        int *pValue_2 = &value_2;

        printf("Input an integer: \n");
        scanf("%d", pValue_2);

        printf("You have entered %d.\n", value_2);

        // DO NOT DEREFERENCE AN UNITIALIZED POINTER

        int *pt;
        *pt = 5;

            // This will just randomly store it in the memory
            // it will create a pointer but no address and will therefore not allocate memory

        // you can test for null

        int *pvalue = NULL;





        return 0;
}



int const_modif()

{
    //reminder when u use the const modifier on a variable or an array, it tells the compuler that the contents of the var
    // will not be changed by the program

    // so with pointers, we have to consider two things when using the const modifier
        // whether the pointer will b changed
        // whether the value that the pointer points to will be changed


    // you can use the const keyword when declaring the pointer to indicate that the value pointed to must not be changed

    long value = 9999L;
    const long *pvalue = &value;

    // now that we declared pvalue with a constant keyword the compiler will check any statements attempting to modify
        // the value pointedby the pvalue flag and flag such statements as an error

    // the following statement will now result in an error message from the compiler:

//    *pvalue = 5000L; // NO DEREFERENCING ALLOWED!!!!

    // but a trick you can do is change the value itself and then a standard dereference does the trick:

    value = 5000L;

    // Another trick with constants:

    int count = 43;
    int *const pcount = &count; // This means the address stored must not be changed!!!
    // how to do it IMPORTANT!
        // you put the star before "const"


    // you can also keep EVERYTHING constant:

    int item = 25;
    const int *const pitem = &item;


    // the void pointer
        // void == absence of type
        // void* means any data type can be stored:


    int i = 10;
    float f = 2.34;
    char ch = 'k';

    void *vptr;

    vptr = &i;
    printf("Value of i = %d\n", *(int*)vptr);

    vptr = &f;
    printf("Value of i = %.2f\n", *(float*)vptr);

    vptr = &ch;
    printf("Value of i = %c\n", *(char*)ch);

    return 0;
}


pointer_arrays()
// most common use of pointers is to use them with arrays
    // uses less memory and executes faster
{
    int values[100];
    int *valuesPtr;

    // to set valuesPTr to the first element in the values array you need to write:

    valuesPtr = values;
    // or:
    valuesPtr = &values[0];

    // as you can see the address operator was not used here.
        // the C compiler treats the appearance of an array nam without a subscript as a poitner to the array
        // specifying these values without a subscript has the effect of producing a pointer to the first element of values

    return 0;
}

int pointer_arithmetic()
// this is where we see the real power of pointers
    // when you perform arithmetic (aka incrementing) in an array

{

    // create array pointers:

    int values[100];
    int *valuesPtr = values;

    // some arithmetic:

    *(valuesPtr + 3); // this references values[3] thru ptr variable

    // lets perform another example using both normal and pointer notation

    values[10] = 27;
    // is the same as:
    *(valuesPtr + 10) = 27;

    //also:

    valuesPtr +=1;

    // or:

    ++valuesPtr;


    // go look into the slides for the full arithmetic loops


    return 0;
}


int pointer_char()

{
    // the char* parameter:
        // works the same as arrays


        char *textPtr;
        ++textPtr;
        --textPtr;




    return 1;
}


int challenge_string(const char *string)

{
    const char *plastAddress = string; // set to beginning address of the string array

    while(*plastAddress) // dereferncing a null terminator is equal to zero --> therefore *last address jumps out of the while
        // loop when it sees zero in the end and exits because \0 == False
        ++plastAddress; // we keep incrementing


    return plastAddress - string; // we substract the last address from string first character
}

// pass by value and reference in c:
    // to return a pointer you need to specify the type of the function as a pointer like this:
        // int *myFunction(){}


int pass_reference(int *const x)
{

    *x = (*x) * (*x);

    return 0;

}

int dynamic_memory()
{
    // this is where c shines
        // dynamic memory allocation:
            // allows data to be stored dynamically when the program executes
            // dy malloc is possible only bc of pointers
            // dynam alloc allows the creation of pointers at runtime that are just large enough to hold the amount of
            // data required for the task




     // heap vs stack: two major data structures
        // heap: allows for more change and sticks around longer
            // controlled by you, you need to keep track of when the memory allocated is no longer used
            //you must free the space you do not use

        // stack: used for everything from variables to memory
            // when the execution ends, the space allocated to store arguments and local variables is freed
            // when you exit the function, everything gets deleted


    //malloc: The simplest standard lib function that allocates memory at runtime
        // part of malloc.h
        // u specify the nb of bytes of memory that u want allocated as argument
        // returns the address of the first byte of memory that is allocated
        // bc u get an address returned, a pointer is the only place to put it
        // always put (type*) before malloc because malloc() returns void normally

    int *pNumber = (int*)malloc(100); // not really useful when statically typing the size,

    //the above shows that we allocate 100 bytes of memory for pnmuber:
        // pNumber will point to the first location at the beginning of the 100 bytes that were allocated
        // can hold 25 int values on computer, 4bytes each
        // assuming int requires 4 bytes

    // but this is inefficient, as we are making assumptions, the below is better:

    int *pNumber_2 = (int*)malloc(25*sizeof(int));

    // releasing memory:
        // even when using a heap, always release memory manually!!
        // otherwise a memory leak will happen

    // you just need to pass in the pointer to the free function
        // then you need to set the pointer to null afterwards:

    free(pNumber);
    pNumber = NULL; // always set the pointer to NULL after freeing

    //calloc()
        // allocates memory as a number of elements given a size
        // it initializes memory that is allocated so that all bytes are zero

    //requires two arguments:
        // nb of data items for which space is requried
        // size of each data item

    // is declared in stdlib.h header

    int *pNumber3 = (int*)calloc(75, sizeof(int));



    //realloc() enables t reuse or extend previously allocated memory using malloc or calloc

    // expects two arg values:
        // a pointer contaning an address that was previously returned by a call to malloc(), calloc()
        // size in bytes of the new memor that you want allocated

    // allocates the amount of memory u specify by the second argument
        // transfers the contents of the previously allocated memory referenced by the pointer that you supply
        // as the first argument to the newly acquired memory
        // returns a void* pointerto the new memory or NULL of the operation fails for some reason

    // most important feature of this opeartion is that realloc() preserves the contents of the original memory area



    char *str;

    // initial memory allocation

    str = (char*)malloc(15*sizeof(char));
    strcpy(str, "Adam");
    printf("String= %s, Address =%p\n", str, str); //not enough

    // reallocate memory

    str=(char*)realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s, Address = %p, \n", str, str);

    free(str);
    return 0;

}

int challenge_memory()

{
    int lim;
    char *str = NULL;

    printf("Please enter the size of the string: \n");
    scanf("%d", &lim);



    str = (char*) malloc(lim*sizeof(char));
    printf("Please enter text");
    scanf(" ");
    gets(str);

    printf("String is: %s \n", str);
    free(str);

    return 0;
}