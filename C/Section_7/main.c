#include <stdio.h>
# include <stdlib.h>

// Control flows
    // Work like in any other language in c no need to catch up here

// However, we have one unique operator we can use!
    // The ternary operator is the conditional operator
        // it has two symbols that are used for condition: "?" or ":"
        // how it works:
            // x = y > 7 ? 25:50;
            // Results in x being set to 25 if y is greater than 7, or to 50 otherwise.

// There is also a go to statement --> Not really useful as it is hard to follow
    // but here is how it works:
        // has two parts:
            // goto
            // label name

int loopy()
{
    // you know how this works
        // here is the c syntax for it:
            // for (starting_condition; continuation_condition; action_per_iteration )
                // loop_statement;

            // continuation condition is tested at the beginning
                // because it is a pre-test loop unlike do-while post-test loops



    for (int count = 1; count <= 10; ++count)
    {
        printf("%d", count);
    }

    // we can also play more and more with the conditions

    for (int i=1, j=2 ; i<= 5; j=j+2, ++i)
    { // as you can see here we initialize two vars (i, j)
        // control using i<=5
        // and counting is done with ++i and j = j+2 after each iteration
        printf(" %5d", i*j);

    }

    // Now while loops:
        // as you know, also a pre-test loop
            // etc...

    printf("While loops");

    int count = 0;

    while (count <= 5) // count controlled while loops
    {
        printf("count = %d", count);
        ++count;

    }

    while (count != -1) // logic controlled loop
    {
        ++count;
        printf("Count is %d", count);

        if (count == 5){
        count = -1;

        printf("Count is %d", count);
        printf("End of loop");

        }

    }


    // Now post-test stuff!!!
        // do while example:

    double number;

    do
        scanf("%d", &number);
    while (number != 20);

    // another number-controlled example:

    number = 1;
    do
    {
        printf("\n Number = %d", number);
        number++;
    }

    while(number < 4);




    return 0;
}


int nested_loop()
{   // as you know already, its just a loop inside of another loop
    // you can nest anything --> for loops + while loops, do while, etc.
        // for example:

    int  count = 0;
    int sum;
    int j;


    for (int i = 1; i<= count; ++i)
    {
        sum = 1; // for inner loop
        j = 1; // integer to be added

        // calculate sum of integers from 1 to i

        while (j<1)
        {
         sum += ++j;
         printf("+ %d", j); // output +j on the same line
        }
        printf("=%d", sum); //output = sum
    }

    // Continue statements:
        // you skip an iteration as u know...
        // rule! Do not use continue if it does not simplify the code

    enum Day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

    for (enum Day day = Monday; day <= Sunday; ++day)

    {
        if(day == Wednesday){
            continue;
        }

        printf("Its not Wednesday! \n");
    }

    // another example is the break statement
        // While continue skips a block, break just ends the loop
        // example:

    int p = 0;
    int q =0;

    while (p > 0)
    {
        printf("%d \n", p);
        scanf("%d", &q);

        while (q>0)
        {
            printf("%d \n", p*q);
            if(q > 100)
            {
                break;
            }
            scanf("%d", &q);
        }

        if (q>100)
            break;
        scanf("%d", &p);
    }


    return 0;
}

int challenge_guess_nb(){

    // generate random number

    int r = rand() % 21; // initialization of 20 random numbers
    int guesses = 5;
    int input;

    do
    {
        printf("You have %d guesses left: \n", (guesses));

        printf("Please enter a number between 0 and 20: \n");
        scanf("%d", &input);


        --guesses;

        if(guesses == 0 && r!=input)
        {
            printf("you lost :( \n");
            break;
        }

    }
    while (input != r);

    printf("Congrats! You have guessed the correct number! (%d)", r);

    return 0;
}




int challenge_pay(){

    int hours;
    int gross;
    double tax;
    double net;

    printf("Please enter the amount of hours you worked this week: \n");
    scanf("%i", &hours);

    gross = hours*12;

    if (hours > 40) // calculate overtime
        gross += (12*(hours-40))*1.5;

    if (gross<=300) // tax rate calculation
    {
        tax = gross * 0.15;
    } else if (gross >= 300 && gross <= 450)
    {
        tax = gross * 0.20;
    } else
    {
        tax = gross*0.25;
    }

    net = gross - tax;


    printf("For %i hours worked \n", hours);
    printf("You have gained %i$ gross \n", gross);
    printf("Paid %lf$ in tax \n", tax);
    printf("Which amounts to a net income of %lf$ \n", net);




    return 0;
}

int switcher(){

    // A very interesting statement is the switch statement
        // When the value of a single variable is successively compared against
        // different values, use the switch statement.
            // It is more convenient and more efficient.
            // to recap, if you need to use if else/ if else/ if else...
                // use switch!

    enum Weekday {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    enum Weekday today = Monday;

    switch (today) // this expression is successively compared against all values below
    {                    // cases must be simple!

        case Sunday:
            printf("Today is Sunday");
            break;

        case Monday:
            printf("Today is Monday");
            break; // we use break to jump out of the case
                   // if not done, the program will also go to the second block

        case Tuesday:
            printf("Today is Tuesday");
            break;

        default:
            printf("Today is whatever");
    }

}

int tester(){

    int nb_to_test, remainder;

    printf("Please enter your number: ");
    scanf("%i", &nb_to_test);

    remainder = nb_to_test % 2;

    if (remainder ==0)
    {
        printf("The number iseven. \n");
    }

    else
    {
        printf("The number is odd. \n");
    }

    return 0;

}


int tester_2() {

    // three way evaluation:

    int number, sign;

    printf("Please type in a nb: ");
    scanf("%i", &number);


    if(number<0){
        sign=-1;

    } else if (number == 0)
    {
        sign = 0;
    } else
    {
        sign = 1;

        if (sign == 1)
        {
            printf("Tada!");
        }
    }

    return 0;
}

int main() {  // Here is the syntax:

    int score = 90;
    int big = 20;

    // for single if statements, you don't need brackets
    if (score > big)
        printf("yes \n");


    // when having a compound statement or an else clause, you need brackets!

    if(score>big)
    {
        score++;
        printf("you win \n");
    }

//    tester();
//    tester_2();
//    switcher();
//    challenge_pay();
//      loopy();
    challenge_guess_nb();
    return 0;
}
