#include <stdio.h>
# include <string.h>

// defining constants:
    // should be done at the top like this:
#define TAXRATE 0.015
    // this is not the same as a variable!!!
        // the value is immutable, you cannot change it!
        // as you may have noticed, it does not have a semicolon and it is global
        // you can also include strings, literals, etc.
# define FOO "foo"

// another tip, you can also turn a variable into a constant like this:
    // this is better as you can:
        // set the scope of the variable
        // set the type
        // use it with enums

const int MONTHS = 12;



// as you know the difference between strings and chars:
    // string --> ""
    // char --> ''
    // string constant "x" != char constant 'x'
        // "x" is a derived type, an array of char
        // 'x' is a basic type
        // "x" really consists of two characters, 'x' and '\0', the null character





    // reminder when dealing with quotes in strings, use backlash before:
        // printf("For \" you write \\\".");

    // do not confuse NULL with null:
        // null char is a string terminator
        // NULL is a symbol that present a memory address that does not reference anything

    // to declare empty strings in c do the following:

int null_demo(void);
int string_demo(void);
int string_demo_2(void);
int string_search_demo(void);
int converting_strings(void);
int challenge_1(const char string[]);
// remaining challenges to be done later, you already know this...



int main() {
//    null_demo();
//    string_demo();
//    char test[] = "Adam";
//    string_demo_2();
//    string_search_demo();
//    converting_strings();
    char string[] = "foo";
    challenge_1(string);
    return 0;
}

int null_demo() // null character demo
{
    printf("The Character \n\0 is used to terminate a string ");
    return 0;
}

int string_demo()
{
    char str[20]; // initialization of an empty string array
    char word[] = {'H', 'e', 'l', 'l', 'o'}; // string array manual declaration
    char word_2[7] = {"Hello!"}; // watch out with specification of the size, mistakes can happen and it will punish you
    char word_3[] = {"Hello"}; // best thing is to let it figure it out
    char str_2[40] = "to Be"; // you can also just initialize it and fill part of it

    // displaying is with printf and %s

    printf("string %s", word_3); // expects a null terminated string

    // same for scanf
    char input[10];

    scanf("%s", &input);

    printf("Input is: %s\n", input);

    // unlike python, equality operators do not work, you need to use the strcompare() method

    return 0;
}


int string_demo_2()
    // with string.h you can return the string length as such:
{
    int length = strlen("adam");
    printf("Length of string is %d \n", length);

    char myString[] = "My name is Adam";
    printf("The Length is: %d\n", strlen(myString));

    // copying:

    char temp[50];
    // always use strncopy To avoid overflows!

    strncpy(temp, myString, sizeof(temp)-1);
    printf("String is %s: ", temp);

    // string concatenation:

    char ourString[] = "my string";
    char input[80];

    printf("Enter a stirng to be concatenated");
    scanf("%s", &input);

    strncat(ourString, input, 10); // destination is always first!
                                        // the 10 means its the first 10 characters

    // comparing strings:
        // as we cannot use "==" in c, we use "strcmp()"
        // returns the following:
            // value < 0 if str1 is less than str2
            // value > 0 if str2 is less than str1

    printf("strcmp(\"A\", \"A\") is: \n");
    printf("%d\n", strcmp("A", "A"));

    printf("strcmp(\"A\", \"B\") is: \n");
    printf("%d\n", strcmp("A", "B"));

    printf("strcmp(\"C\", \"B\") is: \n");
    printf("%d\n", strcmp("C", "B"));
    printf("%d\n", strcmp("C", "B"));

    printf("strcmp(\"C\", \"C\") is: \n");
    printf("%d\n", strcmp("C", "C"));


    // now in words with strncmp:
        // pay attention to how using words now introduces a numerical argument to count the number of chars:

    if (strncmp("astronomy", "astro", 5) == 0) // means look for the first 5 words and check if they match (equal to zero)
    {
        printf("Found: Astronomy");
    }

    if (strncmp("astounding", "astro", 5) == 0)
    {
        printf("Found: Astounding");
    }


    return 0;
}


int string_search_demo(void)
{
    // pointers intro:
        // when saving a value in a variable
        // pointers point to an address in memory that contains a value like this:

    int number = 25; // value
    int *pnumber = &number; // pointer

    // strchr() searches a given string for a given character
        // it will search the string starting at the beginning and return a pointer to the first position in the string
            // where the character is found:
                // it will return the address of this position in the memory
                // is of type char* described as the "pointer to char"

        // to store its value, you must create a variable that can store the address of a character

        // if the character is not found, function returns special value NULL
            // NULL is the equivalent of 0 for a pointer and represents a pointer that does not point to anything
        // here is how it works:


        char str[] = "The quick brown fox"; // string to be searched
        char ch = 'q';  // character we are looking for

        char *pgot_char = NULL; // Pointer initialized to NULL
        pgot_char = strchr(str, ch); // Stores address where ch is found


        // first argument to strchr() is the address of the first location to be searched
            // second argument is the char that is sought
            // expects its second arg to be of type int, so the compiler will convert the value of ch to this type
            // could just as well define ch as type int (int ch= 'q')
            //pgotchar will then pooint to value (quick brown fox)


        // the strstr() is pbly the most useful as it searches for one string for the first occurance of a substring
        // retirns a pointer where string is found, otherwise NULL

        char text[] = "Every dog has his day";
        char word[] = "dog";
        char *pfound = NULL;
        pfound = strstr(text, word);

        // searches text for the first occurance of the string stored in word
            // the string "dog" appears standing at the seventh character in text
            // pFound will be set to the address text + 6 ("dog has his day")
            // search is case sensitive, "Dog" will not be found


        // Tokenizing:
            // a token is a sequence if chars within a string that is bound by a delimiter:
                // it can be anything, but should b unique to the string
                    // spaces, commas and a period are all good examples
            // breaking a sentence into words is called tokenizing
                // we use strtok() for this and requires two arguments:
                    // a string to be tokenized
                    // a string containing all the possible delimiter characters

        char str_2[80] = "Hellow how are you = my name is Jason";
        const char s[2] = "-";
        char *token;

        // get first token:
        token = strtok(str_2, token);

        // walk thru other tokens:
        while(token !=NULL)
        {
            printf("%s\n", token);

            token = strtok(NULL, s);
        }
        // cf. analyzing strings table to visualize all methods
}

int converting_strings()
{
    //toupper() converts to upper case
    //tolower() converts to lower case

    char text[100];
    char substring[100];

    printf("Enter the string to be searched (less than %d characters)", 100);
    scanf("%s", text);

    printf("\n Enter the string sought (less than %d characters): \n", 40);
    scanf("%s", substring);

    printf("First string to be searched: \n%s\n", text);
    printf("Second string to be searched: \n%s\n", substring);

    // Convert both strings to uppercase

    for(int i=0; (text[i] = (char)toupper(text[i])) != "\0"; ++i);
    for(int i=0; (substring[i] = (char)toupper(substring[i])) != "\0"; ++i);

    printf("The second string %s found is the first \n", ((strstr(text, substring))==NULL ? "was not": "was"));



    // you can also convert strings to an int with methods such as atof() (a to float/double)
        // or atoi() a to integer
        // or atol() a to long
        // or atoll() a to long long

        // the above was for single chars, now for full strings

        // strod() string to double
        // strtof() string to float
        // strold() string to long double



}



int challenge_1(const char string[])
{

    int count = 0;

    while (string[count] != '\0')
    {
        ++count;
    }

    printf("String has length of %d \n", count);

    return count;
}