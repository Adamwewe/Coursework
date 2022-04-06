
fn main() {

    // vars and mutability
        // as you know in rust vars can be declared as either mut or safe
    
    let x = 5;
    let mut y = 5;

    println!("Value of non-mutable x is: {}", x);
    println!("Value of mutable y is: {}", y);

    y = 7;

    println!("Value of y after mutation is now: {}", y);
    
    // constants are declared as immutable by default bc they are constants...
        // a constant always comes with a type!
            // as can be seen below with the u32 flag
    const c: u32 = 5;

    println!("const c is {}", c);

    // remember shadowing from the previous chapter?
        // it can also be done with scopes

    let f = 5;

    println!("Value before incrementation: {}", f);

    let f = f + 2;

    println!("Value after incrementaion: {}", f);


    {
        let f = f * 2;
        println!("Value in inner scope is: {}", f);
    }

    println!("Value in outer scope is: {}", f);

    println!("For easy readbility, numbers can be written like this: {}, or like this: {}", 10_000, 1_000_000);

    let emoji = '😻';
    println!("Char Emojis {}", emoji);

    // tuples are also types:
        // like pythonic lists tuples can have multiple data types mixed 
        // however because of this, read/write will be slower

    let tup: (i32, f64, u8) = (500, 6.4, 1);

    println!("Tuple: {}", tup.1);

    // Other way of accessing tuples:

    let tup_2 = (500, 6.4, 1);
    let (x, y, z) = tup; // this is called destructuring 

    println!("The value of x in tuple 2 is {}", x);

    let tup_3: (i32, f64, u32) = (9, 9.5, 9);
    let (x, y, z) = tup_3;

    println!("Explicitely typed tuple is {}", y);

    // Arrays on the other hand are fixed type and allocate data on the stack
        // Therefore, arrays are fixed type and fixed length which means they are useful for collecting fixed data such as months or days

    let days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday"];

    println!("Yay its {}", days[days.len() -1]);

    // indexing also works differently on Arrays than in Tuples
        // for explicit type declaration in arrays, the following operation is performed:
            // where [0] is the data type and [1] is the length of the array (just like java)
    let a: [i32; 5] = [1, 2, 3, 4, 5];

    // functions work just like in another language:
        // however, the cool thing with Rust is that it does not need a declaration before the func (like c/cpp)

    function2(5, 'x');
    function3(2); 
    println!("Value of x is {}", function3(2));              
    
    // now for some control flow:

    //     control('b', 2);
    //     controlOneLine(5);
    //     loopy();
    //     loopyBreak();

        loopyFor();



}

fn function2(x: i32, c: char)
{
    println!("you passed in {}{} to function 2", x, c);

    // Statements vs expressions
        // this is a statement:

    let statement: i32 = 4;

    let expression: i32 = 
    { 
        let expression_nested = 2;
        expression_nested + 2 // notice how expressions do not have ending semi-columns before the closing bracket
    };

println!("yes {}", expression);

}

// now let us try to return something


fn function3(x: i32) -> i32
{
    x + 2 //Notice how no semicolons are used here 
}                                                         

fn control(c: char, x: i32)
{
    if c == 'a'
    {
        println!("I got {} letter", c);
    }
    else if c == 'b' 
    {
        println!("{}roooooo", c)
    }
    else 
    {
        println!("The letter {} does not fit nicely {} times", c, x);
    }
}

fn controlOneLine(x : i32)
{   
    // a really cool way of doing conditional branching

    let condition = false;
    let number = if condition{x} else {x+2};

    println!("Value of x is: {}", x);
}

// lets look at loops 

fn loopy()

{
// Rust also has a loop that just keeps looping until u tell to explicitely stop like so:

    let mut i: u32 = 0;
    loop
    {
        println!("Ewa I am loooooooping");
        i += 1;

        if i > 10
        {
            break println!("mok");
        }

        

        
    }
}

fn loopyBreak()
{
    let mut i: u32 = 0;

    'stop : loop {
        println!("STOP COUNT{}", i);
        let mut i = 10;
        
        loop 
        {
            i+= 1;
            if i < 10 
            {
                println!("HEHE");
                println!("i is {}", i);
            }

            else 
            {
                println!("ELSE");
                break 'stop;
            }

        }
    
    
    }
}

fn loopyFor()
{
    let a = [10, 20 , 30, 40];
    for x in a//in (1..5)
    {
        println!("My name is {} times", x);
    }

}
