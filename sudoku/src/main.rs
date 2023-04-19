// INCOMPLETE

fn main() {
    let mut board: [[u8; 9]; 9] = [[0; 9]; 9]; 
    let key = set_key();
    print_board(key);
}

fn set_key() -> [[u8; 9]; 9] {
    let mut key: [[u8; 9]; 9] = [[0; 9]; 9];
    let mut guess: u8;
    for n in 0..9 {
        for i in 0..9 {
            key[n][i] = loop {
                let mut new_num = true;
                guess = rng();
                for j in 0..i {
                    if guess == key[n][j] { new_num = false; }
                }
                // **this makes it break for some reason**
                // for k in 0..n {
                //     if guess == key[k][i] { new_num = false; }
                // }
                if new_num == true { break guess }
            };
            println!("I made it");
        }
        println!("I made it again");
    }
    return key;
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
