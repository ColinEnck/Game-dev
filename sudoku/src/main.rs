fn main() {
    let mut board: [[u8; 9]; 9] = [[0; 9]; 9]; 
    for n in 0..9 {
        let mut guess: u8;
        board[0][n] = loop {
            let mut new_num = true;
            guess = rng();
            for val in board[0] {
                if guess == val {
                    new_num = false;
                }
            }
            if new_num == true {break guess}
        };
    }

    print_board(board);
}

fn rng() -> u8 {
    (rand::random::<u8>() % 9) + 1
}

fn print_board(board: [[u8; 9]; 9]) {
    for _n in 0..19 {
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
