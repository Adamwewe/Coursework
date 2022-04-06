import java.util.Scanner;
import java.lang.Math;

public class Exos_Week_3 {
    public static void main (String[] args){
        System.out.println("Multiplication Tables: ");
        for(int i=1; i<10; i++){
            for (int j = 1; j<=10; j++){
                System.out.println("Multiplication table of " + i + " "
                       + i + "*" +j + " = " + (i*j));
            }
        }
    }

}

class Exercise_10 {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Please enter a first number: ");
        int a = scanner.nextInt();
        System.out.println("Please enter a second number: ");
        int b = scanner.nextInt();

        System.out.println("first: " + a + " Second: " + b);


        while ((a & b) != 0) {
            if (a > b) {
                int d = a-b;
                a = d;
                System.out.println(a);
            } else if (a < b) {
                int d = b-a;
                b = d;
            }
            System.out.println("The greatest common divisor between a and b is: " + a);
        }
    }
}

class Exercise_11{
    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        double g = 9.81; // locked value g
        System.out.println("PLease enter a height: ");

        double h0 = scanner.nextDouble();

        System.out.println("PLease enter the rebound coefficient: ");
        double eps = scanner.nextDouble();

        System.out.println("PLease enter the number of rebounds: ");
        int nbr = scanner.nextInt();

        for(int i=0; i<=nbr; i-- ){

            double v = Math.sqrt(2*h0*9.81);
            double v1 = eps*v;
            System.out.println(v1);

        }

    }
}
