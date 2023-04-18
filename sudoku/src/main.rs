use rand::prelude::*;
// rand::random::<T>() generates a random instance of said type

fn main() {
    let board: [[u8; 9]; 9] = [[0; 9]; 9]; 
}

fn print_board(board: [[u8; 9]; 9]) {
    for n in 0..19 {
        println!("");
    }
    for i in 0..9 {
        for j in 0..9 {
            print!("{}", board[i][j]);
            if (j + 1) % 3 == 0 {
                print!("     ");
            } else {
                print!("   ");
            }
        }
        println!("");
        if (i + 1) % 3 == 0 {
            println!("\n\n");
        } else {
            println!("\n");
        }
    }
}
