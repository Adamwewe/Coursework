use std::io;


fn main() {

    // ownership, a small demo of how variable scopes work:

    let hello = "ewa"; // this is valid in the entire main function

    {
        let hello_2 = "ewa 2"; // this is not valid in all of it

        println!("hello! {}", hello);
        println!("hello! {}", hello_2);
    }
        // the user-defined scopes above are how rust deals with malloc!!!
            // going out of scope is basically freeing memory as rust calls drop() in the back
            // works the same as cpp's RAII

    // println!("hello! {}", hello_2); // this does not work!
    println!("hello! {}", hello); // but this of course does!

    // 4.1:

    // stringDs();
    // doubleMem();
    // deepCopy();
    // compact();

    // 4.2:

    // referencing();
    // mut_referencing();

    // register user input for the rest:

    let mut guess = String::new();

    io::stdin()
        .read_line(&mut guess)
        .expect("Enter Again Please");
                let mut guess = String::new();

    //4.3

    // let guess = String::from("Hello World");
    // string_noslice(&guess); // pass reference to other
    string_slicer(&guess);
    arr_slicer();

}

fn stringDs()
{
    let mut s = String::from("Push"); // ::from to avoid the use of string_from
                                       // also has to be a mutable value for safety
    // just like in c, strings are just char arrays

    s.push_str(", to heap");

    println!("{}", s);

}

fn doubleMem()
{

    let s1 = String::from("mem eror");
    let s2 = s1;
    println!("{}", s2); // this work
    // pr   intln!("{}", s1); // this will not work as value s1 has already been freed
    // rust never does automatic deep copies, therefore, the default is always the less resource greedy
}
fn deepCopy()
{
    // for custom deep copying, the rust method clone can be used:

    let s1 = String::from("Test");
    let s2 = s1.clone();

    println!("{}{}", s1, s2);

    // the copy method can also be used for moving numeric types, bool and char

    let s1 = give_ownership();
    let s2 = String::from("test");

    let s3 = takes_and_gives_back(s2);

}


// return values and scope


fn give_ownership() -> String
{
    let some_string = String::from("Yours");
    some_string
}
// this function takes a string and returns one

fn takes_and_gives_back(s : String) -> String
{
    return s // return arg is optional
} 
fn compact()
{
    let s1 = String::from("yes");
    let (s1, s2) = calculate_length(s1);

    println!("The length of {} is {}", s1, s2);
}

fn calculate_length(s: String) -> (String, usize)
{
    let length = s.len(); // local var used with passed var
    return (s, length) // no semicolon for returning
}

// in the end none of the above is worth celebrating as it is run of the mill,
    // now to the cool Rust stuff: references

fn referencing()
{
    let s1 = String::from("ewa");
    // let (name, length) = calculate_length_2(&s1); // we copy the previous function but this time with referencing a pointer
    let len = calculate_length_2(&s1);
    println!("{} has length of: {}", s1, len);
}

fn calculate_length_2(s: &String) -> usize { // s refers to the reference of the string
    let len = s.len();
    return len // we return the calculation made on the borrowed var by referencing
}

// you cannot modify a borrowed variable!!
    // references are immutable by default
    // if you want to mutate it then the below manipulation with reference mutability needs to be done:

fn mut_referencing()
{
    let mut var = String::from("NaNaNaNaNaNa");

    change(&mut var); // if you want to make changes by using a pointer then, &mut is a necessary flag beforehand
    println!("{}", var); // Important! You can only have one mutable reference to a piece of data at a time 
     // this is to prevent data races!

    // However as rust is a sexy language, you can circumvent the above with safe local scopes:

    let mut var2 = String::from("Spider");

    {
        let r1 = &mut var2;
    }

    let r2 = &mut var2;
    r2.push_str("-Man");

    println!("{}", var2);

    // Another way to circumvent this is to simply use the referencing variable as it is automatically deferenced after use:

    {
        let r1 = &var2;
        let r2 = &var2;

        // perfectly allowed to have two referencing vars for the same 
            // now will use the two referencing vars to dereference

        println!("r1 and r2 are here: {} {}", r1, r2);

        // Auto-dereferencing is done, now we can freely make the third mutable reference pointer

        let mut r3 = &var2;
        println!("r3 is here: {}", r3); 

        // this is becasue the compiler's ability to deal with Non-Lexical Lifetimes (NLL)

    }

}                        

// Another rule about references, you cannot have a mutable reference while having another immutable one to the same value!
    // these restrictions do not apply to immutable references though

                        

fn change(s: &mut String) // no return argument as you can see because we are mutating by pointing
{
     s.push_str(" Batman!");
}

// Now lets look at dangling pointers:
    // Which happens when a pointer references a location in memory that may have been given to someone else
    // by freeing some memory and preserving a pointer to that memory 

    // Rust Guarantees this will never happen: the var will never go out of scope before the reference to the var does



// Now let us look at the slice type:

    // As you know slices let you reference a specific subset of a DS rather than the entire DS
    // A slice is a reference so it does not have ownership

    // to illustrate this, we code the old school space finder


fn string_noslice(s: &String) -> usize

{

    let bytes = s.as_bytes(); // to loop we need to convert the string to an array of bytes



    for (i, &item) in bytes.iter().enumerate() // we create an iterator on the array using the .iter() method
    // iter is a method that returns each element in a collection
    // and then enumerate wraps the result of iter and returns each element as part of a tuple instead. 

    // Rust however works in the opposite of python with enumerate(x), as here the index i is returned first 
    {
        
        if item == b' ' // the b' ' means the byte literal syntax matching a space
        {
            return i
        }
    }

    s.len()

}


fn string_slicer(s: &String)

{
    let i = s.len();

    println!("{}", &s[0..i]);

}

// ofc the same can be done for arrays as in any language 

fn arr_slicer()
{

    let a = [10, 20, 30, 40];

    let slice = &a[0..2]; // works the same way as for strings ofc
}