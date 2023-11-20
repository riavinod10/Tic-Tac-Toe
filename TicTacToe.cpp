#include <iostream>
#include <vector>

using namespace std;

// print game board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// victory status
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    //columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    //diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// to play
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int moves = 0;

    while (moves < 9) {
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        int row, col;
        cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Make a valid move." << endl;
            continue;
        }

        board[row][col] = currentPlayer;
        moves++;
        printBoard(board);

        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " won" << endl;
            return;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Game Tied" << endl;
}

int main() {
    cout << "Hey, let's play tic tac toe" << endl;
    playGame();
    return 0;
}