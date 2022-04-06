

import java.util.Scanner;

public class LecturesWeek2{

    public static Scanner scanner = new Scanner(System.in);

    public static void main (String[] args){

        System.out.println("Enter a number: ");
        int n = scanner.nextInt();

        // From what we saw last week was just the basics of a the basics.
        // if you want to do any reasonable programming you need to alter behavior. To alter behavior,
        // we use control flows.
        // There are three main control flows:
        //Conditional branching
        // iterations
        // conditional loops

        // conditional branching:
        // if you only have one condition, you do not need to add brackets,
        // HOWEVER, for readability, always do it!!!!!!

        if (n<5){ // conditions are always enclosed in parentheses
            System.out.println("You chose a number smaller than 5");
            System.out.println("Your number is: " + n);

        } else{
            System.out.println("You chose a number bigger than 5");
            System.out.println("Your number is: " + n);

        }

        System.out.println("Closing program");

    }
}

// now for some more complex conditional branching, but please note that this
// should be avoided as much as possible! For branching of more than three levels,
// your code can quickly become unreadable! Please avoid going beyond three!


class BigBranch{
    private static void main(String[] args){

        int n = 4;
        int x = 5;
        int z = 6;
        int y = 8;

        if (x == y){
            if (y ==z){

                System.out.println("The three variables are equal. ");
            }
            else {

                System.out.println("Only the two first values are equal");
            }
        }else {
            if (x ==z){
                System.out.println("Only the first and thrid variables are equal");
            }else {
                if (y ==z){
                    System.out.println("Only the last two variables are equal");
                } else{
                    System.out.println("All three variablesa re different");
                }
            }
        }
    }
}

class ComplexCondition{
    public static void main(String args[]){
        int a = 1;
        int b = 2;

        if (a == b){
            System.out.println("Case 1");
        } else {
            System.out.println("Case 2");
        } if ((2 *a) == b){
            System.out.println("b is the double of a");
        }
    }
}

class And{ //And logic
    public static void main(String args []){
        Scanner keyb = new Scanner(System.in);
        int n = keyb.nextInt();

        if ((n >= 1)&& (n <=10)){
            System.out.println("Correct");
        } else {
            System.out.println("Incorrect");
        }
    }
}

class Or{ // Or logic
    public static void main(String args []){
        Scanner keyb = new Scanner(System.in);
        int n = keyb.nextInt();
        int m = keyb.nextInt();

        if ((m >= 0) || (n >= 0)){
            System.out.println("At least one value is positive");
        } else {
            System.out.println("Both values are negative");
        }
    }
}

class Not{ // Not logic
    public static void main(String args []){
        Scanner keyb = new Scanner(System.in);
        int n = keyb.nextInt();
        int m = keyb.nextInt();

        if (!(m >= 0) || !(n >= 0)){// if !(m>=0) is fulfilled then FALSE, otherwise, opposite is true
            System.out.println("At least one value is positive");
        } else {
            System.out.println("Both values are negative");
        }
    }
}

class Boolean{ // Boolean variables are a type of condition:
        // They declare variables containing the value of a condition
        // It can of course contain ONLY two types of values: True and False
    public static void main(String args []){
        int a =1, b =2;
        boolean test1 = (a==b);
        boolean test2 = (a<b);

        // you can also combine boolean operators with conditional branching as such:

        int d =1, e=2;

        boolean test3 = true;
        boolean test4 = (d==e), test5= (test4 || (d<e));

        if (test5){// as we stored the condition in an object created before, we don't need to specify it again!
            System.out.println("e is true! ");
        }
    }
}
