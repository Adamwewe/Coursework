use std::str;

fn main() {

// as you know from c structs follow the below logic:

    // the struct is deifned but still empty:

    struct User
    {
        active: bool,
        username: String,
        email: String,
        sign_in_count: u64
    } // no semicolon at the end of a struct declaration 
    
    // It is then filled following k/v pair logic:
        // we declare each var then following the above Struct logic:
    let user1 = User // ref to the struct 
    {
        active: true,
        email: String::from("fooadams@gmail.com"),
        username: String::from("foofoo"),
        sign_in_count: 22
    }; // but here add a semicolon


    println!("{}", user1.email); // now we can retrieve data as such 


    // values can be changed again as such iff the var is mutable ofc:
        // we do a borrowing trick:

    let mut user2 = user1;

    user2.email = String::from("foomichaels@gmail.com");

    println!("After changing {}", user2.email);

    // you can also update struct instances from another struct

    let user3 = User {

        active : false,
        username : user2.username,
        email : user2.email,
        sign_in_count: 22
    };

    println!("{}", user3.email);

    // for even less verbosity ".." can be used:

    let user4 = User {

        ..user3
    };

    println!("Less verbose email: {}", user4.email);

    // tuple_structs();

    //5.2

    // struct_pgm();

    //5.3

    // method_chap();
    associated_func();

}


fn tuple_structs()

{

    struct Color(i32, i32, i32);
    struct Point(i32, i32, i32);

    let black = Color(0, 0, 0);
    let origin = Point(0, 0, 0);

    struct Alphabet(String, String);

    let ab = Alphabet(String::from("a"), String::from("b"));

    println!("{}{} or {}{}", ab.0, ab.1, ab.1, ab.0);
    // ofc both structs above are different types because they are instances of different structs
    // each defined struct is its own type

   
    println!("{}", black.0);

    // you can also have empty structs like so:

    struct Coffee;

    let cup = Coffee;



}






// fn user_builder(email: String, username: String) -> User {
//     User {
//             email,
//             username,
//             active: true,
//             sign_in_count: 1,
//         }
// }


fn struct_pgm()

{

    println!("Start of the program");

    let area = rectangle(2, 2);

    println!("Area of the rectangle is {}", area);
}

fn rectangle(l: u32, h: u32) -> u32 // can be sped up if only using references
{
    #[derive(Debug)] // introducing debug macro 
    struct Rectangle 
    {

        height: u32,
        length: u32,

    }

    let rectangle_data =  Rectangle
    {
        height: h,
        length: l
    };

    println!("\n ractangle data is: {:?}", rectangle_data); // to get debug info add {:?} or {:#?}
    println!("\n rectangle data with additional print is {:#?}", rectangle_data); // bear in mind this ony works with #[derive(Debug!!)]


    // alternatively we can use the dbg! macro

    let scaler: u32 = 2;

    let rectangle_data2 = Rectangle
    {
        height: dbg!(scaler*5),
        length: 20
    };

    println!("Using dbg reference: \n");

    dbg!(&rectangle_data2);  // reference to debug macro


    return rectangle_data.height*rectangle_data.length
}

// methods are just like functions, except their context-based definition within a struct, enum or trait object
    // first param is always self (instance of a struct)


    // now lets do refactor the code to take a Rectangle instance as a parameter

    // Done in two steps:
        // First define the struct

        // Second implement method

    #[derive(Debug)]
    struct Rectangle 
    {
        height: u32,
        length: u32
    }

    impl Rectangle // use the impl key word to enclose a method within a struct
    {
        fn area(&self) -> u32
        {
            self.height * self.length
        }
    }

    // what if we implement a method in the fields of a struct itself?

    struct Rectangle2 
    {
        width: u32,
        length: u32
    }

    impl Rectangle2 // keep in mind you can have multiple impl blocks declared separately in the script!
    {
        fn width(&self) -> bool // borrowing using the width nam
        {
            self.width > 0 // return the field of the struct as a method
        } // to implement multiple methods in the same impl block just add as many as you want
    
        fn can_hold (&self, other: &Rectangle) -> bool // second arg has to be explicitely declared
        {
            self.width > other.height && self.length > other.length  // self for instance/other for second arg
        }
    }



fn method_chap()

{

    let rect1 = Rectangle
    {
        length: 20,
        height: 10
    };

    println!("Area of the rectangle is: {}", rect1.area()); // call the global scope method defined above


    let rect2 = Rectangle2
    {
        length: 20,
        width: 20
    };

    println!("Is width non null? {}", rect2.width()); // call the field as a function using()

    if rect2.width()
    {
        println!("Width is {} and {}cm long", rect2.width(), rect2.width);
    }

    if rect2.can_hold(&rect1)
    {
        println!("It can hold!");
    }

    else 
    {
        println!("Can't hold :(");
    }
}


