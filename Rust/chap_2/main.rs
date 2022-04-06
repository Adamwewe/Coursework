use std::io; //std lib import
use rand::Rng;
use std::cmp::Ordering; // for ordering method

// ordering also has its enum variants:
    // Less, Greater and Equal...

fn main() {
    println!("Please enter a number below");

    let secret_number = rand::thread_rng() //calling random generator 
                        .gen_range(1..101); // generating range

    println!("Generated Random number is: {}", secret_number);

    loop 
    
        {
        let mut guess = String :: new(); // mutable variable is declared
    
        // All types are objects so you create an instance of that object when assigning
            // Therefore new() is the associated function creating that instance
        // an example of non mutable variable is the one below:

        // let adam = "Adam";

        // println!("{}", adam);

        // now if I try to mutate adam I will get an error:

        // adam = "Not Adam";

        
        io::stdin()
            .read_line(&mut guess) // the "&" ofc refers to the reference
            // read_line enum is a Result type with a fixed set of possibilities, aka variants
            .expect("Enter value again");


        // to avoid the problem with string and guess comparison, guess has to be reconverted:
            // WE DO NOT REDECLARE HERE: the process described below is called shadowing which allows reusability
        // let guess: u32 = guess // og var containing the string set to int 32 withb u:32
        //                 .trim() // remove white space
        //                 .parse() // parses string to number
        //                 .expect("Please enter a number!"); //

        // other way of doing the above:

        let guess: u32 = match guess 
                        .trim()
                        .parse() {
                            Ok(num) => num, // check of return of enum is ok
                            Err(_) => continue,   // else if not num continue
                        };

        match guess.cmp(&secret_number) // match expressions are made out of arms:
        // An arm is a pattern to match against
        // The code only runs if it fitst the match's pattern
        // 
        {
            Ordering::Less => println!("Too small!"),
            Ordering::Equal => { // nested can be done by using curly brackets
                println!("Congrats you guessed correctly!");
                break // to make loop quit after matching
            }
            Ordering::Greater => println!("Too large!"),
        }

        println!("Your guess is {}", guess);
    }

}