use std::io;

fn main () {
    // let _x = String::new();
    println!("hi");

    let mut index = String::new();

    io::stdin()
        .read_line(&mut index)
        .expect("Can't read :/")

}