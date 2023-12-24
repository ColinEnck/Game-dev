#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"

typedef enum 
{
    BLANK,
    BOMB
} Type;

typedef enum 
{
    HIDDEN,
    OPENED,
    FLAGGED
} Click;

typedef struct 
{
    Type type; // if it's a bomb or not
    int border; // num of bombs that border it
    Click clicked; // if it's been clicked yet
} Tile;

void emptyBoard();
void fillBoard();
void updateBorders();
void printBoard();
void cascadeZeros(struct node* head, int x, int y);
int gameWon();

Tile board[16][16];

int main(int argc, char const *argv[])
{
    char c, *input = malloc(4);
    int flushLines = 1;
    int gameOver = 0;
    struct node* HEAD = (struct node*) malloc(sizeof(struct node));
    HEAD->point.x = -1;
    HEAD->point.y = -1;
    HEAD->next = NULL;
    srand(time(NULL));
    emptyBoard();
    fillBoard();
    updateBorders();
    printf("Type 1 or 2 to click or flag a point, repsectively\n");
    printf("Then type the coordinates of the point you desire\n");
    printf("to select it, in uppercase (i.e. '1CE')\n");
    printf("Type 'Q' at any point to quit\n");
    for (;;)
    {
        printBoard();
        if (gameOver)
        {
            printf("\n\n*** GAME OVER ***\n\n");
            break;
        }
        if (!flushLines) getchar();
        flushLines = 0;
        printf("> ");
        fgets(input, 4, stdin);
        if (input[0] == 'Q')
            break;
        if (atoi(&input[0]) == 1 || atoi(&input[0]) == 2)
            if (input[1] >= 'A' && input[1] <= 'P')
                if (input[2] >= 'A' && input[2] <= 'P')
                    goto skip;
        printf("Invalid input\n");
        flushLines = 1;
        continue;
        skip:
        if ((board[input[1]-'A'][input[2]-'A'].clicked = atoi(&input[0])) == 1)
            if (board[input[1]-'A'][input[2]-'A'].type == BOMB)
                gameOver = 1;
        else if (board[input[1]-'A'][input[2]-'A'].border == 0)
        {
            clearList(HEAD);
            cascadeZeros(HEAD, input[1]-'A', input[2]-'A');
        }
        if (gameWon())
        {
            printf("\n\n*** GAME WON ***\n\n");
            break;
        }
    }
    return 0;
}

void emptyBoard()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            board[i][j].type = BLANK;
            board[i][j].border = 0;
            board[i][j].clicked = 0;
        }
    }
}

void fillBoard()
{
    int x, y;
    for (int i = 0; i < 30; i++)
    {
        x = rand() % 16;
        y = rand() % 16;
        if (board[x][y].type == BOMB)
            i--;
        else
            board[x][y].type = BOMB;
    }
}

void updateBorders()
{
    int count, offsetx, offsety;
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            count = 0;
            if (board[j][i].type == BOMB)
                count = 'B'; // 66 is code for bomb
            else
            {
                // looping thru the variations to 
                // see if the tile borders any bombs
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        if (k == 0 && l == 0)
                            continue;
                        else
                        {
                            offsetx = j+k;
                            offsety = i+l;
                            if (offsetx < 0 || offsetx >= 16 || offsety < 0 || offsety >= 16)
                                continue;
                            else if (board[offsetx][offsety].type == BOMB)
                                count++;
                        }
                    }
                }
            }
            board[j][i].border = count;
        }
    }
    
}

void printBoard()
{
    char labels[] = "ABCDEFGHIJKLMNOP";
    printf("  ");
    for (int i = 0; i < 16; i++)
        printf("%c ", labels[i]);
    printf("\n");
    for (int i = 0; i < 16; i++)
    {
        printf("%c ", labels[i]);
        for (int j = 0; j < 16; j++)
        {
            switch (board[j][i].clicked)
            {
            case HIDDEN:
                printf("* ");
                break;
            case OPENED:
                if (board[j][i].type == BOMB)
                    printf("B ");
                else
                    printf("%d ", board[j][i].border);
                break;
            case FLAGGED:
                printf("! ");
            default:
                break;
            }
        }
        putchar('\n');
    }
}

void cascadeZeros(struct node* head, int x, int y)
{
    if (x >= 16 || x < 0 || y >= 16 || y < 0)
        return;

    Point temp;
    temp.x = x;
    temp.y = y;
    if (search(head, temp)) return;

    if (board[x][y].border == 0)
        board[x][y].clicked = OPENED;
    else return;

    addEnd(head, temp);

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            cascadeZeros(head, x+i, y+j);
        }
    }
}

int gameWon()
{
    int won = 1;
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            if (board[i][j].type == BOMB)
                if (board[i][j].clicked == HIDDEN)
                    won = 0;
    return won;
}
