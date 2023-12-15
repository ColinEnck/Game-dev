#include <stdio.h>
#include <stdlib.h>

void zeroBoard();
void printBoard();

int board[9][9];

int main(int argc, char const *argv[])
{
    zeroBoard();
    
    printBoard();
    return 0;
}

void zeroBoard()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            board[i][j] = 0;
}

void printBoard()
{
    putchar('\n');
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 8)
                printf("%d\n", board[j][i]);
            else if ((j+1) % 3 == 0)
                printf("%d     ", board[j][i]);
            else printf("%d   ", board[j][i]);
        }
        ((i+1) % 3 == 0 && i != 8) ? printf("\n\n") : putchar('\n');
    }
}