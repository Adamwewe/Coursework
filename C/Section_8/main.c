#include <stdio.h>
# define MONTHS 12 // we defined a constant
# define YEARS 5

// Arrays!!!!
    // you know how the basics work, here are some c-specific things you need to know:
    // you declare them with numbers inside the bracket specifying size
    // same as in Java, you need to use a loop to access array elements
    // IMPORTANT!!!
        // Out of bounds errors are not necessarily identified by the compiler!!

int array()
{
    long numbers[10]; // declaration
    int count = 10;
    long sum = 0;
    float average = 0.0f; // round to one decimal

    printf("\n Enter the 10 numbers: \n");

    for (int i = 0; i < count; ++i)
    {
        printf("%2u: ", i +1);
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    average = (float)sum/count;

    printf("average is: %lf", average);

}

int array_init()
{
    // you can also initialize the array with data inside:

    int counters[5] = {1, 2, 3, 4, 5};

    // you can also initialize just a subset of the full array:

    float numbers[500] = {100.0, 300.0, 500.2};

    // another new feature now: Designated Initializers:
        // you pick and choose an element number in a pair of brackets:
        // can be initialized in any order

    float sample_data[500] = {[2] = 500.5,
                              [1] = 300.0,
                              [0] = 100.0};

    // another example of traditional initialization and printing:

    int days[MONTHS] = {
            31, 28, 31, 30,
            31, 30, 31, 31,
            30, 31, 30, 31
    };// we use the defined constant here

    for(int index = 0; index < MONTHS; index++){
        printf("Month %d has %2d days. \n", index +1, days[index]);

    }

    return 0;

}

int multidim() {

    // like in Java you can have 2, 3, n-sized arrays
    // also like in Java, the nb of brackets = the nb of dims:

    int numbers[3][4]; // decalration of an array with 3 rows and 4 columns
    int nb[3][4] = {
            {10, 9, 8, 9}, // first row
            {7, 8, 9, 8},   // second row
            {7, 7, 9, 9}    // third row
    };

    // also just like arrays, you don't need to initialize all values:

    int mat[4][5] = {
            {1, 2, 3},
            {1, 5, 6},
            {40, 50, 60},
            {4, 9}
    };


    // three dimensional arrays:

    int three_d[2][3][4] = { // main stack
            { // first data table (the first [2] in the declaration)
                {10, 9, 8, 9}, // first row of table 1
                {7, 8, 9, 8},   // second row of table 1
                {7, 7, 9, 9}    // third row of table 1
            },
    { // second data table (the first [2] in the declaration)
        {10, 9, 8, 9}, // first row of table 2
        {7, 8, 9, 8},   // second row of table 2
        {7, 7, 9, 9}    // third row of table 2
    }
};

}

int challenge_primes(){ // FIX THIS LATER!!

    // a prime number is a prime number only if it is not evenly divisible
        // by previous prime number


        int primes[100];
        int p1 = 2;
        int p2 = 3;
        int j = 0;

        for (int i = 0; i < sizeof(primes); ++i)
        {
            if (i < 2){

                primes[0] = p1;
                primes[1] = p2;

            }

            if (i % (i-1) == 0)
                primes[j] = i;

            printf("Result for iteration no. %d: %d\n", i, primes[i]);

        }
        ++j;



    return 0;
}

int challenge_weather(){ // finish this later!!

    float weather[YEARS][MONTHS] = {

    };

    int year, month;
    float subtot, total;

    printf("Year \t \t RAINFALL (inches)")


//    for (m = 0; m < 5; ++m)
//    {
//        weather[m] = (2010+m);
//
//        for(j = 0; j < 12; ++j)
//        {
//            [j] = (2010);
//            weather[m][j] = 7.3 ;
//
//            printf("value at [%d][%d] is [%lf] \n", m, j, weather[m][j]);
//            printf("Year is %d \n", weather[m]);
//
//        }
    }
}

int main() {


//    array();
//    array_init();
//    multidim();
//    challenge_primes();
    challenge_weather();

    return 0;
}
