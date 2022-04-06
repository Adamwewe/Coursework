import java.util.Scanner;

public class Week_3 {

    public static void main(String[] args) {

        for (int i = 0; i < 5; ++i) { // never put a ";" after the declaration!!
            // for loops work as follows:

            //start with for argument
            // initiate a dummy argument (in this case i)
            // set a condition for the dummy argument (in this case less than 5)
            // set the incrementation (in this case we increment positively)

            // in summary it follows the below structure:

            System.out.println("for (declare and initialize var; condition; incrementation logic){ \n" +
                    "do something \n" +
                    "};");
            System.out.println("The square of " + i + " is " +
                    i * i);
        }
    }
}
// example with conditional branching

class for_conditional{
    public static void main (String[] args){
    for (int i = 0; i < 5; ++i){
        System.out.println(i);
        if(i %2 == 0){
            System.out.println("pair");
        }
        else {
            System.out.println(" ");
}

        }
    }
}

// example with reductive incrementation

class negative_inc{
    public static void main(String args[]){
        for (int k = 10; k > 0; --k){
            System.out.println(k);
        }
    }
}

// example with five vars

class five_five{
    public static void main (String args[]){

        Scanner scanner = new Scanner(System.in);

    //Without loops this is slow and inefficient:

        double sum = 0;
//
//        System.out.println("Enter the first variable: ");
//        double key = scanner.nextDouble();
//        sum = sum + key;
//
//        System.out.println("Enter the second variable: ");
//        key = scanner.nextDouble();
//        sum = sum + key;
//
//        System.out.println("Enter the third variable: ");
//         key = scanner.nextDouble();
//        sum = sum + key;
//
//        System.out.println("Enter the fourth variable: ");
//         key = scanner.nextDouble();
//        sum = sum + key;
//
//        System.out.println("Enter the fifth variable: ");
//        key = scanner.nextDouble();
//        sum = sum + key;

    // With loops this is very cool:

        for(int i =1; i<=4; ++i){
            System.out.println("Entrez your first grade "+ i);
            double key = scanner.nextDouble();
            sum = sum + key;
        }

        System.out.println("Average = " + sum/4);

        // nested loops:
            // simple example with a multiplier:
        for (int j = 2; j <=10;++j){
            System.out.println("Multiplication table of " + j + ":");
            for(int i = 1; i<=10; ++i){
                System.out.println(j + " Multiplied by " + i + " is equal to " + i*j);
            }
        }

    }
}


class for_conditional2{
    public static void main (String args[]){

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 4; ++j) {
            if (i == j) {
                System.out.print("*");
            } else {
                System.out.print(j);
            }
        }
        System.out.println("");
    }

    System.out.println("Next example!!!");

    for (int i = 0; i <3; ++i){
        for(int j = 0; j <i; ++j){
            System.out.println(j);
        }
        System.out.println("");
    }

    }
}

class do_while_loops{
    // do While loops are cool because they help us iterate according to a condition
    // basically do while!
    public static void main (String args[]){

        Scanner scanner = new Scanner(System.in); // scanner declaration

        int grades; // var declaration

        do{ // start of the body
            System.out.println("Enter the number of grades ");
            grades = scanner.nextInt(); // end of body
        } while (grades <= 3); // while, meaning the conition the body should follow
        // is always decalred in the end


    }
}

class while_loops{
    // unlike the do while loops, while loops here are closer to pythonic whiles, so condition
    // is checked before hand, reducing the risk of getting stuck inside!!
    public static void main (String args[]){
    // look at how the below block will never be accessed
        int i = 100;
        while(i < 10){
            System.out.println("Hello");
        }

        System.out.println("So when do we use while, for and do while??");

        // When we know the nb of iterations before entering the loop, use for!!

        // Otherwise, use while:

            // do...while:

                // when the instructions have to be used at least once

            // otherwise use a normal while!!

        System.out.println("How do you expressa condition per loop type?");


    }
}
