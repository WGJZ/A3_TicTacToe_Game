#include <iostream>
using namespace std;

//initial board grid[3][3].
void initialBoard(char grid[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = ' ';
        }
    }
}
//show the board as required.
void showBoard(char grid[3][3]) {
    cout << "\n  A B C\n"; //A,B,C for each column letter.
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " "; //1,2,3 for each row number.
        for (int j = 0; j < 3; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
//index number 0,1,2 corresponding to capital letter A,B,C of each column.
int convertColumn(char col) {
    switch (col) {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    default:
        return -1;
    }
}
//check if the move we made is valid or not.
bool isValidMove(char grid[3][3], int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ';
    //Make sure the move inside of the ranges of rows/columns and not occupied.
    //return value is boolean value: true or false.
}

//check if the current player win or not.
bool checkWin(char grid[3][3], char player) {

    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) {
            return true;
        }
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) {
        return true;
    }
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) {
        return true;
    }
    return false;
}


//check if the game is draw or not.
bool isDraw(char grid[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == ' ')
                return false;
        }
    }
    return true;
    //every cell is occupied but still no player wins == draw game.
}


void play() {
    char grid[3][3];
    initialBoard(grid);
    char currentPlayer = 'X';

    while (true) {
        showBoard(grid);
        cout << currentPlayer << "'s turn to play.";
        cout << "Make move (e.g. A1,B2): ";
        //get the data user entered.
        string input;
        cin >> input;
        char colChar = toupper(input[0]);
        int row = input[1] - '1';
        int col = convertColumn(colChar);
        //check move valid or not.
        if (col == -1 || !isValidMove(grid, row, col)) {
            cout << "Invalid move!\n";
            continue;
        }
        //make move
        grid[row][col] = currentPlayer;
        //check win after a valid move is made.
        if (checkWin(grid, currentPlayer)) {
            showBoard(grid);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (isDraw(grid)) {
            showBoard(grid);
            cout << "Finally, it's a draw.\n";
            break;
        }
        //switch the player.
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}
int main() {
    play();
    return 0;
}