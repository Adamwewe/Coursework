fn main() {

//  like in c enums are useful for fixed patterns such as the below example with IP addresses
    // IP address can be either version 4 or version 6

    // we defined an enum with IP custom data types below:
    enum IpKind
    {
        V4, 
        V6
    }

    // with the enum defined we can now create custom data types as such:
    let four = IpKind::V4;
    let six = IpKind::V6;

    // with the IPKind defined and instanciated above, we can define a function that only takes such a type

    fn route(ip_kind: IpKind) {}

    // lets make it cooler by using our new type in a struct

    struct IpAddress
    {
        kind: IpKind,
        address: String
    }

    let home = IpAddress
    {
        kind: IpKind::V4,
        address: String::from("127.0.0.1")
    };

    let loopback = IpAddress
    {
        kind: IpKind::V6,
        address: String::from("::1")
    };
    


    // lets make the notation above a bit more concise by putting data directly inside
        // each enum

    enum IpAddress2
    {
        V4(String),
        V6(String)
    }

    // the below definitions work the same way as the enum definition above
    let home2 = IpAddress2::V4(String::from("128.0.0.1")); 
    let loopback2 = IpAddress2::V4(String::from("::1"));

    // another example of enum flexibility is the diversity in data type and amounts below:

    enum IpAdress3
    {
        V4(u8, u8, u8, u8),
        V6(String)
    }

    let home3 = IpAdress3::V4(127, 0, 0, 1);
    let loopback3 = IpAdress3::V6(String::from("::1"));



    // more complex enums

    enum Complex
    {
        Quit, // no data associated with this type
        Move {x: i32, y: i32},
        Write(String),
        ChangeColor(i32, i32, i32)
    }

    // the above is the same as the below structs:

    struct Quit;
    struct Move
    {
        x: i32,
        y : i32
    }
    struct Write(String);
    struct ChangeColor(i32, i32, i32);

    // you can also define methods on enums

    impl Complex
    {
        fn call(&self)
        {
            println!("Ring Ring, Hello, Hello");
        }
    }

    let m = Complex::Write(String::from("Hello"));

    m.call();





}
