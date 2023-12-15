#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
    BLANK,
    BOMB
} Type;

typedef struct 
{
    Type type; // if it's a bomb or not
    int border; // num of bombs that border it
} Tile;

void emptyBoard();
void printBoard();

Tile board[16][16];

int main(int argc, char const *argv[])
{
    emptyBoard();
    printBoard();
    return 0;
}

void emptyBoard()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            board[i][j].border = 0;
            board[i][j].type = BLANK;
        }
    }
}

void printBoard()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            printf("%d.%d ", board[j][i].type, board[j][i].border);
        }
        putchar('\n');
    }
}