#include <stdio.h>
#include <stdlib.h>

// structures are a powerful tool for grouping elements together
    // similar to OOP, it is used group sets of variables together
    // for example dates:
        // day
        // month
        // year

int structure_demo();
int array_ofStructures();
int nested_structures();
int structure_pointers();
int structure_functions();
int structure_challenge();
int structure_challenge_2();

struct item
{
    char *itemName;
    int quatity;
    float price;
    float amount;
};

int main() {
    printf("Hello, World!\n");

    struct item it;
    structure_challenge_2(it);
    return 0;
}



int structure_demo()
{

    struct date
    {
        int day;
        int month;
        int year;
    };

    // no memory allocation for the above declaration
    // var names within structures are called members or fields
        // members of the structure appear between the braces that follow the struct tag name date

    // you can look at it as defining a new type in the language (a bit like enums)
        // after defining the type, you can then add new variables of type struct date:

    struct date today;

    // or another example:

    struct date purchaseDate;

    // now this is how we access variables of a structure:
        // variable names are not pointers
        // we therefore need a special syntax to access a structure
            // aka the dot operator (like dataframes and columns)

    today.day = 25;
    today.year= 2022;
    today.month = 01;


    printf("Today's date is %i/%i/%i \n", today.day, today.month, today.year);

    // expressions work the same way as normal variables:
    int century = today.year/100;


    // now lets look at some pure c elegance
        // you can declare a variable to be of a particular structure type at the same time that the structure is defined
        // include variable name before the terminating semicolon of the structure definition
        // you can also assign initial values to the variables in the normal fashion

    struct date2
    {
        int day;
        int month;
        int year;

    } today2;

    // see how we created an instance of the structure above all in one go?
    // you can also declare an undefined structure, but the cases where this is useful are very rare!


    // we took care of declaration now lets look at initialization:

    struct date date1 = {22, 01, 2022};
    struct date date2 = {23, 01, 2022};
    struct date date3 = {.month=01, .day=3};

    // you can also assign in a single statement using compound literals

    today = (struct date){22, 01, 2022};

    return 0;
}

int array_ofStructures()
{
    struct date {
        int day;
        int month;
        int year;
    };

    // now we declare the array of structures using the above structure:

    struct date myDates[10];
    // each element inside of this array is a structure of three elements each
        // here is how to set individual items inside it:

    myDates[1].month = 8;
    myDates[1].day = 9;
    myDates[1].year = 1986;

    // so on and so forth for the remaining indexes...

    // you can also do the entire declaration and definition this way:

    struct date myDates2[5] = {{12, 12, 2022}, {12, 12, 2022}, {12, 12, 2022}};

    // or this way

    struct date myDates3[5] = {[2] = {12, 10, 1999}}; // just specify the third (index 2) element

    // or this way

    struct date myDates4[5] = {[1].month = 12, [1].day = 30};

    // what about structures containing arrays:
        // most common use is to set up an array of chars in a structure

    // suppose you want to define a structure called month that contains as its members the nb of days
    // in the month as well as a three-char abbreviation for the month name

    struct month
    {
        int numberOfDays;
        char name[3];
    };

    // access is done by creating a variable

    struct month aMonth;
    aMonth.numberOfDays = 31;
    aMonth.name[0] = 'J';
    aMonth.name[1] = 'a';
    aMonth.name[2] = 'n';

    // the above is just an academic example ofc, normally you would use strcpy to do everything at once

    struct month aMonth2 = {31, {'J', 'A', 'N'}};

    struct month months[12];

    return 0;
}


int nested_structures()

{

    // the examples we saw can be further expanded thru nesting

    struct time
    {
        int hours;
        int minutes;
        int seconds;
    };

    struct date
    {
        int day;
        int month;
        int year;
    };


    // now we nest both:

    struct dateAndTime
    {
        struct date sDate;
        struct time sTime;
    };


    // here is how we access the structures

    // first we define the var

    struct dateAndTime event;

    // now we access it

    event.sDate; // we access the date nested structure
    event.sDate.month = 10; // we access the month member inside the month member of the date structure
    ++event.sDate.month; // we can also increment it

    // u can also define and declare like this:

    struct dateAndTime event2 = {{2, 1, 2015}, {3, 30, 0}};

    struct dateAndTime event3 = {
            {.month = 4, .day = 4, .year = 2022},
            {.hours = 3, .minutes = 30, .seconds = 0}
    };

    // what about an array of nested structures?

    struct dateAndTime events[100];

    events[0].sTime.hours = 12;
    events[0].sTime.minutes = 0;
    events[0].sTime.seconds = 0;

    // Thats it!



    return 0;
}

int structure_pointers()
{

    // pointers to structures are easier to manipulate than structure themselves
        // even if you can pass a structure as a function argument, passing a pointer is more efficient
        // because why copy an entire structure when we can just pass in the address of it??

    struct date
    {
        int day;
        int month;
        int year;
    };

    struct date todaysDate = {23, 01, 2022};
    struct date *datePtr;

    datePtr = &todaysDate;

    //  now we want to access the members of the date structure by dereferncing the pointer
        // whatever the date is in the .day location the pointer is pointing to we set to 21

    (*datePtr).day = 21;

    // but the above is a bit cumbersome, so we can avoid doing (*datePtr).day = xx
        // we can just do this:

    datePtr->day = 12; // so u just replace the period with "->"


    // pointers can also be contained in a structure:

    struct inPtrs
    {
        int *p1;
        int *p2;
    }; // a structure of pointers

    struct inPtrs pointers;
    int i1 = 100, i2;

    pointers.p1 = &i1;
    pointers.p2 = &i2;
    *pointers.p2 = -97;


    // character pointers

    struct names{
        char *first_name;
        char *last_name;
    };

    struct names veep = {"Talia", "Summer"};
    struct names trees = {"Brad", "Fallingjaw"};

    printf("%s and %s \n", veep.first_name, trees.first_name);

    // but the above can run out of memory and cause our problem to crash
        // which is why you can use malloc


    return 0;
}

int structure_functions()
{
    // how do we pass structures into function definitions
        // As discussed, pointers are the best way of doing so to avoid memory consumption and time loss

    // you can return a structure from a function ofc:

        // return struct func my_func
        // but still please always use pointers as older versions of c did not support structure passing

}

int structure_challenge()

{

    struct employee{
        char name[30];
        char hireDate[30];
        float salary;
    };

    struct employee emp;

    printf("Please enter employee info: \n");

    printf("Name: ");
    scanf("%s", emp.name);

    printf("Hiring date ");
    scanf("%s", emp.hireDate);

    printf("Salary: ");
    scanf("%f", &emp.salary);

    printf("The recorded data is as follows. Employee name: %s, HiringDate: %s, Salary: %f", emp.name,
           emp.hireDate, emp.salary);

    return 0;
}

// come back to this challenge!!!


int structure_challenge_2(const struct item)

{
    struct item itm;
    struct item *pItem;

    pItem = &itm;
    pItem->itemName = (char*)malloc(30*sizeof(char));

    printf("Please enter the product name: \n");
    scanf("%s", it.itemName);

    printf("Please enter the price: \n");
    scanf("%f", &it.price);

    printf("Please enter the quantity: \n");
    scanf("%i", &it.quatity);


    printf("Item is: %p", it->itemName);



    return 0;
}

