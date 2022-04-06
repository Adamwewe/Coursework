#include <stdio.h>
#include <stdlib.h>


int Byte()
{

    int a;
    char b;
    long c;
    long long d;
    double e ;
    long double f;

    printf("Int format %zd \n", sizeof(a));
    printf("Char format %zd \n", sizeof(b));
    printf("Long format %zd \n", sizeof(c));
    printf("Long long format %zd \n", sizeof(d));
    printf("Double format %zd \n", sizeof(e));
    printf("Long double format %zd \n", sizeof(f));



    return 0;
}


int main() {

    //var declaration

    int minutes;
    int min_year;
    double years;

    printf("Please enter a number of minutes: ");

    scanf("%d", &minutes);

    printf("You have entered %d minutes \n", minutes);

    min_year = 60*24*365;

    double min_days = 60*24;


    printf("This is the equivalent to: \n %lf years. \n", ((double)minutes/ min_year));

    printf("This is the equivalent to: \n %lf days. \n", (minutes/ min_days));

    printf("next up, byte size: \n");

    Byte();

    return 0;
}

