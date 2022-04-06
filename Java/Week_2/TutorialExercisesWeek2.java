import java.security.KeyStore;
import java.util.Scanner;

public class TutorialExercisesWeek2 {
    public static void main (String args[]){
         Scanner scanner = new Scanner(System.in);

        // default var declaration

        // User-specific value declaration:
        System.out.println("Please enter a new value for a ");
        double a = scanner.nextDouble();

        System.out.println("Please enter a new value for b ");
        double b = scanner.nextDouble();

        System.out.println("Please enter a new value for c ");
        double c = scanner.nextDouble();
        while (a==0.0){
            System.out.println("Value of a should not be 0, please change it to"
                    + " a non null value: ");
            a = scanner.nextDouble();
        }


        double delta = (b*b) - (4*a*c); // delta solver

        // Conditional checks:

        if (delta <0) { // when the polynomial has no solutions
            System.out.println("There is no real number solution for the problem because delta is "
            + " negative with a value of: " + delta);
        }
        else if (delta == 0){ // when the polynomial has a single solution
            System.out.println("There is one single solution for the problem: "
            + (-b)/(2*a));
        }
        else{ // all other cases are when the polynomial is simply positive & != 0
              // which triggers the two solution equation
            System.out.println("There are two solutions for the problem: a positive one: "
                    + (-b + Math.sqrt(delta))/(2*a) + "and a negative one: "
                    + (-b - Math.sqrt(delta))/(2*a)) ;
        }
    }
}

class Exercise6 {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        // Variable collection:

        System.out.println("Please enter a number: ");
        int n = scanner.nextInt();

        // Variable evaluation:

        if (n > 0) {
            if (n % 2 == 0) {
                System.out.println("The number is positive and even");
            } else {
                System.out.println("The number is positive and odd");
            }
        }
        if (n < 0) {
            if (n % 2 == 0) {
                System.out.println("The number is negative and even");
            } else {
                System.out.println("The number is negative and odd");
            }
        } if (n == 0){
            System.out.println("The number is null and even");

        }
    }

}


class Exercise7{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);

        // input data

        System.out.println("Please enter a real number: ");
        double n = scanner.nextDouble();

        // Conditional branching verification


        if (n >=-10 & n<= -2){ // remember always put logical operators inside the parenthesis

            System.out.println("n belongs to I");
        } else if(n > 0 & n <= 1){
            System.out.println("n belongs to I");
        } else if(n>= 2 & n < 3){
            System.out.println("n belongs to I");
        } else{
            System.out.println("n does not belong to I");

        }

    }
}

class Exercise8{
    public static void main(String[] args){

        // Scanner method

        Scanner scanner = new Scanner(System.in);

        // Input collection
        System.out.println("Please enter a real number n: ");
        double n = scanner.nextDouble();

        //Computational section/function storage:

        double exp1 = n/(1-Math.exp(n));
        double exp2 = n*Math.log(n)*Math.exp(2/(n-1));
        double exp3 = (-n - (Math.sqrt((n*n)-(8*n))))/(2-n);
//        double exp4 = Math.sqrt((Math.sin(n)-(n/20)*(Math.log(Math.sqrt((n*n)-(1/n))))));
        double exp4 = Math.sqrt((Math.sin(n)-(n/20)*(Math.log(Math.sqrt((n*n)-(1/n))))));

//        System.out.println(exp1);
//        System.out.println(exp2);
//        System.out.println(exp3);
//        System.out.println(exp4);

        // output:

        if (exp1 >= 0 | exp1<= 0){
            System.out.println("Expression 1: " + exp1);
        }
        else{
            System.out.println("Expression 1: Not defined");
        }
        if (exp2 >= 0 | exp2<= 0){
            System.out.println("Expression 2: " + exp2);
        }
        else{
            System.out.println("Expression 2: Not defined");
        }
        if (exp3 >= 0 | exp3<= 0){
            System.out.println("Expression 3: " + exp3);
        }
        else{
            System.out.println("Expression 3: Not defined");
        }
        if (exp4 >= 0 | exp4<= 0){
            System.out.println("Expression 4: " + exp4);
        }
        else{
            System.out.println("Expression 4: Not defined");
        }



        //conditional branching/output

    }
}

