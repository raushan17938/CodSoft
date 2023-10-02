#include <iostream>
using namespace std;

char board[3][3]; // 3x3 game board

// Initialize the game board with empty spaces
void initializeBoard()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

// Display the current state of the board
void displayBoard()
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "| ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl
             << "-------------" << endl;
    }
}

// Check if the current player has won
bool checkWin(char player)
{
    for (int i = 0; i < 3; ++i)
    {
        // Check rows and columns
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Check if the game is a draw
bool checkDraw()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
                return false; // If there's an empty space, the game is not a draw
        }
    }
    return true; // If the board is full and no one has won, it's a draw
}

int main()
{
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    initializeBoard();

    cout << "TIC-TAC-TOE GAME" << endl;

    while (!gameWon && !gameDraw)
    {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";

        int row, col;
        cin >> row >> col;

        // Check if the chosen cell is empty and within bounds
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(currentPlayer))
            {
                displayBoard();
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                gameWon = true;
            }
            else if (checkDraw())
            {
                displayBoard();
                cout << "It's a draw!" << endl;
                gameDraw = true;
            }
            else
            {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else
        {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    cout << "Do you want to play again? (Y/N): ";
    char playAgain;
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y')
    {
        initializeBoard();
        main(); // Start a new game
    }
    else
    {
        cout << "Thanks for playing! Goodbye!" << endl;
    }

    return 0;
}

/*

This program allows users to manage a to-do list by adding tasks, viewing tasks with their status, marking tasks as completed, and removing tasks. Users can choose from a menu of options and perform the desired action.

*/
