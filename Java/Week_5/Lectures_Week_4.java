import java.util.Scanner;
import java.util.Arrays;

class Tables_Intro {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        // A table is a collection of homogenous values, therefore it should contain data
        // of an identical type.
        System.out.println("Enter the number of players: ");
        int n = scanner.nextInt();

        // table input data

        if (n>0){

            double avg = 0;
            int scores [] = new int [n]; // empty array

            // read scores:

            for(int i = 0; i < n ; i++){
                System.out.println("Score of player " + i + ":");
                scores[i] = scanner.nextInt(); // access ith item of the array
                avg += scores[i];
            }

            avg /= n; // compute avg

            // Display

            System.out.println(" Score " + " Deviation ");

            for(int i = 0; i<n; ++i){
                System.out.println(scores[i] + " " + (scores[i]-avg));
            }



        }





    }

}
class Declare_Tables{
    public static void main(String[] args){
        // you can declare a table in two ways:
            // int [] scores; <--  This is more correct though
            // int scores [];
        // Additionally, you can also decalre separately as such:
            // double x;
            // x = 2;

        // Its a three-step process:
            // 1: declaration
            // 2: fill in table with data between curly spaces
            // 3: use a semicolon in between

        // Memory:
            // saving by value vs saving by reference
            // saving by value is applicable for basic data types
            // saving by reference is applicable for evolved data structures (strings + tables...)


        // dynamic table:

        int[] scores = new int[4000]; // we constructed a table with 4 zeros of type int

        // now we fill it in

        for(int i =1000; i<4000; ++i){
            scores[i] = i;
            System.out.println(scores[i]);
        }





    }
}

class Display{
    public static void main(String[] args){

    double[] t1 = {1.1, 2.2, 3.3};
    System.out.println(t1);

    // As you can see the above just displays the reference in memory, to read the contents,
        // you need a loop!!

    // This can be done with two types of loops:
        // iteration on all values:

        System.out.println(" First type: (iteration on all values)");
    for( double val: t1){
        // this loop has some weaknesses:
            // You cannot modify the table's content
            // You can also iterate only one array at a time
            // You can only access one element at a time, comparing i to i + 1 is therefore not possible
            // You can only iterate with one step at a time
        System.out.println(val); // basically the equivalent of python's for t in tab!!

        }
    // classic iteration:
        System.out.println(" Second type: (Classic iteration)");

    for(int i = 0; i< 3; ++i){
        System.out.println(t1[i]);

        }

        System.out.println("Now let us use Java's len() equivalent! ");

        System.out.println("the table t1 is: " + t1.length + " Items long");

        // now using this in the loop

        for(int i = 0; i<t1.length; ++i){
            System.out.println(t1[i]);

        }



    }
}

class Semantic_Error{
    public static void main(String[] args){

        // Saving by reference vs saving by value:

        int[] a = new int [10];
        int[] b = new int[10];

        for(int i = 0 ; i<a.length; ++i){
            a[i] = 1;
        }
        b = a;

        System.out.println("a");

        System.out.println(" Other example of saving by reference below: ");

        int [] tab1 = {20};
        int [] tab2 = {30};

        tab1[0] = 45;

        System.out.println(tab1[0] + " " + tab2[0] + " ");
        tab2 =  tab1;
        System.out.println(tab1[0] + " " + tab2[0] + " ");
        ++tab2[0]; // The "++" or "--" arguments before an array indicate incrementation

        System.out.println(tab1[0] + " " + tab2[0] + " ");


        // Now you see we have a problem to check the true contents of the arrays because of the reference saves
        // Here is how we can check it:

        if(a == null || b == null || a.length!= b.length){

            System.out.println("Different contents or null");
        } else{

            int i = 0;

            while(i < a.length && (a[i] == b[i])){
                ++i;
            } if(i >= a.length){
                System.out.println("Identical contents");
            } else{
                System.out.println("Different contents");

            }
        }
        // other method:

        boolean checkarr = Arrays.equals(tab1, tab2);
        System.out.println(checkarr);
    }
}

class VisualizeTableContents{
    public static void main(String[] args){

        // scanner:

        Scanner scanner = new Scanner(System.in);

        // here are the ways in which you can visualize array contents:

         double tab [] = {20.2, 22.5, 30, 30.2};
         double tab1 [] = new double[4];

        System.out.println("When we do not need to explicitely indicate the indices: ");

        for (double element: tab){
            System.out.println(element + " ");
//            for (double elements: tab1){
//                System.out.println(elements + " ");
//            }
        }


        System.out.println("When we want to indicate indices");

        for(int i=0; i < tab.length;++i){
            System.out.println(tab[i]);
//            for (int d=0; d< tab1.length; ++i){
//                System.out.println(tab1[d]);
//            }
        }
        // in the case where it is always necessary to explicitly cite indexes

        for(int i=0; i< tab.length; ++i){
            System.out.println("PLease enter a value: " + i + ":");
            tab[i] =  scanner.nextDouble();

        }
    }
}

class Multidimensional {
    public static void main(String[] args) {

        // adding a new dimension is simple, you just add another bracket:

        double[][] stats = {
                {0, 1, 2, 3}, // line 0
                {4, 5, 6, 7}, // line 1
                {8, 9, 10, 11}, // line 2
                {12, 13, 14, 15} // line 3
        };

        // selecting indexes works the same way as py
        // I will return the 9

        System.out.print(stats[2][1]);

        System.out.println("How to read data from an array? ");

        for (int i = 0; i <stats.length; ++i) {
            for( int j = 0; j < stats[i].length; ++j){
                System.out.println("Table contents: " + stats[i][j]);
            }
        }



        // other method:

        int[][] tab = {{1, 2}, {3, 4, 5}};
        int[][] tab1 = new int [3][3];
        int s1 = 0;
        int s2 = 0;

        // filling the array

        for (int i =0; i < tab.length; i++){
            s1+= tab[i][i];
            s2+= tab[i][tab[i].length - i -1];
        }

        System.out.println("Result: ");
        System.out.println(s1 + " " + s2);


        for(int[] ligne : tab)

            for(int val : ligne) System.out.print(val + " ");

        System.out.println();





    }

}

