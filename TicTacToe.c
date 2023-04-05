#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    char board[ROWS][COLS] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // create a 3x3 grid of characters to represent the board
    int row, col, player = 1, choice; // variables to store the row, column, player number, and the player's choice
    char mark; // variable to store the player's symbol

    do {
        printf("\nTic Tac Toe\n\n");
        printf("Player 1 (X) - Player 2 (O)\n\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);
        printf("_____|_____|_____\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);
        printf("_____|_____|_____\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);
        printf("     |     |     \n");

        player = (player % 2) ? 1 : 2; // determine the current player

        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice); // get the player's choice

        mark = (player == 1) ? 'X' : 'O'; // determine the player's symbol

        // determine the row and column based on the player's choice
        switch(choice) {
            case 1:
                row = 0;
                col = 0;
                break;
            case 2:
                row = 0;
                col = 1;
                break;
            case 3:
                row = 0;
                col = 2;
                break;
            case 4:
                row = 1;
                col = 0;
                break;
            case 5:
                row = 1;
                col = 1;
                break;
            case 6:
                row = 1;
                col = 2;
                break;
            case 7:
                row = 2;
                col = 0;
                break;
            case 8:
                row = 2;
                col = 1;
                break;
            case 9:
                row = 2;
                col = 2;
                break;
            default:
                printf("Invalid move!\n");
                continue;
        }

        if(board[row][col] == 'X' || board[row][col] == 'O') { // check if the chosen cell is already marked
            printf("Cell already marked!\n");
            continue;
        }

        board[row][col] = mark; // mark the cell with the player's symbol

        printf("\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);
        printf("_____|_____|_____\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);
        printf("_____|_____|_____\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);
        printf("     |     |     \n");

    // check if a player has won
    if(board[0][0] == mark && board[0][1] == mark && board[0][2] == mark ||
       board[1][0] == mark && board[1][1] == mark && board[1][2] == mark ||
       board[2][0] == mark && board[2][1] == mark && board[2][2] == mark ||
       board[0][0] == mark && board[1][0] == mark && board[2][0] == mark ||
       board[0][1] == mark && board[1][1] == mark && board[2][1] == mark ||
       board[0][2] == mark && board[1][2] == mark && board[2][2] == mark ||
       board[0][0] == mark && board[1][1] == mark && board[2][2] == mark ||
       board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        printf("\nPlayer %d wins!\n", player);
        break;
    }

    // check if the board is full
    if(board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
       board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
       board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9') {
        printf("\nIt's a tie!\n");
        break;
    }

    player++; // switch to the other player
} while(1);

return 0;
